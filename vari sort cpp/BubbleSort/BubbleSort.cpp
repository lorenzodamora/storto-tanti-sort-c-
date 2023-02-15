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

void BubbleSort(int arr[], int lua)
{ 
    for (int j = 0; j < lua - 1; j++)
        for (int i = 0; i < lua - 1; i++) 
            if (arr[i] > arr[i + 1]) //elemento in pos i è maggiore dell’elemento in pos i+1?
            { //Se è vero effettuo lo scambio
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                Visualizza(arr, lua); //visualizza un passo di ordinamento
                printf("\n\n");
            }
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
    BubbleSort(arr, lua);
    printf("\n");

    return 0;
}