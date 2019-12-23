#include "Thomas.h"
#include "Affichage.h"
#include "Aleatoire.h"
Thomas::Thomas(Experiences E, Orbes O, Animaux A) : Personnage(2, E, O, A, "Thomas", 6, 3, 1, 0, 10, 80, 3, 8, 0, 3)
{
}

void Thomas::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	int indice;
	switch (choix) {

	case 0:
		DEGATS = degats(0.15, 0.45);
		DEGATS += round(0.10 * vie()+0.05 * vieMax());
		Affichage().dessinerTexte(nom() + " coup de bide ! ");
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		if (chanceHabileter() > Aleatoire(0, 101).entier()) {
			Affichage().dessinerTexte(nom() + " pete un gros coups, ca asphyxie tout le monde ! ");
			for (int i = 0; i < equipeEnnemi().taille() ; i++) {
				DEGATS = round(Aleatoire(0.02, 0.06).decimal() * (vie()*1.0 + bouclier()*1.0));
				Attaque(DEGATS, equipeEnnemi()[i]);
			}
			ajouterMana(1);
		}
	
		ajouterMana(1);
		break;
	case 1:

		Affichage().dessinerTexte(nom() + " saut dans le tas !  ");
		for (int i = 0; i < equipeEnnemi().taille() / 2; i++) {
			DEGATS = degats(0.10+i*0.10, 0.20+i*0.20);
			Attaque(DEGATS, equipeEnnemi()[i]);

			DEGATS = degats(0.10 + i * 0.10, 0.20 + i * 0.20);
			indice = abs(equipeEnnemi().taille() - 1 - i);
			Attaque(DEGATS, equipeEnnemi()[indice]);
		}
		ajouterMana(-1);
		break;
	case 2:

		Affichage().dessinerTexte(nom() + " ramene de la bouffe !  ");
		for (int i = 0 ; i < equipeAllier().taille(); i++) {
			SOINS = soins(0.08, 0.32);
			soigner(SOINS, equipeAllier()[i]);
		}
		ajouterMana(1);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + " J'ai bian manger j'ai bien bu ! ");
		DEGATS = round(0.13 * vie() + 0.02 * vieMax() + 0.15 * bouclier()+0.10*force());
		Attaque(DEGATS, equipeEnnemi().aleatoireEnVie());
		ajouterMana(-3);
		break;
	}
}

void Thomas::passif(int tour)
{
	int SOINS;
	if ((tour + 1) % 5 == 0) {
		SOINS = soins(0.30, 0.60);
		soigner(SOINS, this);
	}
}

void Thomas::passifDefensif()
{
	if (Aleatoire(0, 101).entier() <= 10) {
		AjouterBouclier(round(vieMax()*0.02));
	
	}
}
