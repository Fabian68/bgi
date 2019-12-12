#include "Affichage.h"
#include "Equipes.h"
#include "Personnage.h"


Affichage::Affichage()
{
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
	std::string str = P->nom();
	char* perso = const_cast<char*>(str.c_str());

	int y = -50 + 70 * indice;
	rectangle(x, y, x + 300, y + 65);
	outtextxy(x + 2, y + 5, perso);
	int pourcentageVie = P->pourcentageVie();
	setfillstyle(1, GREEN);
	int Tab[8] = { x + 2,y + 25,x + 2 + pourcentageVie*2,y + 25,x + 2 + pourcentageVie * 2,y + 40,x + 2,y + 40 };
	fillpoly(4, Tab);

	setfillstyle(1, BLACK);
	int Tab3[8] = { x + 2 + pourcentageVie * 2,y + 25,x + 202,y + 25,x + 202,y + 40,x + 2 + pourcentageVie * 2,y + 40 };
	fillpoly(4, Tab3);

	setfillstyle(1, MAGENTA);
	int Tab2[8] = { x + 2,y + 45,x + 202,y + 45,x + 202,y + 60,x + 2,y + 60 };
	fillpoly(4, Tab2);
}

void Affichage::dessinerDegats(Personnage* P, int degats) const {
	int x;
	if (P->equipeAllier().ia()) {
		x = 1200 - 150;
		
	}
	else {
		x = 270;
	}
	int y = -50 + 100 * (P->indiceEquipe()+1);setcolor(BLACK);
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
	int y = -50 + 100 * (P->indiceEquipe() + 1);
	setcolor(GREEN);
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
	outtextxy(500,15, txt);	
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
	}
	else {
		 j = Attaquant->indiceEquipe() + 1;
		 i = Defenseur->indiceEquipe() + 1;
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
	delay(250);
}

Affichage::~Affichage()
{
}
