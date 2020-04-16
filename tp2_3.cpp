#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){



int filas, columnas, i, j, aleatorio=0, contador; 
int *matriz,*pares;

srand (time(NULL));

filas = 15;
columnas = rand() % 11+5;
matriz = (int*)malloc(filas*columnas*sizeof(int));
pares = (int*)malloc(15*sizeof(int));

//////////CARGO VALORES A LA MATRIZ//////////
for(i=0;i<filas*columnas;i++){
    aleatorio = rand() % 900+100;
    *(matriz+i) = aleatorio;            
}


//////////MUESTRO MATRIZ//////////
printf("Matriz de %d filas y %d columnas:\n",filas,columnas);

for(i=0;i<filas;i++){
	for(j=0;j<columnas;j++){
		printf("%d ",*(matriz+i*columnas+j));
	}
    printf("\n");
}


//////////PARES EN FILAS//////////
printf("\n\n");
for(i=0;i<filas;i++){
	for(j=0;j<columnas;j++){
		if(*(matriz+i*columnas+j) %2 == 0){
			contador++;
		}
	}
	printf("Hay %d numeros pares en la fila %d\n",contador,i+1);
	*(pares+i) = contador; //creando vactor con cantidad de numeros pares por filas
	contador = 0;
}

//////////VECTOR DE NUMEROS PARES POR FILA//////////
printf("\n\nVector de numeros pares por fila: \n");
for(i=0;i<15;i++){
    printf("%d ",*(pares+i));
}


    scanf(" %c");
    return 0;
}