#pragma once
#include "Personnage.h"


class Fabian :
	public Personnage
{
public:
	Fabian();
private:
	virtual void attaqueEnnemis()override;
};

