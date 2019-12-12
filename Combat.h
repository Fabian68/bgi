#pragma once
#include "Equipes.h"
#include "Affichage.h"
class Combat
{
public:
	Combat(Equipes & Joueur,Equipes & Ia);
	~Combat();

private:
	Equipes _joueur;
	Equipes _ia;
	std::vector<Personnage> _quiJoue;
};

