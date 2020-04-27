#include "Rapace.h"
#include "Affichage.h"

Rapace::Rapace(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal) : Personnage(LVL, nom, 1, 2, 7, 50, 0, 0, 0, 50, 50, 10, animal, rareteAnimal)
{
	AjouterBouclier(bouclierMax());
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(9 * vie());
	}
}


void Rapace::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	double inc = 0.0;
	int cible;
	double mult = 1.0;
	switch (choix) {

	case 0:

		Affichage().dessinerTexte(nom() + " Assaut");
		DEGATS = degats(0.6, 0.9);
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		if (attaqueDouble()) {
			DEGATS = degats(0.6, 0.9);
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			ajouterMana(1);
		}
		ajouterMana(1);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + "roulade sur le coter ");
		ajouterForce(niveau() / 10);
		ajouterMana(-1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + "SNIPE ");
		DEGATS = degats(1.0, 6.0);
		Attaque(DEGATS, equipeEnnemi().plusFaible());
		if (attaqueDouble()) {
			DEGATS = degats(1.0, 6.0);
			AttaqueBrut(DEGATS, equipeEnnemi().plusFaible());
		}
		ajouterMana(-2);
		break;
	case 3:

		Affichage().dessinerTexte(nom() + " protege alliers ");
		for (int i = 0;i < equipeAllier().taille();i++) {
			equipeAllier()[i]->ajouterReduction(5);
		}
		ajouterMana(-3);
		break;
	}
}

void Rapace::passif(int tour)
{
	if ((tour + 1) % 10 == 0) {
		AjouterBouclier(bouclierMax());
	}
	status().ajouterCompteurProteger(1);
}

void Rapace::passifDefensif()
{
}
