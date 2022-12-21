# Para contar la cantidad de veces que podemos pelar nuestros Convex layers, aplicaremos el siguiente algoritmo.

# Primero se puede calcular el convex hull más externo con el apoyo del algoritmo Graham Scan visto en el curso. Luego, se eliminarán estos puntos encontrados del conjunto de todos los puntos. Esa iteración fue “pelar una capa”. Este proceso se repite hasta que no queden más puntos. Por cada iteración se le suma 1 a la variable que cuenta las capas.

# Pseudocódigo: (por simplicidad se obvian casos bordes como tener < 3 puntos).

def compute_convex_hull(points):
 ch = pila vacia
 p = punto más abajo/derecho de C
 puntos = ordenar(C - {p}) con respecto a p
 push(ch, p)
 push(ch, puntos[1])
 
 for i in range(2,n):
   while cruz(vec(puntos[i-1], puntos[i]) and vec(puntos[p], tope(ch))) < 0:
     pop(ch)
   push(ch, puntos[i])
 
 return conjunto(ch)
 
def convex_layers(points):
 layers = 0
 while points:
   # We can use Graham Scan algorithm to compute the convex hull
   convex_hull = compute_convex_hull(points)
  
   for point in convex_hull:
     points.remove(point)
 
   layers += 1
  
 return layers

# Análisis de complejidad.
# Complejidad en tiempo: El algoritmo para hallar la convex hull de Graham Scan tiene una complejidad en tiempo de O(n*log n). En el peor de los casos el algoritmo devolverá 3 puntos, lo que hará que en cada iteración el número de puntos se reduzca en 3, esto hace que la cantidad de veces que pueda ser llamado el algoritmo sea O(n). Por lo tanto, nos queda que su complejidad en tiempo es O(n^2 log n). Notemos que estamos asumiendo que los puntos se están guardando en una estructura de datos eficiente para la operación delete().

# Complejidad en espacio: El algoritmo para hallar la convex hull de Graham Scan tiene una complejidad en espacio de O(n). Los puntos también son O(n). Por lo que concluimos que nuestra complejidad en espacio es O(n).
