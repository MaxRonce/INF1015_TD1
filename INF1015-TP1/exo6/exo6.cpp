#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Dictionnaire {
	string mot;
	string nature;
	string definition;
};



int main() {
	string plusLongMot = "a";
	ifstream myfile;
	Dictionnaire dictionnaire[4];
	myfile.open("dictionnaire.txt");
	for (int i = 0; i < 4; i++) {
		getline(myfile, dictionnaire[i].mot, '\t');
		getline(myfile, dictionnaire[i].nature, '\t');
		getline(myfile, dictionnaire[i].definition, '\n');
		if (size(plusLongMot) < size(dictionnaire[i].mot)) {
			plusLongMot = dictionnaire[i].mot;
		}
	}
	cout << plusLongMot;

	myfile.close();
}
