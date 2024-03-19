/*
 * Opinion.h
 * Created on: 31 mar. 2022
 * Author: Sergio Orgaz Bravo
 * Correo: sorgazbr@alumnos.unex.es
 * Descripción: Esta clase se encarga de guardar la información de cada opición,
 *              así como una valoración que debe ir de los valores 1 a 10, siendo
 *              1 la peor valoracíon posible y 10 la mejor, la clase tambien
 *              guarda un comentario destinado al conductor.
 */

#ifndef OPINION_H_
#define OPINION_H_
#include <iostream>
using namespace std;

class Opinion {
	int valoracion;
	string comentario;
public:

	/*
	 * CONSTRUCTOR POR DEFECTO:
	 * PRE={}
	 * POST={getValoracion()=1, getComentario()=""}
	 * COMPL: O(1)
	 * DESC: Crea una opinión.
	 */
	Opinion();

	/*
	 * CONSTRUCTOR PARAMETRIZADO:
	 * PRE={}
	 * POST={getValoracion()=valoracion, getComentario()=comentario}
	 * COMPL: O(1).
	 * DESC: Crea una opinion.
	 */
	Opinion(int valoracion, string comentario);

	// MÉTODOS MODIFICADORES:

	/*
	 * PRE={}
	 * POST={Modifica la valoración de la opinión}
	 * COMPL: O(1).
	 */
	void setValoracion(int valoracion);
	/*
	 * PRE={}
	 * POST={Modifica el comentario de la opinión}
	 * COMPL: O(1).
	 */
	void setComentario(string comentario);

	// MÉTODOS SELECTORES:

	/*
	 * PRE={}
	 * POST={Devuelve la valoración de la opinión}
	 * COMPL: O(1).
	 */
	int getValoracion();
	/*
	 * PRE={}
	 * POST={Devuelve el comentario de la opinión}
	 * COMPL: O(1)
	 */
	string getComentario();

	/*
	 * PRE={}
	 * POST={Muestra por pantalla la información de la opinión}
	 * COMPL: O(1).
	 */
	void mostrar();

	/*
	 * DESTRUCTOR:
	 * PRE={}
	 * POST={}
	 * COMPL:
	 */
	~Opinion();
};

#endif /* OPINION_H_ */
