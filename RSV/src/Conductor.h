/*
 * Conductor.h
 * Created on: 31 mar. 2022
 * Author: Sergio Orgaz Bravo
 * Correo: sorgazbr@alumnos.unex.es
 * Descripción: Esta clase se encarga de guardar la información del conductor,
 *              así como el identificador del conductor, el nombre, la edad,
 *              el año que se dió de alta en la aplicación, la marca del coche
 *              y cuenta con un atributo que guarda información sobre una valoracion
 *              y comentario sobre el conductor.
 */

#ifndef CONDUCTOR_H_
#define CONDUCTOR_H_
#include <iostream>
using namespace std;
#include "pila.h"
#include "Opinion.h"

class Conductor {
	string identificador;
	string nombre;
	int edad;
	string marcaCoche;
	int anioAlta;
	Pila <Opinion*> *op;

	/*
	 * PRE={Que la pila de opinión contenga información}
	 * POST={Devuelve la media de las valoraciones de un conductor}
	 * COMPL: O(n²).
	 * DESC: Calcula la media de todas las valoraciones que posee ese conductor.
	 */
	float calcularValoracionMedia();
public:

	/*
	 * CONSTRUCTOR POR DEFECTO:
	 * PRE={}
	 * POST={getIdentificador()="", getNombre()="", getEdad()=0, getMarcaCoche()="", getAnioAlta()=0, Pila<Opinion> = new Pila <Opinion>}
	 * COMPL: O(1).
	 * DESC: Crea un conductor.
	 */
	Conductor();

	/*
	 * CONSTRUCTOR PARAMETRIZADO:
	 * PRE={}
	 * POST={getIdentificador()=identificador, getNombre()=nombre, getEdad()=edad, getMarcaCoche()=marcaCoche, getAnioAlta()=anioAlta, Pila<Opinion> = new Pila <Opinion>}
	 * COMPL: O(1).
	 * DESC: Crea un conductor.
	 */
	Conductor(string identificador, string nombre, int edad, string marcaCoche, int anioAlta);

	//MÉTODOS MODIFICADORES:

	/*
	 * PRE={}
	 * POST={Modifica el identificador del conductor}
	 * COMPL: O(1).
	 */
	void setIdenticador(string identificador);
	/*
	 * PRE={}
	 * POST={Modifica el nombre del conductor}
	 * COMPL: O(1)
	 */
	void setNombre(string nombre);
	/*
	 * PRE={}
	 * POST={Modifica la edad del conductor}
	 * COMPL: O(1)
	 */
	void setEdad(int edad);
	/*
	 * PRE={}
	 * POST={Modifica la marca del coche}
	 * COMPL: O(1).
	 */
	void setMarcaCoche(string marcaCoche);
	/*
	 * PRE={}
	 * POST={Modifica el año de alta del conductor en la aplicación}
	 * COMPL: O(1).
	 */
	void setAnioAlta(int anioAlta);

	// MÉTODOS SELECTORES

	/*
	 * PRE={}
	 * POST={Devuelve el identificador del conductor}
	 * COMPL: O(1).
	 */
	string getIdentificador();
	/*
	 * PRE={}
	 * POST={Devuelve el nombre del conductor}
	 * COMPL: O(1).
	 */
	string getNombre();
	/*
	 * PRE={}
	 * POST={Devuelve la edad del conductor}
	 * COMPL: O(1).
	 */
	int getEdad();
	/*
	 * PRE={}
	 * POST={Devuelve la marca del coche}
	 * COMPL: O(1).
	 */
	string getMarcaCoche();
	/*
	 * PRE={}
	 * POST={Devuelve el año en el que se dio de alta el conductor en la aplicación}
	 * COMPL: O(1).
	 */
	int getAnioAlta();

	/*
	 * PRE={}
	 * POST={Muestra por pantalla toda la información del conductor}
	 * COMPL: O(1).
	 */
	void mostrar();

	/*
	 * PRE={}
	 * POST={Añade una opinion compuestra por una nota y una valoración que le llega por parametros}
	 * COMPL: O(1).
	 */
	void aniadirOpinion(int nota, string valoracion);

	/*
	 * PRE={}
	 * POST={Devuelve el número total de valoraciones que hay en la pila de opinión}
	 * COMPL: O(n²).
	 */
	int cuantas();

	/*
	 * PRE={}
	 * POST={Muestra todas las valoraciones que hay en la pila de opiniones}
	 * COMPL: O(n²).
	 */
	void mostrarValoraciones();

	/*
	 * DESTRUCTOR
	 * PRE={}
	 * POST={Libera la memoria}
	 * COMPL: O(n)
	 */
	~Conductor();
};

#endif /* CONDUCTOR_H_ */
