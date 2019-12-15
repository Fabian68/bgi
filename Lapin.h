#pragma once
#include "Personnage.h"


class Lapin :
	public Personnage
{
public:
	Lapin(int LVL,int difficulte=0,int animal=-1,int rareteAnimal=0);
private:
	virtual void attaqueEnnemis()override;
};


