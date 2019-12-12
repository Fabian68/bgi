#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#endif // !AFFICHAGE_H

#include "graphics.h"
#pragma once
class Personnage;
class Equipes;
class Affichage
{
public:
	Affichage();
	void dessinerJoueur(int indice, bool equipeIA, Personnage* P)const;
	void dessinerTexte(std::string texte)const;
	void dessinerEquipeJoueur(Equipes  J)const;
	void dessinerEquipeIA(Equipes I)const;
	void dessinerDeuxEquipes(Equipes J,Equipes E)const;
	void dessinerAttaque(Personnage * Attaquant, Personnage * Defenseur);
	~Affichage();
private:

};

