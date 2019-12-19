#pragma once
#include "Personnage.h"
class Creeper :
	public Personnage
{
public:
	Creeper(int LVL, std::string nom, int difficulte = 0, int animal = 4, int rareteAnimal = 3);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

