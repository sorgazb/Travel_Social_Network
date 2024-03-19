/*
 * Viaje.cpp
 *
 *  Created on: 31 mar. 2022
 *      Author: alumno
 */

#include "Viaje.h"

Viaje::Viaje(){
	ciudadOrigen="";
	ciudadDestino="";
	horaSalida=0;
	id="";
}

Viaje::Viaje(string ciudadOrigen, string ciudadDestino, int horaSalida, string id) {
	this->ciudadOrigen=ciudadOrigen;
	this->ciudadDestino=ciudadDestino;
	this->horaSalida=horaSalida;
	this->id=id;
}

void Viaje::setCiudadOrigen(string ciudadOrigen) {
	this->ciudadOrigen=ciudadOrigen;
}

void Viaje::setCiudadDestino(string ciudadDestino) {
	this->ciudadDestino=ciudadDestino;
}

void Viaje::setHoraSalida(int horaSalida) {
	this->horaSalida=horaSalida;
}

void Viaje::setId(string id) {
	this->id=id;
}

string Viaje::getCiudadOrigen() {
	return ciudadOrigen;
}

string Viaje::getCiudadDestino() {
	return ciudadDestino;
}

int Viaje::getHoraSalida() {
	return horaSalida;
}

string Viaje::getId() {
	return id;
}

void Viaje::mostrar() {
	cout<<"Origen: "<<ciudadOrigen<<";"<<" Destino: "<<ciudadDestino<<";"<<" Hora: "<<horaSalida<<";"<<" Id: "<<id<<endl;
}

Viaje::~Viaje() {
	// TODO Auto-generated destructor stub
}

