#include <iostream>
using namespace std;

double entreeValeur(double borneInf, double borneSup, string message);



int main() {
	double somme = entreeValeur(0, INFINITY, "Veuillez inserer une somme pretee positive :\n");
	double montantMensuel = entreeValeur(0, INFINITY, "Veuillez inserer un montant mensuel rembourse positif :\n");
	double tauxAnnuel = entreeValeur(0, 100, "Veuillez inserer un taux d'interet annuel positif inferieur a 100 :\n") / 100;
	double tauxMensuel = tauxAnnuel/ 12;
	int mois = 0; double interets = 0;
	while (somme > 0) {
		interets += somme * tauxMensuel;
		somme += somme * tauxMensuel - montantMensuel;
		++mois;
	}
	cout << "le nombre de mois est :\n" << mois << endl;
	cout << "la somme des interets est:\n " << interets;
}


double entreeValeur(double borneInf, double borneSup, string message) {
	double valeur;
	do {
		cout << message;
		cin >> valeur;
	} while (!(valeur > borneInf || valeur <= borneSup));
	return valeur;
}