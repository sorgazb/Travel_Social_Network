/*
	ESTRUCTURAS DE DATOS Y DE LA INFORMACIÓN
	Curso 2021/2022

	Nombre: RSV.cpp
	Descripción: Implementación de la clase RSV Red Social de Viajes
	Autor:	Profesores de la asignatura
    Fecha:	7/03/2022
*/

#include "RSV.h"
RSV::RSV() {
	lc= new LPI <Conductor*>;
	lv= new LPI <Viaje*>;
	cargarDatos();
	cargarOpiniones();
	cargarViajes();
}

void RSV::cargarDatos() {
	Conductor *c;
	string id;
	string nombre;
	string edad;
	string marca;
	string anio;
	int edadInt;
	int anioInt;
	ifstream flujoConductores;
	flujoConductores.open("conductores.csv");
	if(flujoConductores.is_open()){
		while(!flujoConductores.eof()){
			getline(flujoConductores, id, ';');
			if(!flujoConductores.eof()){
				getline(flujoConductores, nombre, ';');
				getline(flujoConductores, edad, ';');
				getline(flujoConductores, marca, ';');
				getline(flujoConductores,anio);
				edadInt=stoi(edad);
				anioInt=stoi(anio);
				c= new Conductor(id, nombre, edadInt, marca, anioInt);
				if(!existe(id)){
					insertarEnOrden(id, nombre, edadInt, marca, anioInt);
				}
			}
		}
		flujoConductores.close();
	}
}

void RSV::cargarOpiniones() {
	Conductor *c;
	string id;
	string nota;
	string comentario;
	int notaInt;
	ifstream flujoOpiniones;
	flujoOpiniones.open("valoraciones.csv");
	if(flujoOpiniones.is_open()){
		while(!flujoOpiniones.eof()){
			getline(flujoOpiniones, id, ';');
			if(!flujoOpiniones.eof()){
				getline(flujoOpiniones, nota, ';');
				getline(flujoOpiniones, comentario);
				notaInt=atoi(nota.c_str());
				if(buscar(id,c)){
					c->aniadirOpinion(notaInt, comentario);
				}
			}
		}
		flujoOpiniones.close();
	}
}

void RSV::cargarViajes() {
	string ciudadOrigen;
	string ciudadDestino;
	string horaSalida;
	string id;
	int horaSalidaInt;
	ifstream flujoViajes;
	flujoViajes.open("viajes.csv");
	if(flujoViajes.is_open()){
		while(!flujoViajes.eof()){
			getline(flujoViajes, ciudadOrigen, ';');
			if(!flujoViajes.eof()){
				getline(flujoViajes, ciudadDestino, ';');
				getline(flujoViajes, horaSalida, ';');
				getline(flujoViajes, id);
				horaSalidaInt=stoi(horaSalida);
				insertarEnOrdenViaje(ciudadOrigen, ciudadDestino, horaSalidaInt, id);
			}
		}
		flujoViajes.close();
	}
}


void RSV::insertarEnOrden(string identificador, string nombre, int edad,string marcaCoche, int anioAlta) {
	Conductor *c = new Conductor( identificador,  nombre,  edad,  marcaCoche, anioAlta);
	Conductor *cAux;
	bool enc=false;
	lc->moverInicio();
	while(!lc->enUltimo() && !enc){
		lc->consultar(cAux);
		if(cAux->getIdentificador() > identificador){
			enc=true;
		}
		else{
			lc->avanzar();
		}
	}
	lc->insertar(c);
}

void RSV::insertarEnOrdenViaje(string ciudadOrigen, string ciudadDestino, int horaSalida, string id) {
	Viaje *v= new Viaje (ciudadOrigen, ciudadDestino, horaSalida, id);
	Viaje *vAux;
	bool enc=false;
	lv->moverInicio();
	while(!lv->enFin() && !enc){
		lv->consultar(vAux);
		if(vAux->getCiudadOrigen() > ciudadOrigen){
			enc=true;
		}
		else{
			if(vAux->getCiudadOrigen()==ciudadOrigen){
				if(vAux->getHoraSalida() > horaSalida){
					enc=true;
				}
				else{
					lv->avanzar();
				}
			}
			else{
				lv->avanzar();
			}
		}
	}
	lv->insertar(v);
}

bool RSV::buscar(string id, Conductor *&c) {
	Conductor *cAux;
	bool enc=false;
	lc->moverInicio();
	while(!lc->enFin() && !enc){
		lc->consultar(cAux);
		if(cAux->getIdentificador() == id){
			enc=true;
			c=cAux;
		}
		else{
			lc->avanzar();
		}
	}
	return enc;
}

void RSV::mostrarConductores() {
	Conductor *c;
	lc->moverInicio();
	while(!lc->enFin()){
		lc->consultar(c);
		c->mostrar();
		lc->avanzar();
	}
}

void RSV::mostrarViajes() {
	Viaje *v;
	lv->moverInicio();
	while(!lv->enFin()){
		lv->consultar(v);
		v->mostrar();
		lv->avanzar();
	}
}

