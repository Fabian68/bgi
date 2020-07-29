#pragma once
#include "Objet.h"
#include <vector>
#include <utility>


class Objets
{
public:
	Objets();

	void objetsDuPersonnage(int numero, Objet& obj1, Objet& obj2)const;
	void sauvegarderObjetsEquiper();
	void equiperObjetDuPersonnage(int numero, Objet obj, bool premier);
	std::vector<Objet> objetsDuNiveau(int numero);
	bool estDebloquer(Objet& obj) const;
	int nombreObjets() const;
	Objet objetNumero(int numero);
	void deblocageObjet( int indiceObjet);
	void sauvegarderObjetsDebloquer();
private:
	std::vector<std::vector<Objet>> _tableLoot;

	std::vector<int> _objetsDebloquer;

	std::vector<Objet> _listeObjets;

	std::vector<std::pair<int, int>> _listeObjetEquiper;
};

