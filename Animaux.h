#pragma once
#include <fstream>
#include "Equipes.h"
class Animaux
{
public:
	Animaux();
	void sauvegarder();
private:
	std::vector<std::vector<int >> _animauxPosseder;
	std::vector<int> _animauxUtiliser;
};

