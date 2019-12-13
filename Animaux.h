#pragma once
#include <fstream>
#include "Equipes.h"
class Animaux
{
public:
	Animaux();
	void animalDuPersonnage(int indicePersonnage, int& indiceAnimal, int& rareteAnimal)const;
	void sauvegarder();
private:
	std::vector<std::vector<int >> _animauxPosseder;
	std::vector<int> _animauxUtiliser;
};

