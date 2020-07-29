#include "Chasseur.h"
#include "Affichage.h"

Chasseur::Chasseur(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal) : Personnage(LVL, nom, 5, 4, 1, 0, 30, 90, 3, 60, 0, 3, animal, rareteAnimal)
{
	ajouterVie(vie());
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(9 * vie());
	}
}


void Chasseur::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	double inc = 0.0;
	int cible;
	double mult = 1.0;
	switch (choix) {

	case 0:
		ajouterMana(1);
		break;
	case 1:
		if (habile()) {
			Affichage().dessinerTexte(nom() + " coup charger ! ");
			DEGATS = degats(1.0, 4.0);
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		}
		ajouterMana(-1);
		break;
	case 2:
		Affichage().dessinerTexte(nom() + " coup coude ! ");
		DEGATS = degats(1.5, 2.5);
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		ajouterMana(-1);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + " coup charger precis ! ");
		if (habile()) {
			DEGATS = degats(4.0, 8.0);
			AttaqueBrut(DEGATS, equipeEnnemi().plusProcheVivant());
		}
		else {
			DEGATS = degats(3.0, 6.0);
			Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
		}
		
	
		ajouterMana(-3);
		break;
	}
}

void Chasseur::passif(int tour)
{
}

void Chasseur::passifDefensif()
{
}
