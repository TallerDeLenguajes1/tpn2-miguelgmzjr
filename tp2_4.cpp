#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int velocidad;
	int anio;
	int cantidad;
	char *tipo_cpu;
}PC;


void cargar(PC *p);
void verPC(PC compu);
void listaPC(PC *punt,int num);
void PCvieja(PC *punt,int num);
void mayorVelocidad(PC *punt,int num);

int main(){
	
	PC *computadoras;
	int cant_pc,i,j,cpu,numpc;
	char tipos[6][10] = {"Intel","AMD","Celeron","Athlon","Core","Pentium"};

	srand (time(NULL));

	/*vel = rand()%3+1; 
	cant = rand()%5+1;
	anio_pc = rand()% 18+2000;*/

	
	printf("Ingrese la cantidad de PCs que desea crear: ");
	scanf("%d",&cant_pc);
	computadoras = (PC*)malloc(cant_pc*sizeof(PC));

//////////MUESTRO LOS TIPOS DE CPU QUE HAY//////////
	printf("\nTIPOS DE CPU: \n");
	for(j=0;j<6;j++){
			printf("%d- ",j);
			puts(tipos[j]);
	}
	printf("\n");

///////////PARA ELEGIR TIPO DE CPU Y CARGAR DATOS EN PC//////////
	for(i=0;i<cant_pc;i++){
		printf("Tipo de cpu de la computadora numero %d: ",i);
		scanf("%d",&cpu);

		cargar(computadoras+i);
		computadoras[i].tipo_cpu = *(tipos+cpu);
	}


    printf("\nVer caracteristicas de la PC numero: ");
	scanf("%d",&numpc);
	while(numpc>cant_pc){
		printf("No existe el numero de PC ingresado, intente nuevamente: ");
		scanf("%d",&numpc);
	}
	numpc--;
	verPC(computadoras[numpc]);

//////////LISTA DE TODAS LAS PCs///////////
    printf("\nLISTA DE TODAS LAS PC\n");
	listaPC(computadoras,cant_pc);


//////////PC MAS VIEJA///////////
printf("\nPC MAS VIEJA\n");
PCvieja(computadoras,cant_pc);


//////////PC DE MAYOR VELOCIDAD//////////
    printf("PC DE MAYOR VELOCIDAD\n");
    mayorVelocidad(computadoras,cant_pc);




scanf(" %c");
return 0;
}





////////////////////////////////////////FUNCIONES/////////////////////////////////////////////////////
void cargar(PC *p){
    int cant,vel,anio_pc;
    char tipos[6][10] = {"Intel","AMD","Celeron","Athlon","Core","Pentium"};

    vel = rand()%3+1; 
	cant = rand()%5+1;
	anio_pc = rand()% 18+2000;


    p->velocidad = vel;
    p->anio = anio_pc;
    p->cantidad = cant;
}

/////////////////////////////////////////////////////////////////////////////////////////////

void verPC(PC compu){
	printf("Velocidad: %d GHz\n",compu.velocidad);
	printf("Anio de fabricacion: %d\n",compu.anio);
	printf("Cantidad de nucleos: %d\n",compu.cantidad);
	printf("Tipo de procesador: "); puts(compu.tipo_cpu);
	printf("\n\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////

void listaPC(PC *punt,int num){
	int i;

	for(i=0;i<num;i++){
		printf("PC numero %d \n",i+1);
		printf("Velocidad: %d GHz\n",punt[i].velocidad);
		printf("Anio de Fabricacion: %d\n",punt[i].anio);
		printf("Cantidad de nucleos: %d\n",punt[i].cantidad);
		printf("Tipo de procesador: "); puts(punt[i].tipo_cpu); printf("\n");
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

void PCvieja(PC *punt,int num){
	int aux=2018,vieja,i;

	for(i=0;i<num;i++){
		if(punt[i].anio < aux){
			vieja = i;
			aux = punt[i].anio;
		}
	}
	printf("La PC mas vieja es la PC numero %d\n\n",vieja+1);
}

/////////////////////////////////////////////////////////////////////////////////////////////

void mayorVelocidad(PC *punt,int num){
	int aux=0,mayor,i;

	for(i=0;i<num;i++){
		if(punt[i].velocidad > aux){
			mayor = i;
			aux = punt[i].velocidad;
		}
	}
	printf("La PC de mayor velocidad es la PC numero %d",mayor+1);
}