/*
 * Conductor.cpp
 *
 *  Created on: 31 mar. 2022
 *      Author: alumno
 */

#include "Conductor.h"

Conductor::Conductor() {
	identificador="";
	nombre="";
	edad=0;
	marcaCoche="";
	anioAlta=0;
	this->op= new Pila <Opinion*>();
}

Conductor::Conductor(string identificador, string nombre, int edad, string marcaCoche, int anioAlta) {
	this->identificador=identificador;
	this->nombre=nombre;
	this->edad=edad;
	this->marcaCoche=marcaCoche;
	this->anioAlta=anioAlta;
	this->op= new Pila <Opinion*>();
}

void Conductor::setIdenticador(string identificador) {
	this->identificador=identificador;
}

void Conductor::setNombre(string nombre) {
	this->nombre=nombre;
}

void Conductor::setEdad(int edad) {
	this->edad=edad;
}

void Conductor::setMarcaCoche(string marcaCoche) {
	this->marcaCoche=marcaCoche;
}

void Conductor::setAnioAlta(int anioAlta) {
	this->anioAlta=anioAlta;
}

string Conductor::getIdentificador() {
	return identificador;
}

string Conductor::getNombre() {
	return nombre;
}

int Conductor::getEdad() {
	return edad;
}

string Conductor::getMarcaCoche() {
	return marcaCoche;
}

int Conductor::getAnioAlta() {
	return anioAlta;
}

void Conductor::mostrar() {
	cout<<"Identificador: "<<identificador<<";"<<"Nombre: "<<nombre<<";"<<"Edad: "<<edad<<";"<<"Marca del Coche: "<<marcaCoche<<";"<<"Año de alta: "<<anioAlta<<endl;
	cout<<"Valoración media: "<<calcularValoracionMedia()<<endl;


}

void Conductor::aniadirOpinion(int nota, string valoracion) {
	Opinion *o= new Opinion(nota,valoracion);
	this->op->apilar(o);
}

int Conductor::cuantas() {
	int cuantas=0;
	Pila <Opinion*> *aux= new Pila <Opinion*>;
	Opinion *o;
	while(!op->vacia()){
		op->cima(o);
		cuantas++;
		op->desapilar();
		aux->apilar(o);
	}
	while(!aux->vacia()){
		aux->cima(o);
		aux->desapilar();
		op->apilar(o);
	}
	delete aux;
	return cuantas;
}

void Conductor::mostrarValoraciones() {
	Pila <Opinion*> *aux= new Pila <Opinion*>;
	Opinion *o;
	while(!op->vacia()){
		op->cima(o);
		o->mostrar();
		op->desapilar();
		aux->apilar(o);
	}
	while(!aux->vacia()){
		aux->cima(o);
		aux->desapilar();
		op->apilar(o);
	}
	delete aux;
}

float Conductor::calcularValoracionMedia() {
	float total=0;
	float cont=0;
	float media;
	Pila <Opinion*> *aux= new Pila<Opinion*>();
	Opinion *o;
	while(!op->vacia()){
		op->cima(o);
		cont++;
		total=total + o->getValoracion();
		op->desapilar();
		aux->apilar(o);
	}
	while(!aux->vacia()){
		aux->cima(o);
		aux->desapilar();
		op->apilar(o);
	}
	delete aux;
	if(cont>0){
		media=total/cont;
	}
	else{
		media=0.0;
	}
	return media;
}

Conductor::~Conductor() {
	Opinion *o;
	while(!op->vacia()){
		op->cima(o);
		op->desapilar();
		delete o;
	}
	delete op;
}

