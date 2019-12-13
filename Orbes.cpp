#include "Orbes.h"

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

