/*
 * Pila.h
 *
 *  Created on: Feb. 2016, 25th
 *  Author: Juan A. Rico (jarico@unex.es)
 *  Definicion de una pila generica.
 */

#ifndef _PILA_H_
#define _PILA_H_

#include <iostream>
/**
* Clase Pila
* Pila generica para almacenar objetos
* Implementación dinámica mediante punteros y basada en Templates C++.
*/
template <class TYPE> class Pila {
private:
	/**
	 * Clase Nodo
	 * Cada Noddo esta computesto por un elemento (tipo generico) y un
    *  puntero al siguiente elemento).
	 */
	class Nodo {
	public:
	    TYPE elem;
	    Nodo *next;

        Nodo (const TYPE &dato) {
            this->elem = dato;
            this->next = nullptr;
        }
	};

	/** Puntero al nodo en la cima de la pila */
	Nodo *topNodo;

public:
	/*
	 * Constructor por defecto
	 * Pre  = { }
	 * Post = {pila.vacia() == True}
	 */
	Pila ();

	/*
	 * Constructor parametrizado
	 * Pre  = { }
	 * Post = {pila.vacia() == False, pila.cima() == Elem}
	 * PARAMS: Elem para insertar en la cima de la pila
	 */
	Pila (TYPE elem);

   /**
   * Destructor de la pila
   * Pre =  {}
   * Post = {pila.vacia() == true}
   * Complejidad: O(n)
   */
   ~Pila ();

	/*
	 * Esta la pila vacia?
	 * Pre  = { }
	 * Post = { }
 	 * RETURN: true si esta vacia, false en otro caso
 	 * Complejidad: O(1)
 	 */
	bool vacia () const;

	/*
	 * Apilar un elemento en la pila
	 * Pre  = {}
	 * Post = {pila.vacia() == False, pila.cima() = Elem}
	 * PARAMS: Elem: elemento a insertar.
 	 * Complejidad: O(1)
 	 */
	void apilar (const TYPE &elem);

	/*
	 * Obtener el elemento en la cima de la pila.
	 * Pre  = {pila.vacia() == False}
	 * Post = {elem == pila.cima() }
	 * PARAM: Elem Es el elemento en la cima de la pila
 	 * Complejidad: O(1)
 	 */
	void cima (TYPE &elem);

	/*
	 * Obtener el elemento en la cima de la pila.
	 * Pre  = {pila.vacia() == False}
	 * Post = {Elem = pila.cima() }
 	 * RETURN: devuelve el elemento en la cima de la pila.
 	 * Complejidad: O(1)
 	 */
	TYPE cima ();


	/*
	 * Borrar el elemento en la cima de la pila.
	 * Pre  = {pila.vacia() == False}
	 * Post = {pila.cima() != Elem}
 	 * Complejidad: O(1)
 	 */
	void desapilar ();

};


template <class TYPE> Pila<TYPE>::Pila () {
	topNodo = nullptr;
}

template <class TYPE> Pila<TYPE>::Pila (TYPE dato) {
	Nodo *nodo = new Nodo (dato);
	nodo->next = topNodo;
	topNodo = nodo;
}

template <class TYPE> bool Pila<TYPE>::vacia () const {
	return (topNodo == NULL);
}

template <class TYPE> void Pila<TYPE>::apilar (const TYPE &dato) {
	Nodo *nodo = new Nodo(dato);
	nodo->next = topNodo;
	topNodo = nodo;
}

template <class TYPE> void Pila<TYPE>::cima (TYPE &dato) {
	dato = topNodo->elem;
}

template <class TYPE> TYPE Pila<TYPE>::cima (){
	return topNodo->elem;
}

template <class TYPE> void  Pila<TYPE>::desapilar
(){
	Nodo *nodo = topNodo;
	topNodo = topNodo->next;
	delete nodo;
// Next code is not correct, due to the Preconditions.
//	if (! empty()){
//		topNodo = topNodo->next;
//		delete Nodo;
//	}
}

template <class TYPE>  Pila<TYPE>::~Pila (){
	Nodo *nodo;
	while (! this->vacia()){
		nodo = topNodo;
		topNodo = topNodo->next;
		delete nodo;
	}
}


#endif /* _PILA_H_ */

