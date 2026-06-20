#include<iostream>
#include<ctime>
using namespace std;
//Declaré las variables auxiliares globales para guardar las matrices que se procesen en las funciones
int matriz_random_10_minas[8][8]={0};
int matriz_random_40_minas[16][16]={0};
int matriz_random_99_minas[16][30]={0};
//Esta función generará minas en espacios aleatorios de cada matriz
void matriz_num_aleatorio(int filas, int columnas){
//La función srand permite crear el número aleatorio, inicializé con time(NULL) que equivale a los segundos transcurridos desde el 1 de enero 1970, sin meterlo en una variable.
	srand(time(NULL));
	int tablero [filas][columnas]={0};
	int maximo=filas*columnas;
	if (maximo==64){
		for (int i=0; i<10; i++){
			//El ciclo va hasta 10 ya que es el número de minas que quiero para una matriz de 8*8, los números aleatorios de deben inicializr de nuevo en cada ciclo
			int aleatorio_filas=rand()%filas;
			int aleatorio_columnas=rand()%columnas;
			//cada 9 repreenta una mina, posteriormente esto cambiara cuando se desarrolle la parte que se muestra al usuario
			//En caso de que la casilla ya tenga una mina, resté 1 a la variable de conteo e inicializé el contador nuevamente
			if(tablero[aleatorio_filas][aleatorio_columnas]!=9){
				tablero[aleatorio_filas][aleatorio_columnas]=9;
				matriz_random_10_minas[aleatorio_filas][aleatorio_columnas]=tablero[aleatorio_filas][aleatorio_columnas];
			}
			else {
				i--;
			}
		}
	}
	if (maximo==256){
		for (int i=0; i<40; i++){
			//El ciclo va hasta 40 ya que es el número de minas que quiero para una matriz de 16*16, los números aleatorios de deben inicializr de nuevo en cada ciclo
			int aleatorio_filas=rand()%filas;
			int aleatorio_columnas=rand()%columnas;
			//cada 9 repreenta una mina, posteriormente esto cambiara cuando se desarrolle la parte que se muestra al usuario
			//En caso de que la casilla ya tenga una mina, resté 1 a la variable de conteo e inicializé el contador nuevamente
			if(tablero[aleatorio_filas][aleatorio_columnas]!=9){
				tablero[aleatorio_filas][aleatorio_columnas]=9;
				matriz_random_40_minas[aleatorio_filas][aleatorio_columnas]=tablero[aleatorio_filas][aleatorio_columnas];
			}
			else {
				i--;
			}
		}
	}
		if (maximo==480){
		for (int i=0; i<99; i++){
			//El ciclo va hasta 99 ya que es el número de minas que quiero para una matriz de 30*16, los números aleatorios de deben inicializr de nuevo en cada ciclo
			int aleatorio_filas=rand()%filas;
			int aleatorio_columnas=rand()%columnas;
			//cada 9 repreenta una mina, posteriormente esto cambiara cuando se desarrolle la parte que se muestra al usuario
			//En caso de que la casilla ya tenga una mina, resté 1 a la variable de conteo e inicializé el contador nuevamente
			if(tablero[aleatorio_filas][aleatorio_columnas]!=9){
				tablero[aleatorio_filas][aleatorio_columnas]=9;
				matriz_random_99_minas[aleatorio_filas][aleatorio_columnas]=tablero[aleatorio_filas][aleatorio_columnas];
			}
			else {
				i--;
			}
		}
	}
}
//Las siguientes funciones void, se encargan de rellenar por medio de ciclos los espacios restantes de las matrices
 void asignar_casillas_8x8(int matriz_1[8][8]){
 	//Los siguientes 4 ifs son para las esquinas de la matriz
	if (matriz_1[0][0]!=9){
		int i=0;
		if(matriz_1[0][1]==9){
			i++;
		}
		if(matriz_1[1][0]==9){
			i++;
		}
		if(matriz_1[1][1]==9){
			i++;
		}
		matriz_1[0][0]=i;
	}
	if (matriz_1[0][7]!=9){
		int i=0;
		if(matriz_1[0][6]==9){
			i++;
		}
		if(matriz_1[1][7]==9){
			i++;
		}
		if(matriz_1[1][6]==9){
			i++;
		}
		matriz_1[0][7]=i;
	}
	if (matriz_1[7][0]!=9){
		int i=0;
		if(matriz_1[7][1]==9){
			i++;
		}
		if(matriz_1[6][0]==9){
			i++;
		}
		if(matriz_1[6][1]==9){
			i++;
		}
		matriz_1[7][0]=i;
	}
	if (matriz_1[7][7]!=9){
		int i=0;
		if(matriz_1[7][6]==9){
			i++;
		}
		if(matriz_1[6][7]==9){
			i++;
		}
		if(matriz_1[6][6]==9){
			i++;
		}
		matriz_1[7][7]=i;
	}
	//Los siguientes 4 fors son para los bordes de la matriz
	for (int i=1; i<7; i++){
		if (matriz_1[0][i]!=9){
			int j=0;
			if (matriz_1[0][i-1]==9){
				j++;
			}
			if (matriz_1[0][i+1]==9){
				j++;
			}
			if (matriz_1[1][i-1]==9){
				j++;
			}
			if (matriz_1[1][i+1]==9){
				j++;
			}
			if (matriz_1[1][i]==9){
				j++;
			}
			matriz_1[0][i]=j;
		}
	}
	for (int i=1; i<7; i++){
		if (matriz_1[7][i]!=9){
			int j=0;
			if (matriz_1[7][i-1]==9){
				j++;
			}
			if (matriz_1[7][i+1]==9){
				j++;
			}
			if (matriz_1[6][i-1]==9){
				j++;
			}
			if (matriz_1[6][i+1]==9){
				j++;
			}
			if (matriz_1[6][i]==9){
				j++;
			}
			matriz_1[7][i]=j;
		}
	}
	for (int i=1; i<7; i++){
		if (matriz_1[i][0]!=9){
			int j=0;
			if (matriz_1[i-1][0]==9){
				j++;
			}
			if (matriz_1[i+1][0]==9){
				j++;
			}
			if (matriz_1[i+1][1]==9){
				j++;
			}
			if (matriz_1[i-1][1]==9){
				j++;
			}
			if (matriz_1[i][1]==9){
				j++;
			}
			matriz_1[i][0]=j;
		}
	}
	for (int i=1; i<7; i++){
		if (matriz_1[i][7]!=9){
			int j=0;
			if (matriz_1[i-1][7]==9){
				j++;
			}
			if (matriz_1[i+1][7]==9){
				j++;
			}
			if (matriz_1[i+1][6]==9){
				j++;
			}
			if (matriz_1[i-1][6]==9){
				j++;
			}
			if (matriz_1[i][6]==9){
				j++;
			}
			matriz_1[i][7]=j;
		}
	}
	//Este for se encarga de rellenar los espacios vacios restantes de la matriz
	for (int i=1; i<7; i++){
		for(int j=1; j<7; j++){
			if(matriz_1[i][j]!=9){
				int c=0;
				if (matriz_1[i][j+1]==9){
				c++;
				}
				if (matriz_1[i][j-1]==9){
				c++;
				}
				if (matriz_1[i-1][j-1]==9){
				c++;
				}
				if (matriz_1[i+1][j-1]==9){
				c++;
				}
				if (matriz_1[i+1][j]==9){
				c++;
				}
				if (matriz_1[i-1][j+1]==9){
				c++;
				}
				if (matriz_1[i+1][j+1]==9){
				c++;
				}
				if (matriz_1[i-1][j]==9){
				c++;
				}
				matriz_1[i][j]=c;
			}
		}
	}
}
//Las siguientes 2 funciones void funcionan igual que la anterior, solo que ahora cambian los tamaños de las matrices
void asignar_casillas_16x16(int matriz_1[16][16]){
	if (matriz_1[0][0]!=9){
		int i=0;
		if(matriz_1[0][1]==9){
			i++;
		}
		if(matriz_1[1][0]==9){
			i++;
		}
		if(matriz_1[1][1]==9){
			i++;
		}
		matriz_1[0][0]=i;
	}
	if (matriz_1[0][15]!=9){
		int i=0;
		if(matriz_1[0][14]==9){
			i++;
		}
		if(matriz_1[1][15]==9){
			i++;
		}
		if(matriz_1[1][14]==9){
			i++;
		}
		matriz_1[0][15]=i;
	}
	if (matriz_1[15][0]!=9){
		int i=0;
		if(matriz_1[15][1]==9){
			i++;
		}
		if(matriz_1[14][0]==9){
			i++;
		}
		if(matriz_1[14][1]==9){
			i++;
		}
		matriz_1[15][0]=i;
	}
	if (matriz_1[15][15]!=9){
		int i=0;
		if(matriz_1[15][14]==9){
			i++;
		}
		if(matriz_1[14][15]==9){
			i++;
		}
		if(matriz_1[14][14]==9){
			i++;
		}
		matriz_1[15][15]=i;
	}
	for (int i=1; i<15; i++){
		if (matriz_1[0][i]!=9){
			int j=0;
			if (matriz_1[0][i-1]==9){
				j++;
			}
			if (matriz_1[0][i+1]==9){
				j++;
			}
			if (matriz_1[1][i-1]==9){
				j++;
			}
			if (matriz_1[1][i+1]==9){
				j++;
			}
			if (matriz_1[1][i]==9){
				j++;
			}
			matriz_1[0][i]=j;
		}
	}
	for (int i=1; i<15; i++){
		if (matriz_1[15][i]!=9){
			int j=0;
			if (matriz_1[15][i-1]==9){
				j++;
			}
			if (matriz_1[15][i+1]==9){
				j++;
			}
			if (matriz_1[14][i-1]==9){
				j++;
			}
			if (matriz_1[14][i+1]==9){
				j++;
			}
			if (matriz_1[14][i]==9){
				j++;
			}
			matriz_1[15][i]=j;
		}
	}
	for (int i=1; i<15; i++){
		if (matriz_1[i][0]!=9){
			int j=0;
			if (matriz_1[i-1][0]==9){
				j++;
			}
			if (matriz_1[i+1][0]==9){
				j++;
			}
			if (matriz_1[i+1][1]==9){
				j++;
			}
			if (matriz_1[i-1][1]==9){
				j++;
			}
			if (matriz_1[i][1]==9){
				j++;
			}
			matriz_1[i][0]=j;
		}
	}
	for (int i=1; i<15; i++){
		if (matriz_1[i][15]!=9){
			int j=0;
			if (matriz_1[i-1][15]==9){
				j++;
			}
			if (matriz_1[i+1][15]==9){
				j++;
			}
			if (matriz_1[i+1][14]==9){
				j++;
			}
			if (matriz_1[i-1][14]==9){
				j++;
			}
			if (matriz_1[i][14]==9){
				j++;
			}
			matriz_1[i][15]=j;
		}
	}
	for (int i=1; i<15; i++){
		for(int j=1; j<15; j++){
			if(matriz_1[i][j]!=9){
				int c=0;
				if (matriz_1[i][j+1]==9){
				c++;
				}
				if (matriz_1[i][j-1]==9){
				c++;
				}
				if (matriz_1[i-1][j-1]==9){
				c++;
				}
				if (matriz_1[i+1][j-1]==9){
				c++;
				}
				if (matriz_1[i+1][j]==9){
				c++;
				}
				if (matriz_1[i-1][j+1]==9){
				c++;
				}
				if (matriz_1[i+1][j+1]==9){
				c++;
				}
				if (matriz_1[i-1][j]==9){
				c++;
				}
				matriz_1[i][j]=c;
			}
		}
	}
}
void asignar_casillas_16x30(int matriz_1[16][30]){
	if (matriz_1[0][0]!=9){
		int i=0;
		if(matriz_1[0][1]==9){
			i++;
		}
		if(matriz_1[1][0]==9){
			i++;
		}
		if(matriz_1[1][1]==9){
			i++;
		}
		matriz_1[0][0]=i;
	}
	if (matriz_1[0][29]!=9){
		int i=0;
		if(matriz_1[0][28]==9){
			i++;
		}
		if(matriz_1[1][29]==9){
			i++;
		}
		if(matriz_1[1][28]==9){
			i++;
		}
		matriz_1[0][29]=i;
	}
	if (matriz_1[15][0]!=9){
		int i=0;
		if(matriz_1[15][1]==9){
			i++;
		}
		if(matriz_1[14][0]==9){
			i++;
		}
		if(matriz_1[14][1]==9){
			i++;
		}
		matriz_1[15][0]=i;
	}
	if (matriz_1[15][29]!=9){
		int i=0;
		if(matriz_1[15][28]==9){
			i++;
		}
		if(matriz_1[14][29]==9){
			i++;
		}
		if(matriz_1[14][18]==9){
			i++;
		}
		matriz_1[15][29]=i;
	}
	for (int i=1; i<29; i++){
		if (matriz_1[0][i]!=9){
			int j=0;
			if (matriz_1[0][i-1]==9){
				j++;
			}
			if (matriz_1[0][i+1]==9){
				j++;
			}
			if (matriz_1[1][i-1]==9){
				j++;
			}
			if (matriz_1[1][i+1]==9){
				j++;
			}
			if (matriz_1[1][i]==9){
				j++;
			}
			matriz_1[0][i]=j;
		}
	}
	for (int i=1; i<29; i++){
		if (matriz_1[15][i]!=9){
			int j=0;
			if (matriz_1[15][i-1]==9){
				j++;
			}
			if (matriz_1[15][i+1]==9){
				j++;
			}
			if (matriz_1[14][i-1]==9){
				j++;
			}
			if (matriz_1[14][i+1]==9){
				j++;
			}
			if (matriz_1[14][i]==9){
				j++;
			}
			matriz_1[15][i]=j;
		}
	}
	for (int i=1; i<15; i++){
		if (matriz_1[i][0]!=9){
			int j=0;
			if (matriz_1[i-1][0]==9){
				j++;
			}
			if (matriz_1[i+1][0]==9){
				j++;
			}
			if (matriz_1[i+1][1]==9){
				j++;
			}
			if (matriz_1[i-1][1]==9){
				j++;
			}
			if (matriz_1[i][1]==9){
				j++;
			}
			matriz_1[i][0]=j;
		}
	}
	for (int i=1; i<15; i++){
		if (matriz_1[i][29]!=9){
			int j=0;
			if (matriz_1[i-1][29]==9){
				j++;
			}
			if (matriz_1[i+1][29]==9){
				j++;
			}
			if (matriz_1[i+1][28]==9){
				j++;
			}
			if (matriz_1[i-1][28]==9){
				j++;
			}
			if (matriz_1[i][28]==9){
				j++;
			}
			matriz_1[i][29]=j;
		}
	}
	for (int i=1; i<15; i++){
		for(int j=1; j<29; j++){
			if(matriz_1[i][j]!=9){
				int c=0;
				if (matriz_1[i][j+1]==9){
				c++;
				}
				if (matriz_1[i][j-1]==9){
				c++;
				}
				if (matriz_1[i-1][j-1]==9){
				c++;
				}
				if (matriz_1[i+1][j-1]==9){
				c++;
				}
				if (matriz_1[i+1][j]==9){
				c++;
				}
				if (matriz_1[i-1][j+1]==9){
				c++;
				}
				if (matriz_1[i+1][j+1]==9){
				c++;
				}
				if (matriz_1[i-1][j]==9){
				c++;
				}
				matriz_1[i][j]=c;
			}
		}
	}
}
void reimprimir_matriz(char matriz[8][8]){
	cout<<"  "<<"A"<<" "<<"B"<<" "<<"C"<<" "<<"D"<<" "<<"E"<<" "<<"F"<<" "<<"G"<<" "<<"H"<<endl;
	cout<<"1 ";
	for (int i=0; i<8; i++){
		cout<<matriz[0][i]<<" ";
	}	
	cout<<endl;	
	cout<<"2 ";
	for (int i=0; i<8; i++){
		cout<<matriz[1][i]<<" ";
	}
	cout<<endl;	
	cout<<"3 ";
	for (int i=0; i<8; i++){
		cout<<matriz[2][i]<<" ";
	}	
	cout<<endl;	
	cout<<"4 ";	
	for (int i=0; i<8; i++){
		cout<<matriz[3][i]<<" ";
	}
	cout<<endl;	
	cout<<"5 ";		
	for (int i=0; i<8; i++){
		cout<<matriz[4][i]<<" ";
	}	
	cout<<endl;		
	cout<<"6 ";
	for (int i=0; i<8; i++){
		cout<<matriz[5][i]<<" ";
	}	
	cout<<endl;		
	cout<<"7 ";
	for (int i=0; i<8; i++){
		cout<<matriz[6][i]<<" ";
	}
	cout<<endl;	
	cout<<"8 ";		
	for (int i=0; i<8; i++){
		cout<<matriz[7][i]<<" ";
	}		
}
//A continuación añadí una función recursiva que recorre la matriz y muestra los espacios adyacentes vacios: Si se oprime o muestra un 0, se mostrará todas las casillas adyacentes, de esta forma, todas las casillas son números distintos de 0 o números.
void limpiar_casillas(char matriz[8][8], int matriz_int [8][8]){
	for (int c=0; c<3; c++){
		if (matriz[0][0]=='0'){
			matriz[0][1]=matriz_int[0][1]+'0';
			matriz[1][0]=matriz_int[1][0]+'0';
			matriz[1][1]=matriz_int[1][1]+'0';
		}
		if (matriz[7][7]=='0'){
			matriz[7][6]=matriz_int[7][6]+'0';
			matriz[6][6]=matriz_int[6][6]+'0';
			matriz[6][7]=matriz_int[6][7]+'0';
		}
		if (matriz[7][0]=='0'){
			matriz[6][0]=matriz_int[0][1]+'0';
			matriz[7][1]=matriz_int[1][0]+'0';
			matriz[6][1]=matriz_int[1][1]+'0';
		}
		if (matriz[0][7]=='0'){
			matriz[0][6]=matriz_int[0][1]+'0';
			matriz[1][7]=matriz_int[1][0]+'0';
			matriz[1][6]=matriz_int[1][1]+'0';
		}
		for (int i=1; i<7; i++){
			if (matriz[0][i]=='0'){
				matriz[0][i-1]=matriz_int[0][i-1]+'0';
				matriz[0][i+1]=matriz_int[0][i+1]+'0';
				matriz[1][i-1]=matriz_int[1][i-1]+'0';
				matriz[1][i+1]=matriz_int[1][i+1]+'0';
				matriz[1][i]=matriz_int[1][i]+'0';
			}
		}
		for (int i=1; i<7; i++){
			if (matriz[7][i]=='0'){
				matriz[7][i-1]=matriz_int[7][i-1]+'0';
				matriz[7][i+1]=matriz_int[7][i+1]+'0';
				matriz[6][i-1]=matriz_int[6][i-1]+'0';
				matriz[6][i+1]=matriz_int[6][i+1]+'0';
				matriz[6][i]=matriz_int[6][i]+'0';
			}
		}
		for (int i=1; i<7; i++){
			if (matriz[i][0]=='0'){
				matriz[i-1][0]=matriz_int[i-1][0]+'0';
				matriz[i+1][0]=matriz_int[i+1][0]+'0';
				matriz[i-1][1]=matriz_int[i-1][1]+'0';
				matriz[i+1][1]=matriz_int[i+1][1]+'0';
				matriz[i][1]=matriz_int[i][1]+'0';
			}
		}
		for (int i=1; i<7; i++){
			if (matriz[i][7]=='0'){
				matriz[i-1][7]=matriz_int[i-1][7]+'0';
				matriz[i+1][7]=matriz_int[i+1][7]+'0';
				matriz[i-1][6]=matriz_int[i-1][6]+'0';
				matriz[i+1][6]=matriz_int[i+1][6]+'0';
				matriz[i][6]=matriz_int[i][6]+'0';
			}
		}
		for (int i=1; i<7; i++){
			for(int j=1; j<7; j++){
				if(matriz[i][j]=='0'){
					matriz[i][j+1]=matriz_int[i][j+1]+'0';
					matriz[i][j-1]=matriz_int[i][j-1]+'0';
					matriz[i-1][j-1]=matriz_int[i-1][j-1]+'0';
					matriz[i+1][j-1]=matriz_int[i+1][j-1]+'0';
				    matriz[i+1][j]=matriz_int[i+1][j]+'0';
	           	 	matriz[i-1][j+1]=matriz_int[i-1][j+1]+'0';
					matriz[i+1][j+1]=matriz_int[i+1][j+1]+'0';
					matriz[i-1][j]=matriz_int[i-1][j]+'0';
				}
			}
		}
	}
}
/*void mostrar_minas(char arr[8][8]){
	for (int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(arr[i][j]=='9'){
				arr[i][j]='M';
			}
		}
	}
	reimprimir_matriz(arr);
}*/
int main (){
	cout<<"Este es un buscaminas de 8x8, contiene 10 minas, escribir una coordenada para destapar la casilla"<<endl;
	cout<<"Sistema coordenado: "<<endl;
	cout<<"  "<<"A"<<" "<<"B"<<" "<<"C"<<" "<<"D"<<" "<<"E"<<" "<<"F"<<" "<<"G"<<" "<<"H"<<endl;
	cout<<"1"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
	cout<<"2"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
	cout<<"3"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
	cout<<"4"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
	cout<<"5"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
	cout<<"6"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
	cout<<"7"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
	cout<<"8"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
	matriz_num_aleatorio(8,8);
	asignar_casillas_8x8(matriz_random_10_minas);
	//Declaro booleano para acabar la partida cuando se gane o se pierda.
	bool cerrar_ciclo_8x8=false;
	//Matriz de caracteres para mostrar al usuario 'X' e irlos cambiando a medida que va ingresando coordenadas, probablemente debamos agregarle una columna y una fila para las coordenadas
	char matriz_char_10[8][8]={
		{'X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X'},
		{'X','X','X','X','X','X','X','X'},
	    {'X','X','X','X','X','X','X','X'}
	};
	//Dentro de este ciclo se piden las jugadas del usuario
	while (cerrar_ciclo_8x8==false){
		string jugada;
		cout<<endl<<endl<<"Escriba una casilla: ";
		cin>>jugada;
		//Instructivo si el usuario ingresa coordenadas no válidas
		if (jugada!="A1" && jugada!="A2" && jugada!="A3" && jugada!="A4" && jugada!="A5" && jugada!="A6" && jugada!="A7" && jugada!="A8"&&
		    jugada!="B1" && jugada!="B2" && jugada!="B3" && jugada!="B4" && jugada!="B5" && jugada!="B6" && jugada!="B7" && jugada!="B8"&&
			jugada!="C1" && jugada!="C2" && jugada!="C3" && jugada!="C4" && jugada!="C5" && jugada!="C6" && jugada!="C7" && jugada!="C8"&&
			jugada!="D1" && jugada!="D2" && jugada!="D3" && jugada!="D4" && jugada!="D5" && jugada!="D6" && jugada!="D7" && jugada!="D8"&&
			jugada!="E1" && jugada!="E2" && jugada!="E3" && jugada!="E4" && jugada!="E5" && jugada!="E6" && jugada!="E7" && jugada!="E8"&&
			jugada!="F1" && jugada!="F2" && jugada!="F3" && jugada!="F4" && jugada!="F5" && jugada!="F6" && jugada!="F7" && jugada!="F8"&&
			jugada!="G1" && jugada!="G2" && jugada!="G3" && jugada!="G4" && jugada!="G5" && jugada!="G6" && jugada!="G7" && jugada!="G8"&&
			jugada!="H1" && jugada!="H2" && jugada!="H3" && jugada!="H4" && jugada!="H5" && jugada!="H6" && jugada!="H7" && jugada!="H8"){
			cout<<"Casilla del tablero no valida, intente otra vez, escribiendo las coordenadas como se muestran en el tablero"<<endl;
		}
		else{
		//En estos condicionales se cambia el espacio de las matrices, dependiendo de la coordenada escrita.
		//El +'0' que se ve al final de la segunda matriz indica que es un entero que se cambia a char para poder ingresarlo en la segunda matriz
			if(jugada=="A1"){
				if(matriz_random_10_minas[0][0]!=9){
					matriz_char_10[0][0]=matriz_random_10_minas[0][0]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="A2"){
				if(matriz_random_10_minas[1][0]!=9){
					matriz_char_10[1][0]=matriz_random_10_minas[1][0]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="A3"){
				if(matriz_random_10_minas[2][0]!=9){
					matriz_char_10[2][0]=matriz_random_10_minas[2][0]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="A4"){
				if(matriz_random_10_minas[3][0]!=9){
					matriz_char_10[3][0]=matriz_random_10_minas[3][0]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="A5"){
				if(matriz_random_10_minas[4][0]!=9){
					matriz_char_10[4][0]=matriz_random_10_minas[4][0]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="A6"){
				if(matriz_random_10_minas[5][0]!=9){
					matriz_char_10[5][0]=matriz_random_10_minas[5][0]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="A7"){
				if(matriz_random_10_minas[6][0]!=9){
					matriz_char_10[6][0]=matriz_random_10_minas[6][0]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}	
			if(jugada=="A8"){
				if(matriz_random_10_minas[7][0]!=9){
					matriz_char_10[7][0]=matriz_random_10_minas[7][0]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="B1"){
				if(matriz_random_10_minas[0][1]!=9){
					matriz_char_10[0][1]=matriz_random_10_minas[0][1]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="B2"){
				if(matriz_random_10_minas[1][1]!=9){
					matriz_char_10[1][1]=matriz_random_10_minas[1][1]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="B3"){
				if(matriz_random_10_minas[2][1]!=9){
					matriz_char_10[2][1]=matriz_random_10_minas[2][1]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="B4"){
				if(matriz_random_10_minas[3][1]!=9){
					matriz_char_10[3][1]=matriz_random_10_minas[3][1]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="B5"){
				if(matriz_random_10_minas[4][1]!=9){
					matriz_char_10[4][1]=matriz_random_10_minas[4][1]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="B6"){
				if(matriz_random_10_minas[5][1]!=9){
					matriz_char_10[5][1]=matriz_random_10_minas[5][1]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="B7"){
				if(matriz_random_10_minas[6][1]!=9){
					matriz_char_10[6][1]=matriz_random_10_minas[6][1]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="B8"){
				if(matriz_random_10_minas[7][1]!=9){
					matriz_char_10[7][1]=matriz_random_10_minas[7][1]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="C1"){
				if(matriz_random_10_minas[0][2]!=9){
					matriz_char_10[0][2]=matriz_random_10_minas[0][2]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="C2"){
				if(matriz_random_10_minas[1][2]!=9){
					matriz_char_10[1][2]=matriz_random_10_minas[1][2]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="C3"){
				if(matriz_random_10_minas[2][2]!=9){
					matriz_char_10[2][2]=matriz_random_10_minas[2][2]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="C4"){
				if(matriz_random_10_minas[3][2]!=9){
					matriz_char_10[3][2]=matriz_random_10_minas[3][2]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			
			if(jugada=="C5"){
				if(matriz_random_10_minas[4][2]!=9){
					matriz_char_10[4][2]=matriz_random_10_minas[4][2]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="C6"){
				if(matriz_random_10_minas[5][2]!=9){
					matriz_char_10[5][2]=matriz_random_10_minas[5][2]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="C7"){
				if(matriz_random_10_minas[6][2]!=9){
					matriz_char_10[6][2]=matriz_random_10_minas[6][2]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="C8"){
				if(matriz_random_10_minas[7][2]!=9){
					matriz_char_10[7][2]=matriz_random_10_minas[7][2]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="D1"){
				if(matriz_random_10_minas[0][3]!=9){
					matriz_char_10[0][3]=matriz_random_10_minas[0][3]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="D2"){
				if(matriz_random_10_minas[1][3]!=9){
					matriz_char_10[1][3]=matriz_random_10_minas[1][3]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="D3"){
				if(matriz_random_10_minas[2][3]!=9){
					matriz_char_10[2][3]=matriz_random_10_minas[2][3]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="D4"){
				if(matriz_random_10_minas[3][3]!=9){
					matriz_char_10[3][3]=matriz_random_10_minas[3][3]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="D5"){
				if(matriz_random_10_minas[4][3]!=9){
					matriz_char_10[4][3]=matriz_random_10_minas[4][3]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="D6"){
				if(matriz_random_10_minas[5][3]!=9){
					matriz_char_10[5][3]=matriz_random_10_minas[5][3]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="D7"){
				if(matriz_random_10_minas[6][3]!=9){
					matriz_char_10[6][3]=matriz_random_10_minas[6][3]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="D8"){
				if(matriz_random_10_minas[7][3]!=9){
					matriz_char_10[7][3]=matriz_random_10_minas[7][3]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="E1"){
				if(matriz_random_10_minas[0][4]!=9){
					matriz_char_10[0][4]=matriz_random_10_minas[0][4]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}	
			if(jugada=="E2"){
				if(matriz_random_10_minas[1][4]!=9){
					matriz_char_10[1][4]=matriz_random_10_minas[1][4]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="E3"){
				if(matriz_random_10_minas[2][4]!=9){
					matriz_char_10[2][4]=matriz_random_10_minas[2][4]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="E4"){
				if(matriz_random_10_minas[3][4]!=9){
					matriz_char_10[3][4]=matriz_random_10_minas[3][4]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="E5"){
				if(matriz_random_10_minas[4][4]!=9){
					matriz_char_10[4][4]=matriz_random_10_minas[4][4]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="E6"){
				if(matriz_random_10_minas[5][4]!=9){
					matriz_char_10[5][4]=matriz_random_10_minas[5][4]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="E7"){
				if(matriz_random_10_minas[6][4]!=9){
					matriz_char_10[6][4]=matriz_random_10_minas[6][4]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="E8"){
				if(matriz_random_10_minas[7][4]!=9){
					matriz_char_10[7][4]=matriz_random_10_minas[7][4]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="F1"){
				if(matriz_random_10_minas[0][5]!=9){
					matriz_char_10[0][5]=matriz_random_10_minas[0][5]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="F2"){
				if(matriz_random_10_minas[1][5]!=9){
					matriz_char_10[1][5]=matriz_random_10_minas[1][5]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="F3"){
				if(matriz_random_10_minas[2][5]!=9){
					matriz_char_10[2][5]=matriz_random_10_minas[2][5]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="F4"){
				if(matriz_random_10_minas[3][5]!=9){
					matriz_char_10[3][5]=matriz_random_10_minas[3][5]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="F5"){
				if(matriz_random_10_minas[4][5]!=9){
					matriz_char_10[4][5]=matriz_random_10_minas[4][5]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="F6"){
				if(matriz_random_10_minas[5][5]!=9){
					matriz_char_10[5][5]=matriz_random_10_minas[5][5]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="F7"){
				if(matriz_random_10_minas[6][5]!=9){
					matriz_char_10[6][5]=matriz_random_10_minas[6][5]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="F8"){
				if(matriz_random_10_minas[7][5]!=9){
					matriz_char_10[7][5]=matriz_random_10_minas[7][5]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="G1"){
				if(matriz_random_10_minas[0][6]!=9){
					matriz_char_10[0][6]=matriz_random_10_minas[0][6]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="G2"){
				if(matriz_random_10_minas[1][6]!=9){
					matriz_char_10[1][6]=matriz_random_10_minas[1][6]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="G3"){
				if(matriz_random_10_minas[2][6]!=9){
					matriz_char_10[2][6]=matriz_random_10_minas[2][6]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="G4"){
				if(matriz_random_10_minas[3][6]!=9){
					matriz_char_10[3][6]=matriz_random_10_minas[3][6]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="G5"){
				if(matriz_random_10_minas[4][6]!=9){
					matriz_char_10[4][6]=matriz_random_10_minas[4][6]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="G6"){
				if(matriz_random_10_minas[5][6]!=9){
					matriz_char_10[5][6]=matriz_random_10_minas[5][6]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="G7"){
				if(matriz_random_10_minas[6][6]!=9){
					matriz_char_10[6][6]=matriz_random_10_minas[6][6]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="G8"){
				if(matriz_random_10_minas[7][6]!=9){
					matriz_char_10[7][6]=matriz_random_10_minas[7][6]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="H1"){
				if(matriz_random_10_minas[0][7]!=9){
					matriz_char_10[0][7]=matriz_random_10_minas[0][7]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="H2"){
				if(matriz_random_10_minas[1][7]!=9){
					matriz_char_10[1][7]=matriz_random_10_minas[1][7]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="H3"){
				if(matriz_random_10_minas[2][7]!=9){
					matriz_char_10[2][7]=matriz_random_10_minas[2][7]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="H4"){
				if(matriz_random_10_minas[3][7]!=9){
					matriz_char_10[3][7]=matriz_random_10_minas[3][7]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="H5"){
				if(matriz_random_10_minas[4][7]!=9){
					matriz_char_10[4][7]=matriz_random_10_minas[4][7]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="H6"){
				if(matriz_random_10_minas[5][7]!=9){
					matriz_char_10[5][7]=matriz_random_10_minas[5][7]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="H7"){
				if(matriz_random_10_minas[6][7]!=9){
					matriz_char_10[6][7]=matriz_random_10_minas[6][7]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
			if(jugada=="H8"){
				if(matriz_random_10_minas[7][7]!=9){
					matriz_char_10[7][7]=matriz_random_10_minas[7][7]+'0';
					limpiar_casillas(matriz_char_10, matriz_random_10_minas);
					reimprimir_matriz(matriz_char_10);
				}
				else{
					cerrar_ciclo_8x8=true;
					for (int i=0; i<8; i++){
						for(int j=0; j<8; j++){
							if(matriz_random_10_minas[i][j]==9){
								matriz_char_10[i][j]='M';
							}
						}
					}
					reimprimir_matriz(matriz_char_10);
					cout<<"Usted oprimio una mina, usted perdio";
				}
			}
	}
	//Este for indica que el programa para cuando se llena la matriz de caracteres
		if(cerrar_ciclo_8x8==false){
			for (int i=0; i<8; i++){
				for (int j=0; j<8; j++){
					if (matriz_char_10[i][j]==matriz_random_10_minas[i][j]+'0'){
						cerrar_ciclo_8x8=true;
					}
					else{
					cerrar_ciclo_8x8=false;
					break;
					}
				}
			}
		}
	}
}
