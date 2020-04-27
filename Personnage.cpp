#include "Personnage.h"
#include "Aleatoire.h"
#include "Affichage.h"
#include <iostream>





Personnage::Personnage(int LVL, std::string nom, int vieLVL, int forceLVL, int vitesseLVL, int chanceDoubleAttaque, int chanceHabilete, int pourcentageReduction, int pourcentageDeviation, int pourcentageBlocage, int pourcentageEsquive, int pourcentageRicochet, int indiceAnimal, int rareteAnimal) :
	_vieMax{ vieLVL * LVL * 10 }, _vie{ vieLVL * LVL * 10 }, _nom{ nom }, _id{ -1 }, _niveau{ LVL }, _force{ forceLVL * LVL }, _vitesse{ vitesseLVL * LVL }, _chanceDoubleAttaque{ chanceDoubleAttaque },
	_chanceHabilete{ chanceHabilete }, _pourcentageReduction{ pourcentageReduction }, _pourcentageDeviation{ pourcentageDeviation }, _pourcentageBlocage{ pourcentageBlocage }, _pourcentageEsquive{ pourcentageEsquive }, _pourcentageRicochet{ pourcentageRicochet },
	_mana{ 0 }, _pourcentageCritique{ 10 }, _degatCritique{ 50 }, _bouclier{ 0 }, _indiceAnimal{ indiceAnimal }, _rareteAnimal{ rareteAnimal }
{
	_statusPerso = Status(this);
	_animal = Animal(_indiceAnimal);
	_objets.first = Objet();
	_objets.second = Objet();
}

Personnage::Personnage(int id,Experiences E,Orbes O,Animaux A, Objets Obj, std::string nom, int vieLVL, int forceLVL, int vitesseLVL, int chanceDoubleAttaque, int chanceHabilete, int pourcentageReduction, int pourcentageDeviation, int pourcentageBlocage, int pourcentageEsquive, int pourcentageRicochet) :
	_nom{ nom }, _id{ id }, _chanceDoubleAttaque{ chanceDoubleAttaque },
	_chanceHabilete{ chanceHabilete }, _pourcentageReduction{ pourcentageReduction }, _pourcentageDeviation{ pourcentageDeviation }, _pourcentageBlocage{ pourcentageBlocage }, _pourcentageEsquive{ pourcentageEsquive }, _pourcentageRicochet{ pourcentageRicochet },
	_mana{ 0 }, _pourcentageCritique{ 10 }, _degatCritique{ 50 }, _bouclier{ 0 }
{
	int bonusLVLattaque;
	int bonusLVLvie;
	int bonusLVLvitesse;
	O.buffOrbes(_id, bonusLVLattaque, bonusLVLvie, bonusLVLvitesse);
	_niveau = E.calculNiveau(id);
	_vie = (vieLVL + bonusLVLvie) * _niveau * 10;
	_vieMax = _vie;
	_force = (forceLVL + bonusLVLattaque) * _niveau;
	_vitesse = (vitesseLVL + bonusLVLvitesse) * _niveau;
	_indiceAnimal = A.indiceAnimal(_id);
	_rareteAnimal = A.rareteAnimal(_id, _indiceAnimal);
	//A.animalDuPersonnage(_id, _indiceAnimal, _rareteAnimal);
	std::cout << _indiceAnimal << " " << _rareteAnimal;
	_animal = Animal(_indiceAnimal);
	_statusPerso = Status(this);
	Obj.objetsDuPersonnage(_id, _objets.first, _objets.second);
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
	_S.ajouterAugmentationVieMax(montant);
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
	_S.ajouterAugmentationForce(montant);
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
		if (possedeObjetNumero(6)) {
			if (Aleatoire(0, 101).entier() < 5) {
				SOINS *= 4;
			}else if (Aleatoire(0, 101).entier() < 10) {
				SOINS *= 3;
			}
			else {
				SOINS *= 2;
			}
			std::cout << " OBJ6 ";
		}
		else {
			SOINS *= 2;
		}
		
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
		if (possedeObjetNumero(6)) {
			if (Aleatoire(0, 101).entier() < 5) {
				degat *= 4;
			}
			else if (Aleatoire(0, 101).entier() < 10) {
				degat *= 3;
			}
			else {
				degat *= 2;
			}
			std::cout << " OBJ6 ";
		}
		else {
			degat *= 2;
		}
		
	}
	return round(degat);
}

