#pragma once
#include <fstream>
#include "Equipes.h"

class Zones
{
public:
	Zones();
	void ecrireZone();
	void equipeEnZone(int i,Equipes & E);
	void choixNiveau(int i);
	void niveauBattu();
	void zoneBattue();
private:
	int _niveauActuel;
	int _niveauMax;
};

