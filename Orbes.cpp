#include "Orbes.h"
#include <iostream>

Orbes::Orbes()
{
	FILE* file = fopen("Orbes.txt", "r");
	if (file == NULL) {
		std::ofstream os("Orbes.txt");
		
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 5; j++) {
				os << 0 << " ";
			}
			for (int j = 0; j < 5; j++) {
				os << 1 << " ";
			}
			os << std::endl;
		}
		os.close();
	}

	_orbesLVL.resize(25);
	_choixOrbes.resize(25);
	for (int i = 0; i < 25; i++) {
			_orbesLVL[i].resize(5);
			_choixOrbes[i].resize(5);
	}	
	
	std::ifstream is("Orbes.txt");
	for(int i=0;i<25;i++){
		for (int j = 0; j < 5; j++) {
			is >> _orbesLVL[i][j];
		}
		for (int j = 0; j < 5; j++) {
			is >> _choixOrbes[i][j];
		}
	}
	is.close();	
}

void Orbes::sauvegarder()
{
	std::ofstream os("Orbes.txt");

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 5; j++) {
			os << _orbesLVL[i][j] << " ";
		}
		for (int j = 0; j < 5; j++) {
			os << _choixOrbes[i][j] << " ";
		}
		os << std::endl;
	}
	os.close();
}

void Orbes::buffOrbes(int indiceJoueur, int& attaqueLvlBonus, int& vieLvLBonus, int& vitesseLvlBonus) const
{
	attaqueLvlBonus = 0;
	vieLvLBonus = 0;
	vitesseLvlBonus = 0;
	for (int i = 0; i < 5; i++) {
		switch (_choixOrbes[indiceJoueur][i]) {
		case 1:
			attaqueLvlBonus += (i + 1) * _orbesLVL[indiceJoueur][i];
			break;
		case 2:
			vieLvLBonus += (i + 1) * _orbesLVL[indiceJoueur][i];
			break;
		case 3:
			vitesseLvlBonus += (i + 1) * _orbesLVL[indiceJoueur][i];
			break;
		}
	}
}

bool Orbes::orbeDebloquer(int indiceJoueur, int rareter) const
{
	return _orbesLVL[indiceJoueur][rareter-1] != 0;
}

void Orbes::deblocageOrbe(int indiceJoueur, int rareter, std::string perso)
{
	std::cout <<perso<< " a débloquer une orbe ";
	std::cout << " de rarete ";
	switch (rareter) {
	case 1:
		std::cout << " commune ( 1 ";
		break;
	case 2:
		std::cout << " rare ( 2 ";
		break;
	case 3:
		std::cout << " epique ( 3 ";
		break;
	case 4:
		std::cout << " LEGENDAIRE ( 4 ";
		break;
	case 5:
		std::cout << " CHEATER ( 5 ";
		break;
	}
	std::cout << "points de stats par niveaux) ,vous dever choisir ou l'equiper, entrer ";
	std::cout << std::endl;
	std::cout << " 1 pour attaque ";
	std::cout << std::endl;
	std::cout << " 2 pour vie ";
	std::cout << std::endl;
	std::cout << " 3 pour vitesse ";
	std::cout << std::endl;
	int entrer;
	std::cin >> entrer;
	if (entrer < 1 || entrer >3) {
		entrer = 1;
	}
	_orbesLVL[indiceJoueur][rareter - 1] = 1;
	_choixOrbes[indiceJoueur][rareter - 1] = entrer;

	sauvegarder();
}

