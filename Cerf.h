#pragma once
#include "Personnage.h"
class Cerf :
	public Personnage
{
public:
	Cerf(int LVL, std::string nom, int difficulte = 0, int animal = 3, int rareteAnimal = 1);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

