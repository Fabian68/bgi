#pragma once
#include "Personnage.h"
class Thomas :
	public Personnage
{
public:
	Thomas(Experiences E, Orbes O, Animaux A);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

