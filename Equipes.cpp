#include "Equipes.h"
#include "Personnage.h"
#include "Aleatoire.h"
#include <iostream>

Equipes::Equipes() : _equipe{}, _equipeIA(true)
{
}

Equipes::Equipes(bool equipeIA) : _equipeIA{equipeIA}
{
}
Equipes::~Equipes() {
	
}

int Equipes::taille() const
{
	return _equipe.size();
}

Personnage*  Equipes::operator[](int i)const
{
	return _equipe[i];
}

Personnage*  Equipes::perso(int i)
{
	return _equipe[i];
}

void Equipes::setIndiceANul(int indice) {
	_equipe[indice]=nullptr;
}

Personnage* Equipes::plusProcheVivant() 
{
	int trouver = false;
	int i = 0;
	while (i < _equipe.size()&&i<11) {
		
		if (_equipe[i]->estEnVie()) {
			return _equipe[i];
		}
		i++;
	}
	return _equipe[0];
	
}

Personnage* Equipes::plusLoinVivant()
{
	int trouver = false;
	int i = _equipe.size()-1;
	while (i >-1) {
		//std::cout << "Plus loin" << std::endl;
		if (_equipe[i]->estEnVie()) {
			return _equipe[i];
		}
		i--;
	}
	return _equipe[0];
	
}

Personnage* Equipes::plusFaible()
{
	int vieMin = INT_MAX;
	int j = 0;
	for (int i = 0;i < _equipe.size();i++) {
		
		if (_equipe[i]->vie()>0&& _equipe[i]->vie()<vieMin) {
		
			vieMin = _equipe[i]->vie();
			j = i;
		}
	}
	return _equipe[j];
}

Personnage* Equipes::aleatoireEnVie() {
	
	int i;
	if (!estEnVie()) {
		return _equipe[0];
	}
	do { 	
		i = Aleatoire(0, _equipe.size()).entier();
	} while (!_equipe[i]->estEnVie());
	return _equipe[i];
	
}

Personnage* Equipes::meilleurDegats()
{
	int max = INT_MIN;
	int indice = 0;
	for (int i = 0;i < _equipe.size();i++) {
		if (_equipe[i]->stats().degatsProvoquer() > max) {
			max = _equipe[i]->stats().degatsProvoquer();
			indice = i;
		}
	}
	return _equipe[indice];
}

Personnage* Equipes::meilleurTank()
{
	int max = INT_MIN;
	int indice = 0;
	for (int i = 0;i < _equipe.size();i++) {
		if (_equipe[i]->stats().degatsRecu() > max) {
			max = _equipe[i]->stats().degatsRecu();
			indice = i;
		}
	}
	return _equipe[indice];
}

Personnage* Equipes::meilleurSoigneur()
{
	int max = INT_MIN;
	int indice = 0;
	for (int i = 0;i < _equipe.size();i++) {
		if (_equipe[i]->stats().soinsDonner() > max) {
			max = _equipe[i]->stats().soinsDonner();
			indice = i;
		}
	}
	return _equipe[indice];
}

Personnage* Equipes::meilleurBouclier()
{
	int max = INT_MIN;
	int indice = 0;
	for (int i = 0;i < _equipe.size();i++) {
		if (_equipe[i]->stats().bouclierDonner() > max) {
			max = _equipe[i]->stats().bouclierDonner();
			indice = i;
		}
	}
	return _equipe[indice];
}

void Equipes::attaqueZone(int Degats,Personnage * Attaquant)
{
	for (int i = 0; i < _equipe.size(); i++) {
		Attaquant->Attaque(Degats, _equipe[i]);
	}
}

void Equipes::soignerZone(int soins, Personnage* Soigneur)
{
	for (int i = 0; i < _equipe.size(); i++) {
		Soigneur->soigner(soins, _equipe[i]);
	}
}
void Equipes::bouclierZone(int montantBouclier, Personnage* bouclierMan)
{
	for (int i = 0; i < _equipe.size(); i++) {
		bouclierMan->bouclier(montantBouclier, _equipe[i]);
	}
}
void Equipes::vider()
{
/*for (int i = 0;i < _equipe.size();i++) {
		if (! nullptr) {
			delete _equipe[i];
		}
	}*/
	_equipe.resize(0);
}
void Equipes::liberer()
{
	for (int i = 0;i < _equipe.size();i++) {
		if (!nullptr) {
			delete _equipe[i];
		}
	}
		_equipe.resize(0);
}
void Equipes::ajouterExperience(int xp, Experiences E) {
	xp /= _equipe.size();
	std::cout << "Les joueurs gagnent " << xp << " d experiences." << std::endl;
	for (int i = 0; i < _equipe.size(); i++) {
		E.ajouterXP(_equipe[i]->id(), xp);
	}
	E.ecrireEXP("T1.txt");
}
void Equipes::chargerEquipe(Equipes Liste)
{
	FILE* file = fopen("monEquipe.txt", "r");
	if (file == NULL) {
		std::ofstream os("monEquipe.txt");

		for (int i = 0; i < 10; i++) {
			os << -1 << " ";
			os << std::endl;
		}
		os.close();
	}
	else {
		fclose(file);
	}
	

	std::ifstream is("monEquipe.txt");
	int perso;
	for (int i = 0; i < 10; i++) {
		
		is >> perso;
		if (perso != - 1) {
			Liste[perso]->modifierIndiceEquipe(_equipe.size());
			_equipe.push_back(Liste[perso]);
		}
	}
	is.close();
}

void Equipes::sauvegarderEquipe()
{
	std::ofstream os("monEquipe.txt");
	for (int i = 0; i < _equipe.size(); i++) {
		os << _equipe[i]->id();
		os << std::endl;
	}
	for (int i = _equipe.size(); i < 10; i++) {
		os << -1 << " ";
		os << std::endl;
	}
	os.close();
}

int Equipes::xpDonner() const
{
	int xp = 0;
	for (int i = 0; i < _equipe.size(); i++) {
		xp += _equipe[i]->xpDonner();
	}
	return xp;
}

void Equipes::ajouterPerso(Personnage * P)
{
	P->modifierIndiceEquipe(_equipe.size());
	_equipe.push_back(P);
}

void Equipes::retirerDernierPerso()
{
	_equipe.pop_back();
}

void Equipes::setAllierEtEnnemis(Equipes E) {
	for (int i = 0; i < _equipe.size(); i++) {
		_equipe[i]->setAllier(*this);
		_equipe[i]->setEnnemis(E);
	}
}
bool Equipes::estEnVie()const {
	int j = 0;
	for (int i = 0;i < _equipe.size();i++) {
		if (_equipe[i]->estEnVie()) {
			j++;
		}
	}
	
	return j > 0;
}

bool Equipes::ia()const {
	return _equipeIA;
}
/*
test envie equipe
*/
