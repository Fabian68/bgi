#include "JeanBaptiste.h"
#include "Affichage.h"
#include "Aleatoire.h"

JeanBaptiste::JeanBaptiste(Experiences E, Orbes O, Animaux A) : Personnage(12, E, O, A, "JB", 4, 1, 5, 5, 10, 50, 15, 50, 15, 5) 
{
	ajouterVie(9 * vie());
}


void JeanBaptiste::attaqueEnnemis()
{
	if (equipeEnnemi().estEnVie()) {
		int choix = choixAttaque();
		int DEGATS;
		int SOINS;

		switch (choix) {

		case 0:
			if (devie()) {
				Affichage().dessinerTexte(nom() + " se défend ");	
				DEGATS = degats(0.5, 2.0);
				Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
			}
			else {
				ajouterMana(1);
			}
			
			
			break;
		case 1:
			Affichage().dessinerTexte(nom() + " mange sans gluten");

			SOINS = vieMax() * 0.005+vie()*0.03;
			soigner(SOINS, this);
			ajouterMana(1);
			break;
		case 2:

			Affichage().dessinerTexte(nom() + " degustation de vin ");
			for (int i = 0;i < equipeAllier().taille();i++) {
				SOINS = soins(0.66, 1.22);
				soigner(SOINS, equipeAllier()[i]);

			}
			ajouterMana(1);

			break;
		case 3:
			Affichage().dessinerTexte(nom() + " protege le plus faible ! ");
			equipeAllier().plusFaible()->ajouterReduction(20);
			ajouterMana(-3);
			break;
		}
	}
}

void JeanBaptiste::passif(int tour)
{
	int xp;
	
	if ((tour + 1) % 10 == 0) {
		Affichage().dessinerTexte(nom() + " donne de l'xp a lequipe ! ");
		if (niveau() >= 7000) {
			xp = 7000;
		}else if (niveau() >= 700) {
			xp = 700;
		}
		else if (niveau() >= 70) {
		xp = 70;
		}
		else if (niveau() >= 7) {
			xp = 7;
		}
		else {
			xp = 1;
		}
		Experiences E;
		equipeAllier().ajouterExperience(xp, E);
	}
	
	
}

void JeanBaptiste::passifDefensif()
{
}
