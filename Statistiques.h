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

	void ajouterAugmentationVieMax(int montant);
	void ajouterAugmentationReduction(int montant);
	void ajouterAugmentationChanceDoubleAttaque(int montant);
	void ajouterAugmentationChanceHabileter(int montant);
	void ajouterAugmentationCoupCritiques(int montant);
	void ajouterAugmentationDegatsCritique(int montant);
	void ajouterAugmentationForce(int montant);

	int nbAttaques()const;
	int nbAttaquesRecues()const;
	int degatsProvoquer()const;
	int degatsRecu()const;
	int soinsDonner()const;
	int bouclierDonner()const;

	int augmentationVieMax()const;
	int augmentationReduction()const;
	int augmentationChanceDoubleAttaque()const;
	int augmentationChanceHabileter()const;
	int augmentationCoupCritiques()const;
	int augmentationDegatsCritique()const;
	int augmentationForce()const;

private:
	int _nbAttaques;
	int _nbAttaquesRecues;
	int _degatsProvoquer;
	int _degatsRecu;
	int _soinsDonner;
	int _bouclierDonner;

	int _augmentationVieMax;
	int _augmentationReduction;
	int _augmentationChanceDoubleAttaque;
	int _augmentationChanceHabileter;
	int _augmentationCoupCritiques;
	int _augmentationDegatsCritique;
	int _augmentationForce;
};

