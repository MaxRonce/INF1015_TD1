#include <iostream>
#include <math.h> /* sqrt */
using namespace std;
bool estPrimaire(int valeur);

int main() {
	while(true) {
		cout << "Entrer un nombre entier : ";
		int x;
		cin >> x;
		if (estPrimaire(x)) {
			cout << "Ce nombre est premier.\n";
		}
		else {
			cout << "Ce nombre n'est pas premier.\n";
		}
	}
	return 0;
}

bool estPrimaire(int valeur) {
	bool estPrimaire = true;
	if (valeur % 2 == 0) {
		estPrimaire = false;
	}
	else {
		for (int i = 3; i <= sqrt(valeur); ++i) {
			if (i % 2 != 0 && valeur % i == 0) {
				estPrimaire = false;
			}
		}
	}
	return estPrimaire;

}

