#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <cctype>

using namespace std;

struct Nodo{  //Creamos la estructura que alamacenara nuestro datos
	string palabra;
	string traduccion;
	string funcionalidad;
	string p;
	Nodo *Siguiente;
	Nodo *Anterior;
	
}*Primer , *ultimo; //Declaramos variables tipo puntero

//se declaran los prototipos de las funciones
void IngresoDeDatos(); 
void BuscarDatos();
void ModificarDatos();
void EliminarDatos();
//cuerpo del programa
int main(){
	bool encontrado=false;
	ofstream archivo;
	string palabra, traduccion, funcionalidad, p;
	string aux;
	int Opcion; //se cra una variavle para realizar seleccion en menju
	while(1==1){  //se crea un ciclo While infinito para que se repita infinatas veces
	//Se colocan las opciones para que el usuario seleccione
	cout<<"-------------BIENVENIDO------------"<<endl;
	cout<<""<<endl;
	cout<<"Ingrese el numero de opcion que desa realizar \n";
	cout<<"1) Ingresar datos \n";
	cout<<"2) Buscar Datos \n";
	cout<<"3) Modificar Datos \n";
	cout<<"4) Eliminar Datos \n";
	cout<<"5) Salir\n";
	cin>>Opcion;
	system("cls");
	switch(Opcion){
		case 1: IngresoDeDatos(); //sen llama la funcion para insertar datos de la lista
		        system("pause");  //se realiza un pause para que el usuariso pueda visualizar los datos ingresados
		        system("cls");  //Se limpia la pantalla
		break;
		case 2: BuscarDatos();   //Se llama la funcion para buscar
		        system("pause"); //se hace pause para visualizar el dato encontrado
		        system("cls");   
		break;
		case 3: ModificarDatos();   //Se llama la funcion para buscar
		        system("pause"); //se hace pause para visualizar el dato encontrado
		        system("cls");   
		break;
		case 4:EliminarDatos();	//Se llama la funcion para eliminar datos
				system("pause");//se hace pause para visualizar el dato
				system("cls");
		break;
		case 5: exit(-1);
		           //salida de programa
		break;
		
		default: cout<<"Ingrese la opcion correcta este numero de opcion es Erroneo\n";
		break;
	}
}
	return 0;
}

void IngresoDeDatos(){  //creamos el metodo para insertar informacion en nuestra lista
	ofstream archivo;
	string palabra;
	string traduccion;
	string funcionalidad; 
	if(!archivo.is_open()){
				archivo.open("registro.txt",ios::out|ios::app);
			}
	cout<<"INGRESE PALABRA EN INGLES: \n"; //Solicitud de codigo
	cin.ignore();
	getline(cin,palabra);
	cout<<"INGRESE TRADUCCION: \n"; //Solicitud de Nombre
	getline(cin,traduccion);
	cout<<"INGRESE FUNCIONALIDAD: \n"; //Solicitud de Identificacion
	getline(cin,funcionalidad);
	archivo<<palabra<<" "<<traduccion<<" "<<funcionalidad<<"\n";
	
	cout<<"------------Datos guardados-------------\n";
	archivo.close();
	fflush(stdin);
	
	
}

void BuscarDatos(){     //Cramos la funcion para realizar una busqueda
string palabra;
char p[50];
string funcionalidad,traduccion;
bool encontrado=false;
fstream archivo;
	
	archivo.open("registro.txt",ios::in); //abrimos el archivo
	if(archivo.is_open()){
		cout <<"INGRESA PALABRA: "<<endl;
		cin>>p;
		archivo>>palabra; //lectura adelantada
		encontrado=false;
		
		while (!archivo.eof()){
			archivo>>traduccion;
			getline(archivo,funcionalidad);
			//comparara registro para ver si es encontradp
			
			if(p==palabra){
				encontrado=true;
				cout<<"Palabra: "<<palabra<<endl;
				cout<<"Traduccion: "<<traduccion<<endl;
				cout<<"Funcionalidad: "<<funcionalidad<<endl;
				cout<<"______"<<endl;
				
			}
			archivo>>palabra;
			
		}
		if(encontrado==false){
			cout<<"NO HAY REGISTRO"<<endl;
		}
		archivo.close();
	}else{
		cout<<"no se pudo abrir archivo"<<endl;
	}
	}
	
