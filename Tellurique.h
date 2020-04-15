#pragma once
#include "Personnage.h"
class Tellurique :
	public Personnage
{
public:
	Tellurique(int LVL, std::string nom, int difficulte = 0, int animal = 3, int rareteAnimal = 5, int id = -1);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
	bool premiereFoisToucher;
};

