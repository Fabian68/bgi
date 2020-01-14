#include "Isidore.h"
#include "Affichage.h"

Isidore::Isidore(Experiences E, Orbes O, Animaux A) : Personnage(7, E, O, A, "Isidore", 1, 1, 8, 10, 10, 10, 10, 10, 10, 10) {}


void Isidore::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;

	int cible;
	switch (choix) {

	case 0:
		
		Affichage().dessinerTexte(nom() + "dit bonjour");
		DEGATS = degats(0.001, 0.01);
		cible = equipeEnnemi().aleatoireEnVie()->indiceEquipe();
		Attaque(DEGATS, equipeEnnemi()[cible]);

		if (habile() && equipeEnnemi()[cible]->estEnVie()) {


			Affichage().dessinerTexte(nom() + "saute sur " + equipeEnnemi()[cible]->nom());
			DEGATS = degats(1.0, 4.0);
		
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

	if ((tour + 1) % 5 == 0) {
		Affichage().dessinerTexte(nom() + "grandit ! ");
		ajouterForce(niveau() / 10);
		ajouterVieMax(niveau());
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
