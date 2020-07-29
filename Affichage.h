#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#endif // !AFFICHAGE_H

#include "graphics.h"
#pragma once
class Personnage;
class Equipes;
class Zones;
class Animaux;
class Objets;

class Affichage
{
public:
	Affichage();

	void affichageTexte(int x, int y, std::string texte);
	
	void animationCercle(int xDepart, int yDepart, int xArriver, int yArriver)const;
	void afficherJoueurs(int indice, Equipes& Liste) const;
	void choixObjets(int page, Objets obj, bool premierObjet, int indicePersonnage, Equipes & Liste)const;
	void afficherAnimaux(Animaux A)const;
	void dessinerJoueur(int indice, bool equipeIA, Personnage* P)const;
	void dessinerDegats(Personnage* P,int degats) const;
	void dessinerSoins(Personnage* P, int soins) const;
	void dessinerBouclier(Personnage* P, int soins) const;
	void dessinerTexte(std::string texte)const;
	void dessinerEquipeJoueur(Equipes  J)const;
	void dessinerEquipeIA(Equipes I)const;
	void choixNiveau(Zones Z, Objets obj,int & niveau,int & repetition)const;
	void afficherObjetsDeblocableNiveau(Objets obj, int niveau)const;
	void menuModifierEquipe(Equipes& Gentil, Equipes choix,int max)const;
	void dessinerDeuxEquipes(Equipes J,Equipes E)const;
	void dessinerAttaque(Personnage * Attaquant, Personnage * Defenseur);
	~Affichage();
private:

};

