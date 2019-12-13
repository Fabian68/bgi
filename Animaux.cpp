#include "Animaux.h"

Animaux::Animaux()
{

	FILE* file = fopen("Animaux.txt", "r");
	if (file == NULL) {
		std::ofstream os("Animaux.txt");

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 5; j++) {
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
		_animauxPosseder[i].resize(10);
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
