#include <iostream>
#include <stdio.h>
#include <stdbool.h>

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

void SeleSort(int arr[], int lua)
{
    for (int i = 0; i < lua - 1; i++) //indice i va da 0 ad lua-2.
    {
        int min = i; //indice del minimo
        for (int j = i + 1; j < lua; j++) //indice j va da i+1 fino ad n
            if (arr[j] < arr[min]) //il numero indice j � pi� piccolo del min
                min = j; //se vero scambia
        int temp = arr[min]; // ordinamento valori
        arr[min] = arr[i];
        arr[i] = temp;
        Visualizza(arr, lua); //visualizza un passo di ordinamento
        printf("\n\n");
    }
}

int main()
{
    int lua, max,arr[100]; //lunghezza array e massimo numeri
    cout << "Quanti elementi?: ";
    cin >> lua;
    //int arr[lua]; //crea array lunghezza data dall'utente
    cout << "Numeri da 1 a: ";
    cin >> max;
    Riempi(arr, lua, max); //riempi random
    SeleSort(arr, lua);
    printf("\n");

    return 0;
}