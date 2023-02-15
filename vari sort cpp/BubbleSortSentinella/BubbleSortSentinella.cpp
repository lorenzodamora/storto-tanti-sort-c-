#include <iostream>
#include <stdbool.h>
#include <stdio.h>

using namespace std;

void Riempi(int arr[], int lua, int max)
{
    srand((unsigned)time(NULL)); //inizializza il seme
    //estraiamo il valore e riempiamo il vettore
    for (int i = 0; i < lua; i++)
        arr[i] = (rand() % max + 1); //valori casuali tra 1 e max
}

void Visualizza(int arr[], int lua)
{
    cout << arr[0]; //visualizza il primo numero
    for (int i = 1; i < lua; i++)
        cout << " | " << arr[i]; //visualizza il resto del vettore
}

void BubbleSortOttimizzato(int arr[], int lua)
{
	bool sen; //sentinella, controllo scambio
	do {
		sen = false; //non ha ancora scambiato
		for (int i = 0; i < lua - 1; i++) //per tutto array
			if (arr[i] > arr[i + 1]) //se elemento i è maggiore di elemento i+1
			{//fai scambi
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				sen = true; //flag 'ha scambiato'

                Visualizza(arr, lua); //visualizza un passo di ordinamento
                printf("\n\n");
			}
	} while (sen == true);
}

int main()
{
    int lua, max, arr[100]; //lunghezza array e massimo numeri
    cout << "Quanti elementi?: ";
    cin >> lua;
    //int arr[lua]; //crea array lunghezza data dall'utente
    cout << "Numeri da 1 a: ";
    cin >> max;
    Riempi(arr, lua, max); //riempi random
    BubbleSortOttimizzato(arr, lua);
    printf("\n");

    return 0;
}