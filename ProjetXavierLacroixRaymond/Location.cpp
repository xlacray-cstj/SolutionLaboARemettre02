// But : Créer un programme qui calcule le montant dû de location de voiture en fonction du kilométrage et de la durée du voyage
// Auteur : Xavier Lacroix-Raymond
// Date : 2020-09-14

#include <iostream> // Bibliothèque cin cout

int main()
{
	setlocale(LC_ALL, "");

	// Déclaration des variables
	float consommation = 7.6 / 100;
	float coutEssence = 1.25;
	float kmSupp = 0.05;
	int nbJours;
	int kmGratuits;
	int kmParcouru;
	int coutVoiture;
	int kmPayants;
	float factureEssence;
	float total;
	
	// Messages pour l'utilisateur afin de récolter les informations nécessaires
	std::cout << "Veuillez entrer votre nombre de kilomètres parcourus: ";
	std::cin >> kmParcouru;

	std::cout << "Veuillez entrer la durée de votre voyage: ";
	std::cin >> nbJours;

	// Calcul du nombre de kilomètres gratuits
	kmGratuits = 250 * nbJours;

	// Calcul du coût de la location de la voiture
	coutVoiture = 45 * nbJours;

	// Calcul du coût de l'essence
	factureEssence = coutEssence * (consommation * kmParcouru);

	// Calcul des kilomètres supplémentaires
	kmPayants = (kmParcouru - kmGratuits) * 0.05;

	// Condition pour s'assurer que l'utilisateur ne rentre pas de valeurs invalides qui causeraient des bugs
	if (kmParcouru < 1 || nbJours < 1)
	{
		kmPayants = 0;
		std::cout << "\n" << "Les valeurs entrées ne sont pas valides" << "\n";
	}
	// Condition pour vérifier si l'utilisateur a utilisé tous ses kilomètres gratuits
	// Si oui
	else if (kmParcouru > kmGratuits)
	{
		// Affichage des coûts
		std::cout << "\n" << "Vous avez dépassé votre nombre de kilomètres gratuits. Sachant que nous facturons 0.05$ par kilomètres supplémentaires, nous vous facturons " << kmPayants << " $" << "\n";
		std::cout << "\n" << "Coût des kilomètres supplémentaires: " << kmPayants << " $" << "\n";
		std::cout << "Coût du carburant: " << factureEssence << " $" << "\n";
		std::cout << "Coût de location: " << coutVoiture << " $" << "\n";

		// Calcul du total
		total = coutVoiture + kmPayants + factureEssence;

		// Affichage du total
		std::cout << "\n" << "Coût total: " << total << " $" << "\n";
	}
	// Sinon
	else
	{
		kmPayants = 0;

		// Affichage des coûts
		std::cout << "\n" << "Coût du carburant: " << factureEssence << " $" << "\n";
		std::cout << "Coût de location: " << coutVoiture << " $" << "\n";

		// Calcul du total
		total = coutVoiture + kmPayants + factureEssence;

		// Affichage du total
		std::cout << "\n" << "Coût total: " << total << " $" << "\n";
	}
	return 0;
}

//----------PLAN DE TEST----------
/*
	kmParcouru				nbJours				kmPayants			factureEssence			coutVoiture			total
		100					  2						0					9.5 $					90 $			 99.5 $	
		0					  0							Les valeurs entrées ne sont pas valides
	   -500				     -5							Les valeurs entrées ne sont pas valides
	   aaaa												Les valeurs entrées ne sont pas valides
	   5000					  7					   162 $			    475 $					315 $			 952 $
	   250					  1						0				    23.75 $					45 $			 68.75 $
	   1					  0							Les valeurs entrées ne sont pas valides
	   0					  1							Les valeurs entrées ne sont pas valides
	  -5					  0							Les valeurs entrées ne sont pas valides
	   0					 -56						Les valeurs entrées ne sont pas valides
*/