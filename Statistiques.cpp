#include "Statistiques.h"

Statistiques::Statistiques() : _nbAttaques{0},_nbAttaquesRecues{0},_degatsProvoquer{0},_degatsRecu{0},_soinsDonner{0},_bouclierDonner{0},_augmentationVieMax{0},_augmentationReduction{0},_augmentationDegatsCritique{0},
_augmentationCoupCritiques{0},_augmentationChanceHabileter{0},_augmentationChanceDoubleAttaque{0},_augmentationForce{0}
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

void Statistiques::ajouterAugmentationVieMax(int montant)
{
	_augmentationVieMax += montant;
}

void Statistiques::ajouterAugmentationReduction(int montant)
{
	_augmentationReduction += montant;
}

void Statistiques::ajouterAugmentationChanceDoubleAttaque(int montant)
{
	_augmentationChanceDoubleAttaque += montant;
}

void Statistiques::ajouterAugmentationChanceHabileter(int montant)
{
	_augmentationChanceHabileter += montant;
}

void Statistiques::ajouterAugmentationCoupCritiques(int montant)
{
	_augmentationCoupCritiques += montant;
}

void Statistiques::ajouterAugmentationDegatsCritique(int montant)
{
	_augmentationDegatsCritique += montant;
}

void Statistiques::ajouterAugmentationForce(int montant)
{
	_augmentationForce +=  montant;
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

int Statistiques::augmentationVieMax() const
{
	return _augmentationVieMax;
}

int Statistiques::augmentationReduction() const
{
	return _augmentationReduction;
}

int Statistiques::augmentationChanceDoubleAttaque() const
{
	return _augmentationChanceDoubleAttaque;
}

int Statistiques::augmentationChanceHabileter() const
{
	return _augmentationChanceHabileter;
}

int Statistiques::augmentationCoupCritiques() const
{
	return _augmentationCoupCritiques;
}

int Statistiques::augmentationDegatsCritique() const
{
	return _augmentationDegatsCritique;
}

int Statistiques::augmentationForce() const
{
	return _augmentationForce;
}
