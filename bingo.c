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

void imprimirTupla(FILE* file, TUPLA* tupla){
	if(tupla !=NULL && file !=NULL){
		if(!empty(tupla)){
			NODO* aux = tupla->primero;
			fprintf(file,"[");
			while(aux!=NULL){
				if(aux->sig == NULL){
					fprintf(file,"%d]", aux->dato);
				}else{
					fprintf(file,"%d ", aux->dato);
				}
				aux=aux->sig;
			}
			fprintf(file,"\n");
		}
	}
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


void lectura(char * ruta,int *n){
	FILE* file=NULL;
	int i;
	if(ruta!=NULL){
		file = fopen(ruta,"r");
		fscanf(file,"%d",n);
	}
	fclose(file);
}

void backtracking_bingo(int n, int valor_paso, int indice, TUPLA * tupla,int * conjunto,  FILE * file){	
	if(valor_paso == 0)	{ //Caso base recursion
		imprimirTupla(file,tupla);
		return; 
		//sin este return sería fuerza bruta 
		//porque igual consideraria el siguiente elemento despues de los 8
	}

	int i;
	for(i = indice; i<n; i++){
		tupla = insertar_final(tupla, conjunto[i]);
		backtracking_bingo(n,(valor_paso-1),(i+1),tupla,conjunto,file);
		tupla = eliminar_final(tupla);

	}
	return;
	
}

void entradaAlgoritmo(int * n){
	int * conjunto = (int*)malloc((*n)*sizeof(int)); 
	int i,j;
	for(i=0; i<(*n); i++){
		conjunto[i] = i+1;
	}
	FILE * file = fopen("SALIDA.txt","w");
	for(j=(*n);j<=20;j++){
		conjunto[(*n)-1] = j;
		fprintf(file,"Conjunto:\n[");
		for(i=0;i<(*n);i++){
			if(i+1==(*n)){
				fprintf(file,"%d]", conjunto[i]);
			}else{
				fprintf(file,"%d ", conjunto[i]);
			}
		}
		fprintf(file, "\nSubconjuntos:\n");
		TUPLA * tupla = crearTupla();
		backtracking_bingo((*n),8,0,tupla,conjunto,file);//llamado a la recursion
	}
	fclose(file);
}

int main(int argc, char * argv[]){
	if(argc<2 || argc>2){
		printf("Ingrese la cantidad de argumentos necesarios\n");
	}else{
		int n;
		lectura(argv[1],&n);
		entradaAlgoritmo(&n);
		printf("Revise el archivo SALIDA.txt\n");
	}
	
}
