#pragma once
class Personnage;
#include <vector>

const int BRULURE = 0;
const int EMPOISONNER = 1;
const int COMPTEURFRAGILISER = 2;
const int COMPTEURPROTEGER = 3;
class Status
{
	public:
		Status();
		Status(Personnage* P);
		bool estBruler()const;
		bool estEmpoisoner()const;
		bool estFragiliser()const;
		bool estProteger()const;

		void appliquerBrulure();
		void appliquerPoison();
		void ajouterCompteurFragile(int nb);
		void ajouterCompteurProteger(int nb);

		void decrementerCompteur();

		void effetBrulure();
		void soignerBrulure();
		void soignerPoison();
		void effetPoison();
	private:
		Personnage* _perso;
		std::vector<int> _status;
};

