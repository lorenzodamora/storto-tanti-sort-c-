#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

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

void InsertSort(int arr[], int lua)
{
	for (int i = 1; i < lua; i++) //indice i parte dal secondo valore
	{
		int temp = arr[i]; //variabile temporale (che si sposterà) per scambio valori
		int j = i - 1; //indice precedente a i
		while ((arr[j] > temp) && (j >= 0)) // ripeti finchè il valore dell'indice j è maggiore di temp e l'indice j>=0.
		{
			arr[j + 1] = arr[j]; //a indice j+1(nella prima iterazione =temp) si mette il valore successivo
			j--; //decremento indice
		}
		arr[j + 1] = temp; //si inserisce valore temporale
		Visualizza(arr, lua);
		printf("\n\n");
	}
}

int main()
{
	int lua, max, arr[100]; //lunghezza array e massimo numeri, array max 100
	cout << "Quanti elementi?: ";
	cin >> lua;
	//arr[lua]; //crea array lunghezza data dall'utente
	cout << "Numeri da 1 a: ";
	cin >> max;
	Riempi(arr, lua, max); //riempi random

	//Ordiniamo l'array
	InsertSort(arr, lua); //ordina
	printf("\n");

	return 0;
}