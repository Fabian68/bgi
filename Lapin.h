#pragma once
#include "Personnage.h"


class Lapin :
	public Personnage
{
public:
	Lapin(Equipes A,int LVL);
private:
	virtual void attaqueEnnemis()override;
};


