//Santiago Troconis
//C.I: 30.605.144

#include<stdio.h>
#include<stdlib.h>


typedef struct productos{
    char nombre[50];
    char marca[50];
    char pais[50];
    int precio;
    int disponibilidad;
}productos;


typedef struct nodo{
    productos *dato;
    struct nodo *Siguiente;
}Nodo;


typedef struct pila{
    Nodo *tope;
    int total; 
}Pila;  

productos *Crearproductos(char nombre[50],char marca[50],char pais[50],int precio,int disponibilidad);
Nodo *CrearNodo(productos *productos);
Pila *CrearPila();
int EstaVacia(Pila *pila);
void Insertar(Pila *pila, Nodo *nodo);
void Imprimir(Pila *pila);
void EliminarElemento(Pila *pila);

int main(){
    
	Pila *pila = CrearPila();
    productos *p1 = Crearproductos("Mayonesa", "Mavesa", "Venezuela", 3, 60);
    Nodo *nodo1 = CrearNodo(p1);
    Insertar(pila,nodo1);

    productos *p2 = Crearproductos("Pasta", "Capri", "Venezuela", 2, 24);
    Nodo *nodo2 = CrearNodo(p2);
    Insertar(pila,nodo2);

    productos *p3 = Crearproductos("Arroz", "Mary", "Venezuela", 2, 60);
    Nodo *nodo3 = CrearNodo(p3);
    Insertar(pila,nodo3);

    Insertar(pila, CrearNodo (Crearproductos("Bebida Energetica", "Speed Max", "Venezuela", 1, 200)));

	Insertar(pila, CrearNodo (Crearproductos("Pan de Sandwich", "Bimbo", "Venezuela", 3, 35)));
	
	//Insertar(pila, CrearNodo (Crearproductos("Jamon", "Plumrose", "Colombia", 20, 5)));

    Imprimir(pila);

    EliminarElemento(pila);

    printf("\n");
    printf("\nSe elimino 1 elemento\n");
    printf("\n");
    Imprimir(pila);


    return 0;
}

productos *Crearproductos(char nombre[50],char marca[50],char pais[50],int precio,int disponibilidad){
    productos *aux = (productos*)malloc(sizeof(productos));
    strcpy(aux->nombre, nombre);
    strcpy(aux->marca, marca);
    strcpy(aux->pais, pais);
    aux->precio = precio;
    aux->disponibilidad = disponibilidad;
    
    return aux;
}

Nodo *CrearNodo(productos *productos){
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = productos;
    aux->Siguiente = NULL;

}

Pila *CrearPila(){
    Pila *aux = (Pila*)malloc(sizeof(Pila));
    aux->tope = NULL;
    aux->total = 0;
    return aux;
}

int EstaVacia(Pila *pila){
    if(pila->total == 0){
        return 1;
    }else{
        return 0;
    }
}

void Insertar(Pila *pila, Nodo *aux){
    if(EstaVacia(pila)){
        pila->tope = aux;
    }else{
        aux->Siguiente = pila->tope;
        pila->tope = aux;
    }

    pila->total++;
}

void Imprimir(Pila *pila){
    Nodo *aux = pila->tope;
    productos *t;
    while(aux != NULL){
        t = aux->dato;

        printf("Nombre: %s\n", t->nombre);
        printf("Marca: %s\n", t->marca);
        printf("Pais de origen: %s\n", t->pais);
        printf("Precio: %d $\n", t->precio);
        printf("Cantidad en stock: %d unidades\n", t->disponibilidad);
		 
        printf("\n\n");

        aux = aux->Siguiente;
    }
}

void EliminarElemento(Pila *pila){
    if(pila->tope == NULL){
        printf("No se pudo eliminar, la pila se encuentra vacia\n");
    }else{
        Nodo *aux = pila->tope;
        pila->tope = pila->tope->Siguiente;
        free(aux->dato);
        free(aux);
        pila->total--;
    }
}