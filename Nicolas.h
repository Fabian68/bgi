#pragma once
#include "Personnage.h"


class Nicolas :
	public Personnage
{
public:
	Nicolas();
private:
	virtual void attaqueEnnemis()override;
};


