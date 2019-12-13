#pragma once
#include "Personnage.h"


class Fabian :
	public Personnage
{
public:
	Fabian(Experiences E);
private:
	virtual void attaqueEnnemis()override;
};

