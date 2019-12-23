#pragma once
#include "Personnage.h"
class Isidore :
	public Personnage
{
public:
	Isidore(Experiences E, Orbes O, Animaux A);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

