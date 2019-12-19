#pragma once
#include "Personnage.h"
class Zombie :
	public Personnage
{
public:
	Zombie(int LVL, std::string nom, int difficulte = 0, int animal = 1, int rareteAnimal = 2);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

