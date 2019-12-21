#pragma once
class Statistiques
{
public:
	Statistiques();
	void incrementerNbAttaques();
	void incrementerNbAttaquesRecues();
	void ajouterDegatsProvoquer(int montant);
	void ajouterDegatsRecu(int montant);
	void ajouterSoinsDonner(int montant);
	void ajouterBouclierDonner(int montant);

	int nbAttaques()const;
	int nbAttaquesRecues()const;
	int degatsProvoquer()const;
	int degatsRecu()const;
	int soinsDonner()const;
	int bouclierDonner()const;
private:
	int _nbAttaques;
	int _nbAttaquesRecues;
	int _degatsProvoquer;
	int _degatsRecu;
	int _soinsDonner;
	int _bouclierDonner;
};

