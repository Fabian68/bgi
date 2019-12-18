#pragma once
#include "Personnage.h"
class Fiona :
	public Personnage
{
public:
	Fiona(Experiences E, Orbes O, Animaux A);
private:
	int _nbAnimaux;
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

