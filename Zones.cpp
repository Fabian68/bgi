#include "Zones.h"
#include "Lapin.h"
#include "Sanglier.h"
#include <iostream>
#include "Cerf.h"
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
		E.ajouterPerso(new Lapin(1, "Lapin nain"));
		break;
	case 2:
		E.ajouterPerso(new Lapin(2, "Lapin nain"));
		E.ajouterPerso(new Lapin(1, "Lapin nain"));
		break;
	case 3:
		E.ajouterPerso(new Lapin(2, "Lapin nain"));
		E.ajouterPerso(new Lapin(3, "Petit lapin"));
		E.ajouterPerso(new Lapin(1, "Lapin nain"));
		break;
	case 4:
		E.ajouterPerso(new Lapin(2, "Lapin nain"));
		E.ajouterPerso(new Lapin(4, "Petit lapin"));
		E.ajouterPerso(new Lapin(2, "Lapin nain"));
		break;
	case 5:
		E.ajouterPerso(new Lapin(3, "Petit lapin"));
		E.ajouterPerso(new Lapin(5, "Jojo le lapin", 1, 0, 5));
		E.ajouterPerso(new Lapin(3, "Petit lapin"));
		break;
	case 6:
		E.ajouterPerso(new Sanglier(8, "Petit sanglier"));
		E.ajouterPerso(new Lapin(4, "Lapin"));
		E.ajouterPerso(new Lapin(4, "Lapin"));
		break;
	case 7:
		E.ajouterPerso(new Sanglier(10, "Petit sanglier"));
		E.ajouterPerso(new Lapin(6, "Lapin"));
		E.ajouterPerso(new Sanglier(8, "Petit sanglier"));
		break;
	case 8:
		E.ajouterPerso(new Sanglier(12, "Petit sanglier"));
		E.ajouterPerso(new Sanglier(10, "Petit sanglier"));
		E.ajouterPerso(new Sanglier(10, "Petit sanglier"));
		break;
	case 9:
		E.ajouterPerso(new Sanglier(12, "Petit sanglier"));
		E.ajouterPerso(new Sanglier(15, "Petit sanglier"));
		E.ajouterPerso(new Sanglier(12, "Petit sanglier"));
		break;
	case 10:
		E.ajouterPerso(new Sanglier(18, "SANGLINOLANT", 1, 9, 1));
		E.ajouterPerso(new Sanglier(15, "Petit sanglier"));
		E.ajouterPerso(new Sanglier(12, "Petit sanglier"));
		E.ajouterPerso(new Sanglier(17, "SANGLOT", 1, 9, 1));
		break;
	case 11:
		E.ajouterPerso(new Sanglier(20, "Sanglier"));
		E.ajouterPerso(new Lapin(22, "Lapin"));
		E.ajouterPerso(new Cerf(20, "Cerf a rien"));
		E.ajouterPerso(new Lapin(25, "Teddy"));
		break;
	case 12:
		E.ajouterPerso(new Sanglier(25, "Sanglier"));
		E.ajouterPerso(new Lapin(24, "Lapinot"));
		E.ajouterPerso(new Cerf(27, "Cerf volant"));
		E.ajouterPerso(new Cerf(28, "Cerfsceau"));
		break;
	case 13:
		E.ajouterPerso(new Sanglier(32, "Sanglier"));
		E.ajouterPerso(new Cerf(29, "Cerftrude"));
		E.ajouterPerso(new Cerf(30, "Cerftoi"));
		E.ajouterPerso(new Cerf(35, "Dans sa maison un grand cerf"));
		break;
	case 14:
		E.ajouterPerso(new Sanglier(35, "Sanglier"));
		E.ajouterPerso(new Cerf(32, "Cerftrude"));
		E.ajouterPerso(new Cerf(32, "Cerftoi"));
		E.ajouterPerso(new Cerf(37, "Dans sa maison un grand cerf"));
		break;
	case 15:
		E.ajouterPerso(new Cerf(55, "Cerf d'acier",2,8,2));
		E.ajouterPerso(new Cerf(52, "CerfLaPince",1,3,3));
		E.ajouterPerso(new Cerf(50, "Cerf gilet jaune",1,3,2));
		E.ajouterPerso(new Cerf(40, "Cerf"));
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
