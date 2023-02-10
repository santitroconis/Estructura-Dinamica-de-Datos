//Santiago Troconis C.I:30.605.144

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{

    int dato;
    struct nodo * siguiente;

}NODO;

 NODO * CrearNodo(int dato);
 int InsertarInicio(NODO **cabeza, int dato);
 int InsertarFinal(NODO **cabeza, int dato);
 void ImprimirLista(NODO *cabeza);
 int EstaVacia(NODO *cabeza);
 int ExisteElemento(NODO *, int dato );

int main (){

    NODO *cabeza = NULL ;
    int res ;

    InsertarInicio(&cabeza, 0);
    InsertarInicio(&cabeza, 3);
    InsertarFinal(&cabeza, 6);
    InsertarFinal(&cabeza, 0);
    InsertarFinal(&cabeza, 5);
    InsertarFinal(&cabeza, 1);
    InsertarFinal(&cabeza, 4);
    InsertarFinal(&cabeza, 4);
    ImprimirLista(cabeza);
    res=  ExisteElemento(cabeza , 8 );

    if(res ==1 ){
        printf("\nEl elemento esta en la lista ...");
    }else{
        printf("\nEl elemento NO esta en la lista ...");
    }



    return 0 ;
}

NODO * CrearNodo(int dato){

    NODO *nuevo = NULL;

    nuevo = (NODO*)malloc (sizeof(NODO));

    if (nuevo != NULL){
        nuevo ->dato = dato;
        nuevo ->siguiente = NULL;
    }

    return nuevo;
}
 int InsertarInicio(NODO **cabeza, int dato){

     NODO  *nuevo = NULL;
     nuevo = CrearNodo(dato);
     if(nuevo != NULL){
        nuevo ->siguiente = *cabeza;
        *cabeza =nuevo;
        return 1;
     }

     return 0 ;
 }

void ImprimirLista(NODO *cabeza){

    NODO *nAux = cabeza;

    while( nAux != NULL){
        printf("%d ", nAux ->dato);
        nAux= nAux ->siguiente;
    }

  }

int InsertarFinal(NODO **cabeza, int dato){

   NODO  *nuevo = NULL, *nAux= * cabeza;

   nuevo = CrearNodo(dato);

   if( nuevo != NULL){
        while(nAux ->siguiente!=NULL){
            nAux  = nAux ->siguiente;
        }
        nAux ->siguiente= nuevo;
        return 1;
   }

   return 0 ;
   }


int EstaVacia(NODO *cabeza){
    if(cabeza == NULL){
        return 1 ;
    }else {
        return 0 ;
    }
}

 int ExisteElemento(NODO * cabeza, int dato ){
    NODO *nAux = cabeza;

    while(nAux != NULL){
        if(nAux ->dato== dato){
            return 1;
        }
        nAux  = nAux ->siguiente;
    }

    return 0 ;
 }
