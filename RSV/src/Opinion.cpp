/*
 * Opinion.cpp
 *
 *  Created on: 31 mar. 2022
 *      Author: alumno
 */

#include "Opinion.h"

Opinion::Opinion() {
	valoracion=1;
	comentario="";
}

Opinion::Opinion(int valoracion, string comentario) {
	this->valoracion=valoracion;
	this->comentario=comentario;
}

void Opinion::setValoracion(int valoracion) {
	this->valoracion=valoracion;
}

void Opinion::setComentario(string comentario) {
	this->comentario=comentario;
}

int Opinion::getValoracion() {
	return valoracion;
}

string Opinion::getComentario() {
	return comentario;
}

void Opinion::mostrar() {
	cout<<"Valoracion: "<<valoracion<<";"<<" comentario: "<<comentario<<endl;
}

Opinion::~Opinion() {
	// TODO Auto-generated destructor stub
}
