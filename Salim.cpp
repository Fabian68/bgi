#include "Salim.h"
#include "Affichage.h"
#include "Aleatoire.h"

Salim::Salim(Experiences E, Orbes O, Animaux A) : Personnage(15, E, O, A, "Salim", 6, 3, 1, 0, 25, 25, 0, 25, 0, 0), estTransformer{ false }, superTransformation{ false } {}


void Salim::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	int nb;
	int cible;
	
	switch (choix) {

	case 0:

		Affichage().dessinerTexte(nom() + " racine poignard ");
		DEGATS = Aleatoire(0.03, 0.06).decimal() * vieMax() + degats(0.1, 0.3);
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		if (habile()&&equipeEnnemi().estEnVie()) {
			DEGATS = Aleatoire(0.03, 0.06).decimal() * vieMax() + degats(0.1, 0.3);
			AttaqueBrut(DEGATS, equipeEnnemi().plusProcheVivant());
			ajouterMana(2);
		}
		ajouterMana(1);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " SUPERSOIN ! ");
		nb = equipeAllier().nbEnVie();
		SOINS = soins(2.0 / nb, 6.0 / nb);
		for (int i = 0;i < equipeAllier().taille();i++) {
			SOINS = soins(2.0 / nb, 6.0 / nb);
			soigner(SOINS, equipeAllier()[i]);
			SOINS = soins(1.0 / nb, 3.0 / nb);
			bouclier(SOINS, equipeAllier()[i]);
		}
		ajouterMana(-1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " endormissement ");
		SOINS = soins(0.1, 10.0);
		bouclier(SOINS, this);
		SOINS = soins(0.2, 2.0);
		soigner(SOINS, this);
		ajouterReduction(5);
		ajouterMana(1);
		break;
	case 3:
		if (!estTransformer) {
			Affichage().dessinerTexte(nom() + " TRANSFORMATION ! ");
			reduireVieMax((vieMax() / 10) * 9);
			ajouterForce(force() * 2);
			setNom("GRAND SALIMALEKUM");
			estTransformer = true;
			ajouterReduction(10);
		}
		else if (!superTransformation && mana() > 9) {
			Affichage().dessinerTexte(nom() + "SUUUPPEEEERR TRANSFORMATION ! ");
			reduireVieMax((vieMax() / 10) * 9);
			ajouterForce(force() * 2);
			setNom("GRAND SALIMALEKUM DIEUX DES TERRES ET DES OCEANS");
			superTransformation = true;
			ajouterReduction(20);
		}
		else {
			Affichage().dessinerTexte(nom() + " rejuvenation ! ");
			ajouterVieMax(niveau()*10);
			SOINS = soins(0.2, 1.2);
			soigner(SOINS, this);
			SOINS = soins(0.1, 0.6);
			bouclier(SOINS, this);
		}
		ajouterMana(-3);
		break;
	}
}

void Salim::passif(int tour)
{
	int DEGATS;

	if (habile()) {
		ajouterVieMax(force() / 5);
		if (habile()) {
			ajouterVieMax(force());
		}
	}
	ajouterVieMax(force() / 10);
	if ((tour + 1) % 100 == 0) {
		Affichage().dessinerTexte(nom() + " jugement dernier ! ");
		for (int i = 0;i < equipeEnnemi().taille();i++) {
			DEGATS = degats(1.0, 10.0);
			if (habile()) {
				AttaqueBrut(DEGATS, equipeEnnemi()[i]);
			}
			else {
				Attaque(DEGATS, equipeEnnemi()[i]);
			}
		}
	}
}

void Salim::passifDefensif()
{
	if (habile()) {
		ajouterVieMax(force() / 5);
		if (habile()) {
			ajouterVieMax(force());
		}
	}
	ajouterVieMax(force()/10);
}
