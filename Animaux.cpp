#include "Animaux.h"
#include <iostream>

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
	std::cout <<perso<< " a débloquer un animal ";
	switch (indiceAnimal) {
	case 0:
		std::cout << " de soins de zone ";
		break;
	case 1:
		std::cout << " qui soigne le plus faible ";
		break;
	case 2:
		std::cout << " qui soigne un allier aleatoire ";
		break;
	case 3:
		std::cout << " qui attaque l'ennemi le plus faible ";
		break;
	case 4:
		std::cout << " qui attaque l'équipe ennemi ";
		break;
	case 5:
		std::cout << " qui attaque une cible aleatoire ";
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	}
	std::cout << " de rarete ";
	switch (rareteAnimal) {
	case 1:
		std::cout << " commune ";
		break;
	case 2:
		std::cout << " rare ";
		break;
	case 3:
		std::cout << " epique ";
		break;
	case 4:
		std::cout << " LEGENDAIRE ";
		break;
	case 5:
		std::cout << " CHEATER ";
		break;
	}
	std::cout << ", voulez voul l'equiper ? Entrer le chiffre 0 si oui ";
	int entrer;
	std::cin >> entrer;
	if (entrer == 0) {
		_animauxUtiliser[indicePersonnage] = indiceAnimal;
	}
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
