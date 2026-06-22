#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<chrono>
#include<sstream>
#include<fstream>
using namespace std;
void mostrarInterfaz(){
	cout<<"-----MENU-----"<<endl;
	cout<<"1. Jugar"<<endl;
	cout<<"2. Ver puntajes"<<endl;
	cout<<"3. Salir"<<endl;
}
void elegirDificultad(int &filas, int &columnas, int &minas){
	int opcion;
	cout<<"Seleccione una dificultad: "<<endl;
	cout<<"1. Facil(8x8, 10 minas)"<<endl;
	cout<<"2. Medio(16x16, 40 minas)"<<endl;
	cout<<"3. Dificil(16x30, 99 minas)"<<endl;
	cout<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
	
		case 1:
			filas = 8;
			columnas = 8;
			minas = 10;
			break;
		case 2:
			filas = 16;
			columnas = 16;
			minas = 40;
			break;
		case 3:
			filas = 16;
			columnas = 30; 
			minas = 99;
			break;
		default:
			cout<<"Opción no válida, se selecionará dificultad Fácil por defecto"<<endl;
			filas = 8;
			columnas = 8;
			minas = 10;
	}
}
void mostrarTablero(const vector<vector<char>>& tablero){
	cout<<"  ";
	for(int i = 0; i < tablero[0].size(); i++){
		cout<<i<<" ";
	}
	cout<<endl;
	
	for(int i = 0; i < tablero.size(); i++){
		cout<<i<<" ";
		for(int j = 0; j < tablero[i].size(); j++){
			cout<<tablero[i][j]<<" ";
		}
		cout<<endl;
	}
}
void colocarMinas(vector<vector<char>>& tablero, int minas){
	int filas = tablero.size();
	int columnas = tablero[0].size();
	while(minas > 0){
		int x = rand() % filas;
		int y = rand() % columnas;
		if(tablero[x][y] != '*'){
			tablero[x][y] = '*';
			minas--;
		}
	}
}
int main(){
	int opcion;
	do{
		mostrarInterfaz();
		cout<<"Opcion: ";
		cin>>opcion;
		switch(opcion){
			case 1: {
				int filas, columnas, minas;
				elegirDificultad(filas, columnas, minas);
				vector<vector<char>> tableroVisible(filas, vector<char>(columnas, '#'));
				vector<vector<char>> tableroOculto(filas, vector<char>(columnas, '0'));
				cout<<"Tablero creado: "<<filas<<" x "<<columnas<<endl;
				colocarMinas(tableroOculto, minas);
				mostrarTablero(tableroVisible);
				mostrarTablero(tableroOculto);
				break;
			}
			case 2:{
				cout<<"Mostrando puntajes: "<<endl;
				break;
			}
		}
		
	}while(opcion != 3);
	
	return 0;
}

