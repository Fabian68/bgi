#include "Affichage.h"
#include "Equipes.h"
#include "Personnage.h"
#include "Bouton.h"
#include "Zones.h"
#include  <iostream>

Affichage::Affichage()
{
}
void afficherTexte(int x, int y, std::string texte) {
	char *perso = const_cast<char*>(texte.c_str());
	outtextxy(x, y, perso);
}

void Affichage::animationCercle(int xDepart, int yDepart, int xArriver, int yArriver) const
{
	int delais = 18;
	int pasX = static_cast<int>((xArriver*1.0 - xDepart*1.0) / 30.0);
	int pasY = static_cast<int>((yArriver*1.0 - yDepart*1.0) / 30.0);
	std::cout << pasY;
	setcolor(RED);
	setfillstyle(1, RED);
	fillellipse(xDepart, yDepart, 10, 10);
	delay(delais);
	for (int i = 1; i <= 31; i++) {
	 	setcolor(BLACK);
		setfillstyle(1, BLACK);
		fillellipse(xDepart + (i - 1) * pasX, yDepart + (i - 1) * pasY, 11, 11);
		setcolor(RED);
		setfillstyle(1, RED);
		circle(xDepart + i * pasX, yDepart + i * pasY, 10);
		fillellipse(xDepart + i * pasX, yDepart + i * pasY, 10, 10);
		delay(delais);
	}
}

void Affichage::afficherJoueurs(int indice,Equipes Liste)const {
	int x = 50;
	int y = 20;
	std::string str;
	setbkcolor(BLACK);
	setcolor(WHITE);		
		str = "Pseudo : "+Liste[indice]->nom();
		afficherTexte(x, y, str);
	
		str = "Niveau : " +std::to_string(Liste[indice]->niveau());
		afficherTexte(x, y+20, str);

		str = "Force : "  +std::to_string(Liste[indice]->force());
		afficherTexte(x, y+40, str);

		str = "Vie : "  +std::to_string(Liste[indice]->vieMax());
		afficherTexte(x, y+60, str);

		str = "Vitesse : "  +std::to_string(Liste[indice]->vitesse());
		afficherTexte(x, y+80, str);

		str = "Chance de double attaque : "  +std::to_string(Liste[indice]->chanceDoubleAttaque());
		afficherTexte(x, y+100, str);

		str = "Chance de coup habile : "  +std::to_string(Liste[indice]->chanceHabileter());
		afficherTexte(x, y+120, str);

		str = "Chance de deviation : "  +std::to_string(Liste[indice]->pourcentageDeviation());
		afficherTexte(x, y+140, str);

		str = "Pourcentage de reduction de degats : "  +std::to_string(Liste[indice]->pourcentageReduction());
		afficherTexte(x, y+160, str);

		str = "Chance de ricochet : " + std::to_string(Liste[indice]->pourcentageRicochet());
		afficherTexte(x, y+180, str);

		str = "Chance esquive : " + std::to_string(Liste[indice]->pourcentageEsquive());
		afficherTexte(x, y+200, str);

		str = "Chance de blocage : " + std::to_string(Liste[indice]->pourcentageBlocage());
		afficherTexte(x, y+220, str);
	
		Bouton Retour(300,600, "RETOUR");
		Retour.afficher();
		Bouton Suivant(600, 600, "Suivant");
		Suivant.afficher();
		const int DELAY = 50; // Milliseconds of delay between checks
		int xc, yc;
			do {
				while (!ismouseclick(WM_LBUTTONDOWN)) {
					delay(DELAY);
				}
				getmouseclick(WM_LBUTTONDOWN, xc, yc);
			} while (!Retour.comprendLesCoord(xc, yc) && !Suivant.comprendLesCoord(xc, yc));

			if (Suivant.comprendLesCoord(xc, yc)) {
				indice = (indice + 1) % Liste.taille();
				cleardevice();
				afficherJoueurs(indice, Liste);
			}	
	cleardevice();
}
void Affichage::dessinerJoueur(int indice, bool equipeIA,Personnage*  P) const
{
	int x;
	if (equipeIA) {
		x = 1200 - 360;
	}
	else {
		x = 60;
	}
	std::string str = P->nom()+" "+std::to_string(P->niveau());
	char* perso = const_cast<char*>(str.c_str());
//	setcolor(GREEN);
	int y = -50 + 70 * indice;
	rectangle(x, y, x + 300, y + 65);
	outtextxy(x + 2, y + 5, perso);
	int pourcentageVie = P->pourcentageVie();
	int pourcentageBouclier = P->pourcentageBouclier();
	setfillstyle(1, GREEN);
	int Tab[8] = { x + 2,y + 25,x + 2 + pourcentageVie*2,y + 25,x + 2 + pourcentageVie * 2,y + 40,x + 2,y + 40 };
	fillpoly(4, Tab);

	setfillstyle(1, BLACK);
	int Tab3[8] = { x + 2 + pourcentageVie * 2,y + 25,x + 202,y + 25,x + 202,y + 40,x + 2 + pourcentageVie * 2,y + 40 };
	fillpoly(4, Tab3);
	// y 45 et 60
	setfillstyle(1, MAGENTA);
	int Tab2[8] = { x + 2,y + 45,x +2 + pourcentageBouclier*2,y + 45,x + 2 + pourcentageBouclier*2,y + 60,x + 2,y + 60 };
	fillpoly(4, Tab2);

	setfillstyle(1, BLACK);
	int Tab4[8] = { x + 2 + pourcentageBouclier * 2,y + 45,x + 202,y + 45,x + 202,y + 60,x + 2 + pourcentageBouclier * 2,y + 60 };
	fillpoly(4, Tab4);

}

