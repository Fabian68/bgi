#pragma once
#include "Personnage.h"
class Salim :
	public Personnage
{
public:
	Salim(Experiences E, Orbes O, Animaux A);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
	bool estTransformer;
	bool superTransformation;
};

