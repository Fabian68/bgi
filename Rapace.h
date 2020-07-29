#pragma once
#include "Personnage.h"
class Rapace :
	public Personnage
{
public:
	Rapace(int LVL, std::string nom, int difficulte = 0, int animal = 1, int rareteAnimal = 4);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

