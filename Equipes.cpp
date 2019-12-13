#include "Equipes.h"
#include "Personnage.h"
#include "Aleatoire.h"
#include <iostream>

Equipes::Equipes() : _equipe{}, _equipeIA(true)
{
}

Equipes::Equipes(bool equipeIA) : _equipeIA{equipeIA}
{
}

int Equipes::taille() const
{
	return _equipe.size();
}

Personnage*  Equipes::operator[](int i)const
{
	return _equipe[i];
}

Personnage*  Equipes::perso(int i)
{
	return _equipe[i];
}

Personnage* Equipes::plusProcheVivant() 
{
	int trouver = false;
	int i = 0;
	while (i < _equipe.size()&&i<11) {
		
		if (_equipe[i]->estEnVie()) {
			return _equipe[i];
		}
		i++;
	}
	
}

Personnage* Equipes::plusLoinVivant()
{
	int trouver = false;
	int i = _equipe.size()-1;
	while (i >-1) {
		//std::cout << "Plus loin" << std::endl;
		if (_equipe[i]->estEnVie()) {
			return _equipe[i];
		}
		i--;
	}
	
}

Personnage* Equipes::plusFaible()
{
	int vie = INT_MAX;
	int j = 0;
	for (int i = 0;i < _equipe.size();i++) {
		std::cout << "b";
		if (_equipe[i]->vie()>0) {
			std::cout << " plus faible" << std::endl;
			vie = _equipe[i]->vie();
			j = i;
		}
	}
	return _equipe[j];
}

Personnage* Equipes::aleatoireEnVie() {
	
	int i;
	do { 	
		i = Aleatoire(0, _equipe.size()).entier();
	} while (!_equipe[i]->estEnVie());
	return _equipe[i];
	
}


Equipes::~Equipes()
{
}

void Equipes::ajouterPerso(Personnage * P)
{
	P->modifierIndiceEquipe(_equipe.size());
	P->setAllier(*this);
	_equipe.push_back(P);
}

bool Equipes::estEnVie()const {
	int j = 0;
	for (int i = 0;i < _equipe.size();i++) {
		if (_equipe[i]->estEnVie()) {
			j++;
		}
	}
	std::cout << j << std::endl;
	return j > 0;
}

bool Equipes::ia()const {
	return _equipeIA;
}
/*
test envie equipe
*/
