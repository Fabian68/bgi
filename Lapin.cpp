#include "Lapin.h"


Lapin::Lapin(int LVL,int difficulte,int animal,int rareteAnimal) : Personnage(LVL, "Lapin", 2, 4, 4, 30, 0, 0, 0, 0, 10, 0,animal,rareteAnimal) 
{
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(9*vie());
	}
}
void Lapin::attaqueEnnemis() {
	Attaque(force()/3, equipeEnnemi().plusLoinVivant());
	bouclier(50, this);
	
}

void Lapin::passif(int tour)
{
}

void Lapin::passifDefensif()
{
}
