#include "Bryan.h"
#include "Aleatoire.h"
#include "Affichage.h"

Bryan::Bryan(Experiences E, Orbes O, Animaux A) : Personnage(5, E, O, A, "Bryan", 1, 5, 4, 30, 30, -100, 0, 0, 30, 3) {
	ajouterCoupCritique(10);
	ajouterDegatsCritique(25);
}

void Bryan::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	int indice;
	double RATIO;
	DEGATS = static_cast<int>(degats(0.10, 0.30) * (1.0 + degatsCritiques() / 100.0));
	Affichage().dessinerTexte(nom() + "Attaque critique");
	Attaque(DEGATS, equipeEnnemi().plusFaible());
	switch (choix) {

	case 0:
		if (equipeEnnemi().estEnVie()) {
			DEGATS = degats(0.45, 0.75);
			Affichage().dessinerTexte(nom() + " coup de dague ! ");
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			if (attaqueDouble() && equipeEnnemi().estEnVie()) {
				DEGATS = degats(0.12, 0.24);
				AttaqueBrut(DEGATS, equipeEnnemi().plusProcheVivant());
			}
		}
		ajouterMana(2);
		break;
	case 1:
		if (equipeEnnemi().estEnVie()) {
			Affichage().dessinerTexte(nom() + " vise le plus faible");
			DEGATS = degats(0.25, 0.50);
			indice = equipeEnnemi().plusFaible()->indiceEquipe();
			RATIO = (equipeEnnemi()[indice]->vieMax() * 1.0) / (equipeEnnemi()[indice]->vie() * 1.0);
			RATIO = min(RATIO, 20.0);
			DEGATS = static_cast<int>(DEGATS * RATIO);
			Attaque(DEGATS, equipeEnnemi().plusFaible());
		}
		ajouterMana(-1);
		break;
	case 2:
		if (equipeEnnemi().estEnVie()) {
			Affichage().dessinerTexte(nom() + " attaque par derrière ");
			DEGATS = degats(1.0, 2.0);
			AttaqueBrut(DEGATS, equipeEnnemi().plusLoinVivant());
			if (attaqueDouble() && equipeEnnemi().estEnVie()) {
				DEGATS = degats(0.5, 1.0);
				AttaqueBrut(DEGATS, equipeEnnemi().plusFaible());
			}
		}
		ajouterMana(-2);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + " ce boost ! ");
		ajouterCoupCritique(1);
		ajouterDegatsCritique(5);
		if (habile()) {
			ajouterCoupCritique(1);
			ajouterDegatsCritique(10);
			ajouterReduction(5);
		}
		SOINS = soins(0.5, 2.5);
		soigner(SOINS, this);
		ajouterMana(-3);
		break;
	}
}

void Bryan::passif(int tour)
{
	if (tour % 10 == 0) {
		ajouterCoupCritique(1);
		ajouterDegatsCritique(2);
		if (habile()) {
			//ajouterCoupCritique(2);
			ajouterDegatsCritique(4);
		}
	}
}

void Bryan::passifDefensif()
{
	if (Aleatoire(0, 101).entier() < pourcentageEsquive()) {
		int SOINS = static_cast<int>(0.33 * vitesse());
		bouclier(SOINS, this);
	}
}
