#include <array>
#include <iostream>

using namespace std;

int main()
{
	int taille= 10, temp;
	array<int, 10> table = {};
	
	for (int i = 0; i < taille; i++) {
		cout << "Entrer un entier : ";
		cin >> table[i];
	}

    for (int i = 0; i < taille; i++)
    {

        if (table[i] % 2 == 0)
        {
            continue;
        }
        // sinon l'élement est impaire
        //check les element suivants
        for (int j = i + 1; j < taille; j++)
        {
            // si l'element suivant est paire
            if (table[j] % 2 == 0)
            {
                // swap 
                temp = table[i];
                table[i] = table[j];
                table[j] = temp;
            }
        }
    }

    for (int i = 0; i < taille; i++) {
        cout << table[i] << " ";
    }

}
