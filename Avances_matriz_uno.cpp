#include<iostream>
#include<ctime>
#include<cmath>
#include<string>
#include<windows.h>
#include<conio.h>
using namespace std;
//Declaré las variables auxiliares globales para guardar las matrices que se procesen en las funciones
int matriz_random_10_minas[8][8]={0};
int matriz_random_40_minas[16][16]={0};
int matriz_random_80_minas[16][26]={0};
int segundos=0;
int minutos=0;
int horas=0;
void imprimir_tablero(int matriz[16][16]){
	for (int i=0; i<16; i++){
		for (int j=0; j<16; j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}

void poner_a_cero_8(int matriz[8][8]){
	for(int i=0; i<8; i++){
		for(int j=0; j <8; j++){
			matriz[i][j]=0;
		}
	}
}
void poner_a_cero_16(int matriz[16][16]){
	for(int i=0; i<16; i++){
		for(int j=0; j <16; j++){
			matriz[i][j]=0;
		}
	}
}
void poner_a_cero_26(int matriz[16][26]){
	for(int i=0; i<16; i++){
		for(int j=0; j <26; j++){
			matriz[i][j]=0;
		}
	}
}
//Esta función generará minas en espacios aleatorios de cada matriz
void matriz_num_aleatorio(int filas, int columnas){
//La función srand permite crear el número aleatorio, inicializé con time(NULL) que equivale a los segundos transcurridos desde el 1 de enero 1970, sin meterlo en una variable.
	int tablero [filas][columnas]={0};
	int maximo=filas*columnas;
	if (maximo==64){
		poner_a_cero_8(matriz_random_10_minas);
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
		poner_a_cero_16(matriz_random_40_minas);
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
		if (maximo==416){
			poner_a_cero_26(matriz_random_80_minas);
		for (int i=0; i<80; i++){
			//El ciclo va hasta 80 ya que es el número de minas que quiero para una matriz de 30*16, los números aleatorios de deben inicializr de nuevo en cada ciclo
			int aleatorio_filas=rand()%filas;
			int aleatorio_columnas=rand()%columnas;
			//cada 9 repreenta una mina, posteriormente esto cambiara cuando se desarrolle la parte que se muestra al usuario
			//En caso de que la casilla ya tenga una mina, resté 1 a la variable de conteo e inicializé el contador nuevamente
			if(tablero[aleatorio_filas][aleatorio_columnas]!=9){
				tablero[aleatorio_filas][aleatorio_columnas]=9;
				matriz_random_80_minas[aleatorio_filas][aleatorio_columnas]=tablero[aleatorio_filas][aleatorio_columnas];
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
void asignar_casillas_16x26(int matriz_1[16][26]){
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
	if (matriz_1[0][25]!=9){
		int i=0;
		if(matriz_1[0][24]==9){
			i++;
		}
		if(matriz_1[1][25]==9){
			i++;
		}
		if(matriz_1[1][24]==9){
			i++;
		}
		matriz_1[0][25]=i;
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
	if (matriz_1[15][25]!=9){
		int i=0;
		if(matriz_1[15][24]==9){
			i++;
		}
		if(matriz_1[14][25]==9){
			i++;
		}
		if(matriz_1[14][24]==9){
			i++;
		}
		matriz_1[15][25]=i;
	}
	for (int i=1; i<25; i++){
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
	for (int i=1; i<25; i++){
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
		if (matriz_1[i][25]!=9){
			int j=0;
			if (matriz_1[i-1][25]==9){
				j++;
			}
			if (matriz_1[i+1][25]==9){
				j++;
			}
			if (matriz_1[i+1][24]==9){
				j++;
			}
			if (matriz_1[i-1][24]==9){
				j++;
			}
			if (matriz_1[i][24]==9){
				j++;
			}
			matriz_1[i][25]=j;
		}
	}
	for (int i=1; i<15; i++){
		for(int j=1; j<25; j++){
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
void reimprimir_matriz_8(char matriz[8][8]){
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
void reimprimir_matriz_16(char matriz[16][16]){
	cout<<"   "<<"A"<<" "<<"B"<<" "<<"C"<<" "<<"D"<<" "<<"E"<<" "<<"F"<<" "<<"G"<<" "<<"H"<<" "<<"I"<<" "<<"J"<<" "<<"K"<<" "<<"L"<<" "<<"M"<<" "<<"N"<<" "<<"O"<<" "<<"P"<<endl;
	cout<<"1  ";
	for (int i=0; i<16; i++){
		cout<<matriz[0][i]<<" ";
	}	
	cout<<endl;	
	cout<<"2  ";
	for (int i=0; i<16; i++){
		cout<<matriz[1][i]<<" ";
	}
	cout<<endl;	
	cout<<"3  ";
	for (int i=0; i<16; i++){
		cout<<matriz[2][i]<<" ";
	}	
	cout<<endl;	
	cout<<"4  ";	
	for (int i=0; i<16; i++){
		cout<<matriz[3][i]<<" ";
	}
	cout<<endl;	
	cout<<"5  ";		
	for (int i=0; i<16; i++){
		cout<<matriz[4][i]<<" ";
	}	
	cout<<endl;		
	cout<<"6  ";
	for (int i=0; i<16; i++){
		cout<<matriz[5][i]<<" ";
	}	
	cout<<endl;		
	cout<<"7  ";
	for (int i=0; i<16; i++){
		cout<<matriz[6][i]<<" ";
	}
	cout<<endl;	
	cout<<"8  ";		
	for (int i=0; i<16; i++){
		cout<<matriz[7][i]<<" ";
	}
	cout<<endl;	
	cout<<"9  ";		
	for (int i=0; i<16; i++){
		cout<<matriz[8][i]<<" ";
	}
	cout<<endl;	
	cout<<"10 ";		
	for (int i=0; i<16; i++){
		cout<<matriz[9][i]<<" ";
	}
	cout<<endl;	
	cout<<"11 ";		
	for (int i=0; i<16; i++){
		cout<<matriz[10][i]<<" ";
	}
	cout<<endl;	
	cout<<"12 ";		
	for (int i=0; i<16; i++){
		cout<<matriz[11][i]<<" ";
	}
	cout<<endl;	
	cout<<"13 ";		
	for (int i=0; i<16; i++){
		cout<<matriz[12][i]<<" ";
	}
	cout<<endl;	
	cout<<"14 ";		
	for (int i=0; i<16; i++){
		cout<<matriz[13][i]<<" ";
	}
	cout<<endl;	
	cout<<"15 ";		
	for (int i=0; i<16; i++){
		cout<<matriz[14][i]<<" ";
	}
	cout<<endl;	
	cout<<"16 ";		
	for (int i=0; i<16; i++){
		cout<<matriz[15][i]<<" ";
	}
}
void reimprimir_matriz_26(char matriz[16][26]){
	cout<<"   "<<"A"<<" "<<"B"<<" "<<"C"<<" "<<"D"<<" "<<"E"<<" "<<"F"<<" "<<"G"<<" "<<"H"<<" "<<"I"<<" "<<"J"<<" "<<"K"<<" "<<"L"<<" "<<"M"<<" "<<"N"<<" "<<"O"<<" "<<"P"<<" "<<"Q"<<" "<<"R"<<" "<<"S"<<" "<<"T"<<" "<<"U"<<" "<<"V"<<" "<<"W"<<" "<<"X"<<" "<<"Y"<<" "<<"Z"<<endl;
	cout<<"1  ";
	for (int i=0; i<26; i++){
		cout<<matriz[0][i]<<" ";
	}	
	cout<<endl;	
	cout<<"2  ";
	for (int i=0; i<26; i++){
		cout<<matriz[1][i]<<" ";
	}
	cout<<endl;	
	cout<<"3  ";
	for (int i=0; i<26; i++){
		cout<<matriz[2][i]<<" ";
	}	
	cout<<endl;	
	cout<<"4  ";	
	for (int i=0; i<26; i++){
		cout<<matriz[3][i]<<" ";
	}
	cout<<endl;	
	cout<<"5  ";		
	for (int i=0; i<26; i++){
		cout<<matriz[4][i]<<" ";
	}	
	cout<<endl;		
	cout<<"6  ";
	for (int i=0; i<26; i++){
		cout<<matriz[5][i]<<" ";
	}	
	cout<<endl;		
	cout<<"7  ";
	for (int i=0; i<26; i++){
		cout<<matriz[6][i]<<" ";
	}
	cout<<endl;	
	cout<<"8  ";		
	for (int i=0; i<26; i++){
		cout<<matriz[7][i]<<" ";
	}
	cout<<endl;	
	cout<<"9  ";		
	for (int i=0; i<26; i++){
		cout<<matriz[8][i]<<" ";
	}
	cout<<endl;	
	cout<<"10 ";		
	for (int i=0; i<26; i++){
		cout<<matriz[9][i]<<" ";
	}
	cout<<endl;	
	cout<<"11 ";		
	for (int i=0; i<26; i++){
		cout<<matriz[10][i]<<" ";
	}
	cout<<endl;	
	cout<<"12 ";		
	for (int i=0; i<26; i++){
		cout<<matriz[11][i]<<" ";
	}
	cout<<endl;	
	cout<<"13 ";		
	for (int i=0; i<26; i++){
		cout<<matriz[12][i]<<" ";
	}
	cout<<endl;	
	cout<<"14 ";		
	for (int i=0; i<26; i++){
		cout<<matriz[13][i]<<" ";
	}
	cout<<endl;	
	cout<<"15 ";		
	for (int i=0; i<26; i++){
		cout<<matriz[14][i]<<" ";
	}
	cout<<endl;	
	cout<<"16 ";		
	for (int i=0; i<26; i++){
		cout<<matriz[15][i]<<" ";
	}
}
//A continuación añadí una función recursiva que recorre la matriz y muestra los espacios adyacentes vacios: Si se oprime o muestra un 0, se mostrará todas las casillas adyacentes, de esta forma, todas las casillas son números distintos de 0 o números.
void limpiar_casillas_8(char matriz[8][8], int matriz_int [8][8]){
	for (int c=0; c<8; c++){
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
			matriz[6][0]=matriz_int[6][0]+'0';
			matriz[7][1]=matriz_int[7][1]+'0';
			matriz[6][1]=matriz_int[6][1]+'0';
		}
		if (matriz[0][7]=='0'){
			matriz[0][6]=matriz_int[0][6]+'0';
			matriz[1][7]=matriz_int[1][7]+'0';
			matriz[1][6]=matriz_int[1][6]+'0';
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
void limpiar_casillas_16(char matriz[16][16], int matriz_int [16][16]){
	for (int c=0; c<16; c++){
		if (matriz[0][0]=='0'){
			matriz[0][1]=matriz_int[0][1]+'0';
			matriz[1][0]=matriz_int[1][0]+'0';
			matriz[1][1]=matriz_int[1][1]+'0';
		}
		if (matriz[15][15]=='0'){
			matriz[15][14]=matriz_int[15][14]+'0';
			matriz[14][14]=matriz_int[14][14]+'0';
			matriz[14][15]=matriz_int[14][15]+'0';
		}
		if (matriz[15][0]=='0'){
			matriz[14][0]=matriz_int[14][0]+'0';
			matriz[15][1]=matriz_int[15][1]+'0';
			matriz[14][1]=matriz_int[14][1]+'0';
		}
		if (matriz[0][15]=='0'){
			matriz[0][14]=matriz_int[0][14]+'0';
			matriz[1][15]=matriz_int[1][15]+'0';
			matriz[1][14]=matriz_int[1][14]+'0';
		}
		for (int i=1; i<15; i++){
			if (matriz[0][i]=='0'){
				matriz[0][i-1]=matriz_int[0][i-1]+'0';
				matriz[0][i+1]=matriz_int[0][i+1]+'0';
				matriz[1][i-1]=matriz_int[1][i-1]+'0';
				matriz[1][i+1]=matriz_int[1][i+1]+'0';
				matriz[1][i]=matriz_int[1][i]+'0';
			}
		}
		for (int i=1; i<15; i++){
			if (matriz[15][i]=='0'){
				matriz[15][i-1]=matriz_int[15][i-1]+'0';
				matriz[15][i+1]=matriz_int[15][i+1]+'0';
				matriz[14][i-1]=matriz_int[14][i-1]+'0';
				matriz[14][i+1]=matriz_int[14][i+1]+'0';
				matriz[14][i]=matriz_int[14][i]+'0';
			}
		}
		for (int i=1; i<15; i++){
			if (matriz[i][0]=='0'){
				matriz[i-1][0]=matriz_int[i-1][0]+'0';
				matriz[i+1][0]=matriz_int[i+1][0]+'0';
				matriz[i-1][1]=matriz_int[i-1][1]+'0';
 				matriz[i+1][1]=matriz_int[i+1][1]+'0';
				matriz[i][1]=matriz_int[i][1]+'0';
			}
		}
		for (int i=1; i<15; i++){
			if (matriz[i][15]=='0'){
				matriz[i-1][15]=matriz_int[i-1][15]+'0';
				matriz[i+1][15]=matriz_int[i+1][15]+'0';
				matriz[i-1][14]=matriz_int[i-1][14]+'0';
				matriz[i+1][14]=matriz_int[i+1][14]+'0';
				matriz[i][14]=matriz_int[i][14]+'0';
			}
		}
		for (int i=1; i<15; i++){
			for(int j=1; j<15; j++){
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
void limpiar_casillas_26(char matriz[16][26], int matriz_int [16][26]){
	for (int c=0; c<26; c++){
		if (matriz[0][0]=='0'){
			matriz[0][1]=matriz_int[0][1]+'0';
			matriz[1][0]=matriz_int[1][0]+'0';
			matriz[1][1]=matriz_int[1][1]+'0';
		}
		if (matriz[15][25]=='0'){
			matriz[15][24]=matriz_int[15][24]+'0';
			matriz[14][24]=matriz_int[14][24]+'0';
			matriz[14][25]=matriz_int[14][25]+'0';
		}
		if (matriz[15][0]=='0'){
			matriz[14][0]=matriz_int[14][0]+'0';
			matriz[15][1]=matriz_int[15][1]+'0';
			matriz[14][1]=matriz_int[14][1]+'0';
		}
		if (matriz[0][25]=='0'){
			matriz[0][24]=matriz_int[0][24]+'0';
			matriz[1][25]=matriz_int[1][25]+'0';
			matriz[1][24]=matriz_int[1][24]+'0';
		}
		for (int i=1; i<25; i++){
			if (matriz[0][i]=='0'){
				matriz[0][i-1]=matriz_int[0][i-1]+'0';
				matriz[0][i+1]=matriz_int[0][i+1]+'0';
				matriz[1][i-1]=matriz_int[1][i-1]+'0';
				matriz[1][i+1]=matriz_int[1][i+1]+'0';
				matriz[1][i]=matriz_int[1][i]+'0';
			}
		}
		for (int i=1; i<25; i++){
			if (matriz[15][i]=='0'){
				matriz[15][i-1]=matriz_int[15][i-1]+'0';
				matriz[15][i+1]=matriz_int[15][i+1]+'0';
				matriz[14][i-1]=matriz_int[14][i-1]+'0';
				matriz[14][i+1]=matriz_int[14][i+1]+'0';
				matriz[14][i]=matriz_int[14][i]+'0';
			}
		}
		for (int i=1; i<15; i++){
			if (matriz[i][0]=='0'){
				matriz[i-1][0]=matriz_int[i-1][0]+'0';
				matriz[i+1][0]=matriz_int[i+1][0]+'0';
				matriz[i-1][1]=matriz_int[i-1][1]+'0';
 				matriz[i+1][1]=matriz_int[i+1][1]+'0';
				matriz[i][1]=matriz_int[i][1]+'0';
			}
		}
		for (int i=1; i<15; i++){
			if (matriz[i][25]=='0'){
				matriz[i-1][25]=matriz_int[i-1][25]+'0';
				matriz[i+1][25]=matriz_int[i+1][25]+'0';
				matriz[i-1][24]=matriz_int[i-1][24]+'0';
				matriz[i+1][24]=matriz_int[i+1][24]+'0';
				matriz[i][24]=matriz_int[i][24]+'0';
			}
		}
		for (int i=1; i<15; i++){
			for(int j=1; j<25; j++){
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
int main (){
	srand(time(NULL));
	cout<<"BUSCAMINAS"<<endl<<"Escoja el nivel que desea jugar"<<endl<<"Oprima 1 para facil (8x8)"<<endl<<"Oprima 2 para medio (16x16)"<<endl<<"Oprima 3 para dificil (16x30)"<<endl;
	int nivel;
	cout<<"Escoja un nivel: "<<endl;
	cin>>nivel;
	system("cls");
	while(nivel<1 || nivel>3){
		cout<<"Solo puede escoger un nivel escribiendo un numero del 1 al 3"<<endl<<"Escoja un nivel: "<<endl;
		cin>>nivel;
	}
	if(nivel==1){
		int jugadas=0;
		int pos_fila;
		int pos_columna;
		cout<<"Este es un buscaminas de 8x8, contiene 10 minas"<<endl<<"Escribir una coordenada en mayuscula para destapar la casilla y en minuscula para colocar una bandera sobre una mina"<<endl;
		cout<<"Sistema coordenado:"<<endl;
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
		int num_minas=10;
		//Dentro de este ciclo se piden las jugadas del usuario
		while (cerrar_ciclo_8x8==false){
			string jugada;
			cout<<endl<<"Minas: "<<num_minas;
			cout<<endl<<"Escriba una casilla: ";
			cin>>jugada;
			system("cls");
			//Instructivo si el usuario ingresa coordenadas no válidas
			if (((jugada[0]>='a' && jugada[0]<='h')||(jugada[0]>='A' && jugada[0]<='H'))&&(jugada[1]>='0' && jugada[1]<='8')){
				switch(jugada[0]){
					case 'A': pos_columna=0;
						 break;
					case 'B': pos_columna=1;
						break;
					case 'C': pos_columna=2;
						break;
					case 'D': pos_columna=3;
						break;
					case 'E': pos_columna=4;
						break;
					case 'F': pos_columna=5;
						break;
					case 'G': pos_columna=6;
						break;
					case 'H': pos_columna=7;
						break;
					case 'a': pos_columna=0;
						 break;
					case 'b': pos_columna=1;
						break;
					case 'c': pos_columna=2;
						break;
					case 'd': pos_columna=3;
						break;
					case 'e': pos_columna=4;
						break;
					case 'f': pos_columna=5;
						break;
					case 'g': pos_columna=6;
						break;
					case 'h': pos_columna=7;
						break;
				}
				pos_fila=(jugada[1]-'0')-1;
			//En estos condicionales se cambia el espacio de las matrices, dependiendo de la coordenada escrita.
			//El +'0' que se ve al final de la segunda matriz indica que es un entero que se cambia a char para poder ingresarlo en la segunda matriz
				if(jugada[0]>='A' && jugada[0]<='H'){
					if(jugadas==0){
						while(matriz_random_10_minas[pos_fila][pos_columna]!=0){
							matriz_num_aleatorio(8, 8);
							asignar_casillas_8x8(matriz_random_10_minas);
						}
					}
					if(matriz_random_10_minas[pos_fila][pos_columna]!=9){
						matriz_char_10[pos_fila][pos_columna]=matriz_random_10_minas[pos_fila][pos_columna]+'0';
						limpiar_casillas_8(matriz_char_10, matriz_random_10_minas);
						reimprimir_matriz_8(matriz_char_10);
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
						reimprimir_matriz_8(matriz_char_10);
						cout<<"Usted oprimio una mina, usted perdio";
					}
				}
				if(jugada[0]>='a' && jugada[0]<='h'){
					if(jugadas==0){
						jugadas--;
					}
					if(matriz_char_10[pos_fila][pos_columna]=='X'|| matriz_char_10[pos_fila][pos_columna]=='b'){
						if(matriz_char_10[pos_fila][pos_columna]=='X'){
							matriz_char_10[pos_fila][pos_columna]='b';
							reimprimir_matriz_8(matriz_char_10);
							if(num_minas>0){
								num_minas--;
							}
						}
						else {
							if (matriz_char_10[pos_fila][pos_columna]=='b'){
								matriz_char_10[pos_fila][pos_columna]='X';
								reimprimir_matriz_8(matriz_char_10);
								num_minas++;
							}
						}
					}
					else{
						cout<<endl<<"Este numero ya esta marcado como un espacio libre de minas"<<endl;
						reimprimir_matriz_8(matriz_char_10);
					}
				}
		//Este for indica que el programa para cuando se llena la matriz de caracteres
			if(cerrar_ciclo_8x8==false){
				for (int i=0; i<8; i++){
					for (int j=0; j<8; j++){
						if (matriz_char_10[i][j]!='X'){
							cerrar_ciclo_8x8=true;
						}
						else{
						cerrar_ciclo_8x8=false;
						break;
						}
					}
					if (cerrar_ciclo_8x8==false){
						break;
					}
				}
				if(cerrar_ciclo_8x8==true){
					cout<<endl<<"¡Felicidades usted ha ganado el nivel facil!"<<endl;
				}
			}
			jugadas++;
			}
			else{
				cout<<"Casilla del tablero no valida, intente otra vez, escribiendo las coordenadas como se muestran en el tablero"<<endl;	
				reimprimir_matriz_8(matriz_char_10);
			}
		}
	}
	if(nivel==2){
		int jugadas=0;
		int pos_fila;
		int pos_columna;
		cout<<"Este es un buscaminas de 16x16, contiene 40 minas"<<endl<<"Escribir una coordenada en mayuscula para destapar la casilla y en minuscula para colocar una bandera sobre una mina"<<endl;
		cout<<"Sistema coordenado:"<<endl;
		cout<<"   "<<"A"<<" "<<"B"<<" "<<"C"<<" "<<"D"<<" "<<"E"<<" "<<"F"<<" "<<"G"<<" "<<"H"<<" "<<"I"<<" "<<"J"<<" "<<"K"<<" "<<"L"<<" "<<"M"<<" "<<"N"<<" "<<"O"<<" "<<"P"<<endl;
		cout<<" 1"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 2"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 3"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 4"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 5"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 6"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 7"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 8"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 9"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"10"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"11"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"12"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"13"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"14"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"15"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"16"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		matriz_num_aleatorio(16, 16);
		asignar_casillas_16x16(matriz_random_40_minas);
		bool cerrar_ciclo_16x16=false;
		char matriz_char_40[16][16]={
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		};
		int num_minas=40;
		while(cerrar_ciclo_16x16==false){
			string jugada;
			cout<<endl<<"Minas: "<<num_minas;
			cout<<endl<<"Escriba una casilla: ";
			cin>>jugada;
			system("cls");
			if (((jugada[0]>='a' && jugada[0]<='p')||(jugada[0]>='A' && jugada[0]<='P'))&&(jugada[1]>='0' && jugada[1]<='16')){
				switch(jugada[0]){
					case 'A': pos_columna=0;
						 break;
					case 'B': pos_columna=1;
						break;
					case 'C': pos_columna=2;
						break;
					case 'D': pos_columna=3;
						break;
					case 'E': pos_columna=4;
						break;
					case 'F': pos_columna=5;
						break;
					case 'G': pos_columna=6;
						break;
					case 'H': pos_columna=7;
						break;
					case 'I': pos_columna=8;
						 break;
					case 'J': pos_columna=9;
						break;
					case 'K': pos_columna=10;
						break;
					case 'L': pos_columna=11;
						break;
					case 'M': pos_columna=12;
						break;
					case 'N': pos_columna=13;
						break;
					case 'O': pos_columna=14;
						break;
					case 'P': pos_columna=15;
						break;
					case 'a': pos_columna=0;
						 break;
					case 'b': pos_columna=1;
						break;
					case 'c': pos_columna=2;
						break;
					case 'd': pos_columna=3;
						break;
					case 'e': pos_columna=4;
						break;
					case 'f': pos_columna=5;
						break;
					case 'g': pos_columna=6;
						break;
					case 'h': pos_columna=7;
						break;
					case 'i': pos_columna=8;
						 break;
					case 'j': pos_columna=9;
						break;
					case 'k': pos_columna=10;
						break;
					case 'l': pos_columna=11;
						break;
					case 'm': pos_columna=12;
						break;
					case 'n': pos_columna=13;
						break;
					case 'o': pos_columna=14;
						break;
					case 'p': pos_columna=15;
						break;
				}
				pos_fila=(jugada[1]-'0')-1;
				switch(jugada[2]){
					case '0': pos_fila=9;
						break;
					case '1': pos_fila=10;
						break;
					case '2': pos_fila=11;
						break;
					case '3': pos_fila=12;
						break;
					case '4': pos_fila=13;
						break;
					case '5': pos_fila=14;
						break;
					case '6': pos_fila=15;
						break;
				}
				
				if(jugada[0]>='A' && jugada[0]<='P'){
					if(jugadas==0){
						while(matriz_random_40_minas[pos_fila][pos_columna]!=0){
							matriz_num_aleatorio(16, 16);
							asignar_casillas_16x16(matriz_random_40_minas);
						}
					}
					if(matriz_random_40_minas[pos_fila][pos_columna]!=9){
						matriz_char_40[pos_fila][pos_columna]=matriz_random_40_minas[pos_fila][pos_columna]+'0';
						limpiar_casillas_16(matriz_char_40, matriz_random_40_minas);
						reimprimir_matriz_16(matriz_char_40);
					}
					else{
						cerrar_ciclo_16x16=true;
						for (int i=0; i<16; i++){
							for(int j=0; j<16; j++){
								if(matriz_random_40_minas[i][j]==9){
									matriz_char_40[i][j]='M';
								}
							}
						}
						reimprimir_matriz_16(matriz_char_40);
						cout<<"Usted oprimio una mina, usted perdio";
					}
				}
				if(jugada[0]>='a' && jugada[0]<='p'){
					if(jugadas==0){
						jugadas--;
					}
					if(matriz_char_40[pos_fila][pos_columna]=='X'|| matriz_char_40[pos_fila][pos_columna]=='b'){
						if(matriz_char_40[pos_fila][pos_columna]=='X'){
							matriz_char_40[pos_fila][pos_columna]='b';
							reimprimir_matriz_16(matriz_char_40);
							if (num_minas>0){
								num_minas--;
							}
						}
						else {
							if (matriz_char_40[pos_fila][pos_columna]=='b'){
								matriz_char_40[pos_fila][pos_columna]='X';
								reimprimir_matriz_16(matriz_char_40);
								num_minas++;
							}
						}
					}
					else{
						cout<<endl<<"Este numero ya esta marcado como un espacio libre de minas"<<endl;
						reimprimir_matriz_16(matriz_char_40);
					}
				}
				if(cerrar_ciclo_16x16==false){
					for (int i=0; i<16; i++){
						for (int j=0; j<16; j++){
							if (matriz_char_40[i][j]!='X'){
								cerrar_ciclo_16x16=true;
							}
							else{
								cerrar_ciclo_16x16=false;
								break;
							}
						}
						if (cerrar_ciclo_16x16==false){
							break;
						}
					}
					if(cerrar_ciclo_16x16==true){
						cout<<endl<<"¡Felicidades usted ha ganado el nivel medio!"<<endl;
					}
				}
				jugadas++;
			}
			else{
				cout<<"Casilla del tablero no valida, intente otra vez, escribiendo las coordenadas como se muestran en el tablero"<<endl;	
				reimprimir_matriz_16(matriz_char_40);
			}
		}		
	}
	if(nivel==3){
		int jugadas=0;
		int pos_fila;
		int pos_columna;
		cout<<"Este es un buscaminas de 16x30, contiene 40 minas"<<endl<<"Escribir una coordenada, en mayuscula para destapar la casilla y en minuscula para colocar una bandera sobre una mina"<<endl;
		cout<<"Sistema coordenado:"<<endl;
		cout<<"   "<<"A"<<" "<<"B"<<" "<<"C"<<" "<<"D"<<" "<<"E"<<" "<<"F"<<" "<<"G"<<" "<<"H"<<" "<<"I"<<" "<<"J"<<" "<<"K"<<" "<<"L"<<" "<<"M"<<" "<<"N"<<" "<<"O"<<" "<<"P"<<" "<<"Q"<<" "<<"R"<<" "<<"S"<<" "<<"T"<<" "<<"U"<<" "<<"V"<<" "<<"W"<<" "<<"X"<<" "<<"Y"<<" "<<"Z"<<endl;
		cout<<" 1"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 2"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 3"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 4"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 5"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 6"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 7"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 8"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<" 9"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"10"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"11"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"12"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"13"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"14"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"15"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		cout<<"16"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<" "<<"X"<<endl;
		matriz_num_aleatorio(16, 26);
		asignar_casillas_16x26(matriz_random_80_minas);
		bool cerrar_ciclo_16x26=false;
		char matriz_char_80[16][26]={
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
		    {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
		};
		int num_minas=80;
		while(cerrar_ciclo_16x26==false){
			string jugada;
			cout<<endl<<"Minas: "<<num_minas;
			cout<<endl<<"Escriba una casilla: ";
			cin>>jugada;
			system("cls");
			if (((jugada[0]>='a' && jugada[0]<='z')||(jugada[0]>='A' && jugada[0]<='Z'))&&(jugada[1]>='0' && jugada[1]<='16')){
				switch(jugada[0]){
					case 'A': pos_columna=0;
						 break;
					case 'B': pos_columna=1;
						break;
					case 'C': pos_columna=2;
						break;
					case 'D': pos_columna=3;
						break;
					case 'E': pos_columna=4;
						break;
					case 'F': pos_columna=5;
						break;
					case 'G': pos_columna=6;
						break;
					case 'H': pos_columna=7;
						break;
					case 'I': pos_columna=8;
						 break;
					case 'J': pos_columna=9;
						break;
					case 'K': pos_columna=10;
						break;
					case 'L': pos_columna=11;
						break;
					case 'M': pos_columna=12;
						break;
					case 'N': pos_columna=13;
						break;
					case 'O': pos_columna=14;
						break;
					case 'P': pos_columna=15;
						break;
					case 'Q': pos_columna=16;
						 break;
					case 'R': pos_columna=17;
						break;
					case 'S': pos_columna=18;
						break;
					case 'T': pos_columna=19;
						break;
					case 'U': pos_columna=20;
						break;
					case 'V': pos_columna=21;
						break;
					case 'W': pos_columna=22;
						break;
					case 'X': pos_columna=23;
						break;
					case 'Y': pos_columna=24;
						 break;
					case 'Z': pos_columna=25;
						break;
					case 'a': pos_columna=0;
						 break;
					case 'b': pos_columna=1;
						break;
					case 'c': pos_columna=2;
						break;
					case 'd': pos_columna=3;
						break;
					case 'e': pos_columna=4;
						break;
					case 'f': pos_columna=5;
						break;
					case 'g': pos_columna=6;
						break;
					case 'h': pos_columna=7;
						break;
					case 'i': pos_columna=8;
						 break;
					case 'j': pos_columna=9;
						break;
					case 'k': pos_columna=10;
						break;
					case 'l': pos_columna=11;
						break;
					case 'm': pos_columna=12;
						break;
					case 'n': pos_columna=13;
						break;
					case 'o': pos_columna=14;
						break;
					case 'p': pos_columna=15;
						break;
					case 'q': pos_columna=16;
						 break;
					case 'r': pos_columna=17;
						break;
					case 's': pos_columna=18;
						break;
					case 't': pos_columna=19;
						break;
					case 'u': pos_columna=20;
						break;
					case 'v': pos_columna=21;
						break;
					case 'w': pos_columna=22;
						break;
					case 'x': pos_columna=23;
						break;
					case 'y': pos_columna=24;
						 break;
					case 'z': pos_columna=25;
						break;
				}
				pos_fila=(jugada[1]-'0')-1;
				switch(jugada[2]){
					case '0': pos_fila=9;
						break;
					case '1': pos_fila=10;
						break;
					case '2': pos_fila=11;
						break;
					case '3': pos_fila=12;
						break;
					case '4': pos_fila=13;
						break;
					case '5': pos_fila=14;
						break;
					case '6': pos_fila=15;
						break;
				}
				if(jugada[0]>='A' && jugada[0]<='Z'){
					if(jugadas==0){
						while(matriz_random_80_minas[pos_fila][pos_columna]!=0){
							matriz_num_aleatorio(16, 26);
							asignar_casillas_16x26(matriz_random_80_minas);
						}
					}
					if(matriz_random_80_minas[pos_fila][pos_columna]!=9){
						matriz_char_80[pos_fila][pos_columna]=matriz_random_80_minas[pos_fila][pos_columna]+'0';
						limpiar_casillas_26(matriz_char_80, matriz_random_80_minas);
						reimprimir_matriz_26(matriz_char_80);
					}
					else{
						cerrar_ciclo_16x26=true;
						for (int i=0; i<16; i++){
							for(int j=0; j<26; j++){
								if(matriz_random_80_minas[i][j]==9){
									matriz_char_80[i][j]='M';
								}
							}
						}
						reimprimir_matriz_26(matriz_char_80);
						cout<<"Usted oprimio una mina, usted perdio";
					}
				}
				if(jugada[0]>='a' && jugada[0]<='p'){
					if(jugadas==0){
						jugadas--;
					}
					if(matriz_char_80[pos_fila][pos_columna]=='X'|| matriz_char_80[pos_fila][pos_columna]=='b'){
						if(matriz_char_80[pos_fila][pos_columna]=='X'){
							matriz_char_80[pos_fila][pos_columna]='b';
							reimprimir_matriz_26(matriz_char_80);
							if(num_minas>0){
								num_minas--;
							}
						}
						else {
							if (matriz_char_80[pos_fila][pos_columna]=='b'){
								matriz_char_80[pos_fila][pos_columna]='X';
								reimprimir_matriz_26(matriz_char_80);
								num_minas++;
							}
						}
					}
					else{
						cout<<endl<<"Este numero ya esta marcado como un espacio libre de minas"<<endl;
						reimprimir_matriz_26(matriz_char_80);
					}
				}
				if(cerrar_ciclo_16x26==false){
					for (int i=0; i<16; i++){
						for (int j=0; j<26; j++){
							if (matriz_char_80[i][j]!='X'){
								cerrar_ciclo_16x26=true;
							}
							else{
								cerrar_ciclo_16x26=false;
								break;
							}
						}
						if (cerrar_ciclo_16x26==false){
							break;
						}
					}
					if(cerrar_ciclo_16x26==true){
						cout<<endl<<"¡Felicidades usted ha ganado el nivel medio!"<<endl;
					}
				}
				jugadas++;
			}
			else{
				cout<<"Casilla del tablero no valida, intente otra vez, escribiendo las coordenadas como se muestran en el tablero"<<endl;	
				reimprimir_matriz_26(matriz_char_80);
			}
		}
	}
}
