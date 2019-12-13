#include "Lapin.h"


Lapin::Lapin(int LVL,int difficulte) : Personnage(LVL, "Lapin", 2, 4, 4, 30, 0, 0, 0, 0, 10, 0,-1,0) 
{
	if (difficulte == 1) {
		ajouterForce(force());
		ajouterVitesse(vitesse());
		ajouterVie(9*vie());
	}
}
void Lapin::attaqueEnnemis() {
	Attaque(force()/3, equipeEnnemi().plusLoinVivant());
	
	
}