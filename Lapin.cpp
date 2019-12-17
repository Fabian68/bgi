#include "Lapin.h"
#include "Affichage.h"


Lapin::Lapin(int LVL,std::string nom,int difficulte,int animal,int rareteAnimal) : Personnage(LVL, nom, 2, 4, 4, 30, 0, 0, 0, 0, 10, 0,animal,rareteAnimal) 
{
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(9*vie());
	}
}
void Lapin::attaqueEnnemis() {
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	
	switch (choix) {

	case 0:
		DEGATS = degats(0.1, 0.2);
		Affichage().dessinerTexte(nom() + " bondissage ");
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());

		if (attaqueDouble() && equipeEnnemi().estEnVie()) {
			Affichage().dessinerTexte(nom() + " Coup de bougnoule ");
			DEGATS = degats(0.2, 0.8);
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			ajouterMana(1);
		}
		ajouterChanceDoubleAttaque(1);
		ajouterMana(1);
		break;
	case 1:
		
		DEGATS = degats(0.3, 1.2);
		Affichage().dessinerTexte(nom() + " griffures !  ");

		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		if (attaqueDouble()) {
			DEGATS = degats(0.15, 0.6);
			Affichage().dessinerTexte(nom() + " saignement !  ");
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		}
		ajouterMana(-1);
		break;
	case 2:

		DEGATS = degats(0.1, 1.0);
		Affichage().dessinerTexte(nom() + " sautille !  ");

		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		if (attaqueDouble()) {
			DEGATS = degats(1.15, 1.6);
			Affichage().dessinerTexte(nom() + " coup de boule !  ");
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		}
		ajouterMana(-2);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + "s'enrage !");
		DEGATS = degats(1.3, 2.2);
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		ajouterChanceHabileter(5);
		ajouterMana(-3);
		break;
	}
	
}

void Lapin::passif(int tour)
{
	if ((tour+1) % 3 == 0) {
		AjouterBouclier(round(vitesse()/3.0));
	}
}

void Lapin::passifDefensif()
{
}
