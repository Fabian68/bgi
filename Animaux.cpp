#include "Animaux.h"
#include <iostream>
#include "Bouton.h"

Animaux::Animaux()
{

	FILE* file = fopen("Animaux.txt", "r");
	if (file == NULL) {
		std::ofstream os("Animaux.txt");

		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 9; j++) {
				os << 0 << " ";
			}
			os << -1 << " ";
			os << std::endl;
		}
		os.close();
	}
	else {
		fclose(file);
	}

	_animauxPosseder.resize(25);
	_animauxUtiliser.resize(25);

	for (int i = 0; i < 25; i++) {
		_animauxPosseder[i].resize(9);
	}

	std::ifstream is("Animaux.txt");
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 9; j++) {
			is >> _animauxPosseder[i][j];
		}
		is >> _animauxUtiliser[i];
	}
	is.close();
	_listeAnimaux.resize(10);
	for (int i = 0; i < 10; i++) {
		_listeAnimaux[i] = Animal(i);
	}
}

void Animaux::animalDuPersonnage(int indicePersonnage, int& indiceAnimal, int& rareteAnimal) const
{
	indiceAnimal = _animauxUtiliser[indicePersonnage];
	rareteAnimal = _animauxPosseder[indicePersonnage][indiceAnimal];
}

int Animaux::indiceAnimal(int indicePersonnage)const {
	return _animauxUtiliser[indicePersonnage];
}
int Animaux::rareteAnimal(int indicePersonnage, int indiceAnimal)const {
	if (indiceAnimal == -1) {
		return -1;
	}
	else {
		return _animauxPosseder[indicePersonnage][indiceAnimal];
	}
}

bool Animaux::animalDebloquer(int indicePersonnage, int indiceAnimal, int rareteAnimal) const
{
	return _animauxPosseder[indicePersonnage][indiceAnimal]>=rareteAnimal;
}

void Animaux::deblocageAnimal(int indicePersonnage, int indiceAnimal, int rareteAnimal,std::string perso)
{
	std::string txt= "";
	txt+= perso + " a débloquer un animal ";
	switch (indiceAnimal) {
	case 0:
		txt += " de soins de zone ";
		break;
	case 1:
		txt += " qui soigne le plus faible ";
		break;
	case 2:
		txt += " qui soigne un allier aleatoire ";
		break;
	case 3:
		txt += " qui attaque l'ennemi le plus faible ";
		break;
	case 4:
		txt += " qui attaque l'équipe ennemi ";
		break;
	case 5:
		txt += " qui attaque une cible aleatoire ";
		break;
	case 6:
		txt += " qui bouclier de zone ";
		break;
	case 7:
		txt += " qui bouclier le plus faible ";
		break;
	case 8:
		txt += " qui bouclier une cible aleatoire ";
		break;
	case 9:
		txt += " qui soigne et bouclier de zone ";
		break;
	}
	txt += " de rarete ";
	switch (rareteAnimal) {
	case 1:
		txt += " commune ";
		break;
	case 2:
		txt += " rare ";
		break;
	case 3:
		txt += " epique ";
		break;
	case 4:
		txt += " LEGENDAIRE ";
		break;
	case 5:
		txt += " CHEATER ";
		break;
	}
	/*std::cout << ", voulez voul l'equiper ? Entrer le chiffre 0 si oui ";
	int entrer;
	std::cin >> entrer;
	if (entrer == 0) {
		_animauxUtiliser[indicePersonnage] = indiceAnimal;
	}*/
	Bouton(300, 400, txt, 0, GREEN, GREEN).afficher();
	
	Bouton Equiper(340, 450, " Equiper ", 0, GREEN, GREEN);
	Equiper.afficher();
	Bouton NePasEquiper(440, 450, " NePasEquiper ", 0, GREEN, GREEN);
	NePasEquiper.afficher();

	int xc, yc;
	bool selectionner = false;
	int DELAY = 50;
	do {
		while (!ismouseclick(WM_LBUTTONDOWN)) {
			delay(DELAY);
		}
		getmouseclick(WM_LBUTTONDOWN, xc, yc);
		if (Equiper.comprendLesCoord(xc, yc)) {
			selectionner = true;
			_animauxUtiliser[indicePersonnage] = indiceAnimal;
		}
		else if (NePasEquiper.comprendLesCoord(xc, yc)) {
			selectionner = true;
		}	
	} while (!selectionner);
	cleardevice();
	_animauxPosseder[indicePersonnage][indiceAnimal] = rareteAnimal;
	sauvegarder();
}

void Animaux::sauvegarder()
{
	std::ofstream os("Animaux.txt");

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 9; j++) {
			os << _animauxPosseder[i][j]<<" ";
		}
		os << _animauxUtiliser[i] << " ";
		os << std::endl;
	}
	os.close();
}

Animal Animaux::animalNumero(int indice) const
{
	return _listeAnimaux[indice];
}

void Animaux::setAnimalPersonnage(int indicePersonnage, int indiceAnimal)
{
	_animauxUtiliser[indicePersonnage] = indiceAnimal;
	sauvegarder();
}
