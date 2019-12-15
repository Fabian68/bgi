#pragma once
#include "graphics.h"
class Bouton
{
public:
	Bouton(int xDepart, int yDepart, std::string texte, int couleurRectangle = BLACK, int couleurBordure = RED, int couleurTexte = RED);
	void afficher()const;
	bool comprendLesCoord(int x, int y)const;
private:
	int _x1, _x2, _y1,_y2, _couleurRectangle, _couleurTexte, _couleurBordure;
	std::string _texte;
};

