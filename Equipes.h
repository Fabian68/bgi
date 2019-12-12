#pragma once
#include <vector>


class Personnage;
class Equipes
{
public:
	Equipes();
	Equipes(bool equipeIA);
	int taille()const;
	Personnage* operator[](int i)const;
	Personnage* perso(int i);
	Personnage* plusProcheVivant();
	Personnage* plusLoinVivant();
	Personnage* plusFaible();
	Personnage* aleatoireEnVie();
	~Equipes();
	void ajouterPerso(Personnage* P);
	bool estEnVie() const;
	bool ia() const;
private:
	std::vector<Personnage*> _equipe;
	bool _equipeIA;
};

