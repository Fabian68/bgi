#include "Zones.h"
#include "Lapin.h"
#include "Sanglier.h"
#include <iostream>
#include "Cerf.h"
#include "Zombie.h"
#include "SqueletteArcher.h"
#include "Creeper.h"
#include "Ghast.h"
#include "WitherSquelette.h"
#include "Wither.h"
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
	case 16:
		E.ajouterPerso(new Sanglier(60, "Sanglier"));
		E.ajouterPerso(new Cerf(62, "Cerf"));
		E.ajouterPerso(new Cerf(61, "Cerf"));
		E.ajouterPerso(new Lapin(68, "Lapin"));
		break;
	case 17:
		E.ajouterPerso(new Sanglier(65, "Sanglier"));
		E.ajouterPerso(new Sanglier(68, "Sanglier"));
		E.ajouterPerso(new Cerf(67, "Cerf"));
		E.ajouterPerso(new Lapin(69, "Lapin"));
		break;
	case 18:
		E.ajouterPerso(new Sanglier(80, "Sanglier"));
		E.ajouterPerso(new Sanglier(74, "Sanglier"));
		E.ajouterPerso(new Cerf(78, "Cerf"));
		E.ajouterPerso(new Sanglier(76, "Sanglier"));
		break;
	case 19:
		E.ajouterPerso(new Sanglier(86, "Sanglier"));
		E.ajouterPerso(new Lapin(89, "Lapin"));
		E.ajouterPerso(new Cerf(84, "Cerf"));
		E.ajouterPerso(new Sanglier(87, "Sanglier"));
		break;
	case 20:
		E.ajouterPerso(new Lapin(90, "Lapinou",2,9,5));
		E.ajouterPerso(new Lapin(95, "Lapin",0,2,1));
		E.ajouterPerso(new Cerf(99, "Cerf",0,3,2));
		E.ajouterPerso(new Sanglier(92, "Sanglier",0,5,2));
		break;
	case 21:
		E.ajouterPerso(new Zombie(100, "Zombie"));
		E.ajouterPerso(new Zombie(100, "Zombie"));
		E.ajouterPerso(new Zombie(100, "Zombie"));
		break;
	case 22:
		E.ajouterPerso(new Zombie(100, "Zombie"));
		E.ajouterPerso(new Zombie(102, "Zombie"));
		E.ajouterPerso(new Zombie(105, "Zombie"));
		E.ajouterPerso(new Zombie(102, "Zombie"));
		break;
	case 23:
		E.ajouterPerso(new Zombie(115, "Zombie"));
		E.ajouterPerso(new SqueletteArcher(105, "Squelette archer"));
		E.ajouterPerso(new SqueletteArcher(110, "Squelette archer"));
		break;
	case 24:
		E.ajouterPerso(new Zombie(125, "Zombie"));
		E.ajouterPerso(new SqueletteArcher(130, "Squelette archer"));
		E.ajouterPerso(new SqueletteArcher(120, "Squelette archer"));
		E.ajouterPerso(new SqueletteArcher(130, "Squelette archer"));
		break;
	case 25:
		E.ajouterPerso(new Zombie(140, "Zombie"));
		E.ajouterPerso(new SqueletteArcher(145, "Squelette archer"));
		E.ajouterPerso(new SqueletteArcher(125, "Squelette archer"));
		E.ajouterPerso(new Zombie(135, "Zombie",0,1,3));
		break;
	case 26:
		E.ajouterPerso(new Zombie(150, "Zombie"));
		E.ajouterPerso(new SqueletteArcher(145, "Squelette archer"));
		E.ajouterPerso(new Creeper(150, "Cripeur"));
		E.ajouterPerso(new Zombie(145, "Squelette archer", 0, 1, 3));
		break;
	case 27:
		E.ajouterPerso(new Zombie(160, "Zombie"));
		E.ajouterPerso(new SqueletteArcher(155, "Squelette archer"));
		E.ajouterPerso(new Creeper(155, "Creeper"));
		E.ajouterPerso(new Creeper(160, "Creeper"));
		break;
	case 28:
		E.ajouterPerso(new Zombie(180, "Zombie"));
		E.ajouterPerso(new Creeper(175, "Creeper"));
		E.ajouterPerso(new Creeper(165, "Creeper"));
		E.ajouterPerso(new Creeper(170, "Creeper"));
		break;
	case 29:
		E.ajouterPerso(new Zombie(190, "Zombie"));
		E.ajouterPerso(new Creeper(180, "Creeper"));
		E.ajouterPerso(new Lapin(199, "Lapin",0,1,5));
		E.ajouterPerso(new Creeper(175, "Creeper"));
		break;
	case 30:
		E.ajouterPerso(new Zombie(200, "Zombie Cochon",0,1,3));
		E.ajouterPerso(new Creeper(199, "Creeper",1));
		E.ajouterPerso(new Ghast(200, "Ghast"));
		E.ajouterPerso(new WitherSquelette(200, "Wither Squelette"));
		break;
	case 31:
		E.ajouterPerso(new Zombie(210, "Zombie Cochon", 0, 1, 3));
		E.ajouterPerso(new Ghast(215, "Ghast"));
		E.ajouterPerso(new Ghast(210, "Ghast"));
		E.ajouterPerso(new WitherSquelette(220, "Wither Squelette"));
		break;
	case 32:
		E.ajouterPerso(new Zombie(220, "Zombie Cochon", 0, 1, 3));
		E.ajouterPerso(new WitherSquelette(225, "Wither Squelette"));
		E.ajouterPerso(new WitherSquelette(230, "Wither Squelette"));
		E.ajouterPerso(new WitherSquelette(222, "Wither Squelette"));
		break;
	case 33:
		E.ajouterPerso(new Wither(230, "Wither lvl 1"));
		E.ajouterPerso(new WitherSquelette(235, "Wither Squelette"));
		E.ajouterPerso(new WitherSquelette(230, "Wither Squelette"));
		E.ajouterPerso(new WitherSquelette(225, "Wither Squelette"));
		break;
	case 34:
		E.ajouterPerso(new WitherSquelette(240, "Wither Squelette GOD ",1));
		E.ajouterPerso(new WitherSquelette(245, "Wither Squelette"));
		E.ajouterPerso(new Wither(250, "Super WITHER",1));
		E.ajouterPerso(new WitherSquelette(245, "Wither Squelette"));
		E.ajouterPerso(new WitherSquelette(240, "Wither Squelette"));
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
	if (_niveauMax >= 35) {
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
