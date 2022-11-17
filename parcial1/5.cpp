#include<iostream>
using namespace std;

/**
 * Sea T[1..n] un arreglo de enteros. Queremos saber si existe un elemento en T, que aparezca al menos ceil(n/2) veces.
 *  Por ejemplo, si T = [1, 3, 2, 4, 3, 5, 3, 3, 1, 3], dicho elemento existe y es 3 (aparece 5/10 veces). 
 * Se desea que diseñe un algoritmo que tome tiempo Θ(n) y use memoria adicional Θ(1) para decidir si existe un 
 * elemento en T con estas condiciones y, de existir, reporte cuál es.
*/

/**
 * ---------- SOLUCION ----------
 * 
 * Este algoritmo es una modificación del algoritmo de Moore (https://www.cs.rug.nl/~wim/pub/whh348.pdf). 
 * Salvo que se toman los ultimos dos candidatos con mayor frecuencia y se verifica si alguno de ellos cumple la condición.
 * Esto es porque para Moore es para un elemento que ocurre mas de n/2 veces, pero en este caso, se pide que sea mayor o igual a n/2.
 * 
 * Argumento de complejidad de espacio:
 * Es θ(1) pues solo se usa memoria adicional para guardar unas variables enteras
 * 
 * Argumento de complejidad de tiempo:
 * Solo se hacen unos ciclos for, y se hace una comparación por cada elemento del arreglo. Por lo tanto, la complejidad es θ(n)
 * 
 * @param T Arreglo de enteros
 * @param n Tamaño del arreglo
*/
int findMajorityElement(int *T, int n){
	if(n == 1) return T[0];

	int count = 0;
	int candidate1 = INT32_MAX; // Dummy value
	int candidate2 = INT32_MAX; // Dummy value

	for(int i = 0; i < n; i++){
		if(candidate1 == T[i]){
			count++;
		} else if(count == 0){
			candidate1 = T[i];
			count = 1;
		} else {
			count--;
			if(count == 0){
				candidate2 = candidate1;
				candidate1 = T[i];
			}
		}
	}

	int count1 = 0;
	int count2 = 0;
	for(int i = 0; i < n; i++){
		if(T[i] == candidate1) count1++;
		if(T[i] == candidate2) count2++;
	}
	
	if(count1*2 >= n) return candidate1;
	if(count2*2 >= n) return candidate2;

	// No existe
	return -1;
}

int main(){
	int T[] = {1, 3, 2, 4, 3, 5, 3, 3, 1, 3};
	int n = 10;
	cout << findMajorityElement(T, n) << "\n";
}