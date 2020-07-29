#pragma once
#include <vector>
#include "Equipes.h"
class Affinites
{
public:
	Affinites();
	double affinite(int perso, int avecperso)const;

	std::vector<double> listeAffinites(const Equipes& E)const;
private:
	std::vector<std::vector<double>> _affinites;
};

