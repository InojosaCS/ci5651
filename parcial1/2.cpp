#include<iostream>
using namespace std;

/*
Sea T[1..n] un arreglo de enteros sin elementos repetidos, ordenado de menor a mayor. Queremos hallar un índice k, tal que 1 ≤ k ≤ n y T[k] = k. Si no existe dicho índice, entonces k será -1. Se desea que diseñe un algoritmo que tome tiempo Θ(log n) y use memoria adicional Θ(1).
*/

/**
 * ---------- SOLUCION ----------
 * @brief Devuelve el índice k, tal que 1 ≤ k ≤ n y T[k] = k. Si no existe dicho índice, entonces k será -1.
 * 
 * Argumento de correctitud: 
 * Sea un arreglo ordenado de menor a mayor T[1..n] de elementos distintos:
 * 
 * Si T[i] > i, entonces T[i+1] > i+1 para todo i. Argumento: Como el arreglo es de elementos distintos y 
 * ordenado, entonces T[i+1] > T[i] > i. Esto implica T[i+1] >= T[i]+1 > i+1. Por lo tanto, no vale la pena
 * buscar la solución para los elementos a la derecha de T[i] en el arreglo. Pues T[i+1] > i+1, y por inducción
 * se puede ver que T[i+2] > i+2, T[i+3] > i+3, ..., T[n] > n.
 * 
 * De manera analoga, si T[i] < i, entonces T[i-1] < i-1 para todo i.
 * 
 * Argumento de complejidad de espacio:
 * Es θ(1) pues solo se usa memoria adicional para guardar los indices l, r y el valor iterativo de k.
 * 
 * Argumento de complejidad de tiempo:
 * En cada iteración del algoritmo, se divide el problema a la mitad y se realiza una cantidad constante de
 * operaciones. La recurrencia nos queda T(n) = T(n/2) + c. Por el teorema maestro, la complejidad de tiempo
 * es θ(log n).
 *  
 * @param T Arreglo de enteros
 * @param n Tamaño del arreglo
 * 
*/
int findIndex(int *T, int n){
	int l = 0;
	int r = n-1;
	while(l <= r){
		int k = (l+r)/2;
		if(T[k] == k) return k;
		else if(T[k] > k) r = k-1;
		else l = k+1;
	}
	return -1;
}

