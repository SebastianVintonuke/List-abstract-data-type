#include "lista.h"
#include "testing.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>


static void prueba_lista_vacia(void) {
    printf("INICIO DE PRUEBAS LISTA VACIA\n");

    /* Declaro las variables a utilizar */
    lista_t *lista = lista_crear();

    /* Inicio de pruebas */
    print_test("crear lista", lista != NULL);
    print_test("la lista esta vacia", lista_esta_vacia(lista));
    print_test("el largo es 0", lista_largo(lista) == 0);

    /* Pruebo ver el primero y ultimo de una lista vacia */
    print_test("ver primero de una lista vacia es NULL", lista_ver_primero(lista) == NULL);
    print_test("ver ultimo de una lista vacia es NULL", lista_ver_ultimo(lista) == NULL);

    /* Pruebo borrar primero de una lista vacia */
    print_test("borrar primero de una lista vacia es NULL", lista_borrar_primero(lista) == NULL);

    /* Destruyo la lista */
    lista_destruir(lista, NULL);
    print_test("la lista fue destruida", true);
}

static void prueba_insertar(void) {
    printf("INICIO DE PRUEBAS DE INSERTAR\n");
    
    lista_t *lista2 = lista_crear();
    print_test("crear lista", lista2 != NULL);
    
    /* Declaro las variables a utilizar */
    int n1 = 1;
    int n2 = 2;
    int n3 = 3;
    int *valor1 = &n1;
    int *valor2 = &n2;
    int *valor3 = &n3;
    
    /* Pruebo insertar primero */
    print_test("se inserto primero el elemento 1", lista_insertar_primero(lista2, valor1));
    
    /* Pruebo el elemento insertado */
    print_test("el primero es el elemento 1", (lista_ver_primero(lista2) == valor1));
    print_test("el ultimo es el elemento 1", (lista_ver_ultimo(lista2) == valor1));
    print_test("el largo es 1", lista_largo(lista2) == 1);
    
    /* Pruebo insertar ultimo */
    print_test("se inserto ultimo el elemento 2", lista_insertar_ultimo(lista2, valor2));
    
    /* Pruebo el elemento insertado */
    print_test("el primero es el elemento 1", (lista_ver_primero(lista2) == valor1));
    print_test("el ultimo es el elemento 2", (lista_ver_ultimo(lista2) == valor2));
    print_test("el largo es 2", lista_largo(lista2) == 2);
    
    /* Pruebo insertar primero */
    print_test("se inserto primero el elemento 3", lista_insertar_primero(lista2, valor3));
    
    /* Pruebo el elemento insertado */
    print_test("el primero es el elemento 3", (lista_ver_primero(lista2) == valor3));
    print_test("el ultimo es el elemento 2", (lista_ver_ultimo(lista2) == valor2));
    print_test("el largo es 3", lista_largo(lista2) == 3);
    
    /* Pruebo borrar */
    print_test("el borrado es el elemento 3", (lista_borrar_primero(lista2) == valor3));
    print_test("el largo es 2", lista_largo(lista2) == 2);
    print_test("el borrado es el elemento 1", (lista_borrar_primero(lista2) == valor1));
    print_test("el largo es 1", lista_largo(lista2) == 1);
    print_test("el borrado es el elemento 2", (lista_borrar_primero(lista2) == valor2));
    
    /* Pruebo que la lista este vacia */
    print_test("la lista esta vacia", lista_esta_vacia(lista2));
    print_test("el largo es 0", lista_largo(lista2) == 0);
    
    /* Pruebo ver el primero de una lista vacia */
    print_test("ver primero de una lista vacia es NULL", lista_ver_primero(lista2) == NULL);
    
    /* Pruebo ver el ultimo de una lista vacia */
    print_test("ver ultimo de una lista vacia es NULL", lista_ver_ultimo(lista2) == NULL);
    
    /* Pruebo borrar de una lista vacia */
    print_test("borrar de una lista vacia es NULL", lista_borrar_primero(lista2) == NULL);
    
    /* Destruyo la lista */
    lista_destruir(lista2, NULL);
    print_test("la lista fue destruida", true);
}