void Affichage::dessinerDegats(Personnage* P, int degats) const {
	int x;
	if (P->equipeAllier().ia()) {
		x = 1200 - 150;
		
	}
	else {
		x = 270;
	}
	int y = -20 + 70 * (P->indiceEquipe()+1);
	setcolor(BLACK);
	setfillstyle(1,BLACK);
	int Tab[8] = { x - 5,y -5,x +80 ,y -5,x+80 ,y + 20,x -5,y + 20 };
	fillpoly(4, Tab);
	std::string texte = " - " + std::to_string(degats);
	setcolor(RED);
	char* txt = const_cast<char*>(texte.c_str());
	outtextxy(x, y,txt);
	delay(250);
}

void Affichage::dessinerSoins(Personnage* P, int soins) const {
	int x;
	if (P->equipeAllier().ia()) {
		x = 1200 - 150;
	}
	else {
		x = 270;
	}
	int y = -20 + 70 * (P->indiceEquipe() + 1);
	setcolor(BLACK);
	setfillstyle(1, BLACK);
	int Tab[8] = { x - 5,y - 5,x + 80 ,y - 5,x + 80 ,y + 20,x - 5,y + 20 };
	fillpoly(4, Tab);
	setcolor(GREEN);
	std::string texte = " + " + std::to_string(soins);
	
	char* txt = const_cast<char*>(texte.c_str());
	outtextxy(x, y, txt);
	delay(250);
}

void Affichage::dessinerBouclier(Personnage* P, int soins) const {
	int x;
	if (P->equipeAllier().ia()) {
		x = 1200 - 150;
	}
	else {
		x = 270;
	}
	int y = -20 + 70 * (P->indiceEquipe() + 1);
	setcolor(BLACK);
	setfillstyle(1, BLACK);
	
	int Tab[8] = { x - 5,y - 5,x + 80 ,y - 5,x + 80 ,y + 20,x - 5,y + 20 };
	fillpoly(4, Tab);
	setcolor(MAGENTA);
	std::string texte = " + " + std::to_string(soins);

	char* txt = const_cast<char*>(texte.c_str());
	outtextxy(x, y, txt);
	delay(250);
}

