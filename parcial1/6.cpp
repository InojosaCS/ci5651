#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * Dadas n peticiones de publicidad, donde la i–ésima petición tiene pi (el punto de inicio de la valla) 
 * y ti (el tamaño de la valla), diseñe un algoritmo eficiente que permite escoger un conjunto maximal 
 * de peticiones tal que ninguna valla intersecte con otra.
*/

/**
 * ---------- SOLUCION ----------
 * @brief Halla el número máximo de vallas que se pueden colocar sin que se interseccionen
 * 
 * Este problema es equivalente a hallar el maximo numero de intervalos disconjuntos en un conjunto de intervalos.
 * Para resolver este problema usaremos un algoritmo de Greedy, el cual consiste ordenar las vallas por su punto 
 * de finalización que para la valla i sería p(i) + t(i). Luego, ir recorriendo todos los intervalos,
 * si obtenemos dos intervalos que se solapan, entonces elegimos  el intervalo con el punto final más bajo ya que,
 * al elegirlo, en el mejor de los casos permite acomodar más intervalos, y en el peor, no afecta negativamente.
 * 
 * Argumento de complejidad de espacio:
 * Es θ(n) pues se usa memoria adicional para guardar los intervalos.
 * 
 * Argumento de complejidad de tiempo:
 * El ordenamiento es O(n log n), y el recorrido de los intervalos es O(n), por lo tanto, la complejidad de tiempo es O(n log n).
 * 
 * @param p Arreglo con puntos de inicio de las vallas
 * @param t Arreglo con tamaños de las vallas
*/
int maximalDisjointInterval(vector<int> p, vector<int> t){
	int n = p.size();
	vector<pair<int, int>> intervals;
	for(int i = 0; i < n; i++){
		intervals.push_back({p[i], p[i] + t[i]});
	}

	sort(intervals.begin(), intervals.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second < b.second;
	});

	int ans = 0;
	int last = -1;
	for(auto interval : intervals){
		if(interval.first >= last){
			ans++;
			last = interval.second;
		}
	}

	return ans;
}

int main(){
	vector<int> p = {1, 2, 3};
	vector<int> t = {4, 1, 3};
	cout << maximalDisjointInterval(p, t) << endl;
}