static void prueba_elemento_NULL(void) {
    printf("INICIO DE PRUEBAS ELEMENTO NULL\n");
    
    lista_t *lista3 = lista_crear();
    print_test("crear lista", lista3 != NULL);
    
    /* Pruebo insertar primero NULL */
    print_test("se inserto primero el elemento NULL", lista_insertar_primero(lista3, NULL));
    
    /* Pruebo insertar ultimo NULL */
    print_test("se inserto ultimo el elemento NULL", lista_insertar_ultimo(lista3, NULL));
    
    /* Pruebo que la lista NO este vacia */
    print_test("la lista NO esta vacia", !lista_esta_vacia(lista3));
    print_test("el largo es 2", lista_largo(lista3) == 2);
    
    /* Pruebo ver primero */
    print_test("el primero es el elemento NULL", (lista_ver_primero(lista3) == NULL));
    
    /* Pruebo ver ultimo */
    print_test("el ultimo es el elemento NULL", (lista_ver_ultimo(lista3) == NULL));
    
    /* Pruebo borrar primero NULL */
    print_test("borro primer NULL", lista_borrar_primero(lista3) == NULL);
    print_test("borro segundo NULL", lista_borrar_primero(lista3) == NULL);
    
    /* Pruebo que la lista este vacia */
    print_test("la lista esta vacia", lista_esta_vacia(lista3));
    
    /* Destruyo la lista */
    lista_destruir(lista3, NULL);
    print_test("la lista fue destruida", true);
}

static void prueba_lista_volumen(void) {
    printf("INICIO DE PRUEBAS DE VOLUMEN\n");
    
    lista_t *lista4 = lista_crear();
    print_test("crear lista", lista4 != NULL);
    
    /* Declaro las variables a utilizar*/
    size_t largo = 0;
    bool ok = true;
    bool ok1 = true;
    bool ok2 = true;
    bool ok3 = true;
    bool ok4 = true;
    int valores[500];
    for (int i = 0; i<500; i++) {
        valores[i] = i;
    }
    
    /* Pruebo que se pueden insertar muchos elementos */
    for (int i = 0; i<500; i++) {
        ok &= lista_insertar_primero(lista4, &valores[i]);
        ok1 &= lista_ver_primero(lista4) == &valores[i];
        ok4 &= lista_largo(lista4) == ++largo;
        ok2 &= lista_insertar_ultimo(lista4, &valores[i]);
        ok3 &= lista_ver_ultimo(lista4) == &valores[i];
        ok4 &= lista_largo(lista4) == ++largo;
    }
    print_test("se pudieron insertar_primero todos los elementos", ok);
    print_test("todos los primeros fueron correctos", ok1);
    print_test("se pudieron insertar_ultimo todos los elementos", ok2);
    print_test("todos los ultimos fueron correctos", ok3);
    print_test("todos los largos fueron correctos", ok4);
    
    bool ok5 = true;
    bool ok6 = true;
    
    /* Pruebo que se pueden borrar muchos elementos */
    for (size_t i = 500; i>0; i--) {
        ok5 &= lista_ver_primero(lista4) == &valores[i-1];
        lista_borrar_primero(lista4);
        ok6 &= lista_largo(lista4) == --largo;
    }
    for (int i = 0; i<500; i++) {
        ok5 &= lista_ver_primero(lista4) == &valores[i];
        lista_borrar_primero(lista4);
        ok6 &= lista_largo(lista4) == --largo;
    }
    
    print_test("se pudieron borrar todos los elementos", lista_esta_vacia(lista4));
    print_test("todos los elementos fueron correctos", ok5);
    print_test("todos los largos fueron correctos", ok6);
    
    /* Destruyo la lista*/
    lista_destruir(lista4, NULL);
    print_test("la lista fue destruida", true);
}

