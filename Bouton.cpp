#include "Bouton.h"
#include <iostream>
Bouton::Bouton(int xDepart, int yDepart, std::string texte, int couleurRectangle, int couleurBordure, int couleurTexte) : _x1{xDepart}, _y1{yDepart},_couleurRectangle{couleurRectangle},_couleurBordure{couleurBordure},_couleurTexte{couleurTexte}, _texte{texte}
{
	_x2 = _x1+7 * texte.size()+20;
	_y2 = _y1 + 40;
}

void Bouton::afficher() const
{
	setcolor(_couleurBordure);
	setfillstyle(1, _couleurRectangle);
	int Tab[8] = {_x1,_y1,_x2,_y1,_x2,_y2,_x1,_y2};
	fillpoly(4, Tab);

	setcolor(_couleurTexte);
	std::cout << _texte;
	char* perso = const_cast<char*>(_texte.c_str());
	outtextxy(_x1+10, _y1+12, perso);

}

bool Bouton::comprendLesCoord(int x, int y) const
{
	return ((x>=_x1&&x<=_x2)&& (y >= _y1 && y <= _y2));
}
