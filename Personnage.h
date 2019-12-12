#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#endif // !PERSONNAGE_H

#include <iostream>

class Personnage
{
public:
	Personnage();
	Personnage(int id, int LVL, std::string nom, int vieLVL, int attaqueLVL, int vitesseLVL, int chanceDoubleAttaque, int chanceHabilete, int pourcentageReduction, int pourcentageDeviation, int pourcentageBlocage, int pourcentageEsquive, int pourcentageRicochet,bool ia);
	virtual ~Personnage();
	int id() const;
	int mana()const;
	std::string nom()const;
	int vie()const;
	int vieMax()const;
	void reduireVie(int nb);
	int pourcentageVie()const;
	virtual void competence1();
	bool estEnVie() const;
	int force() const;
	int vitesse()const;
	bool ia() const;
	int soins(double RatioMin, double RatioMax) const;
	int degats(double RatioMin, double RatioMax) const;
	void soigner(int soins,Personnage & P);
	void AjouterVie(int montant);
	bool estAttaquable() const;
    void   Attaque(int Degat, Personnage & Defenseur) ;
	bool bloque() const;
	bool attaqueDouble() const;
	void ajouterMana(int n);
	int reductionDesDegats(int entier) const;
	bool devie() const;
	bool ricoche() const;
	void modifierIndiceEquipe(int i);
	int indiceEquipe() const;
private:
	int _id;
	int _niveau;
	int _vieMax;
	int _vie;
	int _vieParNiveau;
	int _force;
	int _forceParNiveau;
	int _vitesse;
	int _vitesseParNiveau;
	int _bouclier;
	int _mana;
	int _pourcentageCritique;
	int _degatCritique;
	int _chanceDoubleAttaque;
	int _chanceHabilete;
	int _nbFoisJouer;
	int _pourcentageDeviation;
	int _pourcentageReduction;
	int _pourcentageRicochet;
	int _pourcentageEsquive;
	int _pourcentageBlocage;
	bool _ia;
	int _indiceEquipe;


	std::string _nom;
};

