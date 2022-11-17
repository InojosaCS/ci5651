#include<iostream>
#include<vector>
using namespace std;

/**
 * Sea A[1..n] un arreglo de enteros. 
 * 
 * Decimos que B es un sub–arreglo de A si se pueden remover elementos del arreglo A, respetando 
 * el orden en el que aparecen, para obtener B. Decimos que B[1..k] es bueno si el arreglo no está vacío 
 * y para todo i, tal que 1 ≤ i ≤ k se cumple que B[i] es divisible entre i. Consideramos que dos 
 * sub-arreglos son diferentes si provienen de posiciones diferentes en A, incluso si los valore son iguales
 * 
 * Queremos saber la cantidad de sub–arreglos buenos de A.
*/

/**
 * ---------- SOLUCION ----------
 * @brief Devuelve la cantidad de sub–arreglos buenos de A.
 * 
 * Para cada elemento A[i] del arreglo, se puede elegir o no elegir. Si se elige, entonces se debe cumplir que
 * A[i] es divisible por algun j, tal que 1 ≤ j ≤ i. Luego, si A[i] es divisible por j, entonces se puede plantear 
 * el problema de encontrar la cantidad de sub-arreglos buenos de A[1..i-1] (de tamaño j-1), y agregarle A[i] a cada uno 
 * de ellos en la posicion j.
 * 
 * Argumento de complejidad de espacio:
 * Es θ(n) pues se usa de memoria adicional un arreglo de tamaño N para guardar los valores de la cantidad de 
 * sub-arreglos buenos de A[1..i] para cada i.
 * 
 * Argumento de complejidad de tiempo:
 * Por cada posición i del arreglo, se recorre el arreglo de 1 a i-1, y se realiza una cantidad constante de operaciones.
 * Esto puede verse como n*(n+1)/2. Por lo tanto, la complejidad de tiempo es θ(n^2).
 * 
 * @param T Arreglo de enteros
 * @param n Tamaño del arreglo
*/
int dp(int *T, int n){
	// dp(i) = cantidad de sub-arreglos buenos de tamaño i
	vector<int> dp(n+1, 0);

	// Caso base
	dp[0] = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j > 0; j--){
			if(T[i] % j == 0){
				// Si T[i] es divisible por j, entonces puedo agregarlo a todos los sub-arreglos de tamaño j-1
				// this is the actual dp magic :)
				dp[j] += dp[j-1];
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += dp[i];
	}

	return ans;
}

int main(){
	int T[] = {2, 2, 1, 22, 14};
	int n = 5;
	cout << dp(T, n) << endl;
}