#pragma once
#include "Personnage.h"


class Fabian :
	public Personnage
{
public:
	Fabian(Equipes A);
private:
	virtual void attaqueEnnemis()override;
};

