#include "Personnage.h"
#include "Aleatoire.h"
#include "Affichage.h"
#include <iostream>





Personnage::Personnage(int LVL, std::string nom,int vieLVL,int forceLVL,int vitesseLVL,int chanceDoubleAttaque,int chanceHabilete,int pourcentageReduction,int pourcentageDeviation,int pourcentageBlocage,int pourcentageEsquive,int pourcentageRicochet, int indiceAnimal, int rareteAnimal) :
	_vieMax{ vieLVL*LVL*10 }, _vie{ vieLVL*LVL*10 }, _nom{ nom },_id{-1},_niveau{LVL},_force{forceLVL*LVL},_vitesse{vitesseLVL*LVL},_chanceDoubleAttaque{chanceDoubleAttaque},
	_chanceHabilete{chanceHabilete},_pourcentageReduction{pourcentageReduction},_pourcentageDeviation{pourcentageDeviation},_pourcentageBlocage{pourcentageBlocage},_pourcentageEsquive{pourcentageEsquive},_pourcentageRicochet{pourcentageRicochet},
	_mana{0},_pourcentageCritique{10},_degatCritique{50},_nbFoisJouer{0},_bouclier{0},_indiceAnimal{indiceAnimal},_rareteAnimal{rareteAnimal}
{
}

Personnage::Personnage(int id,Experiences E,Orbes O,Animaux A, std::string nom, int vieLVL, int forceLVL, int vitesseLVL, int chanceDoubleAttaque, int chanceHabilete, int pourcentageReduction, int pourcentageDeviation, int pourcentageBlocage, int pourcentageEsquive, int pourcentageRicochet) :
	_nom{ nom }, _id{ id }, _chanceDoubleAttaque{ chanceDoubleAttaque },
	_chanceHabilete{ chanceHabilete }, _pourcentageReduction{ pourcentageReduction }, _pourcentageDeviation{ pourcentageDeviation }, _pourcentageBlocage{ pourcentageBlocage }, _pourcentageEsquive{ pourcentageEsquive }, _pourcentageRicochet{ pourcentageRicochet },
	_mana{ 0 }, _pourcentageCritique{ 10 }, _degatCritique{ 50 }, _nbFoisJouer{ 0 }, _bouclier{ 0 }
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
	_indiceAnimal = A.indiceAnimal(_id);
	_rareteAnimal = A.rareteAnimal(_id, _indiceAnimal);
	//A.animalDuPersonnage(_id, _indiceAnimal, _rareteAnimal);
	std::cout << _indiceAnimal << " " << _rareteAnimal;
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

int Personnage::reduireBouclier(int nb)
{
	int ecart;
	if (nb > _bouclier) {
		ecart = nb - _bouclier;
		_bouclier = 0;
	}
	else {
		ecart = 0;
		_bouclier = _bouclier - nb;
	}
	return ecart;
}

int Personnage::pourcentageVie() const
{
	return ceil((static_cast<double>(_vie)/ static_cast<double>(_vieMax))*100);
}

