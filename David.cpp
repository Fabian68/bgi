#include "David.h"
#include "Aleatoire.h"
#include "Affichage.h"

David::David(Experiences E, Orbes O, Animaux A, Objets Obj) : Personnage(6, E, O, A, Obj, "David", 2, 2, 6, 0, 30, 0, 3, 0, 0, 3) {}


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
				DEGATS = Aleatoire(0.2, 1.25).decimal() * vitesse();
				Attaque(DEGATS, equipeEnnemi().plusFaible());	
				ajouterMana(1);
			}		
		}
		
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " joue de la guitare ");

		if (!habile()) {
			for (int i = 0;i < equipeEnnemi().taille();i++) {
				DEGATS = degats(ratio / 4.0, ratio / 2.0);
				Attaque(DEGATS, equipeEnnemi()[i]);
			}
		}
		else {
			for (int i = 0;i < equipeAllier().taille();i++) {
				SOINS = soins(ratio / 4.0, ratio / 2.0);
				soigner(SOINS, equipeAllier()[i]);

				SOINS = soins(ratio / 5.0, ratio / 2.5);
				bouclier(SOINS, equipeAllier()[i]);
			}
		}
		ajouterMana(+1);
		break;
	case 2:
		passif(0);
		ajouterMana(1);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + " roule sur les ennemis ");
		double j;
		for (int i = 0, j = 0.02;i < equipeEnnemi().taille();i++) {
			if (equipeEnnemi()[i]->estEnVie()) {
				DEGATS = static_cast<int>(Aleatoire(j, j * 2).decimal() * (vitesse()*1.0));
				Attaque(DEGATS, equipeEnnemi()[i]);	
				if (habile()) {
					DEGATS = static_cast<int>(Aleatoire(j, j * 2).decimal() * (vitesse() * 1.0));
					AttaqueBrut(DEGATS, equipeEnnemi()[i]);
				}
				j *= 2;
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
