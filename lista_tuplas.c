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


void verListaTuplas(LISTA_TUPLAS* lp){
	if(lp !=NULL){
		if(!empty_LP(lp)){
			TUPLA* aux = lp->primero;
			NODO* aux2 = NULL;
			int i =0;
			while(aux!=NULL){
				aux2 = aux->primero;
				while(aux2!=NULL){
					printf(" %d ", aux2->dato);
					aux2 = aux2->sig;
				}
				i++;
				if(i == 18){
					break;
				}
				printf("\n");
				aux=aux->sig;
			}
		}
	}
}
