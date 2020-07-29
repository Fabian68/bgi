#pragma once
#include "Personnage.h"
class Magicien :
	public Personnage
{
public:
	Magicien(int LVL, std::string nom, int difficulte = 0, int animal = 9, int rareteAnimal = 5);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
	int stade;
};

