#include<iostream>
#include<vector>
using namespace std;

/**
 * Definimos los números de Perrin con la siguiente recurrencia
 * P(0) = 3
 * P(1) = 0
 * P(2) = 2
 * P(n) = P(n-2) + P(n-3) para todo n > 2
 * 
 * Se desea que diseñe un algoritmo que tome tiempo Θ(log n) para hallar el valor de P(n).
 *
*/

/* Funciones auxiliares para multiplicar matrices y hallar una potencia de matrices*/
vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B);
vector<vector<int>> power(vector<vector<int>> A, int n);

/**
 * ---------- SOLUCION ----------
 * @brief Halla el valor de P(n) en tiempo Θ(log n)
 * 
 * Este algoritmo se basa en la conocida tecnica de exponenciación de matrices.
 * El caso más popular de esta tecnica es la de calcular nth número de fibonacci.
 * Para el caso de los números de Perrin usaremos de base la matrices A = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}}
 * B = {{3}, {0}, {2}}. Entonces {P(n), P(n+1), P(n+2)} = A^n * B. La demostración de esta igualdad es por inducción,
 * y sería similar al caso de fibonacci.
 * 
 * Argumento de complejidad de espacio:
 * Es θ(1) pues solo se usa memoria adicional para guardar las matrices A, B y la matriz resultante, y estas tienen un 
 * tamaño constante acotado por 3x3.
 * 
 * Argumento de complejidad de tiempo:
 * Al igual que el fibonacci de la tecnica de exponenciación de matrices, el algoritmo de los números de Perrin realiza
 * θ(1) operaciones por cada multiplicación de matrices, y se llama θ(log n) veces por el algoritmo de exponenciación binaria
 * Por lo tanto, la complejidad de tiempo es θ(log n).
 * 
 * @param n Número de Perrin a hallar
 * 
*/
int findNthPerrinNumber(int n){
	// Caso base
	if(n == 0) return 3;
	if(n == 1) return 0;
	if(n == 2) return 2;

	// Caso general
	vector<vector<int>> base = {
		{0,1,0},
		{0,0,1},
		{1,1,0}
	};

	auto C = multiply(power(base, n), {{3},{0},{2}});
	return C[0][0];
}

int main(){
	for(int i = 0; i < 14; i++){
		cout << findNthPerrinNumber(i) << " ";
	}
	return 0;
}

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B){
	int r = A.size();
	int c = B[0].size();
	vector<vector<int>> C(r, vector<int>(c, 0));

	for(int i = 0; i < r; i++){    
		for(int j = 0; j < c; j++){    
			for(int k = 0; k < r; k++){    
				C[i][j] += A[i][k]*B[k][j];    
			}    
		}    
	} 

	return C;
}

vector<vector<int>> power(vector<vector<int>> A, int n){
	if(n == 1){
		return A;
	}
	if(n%2 == 0){
		return power(multiply(A, A), n/2);
	}
	return multiply(A, power(multiply(A, A), (n-1)/2));
}
