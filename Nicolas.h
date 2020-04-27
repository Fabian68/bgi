#pragma once
#include "Personnage.h"


class Nicolas :
	public Personnage
{
public:
	Nicolas(Experiences E,Orbes O,Animaux A, Objets Obj);
private:
	virtual void attaqueEnnemis()override;
	virtual void passif(int tour)override;
	virtual void passifDefensif()override;
};


