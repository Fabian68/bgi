#include "Nicolas.h"



Nicolas::Nicolas(Experiences E) : Personnage(1, E, "Niquola", 4, 3, 3, 10, 10, 50, 0, 50, 25, 0) {}
void Nicolas::attaqueEnnemis() {
	reduireVie(10);
}
