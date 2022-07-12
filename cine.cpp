//Carlos Gonzalez V27450317
//Programa del cine
#include <conio.h>
#include <stdio.h> //se declaran las librerias necesarias para poder correr el programa
#include <stdlib.h>

//fucion para validar
void clearBuf(void);
int validFormat(const char*, void*); // se declaran la variables globales
int validar=1; //para el funcionamiento de las fucuines
 
char asiento[4][25];
int b,i,j, but;
char a, fila;

void empezar(void);
void reservado(void); //este vacio se utiliza para el uso de las fuciones
void eliminar (void);
void mostrar (void);

int main (){ //inicio del programa
	
	int opc,op1; //se regitran las variables locales
	
	empezar (); //empezar coloca los valores de la matriz en 0 para empezar
	
	opc=1;//inicia el valor del bucle
	
	while(opc==1){//while que repite el programa
		
		mostrar();//muestra en pantalla los asientos
		
			do{//empieza un ciclo para reiniciar en caso de que una opcion este mala
				
				verificacion: //marca un punto en el programa para poder retornar a el
				
					printf("\n\n\tseleccione una opcion\n\n");
					printf("1- reservar asiento\n");
					printf("2- cancelar\n");//se imprime en pantalla las opciones 
					printf("3- salir\n");
					printf("Su opcion es = ");
					
					if(validFormat("%i",&op1)) continue; //validformat nos sirve para ingresar los datos y validarlos
					
					//op1 inicia el switch en cualquiera de sus opciones
					
					validar=op1<=0;//valida la opcion y si es menor saltara un error
			
					if(validar){//if que sirve para imprimir en pantalla el error
				
						printf("\n\nIngreso un numero invalido\n");
						printf("No se aceptan numeros menores o iguales 0\n\n"); //imprime en pantalla el error
			
					}
					
			}while(validar); //que retorna despues de mostrar el error
			
			if(op1>=5 or op1>=999999){ //if que sirve para imprimir en pantalla el error de numeros muy grandes
				
				printf("\n\nIngreso un numero demasiado alto o invalido\n");
				printf("Ingrese una opcion valida\n\n"); //imprime en pantalla el error
			
				goto verificacion; //da la orden para que el programa vaya a un punto de este
				
			}
	
	switch (op1){//inicia el switch
	
		case 1://caso uno reserva un asiento 
			
			printf("\n\tBienvenidos a nuestro cine\n\t Gracias por elegirnos\n");//mensaje de bienvenida
			
			reservado();//llama a la fucion
			
			break;//da una pausa antese de saltar al siguiente paso
			
		case 2://caso que elimina una reserva
			
			printf("\n\tBienvenidos a nuestro cine\n\tDisculpe por no poder complacerlo\n"); //mensaje de bienvenida
			
			eliminar();//llama a la fucion
			
			break;//da una pausa antese de saltar al siguiente paso
		
		case 3://caso que termina el programa
			
			printf("\n\tQue tenga un buen dia :)\n"); //mensaje de despedida
			
			opc=2;//cambia el valor de opc haciendo que while no se repita
			
			break;//caso que termina el programa
			
	}
}
}

//se termina el programa
//declaracion de las fuciones

