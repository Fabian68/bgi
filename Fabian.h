#pragma once
#include "Personnage.h"


class Fabian :
	public Personnage
{
public:
	Fabian(Experiences E,Orbes O,Animaux A,Objets Obj);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};

