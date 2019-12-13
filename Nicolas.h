#pragma once
#include "Personnage.h"


class Nicolas :
	public Personnage
{
public:
	Nicolas(Experiences E);
private:
	virtual void attaqueEnnemis()override;
};


