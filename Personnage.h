#pragma once

#include <string>
#include "Equipes.h"
#include "Experiences.h"
#include "Orbes.h"
#include "Animaux.h"
#include "Statistiques.h"
class Personnage
{
public:
	Personnage(int id, Experiences E,Orbes O,Animaux A, std::string nom, int vieLVL, int attaqueLVL, int vitesseLVL, int chanceDoubleAttaque, int chanceHabilete, int pourcentageReduction, int pourcentageDeviation, int pourcentageBlocage, int pourcentageEsquive, int pourcentageRicochet);
	Personnage(int LVL, std::string nom, int vieLVL, int attaqueLVL, int vitesseLVL, int chanceDoubleAttaque, int chanceHabilete, int pourcentageReduction, int pourcentageDeviation, int pourcentageBlocage, int pourcentageEsquive, int pourcentageRicochet,int indiceAnimal,int rareteAnimal);
	virtual ~Personnage();
	int id() const;
	int mana()const;
	std::string nom()const;
	int vie()const;
	int vieMax()const;
	void ajouterVieMax(int montant);
	void reduireVieMax(int montant);
	void reduireVie(int nb);
	int reduireBouclier(int nb);
	int pourcentageVie()const;
	int pourcentageBouclier() const;
	virtual void attaqueEnnemis()=0;
	virtual void passif(int tour) = 0 ;
	virtual void passifDefensif() = 0;
	bool estEnVie() const;
	int force() const;
	int vitesse()const;
	int niveau() const;
	void ajouterForce(int montant);
	void ajouterVitesse(int montant);
	void ajouterVie(int montant);
	int xpDonner()const;
	int soins(double RatioMin, double RatioMax) const;
	Statistiques& stats();
	int degats(double RatioMin, double RatioMax) const;
	void soigner(int soins,Personnage * P);
	void AjouterVie(int montant);
	void bouclier(int soins, Personnage* P);
	void AjouterBouclier(int montant);
	void ajouterBouclier(int montant);
	int bouclierMax()const;
	bool estAttaquable() const;
	void setEnnemis(Equipes & E);
	void setAllier(Equipes & A);
	Equipes& equipeAllier();
	Equipes& equipeEnnemi();
	bool habile() const;
	void traitementAnimaux();
    void   Attaque(int Degat, Personnage * Defenseur) ;
	void AttaqueBrut(int Degat, Personnage* Defenseur);
	int degatsCritiques() const;
	void setReduction(int montant);
	void ajouterChanceDoubleAttaque(int montant);
	void ajouterChanceHabileter(int montant);
	void ajouterReduction(int montant);
	int bouclier() const;
	bool bloque() const;
	bool attaqueDouble() const;
	void ajouterMana(int n);
	int reductionDesDegats(int entier) const;
	bool devie() const;
	bool ricoche() const;
	void modifierIndiceEquipe(int i);
	int choixAttaque();
	int indiceEquipe() const;
	int chanceDoubleAttaque()const;
	int chanceHabileter()const;
	int pourcentageDeviation()const;
	int pourcentageReduction()const;
	int pourcentageRicochet()const;
	int pourcentageEsquive()const;
	int pourcentageBlocage()const;
	void setId(int val);
	void setAnimal(Animal A);
	Animal animal()const;
	int rareterAnimal()const;
	void ajouterCoupCritique(int pourcentage);
	void ajouterDegatsCritique(int pourcentage);
	void setNom(std::string nom);
private:
	int _id;
	int _niveau;
	int _vieMax;
	int _vie;
	int _force;
	int _vitesse;
	int _bouclier;
	int _mana;
	int _pourcentageCritique;
	int _degatCritique;
	int _chanceDoubleAttaque;
	int _chanceHabilete;
	int _pourcentageDeviation;
	int _pourcentageReduction;
	int _pourcentageRicochet;
	int _pourcentageEsquive;
	int _pourcentageBlocage;
	int _indiceEquipe;
	Equipes _A;
	Equipes _E;
	int _indiceAnimal;
	int _rareteAnimal;
	Animal _animal;
	std::string _nom;
	Statistiques _S;
};

