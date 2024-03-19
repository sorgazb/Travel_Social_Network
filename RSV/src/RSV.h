/*
	ESTRUCTURAS DE DATOS Y DE LA INFORMACIÓN
	Curso 2021/2022
	Nombre: RSV.h
	Descripción: Definición de la clase RSV Red Social de Viajes
	Autor:	Profesores de la asignatura
    Fecha:	7/03/2022
    Alumno: Sergio Orgaz Bravo
    Correo: sorgazbr@alumnos.unex.es
*/

#ifndef RSV_H_
#define RSV_H_
#include <fstream>
#include "cola.h"
#include "lpi.h"
#include "Conductor.h"
#include "Viaje.h"

class RSV {
	LPI <Conductor*> *lc;
	LPI <Viaje* > *lv;

	/*
	 * PRE={Que el fichero de texto se haya abierto correctamente}
	 * POST={Se encarga de cargar todo el fichero de texto a la clase principal}
	 * COMPL: O(n)
	 * DESC: Se encarga de leer toda la informacion del fichero de texto y dejarla a disposición del usuario.
	 */
	void cargarDatos();
	/*
	 * PRE={Que el fichero de texto se haya abierto correctamente}
	 * POST={Se encarga de cargar todo el fichero de texto a la clase principal}
	 * COMPL: O(n)
	 * DESC: Se encarga de leer toda la informacion del fichero de texto y dejarla a disposición del usuario.
	 */
	void cargarOpiniones();
	/*
	 * PRE={Que el fichero de texto se haya abierto correctamente}
	 * POST={Se encarga de cargar todo el fichero de texto a la clase principal}
	 * COMPL: O(n)
	 * DESC: Se encarga de leer toda la informacion del fichero de texto y dejarla a disposición del usuario.
	 */
	void cargarViajes();
public:

	/*
	 * CONSTRUCTOR POR DEFECTO:
	 * PRE={}
	 * POST={lc=new, lv=new}
	 * COMPL: O(1).
	 * DESC: Crea la RSV.
	 */
	RSV();

	/*
	 * PRE={}
	 * POST={Añade un conductor nuevo a la lista de conductores y este es insertado por orden alfabético}
	 * COMPL: O(n).
	 * DESC: Recorre la lista de conductores para buscar la posicion en la que debe ser insertado el conductor y lo inserta.
	 */
	void insertarEnOrden(string identificador, string nombre, int edad, string marcaCoche, int anioAlta);

	/*
	 * PRE={}
	 * POST={Añade un viaje nuevo a la lista de viajes, estos son insetados por orden alfabetico de la ciudad de origen}
	 * COMPL: O(n)
	 * DESC: Recorre la lista de viajes para buscar la posición adecuada en la que se debe insertar el viaje,
	 *       esta inserción se hace mediante orden alfabetico de la ciudad de origen, si hay más de un viaje que
	 *       parte de esa misma ciudad se insertan por orden se hora de salida.
	 */
	void insertarEnOrdenViaje(string ciudadOrigen, string ciudadDestino, int horaSalida, string id);

	/*
	 * PRE={Que el conductor exista}
	 * POST={Busca un conductor concreto y lo devuelve através del parametro}
	 * COMPL: O(n).
	 * DESC: Dado un identificador, busca a ese conductor en la lista de conductores, si lo encuentra lo devuelve.
	 */
	bool buscar(string id, Conductor *&c);

	/*
	 * PRE={}
	 * POST={Muestra por pantalla toda la lista de conductores junto con sus opiniones}
	 * COMPL: O(n).
	 * DESC:
	 */
	void mostrarConductores();

	/*
	 * PRE={}
	 * POST={Muestra por pantalla toda la lista de viajes}
	 * COMPL: O(1).
	 * DESC:
	 */
	void mostrarViajes();

	/*
	 * PRE={}
	 * POST={Dice si existe el conductor cuyo identificador se pasa por parametros en la lista de conductores}
	 * COMPL: O(n).
	 * DESC: Recorre la lista de conductores en busca del identificador de un conductor en concreto y dice si ese conductor existe o no.
	 */
	bool existe(string identificador);

	/*
	 * PRE={}
	 * POST={Inserta en la lista de conductores un nuevo conductor y lo inserta en orden alfabético, si ya existe ese conductor no lo inserta}
	 * COMPL: O(1).
	 * DESC:
	 */
	void insertarConductor();

	/*
	 * PRE={La valoración debe estar comprendida entre 1-10}
	 * POST={Añade una nueva valoración a un conductor}
	 * COMPL:
	 * DESC: O(1).
	 */
	void valorarConductor();

	/*
	 * PRE={Que conductor exista}
	 * POST={Inserta la información de un nuevo viaje en la lista de viajes}
	 * COMPL: O(1).
	 * DESC:
	 */
	void insertarViaje();

	/*
	 * PRE={}
	 * POST={Busca un conductor concreto y muestra toda su información}
	 * COMPL: O(1)
	 * DESC:
	 */
	void buscarConductorConcreto(string identificador);

	/*
	 * PRE={Que identificador exista}
	 * POST={Borra toda la información  y los viajes del conductor}
	 * COMPL: O(n)
	 * DESC:
	 */
	void eliminarConductor(string identificador);

	/*
	 * PRE={Que el identificador exista}
	 * POST={Borra todos los viajes del conductor en concreto}
	 * COMPL: O(1)
	 * DESC: Este método sirve de apollo al método de eliminarConductor.
	 */
	void eliminarViajesConductor(string idenficador);

	/*
	 * PRE={}
	 * POST={Muestra la cola de viajes que tengan la misma ciudad de origen y destino que se le pasan por parametros}
	 * COMPL: O(n)
	 * DESC:
	 */
	void obtenerCola(string ciudadOrigen, string ciudadDestino, Cola <Viaje*> *cViaje);
	void mostrarCola(Cola <Viaje*> *cViaje);


	/*
	 * DESTRUCTOR
	 * PRE={}
	 * POST={Libera espacio}
	 * COMPL: O(n²)
	 * DESC:
	 */
	~RSV();
};

#endif /* RSV_H_ */
