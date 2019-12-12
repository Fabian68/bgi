#pragma once
#include "Personnage.h"


class Nicolas :
	public Personnage
{
public:
	Nicolas(Equipes A);
private:
	virtual void attaqueEnnemis()override;
};


