/*
 * LPI.h
 *
 *  Created on: 28/02/2021
 *      Author: JGR
 */

#ifndef LPI_H_
#define LPI_H_


#include <cstdlib>
#include <iostream>
using namespace std;


template <class TipoDato>
class LPI {

private:

	class Nodo {

	public:

		TipoDato  dato;
		Nodo     *siguiente;
		Nodo     *anterior;

		Nodo (const TipoDato &dato) {
			this->dato      = dato;
			this->siguiente = NULL;
			this->anterior  = NULL;
		}
	};

	Nodo *cabeza;
	Nodo *fin;
	Nodo *pI;


public:

    /* DESC:   Crea una lista con punto de interes vacia
     * PRE:    -
     * POST:   Lista vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	LPI ();

    /* DESC:   Consulta si la lista esta vacia
     * PRE:    Lista creada
     * POST:   -
     * PARAM:  -
     * RET:    TRUE:  lista vacia
     *         FALSE: lista no vacia
     * COMP:   O(1)
     */
	bool  vacia ();

    /* DESC:   Coloca el PI al inicio de la lista
     * PRE:    Lista creada
     * POST:   PI apunta al primero elemento o a NULL si la lista esta vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	void  moverInicio ();

	/* DESC:   Coloca el PI al final de la lista
     * PRE:    Lista creada
     * POST:   PI apunta al ultimo elemento o a NULL si la lista esta vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	void  moverUltimo ();

    /* DESC:   Coloca el PI apuntando al siguiente elemento de la lista
     * PRE:    Lista creada
     * POST:   PI apunta al siguiente elemento o a NULL si la lista esta vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	void  avanzar ();

    /* DESC:   Coloca el PI apuntando al anterior elemento de la lista
     * PRE:    Lista creada
     * POST:   PI apunta al anterior elemento o a NULL si la lista esta vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	void  retroceder ();

    /* DESC:   Consulta si el PI apunta al elemento inicial de la lista
     * PRE:    Lista creada
     * POST:   -
     * PARAM:  -
     * RET:    TRUE:  Si el PI apunta al primer elemento de la lista
     *         FALSE: Si el PI no apunta al primer elemento de la lista
     * COMP:   O(1)
     */
	bool  enInicio ();

    /* DESC:   Consulta si el PI apunta al ultimo elemento de la lista
     * PRE:    Lista creada
     * POST:   -
     * PARAM:  -
     * RET:    TRUE:  Si el PI apunta al ultimo elemento de la lista
     *         FALSE: Si el PI no apunta al ultimo elemento de la lista
     * COMP:   O(1)
     */
	bool  enUltimo ();

    /* DESC:   Consulta si el PI apunta despues del ultimo elemento de la lista
     * PRE:    Lista creada
     * POST:   -
     * PARAM:  -
     * RET:    TRUE:  Si el PI apunta despues del ultimo elemento de la lista
     *         FALSE: Si el PI no apunta despues del ultimo elemento de la lista
     * COMP:   O(1)
     */
	bool  enFin ();

    /* DESC:   Inserta un elemento en la lista, justo delante del PI
     * PRE:    Lista creada.
     * POST:   Lista con un elemento mas. PI apunta al elemento insertado.
     * PARAM:  E: dato -> Elemento a insertar
     * RET:    -
     * COMP:   O(1)
     */
	void  insertar (const TipoDato &dato);

	/* DESC:   Devuelve el elemento de la lista apuntado por el PI
	 * PRE:    Lista creada.
	 * POST:   -
	 * PARAM:  S: dato -> Elemento apuntado por PI (si PI apunta a un elemento valido)
	 * RET:    -
	 * COMP:   O(1)
	 */
	void  consultar (TipoDato &dato);

	/* DESC:   Devuelve el elemento de la lista apuntado por el PI
	 * PRE:    Lista creada
	 * POST:   -
	 * PARAM:  -
	 * RET:    Elemento apuntado por PI (si PI apunta a un elemento valido)
	 * COMP:   O(1)
	 */
	TipoDato& consultar();

