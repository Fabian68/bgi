#pragma once
#include "Personnage.h"
class Amine :
	public Personnage
{
public:
	Amine(Experiences E, Orbes O, Animaux A);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

