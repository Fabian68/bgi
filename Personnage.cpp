#include "Personnage.h"
#include "Aleatoire.h"
#include "Affichage.h"
#include <iostream>





Personnage::Personnage(int LVL, std::string nom,int vieLVL,int forceLVL,int vitesseLVL,int chanceDoubleAttaque,int chanceHabilete,int pourcentageReduction,int pourcentageDeviation,int pourcentageBlocage,int pourcentageEsquive,int pourcentageRicochet) : 
	_vieMax{ vieLVL*LVL }, _vie{ vieLVL*LVL }, _nom{ nom },_id{-1},_niveau{LVL},_force{forceLVL*LVL},_vitesse{vitesseLVL*LVL},_chanceDoubleAttaque{chanceDoubleAttaque},
	_chanceHabilete{chanceHabilete},_pourcentageReduction{pourcentageReduction},_pourcentageDeviation{pourcentageDeviation},_pourcentageBlocage{pourcentageBlocage},_pourcentageEsquive{pourcentageEsquive},_pourcentageRicochet{pourcentageRicochet},
	_mana{0},_pourcentageCritique{10},_degatCritique{50},_nbFoisJouer{0},_bouclier{0}
{
}

Personnage::Personnage(int id,Experiences E,Orbes O,Animaux A, std::string nom, int vieLVL, int forceLVL, int vitesseLVL, int chanceDoubleAttaque, int chanceHabilete, int pourcentageReduction, int pourcentageDeviation, int pourcentageBlocage, int pourcentageEsquive, int pourcentageRicochet) :
	_nom{ nom }, _id{ id }, _chanceDoubleAttaque{ chanceDoubleAttaque },
	_chanceHabilete{ chanceHabilete }, _pourcentageReduction{ pourcentageReduction }, _pourcentageDeviation{ pourcentageDeviation }, _pourcentageBlocage{ pourcentageBlocage }, _pourcentageEsquive{ pourcentageEsquive }, _pourcentageRicochet{ pourcentageRicochet },
	_mana{ 0 }, _pourcentageCritique{ 10 }, _degatCritique{ 50 }, _nbFoisJouer{ 0 }, _bouclier{ 0 },_An{A}
{
	int bonusLVLattaque;
	int bonusLVLvie;
	int bonusLVLvitesse;
	O.buffOrbes(_id, bonusLVLattaque, bonusLVLvie, bonusLVLvitesse);
	_niveau = E.calculNiveau(id);
	_vie = (vieLVL+bonusLVLvie) * _niveau * 10;
	_vieMax = _vie;
	_force = (forceLVL+bonusLVLattaque) * _niveau;
	_vitesse = (vitesseLVL+bonusLVLvitesse) * _niveau;
}

Personnage::~Personnage()
{
}

int Personnage::id()const 
{
	return _id;
}
int Personnage::mana() const
{
	return _mana;
}
std::string Personnage::nom()const
{
	return _nom;
}

int Personnage::vie() const
{
	return _vie;
}

int Personnage::vieMax() const
{
	return _vieMax;
}

void Personnage::reduireVie(int nb)
{
	_vie -= nb;
	if (_vie < 0) {
		_vie = 0;
	}
}

int Personnage::pourcentageVie() const
{
	return ceil((static_cast<double>(_vie)/ static_cast<double>(_vieMax))*100);
}

bool Personnage::estEnVie()const {
	return _vie > 0;
}

int Personnage::force()const {
	return _force;
}

int Personnage::vitesse() const
{
	return _vitesse;
}

int Personnage::niveau()const {
	return _niveau;
}
int Personnage::soins(double RatioMin,double RatioMax) const {
	double SOINS = Aleatoire(RatioMin,RatioMax).decimal()*force();
	if (Aleatoire().entier() < _pourcentageCritique) {
		SOINS *= (_degatCritique / 100.0 + 1);
	}
	if (Aleatoire().entier() < _chanceHabilete) {
		SOINS *= 2;
	}
	return static_cast<int>(SOINS);

}

int Personnage::degats(double RatioMin, double RatioMax) const
{
	double degat = Aleatoire(RatioMin, RatioMax).decimal()*(force()*1.0);
	if (Aleatoire().entier() < _pourcentageCritique) {
		degat *= (_degatCritique / 100.0 + 1);
	}
	if (Aleatoire().entier() < _chanceHabilete) {
		degat *= 2;
	}
	return static_cast<int>(degat);
}

void Personnage::soigner(int soins,Personnage * P)
{
	Affichage H;
	P->AjouterVie(soins);
	H.dessinerJoueur(P->indiceEquipe() + 1, P->equipeAllier().ia(), P);
	H.dessinerSoins(P, soins);
}

void Personnage::AjouterVie(int montant) {
	_vie += montant;
	if (_vie > _vieMax) {
		_vie = _vieMax;
	}
}

bool Personnage::estAttaquable()const {
	return (estEnVie() && _pourcentageEsquive < Aleatoire().entier());
}

void Personnage::setEnnemis(Equipes & E)
{
	_E = E;
}

void Personnage::setAllier(Equipes & A)
{
	_A = A;
}

Equipes & Personnage::equipeAllier() 
{
	return _A;
}

Equipes & Personnage::equipeEnnemi() 
{
	return _E;
}

void  Personnage::Attaque(int Degat, Personnage * Defenseur) 
{
	std::cout << _nom << " attaque " << Defenseur->nom() << std::endl;
	
	if (Defenseur->estAttaquable()) {
		if (Defenseur->bloque()) {
			Degat /= 2;
		}
		Degat = Defenseur->reductionDesDegats(Degat);
		if (Degat < 0) {
			Degat = 0;
		}
		if (Defenseur->devie()) {
			std::cout << "Devie";
			Defenseur->Attaque(Degat, this);
			std::cout << _vie << std::endl;
		}
		else {
			Affichage H;
			H.dessinerAttaque(this, Defenseur);
			Defenseur->reduireVie(Degat);
			
			H.dessinerJoueur(Defenseur->indiceEquipe()+1, Defenseur->equipeAllier().ia(), Defenseur);
			H.dessinerDegats(Defenseur, Degat);
			if (!Defenseur->estEnVie()) {
				//plus tard
			}
		}
	}
	
}

bool Personnage::bloque()const {
	return Aleatoire().entier() < _pourcentageBlocage;
}

bool Personnage::attaqueDouble()const {
	return Aleatoire().entier() < _chanceDoubleAttaque;
}

void Personnage::ajouterMana(int n) {
	_mana+=n;
}
int Personnage::reductionDesDegats(int entier)const {
	return static_cast<int>(entier*(1 - _pourcentageReduction / 100.0));
}

bool Personnage::devie()const {
	return Aleatoire().entier() < _pourcentageDeviation;
}

bool Personnage::ricoche()const {
	return Aleatoire().entier() < _pourcentageRicochet;
}

void Personnage::modifierIndiceEquipe(int i) {
	_indiceEquipe = i;
}

int Personnage::choixAttaque()
{
	return Aleatoire(0, (_mana % 4 + 1)).entier();
}

int Personnage::indiceEquipe()const {
	return _indiceEquipe;
}
