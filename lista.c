#include "lista.h"

#include <stdbool.h>
#include <stdlib.h>

typedef struct nodo {
    void* dato;
    struct nodo* prox;
}nodo_t;

typedef struct lista {
    nodo_t* prim;
    nodo_t* ult;
    size_t largo;
}lista_t;

nodo_t* crear_nodo(void* valor) {
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if(!nodo) {
        return NULL;
    }
    nodo->dato = valor;
    nodo->prox = NULL;
    return nodo;
}

lista_t *lista_crear(void) {
    lista_t* lista = malloc(sizeof(lista_t));
    if(!lista) {
        return NULL;
    }
    lista->prim = NULL;
    lista->ult = NULL;
    lista->largo = 0;
    return lista;
}

bool lista_esta_vacia(const lista_t *lista) {
    return (!lista->prim);
}

bool lista_insertar_primero(lista_t *lista, void *dato) {
    nodo_t* nodo = crear_nodo(dato);
    if (!nodo) {
        return false;
    }
    if (lista_esta_vacia(lista)) {
        lista->ult = nodo;
    } else {
        nodo->prox = lista->prim;
    }
    lista->prim = nodo;
    lista->largo ++;
    return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato) {
    nodo_t* nodo = crear_nodo(dato);
    if (!nodo) {
        return false;
    }
    if (lista_esta_vacia(lista)) {
        lista->prim = nodo;
    } else {
        lista->ult->prox = nodo;
    }
    lista->ult = nodo;
    lista->largo ++;
    return true;
}

void *lista_borrar_primero(lista_t *lista) {
    if (lista_esta_vacia(lista)) {
        return NULL;
    }
    void* dato = lista->prim->dato;
    nodo_t* nodo = lista->prim;
    lista->prim = lista->prim->prox;
    free(nodo);
    lista->largo --;
    return dato;
}

void *lista_ver_primero(const lista_t *lista) {
    if (lista_esta_vacia(lista)) {
        return NULL;
    }
    return (lista->prim->dato);
}

void *lista_ver_ultimo(const lista_t* lista) {
    if (lista_esta_vacia(lista)) {
        return NULL;
    }
    return (lista->ult->dato);
}

size_t lista_largo(const lista_t *lista) {
    return (lista->largo);
}

void lista_destruir(lista_t *lista, void (*destruir_dato)(void *)) {
    while (!lista_esta_vacia(lista)) {
        nodo_t* nodo = lista->prim;
        if (destruir_dato) {
            destruir_dato(nodo->dato);
        }
        lista->prim = lista->prim->prox;
        free(nodo);
    }
    free(lista);
}

void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra) {
    nodo_t* pos = lista->prim;
    while (pos != NULL) {
        if (!visitar(pos->dato, extra)) {
            break;
        }
        pos = pos->prox;
    }
}

typedef struct lista_iter {
    lista_t *lista;
    nodo_t *pos;
    nodo_t *pos_ant;
}lista_iter_t;

lista_iter_t *lista_iter_crear(lista_t *lista) {
    lista_iter_t* iter = malloc(sizeof(lista_iter_t));
    if(!iter) {
        return NULL;
    }
    iter->lista = lista;
    iter->pos = lista->prim;
    iter->pos_ant = NULL;
    return iter;
}

bool lista_iter_avanzar(lista_iter_t *iter) {
    if (!lista_iter_al_final(iter)) {
        iter->pos_ant = iter->pos;
        iter->pos = iter->pos->prox;
        return true;
    }
    return false;
}

void *lista_iter_ver_actual(const lista_iter_t *iter) {
    if (lista_iter_al_final(iter)) {
        return NULL;
    }
    return (iter->pos->dato);
}

bool lista_iter_al_final(const lista_iter_t *iter) {
    return (iter->pos == NULL);
}

void lista_iter_destruir(lista_iter_t *iter) {
    free(iter);
}

bool lista_iter_insertar(lista_iter_t *iter, void *dato) {
    nodo_t* nodo = crear_nodo(dato);
    if (!nodo) {
        return false;
    }
    if (iter->pos == iter->lista->prim) {
        nodo->prox = iter->pos;
        iter->pos = nodo;
        iter->lista->prim = nodo;
        if (nodo->prox == NULL) {
            iter->lista->ult = nodo;
        }
    } else if (lista_iter_al_final(iter)) {
        iter->pos_ant->prox = nodo;
        iter->pos = nodo;
        iter->lista->ult = nodo;
    } else {
        iter->pos_ant->prox = nodo;
        nodo->prox = iter->pos;
        iter->pos = nodo;
    }
    iter->lista->largo ++;
    return true;
}

void *lista_iter_borrar(lista_iter_t *iter) {
    if (lista_iter_al_final(iter)) {
        return NULL;
    }
    void* dato = iter->pos->dato;
    if (iter->pos == iter->lista->prim) {
        iter->lista->prim = iter->pos->prox;
        free(iter->pos);
        iter->pos = iter->lista->prim;
    } else if (iter->pos->prox == NULL) {
        iter->pos_ant->prox = NULL;
        free(iter->pos);
        iter->pos = NULL;
        iter->lista->ult = iter->pos_ant;
    } else {
        iter->pos_ant->prox = iter->pos->prox;
        free(iter->pos);
        iter->pos = iter->pos_ant->prox;
    }
    iter->lista->largo --;
    return dato;
}
