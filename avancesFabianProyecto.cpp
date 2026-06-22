#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<chrono>
#include<sstream>
#include<fstream>
using namespace std;
void mostrarInterfaz(){ //Esta funcion es para mostrar la interfaz al principio de todo, de esta manera hay interactividad con el usuario para que luego comienze a escojer lo que desea hacer
	cout<<"-----MENU-----"<<endl;
	cout<<"1. Jugar"<<endl;
	cout<<"2. Ver puntajes"<<endl;
	cout<<"3. Salir"<<endl;
}
void elegirDificultad(int &filas, int &columnas, int &minas){ //Esta funcion tambien es interactiva ya que permite al usuario escojer una dificultad deseada
	int opcion;
	cout<<"Seleccione una dificultad: "<<endl;
	cout<<"1. Facil(8x8, 10 minas)"<<endl;
	cout<<"2. Medio(16x16, 40 minas)"<<endl;
	cout<<"3. Dificil(16x30, 99 minas)"<<endl;
	cout<<"Al escojer otro numero se seleccionara dificultad Facil por defecto"<<endl;
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
			cout<<"Opcion no valida, se selecionara dificultad Facil por defecto"<<endl;
			filas = 8;
			columnas = 8;
			minas = 10;
	}
}
void mostrarTablero(const vector<vector<char>>& tablero){ //Esta funcion muestra el tablero para que el jugador pueda ver los cambios durante el transcurso del juego
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
void colocarMinas(vector<vector<char>>& tablero, int minas){ //Esta funcion ayuda a colocar las minas en el tablero de manera aleatoria
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
		mostrarInterfaz(); //mostramos la interfaz
		cout<<"Opcion: ";
		cin>>opcion;
		switch(opcion){ //aqui es donde el usuario elije que hacer a partir de la interfaz
			case 1: {
				int filas, columnas, minas;
				elegirDificultad(filas, columnas, minas);
				vector<vector<char>> tableroVisible(filas, vector<char>(columnas, '#')); //creamos dos tableros, uno visible y uno oculto para el usuario, donde se iran generando cambios y nos permite ver a nosotros como transcurre el juego durante la programacion
				vector<vector<char>> tableroOculto(filas, vector<char>(columnas, '0'));
				cout<<"Tablero creado: "<<filas<<" x "<<columnas<<endl; //el usuario puede corroborar la dificultad escojida
				colocarMinas(tableroOculto, minas); //colocamos las minas aleatoriamente
				mostrarTablero(tableroVisible); //ver  parcialmente el tablero
				mostrarTablero(tableroOculto); // esto se quitara luego pero ahora nos sirve para comparar con respecto al otro tablero durante la programacion del juego
				break;
			}
			case 2:{
				cout<<"Mostrando puntajes: "<<endl; //aca se mostraran puntajes, falta por terminar
				break;
			}
		}
		
	}while(opcion != 3); //permite que si se escoje 3, termina el programa, ademas, si se scoje un numero diferente volvera a aparecer la interfaz hasta que el usuario decida jugar o ver los puntajes.
	
	return 0;
}

