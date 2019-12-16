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
	is >> _niveauMax;
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
		E.ajouterPerso(new Lapin(1,"Lapin nain"));
		break;
	case 2:
		E.ajouterPerso(new Lapin(2, "Lapin nain"));
		E.ajouterPerso(new Lapin(1, "Lapin nain"));
		break;
	case 3:
		E.ajouterPerso(new Lapin(2, "Lapin nain"));
		E.ajouterPerso(new Lapin(3, "Petit lapin"));
		E.ajouterPerso(new Lapin(1,"Lapin nain"));
		break;
	case 4:
		E.ajouterPerso(new Lapin(2, "Lapin nain"));
		E.ajouterPerso(new Lapin(4, "Petit lapin"));
		E.ajouterPerso(new Lapin(2, "Lapin nain"));
		break;
	case 5:
		E.ajouterPerso(new Lapin(3, "Petit lapin"));
		E.ajouterPerso(new Lapin(5, "Jojo le lapin",1,0,5));
		E.ajouterPerso(new Lapin(3, "Petit lapin"));
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

int Zones::niveauActuel() const
{
	return _niveauActuel;
}

int Zones::niveauMax() const
{
	return _niveauMax;
}

int Zones::nbPersoJouable() const
{
	int nb = 1;
	if (_niveauMax >= 3) {
		nb++;
	}
	if (_niveauMax >= 6) {
		nb++;
	}
	if (_niveauMax >= 16) {
		nb++;
	}
	return nb;
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