	/* DESC:   Borra el elemento de la lista apuntado por el PI
	 * PRE:    Lista creada.
	 * POST:   Num. elementos en la lista disminuye en 1 si se puede borrar.
	 *         PI queda apuntando al siguiente elemento.
	 * PARAM:  -
	 * RET:    -
	 * COMP:   O(1)
	 */
	void  borrar ();

	/* DESC:   Libera la memoria ocupada por los nodos de la lista
	 * PRE:    Lista creada.
	 * POST:   Num. elementos en la lista = 0. Lista vacia == TRUE
	 * PARAM:  -
	 * RET:    -
	 * COMP:   O(n)
	 */
     ~LPI();

};




template <class TipoDato>
LPI<TipoDato>::LPI () {
	cabeza = NULL;
	fin    = NULL;
	pI     = NULL;
}

template <class TipoDato>
bool LPI<TipoDato>::vacia () {
	return (cabeza == NULL);
}

template <class TipoDato>
void LPI<TipoDato>::moverInicio (){
	pI = cabeza;
}

template <class TipoDato>
void LPI<TipoDato>::moverUltimo (){
	pI= fin;
}

template <class TipoDato>
void LPI<TipoDato>::avanzar () {

	if (pI != NULL) {
		pI = pI->siguiente;
	}
}

template <class TipoDato>
void LPI<TipoDato>::retroceder (){

	if (pI != cabeza) {
		if (pI != NULL) {
			pI = pI->anterior;
		} else {
			pI = fin;
		}
	}
}

template <class TipoDato>
bool LPI<TipoDato>::enInicio (){
	return (pI == cabeza);
}

template <class TipoDato>
bool LPI<TipoDato>::enUltimo (){
	return (pI == fin);
}

template <class TipoDato>
bool LPI<TipoDato>::enFin (){
	return (pI == NULL);
}

template <class TipoDato>
void LPI<TipoDato>::consultar (TipoDato &dato){

	if (pI != NULL) {
		dato = pI->dato;
	}
}
template<class TipoDato>
TipoDato& LPI<TipoDato>::consultar() {
	Nodo *pAux;
	if (pI != NULL)
		pAux = pI->dato;
  return pAux;
}

template <class TipoDato>
void LPI<TipoDato>::insertar (const TipoDato &dato) {


	Nodo *nuevo = new Nodo (dato);
	if (pI == NULL){
		if (vacia()) { // Lista vacia
			nuevo->siguiente = pI;
			cabeza = nuevo;
			fin    = nuevo;
		} else { // pI apunta al elemento siguiente al final: el nodo se inserta al final
                       //cout<<" poi a null y La lista no est� vac�a...."<<endl;
			nuevo->anterior = fin;
			fin->siguiente  = nuevo;
			fin = nuevo;
		}

	} else {

		if (pI->anterior == NULL) { // Insercion el primero de la lista
			cabeza = nuevo;
			nuevo->siguiente = pI;
			nuevo->anterior = NULL;
			pI->anterior = nuevo;
		} else {  // Insercion en posicion intermedia
			nuevo->anterior  = pI->anterior;
			nuevo->siguiente = pI;
			(pI->anterior)->siguiente = nuevo;
			pI->anterior = nuevo;
		}

	}

	// El PI apunta al nuevo nodo insertado
	pI = nuevo;
}

template <class TipoDato>
void LPI<TipoDato>::borrar () {

	Nodo *pAux;

	if (!vacia() && !enFin()) {

		pAux=pI;

		if (pI == cabeza) // El nodo a borrar es el primero
			cabeza = cabeza->siguiente;
		if (pI == fin)    // El nodo a borrar es el ultimo
			fin = fin->anterior;

		pI = pI->siguiente; // El PI apunta al siguiente

		if (pAux->anterior!=NULL)
			(pAux->anterior)->siguiente = pI;
		if (pAux->siguiente!=NULL)
			pI->anterior = pAux->anterior;

		delete pAux;
	}
}


template <class TipoDato>
LPI<TipoDato>::~LPI() {
	moverInicio();
		while (!vacia())
			borrar();

	cabeza = NULL;
	fin    = NULL;
	pI     = NULL;
}




#endif /* LPI_H_ */
