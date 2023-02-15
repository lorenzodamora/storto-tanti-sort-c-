#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <array>

using namespace std;

void Riempi(int arr[], int lug, int max) //lunghezza array generico
{
    //estraiamo il valore e riempiamo il vettore
    for (int i = 0; i < lug; i++)
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

    for (int j = sta; j < end; j++) // cicla tutti gli elementi del sottovettore da inizio a fine
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
    if (sta >= end) // se in sta < end
        return; //chiamate ricorsive

    int pip = partizione(arr, sta, end); // partizione indice pivot = Chiamata partizione per sort + avere indice pivot 
    QuickSort(arr, sta, pip - 1); // Chiamata ricorsiva sulla prima metà del sottovettore
    QuickSort(arr, pip + 1, end); // Chiamata ricorsiva sulla seconda metà del sottovettore
}

void fusione(int arr[], int brr[], int lua, int lub, int crr[])
{
    int i = 0, j = 0, k = 0;  // Inizializziamo i contatori per gli array a, b e c
    while (i < lua && j < lub) // Uniamo gli elementi degli array a e b in c
        if (arr[i] < brr[j])
            crr[k++] = arr[i++]; // lo inseriamo in c[k] e incrementiamo i
        else
            crr[k++] = brr[j++]; // Altrimenti, inseriamo b[j] in c[k] e incrementiamo j
    while (i < lua) // Aggiungiamo gli eventuali elementi rimanenti di a in c
        crr[k++] = arr[i++];
    while (j < lub)  // Aggiungiamo gli eventuali elementi rimanenti di b in c
        crr[k++] = brr[j++];
}

int main()
{
    srand(time(NULL)); // seed per la generazione di numeri casuali

    int lua, lub, max, arr[100], brr[100]; //lungezza array a e b

    cout << "Inserisci la dimensione del primo vettore: ";
    cin >> lua;
    cout << "Numeri da 1 a: ";
    cin >> max;
    Riempi(arr, lua, max);

    cout << "Primo vettore non ordinato: ";
    Visualizza(arr, lua);

    QuickSort(arr, 0, lua - 1);

    cout << "Primo vettore ordinato: ";
    Visualizza(arr, lua);

    cout << "Inserisci la dimensione del secondo vettore: ";
    cin >> lub;
    cout << "Numeri da 1 a: ";
    cin >> max;
    Riempi(brr, lub, max);
    cout << "Secondo vettore non ordinato: ";
    Visualizza(brr, lub);

    QuickSort(brr, 0, lub - 1);

    cout << "Secondo vettore ordinato: ";
    Visualizza(brr, lub);

    int crr[200]; //array c | finale

    fusione(arr, brr, lua, lub, crr);

    cout << "Il vettore finale è: ";
    Visualizza(crr, lua + lub);

    return 0;
}