#include "Lapin.h"


Lapin::Lapin(Equipes A,int LVL) : Personnage(3, LVL, "Lapin", 2, 4, 4, 30, 0, 0, 0, 0, 10, 0, A) {}
void Lapin::attaqueEnnemis() {
	Attaque(force()/10, equipeEnnemi().plusProcheVivant());
	
	
}