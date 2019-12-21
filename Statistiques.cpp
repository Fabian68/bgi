#include "Statistiques.h"

Statistiques::Statistiques() : _nbAttaques{0},_nbAttaquesRecues{0},_degatsProvoquer{0},_degatsRecu{0},_soinsDonner{0},_bouclierDonner{0}
{
}

void Statistiques::incrementerNbAttaques()
{
	_nbAttaques++;
}

void Statistiques::incrementerNbAttaquesRecues()
{
	_nbAttaquesRecues++;
}

void Statistiques::ajouterDegatsProvoquer(int montant)
{
	_degatsProvoquer += montant;
}

void Statistiques::ajouterDegatsRecu(int montant)
{
	_degatsRecu += montant;
}

void Statistiques::ajouterSoinsDonner(int montant)
{
	_soinsDonner += montant;
}

void Statistiques::ajouterBouclierDonner(int montant)
{
	_bouclierDonner += montant;
}

int Statistiques::nbAttaques() const
{
	return _nbAttaques;
}

int Statistiques::nbAttaquesRecues() const
{
	return _nbAttaquesRecues;
}

int Statistiques::degatsProvoquer() const
{
	return _degatsProvoquer;
}

int Statistiques::degatsRecu() const
{
	return _degatsRecu;
}

int Statistiques::soinsDonner() const
{
	return _soinsDonner;
}

int Statistiques::bouclierDonner() const
{
	return _bouclierDonner;
}
