#pragma once
#include "Personnage.h"


class Lapin :
	public Personnage
{
public:
	Lapin(int LVL,int difficulte=0);
private:
	virtual void attaqueEnnemis()override;
};


