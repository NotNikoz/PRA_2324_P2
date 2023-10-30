#include <ostream>
#include <iostream>
#include <algorithm>
using namespace std;

int* mochila (int N, int* P, int* b, int M) {

	// N = Número de objetos
	// P = vector de pesos
	// b = vector de beneficios
	// M = Peso máximo
	
	//Se comenzará creando una matriz de (N, M)
	
	int** matrix = new int* [N]; //Se crea un array que serán las filas
	
	for (int i = 0 ; i < N ; i ++) { //Se crean M + 1 columnas

		matrix [i] = new int [M + 1];

	}

	for (int i = 0 ; i < N; i++) { //Se rellena la primera columna de cada fila con 0
                matrix [i] [0] = 0;
        }

	//Se recorren todas las filas y columnas para los casos base
	
	for (int i = 0 ; i < N ; i ++) {
		
		for (int j = 1 ; j < M + 1 ; j ++) {

			if ( i == 0 && P [i] > j ) {
				
				matrix [i] [j] = 0;

			} else if (i == 0) {

				matrix [i] [j] = b [i];

			} else if (i > 0 && P [i] > j) {

				matrix [i] [j] = matrix [i - 1] [j];

			} else {

				matrix [i] [j] = max ( matrix [i - 1] [j] , b[i] + matrix [i - 1] [j - P [i]] );

			}

		}

	}


	//Calculo del vector solucion

        int i = N - 1 ;
        int j = M;
        int* x = new int [N]; //Se crea un array de enteros
        for (int k = 0; k < N; k++) { //Este array lo inicializamos a 0, teniendo el tamaño del número de objetos que hay
                x[k] = 0;
        }

        while (i > 0 && j > 0) {

                if ( i == 1 && matrix [i] [j] == b [i] ) { 

                        x [i] = x [i] + 1 ; //Si lo encuentra le sumará 1 a x [i]

                } else if ( matrix [i] [j] == ( b [i] + matrix [i - 1] [j - P [i]] )) {

			x [i] = x [i] + 1;
			j = j - P [i];

		} 
			
			i = i - 1;

	}
			


        for (int i = 0; i < N; i++) {
                delete[] matrix[i];
        }

        delete[] matrix;

        return x;

}

int main () {

        int arr [5] = {1,2,5,6,7};
	int arr1 [5] = {1,6,18,22,28};
        int* solucion = mochila (5, arr, arr1, 11);
        cout << "Se necesitarán : " << endl;

        for (int i = 0; i < 5 ; i ++) {

                        cout << solucion [i];

        }

	cout << endl;

}
