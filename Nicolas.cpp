#include "Nicolas.h"



Nicolas::Nicolas(Equipes A) : Personnage(1, 50, "Niquola", 4, 3, 3, 10, 10, 50, 0, 50, 25, 0,A) {}
void Nicolas::attaqueEnnemis() {
	reduireVie(10);
}
