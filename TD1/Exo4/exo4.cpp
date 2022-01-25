#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

double randomGenerator() {

	return ((float)(rand())/(RAND_MAX/2)) -1;
}

int main() {
	int nombreIterations, dansCercle = 0;
	double x, y,approxPI,ecartRelatif, pi = 3.141593, erreurRelative;
	srand((unsigned)time(NULL));
	cout << "Entrer le nombre d'itérations souhaités : ";
	cin >> nombreIterations;

	for (int i = 0; i < nombreIterations; i++) {
		x = randomGenerator();
		y = randomGenerator();
		if (sqrt(pow(x, 2) + pow(y, 2) < 1)) {
			dansCercle = dansCercle+1;
		}
	}
	approxPI = (dansCercle/double(nombreIterations))*4;

	ecartRelatif = abs(approxPI-pi);
	erreurRelative = (abs(approxPI - pi) / pi) * 100;
	cout << "Avec " << nombreIterations << " iterations, la valeur approche de PI est  : " << approxPI<<endl;
	cout << "L'erreur relative est de : " << ecartRelatif<<endl;
	cout << "Ce qui represente une erreure relative de : " << erreurRelative << " pourcent ";

}