//creamos para modificar datos ingresados 
void ModificarDatos(){
	bool encontrado;
	
	ofstream aux;
	ifstream archivo ("registro.txt");
	string palabra;
	string traduccion;
	string funcionalidad;
	string auxpalabra;
	string auxTraduccion;
	string auxFuncionalidad;
	
	
	encontrado=false;
	aux.open("auxiliar.txt", ios ::out);
	if(aux.is_open()&& archivo.is_open()){
		cout<<"INGRESE PALABRA A MODIFICAR: "<<endl;
		cin>>auxpalabra;
		archivo>>palabra;
		
		while(!archivo.eof()){
			archivo>>traduccion;
			getline(archivo,funcionalidad);
			if (auxpalabra==palabra){
				encontrado=true;
				cout<<"_______________________________________"<<endl;
				cout<<"palabra: " <<palabra<<endl;
				cout<<"traduccion: " <<traduccion<<endl;
				cout<<"funcionalidad: " <<funcionalidad<<endl;	
				cout<<"-----------------------------------------"<<endl;
				cout <<"INGRESE PALABRA MODIFICADA: "<<endl;
				cin.ignore();
				getline(cin,auxpalabra);
				cout<<"Ingrese traduccion modificada"<<endl;
				getline(cin,auxTraduccion);
				cout<<"ingrese Funcionalidad modificada"<<endl;
				getline(cin,auxFuncionalidad);
				aux<<auxpalabra<<" "<<auxTraduccion<<" "<<auxFuncionalidad<<endl;
				cout<<"REGISTRO MODIFICADO TERMINADO"<<endl;
				
			}else{
				aux<<palabra<<" "<<traduccion<<" "<<funcionalidad<<endl;
			}
			archivo>>palabra;
		}
		aux.close();
		archivo.close();
	}else{
			cout<<"no se pudo abrir archivo"<<endl;
	}
	if(encontrado==false){
		cout<<"NO SE ENCONTRO NINGUN REGISTRO"<<endl;		
	}
	remove("registro.txt");
	rename("auxiliar.txt","registro.txt");
	}
	
 //ELIMANDO DATOS REGISTRADOS
void EliminarDatos(){
	bool encontrado;
	ofstream aux;
	ifstream archivo;
	string palabra;
	string traduccion;
	string funcionalidad;
	string auxpalabra;
	
	encontrado=false;
	
	aux.open("auxiliar.txt", ios ::out);
	archivo.open("registro.txt", ios::out|ios::in);
	if(aux.is_open()&& archivo.is_open()){
		cout<<"INGRESE PALABRA A ELIMINAR: "<<endl;
		cin>>auxpalabra;
		archivo>>palabra;
		
		while(!archivo.eof()){
				archivo>>traduccion;
				getline(archivo,funcionalidad);;
			if (auxpalabra==palabra){
				encontrado=true;
				cout<<"_______________________________________"<<endl;
				cout<<"palabra: " <<palabra<<endl;
				cout<<"traduccion: " <<traduccion<<endl;
				cout<<"funcionalidad: " <<funcionalidad<<endl;	
				cout<<"EL REGISTRO SE HA ELIMINADO "<<endl;
			}else{
				aux<<palabra<<" "<<traduccion<<" "<<funcionalidad<<"\n";
			}
			archivo>>palabra;
		}
	}
	if(encontrado==false){
		cout<<"NO SE ENCONTRO NINGUN REGISTRO"<<endl;		
	}
	aux.close();
	archivo.close();
	remove("registro.txt");
	rename("auxiliar.txt","registro.txt");
}

	
	
	