static void prueba_lista_destruir(void) {
    printf("INICIO DE PRUEBAS DESTRUIR LISTA\n");
    
    lista_t *lista5 = lista_crear();
    print_test("crear lista", lista5 != NULL);
    
    /* Declaro las variables a utilizar*/
    bool ok = true;
    int valores[500];
    for (int i = 0; i<500; i++) {
        valores[i] = i;
        ok &= lista_insertar_ultimo(lista5, &valores[i]);
    }

    print_test("se pudieron agregar al final todos los elementos", ok);
    
    /* Destruyo la lista*/
    lista_destruir(lista5, NULL);
    print_test("la lista llena fue destruida", true);   
}

//* Funciones visitar auxiliares *//
bool visitar_sumar(void *dato, void *extra) {
    *(int*)extra += *(int*)dato;
    return true;
}

bool visitar_set_0(void *dato, void *extra) {
    if (*(int*) extra != 0) {
        *(int*)dato = 0;
        --*(int*)extra;
        return true;
    }
    return false;
}

static void prueba_lista_iterador_interno(void) {
    printf("INICIO DE PRUEBAS DEL ITERADOR INTERNO\n");
    
    lista_t *lista6 = lista_crear();
    print_test("crear lista", lista6 != NULL);
    
    int suma = 0;
    int esperado = 0;
    int valores[10];
    for (int i = 0; i<10; i++) {
        valores[i] = i;
        esperado += i;
        lista_insertar_ultimo(lista6, &valores[i]);
    }
    
    //* Pruebo sumar todos los elementos de la lista *//
    lista_iterar(lista6, visitar_sumar, &suma);
    print_test("la suma de todos los elementos es correcta", suma == esperado);
    
    bool ok = true;
    int corte = 5;
    //* Pruebo condicion de corte *//
    lista_iterar(lista6, visitar_set_0, &corte);
    
    for (int i=0; i<5; i++) {
        ok &= *(int*)lista_borrar_primero(lista6) == 0;
    }
    for (int i= 5; i<10; i++) {
        ok &= lista_borrar_primero(lista6) == &valores[i];
    }
    print_test("la condicion de corte fue correcta", ok);
        
    lista_destruir(lista6, NULL);
    print_test("la lista fue destruida", true);     
}

static void prueba_lista_iterador_externo(void) {
    printf("INICIO DE PRUEBAS DEL ITERADOR EXTERNO\n");
    
    lista_t *lista7 = lista_crear();
    print_test("crear lista", lista7 != NULL);
    
    int valores[10];
    for (int i = 0; i<10; i++) {
        valores[i] = i;
        lista_insertar_ultimo(lista7, &valores[i]);
    }
    
    //* Creo el iterador *//   
    lista_iter_t *iterador = lista_iter_crear(lista7);
    print_test("crear iterador", iterador != NULL);
    
    print_test("el iterador no esta al final", !lista_iter_al_final(iterador));
    
    //* Avanzo el iterador hasta el final comprobando los datos *//
    bool ok = true;
    for (int pos = 0; !lista_iter_al_final(iterador); pos++) {
        ok &= lista_iter_ver_actual(iterador) == &valores[pos];
        ok &= lista_iter_avanzar(iterador);
    }
    
    print_test("el iterador avanza correctamente hasta el final", ok);
    
    //* Destruyo el iterador *//
    lista_iter_destruir(iterador);
    print_test("el iterador fue destruido", true);
    
    /* Destruyo la lista*/
    lista_destruir(lista7, NULL);
    print_test("la lista fue destruida", true);    
}

