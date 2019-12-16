#include "Nicolas.h"
#include "Aleatoire.h"
#include "Affichage.h"


Nicolas::Nicolas(Experiences E,Orbes O,Animaux A) : Personnage(1, E,O,A, "Niquola", 4, 3, 3, 10, 10, 50, 0, 50, 25, 0) {}
void Nicolas::attaqueEnnemis() {
	//equipeEnnemi().attaqueZone(25, this);
	//equipeAllier().soignerZone(25, this);
}

void Nicolas::passif(int tour)
{
	if (tour>100) {
		int Degats = degats(tour/10.0, tour/5.0);
		Affichage().dessinerTexte(this->nom() + " est enerver le combat est trop long ! ");
		equipeEnnemi().attaqueZone(Degats, this);
	}
}

void Nicolas::passifDefensif()
{
	if (Aleatoire(0, 101).entier() <= 10) {
		int Degats = degats(0.10, 0.25);
		Affichage().dessinerTexte(this->nom() + " contre attaque ");
		Attaque(Degats, equipeEnnemi().plusProcheVivant());
	}
}
