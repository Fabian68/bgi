#include "Sebastien.h"
#include "Affichage.h"

Sebastien::Sebastien(Experiences E, Orbes O, Animaux A, Objets Obj) : Personnage(8, E, O, A, Obj, "Sebastien", 2, 1, 7, 20, 0, -25, 0, 0, 0, 6), pause{ 0 } {}


void Sebastien::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	double inc = 0.0;
	int cible;
	double mult = 1.0;
	switch (choix) {

	case 0:

		Affichage().dessinerTexte(nom() + " attaque a la mitraillette");
		for (int i = 0;i < 11 && equipeEnnemi().estEnVie();i++, inc += 0.01) {	
			DEGATS = degats(0.1, 0.2 + inc);
			Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			if (attaqueDouble()&& equipeEnnemi().estEnVie()) {
				DEGATS = degats(0.1, 0.2 + inc);
				Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
				inc += 0.01;
			}
			inc += 0.01;
		}
		if (attaqueDouble()) {
			for (int i = 0;i < 11 && equipeEnnemi().estEnVie();i++, inc += 0.01) {
				DEGATS = degats(0.1, 0.2 + inc);
				Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
				if (attaqueDouble() && equipeEnnemi().estEnVie()) {
					DEGATS = degats(0.1, 0.2 + inc);
					Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
					inc += 0.01;
				}
				inc += 0.01;
			}
		}
		ajouterMana(3);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " cible un ennemi au gun ! ");
		DEGATS = degats(0.25, 0.75);
		Attaque(DEGATS, equipeEnnemi().plusFaible());
		if (attaqueDouble() && equipeEnnemi().estEnVie()) {
			DEGATS = degats(0.5, 1.5);
			Attaque(DEGATS, equipeEnnemi().plusFaible());
			if (attaqueDouble() && equipeEnnemi().estEnVie()) {
				DEGATS = degats(1.0, 3.0);
				Attaque(DEGATS, equipeEnnemi().plusFaible());
			}
		}
		ajouterMana(1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " coup épée ");
		DEGATS = degats(2.0, 4.0);
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		if (attaqueDouble() && equipeEnnemi().estEnVie()) {
			DEGATS = degats(1.5, 3.0);
			Attaque(DEGATS, equipeEnnemi().plusFaible());
			
		}
		ajouterMana(-2);
		break;
	case 3:
	
		Affichage().dessinerTexte(nom() + " BAZOOKA ");
		for (int i = 0, j = equipeEnnemi().taille() - 1;i < equipeEnnemi().taille()/2 && j>=0;i++, j--,mult*=2) {
			DEGATS = degats(0.2*mult, 0.4*mult);
			Attaque(DEGATS, equipeEnnemi()[i]);

			DEGATS = degats(0.2 * mult, 0.4 * mult);
			Attaque(DEGATS, equipeEnnemi()[j]);
		}
		ajouterMana(-3);
		break;
	}
}

void Sebastien::passif(int tour)
{
	
	if ((pause + 1) % 4 == 0) {
		bouclier(bouclierMax(), this);
	}
	pause++;
}

void Sebastien::passifDefensif()
{
	ajouterChanceDoubleAttaque(1);
	pause = 0;
}
