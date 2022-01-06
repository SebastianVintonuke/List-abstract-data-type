#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>
#include <stddef.h>

//gcc -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror -o pruebas *.c
//valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas

/* ***************************************************************** *
 *                DEFINICION DE LOS TIPOS DE DATOS                   *
 * ***************************************************************** */

/* La lista está planteada como una lista de punteros genéricos. */

struct lista;
typedef struct lista lista_t;

/* ******************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

// Crea una lista.
// Post: devuelve una nueva lista vacía.
lista_t *lista_crear(void);

// Destruye la lista. Si se recibe la función destruir_dato por parámetro,
// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una función capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
void lista_destruir(lista_t *lista, void (*destruir_dato)(void *));

// Devuelve verdadero si la lista no tiene elementos, false en caso contrario.
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista);

// Agrega un nuevo elemento a la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento a la lista, valor se encuentra al inicio
// de la lista.
bool lista_insertar_primero(lista_t *lista, void *dato);

// Agrega un nuevo elemento a la lista. Devuelve falso en caso de error.
// Pre: la lista fue creada.
// Post: se agregó un nuevo elemento a la lista, valor se encuentra al final
// de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato);

// Obtiene el valor del primer elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del primero, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el primer elemento de la lista, cuando no está vacía.
void *lista_ver_primero(const lista_t *lista);

// Obtiene el valor del ultimo elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del ultimo, si está vacía devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el ultimo elemento de la lista, cuando no está vacía.
void *lista_ver_ultimo(const lista_t* lista);

// Devuelve el tamaño de la lista
// Pre: la lista fue creado
size_t lista_largo(const lista_t *lista);

// Saca el primer elemento de la lista. Si la lista tiene elementos, se quita el
// primero de la lista, y se devuelve su valor, si está vacía, devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolvió el valor del primer elemento anterior, la lista
// contiene un elemento menos, si la lista no estaba vacía.
void *lista_borrar_primero(lista_t *lista);

// Itera la lista, para cada uno de los elementos de la lista llama a visitar.
// Puede recibir un dato extra por parametro.
// Pre: la lista fue creada.
// Post: la lista fue recorrida aplicando visitar a cada elemento.
void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

struct lista_iter;
typedef struct lista_iter lista_iter_t;

/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR
 * *****************************************************************/

// Crea un iterador.
// Post: devuelve un nuevo iterador.
lista_iter_t *lista_iter_crear(lista_t *lista);

//Avanza la posicion del iterador.
//Pre: el iterador fue creado.
//Post: el iterador apunta al siguiente elemento de la lista.
bool lista_iter_avanzar(lista_iter_t *iter);

// Obtiene el valor de un elemento.
// Pre: el iterador fue creado.
// Post: se devolvió el elemento en la posicion del iterador.
void *lista_iter_ver_actual(const lista_iter_t *iter);

// Devuelve verdadero si el iterador esta al final de la lista, false en caso contrario.
// Pre: el iterador fue creado.
bool lista_iter_al_final(const lista_iter_t *iter);

// Destruye el iterador.
// Pre: el iterador fue creado.
// Post: se elimino el iterador.
void lista_iter_destruir(lista_iter_t *iter);

// Agrega un nuevo elemento a la lista. Devuelve falso en caso de error.
// Pre: el iterador fue creado.
// Post: se agregó un nuevo elemento a la lista, valor se encuentra en la posicion
// del iterador.
bool lista_iter_insertar(lista_iter_t *iter, void *dato);

// Borra un elemento de la lista.
// Pre: el iterador fue creado.
// Post: se borro un elemento de la lista, el valor borrado se encuentra en la posicion
// del iterador.
void *lista_iter_borrar(lista_iter_t *iter);

/* *****************************************************************
 *                      PRUEBAS UNITARIAS
 * *****************************************************************/

void pruebas_lista_estudiante(void);

#endif  // LISTA_H
