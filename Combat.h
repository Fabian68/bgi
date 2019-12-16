#pragma once

#include "Zones.h"
#include <vector>
#include "Personnage.h"
class Combat
{
public:
	Combat(Equipes   & Joueur,Equipes  & Ia,Zones & Z,Animaux& A, Orbes& O);
	void tirageRecompenses(Zones Z, Animaux A, Orbes O);
	~Combat();

private:
	Equipes _joueur;
	Equipes _ia;
	std::vector<Personnage*> _quiJoue;
	int _tour;
};

