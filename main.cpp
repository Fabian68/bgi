#include "graphics.h"
#include "Point.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include "Combat.h"
#include "Aleatoire.h"


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

	
	Personnage Fabian(1, 1, "Fabian", 2000, 4, 4, 100, 100, 70, 0, 0, 7, 17, 0);
	Personnage Nicolas(1, 1, "Niquola", 2, 4, 4, 10, 10, 10, 0, 0, 7, 17, 0);
	Equipes Gentil(false);
	Gentil.ajouterPerso(Nicolas);
	Gentil.ajouterPerso(Fabian);

	Personnage Didier(1, 1, "Didier", 8, 1, 1,10,10,75,5,50,15,5,1);
	Personnage LOOL(1, 1, "LOL", 6, 2, 2,10,10,10,10,10,10,10,1) ;
	Personnage THOMY(1, 1, "THOMY", 6, 2, 2, 10,10,50,75,50,0,0,1);
	Personnage SACAPV(1, 3, "PVVV", 100, 10, 10, 0, 0, 0, 0, 0, 0, 0, 1);
	Equipes Meuchant(true);
	Meuchant.ajouterPerso(Didier);
	Meuchant.ajouterPerso(LOOL);
	Meuchant.ajouterPerso(THOMY);
	Meuchant.ajouterPerso(SACAPV);
	Combat(Gentil, Meuchant);
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