bool RSV::existe(string identificador) {
	Conductor *c;
	bool enc=false;
	lc->moverInicio();
	while(!lc->enFin() && !enc){
		lc->consultar(c);
		if(c->getIdentificador() == identificador){
			enc=true;
		}
		else{
			lc->avanzar();
		}
	}
	return enc;
}

void RSV::insertarConductor() {
	string identificador,nombre,marca;
	int edad,anio;
	cout<<"Introduzca el identificador del conductor: "<<endl;
	getline(cin,identificador);
	cout<<"Introduzca el nombre del conductor: "<<endl;
	getline(cin,nombre);
	cout<<"Introduzca la edad del conductor: "<<endl;
	cin>>edad;
	cin.ignore();
	cout<<"Introduzca la marca del coche del conductor: "<<endl;
	getline(cin,marca);
	cout<<"Introduzca el año de alta en la aplicacion: "<<endl;
	cin>>anio;
	if(!existe(identificador)){
		insertarEnOrden(identificador, nombre, edad, marca, anio);
	}
	else{
		cout<<"Error, no se ha podido insertar. "<<endl;
	}
}

void RSV::valorarConductor() {
	string identificador;
	string comentario;
	int valoracion;
	cout<<"Introduce el identificador del conductor: "<<endl;
	getline(cin,identificador);
	cout<<"Introduce una nota para el conductor (1-10): "<<endl;
	cin>>valoracion;
	cin.ignore();
	cout<<"Introduce un comentario para el conductor: "<<endl;
	getline(cin,comentario);
	if(valoracion >=1 && valoracion <=10){
		Conductor *c;
		if(buscar(identificador, c)){
			c->aniadirOpinion(valoracion, comentario);
		}
		else{
			cout<<"No se ha encontrado a ningún conductor con ese identificador. "<<endl;
		}
	}
	else{
		cout<<"Error al introducir la nota del conductor. "<<endl;
	}
}

void RSV::insertarViaje() {
	string ciudadOrigen;
	string ciudadDestino;
	string identificador;
	int horaSalida;
	cout<<"Introduzca la ciudad de origen del viaje: "<<endl;
	getline(cin,ciudadOrigen);
	cout<<"Introduzca la ciudad de destino del viaje: "<<endl;
	getline(cin,ciudadDestino);
	cout<<"Introduzca la hora de comienzo del viaje: "<<endl;
	cin>>horaSalida;
	cin.ignore();
	cout<<"Introduzca el identificador del conductor: "<<endl;
	getline(cin,identificador);
	if(existe(identificador)){
		insertarEnOrdenViaje(ciudadOrigen, ciudadDestino, horaSalida, identificador);
	}
	else{
		cout<<"No se ha podido insertar el viaje porque no existe el conductor. "<<endl;
	}
}

void RSV::buscarConductorConcreto(string identificador) {
	Conductor *c;
	if(buscar(identificador, c)){
		c->mostrar();
		c->mostrarValoraciones();
	}
	cout<<"No se ha podido encontrar a ese conductor. "<<endl;
}

void RSV::eliminarConductor(string identificador) {
	Conductor *c;
	bool enc=false;
	lc->moverUltimo();
	while(!lc->enFin() && !enc){
		lc->consultar(c);
		if(c->getIdentificador()==identificador){
			enc=true;
			lc->borrar();
			delete c;
			eliminarViajesConductor(identificador);
		}
		else{
			lc->avanzar();
		}
	}
}

void RSV::eliminarViajesConductor(string idenficador) {
	Viaje *v;
	lv->moverInicio();
	while(!lv->enFin()){
		lv->consultar(v);
		if(v->getId()==idenficador){
			lv->borrar();
			delete v;
		}
		else{
			lv->avanzar();
		}
	}
}

void RSV::obtenerCola(string ciudadOrigen, string ciudadDestino, Cola<Viaje*> *cViaje) {
	Viaje *v;
	lv->moverInicio();
	while(!lv->enFin()){
		lv->consultar(v);
		if(v->getCiudadOrigen()==ciudadOrigen && v->getCiudadDestino()==ciudadDestino){
			cViaje->encolar(v);
		}
		lv->avanzar();
	}
}


void RSV::mostrarCola(Cola<Viaje*> *cViaje) {
	Cola <Viaje*> *caux= new Cola <Viaje*>;
	Viaje *v;
	while(!cViaje->vacia()){
		cViaje->primero(v);
		v->mostrar();
		cViaje->desencolar();
		caux->encolar(v);
	}
	while(!caux->vacia()){
		caux->primero(v);
		caux->desencolar();
		cViaje->encolar(v);
	}
	delete caux;
}

RSV::~RSV() {
	Conductor *con;
	Viaje *v;
	lc->moverInicio();
	while(!lc->vacia()){
		lc->consultar(con);
		delete con;
		lc->borrar();
	}
	delete lc;
	lv->moverInicio();
	while(!lv->vacia()){
		lv->consultar(v);
		delete v;
		lv->borrar();
	}
	delete lv;
}


