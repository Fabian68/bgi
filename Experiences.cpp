#include "Experiences.h"



Experiences::Experiences()
{
	FILE *file = fopen("T1.txt", "r");
	if (file == NULL) {
		std::ofstream os("T1.txt");
		for (int i = 0;i < 50;i++) {
			os << 1 << std::endl;
		}
		os.close();
	}
	std::ifstream is("T1.txt");

	int i = 0;
	// lecture tantque possible
	while (!is.eof())
	{
		_ExperiencesPersonnages.resize(51);
		is >> _ExperiencesPersonnages[i];
		i++;
	}
	is.close();

	std::ofstream os("Exp.txt");
	long long int UnEntierTresTresLong;
	_tabXp.resize(10000);
	for (long long int i = 0;i < 10000;i++) {


		UnEntierTresTresLong = static_cast<long long int>(100 * pow(1.0024, i) - 100 + 3 * i*i);
		os << UnEntierTresTresLong << std::endl;
		_tabXp[i] = UnEntierTresTresLong;
	}

	os.close();
}

bool Experiences::ecrireEXP(const std::string& fichier)
{
	std::ofstream os(fichier);

	int i = 0;
	// lecture tantque possible
	while (i != 50)
	{
		os << _ExperiencesPersonnages[i] << std::endl;
		i++;
	}
	os.close();
	return true;
}

Experiences::~Experiences()
{
}

int Experiences::calculNiveau(int indiceTabxp) const
{
	int niv = 1;
	int xp = _ExperiencesPersonnages[indiceTabxp];
	int i = 0;
	while (xp > _tabXp[i]) {
		i++;
	}
	return i;
}

void Experiences::ajouterXP(int indiceTabxp,int montant) {
	_ExperiencesPersonnages[indiceTabxp] += montant;
}
