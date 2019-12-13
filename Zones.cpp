#include "Zones.h"
#include "Lapin.h"
#include <iostream>
Zones::Zones()
{
	FILE* file = fopen("Zones.txt", "r");
	if (file == NULL) {
		std::ofstream os("Zones.txt");
		os << 1 << std::endl;
		os.close();
	}
	std::ifstream is("Zones.txt");
	int i = 0;	
	is >> _niveauMax;
	_niveauActuel = _niveauMax;
	i++;
	is.close();
}

void Zones::ecrireZone()
{
	std::ofstream os("Zones.txt");
	os << _niveauMax << std::endl;
	os.close();
}

void Zones::equipeEnZone(int i,Equipes & E)
{
	switch (i)
	{
	case 1:
		E.ajouterPerso(new Lapin(1));
	
		break;
	case 2:
		E.ajouterPerso(new Lapin(2));
		E.ajouterPerso(new Lapin(1));
		break;
	case 3:
		E.ajouterPerso(new Lapin(2));
		E.ajouterPerso(new Lapin(3));
		E.ajouterPerso(new Lapin(1));
		break;
	}
}

void Zones::choixNiveau(int i)
{
	if (i > _niveauMax) {
		_niveauActuel = _niveauMax;
	}
	else {
		_niveauActuel = i;
	}
}

void Zones::niveauBattu()
{
	if (_niveauActuel == _niveauMax) {
		_niveauMax++;
		ecrireZone();
	}
}

void Zones::zoneBattue()
{
}