void Personnage::soigner(int soins,Personnage * P)
{	if (P->estEnVie()) {
		if ((soins + P->vie()) > P->vieMax()) {
			soins = P->vieMax() - P->vie();
			
		}
		P->stats().ajouterSoinsDonner(soins);
		P->AjouterVie(soins);
		if (possedeObjetNumero(4)) {
			if (Aleatoire(0, 101).entier() < 20) {
				P->bouclier(soins, P);
			}
			std::cout << " OBJ4 ";
		}
	}
}

void Personnage::AjouterVie(int montant) {
	if (montant <= 0) {
		montant = 0;
	}
	else {
		_vie += montant;
		Affichage H;
		H.dessinerSoins(this, montant);
	
		if (_vie > _vieMax) {
			_vie = _vieMax;	
		}
		H.dessinerJoueur(this->indiceEquipe() + 1, this->equipeAllier().ia(), this);
	}
}

void Personnage::bouclier(int soins, Personnage* P)
{
	if (P->estEnVie()) {
		if ((soins + P->bouclier()) >P->bouclierMax()) {
			soins = P->bouclierMax() - P->bouclier();

		}
		P->stats().ajouterBouclierDonner(soins);
		P->AjouterBouclier(soins);
		if (possedeObjetNumero(4)) {
			if (Aleatoire(0, 101).entier() < 10) {
				P->status().ajouterCompteurProteger(1);
			}
			std::cout << " OBJ4 ";
		}
	}
}

