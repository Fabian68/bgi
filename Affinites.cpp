#include "Affinites.h"
#include <iostream>
#include "Personnage.h"
Affinites::Affinites()
{
	
	double tab[25][25] = { {0.0,0.8,0.5,0.1,-0.3,0.3,0.1,0.2,0.0,0.1,-0.5,0.6,0.4,-0.2,0.0,0.5},
		{0.8,0.0,0.5,-0.2,-0.5,-0.2,-0.1,0.7,0.8,0.5,-0.2,0.7,0.7,0.4,1.0,-0.2},
		{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0},
		{0.1,-0.5,-0.5,0.0,0.5,0.0,1.0,-1.0,-0.5,0.1,-0.2,-0.5,-0.5,-0.3,0.0,-0.5},
		{-0.5,-0.5,-0.5,0.5,0.0,0.0,0.2,-1.0,-0.5,-0.3,-0.1,-0.5,-0.5,-0.1,0.0,-0.5},
		{0.3,0.2,0.1,0.0,0.0,0.0,0.1,0.1,0.1,0.0,-0.25,0.5,0.1,-0.5,0.0,0.2},
		{0.3,0.1,0.4,1.0,0.3,0.0,0.0,-1.0,0.2,0.1,-0.1,1.0,0.1,-0.5,-0.5,-1.0},
		{1.0,1.0,0.5,0.0,0.0,0.0,-0.5,0.0,1.0,0.2,0.1,0.6,0.6,0.0,0.0,0.2},
		{0.6,0.7,0.5,0.0,-0.3,0.1,0.2,0.3,0.0,0.5,0.1,0.6,0.6,0.0,0.0,0.2},
		{1.0,1.0,-0.1,1.0,-0.2,-0.5,1.0,0.0,-0.2,0.0,0.5,0.3,0.0,-0.5,0.0,0.0},
		{0.1,0.0,0.0,-0.2,-0.3,0.0,0.0,-0.5,0.0,-0.5,0.0,0.0,0.0,-0.8,0.0,0.0},
		{1.0,0.8,0.7,0.3,0.2,0.5,0.6,0.0,0.2,0.4,0.4,0.0,0.8,0.0,0.4,0.4},
		{0.4,0.5,0.2,0.0,0.0,0.0,0.0,0.0,0.5,0.4,0.0,0.7,0.0,0.1,0.2,0.0},
		{0.7,1.0,0.1,0.7,0.75,0.9,0.75,1.0,0.9,0.0,0.75,0.7,0.7,0.0,0.0,0.7},
		{0.3,1.0,-0.2,-0.8,-0.5,-0.8,-0.6,0.6,0.4,0.6,-0.5,0.2,0.2,-0.5,0.0,-0.5},
		{0.8,-0.2,0.1,-0.1,-0.5,0.0,-0.5,-0.5,0.1,0.6,-0.2,0.5,0.0,-0.6,-0.3,0.0} };
	
	_affinites.resize(25);
	for (int i = 0;i < 25;i++) {
		_affinites[i].resize(25);
	}
	for (int i = 0;i < 25;i++) {
		for (int j = 0;j < 25;j++) {
			_affinites[i][j] = tab[i][j];
		}
	}
	std::cout << _affinites[0][1]<< " blelel";
}

double Affinites::affinite(int perso, int avecperso) const
{
	return _affinites[perso][avecperso];
}

std::vector<double> Affinites::listeAffinites(const Equipes& E) const
{
	
	std::vector<double> liste(E.taille(), 0.0);
	for (int i = 0;i < E.taille();i++) {
		for (int j = 0;j < E.taille();j++) {
			liste[i] += _affinites[E[i]->id()][E[j]->id()];
		}
	}
	for (int j = 0;j < E.taille();j++) {
		liste[j] /=(E.taille()-1.0);
	}
	return liste;
}