#pragma once
#include "Personnage.h"
class Wither :
	public Personnage
{
public:
	Wither(int LVL, std::string nom, int difficulte = 0, int animal = 6, int rareteAnimal = 5, int id = -1);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