void Affichage::dessinerTexte(std::string texte)const {
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	int Tab[8] = { 365,0,835,0,835,30,365,30 };
	fillpoly(4, Tab);
	setcolor(RED);
	char* txt = const_cast<char*>(texte.c_str());
	outtextxy(400,15, txt);	
	delay(200);
}
void Affichage::dessinerEquipeJoueur(Equipes J) const
{
	for (int i = 0;i < J.taille();i++) {
		dessinerJoueur(i + 1, false, J.perso(i));
	}
}

void Affichage::dessinerEquipeIA(Equipes I) const
{
	for (int i = 0;i < I.taille();i++) {
		dessinerJoueur(i + 1, true, I.perso(i));
	}
}

void Affichage::choixNiveau(Zones Z, int & niveau,int & repetition) const
{
	
	int niveauMax = Z.niveauMax();
	if (niveau < 1) {
		niveau = 1;
	}
	else if (niveau > niveauMax) {
		niveau = niveauMax;
	}
	if (repetition < 1) {
		repetition = 1;
	}
	else if (repetition > 100) {
		repetition = 100;
	}

	afficherTexte(100, 100, "Choix du niveau, niveau max = "+std::to_string(niveauMax));
	Bouton plus1(100, 200, " + 1 ");
	Bouton moins1(100, 300, " - 1 ");
	Bouton plus10(200, 200, " + 10 ");
	Bouton moins10(200, 300, " - 10 ");
	Bouton niveauActuel(350, 100, std::to_string(niveau));
	
	afficherTexte(400, 100, "Choix du nombre de repetition, max = 100 ");
	Bouton plus1r(400, 200, " + 1 ");
	Bouton moins1r(400, 300, " - 1 ");
	Bouton plus10r(500, 200, " + 10 ");
	Bouton moins10r(500, 300, " - 10 ");
	Bouton repetitionActuel(600, 100, std::to_string(repetition));
	
	Bouton confirmer(150, 400, "Confirmer");
	
	plus1.afficher();
	moins1.afficher();
	plus10.afficher();
	moins10.afficher();
	niveauActuel.afficher();

	confirmer.afficher();

	plus1r.afficher();
	moins1r.afficher();
	plus10r.afficher();
	moins10r.afficher();
	repetitionActuel.afficher();

	bool bouttonHit = false;
	const int DELAY = 50; // Milliseconds of delay between checks
	int xc, yc;
	do {
		while (!ismouseclick(WM_LBUTTONDOWN)) {
			delay(DELAY);
		}
		getmouseclick(WM_LBUTTONDOWN, xc, yc);

		if (plus1.comprendLesCoord(xc, yc)) {
				
			bouttonHit = true;
			choixNiveau(Z, ++niveau,repetition);
		}else if (plus10.comprendLesCoord(xc, yc)) {
			bouttonHit = true;
			niveau = niveau + 10;
			choixNiveau(Z, niveau,repetition);
		}else if (moins1.comprendLesCoord(xc, yc)) {

			bouttonHit = true;
			choixNiveau(Z, --niveau,repetition);
		}
		else if (moins10.comprendLesCoord(xc, yc)) {
			bouttonHit = true;
			niveau = niveau - 10;
			choixNiveau(Z, niveau,repetition);
		}
		else if (plus1r.comprendLesCoord(xc, yc)) {

			bouttonHit = true;
			choixNiveau(Z, niveau, ++repetition);
		}
		else if (plus10r.comprendLesCoord(xc, yc)) {
			bouttonHit = true;
			repetition += 10;
			choixNiveau(Z, niveau, repetition);
		}
		else if (moins1r.comprendLesCoord(xc, yc)) {

			bouttonHit = true;
			choixNiveau(Z, niveau, --repetition);
		}
		else if (moins10r.comprendLesCoord(xc, yc)) {

			bouttonHit = true;
			repetition -= 10;
			choixNiveau(Z, niveau, repetition);
		}
	} while (!confirmer.comprendLesCoord(xc,yc)&&!bouttonHit);
	cleardevice();
}

