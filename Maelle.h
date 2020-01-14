#pragma once
#include "Personnage.h"
class Maelle :
	public Personnage
{
public:
	Maelle(Experiences E, Orbes O, Animaux A);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
	bool estTransformer;
};

