//Santiago Troconis
//C.I: 30.605.144

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NOMBRE 50
#define MAX_COLA 100

typedef struct {
    char nombre[MAX_NOMBRE];
    int comida;
    int tlf;
} Lugar;

typedef struct nodo {
    Lugar restaurante;
    struct nodo *sig;
} Nodo;

typedef struct {
    Nodo *primero;
    Nodo *ultimo;
    int tamano;
} Cola;

Nodo *crearNodo(Lugar restaurante) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->restaurante = restaurante;
    nuevo->sig = NULL;
    return nuevo;
}

Cola *crearCola() {
    Cola *c = (Cola *)malloc(sizeof(Cola));
    c->primero = c->ultimo = NULL;
    c->tamano = 0;
    return c;
}

void agreg(Lugar restaurante, Cola *c) {
    Nodo *nuevo = crearNodo(restaurante);
    if (c->primero == NULL) {
        c->primero = c->ultimo = nuevo;
    } else {
        c->ultimo->sig = nuevo;
        c->ultimo = nuevo;
    }
    c->tamano++;
}

Lugar quitar(Cola *c) {
    if (c->primero == NULL) {
        Lugar vacio = {"", 0, 0};
        return vacio;
    }

    Nodo *eliminado = c->primero;
    Lugar restaurante = eliminado->restaurante;

    c->primero = eliminado->sig;
    if (c->primero == NULL) {
        c->ultimo = NULL;
    }

    free(eliminado);
    c->tamano--;

    return restaurante;
}

void mostrar(Cola *c) {
    printf("Elementos de la cola:\n");

    Nodo *actual = c->primero;
    while (actual != NULL) {
        printf("%s, los mejores en %s y abiertos desde %d\n", actual->restaurante.nombre, actual->restaurante.comida, actual->restaurante.tlf);
        actual = actual->sig;
    }

    printf("\n");
}

int main() {
    Cola *c = crearCola();

    // Agregar elementos a la cola
	Lugar e1 = {"Pizza Hut", "Pizzas", 2001};
    Lugar e2 = {"Jakai", "Sushi", 2023};
    Lugar e3 = {"Burger King", "Hamburguesas", 2002};
    Lugar e4 = {"Chops", "Tequenos", 2005};

    agreg(e1, c);
    agreg(e2, c);
    agreg(e3, c);
    agreg(e4, c);

    // Mostrar elementos de la cola
    mostrar(c);
	
	Lugar eliminado = quitar(c);

    return 0;
}