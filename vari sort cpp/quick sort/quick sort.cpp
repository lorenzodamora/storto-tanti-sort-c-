#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <array>

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
    printf("\n\n");
}

int partizione(int arr[], int sta, int end) //inizio fine
{
    //int pivot = arr[end]; //ultimo elemento = pivot
    int i = sta - 1; //indice i valore iniziale 

    for (int j = sta; j < end ; j++) // cicla tutti gli elementi del sottovettore da inizio a fine
    {
        if (arr[j] <= arr[end]) // Se l'elemento corrente <= pivot
        {
            i++; // Incrementa i
            int temp = arr[i]; // scambia valori
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1]; // scambia pivot con l'elemento indice i + 1
    arr[i + 1] = arr[end];
    arr[end] = temp;
    cout << "pivot: " << arr[end] << endl;
    return (i + 1); // Restituisce l'indice del pivot
}
void QuickSort(int arr[], int sta, int end) //inizio fine
{
    if (sta >= end) // se in sta < ebd
        return; //chiamate ricorsive

    int pip = partizione(arr, sta, end); // partizione indice pivot = Chiamata partizione per sort + avere indice pivot 
    QuickSort(arr, sta, pip - 1); // Chiamata ricorsiva sulla prima metà del sottovettore
    QuickSort(arr, pip + 1, end); // Chiamata ricorsiva sulla seconda metà del sottovettore
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

    QuickSort(arr, 0, lua - 1);

    cout << "\nVettore ordinato: ";
    Visualizza(arr, lua);
    printf("\n");

    return 0;
}



array<int, 100> QuickSort1(int arr[], int lei, int rii) //array, leftIndex rightIndex
{
    int i = lei;
    int j = rii;
    int pivot = arr[lei];
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (lei < j)
        QuickSort1(arr, lei, j);
    if (i < rii)
        QuickSort1(arr, i, rii);

    array<int, 100> arf;
    for (int i = 0; i < 100; i++)
        arf[i] = arr[i];
    return arf;
}