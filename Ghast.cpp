#include "Ghast.h"
#include "Affichage.h"

Ghast::Ghast(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal, int id) : Personnage(LVL, nom, 1, 6, 3, 0, 60, 10, 0, 0, 30, 0, animal, rareteAnimal)
{
	setId(id);
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(9 * vie());
	}
}

void Ghast::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;


	Affichage().dessinerTexte(nom() + " boule de feu ! ");
	for (int i = 0; i < equipeEnnemi().taille()&&equipeEnnemi().estEnVie(); i++) {
		DEGATS = degats(0.8, 1.6);
		Attaque(DEGATS, equipeEnnemi()[i]);
		if (habile() && equipeEnnemi().estEnVie()) {
			DEGATS = degats(0.4, 0.8);
			Attaque(DEGATS, equipeEnnemi()[i]);
		}
		if (habile() && equipeEnnemi().estEnVie()) {
			DEGATS = degats(0.3, 0.7);
			Attaque(DEGATS, equipeEnnemi()[i]);
		}
		if (habile() && equipeEnnemi().estEnVie()) {
			DEGATS = degats(0.2, 0.6);
			Attaque(DEGATS, equipeEnnemi()[i]);
		}
	}
	ajouterMana(1);
}

void Ghast::passif(int tour)
{
}

void Ghast::passifDefensif()
{
}