int Personnage::pourcentageBouclier() const
{
	return ceil((static_cast<double>(_bouclier) / static_cast<double>(bouclierMax()) * 100));
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
void Personnage::ajouterForce(int montant)
{
	_force += montant;
}
void Personnage::ajouterVitesse(int montant)
{
	_vitesse += montant;
}
void Personnage::ajouterVie(int montant)
{
	_vie += montant;
	_vieMax = _vie;
}
int Personnage::xpDonner() const
{
	double xp;
	double multiplicateur = 1.0;
	xp = _force / 10.0 + _vitesse / 10.0 + _vieMax / 100.0;
	multiplicateur += _chanceDoubleAttaque / 100.0 + _chanceHabilete / 100.0 + _pourcentageRicochet / 100.0 + _pourcentageReduction / 100.0 + _pourcentageEsquive / 100.0 + _pourcentageDeviation / 100.0 + _pourcentageBlocage / 100.0;
	return round(xp * multiplicateur);
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
	if (P->estEnVie()) {
		P->AjouterVie(soins);	
	}
}

void Personnage::AjouterVie(int montant) {
	if (montant < 0) {
		montant = 0;
	}
	_vie += montant;
	Affichage H;
	H.dessinerSoins(this, montant);
	
	if (_vie > _vieMax) {
		_vie = _vieMax;	
	}
	H.dessinerJoueur(this->indiceEquipe() + 1, this->equipeAllier().ia(), this);
}

void Personnage::bouclier(int soins, Personnage* P)
{
	if (P->estEnVie()) {
		P->AjouterBouclier(soins);
	}
}

void Personnage::AjouterBouclier(int montant) {
	if (montant < 0) {
		montant = 0;
	}
	_bouclier += montant;
	Affichage H;

	
	H.dessinerBouclier(this,montant);
	if (_bouclier > bouclierMax()) {
		_bouclier = bouclierMax();
		
	}
	H.dessinerJoueur(this->indiceEquipe() + 1, this->equipeAllier().ia(), this);
}

int Personnage::bouclierMax()const {
	return (_force * 10 + _vieMax)/2;
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
void Personnage::traitementAnimaux() {
	switch (_indiceAnimal) {
	case 0:
		if (Aleatoire(0, 101).entier() < (6 +3 * (_rareteAnimal-1))) {
			int Soins=soins(0.08 * _rareteAnimal - 1, 0.08 * _rareteAnimal);
			Affichage().dessinerTexte(this->nom()+" soin de zone animal");
			_A.soignerZone(Soins, this);
		}
		break;
	case 1:
		if (Aleatoire(0, 101).entier() < (10 + 5 * (_rareteAnimal - 1))) {
			int Soins = soins(pow(2, _rareteAnimal - 1) * 0.05, pow(2, _rareteAnimal - 1) * 0.10);
			Affichage().dessinerTexte(this->nom() + " soigne le plus faible animal");
			soigner(Soins, _A.plusFaible());
		}
		break;
	case 2:
		if (Aleatoire(0, 101).entier() < (3 + 8 * (_rareteAnimal - 1))) {
			int Soins = soins(_rareteAnimal * 0.10, 0.15 + 0.20 *(_rareteAnimal-1));
			Affichage().dessinerTexte(this->nom() + " soigne une personne aleatoire animal");
			soigner(Soins, _A.aleatoireEnVie());
		}
		break;
	case 3:
		if (Aleatoire(0, 101).entier() < (4 + 4 * (_rareteAnimal - 1))) {
			int Degats = degats(0.02 * _rareteAnimal - 1, 0.06 * _rareteAnimal);
			Affichage().dessinerTexte(this->nom() + " attaque le plus faible animal ");
			Attaque(Degats, _E.plusFaible());
		}
		break;
	case 4:
		if (Aleatoire(0, 101).entier() < (2 + 5 * (_rareteAnimal - 1))) {
			int Degats = degats(pow(2, _rareteAnimal - 1) * 0.01+0.01, pow(2, _rareteAnimal ) * 0.01 + 0.02);
			Affichage().dessinerTexte(this->nom() + " attaque de zone animal");
			_E.attaqueZone(Degats, this);
		}
		break;
	case 5:
		if (Aleatoire(0, 101).entier() < (2 + 8 * (_rareteAnimal - 1))) {
			int Degats = degats(0.06 * _rareteAnimal - 1, 0.12 * _rareteAnimal);
			Affichage().dessinerTexte(this->nom() + " attaque une personne aleatoire animal");
			Attaque(Degats, _E.aleatoireEnVie());
		}
		break;
	case 6:
		if (Aleatoire(0, 101).entier() < (3 + 4 * (_rareteAnimal - 1))) {
			int Soins = soins(0.04 * _rareteAnimal - 1, 0.09 * _rareteAnimal);
			Affichage().dessinerTexte(this->nom() + " bouclier de zone animal");
			_A.bouclierZone(Soins, this);
		}
		break;
	case 7:
		if (Aleatoire(0, 101).entier() < (3 + 8 * (_rareteAnimal - 1))) {
			int Soins = soins(pow(2, _rareteAnimal - 1) * 0.03, pow(2, _rareteAnimal - 1) * 0.06);
			Affichage().dessinerTexte(this->nom() + " bouclier le plus faible animal");
			bouclier(Soins, _A.plusFaible());
		}
		break;
	case 8:
		if (Aleatoire(0, 101).entier() < (1 + 10 * (_rareteAnimal - 1))) {
			int Soins = soins(_rareteAnimal * 0.05, 0.10 + 0.10 * (_rareteAnimal - 1));
			Affichage().dessinerTexte(this->nom() + " bouclier une personne aleatoire animal");
			bouclier(Soins, _A.aleatoireEnVie());
		}
		break;
	case 9:
		if (Aleatoire(0, 101).entier() < (1 + 11 * (_rareteAnimal - 1))) {
			int Soins = soins(_rareteAnimal * 0.03, 0.06 + 0.06 * (_rareteAnimal - 1));
			Affichage().dessinerTexte(this->nom() + " soin et bouclier de zone");
			_A.soignerZone(Soins, this);
			Soins = soins(_rareteAnimal * 0.01, 0.03 + 0.03 * (_rareteAnimal - 1));
			_A.bouclierZone(Soins, this);
		}
		break;
	}
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
			Defenseur->passifDefensif();
			Defenseur->traitementAnimaux();
			this->traitementAnimaux();
			Affichage H;
			
			H.dessinerAttaque(this, Defenseur);
		
			if (Defenseur->bouclier() > 0) {
				Degat=Defenseur->reduireBouclier(Degat);
			}
			if (Degat > 0) {
				Defenseur->reduireVie(Degat);
			}
			H.dessinerJoueur(Defenseur->indiceEquipe()+1, Defenseur->equipeAllier().ia(), Defenseur);
			H.dessinerDegats(Defenseur, Degat);
			if (!Defenseur->estEnVie()) {
				//plus tard
			}
		}
	}
	if (ricoche()&&_E.estEnVie()) {
		Attaque(Degat, _E.aleatoireEnVie());
	}
}

void Personnage::ajouterChanceDoubleAttaque(int montant) {
	_chanceDoubleAttaque += montant;
}
void Personnage::ajouterChanceHabileter(int montant) {
	_chanceHabilete += montant;
}
void Personnage::ajouterReduction(int montant) {
	_pourcentageReduction += montant;
	if (_pourcentageReduction >= 100) {
		_pourcentageReduction = 99;
	}
}
int Personnage::bouclier()const {
	return _bouclier;
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

int Personnage::chanceDoubleAttaque() const
{
	return _chanceDoubleAttaque;
}

int Personnage::chanceHabileter() const
{
	return _chanceHabilete;
}

int Personnage::pourcentageDeviation() const
{
	return _pourcentageDeviation;
}

int Personnage::pourcentageReduction() const
{
	return _pourcentageReduction;
}

int Personnage::pourcentageRicochet() const
{
	return _pourcentageRicochet;
}

int Personnage::pourcentageEsquive() const
{
	return _pourcentageEsquive;
}

int Personnage::pourcentageBlocage() const
{
	return _pourcentageBlocage;
}
