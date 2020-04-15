#include "SqueletteArcher.h"
#include "Affichage.h"	

SqueletteArcher::SqueletteArcher(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal, int id) : Personnage(LVL, nom, 1, 4, 5, 30, 30, 30, 3, 30, 3, 3, animal, rareteAnimal)
{
	setId(id);
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(9 * vie());
	}
}



void SqueletteArcher::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	

	Affichage().dessinerTexte(nom() + " fleches ");
	for (int i = 1; i <= 3&& equipeEnnemi().estEnVie(); i++) {
		DEGATS = degats(0.3*i, 0.3*(i+1.0));
		Attaque(DEGATS, equipeEnnemi().plusFaible());
		if (attaqueDouble() && equipeEnnemi().estEnVie()) {
			DEGATS = degats(0.3 * i, 0.3 * (i + 1.0));
			Attaque(DEGATS, equipeEnnemi().plusFaible());
		}
	}
	if (attaqueDouble() && equipeEnnemi().estEnVie()) {
		for (int i = 1; i <= 3 && equipeEnnemi().estEnVie(); i++) {
			DEGATS = degats(0.3 * i, 0.3 * (i + 1.0));
			Attaque(DEGATS, equipeEnnemi().plusFaible());
			if (attaqueDouble() && equipeEnnemi().estEnVie()) {
				DEGATS = degats(0.3 * i, 0.3 * (i + 1.0));
				Attaque(DEGATS, equipeEnnemi().plusFaible());
			}
		}
	}
	ajouterMana(1);
}

void SqueletteArcher::passif(int tour)
{
}

void SqueletteArcher::passifDefensif()
{
}
