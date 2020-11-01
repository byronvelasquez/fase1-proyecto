#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

ifstream leer;//archivo de lectura
ofstream auxdatos;//archivo de guardado de datos
string linea,a,b,c,d;
int op;
char op2[10];
void ingresodatos();
void mostrardatos();

int main(){
	while(1==1){	
	cout<<"--------------BIENVENIDO----------"<<endl;
	cout<<""<<endl;
	cout<<"1) Ingreso de datos"<<endl;
	cout<<"2) Mostrar datos ingresados"<<endl;
	cout<<"3) Mostrar datos traducidos"<<endl;
	cout<<"4) salir"<<endl;
	cin>>op;
	system("cls");
	switch(op){
		case 1: ingresodatos();
				system("pause");  //se realiza un pause para que el usuariso pueda visualizar los datos ingresados
		        system("cls");  //Se limpia la pantalla
		break;
		case 2: void mostrardatos();
				system("pause");
				system("cls");
		break;
		case 4:exit(-1);
		           //salida de programa
		break;	
		
}
}
return 0;
}

void ingresodatos(){
 auxdatos.open("codigo.txt",ios::out);
 int salir = 0;
 string Cadena;
cout<<"Ingrese datos que desea traducir"<<endl;
cout<<"Para dejar de ingresar datos solo ingrese: salir"<<endl;
cin.ignore();
do {
getline(cin,a);
if (a=="salir"){
	auxdatos.close();
}else
auxdatos<<a<<"\n";
}
while (a !="salir");
auxdatos.close();
}

void mostrardatos(){
	leer.open("codigo.txt",ios::in);
	if(leer.is_open()){
	while (!leer.eof()){
	getline(leer,a);
	cout<<a;
}
}
else{
	cout<<"No se puede abrir archivo";
}
leer.close();	
}