void Personnage::AjouterBouclier(int montant) {
	if (montant <= 0) {
		montant = 0;
	}
	else {
		_bouclier += montant;
		Affichage H;

		H.dessinerBouclier(this,montant);
		if (_bouclier > bouclierMax()) {
			_bouclier = bouclierMax();
		
		}
		H.dessinerJoueur(this->indiceEquipe() + 1, this->equipeAllier().ia(), this);
	}
	
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

	bool redirection = false;
	Degat++;
	std::string FRAGILISER = "";
	std::string PROTEGER = "";
	int degatEffectif;
	if (Defenseur->estAttaquable()) {

		if (possedeObjetNumero(5)) {
			Degat *= 2.5;
			std::cout << " OBJ5 ";
		}
		if (possedeObjetNumero(16)) {
			Degat *= 1.2;
			std::cout << " OBJ16 ";
		}
		if (possedeObjetNumero(12) && _S.nbAttaquesRecues()%3==0) {
			Degat *= 1.3;
			std::cout << " OBJ12 ";
		}
		if (Defenseur->bloque()) {
			Degat /= 2;
		}
		if (Defenseur->status().estProteger()) {
			Degat /= 2;
			PROTEGER = "PROTEGER";
		}
		if (Defenseur->status().estFragiliser()) {
			Degat *= 2;
			FRAGILISER = "FRAGILISER";
		}
		Defenseur->status().decrementerCompteur();

		Degat = Defenseur->reductionDesDegats(Degat);
		if (Degat < 0) {
			Degat = 0;
		}
		if (Defenseur->devie()) {
			if (Defenseur->possedeObjetNumero(9)) {
				Degat *= 1.5;
				std::cout << " OBJ9 ";
			}
			Defenseur->Attaque(Degat, this);
			
		}
		else if (Defenseur->possedeObjetNumero(10) && Aleatoire(0, 101).entier() < 10) {
			Defenseur->AjouterBouclier(Degat / 10);
		}
		else {

			for (int i = 0;i < Defenseur->equipeAllier().taille()&&!redirection;i++) {
				if (Defenseur->equipeAllier()[i]->possedeObjetNumero(11) && Aleatoire(0, 101).entier() < 25) {
					redirection = true;
					Attaque(Degat, Defenseur->equipeAllier()[i]);
					std::cout << " OBJ11 ";
				}
			}
			if (!redirection) {
				Defenseur->passifDefensif();
				Defenseur->traitementAnimaux();
				this->traitementAnimaux();

				degatEffectif = Degat;

				std::cout << _nom << " attaque " << Defenseur->indiceEquipe() << Defenseur->nom() << " " << FRAGILISER << " " << PROTEGER;
				std::cout << " " << Degat << std::endl;
				if (Defenseur->possedeObjetNumero(25)) {
					Degat -= Defenseur->niveau();
					std::cout << " OBJ25 ";
				}
				if (Defenseur->bouclier() > 0) {
					Degat = Defenseur->reduireBouclier(Degat);
				}
				if (Degat > 0) {
					if (Degat > Defenseur->vie()) {
						Degat = Defenseur->vie();
					}
					_S.ajouterDegatsProvoquer(Degat);
					_S.incrementerNbAttaques();
					Defenseur->stats().incrementerNbAttaquesRecues();
					Defenseur->reduireVie(Degat);
					if (Defenseur->possedeObjetNumero(14) && _A.estEnVie()) {
						Defenseur->AttaqueBrut(Degat / 10, _A.plusProcheVivant());
						std::cout << " OBJ14 ";
					}
				}
				Affichage H;
				H.dessinerAttaque(this, Defenseur);
				H.dessinerJoueur(Defenseur->indiceEquipe() + 1, Defenseur->equipeAllier().ia(), Defenseur);
				H.dessinerDegats(Defenseur, degatEffectif);
			}
		}
		if (ricoche()&&_E.estEnVie()&&!redirection) {
			
			if (Aleatoire().entier() < _pourcentageCritique) {
				Degat *= (_degatCritique / 100.0 + 1);
			}
			if (Aleatoire().entier() < _chanceHabilete) {
				Degat *= 2;
			}
			if (possedeObjetNumero(27)) {
				Degat *= 1.3;
			}
			Attaque(Degat, _E.aleatoireEnVie());
		}
	}
	else{
		if (Defenseur->possedeObjetNumero(15)) {
			Defenseur->ajouterDegatsCritique(5);
			std::cout << " OBJ15 ";
		}
		if (Defenseur->possedeObjetNumero(16)) {
			Defenseur->AttaqueBrut(degats(0.2,0.4),_A.plusFaible());
			std::cout << " OBJ16 ";
		}
	}
	if (possedeObjetNumero(13) && _E.estEnVie()) {
		Degat = degats(0.05, 0.10);
		AttaqueBrut(Degat, _E.plusFaible());
		std::cout << " OBJ13 ";
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
	_S.ajouterAugmentationChanceDoubleAttaque(montant);
}
void Personnage::ajouterChanceHabileter(int montant) {
	_chanceHabilete += montant;
	_S.ajouterAugmentationChanceHabileter(montant);
}
void Personnage::ajouterReduction(int montant) {
	_pourcentageReduction += montant;
	_S.ajouterAugmentationReduction(montant);
	if (_pourcentageReduction >= 95) {
		_pourcentageReduction = 95;
	}
}

void Personnage::ajouterDeviation(int montant) {
	_pourcentageDeviation += montant;
}

void Personnage::ajouterChanceRicochet(int montant) {
	_pourcentageRicochet += montant;
}

void Personnage::ajouterEsquive(int montant) {
	_pourcentageEsquive += montant;
}
bool Personnage::possedeObjetNumero(int i)const {
	return (_objets.first.numero() == i || _objets.second.numero());

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
	_S.ajouterAugmentationCoupCritiques(pourcentage);
	_pourcentageCritique += pourcentage;
	if (_pourcentageCritique > 100) {
		_pourcentageCritique = 100;
	}
}

void Personnage::ajouterDegatsCritique(int pourcentage)
{
	_S.ajouterAugmentationDegatsCritique(pourcentage);
	_degatCritique += pourcentage;
}

void Personnage::setNom(std::string nom)
{
	_nom = nom;
}

void Personnage::modifierStats(double ratio)
{
	std::cout << "ratio " << ratio <<" "<< std::endl;
	if (ratio > -1.0) {
		_force = round(_force * (1.0 + ratio));
		_vieMax = round(_vie * (1.0 + ratio));
		_vie = _vieMax;
		_vitesse = round(_vitesse * (1.0+ratio));
	}
	else {
		_force = 1;
		_vie = 1;
		_vieMax = 1;
		_vitesse = 1;
	}
}

Status& Personnage::status()
{
	return _statusPerso;
}

std::pair<Objet, Objet> Personnage::objets()
{
	return _objets;
}

void Personnage::equiperObjet(Objet obj, bool premier) {
	if (premier == true) {
		_objets.first = obj;
	}
	else {
		_objets.second = obj;
	}
}

void Personnage::appliquerEffets() {
	_objets.first.appliquerEffet(this);
	_objets.second.appliquerEffet(this);
}

