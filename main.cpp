#include "graphics.h"
#include "Point.h"
#include <ctime>
#include <cstdlib>
#include "Combat.h"
#include "Aleatoire.h"
#include "Fabian.h"
#include "Nicolas.h"
#include "Thomas.h"
#include "Lapin.h"
#include "Experiences.h"
#include "Zones.h"
#include "Animaux.h"
#include <iostream>
#include "Affichage.h"
#include "Bouton.h"
#include "Fiona.h"
#include "Moustick.h"
#include "Bryan.h"
#include "David.h"
#include "Isidore.h"
#include "Sebastien.h"
#include "Cloe.h"
#include "Amine.h"
#include "Florian.h"
#include "JeanBaptiste.h"
#include "Maelle.h"
#include "Pollyana.h"
#include "Salim.h"
#include "Affinites.h"
#include "Conseils.h"
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
	Objets Obj;
	Liste.liberer();
	
	Liste.ajouterPerso(new Fabian(E,O,A,Obj));
	Liste.ajouterPerso(new Nicolas(E, O, A, Obj));
	Liste.ajouterPerso(new Thomas(E, O, A, Obj));
	Liste.ajouterPerso(new Fiona(E, O, A, Obj));
	Liste.ajouterPerso(new Moustick(E, O, A, Obj));
	Liste.ajouterPerso(new Bryan(E, O, A, Obj));
	Liste.ajouterPerso(new David(E, O, A, Obj));
	Liste.ajouterPerso(new Isidore(E, O, A, Obj));
	Liste.ajouterPerso(new Sebastien(E, O, A, Obj));
	Liste.ajouterPerso(new Cloe(E, O, A, Obj));
	Liste.ajouterPerso(new Amine(E, O, A, Obj));
	Liste.ajouterPerso(new Florian(E,O,A, Obj));
	Liste.ajouterPerso(new JeanBaptiste(E, O, A, Obj));
	Liste.ajouterPerso(new Maelle(E, O, A, Obj));
	Liste.ajouterPerso(new Pollyana(E, O, A, Obj));
	Liste.ajouterPerso(new Salim(E, O, A, Obj));

}

void reinitEquipe(Equipes& monEquipe, Equipes & ListePerso) {
	monEquipe.vider();
	monEquipe.chargerEquipe(ListePerso);
}
int main()
{
	srand(time(0));

	initwindow(1200,800, "First Sample");
	setbkcolor(0);
	setcolor(RED);
	Affinites();
	
	
	Equipes  Gentil(false);
	

	
	//Gentil.chargerEquipe(choix);
//	Gentil.ajouterPerso(&N);
//	Gentil.ajouterPerso(&F);
	Equipes choix(false);
	
	Conseils C;
	Equipes Meuchant(true);
	
	Bouton modifierEquipe(500, 50, "Modifier equipe");
	Bouton AfficherJoueurs(500, 100, "AfficherJoueurs");
	Bouton AfficherAnimaux(500, 150, "AfficherAnimaux");
	Bouton Jouer(500, 200, "Jouer");
	Bouton Conseil(100, 300, C.conseilAleatoire());
	

	const int DELAY = 50; // Milliseconds of delay between checks
	int x, y;
	while (true) {
		
		Zones Z;
		Orbes O;
		Animaux A;
		Objets Obj;
		Affichage H;
		
		H.dessinerTexte("Version 2.02 ");
		Meuchant.liberer();
		reinitListeEquipe(choix);
		reinitEquipe(Gentil, choix);
		modifierEquipe.afficher();
		AfficherJoueurs.afficher();
		AfficherAnimaux.afficher();
		Jouer.afficher();
		Bouton Conseil(100, 300, C.conseilAleatoire());
		Conseil.afficher();
		do {
			while (!ismouseclick(WM_LBUTTONDOWN)) {
				delay(DELAY);
			}
			getmouseclick(WM_LBUTTONDOWN, x, y);
		} while (!AfficherJoueurs.comprendLesCoord(x, y) && !Jouer.comprendLesCoord(x, y)&&!modifierEquipe.comprendLesCoord(x,y) && !AfficherAnimaux.comprendLesCoord(x, y));

		if (AfficherJoueurs.comprendLesCoord(x, y)) {
			cleardevice();
			H.afficherJoueurs(0,choix);
		}
		else if (AfficherAnimaux.comprendLesCoord(x, y)) {
			cleardevice();
			H.afficherAnimaux(A);
		}
		else if (Jouer.comprendLesCoord(x, y)) {
			cleardevice();
			int niveauChoisit = Z.niveauActuel();
			int repetition = 1;
			Affichage().choixNiveau(Z,Obj, niveauChoisit,repetition);
			Z.choixNiveau(niveauChoisit);
			for (int i = 0; i < repetition; i++) {
				std::cout << i+1 << std::endl;
				Orbes O;
				Animaux A;
				Meuchant.liberer();
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