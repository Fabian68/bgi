#include "Affichage.h"
#include "Equipes.h"
#include "Personnage.h"


Affichage::Affichage()
{
}
void afficherTexte(int x, int y, std::string texte) {
	char *perso = const_cast<char*>(texte.c_str());
	outtextxy(x, y, perso);
}
void Affichage::afficherJoueurs(Equipes E)const {
	int x = 50;
	int y = 20;
	std::string str;
	setbkcolor(BLACK);
	setcolor(WHITE);

	for (int i = 0; i < E.taille(); i++,y+=250) {
		
		str = "Pseudo : "+E[i]->nom();
		afficherTexte(x, y, str);
	
		str = "Niveau : " +std::to_string(E[i]->niveau());
		afficherTexte(x, y+20, str);

		str = "Force : "  +std::to_string(E[i]->force());
		afficherTexte(x, y+40, str);

		str = "Vie : "  +std::to_string(E[i]->vieMax());
		afficherTexte(x, y+60, str);

		str = "Vitesse : "  +std::to_string(E[i]->vitesse());
		afficherTexte(x, y+80, str);

		str = "Chance de double attaque : "  +std::to_string(E[i]->chanceDoubleAttaque());
		afficherTexte(x, y+100, str);

		str = "Chance de coup habile : "  +std::to_string(E[i]->chanceHabileter());
		afficherTexte(x, y+120, str);

		str = "Chance de deviation : "  +std::to_string(E[i]->pourcentageDeviation());
		afficherTexte(x, y+140, str);

		str = "Pourcentage de reduction de degats : "  +std::to_string(E[i]->pourcentageReduction());
		afficherTexte(x, y+160, str);

		str = "Chance de ricochet : " + std::to_string(E[i]->pourcentageRicochet());
		afficherTexte(x, y+180, str);

		str = "Chance esquive : " + std::to_string(E[i]->pourcentageEsquive());
		afficherTexte(x, y+200, str);

		str = "Chance de blocage : " + std::to_string(E[i]->pourcentageBlocage());
		afficherTexte(x, y+220, str);
	}
	getch();
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
