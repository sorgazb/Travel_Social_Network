/*
 * Viaje.h
 * Created on: 31 mar. 2022
 * Author: Sergio Orgaz Bravo
 * Correo: sorgazbr@alumnos.unex.es
 * Descripción: Esta clase se encarga de guardar la información de cada viaje,
 *              así como la ciudad de origen, la ciudad de destino, la hora de salida,
 *              y el identificador del conductor.
 */

#ifndef VIAJE_H_
#define VIAJE_H_
#include <iostream>
using namespace std;

class Viaje {
	string ciudadOrigen;
	string ciudadDestino;
	int horaSalida;
	string id;
public:

	/*
	 * CONSTRUCTOR POR DEFECTO:
	 * PRE={}
	 * POST={getCiudadOrigen()="", getCiudadDestino()="", getHoraSalida()=0, getId()=""}
	 * COMPL: O(1).
	 * DESC:Crea un viaje.
	 */
	Viaje();

	/*
	 * CONSTRUTOR PARAMETRIZADO:
	 * PRE={}
	 * POST={getCiudadOrigen()=ciudadOrigen, getCiudadDestino()=ciudadDestino, getHoraSalida()=horaSalida, getId()=id}
	 * COMPL: O(1)
	 * DESC: Crea un viaje.
	 */
	Viaje(string ciudadOrigen, string ciudadDestino, int horaSalida, string id);

	// MÉTODOS MODIFICADORES:

	/*
	 * PRE={}
	 * POST={Modifica la ciudad de origen del viaje}
	 * COMPL: O(1)
	 */
	void setCiudadOrigen(string ciudadOrigen);
	/*
	 * PRE={}
	 * POST={Modifica la ciudad de destino del viaje}
	 * COMPL: O(1)
	 */
	void setCiudadDestino(string ciudadDestino);
	/*
	 * PRE={}
	 * POST={Modifica la hora de salida del viaje}
	 * COMPL: O(1)
	 */
	void setHoraSalida(int horaSalida);
	/*
	 * PRE={}
	 * POST={Modifica el identificador del conductor del viaje}
	 * COMPL: O(1)
	 */
	void setId(string id);

	// METODOS SELECTORES

	/*
	 * PRE={}
	 * POST={Devuelve la ciudad de origen del viaje}
	 * COMPL: O(1)
	 */
	string getCiudadOrigen();
	/*
	 * PRE={}
	 * POST={Devuelve la ciudad de destino del viaje}
	 * COMPL: O(1)
	 */
	string getCiudadDestino();
	/*
	 * PRE={}
	 * POST={Devuelve la hora de salida del viaje}
	 * COMPL: O(1)
	 */
	int getHoraSalida();
	/*
	 * PRE={}
	 * POST={Devuelve el identificador del conductor del viaje}
	 * COMPL: O(1)
	 */
	string getId();

	/*
	 * PRE={}
	 * POST={Muestra por pantalla la información del viaje}
	 * COMPL: O(1)
	 */
	void mostrar();

	/*
	 * DESTRUCTOR:
	 * PRE={}
	 * POST={}
	 * COMPL:
	 */
	~Viaje();
};

#endif /* VIAJE_H_ */
