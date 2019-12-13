#pragma once
#include <fstream>
#include <vector>
class Orbes
{
public:
	Orbes();
	void sauvegarder();
	void buffOrbes(int indiceJoueur, int& attaqueLvlBonus, int& vieLvLBonus, int& vitesseLvlBonus)const;

private:
	std::vector<std::vector<int>> _orbesLVL;
	std::vector<std::vector<int>> _choixOrbes;
};