void empezar(void){//se inicializa la matriz en '0'
	b=0;
	for(i=0;i<4;i++){
		for (j=0;j<25;j++){
			asiento [i][j]='0'; 
		}
	}	
}
void reservado(void){//se cargan las reservas los asientos 
	
	do{
		printf("\n\n\tPor favor ingrese solo mayusculas A,B,C,D\n");
		printf("Ingrese la Letra de la fila : "); //muestra las en pantalla un mensaje
		scanf("%c",&fila);
		
	while(getchar() != '\n');//frena el bucle 
	
	if(fila<'A' or fila>'D' ){//muestra un error si hay un valor erronio
		
		printf("\n\n\tError Ingreso una opcion no valida\n");//imprime el error
		
	}
		
	} while(fila < 'A' or fila > 'D' ); //validacion 
	
		
		verificacion1: //marca un punto en el programa para poder retornar a el
				
			do{//empieza un ciclo para reiniciar en caso de que una opcion este mala
				
				printf("\n\tPor favor ingrese un numero del 1 a 25\n");
				printf("Ingrese numero asiento : "); //imprime las opciones
				
					
		if(validFormat("%d",&but)) continue; //validformat nos sirve para ingresar los datos y validarlos
			
		validar=but<=0;//valida la opcion y si es menor saltara un error
			
		if(validar){//if que sirve para imprimir en pantalla el error
				
			printf("\n\nIngreso un numero invalido\n");
			printf("No se aceptan numeros menores o iguales 0\n\n"); //imprime en pantalla el error
			
		}
		}while(validar); //que retorna despues de mostrar el error
			
		if(but>=26 or but>=999999){ //if que sirve para imprimir en pantalla el error de numeros muy grandes
				
			printf("\n\nIngreso un numero demasiado alto o invalido\n");
			printf("Ingrese una opcion valida\n\n"); //imprime en pantalla el error
			
			goto verificacion1; //da la orden para que el programa vaya a un punto de este
				
		}
		
	printf("\n\n\tGracias por reservar con nosotros ");// muestra un mensaje de agradecimiento
	
	if(fila =='A')
		b=0;
	if(fila =='B') //este marca la fila seleccionada
		b=1;
	if(fila =='C')
		b=2;
	if(fila =='D')
		b=3;
		
	if(asiento[b][but-1]=='X'){ // si el asiento esta ocupado imprime un error
		printf("el asiento %c%i Ya esta reservado\n Ingrese uno no reservado\n\n\n",fila,but);
		reservado();//llama a la fucion
	}else{//en caso de que todo este correcto
	//muestra en pantalla una confirmacion
		printf("Usted eligio la fila %c numero %d\n\n\n", fila, but);
		asiento [b][but-1]= 'X'; //pone el valor x para mostrar que ese asiento esta ocupado
		printf("\tOperacion exitosa\n\n");
	}
	

	
}
void eliminar (void){//elimina sirve para realizar borrar los datos de una reserva anteriormente hecha
	
	do{
		printf("\n\n\tPor favor ingrese solo mayusculas A,B,C,D\n");
		printf("Ingrese la Letra de la fila : "); //imprime en pantalla mensaje
		scanf("%c",&fila);
	
		while(getchar() != '\n');//frena el bucle 
	
		if(fila<'A' or fila>'D' ){//muestra un error si hay un valor erronio
		
			printf("\n\n\tError Ingreso una opcion no valida\n");//imprime el error
		
		}
		
	} while(fila < 'A' or fila > 'D' ); //validacion 
	
	
	verificacion2: //marca un punto en el programa para poder retornar a el
				
			do{//empieza un ciclo para reiniciar en caso de que una opcion este mala
				
				printf("\n\tPor favor ingrese un numero del 1 a 25\n");
				printf("Ingrese numero asiento : ");
				
					
		if(validFormat("%d",&but)) continue; //validformat nos sirve para ingresar los datos y validarlos
			
		validar=but<=0;//valida la opcion y si es menor saltara un error
			
		if(validar){//if que sirve para imprimir en pantalla el error
				
			printf("\n\nIngreso un numero invalido\n");
			printf("No se aceptan numeros menores o iguales 0\n\n"); //imprime en pantalla el error
			
		}
		}while(validar); //que retorna despues de mostrar el error
			
		if(but>=26 or but>=999999){ //if que sirve para imprimir en pantalla el error de numeros muy grandes
				
			printf("\n\nIngreso un numero demasiado alto o invalido\n");
			printf("Ingrese una opcion valida\n\n"); //imprime en pantalla el error
			
			goto verificacion2; //da la orden para que el programa vaya a un punto de este
				
		}
		
	if(fila =='A')
		b=0;
	if(fila =='B') //este marca la fila seleccionada
		b=1;
	if(fila =='C')
		b=2;
	if(fila =='D')
		b=3;
		
	if(asiento[b][but-1]!='X'){//muestra un error en caso de que no alla registro
	
		printf("\n\nel asiento %c%d NO esta reservado por lo tanto ingrese su opcion valida\n\n",fila,but); //imprime el error
		
		eliminar ();//llama la funcion
		
	}else{//en caso de que todo este correcto
		//se muestra un mensaje de confirmacion
		printf("\nDisculpe por no poder entretenerlo esta vez\n");
		printf("Usted elimino el asiento de la fila %c numero %d\n\n", fila, but);
		asiento [b][but-1]= '0';
		
	}

}

void mostrar (void){// muestra en pantalla la butaca disponibles y las que no
	a='A';
	printf("\t");
	for (j=1;j<26;j++){
			printf(" %d ",j);//marca del 1 al 25
		}
		printf("\n"); //muestra en bantalla los valores de la matriz
    for(i=0;i<4;i++){
		printf("%c \n\t", a);
		a= a+1;
		for (j=0;j<25;j++){
			if (j<10)
				printf(" %c ",asiento[i][j]);
			else
				printf(" %c  ",asiento[i][j]);
		}
	printf("\n\n\n");//espacio
	}
	
}
int validFormat(const char* formato, void* variable){ /* Esto es para verificar variables */
	
	validar=1;//reseteamos la comprobacion de la opcion
    /* si se retorna 0 fue porque ocurrio un error*/
    
    if(!scanf(formato, variable) || (getchar() != '\n'))
    {
        
        clearBuf();/* Se utiliza para limpiar el buffer */
        
        printf("\n\n\tError\n\n");
        printf("\n\tUsted Ingreso una opcion no valida\n"); /* Se imprime en pantalla el error */
        printf("\n\tPor favor ingrese una opcion valida\n");
        system("pause");
		
        return 1;
    }
    
    return 0;
}

void clearBuf()
{
    int ch;
    /* Se utiliza para limpiar el buffer */
    while((ch = getchar()) != '\n' && ch != EOF);
}


