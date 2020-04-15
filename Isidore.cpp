#include "Isidore.h"
#include "Affichage.h"

Isidore::Isidore(Experiences E, Orbes O, Animaux A) : Personnage(7, E, O, A, "Isidore", 1, 1, 8, 10, 10, 10, 10, 10, 10, 10) {}


void Isidore::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	ajouterVieMax(niveau());
	int cible;
	switch (choix) {

	case 0:
		
		Affichage().dessinerTexte(nom() + "dit bonjour");
		DEGATS = degats(0.001, 0.01);
		cible = equipeEnnemi().aleatoireEnVie()->indiceEquipe();
		Attaque(DEGATS, equipeEnnemi()[cible]);

		if (habile() && equipeEnnemi()[cible]->estEnVie()) {


			Affichage().dessinerTexte(nom() + "saute sur " + equipeEnnemi()[cible]->nom());
			DEGATS = degats(1.0, 6.0);
		
			Attaque(DEGATS, equipeEnnemi()[cible]);
			ajouterMana(2);
		}
		ajouterMana(1);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " ganbade");
		for (double i = 0; i < 1.0; i += 0.01) {
			if (habile()) {
				SOINS = soins(i / 10.0, i / 10.0 + 0.01);
				soigner(SOINS, this);
			
				ajouterVieMax(vieMax()*0.01);
			}
		}
		ajouterMana(1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + "embete les ennemis ");
		for (int i = 0; i < equipeEnnemi().taille(); i++) {

			equipeEnnemi()[i]->ajouterReduction(-3);

		}
		ajouterMana(-2);
		break;
	case 3:
		cible = equipeEnnemi().aleatoireEnVie()->indiceEquipe();
		Affichage().dessinerTexte(nom() + " encule " + equipeEnnemi()[cible]->nom());
		DEGATS = degats(2.0, 5.0);
		Attaque(DEGATS, equipeEnnemi()[cible]);
		ajouterMana(-3);
		break;
	}
}

void Isidore::passif(int tour)
{
	ajouterVieMax(niveau()/10);
	if ((tour + 1) % 5 == 0) {
		if (habile() || attaqueDouble()) {
			ajouterForce(niveau() / 10);
			ajouterVieMax(niveau()*10);
		}
		else {
			ajouterForce(niveau() / 10);
			ajouterVieMax(niveau());
		}
		Affichage().dessinerTexte(nom() + "grandit ! ");
		
	}
	if ((tour + 1) % 30 == 0) {
		Affichage().dessinerTexte(nom() + "se repose ! ");
		soigner(vieMax(), this);
		bouclier(vieMax(), this);
	}
	
}

void Isidore::passifDefensif()
{
}
