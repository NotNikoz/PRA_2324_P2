#include <ostream>
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int* cambio (int N, int* V, int M) {

        //int N : numero de monedas
        //int* V : vector de monedas
        //int M : cantidad a devolver

        int** matrix = new int*[N]; //Se crea la matriz de N filas

        for (int i = 0; i < N ; i++) { //Se crean M + 1 columnas en cada fila
                matrix [i] = new int [M + 1];
        }

        for (int i = 0 ; i < N; i++) { //Se rellena la primera columna de cada fila con 0
                matrix [i] [0] = 0;
        }

        //Comenzamos con los casos bases
        for (int i = 0; i < N ; i++) { //Se recorren todas las filas
                for (int j = 1; j < M + 1 ; j++) { //Recorren todas las columnas

                        if (i == 0 && V [0] > j) { //Comprueba que la primera moneda no sea mayor que la cantidad a devolver
                                int infinito = numeric_limits <int>::max();
                                matrix [i] [j] = infinito;

                        }

                        else if (i == 0 && V [0] <= j) { //Si la primera moneda no es mayor que la cantidad a devolver

                                matrix [i] [j] = 1 + matrix [0] [j - V[0]];
                                //Representa la cantidad mínima para alcanzar la cantidad restante

                        }

                        else if (i > 0 && V [i] > j) {

                                matrix [i] [j] = matrix [i - 1][ j];
                                //Simplemente se usa el valor de la celda en la fila anterior

                        }

                        else {

                                matrix [i] [j] =  min ( matrix [i - 1] [ j], 1 + matrix [i] [j - V[i]]);
                                //Se minimizará la funcon coste del problema
                        }
                }

        }

        //Calculo del vector solucion

        int i = N - 1;
        int j = M;
        int* x = new int [N]; //Se crea un array de enteros
        for (int k = 0; k < N; k++) { //Este array lo inicializamos a 0, teniendo el tamaño del número de monedas que hay
                x[k] = 0;
        }

        while (i > 0 && j > 0) {

                if ( matrix [i] [j] == 1 + matrix [i] [j - V[i]] ) { //Se busca por el valor optimo dentro de la matriz

                        x [i] = x [i] + 1; //Si lo encuentra le sumará 1 a x [i]
                        j = j - V [i]; //Actualizará j restandole la moneda que se ha usado

                } else {

                        i = i - 1; //Si no encuentra el valor optimo restara una moneda menos y pasará a la siguiente

                }

        }

        for (int i = 0; i < N; i++) {
                delete[] matrix[i];
        }

        delete[] matrix;

        return x;


}




int main () {

        int arr [3] = {1,4,6};
        int* solucion = cambio (3, arr, 8);
        cout << "Se necesitarán : " << endl;

        for (int i = 0; i < 3 ; i ++) {

                if (solucion [i] > 0) {

                        cout << solucion [i] << " monedas de " << arr [i] << " euros" << endl;
                }

        }

}
