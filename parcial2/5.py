# Sea A y B dos matrices n x n, para algun entero n > 0.
# Sospechamos que B = A^-1. Esto es, que B es la matriz inversa de A.
# Diseñe un algoritmo de Monte Carlo que permita confirmar esta sospecha, con un cierto error permitido \epsilon, usando tiempo O(n2log 1/\epsilon).

# Solución

# Para resolver este problema usaremos el método de Freivalds de los algoritmos de Monte Carlo visto en clase.

# Básicamente este método nos permite verificar si dadas 3 matrices A', B' y C', se cumple que A'B' = C', con un error \epsilon, usando tiempo O(n2log 1/\epsilon).

# En nuestro caso, tenemos que averiguar si B = A^-1, es decir, su matriz inversa. Para aplicar el método de Freivalds, verificaremos si AB = I, donde I es la matriz identidad. Esto es, C' = I.

# Tal como se describe en la clase generamos el vector X de 1xn.

# Luego nos queda ver si:
# XAB = XC.


# Esto se puede hacer eficientemente en O(n^2), en dado que X es 1xn.

# Si AB = C el algoritmo siempre dara True, pero si no, la probabilidad de dar un falso positivo es de 1/2. Como queremos un error de \epsilon, tendremos que correr el algoritmo log(1/\epsilon) veces. De ahí, la complejidad O(n^2log(1/\epsilon)).

import random
import math

# multiply vector 1xn by matrix nxn
def multiply_vector_matrix(vector, matrix):
	result = []
	for i in range(len(matrix)):
		sum = 0
		for j in range(len(vector)):
			sum += vector[j] * matrix[i][j]
		result.append(sum)
	return result


def freivalds(epsilon, A, B, C):
	k = int(math.log(1/epsilon))

	for _ in range(k):
		# generate vector X randomly
		X = [random.randint(0, 1) for _ in range(len(A))]
		# calculate XAB
		XAB = multiply_vector_matrix(X, A)
		XAB = multiply_vector_matrix(XAB, B)
		# calculate XC
		XC = multiply_vector_matrix(X, C)
		# compare XAB and XC
		if XAB != XC:
			return False

	return True
	

if __name__ == '__main__':
	A = [[1, 2], [3, 4]]
	B = [[-2, 1], [3/2, -1/2]]
	C = [[1 if i == j else 0 for i in range(len(A))] for j in range(len(A))]
	epsilon = 0.1
	print(freivalds(epsilon, A, B, C))
