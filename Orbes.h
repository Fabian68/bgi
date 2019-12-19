#pragma once
#include <fstream>
#include <vector>
class Orbes
{
public:
	Orbes();
	void sauvegarder();
	void buffOrbes(int indiceJoueur, int& attaqueLvlBonus, int& vieLvLBonus, int& vitesseLvlBonus)const;
	bool orbeDebloquer(int indiceJoueur, int rareter)const;
	void deblocageOrbe(int indiceJoueur, int rareter, std::string perso);
    int choixOrbe(int indicePerso,int rareter)const;
	void setChoixOrbe(int indicePerso,int rareter, int choix);
private:
	std::vector<std::vector<int>> _orbesLVL;
	std::vector<std::vector<int>> _choixOrbes;
};

