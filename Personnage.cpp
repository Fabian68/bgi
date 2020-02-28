#include "Personnage.h"
#include "Aleatoire.h"
#include "Affichage.h"
#include <iostream>





Personnage::Personnage(int LVL, std::string nom,int vieLVL,int forceLVL,int vitesseLVL,int chanceDoubleAttaque,int chanceHabilete,int pourcentageReduction,int pourcentageDeviation,int pourcentageBlocage,int pourcentageEsquive,int pourcentageRicochet, int indiceAnimal, int rareteAnimal) :
	_vieMax{ vieLVL*LVL*10 }, _vie{ vieLVL*LVL*10 }, _nom{ nom },_id{-1},_niveau{LVL},_force{forceLVL*LVL},_vitesse{vitesseLVL*LVL},_chanceDoubleAttaque{chanceDoubleAttaque},
	_chanceHabilete{chanceHabilete},_pourcentageReduction{pourcentageReduction},_pourcentageDeviation{pourcentageDeviation},_pourcentageBlocage{pourcentageBlocage},_pourcentageEsquive{pourcentageEsquive},_pourcentageRicochet{pourcentageRicochet},
	_mana{0},_pourcentageCritique{10},_degatCritique{50},_bouclier{0},_indiceAnimal{indiceAnimal},_rareteAnimal{rareteAnimal}
{
	_animal = Animal(_indiceAnimal);
}

Personnage::Personnage(int id,Experiences E,Orbes O,Animaux A, std::string nom, int vieLVL, int forceLVL, int vitesseLVL, int chanceDoubleAttaque, int chanceHabilete, int pourcentageReduction, int pourcentageDeviation, int pourcentageBlocage, int pourcentageEsquive, int pourcentageRicochet) :
	_nom{ nom }, _id{ id }, _chanceDoubleAttaque{ chanceDoubleAttaque },
	_chanceHabilete{ chanceHabilete }, _pourcentageReduction{ pourcentageReduction }, _pourcentageDeviation{ pourcentageDeviation }, _pourcentageBlocage{ pourcentageBlocage }, _pourcentageEsquive{ pourcentageEsquive }, _pourcentageRicochet{ pourcentageRicochet },
	_mana{ 0 }, _pourcentageCritique{ 10 }, _degatCritique{ 50 }, _bouclier{ 0 }
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
	_animal = Animal(_indiceAnimal);
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
void Personnage::ajouterVieMax(int montant) {
	_vieMax += montant;
}

void Personnage::reduireVieMax(int montant) {
	ajouterVieMax(-montant);
	if (_vie > _vieMax) {
		_vie = _vieMax;
	}
}
void Personnage::reduireVie(int nb)
{
	if (_vie < nb) {
		_S.ajouterDegatsRecu(_vie);
		_vie = 0;
	}
	else {
		_vie -= nb;
		_S.ajouterDegatsRecu(nb);
	}
}

