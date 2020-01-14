#include "Elite.h"
#include "Affichage.h"

Elite::Elite(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal) : Personnage(LVL, nom, 2, 4, 4, 20, 20, 50, 0, 0, 20, 0, animal, rareteAnimal)
{
	AjouterBouclier(vieMax());
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(9 * vie());
	}
	pause = 0;
}


void Elite::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	double inc = 0.0;
	int cible;
	double mult = 1.0;
	switch (choix) {

	case 0:

		Affichage().dessinerTexte(nom() + " Mitraillette alien");
		for (int i = 0;i < 10 && equipeEnnemi().estEnVie();i++) {
			DEGATS = degats(0.2, 0.3);
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			if (attaqueDouble() && equipeEnnemi().estEnVie()) {
				DEGATS = degats(0.2, 0.3 );
				Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
				
			}
		}
		if (attaqueDouble()) {
			for (int i = 0;i < 10 && equipeEnnemi().estEnVie();i++) {
				DEGATS = degats(0.2, 0.3);
				Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
				if (attaqueDouble() && equipeEnnemi().estEnVie()) {
					DEGATS = degats(0.2, 0.3);
					Attaque(DEGATS, equipeEnnemi().plusProcheVivant());

				}
			}
		}
		ajouterMana(1);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " coup épée ");
		DEGATS = degats(2.0, 4.0);
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		if (attaqueDouble() && equipeEnnemi().estEnVie()) {
			DEGATS = degats(1.5, 3.0);
			Attaque(DEGATS, equipeEnnemi().plusFaible());

		}
		ajouterMana(-1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " WUT WUT WUT ");
		equipeEnnemi().plusProcheVivant()->ajouterReduction(-10);
		ajouterMana(1);
		break;
	case 3:

		Affichage().dessinerTexte(nom() + " U DADA ");
		this->ajouterForce(force() * 0.20);
		ajouterMana(-3);
		break;
	}
}

void Elite::passif(int tour)
{
	if ((pause + 1) % 4 == 0) {
		bouclier(bouclierMax(), this);
	}
	pause++;
}

void Elite::passifDefensif()
{
	pause = 0;
}
