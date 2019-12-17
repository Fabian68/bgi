#pragma once
#include "Personnage.h"

class Sanglier :
	public Personnage
{
public:
	Sanglier(int LVL, std::string nom, int difficulte = 0, int animal = -1, int rareteAnimal = 0);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

