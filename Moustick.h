#pragma once
#include "Personnage.h"
class Moustick :
	public Personnage
{
public:
	Moustick(Experiences E, Orbes O, Animaux A);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

