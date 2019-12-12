#include "Personnage.h"
#include "Aleatoire.h"
#include "Affichage.h"



Personnage::Personnage() : _vieMax{ 100 }, _vie{ 100 }, _nom{ "BASE" }
{
}

Personnage::Personnage(int id,int LVL, std::string nom,int vieLVL,int forceLVL,int vitesseLVL,int chanceDoubleAttaque,int chanceHabilete,int pourcentageReduction,int pourcentageDeviation,int pourcentageBlocage,int pourcentageEsquive,int pourcentageRicochet,bool ia) : 
	_vieMax{ vieLVL*LVL }, _vie{ vieLVL*LVL }, _nom{ nom },_id{id},_niveau{LVL},_force{forceLVL*LVL},_vitesse{vitesseLVL*LVL},_chanceDoubleAttaque{chanceDoubleAttaque},
	_chanceHabilete{chanceHabilete},_pourcentageReduction{pourcentageReduction},_pourcentageDeviation{pourcentageDeviation},_pourcentageBlocage{pourcentageBlocage},_pourcentageEsquive{pourcentageEsquive},_pourcentageRicochet{pourcentageRicochet},
	_mana{0},_pourcentageCritique{10},_degatCritique{50},_nbFoisJouer{0},_bouclier{0},_ia{ia}
{
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

void Personnage::competence1()
{
	std::cout << "Perso normal";
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

bool Personnage::ia() const
{
	return _ia;
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

void Personnage::soigner(int soins,Personnage & P)
{
	P.AjouterVie(soins);
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

void  Personnage::Attaque(int Degat, Personnage & Defenseur) 
{
	std::cout << _nom << " attaque " << Defenseur.nom() << std::endl;
	
	if (Defenseur.estAttaquable()) {
		if (Defenseur.bloque()) {
			Degat /= 2;
		}
		Degat = Defenseur.reductionDesDegats(Degat);
		if (Degat < 0) {
			Degat = 0;
		}
		if (Defenseur.devie()) {
			std::cout << "Devie";
			Defenseur.Attaque(Degat, *this);
			std::cout << _vie << std::endl;
		}
		else {
			Affichage H;
			H.dessinerAttaque(*this, Defenseur);
			H.dessinerJoueur(Defenseur.indiceEquipe()+1, Defenseur.ia(), Defenseur);
			Defenseur.reduireVie(Degat);
			H.dessinerJoueur(Defenseur.indiceEquipe() + 1, Defenseur.ia(), Defenseur);
			if (!Defenseur.estEnVie()) {

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

int Personnage::indiceEquipe()const {
	return _indiceEquipe;
}
