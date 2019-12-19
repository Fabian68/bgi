#pragma once
#include "Personnage.h"
class SqueletteArcher :
	public Personnage
{
public:
	SqueletteArcher(int LVL, std::string nom, int difficulte = 0, int animal = 5, int rareteAnimal = 2, int id = -1);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

