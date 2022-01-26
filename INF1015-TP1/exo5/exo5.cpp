#include <iostream>
using namespace std;



int main() {
	int tableauInserer[10] = {};
	int tableauAfficher[10] = {};
	int compteur = 0;
	cout << "Veuillez saisir votre tableau d'entiers\n";
	for (int elem = 0; elem < 10; elem++) {
		cin >> tableauInserer[elem];
	}
	for (int valeur : tableauInserer) {
		if (valeur % 2 == 0) {
			tableauAfficher[compteur] = valeur;
			++compteur;
		}
	}
	for (int valeur : tableauInserer) {
		if (valeur % 2 != 0) {
			tableauAfficher[compteur] = valeur;
			++compteur;
		}
	}
	for (int elem = 0; elem < 10; elem++)
		cout << tableauAfficher[elem];
}
