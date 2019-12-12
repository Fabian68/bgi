#pragma once
#include <fstream>
#include <vector>
class Experiences
{
public:
	Experiences();
	bool ecrireEXP(const std::string & fichier);
	~Experiences();

private:
	std::vector<long long int> _tabXp;
	std::vector<long long int> _ExperiencesPersonnages;
};

