#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

void Riempi(int arr[], int lua, int max)
{
	//estraiamo il valore e riempiamo il vettore
	for (int i = 0; i < lua; i++)
		arr[i] = (rand() % max + 1); //valori casuali tra 1 e max
}

void Visualizza(int arr[], int lug) //lunghezza generica
{
	cout << arr[0]; //visualizza il primo numero
	for (int i = 1; i < lug; i++) // ciclo che scorre gli elementi del vettore
		cout << " | " << arr[i]; //visualizza il resto dei valori
	printf("\n");
}

void Merge(int arr[], int lef, int mid, int rig) //left mid right
{
	int n1 = mid - lef + 1; // calcola la lunghezza del primo sotto-vettore
	int n2 = rig - mid;     // calcola la lunghezza del secondo sotto-vettore

	//int L[n1], R[n2];
	int an1[51], an2[51]; //sotto array 1 e 2
	for (int i = 0; i < n1; i++) // copia i valori del primo sotto-vettore nel vettore temporaneo 1
		an1[i] = arr[lef + i];
	for (int j = 0; j < n2; j++) // copia i valori del secondo sotto-vettori nel vettore temporaneo 2
		an2[j] = arr[mid + 1 + j];

	cout << "Sottovettore sinistro: ";
	Visualizza(an1, n1);
	cout << "Sottovettore destro: ";
	Visualizza(an2, n2);

	int i = 0, j = 0, k = lef; //indici vettore sinistro vettore destro e vettore finale

	while (i < n1 && j < n2) //cicla fino a quando non arriva al limite array
	{
		if (an1[i] <= an2[j]) // confronta gli elementi dei due sotto-vettori e inserisce i valori nel vettore originale
		{
			arr[k] = an1[i];
			i++;
		}
		else
		{
			arr[k] = an2[j];
			j++;
		}
		k++;
	}

	while (i < n1) // copia i valori rimanenti di L nel vettore originale
	{
		arr[k] = an1[i];
		i++;
		k++;
	}

	while (j < n2) // copia i valori rimanenti di R nel vettore originale
	{
		arr[k] = an2[j];
		j++;
		k++;
	}
}

void MergeSort(int vet[], int begin, int end)
{
	//chiamate ricorsive
	if (begin >= end)
		return;
	//else
	int mid = begin + (end - begin) / 2;	// Trova la posizione centrale del vettore
	MergeSort(vet, begin, mid);			// Chiamata ricorsiva a sinistra
	MergeSort(vet, mid + 1, end);			// Chiamata ricorsiva a destra
	Merge(vet, begin, mid, end);			// Chiamata ordinamento vettore
	cout << "Sotto-vettore corrente: ";
	Visualizza(vet + begin, end - begin + 1);
}


int main()
{
	srand(time(NULL)); // seed per la generazione di numeri casuali

	int lua, max, arr[100]; //lunghezza array e massimo numeri
	cout << "Quanti elementi?: ";
	cin >> lua;
	//int arr[lua]; //crea array lunghezza data dall'utente
	cout << "Numeri da 1 a: ";
	cin >> max;

	Riempi(arr, lua, max); //riempi random

	cout << "Vettore originale:";
	Visualizza(arr, lua);

	MergeSort(arr, 0, lua - 1);

	cout << "Vettore ordinato: ";
	Visualizza(arr, lua);
	printf("\n\n");

	return 0;
}