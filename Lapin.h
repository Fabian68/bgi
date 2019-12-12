#pragma once
#include "Personnage.h"


class Lapin :
	public Personnage
{
public:
	Lapin(int LVL);
private:
	virtual void attaqueEnnemis()override;
};