int Personnage::reduireBouclier(int nb)
{
	int ecart;
	if (nb > _bouclier) {
		ecart = nb - _bouclier;
		_bouclier = 0;
		_S.ajouterDegatsRecu(ecart);
	}
	else {
		ecart = 0;
		_bouclier = _bouclier - nb;
		_S.ajouterDegatsRecu(nb);
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
	if (Aleatoire().entier() <= _pourcentageCritique) {
		SOINS *= (_degatCritique / 100.0 + 1);
	}
	if (Aleatoire().entier() <= _chanceHabilete) {
		SOINS *= 2;
	}
	return round(SOINS);

}

Statistiques& Personnage::stats() {
	return _S;
}
int Personnage::degats(double RatioMin, double RatioMax) const
{
	double degat = Aleatoire(RatioMin, RatioMax).decimal()*(force()*1.0);
	if (Aleatoire().entier() <= _pourcentageCritique) {
		degat *= (_degatCritique / 100.0 + 1);
	}
	if (Aleatoire().entier() <= _chanceHabilete) {
		degat *= 2;
	}
	return round(degat);
}

void Personnage::soigner(int soins,Personnage * P)
{	if (P->estEnVie()) {
		if ((soins + _vie) > _vieMax) {
			soins = _vieMax - _vie;
			
		}
		P->stats().ajouterSoinsDonner(soins);
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
		if ((soins + _bouclier) >bouclierMax()) {
			soins = bouclierMax() - _bouclier;

		}
		P->stats().ajouterBouclierDonner(soins);
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

void Personnage::ajouterBouclier(int montant) {
	_bouclier += montant;
}
int Personnage::bouclierMax()const {
	return (_force * 10 + _vieMax)/4;
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

bool Personnage::habile()const {
	return Aleatoire(0, 101).entier() <= _chanceHabilete;
}
void Personnage::traitementAnimaux() {
	if (_animal.activer(_rareteAnimal)) {
		int Soins = soins(_animal.ratioMin(_rareteAnimal), _animal.ratioMax(_rareteAnimal));
		int Degats = degats(_animal.ratioMin(_rareteAnimal), _animal.ratioMax(_rareteAnimal));
		std::cout << _nom+_animal.type()+"animal" << std::endl;
		switch (_indiceAnimal) {
		case 0:
				_A.soignerZone(Soins, this);
			break;
		case 1:
				soigner(Soins, _A.plusFaible());	
			break;
		case 2:
				soigner(Soins, _A.aleatoireEnVie());
			break;
		case 3:
				Attaque(Degats, _E.plusFaible());
			break;
		case 4:
				_E.attaqueZone(Degats, this);
			break;
		case 5:
				Attaque(Degats, _E.aleatoireEnVie());
			break;
		case 6:
				_A.bouclierZone(Soins, this);
			break;
		case 7:
				bouclier(Soins, _A.plusFaible());
			break;
		case 8:
				bouclier(Soins, _A.aleatoireEnVie());
			break;
		case 9:
				_A.soignerZone(Soins, this);
				_A.bouclierZone(Soins, this);
			break;
		}
	}
}
void  Personnage::Attaque(int Degat, Personnage * Defenseur) 
{
	
	int degatEffectif;
	if (Defenseur->estAttaquable()) {
		if (Defenseur->bloque()) {
			Degat /= 2;
		}
		Degat = Defenseur->reductionDesDegats(Degat);
		if (Degat < 0) {
			Degat = 0;
		}
		if (Defenseur->devie()) {
			
			Defenseur->Attaque(Degat, this);
			
		}
		else {
			Defenseur->passifDefensif();
			Defenseur->traitementAnimaux();
			this->traitementAnimaux();
		
			degatEffectif = Degat;
			
			std::cout << _nom << " attaque " <<Defenseur->indiceEquipe()<< Defenseur->nom();
			std::cout << " "<<Degat << std::endl;
			if (Defenseur->bouclier() > 0) {
				Degat=Defenseur->reduireBouclier(Degat);
			}
			if (Degat > 0) {
				if (Degat > Defenseur->vie()) {
					Degat = Defenseur->vie();
				}
				_S.ajouterDegatsProvoquer(Degat);
				_S.incrementerNbAttaques();
				Defenseur->stats().incrementerNbAttaquesRecues();
				Defenseur->reduireVie(Degat);
			}
			Affichage H;
			H.dessinerAttaque(this, Defenseur);
			H.dessinerJoueur(Defenseur->indiceEquipe()+1, Defenseur->equipeAllier().ia(), Defenseur);
			H.dessinerDegats(Defenseur, degatEffectif);
		}
		if (ricoche()&&_E.estEnVie()) {
			
			if (Aleatoire().entier() < _pourcentageCritique) {
				Degat *= (_degatCritique / 100.0 + 1);
			}
			if (Aleatoire().entier() < _chanceHabilete) {
				Degat *= 2;
			}
			Attaque(Degat, _E.aleatoireEnVie());
		}
	}
	
}

void  Personnage::AttaqueBrut(int Degat, Personnage* Defenseur)
{
	if (Defenseur->estAttaquable()) {
			std::cout << _nom << " attaqueBrut " << Defenseur->indiceEquipe() << Defenseur->nom();
			std::cout << " " << Degat << std::endl;
			if (Degat > 0) {
				if (Degat > Defenseur->vie()) {
					Degat = Defenseur->vie();
				}
				_S.ajouterDegatsProvoquer(Degat);
				_S.incrementerNbAttaques();
				Defenseur->stats().incrementerNbAttaquesRecues();
				Defenseur->reduireVie(Degat);
			}
			Affichage H;
			H.dessinerAttaque(this, Defenseur);
			H.dessinerJoueur(Defenseur->indiceEquipe() + 1, Defenseur->equipeAllier().ia(), Defenseur);
			H.dessinerDegats(Defenseur, Degat);
	}

}

int Personnage::degatsCritiques()const {
	return _degatCritique;
}
void Personnage::setReduction(int montant) {
	_pourcentageReduction = montant;
}
void Personnage::ajouterChanceDoubleAttaque(int montant) {
	_chanceDoubleAttaque += montant;
}
void Personnage::ajouterChanceHabileter(int montant) {
	_chanceHabilete += montant;
}
void Personnage::ajouterReduction(int montant) {
	_pourcentageReduction += montant;
	if (_pourcentageReduction >= 90) {
		_pourcentageReduction = 90;
	}
}
int Personnage::bouclier()const {
	return _bouclier;
}
bool Personnage::bloque()const {
	return Aleatoire().entier() <= _pourcentageBlocage;
}

bool Personnage::attaqueDouble()const {
	return Aleatoire().entier() <= _chanceDoubleAttaque;
}

void Personnage::ajouterMana(int n) {
	_mana+=n;
}
int Personnage::reductionDesDegats(int entier)const {
	return static_cast<int>(entier*(1 - _pourcentageReduction / 100.0));
}

bool Personnage::devie()const {
	return Aleatoire().entier() <= _pourcentageDeviation;
}

bool Personnage::ricoche()const {
	return Aleatoire().entier() <= _pourcentageRicochet;
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

void Personnage::setId(int val)
{
	_id = val;
}

void Personnage::setAnimal(Animal A)
{
	_animal = A;
}

Animal Personnage::animal() const
{
	return _animal;
}

int Personnage::rareterAnimal() const
{
	return _rareteAnimal;
}

void Personnage::ajouterCoupCritique(int pourcentage)
{
	_pourcentageCritique += pourcentage;
	if (_pourcentageCritique > 100) {
		_pourcentageCritique = 100;
	}
}

void Personnage::ajouterDegatsCritique(int pourcentage)
{
	_degatCritique += pourcentage;
}

void Personnage::setNom(std::string nom)
{
	_nom = nom;
}


