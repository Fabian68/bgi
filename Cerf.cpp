#include "Cerf.h"
#include "Affichage.h"

Cerf::Cerf(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal) : Personnage(LVL, nom, 2, 6, 2, 50, 0, 0, 0, 10, 0, 0, animal, rareteAnimal)
{
	ajouterForce(force()/2);
	ajouterVitesse(vitesse()/2);
	if (difficulte == 1) {
		ajouterVie(9 * vie());
	}
	else if (difficulte == 2) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(19 * vie());
		ajouterReduction(90);
	}
	else if (difficulte == 5) {
		ajouterVie(2*vie());
		ajouterReduction(99);
	}
}

void Cerf::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	int minusVie;
	switch (choix) {

	case 0:
		DEGATS = degats(0.75, 1.5);
		Affichage().dessinerTexte(nom() + "coup de bois ! ");
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		ajouterMana(1);
		break;
	case 1:

		DEGATS = degats(1.25, 1.75);
		Affichage().dessinerTexte(nom() + " coup viser !  ");
		Attaque(DEGATS, equipeEnnemi().plusFaible());

		ajouterMana(-1);
		break;
	case 2:

		SOINS = soins(0.45, 0.75);
		Affichage().dessinerTexte(nom() + " esprit de la nature !  ");
		for (int i = 0; i < equipeAllier().taille(); i++) {
			SOINS = soins(0.45, 0.75);
			soigner(SOINS, equipeAllier()[i]);
			equipeAllier()[i]->status().ajouterCompteurProteger(1);
		}
		
		ajouterMana(-2);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + "sacrifice !");
		DEGATS = degats(10.0, 15.0);
		Attaque(DEGATS, equipeEnnemi().plusFort());
		minusVie = round(vie() * 0.999);
		reduireVie(minusVie);
		
		ajouterMana(-3);
		break;
	}
}

void Cerf::passif(int tour)
{
}

void Cerf::passifDefensif()
{
}
