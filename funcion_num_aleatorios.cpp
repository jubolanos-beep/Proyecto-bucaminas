#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
//Esta función sera la encargada de crear las 3 matrices de los 3 tipos de juego disponibles, asignándoles el número correspondiente de minas en espacios aleatorios.
void matriz_num_aleatorio(int filas, int columnas){
//La función srand permite crear el número aleatorio, inicializé con time(NULL) que equivale a los segundos transcurridos desde el 1 de enero 1970, sin meterlo en una variable.
	srand(time(NULL));
	int tablero [filas][columnas]={0};
	int maximo=filas*columnas;
	if (maximo=8*8){
		for (int i=0; i<10; i++){
			//El ciclo va hasta 10 ya que es el número de minas que quiero para una matriz de 8*8, los números aleatorios de deben inicializr de nuevo en cada ciclo
			int aleatorio_filas=rand()%filas;
			int aleatorio_columnas=rand()%columnas;
			//cada 9 repreenta una mina, posteriormente esto cambiara cuando se desarrolle la parte que se muestra al usuario
			//En caso de que la casilla ya tenga una mina, resté 1 a la variable de conteo e inicializé el contador nuevamente
			if(tablero[aleatorio_filas][aleatorio_columnas]!=9){
				tablero[aleatorio_filas][aleatorio_columnas]=9;
			}
			else {
				i--;
			}
		}
	}
	if (maximo=16*16){
		for (int i=0; i<40; i++){
			//El ciclo va hasta 40 ya que es el número de minas que quiero para una matriz de 16*16, los números aleatorios de deben inicializr de nuevo en cada ciclo
			int aleatorio_filas=rand()%filas;
			int aleatorio_columnas=rand()%columnas;
			//cada 9 repreenta una mina, posteriormente esto cambiara cuando se desarrolle la parte que se muestra al usuario
			//En caso de que la casilla ya tenga una mina, resté 1 a la variable de conteo e inicializé el contador nuevamente
			if(tablero[aleatorio_filas][aleatorio_columnas]!=9){
				tablero[aleatorio_filas][aleatorio_columnas]=9;
			}
			else {
				i--;
			}
		}
	}
		if (maximo=30*16){
		for (int i=0; i<99; i++){
			//El ciclo va hasta 99 ya que es el número de minas que quiero para una matriz de 30*16, los números aleatorios de deben inicializr de nuevo en cada ciclo
			int aleatorio_filas=rand()%filas;
			int aleatorio_columnas=rand()%columnas;
			//cada 9 repreenta una mina, posteriormente esto cambiara cuando se desarrolle la parte que se muestra al usuario
			//En caso de que la casilla ya tenga una mina, resté 1 a la variable de conteo e inicializé el contador nuevamente
			if(tablero[aleatorio_filas][aleatorio_columnas]!=9){
				tablero[aleatorio_filas][aleatorio_columnas]=9;
			}
			else {
				i--;
			}
		}
	}
}
//Coloqué la función int main para probar y compilar la función
int main(){
	matriz_num_aleatorio(8, 8);
}

