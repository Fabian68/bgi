#include "Dragon.h"
#include "Affichage.h"

Dragon::Dragon(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal, int id) : Personnage(LVL, nom, 2, 4, 4, 10, 10, 10, 10, 10, 10, 10, animal, rareteAnimal)
{
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(90 * vie());
	}
}

void Dragon::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	double inc = 0.0;
	int cible;
	double mult = 1.0;
	switch (choix) {

	case 0:

		Affichage().dessinerTexte(nom() + " morsure ");
		DEGATS = degats(1.0, 2.0);
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		if (attaqueDouble()) {
			DEGATS = degats(1.0, 2.0);
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		}
		ajouterMana(1);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " lance flamme ! ");
		DEGATS = degats(6.0, 12.0);
		for (int i = 0;i < equipeEnnemi().taille();i++) {
			if (equipeEnnemi()[i]->estEnVie()) {
				Attaque(DEGATS*mult, equipeEnnemi()[i]);
				DEGATS = round(DEGATS * (1.0 - equipeEnnemi()[i]->pourcentageReduction() / 100.0));
			}
		}
		ajouterMana(-1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " Coup de queue ");
		DEGATS = degats(1.0, 2.0);
		for (int i = equipeEnnemi().taille()-1;i >=0;i--) {
			if (equipeEnnemi()[i]->estEnVie()) {
				Attaque(DEGATS * mult, equipeEnnemi()[i]);
				DEGATS = round(DEGATS * (1.2 + equipeEnnemi()[i]->pourcentageReduction() / 100.0));
			}
		}
		ajouterMana(1);
		break;
	case 3:

		Affichage().dessinerTexte(nom() + " Croissance ");
		ajouterChanceDoubleAttaque(10);
		ajouterChanceHabileter(10);
		ajouterReduction(10);
		ajouterCoupCritique(10);
		ajouterDegatsCritique(10);
		ajouterMana(-3);
		break;
	}
}

void Dragon::passif(int tour)
{
}

void Dragon::passifDefensif()
{
}
