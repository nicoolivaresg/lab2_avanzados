#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct nodo{
	int dato;
	struct nodo * sig;
}NODO;

typedef struct tupla{
	NODO * primero;
	NODO * ultimo;
	struct tupla * sig;
}TUPLA;

typedef struct lista_tuplas{
	TUPLA* primero;
	TUPLA* ultimo;
}LISTA_TUPLAS;

LISTA_TUPLAS* crearListaTuplas(){
	LISTA_TUPLAS * nueva_lista_tuplas = (LISTA_TUPLAS*)malloc(sizeof(LISTA_TUPLAS));
	nueva_lista_tuplas->primero =NULL;
	nueva_lista_tuplas->ultimo =NULL;
	return nueva_lista_tuplas;
}

int empty(TUPLA* tupla){
	if(tupla!=NULL){
		if(tupla->primero==NULL && tupla->ultimo==NULL){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

int empty_LP(LISTA_TUPLAS* lp){
	if(lp!=NULL){
		if(lp->primero==NULL && lp->ultimo==NULL){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

TUPLA* crearTupla(){
	TUPLA * nueva_tupla = (TUPLA*)malloc(sizeof(TUPLA));
	nueva_tupla->primero =NULL;
	nueva_tupla->ultimo =NULL;
	nueva_tupla->sig =NULL;
	return nueva_tupla;
}

NODO* crearNodo(int x){
	NODO * nuevo_nodo = (NODO*)malloc(sizeof(NODO));
	nuevo_nodo->dato = x;
	nuevo_nodo->sig = NULL;
	return nuevo_nodo;
}

void verTupla(TUPLA* tupla){
	if(tupla !=NULL){
		if(!empty(tupla)){
			NODO* aux = tupla->primero;
			while(aux!=NULL){
				printf(" %d ", aux->dato);
				aux=aux->sig;
			}
			printf("\n");
		}
	}
}

LISTA_TUPLAS* eliminar_inicio_LP(LISTA_TUPLAS* lp){
	if(lp!=NULL){
		if(empty_LP(lp)){
			return NULL;
		}else{
			TUPLA* aux = lp->primero;
			if(aux->sig == NULL){
				lp->primero=NULL;
				lp->ultimo=NULL;
				free(aux);
				return lp;
			}else{
				lp->primero = aux->sig;
				free(aux);
				return lp;
			}
		}
	}else{
		return NULL;
	}
	return NULL;
}

LISTA_TUPLAS* eliminar_final_LP(LISTA_TUPLAS * lp){
	if(lp!=NULL){
		if(empty_LP(lp)){
			return NULL;
		}else{
			TUPLA* aux = lp->primero;
			if(aux->sig == NULL){
				lp->primero=NULL;
				lp->ultimo=NULL;
				free(aux);
				return lp;
			}else{
				while(aux->sig!=lp->ultimo){
					aux =aux->sig;
				}
				aux->sig=NULL;
				free(lp->ultimo);
				lp->ultimo = aux;
				return lp;
			}
		}
	}else{
		return NULL;
	}
	return NULL;
}

LISTA_TUPLAS* insertar_final_LP(LISTA_TUPLAS * lp, TUPLA * nuevo){
	if(lp!=NULL){
		TUPLA* aux = lp->ultimo;
		if(aux==NULL){
			lp->ultimo = nuevo;
			lp->primero = nuevo;
			return lp;
		}else{
			lp->ultimo->sig=nuevo;
			lp->ultimo = nuevo;
			return lp;
		}
	}else{
		return NULL;
	}
	return NULL;
}

LISTA_TUPLAS* insertar_inicio_LP(LISTA_TUPLAS* lp, TUPLA * nuevo){
	if(lp!=NULL){
		TUPLA* aux = lp->primero;
		if(aux==NULL){
			lp->primero = nuevo;
			lp->ultimo = nuevo;
		}else{
			nuevo->sig= aux;
			lp->primero = nuevo;
		}
		return lp;
	}else{
		return NULL;
	}
	return NULL;
}

TUPLA* eliminar_inicio(TUPLA* tupla){
	if(tupla!=NULL){
		if(empty(tupla)){
			return NULL;
		}else{
			NODO* aux = tupla->primero;
			if(aux->sig == NULL){
				tupla->primero=NULL;
				tupla->ultimo=NULL;
				free(aux);
				return tupla;
			}else{
				tupla->primero = aux->sig;
				free(aux);
				return tupla;
			}
		}
	}else{
		return NULL;
	}
	return NULL;
}

TUPLA* eliminar_final(TUPLA * tupla){
	if(tupla!=NULL){
		if(empty(tupla)){
			return NULL;
		}else{
			NODO* aux = tupla->primero;
			if(aux->sig == NULL){
				tupla->primero=NULL;
				tupla->ultimo=NULL;
				free(aux);
				return tupla;
			}else{
				while(aux->sig!=tupla->ultimo){
					aux =aux->sig;
				}
				aux->sig=NULL;
				free(tupla->ultimo);
				tupla->ultimo = aux;
				return tupla;
			}
		}
	}else{
		return NULL;
	}
	return NULL;
}

TUPLA* insertar_final(TUPLA * tupla, int x){
	if(tupla!=NULL){
		NODO* aux = tupla->ultimo;
		NODO * nuevo = crearNodo(x);
		if(aux==NULL){
			tupla->ultimo = nuevo;
			tupla->primero = nuevo;
			return tupla;
		}else{
			tupla->ultimo->sig=nuevo;
			tupla->ultimo = nuevo;
			return tupla;
		}
	}else{
		return NULL;
	}
	return NULL;
}

TUPLA* insertar_inicio(TUPLA* tupla, int x){
	if(tupla!=NULL){
		NODO* aux = tupla->primero;
		NODO * nuevo = crearNodo(x);
		if(aux==NULL){
			tupla->primero = nuevo;
			tupla->ultimo = nuevo;
		}else{
			nuevo->sig= aux;
			tupla->primero = nuevo;
		}
		return tupla;
	}else{
		return NULL;
	}
	return NULL;
}

void verListaTuplas(LISTA_TUPLAS* lp){
	if(lp !=NULL){
		if(!empty_LP(lp)){
			TUPLA* aux = lp->primero;
			NODO* aux2 = NULL;
			while(aux!=NULL){
				aux2 = aux->primero;
				while(aux2!=NULL){
					printf(" %d ", aux2->dato);
					aux2 = aux2->sig;
				}
				printf("\n");
				aux=aux->sig;
			}
		}
	}
}

int * lectura(char * ruta, int *n){
	FILE* file=NULL;
	int * resultado  = NULL;
	int i;
	if(ruta!=NULL){
		file = fopen(ruta,"r");
		fscanf(file,"%d",n);
		resultado = (int*)malloc((*n)*sizeof(int));
		for (i = 0; i < (*n); i++)
		{
			resultado[i] = i+1;
		}
	}
	fclose(file);
	return resultado;
}

void entradaAlgoritmo(int * n){
	int conjunto[(*n)]; 
	int i;
	for(i=0; i<(*n); i++){
		conjunto[i] = i+1;
	}
}


void backtracking_bingo(int valor_paso,int * n, int indice, int * conjunto, TUPLA * tupla, LISTA_TUPLAS * resultados){
	
	if(valor_paso == 0)	{ //Caso base recursion
		resultados= insertar_final_LP(resultados,tupla);
		return;
	}

	int i;
	for(i = indice; i<(*n); i++){
		tupla = insertar_final(tupla, conjunto[i]);
		backtracking_bingo(valor_paso-1,n,i+1,conjunto,tupla,resultados);
		tupla = eliminar_final(tupla);
	}

	return;
}



int main(int argc, char * argv[]){
	if(argc<2 || argc>2){
		printf("Ingresa la wea bien\n");
	}else{
		int i,n;
		int * conjunto; 
		conjunto = lectura(argv[1],&n);
		/*
		for (i = 0; i < n; i++)
		{
			printf("%d\n",conjunto[i]);
		}
		*/
//		entradaAlgoritmo(conjunto,&n);
		TUPLA *t1 = crearTupla();
		t1 = insertar_inicio(t1,4);
		t1 = insertar_inicio(t1,1);
		t1 = insertar_inicio(t1,2);
		t1 = insertar_inicio(t1,3);
		TUPLA *t2 = crearTupla();
		t2 = insertar_inicio(t2,100);
		t2 = insertar_inicio(t2,29);
		t2 = insertar_inicio(t2,7);
		t2 = insertar_inicio(t2,1);
		LISTA_TUPLAS * all = crearListaTuplas();
		all = insertar_inicio_LP(all,t1);
		all = insertar_inicio_LP(all,t2);
		verListaTuplas(all);
	}
	
}
