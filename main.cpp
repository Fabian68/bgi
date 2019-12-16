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

void reinitListeEquipe(Equipes& Liste) {
	
	Experiences E;
	Orbes O;
	Animaux A;

	Liste.vider();
	
	Fabian F(E, O, A);
	Nicolas N(E, O, A);
	Liste.ajouterPerso(new Fabian(E,O,A));
	Liste.ajouterPerso(new Nicolas(E, O, A));

}

void reinitEquipe(Equipes& monEquipe, Equipes ListePerso) {
	monEquipe.vider();
	monEquipe.chargerEquipe(ListePerso);
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
		
		Zones Z;
		Orbes O;
		Animaux A;
		Affichage H;
		
	
		Meuchant.vider();
		reinitListeEquipe(choix);
		reinitEquipe(Gentil, choix);
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
			int niveauChoisit = 1;
			int repetition = 1;
			Affichage().choixNiveau(Z, niveauChoisit,repetition);
			Z.choixNiveau(niveauChoisit);
			for (int i = 0; i < repetition; i++) {
				Meuchant.vider();
				reinitListeEquipe(choix);
				reinitEquipe(Gentil, choix);
				Z.equipeEnZone(Z.niveauActuel(), Meuchant);
				Gentil.setAllierEtEnnemis(Meuchant);
				Meuchant.setAllierEtEnnemis(Gentil);
				Combat C(Gentil, Meuchant, Z, A, O);
				cleardevice();
			}
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