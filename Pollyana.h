#pragma once
#include "Personnage.h"
class Pollyana :
	public Personnage
{
public:
	Pollyana(Experiences E, Orbes O, Animaux A, Objets Obj);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
	bool ombre = false;
};

