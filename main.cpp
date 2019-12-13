#include "graphics.h"
#include "Point.h"
#include <ctime>
#include <cstdlib>
#include "Combat.h"
#include "Aleatoire.h"
#include "Fabian.h"
#include "Nicolas.h"
#include "Lapin.h"
#include "Experiences.h"
#include "Zones.h"
#include "Animaux.h"
#include <iostream>

#define PI 3.14159265

void nettoyerZoneAttaque() {
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	int Tab[8] = { 365,0,835,0,835,800,365,800};
	fillpoly(4, Tab);
}


int main()
{
	srand(time(0));

	initwindow(1200,800, "First Sample");
	setbkcolor(0);
	setcolor(RED);

	Experiences E;
	Zones Z;
	Orbes O;
	Animaux A;
	Equipes  Gentil(false);
	Fabian F(E,O,A);	
	Nicolas N(E,O,A);
	Gentil.ajouterPerso(&N);
	Gentil.ajouterPerso(&F);
	
	Equipes Meuchant(true);
	
	Z.equipeEnZone(3, Meuchant);
	for (int i = 0; i < Meuchant.taille(); i++) {
		Meuchant[i]->setEnnemis(Gentil);
	}
	F.setEnnemis(Meuchant);
	N.setEnnemis(Meuchant);
	
	Combat C(Gentil,Meuchant);
	
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}