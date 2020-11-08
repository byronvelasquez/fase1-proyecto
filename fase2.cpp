#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <sstream>

using namespace std;

ifstream archivo;
ifstream leer;//archivo de lectura
ofstream auxdatos;//archivo de guardado de datos
ofstream auxtra;//guardar los datos traduciodos
string linea,a,d;
int op;
char op2[10];
void ingresodatos();
void mostrardatos();
void traduccion();

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
		case 2: mostrardatos();
				system("pause");
				system("cls");
		break;
		case 3: traduccion();
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
	cout<<"--------Datos ingresados----------\n";
	leer.open("codigo.txt",ios::in);
while (getline(leer,linea)){
	d=d+linea+"\n";
}
cout<<d<<endl;

leer.close();	
}

void traduccion(){
//variables
	string b,vector;
	string palabra,traduccion;
	string tempb;
	char c[100],f[100];
	bool encontrado=false;
	cout<<"-----------DATOS TRADUCIDOS---------"<<endl;
leer.open("codigo.txt",ios::in );
archivo.open("registro.txt",ios::in);
auxtra.open("traducido.txt",ios::out);
//lee datos del archivo y los almacena en un cadena de caracteres

archivo>>palabra;
while (getline(leer,linea)){
b=b+linea+"\n";	
}
istringstream isstream(b);
while (!isstream.eof()){
	isstream>>tempb;
	cout<<tempb<<endl;

}
if(tempb==palabra){
archivo>>traduccion;
	auxtra<<traduccion;

}else {
	auxtra<<tempb;
}

//descompone la cadena de caracteres a palabra * palabra

archivo>>palabra;
}