static void prueba_lista_iterador_externo_insertar(void) {
    printf("INICIO DE PRUEBAS DEL ITERADOR EXTERNO INSERTAR\n");
    
    lista_t *lista8 = lista_crear();
    print_test("crear lista", lista8 != NULL);
    
    int valores[10];
    for (int i = 0; i<10; i++) {
        valores[i] = 0;
        lista_insertar_ultimo(lista8, &valores[i]);
    }
    
    //* Creo el iterador *//
    lista_iter_t *iterador2 = lista_iter_crear(lista8);
    print_test("crear iterador", iterador2 != NULL);
    
    int principio = 1;
    int medio = 2;
    int final = 3;
    
    for (int pos = 0; !lista_iter_al_final(iterador2); pos++) {
        //* Pruebo insertar al principio *//
        if (pos == 0) {
            lista_iter_insertar(iterador2, &principio);
        }
        //* Pruebo insertar en el medio *//
        if (pos == 5) {
            lista_iter_insertar(iterador2, &medio);
        }
        lista_iter_avanzar(iterador2);
    }
    //* Pruebo insertar al final *//
    if (lista_iter_al_final(iterador2)) {
        lista_iter_insertar(iterador2, &final);
    }
    print_test("el largo es correcto",lista_largo(lista8) == 13);

    //* Destruyo el iterador *//
    lista_iter_destruir(iterador2);
    print_test("el iterador fue destruido", true);

    //* Verifico la lista con otro iterador *//
    lista_iter_t *iterador3 = lista_iter_crear(lista8);
    
    bool ok = true;
    for (int pos = 0; !lista_iter_al_final(iterador3); pos++) {
        if (pos==0) {
            ok &= lista_iter_ver_actual(iterador3) == &principio;
        } else if (pos==5) {
            ok &= lista_iter_ver_actual(iterador3) == &medio;
        } else if (pos==12) {
            ok &= lista_iter_ver_actual(iterador3) == &final;
        } else {
            ok &= *(int*)lista_iter_ver_actual(iterador3) == 0;
        }
        lista_iter_avanzar(iterador3);
    }
    
    print_test("la lista es correcta", ok);
    
    //* Destruyo el iterador *//
    lista_iter_destruir(iterador3);

    /* Destruyo la lista*/
    lista_destruir(lista8, NULL);
    print_test("la lista fue destruida", true);
}

static void prueba_lista_iterador_externo_borrar(void) {
    printf("INICIO DE PRUEBAS DEL ITERADOR EXTERNO BORRAR\n");
    
    lista_t *lista9 = lista_crear();
    print_test("crear lista", lista9 != NULL);
    
    int valores[10];
    for (int i = 0; i<10; i++) {
        valores[i] = i;
        lista_insertar_ultimo(lista9, &valores[i]);
    }
    //* Creo el iterador *//
    lista_iter_t *iterador4 = lista_iter_crear(lista9);
    print_test("crear iterador", iterador4 != NULL);
    
    for (int pos = 0; !lista_iter_al_final(iterador4); pos++) {
        //* Pruebo borrar al principio *//
        if (pos == 0) {
            print_test("borrar el primer elemento", lista_iter_borrar(iterador4) == &valores[0]);
            continue;
        }
        if (pos == 5) {
            print_test("borrar un elemento del medio", lista_iter_borrar(iterador4) == &valores[5]);
            continue;
        }
        if (pos == 9) {
            print_test("borrar el ultimo elemento", lista_iter_borrar(iterador4) == &valores[9]);
            continue;
        }
        lista_iter_avanzar(iterador4);
    }
    print_test("el largo es correcto",lista_largo(lista9) == 7);
    
    //* Destruyo el iterador *//
    lista_iter_destruir(iterador4);
    print_test("el iterador fue destruido", true);
    
    //* Verifico la lista con otro iterador *//
    lista_iter_t *iterador5 = lista_iter_crear(lista9);
    
    bool ok = true;
    for (int i = 0; !lista_iter_al_final(iterador5); i++) {
        if (i==0 || i==5 || i==9) {
            continue;
        }
        ok &= lista_iter_ver_actual(iterador5) == &valores[i];
        lista_iter_avanzar(iterador5);
    }  
    print_test("la lista es correcta", ok);
    
    //* Destruyo el iterador *//
    lista_iter_destruir(iterador5);
    
    /* Destruyo la lista*/
    lista_destruir(lista9, NULL);
    print_test("la lista fue destruida", true);
}

void pruebas_lista_estudiante() {
    prueba_lista_vacia();
    prueba_insertar();
    prueba_elemento_NULL();
    prueba_lista_volumen();
    prueba_lista_destruir();
    prueba_lista_iterador_interno();
    prueba_lista_iterador_externo();
    prueba_lista_iterador_externo_insertar();
    prueba_lista_iterador_externo_borrar();
}

#ifndef CORRECTOR

int main(void) {
    pruebas_lista_estudiante();
    return failure_count() > 0;
}

#endif
