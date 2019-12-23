#include "Cloe.h"
#include "Affichage.h"

Cloe::Cloe(Experiences E, Orbes O, Animaux A) : Personnage(9, E, O, A, "Cloe", 1, 6, 3, 25, 25, -50, 0, 0, 0, 0) {}


void Cloe::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	double ratio = (vitesse() * 1.0) / (force() * 1.0);
	int cible;
	switch (choix) {

	case 0:

	
		Affichage().dessinerTexte(nom() + " viens jouer  ");
		for (int i = 0;i < equipeAllier().taille();i++) {
			if (habile()) {
				SOINS = soins(0.1, 0.2);
				bouclier(SOINS, equipeAllier()[i]);
				if (attaqueDouble()) {
					SOINS = soins(0.1, 0.2);
					bouclier(SOINS, equipeAllier()[i]);
				}
			}
			if (attaqueDouble()) {
				SOINS = soins(0.1, 0.2);
				bouclier(SOINS, equipeAllier()[i]);
				if (habile()) {
					SOINS = soins(0.1, 0.2);
					bouclier(SOINS, equipeAllier()[i]);
				}
			}
		}
		if (attaqueDouble()) {
			for (int i = 0;i < equipeAllier().taille();i++) {
				if (habile()) {
					SOINS = soins(0.1, 0.2);
					bouclier(SOINS, equipeAllier()[i]);
					if (attaqueDouble()) {
						SOINS = soins(0.1, 0.2);
						bouclier(SOINS, equipeAllier()[i]);
					}
				}
				if (attaqueDouble()) {
					SOINS = soins(0.1, 0.2);
					bouclier(SOINS, equipeAllier()[i]);
					if (habile()) {
						SOINS = soins(0.1, 0.2);
						bouclier(SOINS, equipeAllier()[i]);
					}
				}
			}
		}
		ajouterMana(1);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " fais un calin ! ");
		cible = equipeAllier().aleatoireEnVie()->indiceEquipe();
		if (cible != this->indiceEquipe()) {
			if (!habile()) {
				equipeAllier()[cible]->ajouterForce(niveau() / 20);
				equipeAllier()[cible]->ajouterReduction(3);
			}
			else {
				equipeAllier()[cible]->ajouterForce(niveau() / 10);
				equipeAllier()[cible]->ajouterReduction(6);
			}
		}

		ajouterMana(1);
		break;
	case 2:
		Affichage().dessinerTexte(nom() + " soigne l'équipe ! ");
		for (int i = 0,j=1;i < equipeAllier().taille();i++,j*=2) {
			SOINS = soins(0.1 * j, 0.2 * j);
			soigner(SOINS, equipeAllier()[i]);
		}
		ajouterMana(-2);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + "balance de la KPOP ");
		DEGATS = degats(1.0, 2.0);
		equipeEnnemi().attaqueZone(DEGATS, this);
		ajouterMana(-3);
		break;
	}
}

void Cloe::passif(int tour)
{
	if ((tour + 1) % 5 == 0) {
		Affichage().dessinerTexte(nom() + " est fatiguer ");
		reduireVie(vie() * 0.05);
	}
}

void Cloe::passifDefensif()
{
	ajouterReduction(1);
}
