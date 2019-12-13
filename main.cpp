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
	
	/*
	for (size_t i = 0; i <= 3000; i++)
	{
		dessinerAttaque(static_cast<int>(frand_a_b(1.0, 9.0)), static_cast<int>(frand_a_b(1.0, 9.0)), static_cast<int>(frand_a_b(0.0, 2.0)));
		delay(200);
		nettoyerZoneAttaque();
	}*/

	
	
	Experiences E;
	Equipes  Gentil(false);
	E.ajouterXP(0, 100);
	Fabian F(E);
	
	Nicolas N(E);
	Gentil.ajouterPerso(&N);
	Gentil.ajouterPerso(&F);
	
	Equipes Meuchant(true);
	Lapin L(5);

	Meuchant.ajouterPerso(&L);
	
	F.setEnnemis(Meuchant);
	N.setEnnemis(Meuchant);
	L.setEnnemis(Gentil);
	Combat C(Gentil,Meuchant);
	/*Affichage Hi;
	Hi.dessinerDeuxEquipes(Gentil,Meuchant);
	for (int i = 0;i <= 100000000000;i++) {
		Attaque(Gentil.perso(1), Meuchant, Gentil);
	
		//Attaque(Didier, Gentil, Meuchant);
		//std::cout << Fabian.vie() <<" "<<Gentil[1].vie()<<std::endl;
		delay(500);
		Hi.dessinerDeuxEquipes(Gentil, Meuchant);

	}*/
	
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}