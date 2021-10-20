#include <iostream>
#include <vector>
#include <time.h>
#include <string.h>
#include <locale.h>

using namespace std;



void showIteration(std::vector<int> &arreglo) {
    for ( int i = 0; i < arreglo.size(); i++ ) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

void merge(std::vector<int> &arreglo, int inicio, int mitad, int final) {
    int i, j, k;
    int elementosIzq = mitad - inicio + 1;
    int elementosDer = final - mitad;

    std::vector<int> izquierda(elementosIzq);
    std::vector<int> derecha (elementosDer);

    for ( int i = 0; i < elementosIzq; i++ ) {
        izquierda[i] = arreglo[inicio+i];
    }
    for ( int j = 0; j < elementosDer; j++ ) {
        derecha[j] = arreglo[mitad + 1 + j];
    }

    i = 0; j = 0; k = inicio;

    while ( i < elementosIzq && j < elementosDer ) {
        if ( izquierda[i] <= derecha[j] ) {
            arreglo[k] = izquierda[i];
            i++;
        }
        else {
            arreglo[k] = derecha[j];
            j++;
        }
        k++;
    }

    while ( j < elementosDer ) {
        arreglo[k] = derecha[j];
        j++; k++;
    }
    while ( i < elementosIzq ) {
        arreglo[k] = izquierda[i];
        i++; k++;
    }

}

void mergeSort(std::vector<int> &arreglo, int inicio, int final) {
    if ( inicio < final ) {
        int mitad = inicio+(final-inicio)/2;
        mergeSort(arreglo, inicio, mitad);
        mergeSort(arreglo, mitad+1, final);
        merge(arreglo, inicio, mitad, final);
    }
}

int main() {
    // Admición de caracteres especiales
    setlocale(LC_CTYPE, "Spanish");
    srand(time(NULL));

    cout << "Merge Sort" << endl;
    cout << "García Martínez Braulio Israel 220331615" << endl;

    /** Definici�n de la longitud del vector */
    int noe;
    do{
        cout << "Ingrese la cantidad de datos que desea ordenar: ";
        cin >> noe;

        if( (noe < 2) || (noe >100) ){
            cout << "La cantidad m�nima de elementos a ordenar son 2 y la cantidad m�xima son 100" << endl;
        }
    }while( (noe < 2) || (noe > 100) );

    /** Ingreso de datos al vector */
    std::vector<int> items(noe);
    for( int i = 0; i < items.size(); i++ ){
        items[i] = rand() % 10 + 1;
    }

    showIteration(items);
    mergeSort(items, 0, items.size()-1);
    showIteration(items);

    return 0;
}
