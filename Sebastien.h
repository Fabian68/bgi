#pragma once
#include "Personnage.h"
class Sebastien :
	public Personnage
{
public:
	Sebastien(Experiences E, Orbes O, Animaux A);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
	int pause;
};

