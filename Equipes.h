#pragma once
#include <vector>


class Personnage;
class Equipes
{
public:
	Equipes();
	Equipes(bool equipeIA);
	int taille()const;
	Personnage* operator[](int i)const;
	Personnage* perso(int i);
	Personnage* plusProcheVivant();
	Personnage* plusLoinVivant();
	Personnage* plusFaible();
	Personnage* aleatoireEnVie();
	void attaqueZone(int Degats,Personnage*Attaquant);
	void soignerZone(int soins, Personnage* Soigneur);
	int xpDonner()const;
	~Equipes();
	void ajouterPerso(Personnage* P);
	void setAllierEtEnnemis(Equipes E);
	bool estEnVie() const;
	bool ia() const;
private:
	std::vector<Personnage*> _equipe;
	bool _equipeIA;
};

