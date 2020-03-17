#include "Grognard.h"
#include "Affichage.h"

Grognard::Grognard(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal) : Personnage(LVL, nom, 1, 3, 6, 50, 0, 0, 0, 0, 10, 10, animal, rareteAnimal)
{	
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(9 * vie());
	}
	else if (difficulte == 5) {
		ajouterVie(vie());
		ajouterReduction(90);
	}
}

void Grognard::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	double inc = 0.0;
	int cible;
	double mult = 1.0;
	switch (choix) {

	case 0:

		Affichage().dessinerTexte(nom() + " needler !");
		for (int i = 0;i < 10 && equipeEnnemi().estEnVie();i++) {
			DEGATS = degats(0.1, 0.2);
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			inc += 0.1;
			if (attaqueDouble() && equipeEnnemi().estEnVie()) {
				inc += 0.1;
				DEGATS = degats(0.1, 0.2);
				Attaque(DEGATS, equipeEnnemi().plusProcheVivant());

			}
		}
		if (equipeEnnemi().estEnVie()) {
			Affichage().dessinerTexte(nom() + "Explosion");
			DEGATS = degats(0.2+inc, 0.4+inc*2);
			AttaqueBrut(DEGATS, equipeEnnemi().plusProcheVivant());
		}
		ajouterMana(1);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " sauver vous ! ");
		for (int i = 0;i < equipeAllier().taille();i++) {
			equipeAllier()[i]->ajouterReduction(1);
		}
		ajouterMana(-1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " a l'aide ! ");
		for (int i = 0;i < equipeAllier().taille();i++) {
			equipeAllier()[i]->ajouterReduction(1);
		}
		ajouterMana(-1);
		break;
	case 3:

		Affichage().dessinerTexte(nom() + " SUICIDE ");
		DEGATS = degats(5.0, 10.0);
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		Attaque(DEGATS, this);
		ajouterMana(-3);
		break;
	}
}

void Grognard::passif(int tour)
{
}

void Grognard::passifDefensif()
{
}
