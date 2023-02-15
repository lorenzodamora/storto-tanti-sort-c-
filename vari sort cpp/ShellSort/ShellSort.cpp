#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <ctime>

using namespace std;

void Riempi(int arr[], int lua, int max)
{
    srand(time(0)); //inizializza il seme
    //estraiamo il valore e riempiamo il vettore
    for (int i = 0; i < lua; i++)
        arr[i] = (rand() % max + 1); //valori casuali tra 1 e max
}

void ShellSort(int arr[], int lua)
{
    for (int gap = lua / 2; gap > 0; gap /= 2) // inizia con un grande gap, poi dimezzi
    {
        for (int i = gap; i < lua; i ++) // ciclo sottogruppi | incrementando passa al sottogruppo dopo
        {
            int temp = arr[i];//salvataggio
            int j; //salva indice j
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) // cicla finchè j ( che parte da i) è superiore a gap & finchè elemento precedente dello stesso
                                                                   //sottoinsieme(j-gap) > temp | decrementa del valore gap la j, per confrontare tutto lo stesso sottogruppo
                arr[j] = arr[j - gap]; //ordina coppia nello stesso sottogruppo
            arr[j] = temp; // a fine confronti dello stesso sottogruppo temp va messa nel buco rimasto
        }
        cout << "Passo: " << arr[0]; //visualizza il primo numero
        for (int i = 1; i < lua; i++)
            cout << " | " << arr[i]; //visualizza il resto del vettore
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

    cout << "Vettore non ordinato:" << endl << arr[0]; //visualizza il primo numero
    for (int i = 1; i < lua; i++)
        cout << " | " << arr[i]; //visualizza il resto del vettore
    printf("\n\n");

    ShellSort(arr, lua);

    cout << "Vettore ordinato:" << endl << arr[0]; //visualizza il primo numero
    for (int i = 1; i < lua; i++)
        cout << " | " << arr[i]; //visualizza il resto del vettore
    printf("\n\n");

    return 0;
}