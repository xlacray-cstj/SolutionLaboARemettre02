// But : Cr�er un programme qui calcule le montant d� de location de voiture en fonction du kilom�trage et de la dur�e du voyage
// Auteur : Xavier Lacroix-Raymond
// Date : 2020-09-14

#include <iostream> // Biblioth�que cin cout

int main()
{
	setlocale(LC_ALL, "");

	// D�claration des variables
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
	
	// Messages pour l'utilisateur afin de r�colter les informations n�cessaires
	std::cout << "Veuillez entrer votre nombre de kilom�tres parcourus: ";
	std::cin >> kmParcouru;

	std::cout << "Veuillez entrer la dur�e de votre voyage: ";
	std::cin >> nbJours;

	// Calcul du nombre de kilom�tres gratuits
	kmGratuits = 250 * nbJours;

	// Calcul du co�t de la location de la voiture
	coutVoiture = 45 * nbJours;

	// Calcul du co�t de l'essence
	factureEssence = coutEssence * (consommation * kmParcouru);

	// Calcul des kilom�tres suppl�mentaires
	kmPayants = (kmParcouru - kmGratuits) * 0.05;

	// Condition pour s'assurer que l'utilisateur ne rentre pas de valeurs invalides qui causeraient des bugs
	if (kmParcouru < 1 || nbJours < 1)
	{
		kmPayants = 0;
		std::cout << "\n" << "Les valeurs entr�es ne sont pas valides" << "\n";
	}
	// Condition pour v�rifier si l'utilisateur a utilis� tous ses kilom�tres gratuits
	// Si oui
	else if (kmParcouru > kmGratuits)
	{
		// Affichage des co�ts
		std::cout << "\n" << "Vous avez d�pass� votre nombre de kilom�tres gratuits. Sachant que nous facturons 0.05$ par kilom�tres suppl�mentaires, nous vous facturons " << kmPayants << " $" << "\n";
		std::cout << "\n" << "Co�t des kilom�tres suppl�mentaires: " << kmPayants << " $" << "\n";
		std::cout << "Co�t du carburant: " << factureEssence << " $" << "\n";
		std::cout << "Co�t de location: " << coutVoiture << " $" << "\n";

		// Calcul du total
		total = coutVoiture + kmPayants + factureEssence;

		// Affichage du total
		std::cout << "\n" << "Co�t total: " << total << " $" << "\n";
	}
	// Sinon
	else
	{
		kmPayants = 0;

		// Affichage des co�ts
		std::cout << "\n" << "Co�t du carburant: " << factureEssence << " $" << "\n";
		std::cout << "Co�t de location: " << coutVoiture << " $" << "\n";

		// Calcul du total
		total = coutVoiture + kmPayants + factureEssence;

		// Affichage du total
		std::cout << "\n" << "Co�t total: " << total << " $" << "\n";
	}
	return 0;
}

//----------PLAN DE TEST----------
/*
	kmParcouru				nbJours				kmPayants			factureEssence			coutVoiture			total
		100					  2						0					9.5 $					90 $			 99.5 $	
		0					  0							Les valeurs entr�es ne sont pas valides
	   -500				     -5							Les valeurs entr�es ne sont pas valides
	   aaaa												Les valeurs entr�es ne sont pas valides
	   5000					  7					   162 $			    475 $					315 $			 952 $
	   250					  1						0				    23.75 $					45 $			 68.75 $
	   1					  0							Les valeurs entr�es ne sont pas valides
	   0					  1							Les valeurs entr�es ne sont pas valides
	  -5					  0							Les valeurs entr�es ne sont pas valides
	   0					 -56						Les valeurs entr�es ne sont pas valides
*/