#include "David.h"
#include "Aleatoire.h"
#include "Affichage.h"

David::David(Experiences E, Orbes O, Animaux A) : Personnage(6, E, O, A, "David", 2, 2, 6, 0, 30, 0, 3, 0, 0, 3) {}


void David::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	double ratio = (vitesse() * 1.0) / (force() * 1.0);

	switch (choix) {

	case 0:
		
		DEGATS = degats(0.4, 0.8);
		Affichage().dessinerTexte(nom() + " joue du diabolo ");
		for (int i = 0;i < 5 && equipeEnnemi().estEnVie();i++) {
			if (habile()) {
				DEGATS = Aleatoire(0.0, 1.0).decimal() * vitesse();
				Attaque(DEGATS, equipeEnnemi().plusFaible());	
				ajouterMana(1);
			}		
		}
		
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " joue de la guitare ");

		if (!habile()) {
			for (int i = 0;i < equipeEnnemi().taille();i++) {
				DEGATS = degats(ratio / 6.0, ratio / 3.0);
				Attaque(DEGATS, equipeEnnemi()[i]);
			}
		}
		else {
			for (int i = 0;i < equipeAllier().taille();i++) {
				SOINS = soins(ratio / 8.0, ratio / 4.0);
				soigner(SOINS, equipeEnnemi()[i]);

				SOINS = soins(ratio / 10.0, ratio / 5.0);
				bouclier(SOINS, equipeEnnemi()[i]);
			}
		}
		ajouterMana(+1);
		break;
	case 2:
		passif(0);
		ajouterMana(-2);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + " roule sur les ennemis ");
		double j;
		for (int i = 0, j = 0.02;i < equipeEnnemi().taille();i++) {
			if (equipeEnnemi()[i]->estEnVie()) {
				DEGATS = static_cast<int>(Aleatoire(j, j * 2).decimal() * (vitesse()*1.0));
				Attaque(DEGATS, equipeEnnemi()[i]);
				j *=2;
			}
		}
		ajouterMana(-3);
		break;
	}
}

void David::passif(int tour)
{
	Affichage().dessinerTexte(nom() + " s'enfile une desperado ");
	int SOINS = static_cast<int>(0.059 * vieMax());
	soigner(SOINS, this);
}

void David::passifDefensif()
{
}