void Affichage::menuModifierEquipe(Equipes& Gentil, Equipes choix,int max) const
{
	afficherTexte(100, 20, "Equipe actuel");
	for (int i = 0; i < Gentil.taille(); i++) {
		Bouton(100, (i + 1) * 50, std::to_string(i) + Gentil[i]->nom()).afficher();
	}
	if (max > 0) {
		afficherTexte(400, 20, "Personnages selectionnable");
		for (int i = 0; i < choix.taille(); i++) {
			Bouton(400, (i + 1) * 50, std::to_string(i) + choix[i]->nom()).afficher();
		}
	}
	else {
		afficherTexte(400, 20, "Maximum de personnages selectionnable atteintes");
	}
	Bouton retirer(200, 400, "Retirer le dernier personnage");
	if (Gentil.taille() > 0) {
		retirer.afficher();
	}

	Bouton Sauvegarder(400, 400, "Sauvegarder");
	Sauvegarder.afficher();
	Bouton Retour(600, 400, "Retour");
	Retour.afficher();
	const int DELAY = 50; // Milliseconds of delay between checks
	int xc, yc;
	bool boutonSelectionnerPerso = false;
	bool boutonSelectionnerAutre = false;
	do {
		while (!ismouseclick(WM_LBUTTONDOWN)) {
			delay(DELAY);
		}
		getmouseclick(WM_LBUTTONDOWN, xc, yc);
		if (max > 0) {
			for (int i = 0; i < choix.taille(); i++) {
				if (Bouton(400, (i + 1) * 50, std::to_string(i) + choix[i]->nom()).comprendLesCoord(xc, yc)) {
					Gentil.ajouterPerso(choix[i]);
					boutonSelectionnerPerso = true;
					menuModifierEquipe(Gentil, choix, --max);
				}
			}
		}
		if (Gentil.taille() > 0) {
			if (retirer.comprendLesCoord(xc, yc)) {
				boutonSelectionnerAutre = true;
				Gentil.retirerDernierPerso();
				cleardevice();
				menuModifierEquipe(Gentil, choix, ++max);
			}
		}
		if (Sauvegarder.comprendLesCoord(xc, yc)) {
			Gentil.sauvegarderEquipe();
			boutonSelectionnerAutre = true;
			menuModifierEquipe(Gentil, choix, max);
		}
		else if (Retour.comprendLesCoord(xc, yc)) {
			boutonSelectionnerAutre = true;
		}
	} while (!boutonSelectionnerPerso && !boutonSelectionnerAutre);
	cleardevice();
}

void Affichage::dessinerDeuxEquipes(Equipes Joueur,Equipes IA) const
{
	dessinerEquipeJoueur(Joueur);
	dessinerEquipeIA(IA);
}

void Affichage::dessinerAttaque(Personnage * Attaquant, Personnage * Defenseur) {
	
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	int Tab[8] = { 365,30,835,30,835,800,365,800 };
	fillpoly(4, Tab);
	setcolor(RED);
	
	int i, j;
	if (!Attaquant->equipeAllier().ia()) {
		 i = Attaquant->indiceEquipe() + 1;
		 j = Defenseur->indiceEquipe() + 1;
		//animationCercle(390, -20 + 70 * i, 810, -20 + 70 * j);
		
	}
	else {
		 j = Attaquant->indiceEquipe() + 1;
		 i = Defenseur->indiceEquipe() + 1;
	//	animationCercle(810, -20 + 70 * j, 390, -20 + 70 * i);
	}
	line(370, -25 + 70 * i, 830, -25 + 70 * j);
	if (!Attaquant->equipeAllier().ia()) {
		
		line(810, -5 + 70 *j, 830, -25 + 70 * j);
		line(810, -45 + 70 * j, 830, -25 + 70 * j);
	}
	else {
		line(390, -5 + 70 * i, 370, -25 + 70 * i);
		line(390, -45 + 70 * i, 370, -25 + 70 * i);
		
	}
	delay(300);
}

Affichage::~Affichage()
{
}
