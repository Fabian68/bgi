#include "Lapin.h"


Lapin::Lapin(int LVL) : Personnage(LVL, "Lapin", 2000, 4, 4, 30, 0, 0, 0, 0, 10, 0) {}
void Lapin::attaqueEnnemis() {
	Attaque(force()/3, equipeEnnemi().plusLoinVivant());
	
	
}