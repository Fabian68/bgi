#include "Sanglier.h"
#include "Affichage.h"
#include "Aleatoire.h"

Sanglier::Sanglier(int LVL, std::string nom, int difficulte, int animal, int rareteAnimal) : Personnage(LVL, nom, 4, 4, 2, 0, 30, 30, 3, 30, 0, 0, animal, rareteAnimal)
{
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(9 * vie());
	}
}




void Sanglier::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;

	switch (choix) {

	case 0:
		DEGATS = degats(0.9, 1.3);
		Affichage().dessinerTexte(nom() + " charge ");
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());

		ajouterChanceDoubleAttaque(round(force()*1.01));
		ajouterMana(1);
		break;
	case 1:

		SOINS = soins(0.5, 0.75);
		Affichage().dessinerTexte(nom() + " se repose !  ");
		soigner(SOINS, this);
		
		ajouterMana(1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " se gonfle !  ");

		ajouterChanceHabileter(3);
		ajouterForce(round(force() / 10.0));
		ajouterMana(1);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + " charge dans tout les sens ! ");
		for (int i = 1,j=1; i <= 5 && equipeEnnemi().estEnVie(); i++,j*=2) {
			DEGATS = degats(j/10.0, j/5.0);
			Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
		}
		ajouterMana(-3);
		break;
	}
}

void Sanglier::passif(int tour)
{
	int SOINS;
	if ((tour + 1) % 5 == 0) {
		SOINS = soins(0.10, 0.25);
		AjouterBouclier(SOINS);
	}
	if ((tour + 1) % 10 == 0) {
		SOINS = soins(0.25, 0.50);
		soigner(SOINS, this);
	}
}

void Sanglier::passifDefensif()
{
	int SOINS;
	if (Aleatoire(0, 101).entier() <= 10) {
		SOINS = soins(0.05, 0.10);
		AjouterBouclier(SOINS);
	}
	if (Aleatoire(0, 101).entier() <= 10) {
		SOINS = soins(0.08, 0.24);
		soigner(SOINS, this);
	}
}
