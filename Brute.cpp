#include "Brute.h"
#include "Affichage.h"

Brute::Brute(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal) : Personnage(LVL, nom, 2, 6, 2, 10, 50, 25, 0, 0, 0, 0, animal, rareteAnimal)
{
	ajouterForce(force());
	if (difficulte == 1) {
		ajouterVitesse(vitesse());
		ajouterVie(9 * vie());
	}
	else if (difficulte == 5) {
		ajouterVie(vie());
		ajouterReduction(90);
	}
	enrager = false;
}


void Brute::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	double inc = 0.0;
	int cible;
	double mult = 1.0;
	switch (choix) {

	case 0:

		Affichage().dessinerTexte(nom() + " Lance Grenade");
		DEGATS = degats(0.4, 0.8);
		if (enrager) {
			DEGATS *= 2;
		}
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		if (attaqueDouble()) {
			DEGATS = degats(0.4, 0.8);
			if (enrager) {
				DEGATS *= 2;
			}
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		}
		ajouterMana(1);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " coup rasoir ");
		DEGATS = degats(0.5, 1.5);
		if (enrager) {
			DEGATS *= 2;
		}
		Attaque(DEGATS, equipeEnnemi().plusFaible());
		if (attaqueDouble()) {
			DEGATS = degats(0.5, 1.5);
			if (enrager) {
				DEGATS *= 2;
			}
			Attaque(DEGATS, equipeEnnemi().plusFaible());
		}
		ajouterMana(-1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " coup enrager ");
		DEGATS = degats(1.5, 3.0);
		AttaqueBrut(DEGATS, equipeEnnemi().plusFort());
		ajouterMana(-2);
		break;
	case 3:

		Affichage().dessinerTexte(nom() + " Coup de marteau ");
		DEGATS = degats(2.0, 4.0);
		if (enrager) {
			DEGATS *= 2;
		}
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		ajouterMana(-3);
		break;
	}
}

void Brute::passif(int tour)
{
	if (vie() < (vieMax() / 5)) {
		enrager = true;
	}
	else {
		enrager = false;
	}
}

void Brute::passifDefensif()
{
}
