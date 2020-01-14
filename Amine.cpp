#include "Amine.h"
#include "Affichage.h"	

Amine::Amine(Experiences E, Orbes O, Animaux A) : Personnage(10, E, O, A, "Amine", 1, 8, 1, 20, 50, -50, 5, 50, 0,5)
{
}

void Amine::attaqueEnnemis()
{
	int choix = choixAttaque();
	int DEGATS;
	int SOINS;
	int indice;
	double RATIO;
	
	switch (choix) {

	case 0:
		Affichage().dessinerTexte(nom() + " poings du dragon ! ");
		equipeEnnemi().plusProcheVivant()->ajouterReduction(-5);
		DEGATS = degats(1.0, 2.0);
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		ajouterMana(1);
		break;
	case 1:
		Affichage().dessinerTexte(nom() + " a la flemme ");
		SOINS = soins(0.3, 0.6);
		soigner(SOINS * 2, this);
		bouclier(SOINS, this);
		ajouterMana(1);
		break;
	case 2:
		Affichage().dessinerTexte(nom() + "se prepare ");
		ajouterMana(3);
		break;
	case 3:
		Affichage().dessinerTexte(nom() + " ASURA STRIKE ! ");
		DEGATS = degats(7.5, 12.5);
		reduireBouclier(bouclierMax());
		Attaque(DEGATS, equipeEnnemi().plusProcheVivant());
		ajouterMana(-3);
		break;
	}
}

void Amine::passif(int tour)
{
	int DEGATS;
	double ratio = equipeEnnemi().plusProcheVivant()->pourcentageReduction() / 30.0;
	
	if ((tour + 1) % 10 == 0) {
		Affichage().dessinerTexte(nom() + " fist du dragon ! ");
		DEGATS = degats(ratio, ratio / 3.0);
		AttaqueBrut(DEGATS, equipeEnnemi().plusProcheVivant());
	}
}

void Amine::passifDefensif()
{
	bouclier(niveau(), this);
}
