#pragma once
#include "Personnage.h"


class Fabian :
	public Personnage
{
public:
	Fabian(Experiences E,Orbes O,Animaux A);
private:
	virtual void attaqueEnnemis()override;
};

