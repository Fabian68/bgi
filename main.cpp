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
#include "Affichage.h"
#include "Bouton.h"

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

	
	
	Equipes  Gentil(false);
	

	
	//Gentil.chargerEquipe(choix);
//	Gentil.ajouterPerso(&N);
//	Gentil.ajouterPerso(&F);
	Equipes choix(false);
	
	
	Equipes Meuchant(true);
	
	Bouton modifierEquipe(500, 50, "Modifier equipe");
	Bouton AfficherJoueurs(500, 100, "AfficherJoueurs");
	Bouton Jouer(500, 150, "Jouer");

	const int DELAY = 50; // Milliseconds of delay between checks
	int x, y;
	while (true) {
		Experiences E;
		Zones Z;
		Orbes O;
		Animaux A;
		Affichage H;

		choix.vider();
		Fabian F(E, O, A);
		Nicolas N(E, O, A);
		choix.ajouterPerso(&F);
		choix.ajouterPerso(&N);
		Gentil.vider();
		Gentil.chargerEquipe(choix);
		modifierEquipe.afficher();
		AfficherJoueurs.afficher();
		Jouer.afficher();
		do {
			while (!ismouseclick(WM_LBUTTONDOWN)) {
				delay(DELAY);
			}
			getmouseclick(WM_LBUTTONDOWN, x, y);
		} while (!AfficherJoueurs.comprendLesCoord(x, y) && !Jouer.comprendLesCoord(x, y)&&!modifierEquipe.comprendLesCoord(x,y));

		if (AfficherJoueurs.comprendLesCoord(x, y)) {
			cleardevice();
			H.afficherJoueurs(0,choix);
		}
		else if (Jouer.comprendLesCoord(x, y)) {
			cleardevice();
			Combat C(Gentil, Meuchant, Z, A, O);
			cleardevice();
		}
		else if (modifierEquipe.comprendLesCoord(x, y)) {
			cleardevice();
			H.menuModifierEquipe(Gentil,choix,Z.nbPersoJouable()-Gentil.taille());
		}
	}
	
	
	
	
	Sleep(1000000);
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}