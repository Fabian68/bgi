#pragma once
#include "Personnage.h"
class Brute :
	public Personnage
{
public:
	Brute(int LVL, std::string nom, int difficulte = 0, int animal = 3, int rareteAnimal = 4);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
	bool enrager;
};

