//============================================================================
// Name        : mainRSV.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "RSV.h"
#include <iostream>


using namespace std;





// Muestra el menu por pantalla y devuelve una opcion elegida.
int menu() {

	int opcion;

	do {
		cout << endl;
		cout << "______________ MENU PRINCIPAL ______________"<< endl << endl;


				cout << "     1. Insertar conductor                 " << endl;
				cout << "     2. Valorar conductor                  " << endl;
				cout << "     3. Insertar Viaje                     " << endl;
				cout << "     4. Mostrar conductores                " << endl;
				cout << "     5. Mostrar viajes                     " << endl;
				cout << "     6. Mostrar todo                       " << endl;
				cout << "     7. Buscar conductor                   " << endl;
				cout << "     8. Eliminar Conductor                 " << endl;
				cout << "     9. Cola Viajes                        " << endl;
				cout <<                                                  endl;
				cout << "     0. Finalizar.                         " << endl;
				cout << "                        Opcion:  ";
				cin >> opcion;
				cin.ignore();

	} while ((opcion < 0) || (opcion > 9));

	return opcion;
}

int main() {
	string identificador;
	string ciudadOrigen;
	string ciudadDestino;

	Cola <Viaje*> *cViajes;

	RSV *rsv;
	rsv= new RSV();
	bool terminar = false;
	int opcion;
	while (!terminar) {
		opcion = menu();

		switch (opcion) {
		case 1:
			cout<<"OPCION 1 -> INSERTAR CONDUCTOR: "<<endl;
			rsv->insertarConductor();
			break;
		case 2:
			cout<<"OPCION 2 -> VALORAR CONDUCTOR: "<<endl;
			rsv->valorarConductor();
			break;
		case 3:
			cout<<"OPCION 3 -> INSERTAR VIAJE: "<<endl;
			rsv->insertarViaje();
			break;
		case 4:
			cout<<"OPCION 4 -> MOSTRAR CONDUCTORES: "<<endl;
			rsv->mostrarConductores();
			break;
		case 5:
			cout<<"OPCION 5 -> MOSTRAR VIAJES: "<<endl;
			rsv->mostrarViajes();
			break;
		case 6:
			cout<<"OPCION 6 -> MOSTRAR TODO: "<<endl;
			cout<<"----------Lista de Conductores:----------"<<endl;
			rsv->mostrarConductores();
			cout<<"----------Lista de Viajes:----------"<<endl;
			rsv->mostrarViajes();
			break;
		case 7:
			cout<<"OPCION 7 -> BUSCAR CONDUCTOR: "<<endl;
			cout<<"Introduzca el identificador del conductor a buscar: "<<endl;
			getline(cin, identificador);
			rsv->buscarConductorConcreto(identificador);
			break;
		case 8:
			cout<<"OPCION 8 -> ELIMINAR CONDUCTOR: "<<endl;
			cout<<"Introduzca el identificador del conductor a eliminar: "<<endl;
			getline(cin,identificador);
			rsv->eliminarConductor(identificador);
			break;
		case 9:
			cout<<"OPCION 9 -> COLA VIAJES: "<<endl;
			cout<<"Introduce la ciudad de origen: "<<endl;
			getline(cin,ciudadOrigen);
			cout<<"Introduce la ciudad de destino: "<<endl;
			getline(cin,ciudadDestino);
			cViajes= new Cola <Viaje*>;
			rsv->obtenerCola(ciudadOrigen, ciudadDestino, cViajes);
			rsv->mostrarCola(cViajes);
			delete cViajes;
			break;
		case 0:
			terminar = true;
			break;

		default:
			break;

		}

	}

	return 0;


}
