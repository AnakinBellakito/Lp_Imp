
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "Animal.h"
/*
typedef struct Animal{
    void * fuerza;
    char tipo_fuerza;
    void * velocidad;
    char tipo_velocidad;
    void* resistencia;
    char tipo_resistencia;
    int desfase; 
    void (*reproduccion)(struct Animal * padre,struct Animal* madre ,struct Animal* hijo );
    void (*comerHuir)(struct Animal * a1, struct Animal* a2);
}Animal;
*/


//Funcion para probabilidad 50:50

/*************
* int chance50
**************
* Funcion que genera un valor al azar entre 0 y 1
**************
* Input:
* 
**************
* return:
*    int 0 o 1 al azar
**************/
int chanche50(){
        srand(time(0));
        int bajo = 0, alto = 1;
        int num = (rand() %(alto-bajo + 1))+ bajo;
        return num;
    }
//Funcion para probabilidad 1:3 posibilidades

/*************
* int chance3
**************
* Funcion que genera un valor al azar entre 0 o 1 o 2
**************
* Input:
* 
**************
* return:
*    int 0 o 1 o 2 al azar
**************/
int chanche3(){
        srand(time(0));
        int bajo = 0, alto = 2;
        int num = (rand() %(alto-bajo + 1))+ bajo;
        return num;
    }
/*
 void reproducir(struct Animal* padre,struct Animal * madre,struct Animal* hijo){
    void (*reproducir)(struct Animal* padre,struct Animal * madre,struct Animal* hijo);
    }

 void comerHuir(struct Animal* ,struct Animal *){
    void (*comerHuir)(struct Animal*,struct Animal *);
    }
*/
/*
    void (*reproduccionSimple)(struct Animal*padre,struct Animal*madre,struct Animal* hijo);
    void (*reproduccionCruzada)(struct Animal*padre,struct Animal*madre,struct Animal* hijo);
    */

int comparar(struct Animal *a1,struct  Animal *a2) {
    int i,j;
    i = j = 0;
    bool fuerza,vel,res = false;
    bool fuerza1,vel1,res1 = false;

    if(a1->tipo_fuerza == 'c')fuerza = true;
    if(a1->tipo_velocidad == 'c')vel = true;
    if(a1->tipo_resistencia == 'c')res = true;

    if(a2->tipo_fuerza == 'c')fuerza1 = true;
    if(a2->tipo_velocidad == 'c')vel1 = true;
    if(a2->tipo_resistencia == 'c')res1 = true;
    
    //Comienza Fuerza
    if(fuerza == true && fuerza1 == true){
        if (*(int*)a1->fuerza/4 > *(int*)(a2->fuerza)/4) i++;
        else if(*(int*)(a1->fuerza)/4 < *(int*)(a2->fuerza)/4) j++;
    }
    else if(fuerza == true && fuerza1 == false){
          if (*(int*)a1->fuerza/4 > *(int*)(a2->fuerza)) i++;
          else if(*(int*)(a1->fuerza)/4 < *(int*)(a2->fuerza)) j++;

    }
    else if(fuerza == false && fuerza1 == true){
          if (*(int*)a1->fuerza > *(int*)(a2->fuerza)/4) i++;
          else if(*(int*)a1->fuerza < *(int*)(a2->fuerza)/4) j++;

    }
    else if (fuerza == false && fuerza1 == false){
        if (*(int*)a1->fuerza > *(int*)a2->fuerza) i++;
        else if(*(int*)a1->fuerza < *(int*)a2->fuerza) j++;
    
    }
    //Comienza velocidad

    if(vel == true && vel1 == true){
        if (*(int*)a1->velocidad/4 > *(int*)(a2->velocidad)/4) i++;
        else if(*(int*)(a1->velocidad)/4 < *(int*)(a2->velocidad)/4) j++;
    }
    else if(vel == true && vel1 == false){
          if (*(int*)a1->velocidad/4 > *(int*)(a2->velocidad)) i++;
          else if(*(int*)(a1->velocidad)/4 < *(int*)(a2->velocidad)) j++;

    }
    else if(vel == false && vel1 == true){
          if (*(int*)a1->velocidad > *(int*)(a2->velocidad)/4) i++;
          else if(*(int*)a1->velocidad < *(int*)(a2->velocidad)/4) j++;

    }
    else if (vel == false && vel1 == false){
        if (*(int*)a1->velocidad > *(int*)a2->velocidad) i++;
        else if(*(int*)a1->velocidad < *(int*)a2->velocidad) j++;
    
    }
    // comienza resistencia
    
    if(res == true && res1 == true){
        if (*(int*)a1->resistencia/4 > *(int*)(a2->resistencia)/4) i++;
        else if(*(int*)(a1->resistencia)/4 < *(int*)(a2->resistencia)/4) j++;
    }
    else if(res == true && res1 == false){
          if (*(int*)a1->resistencia/4 > *(int*)(a2->resistencia)) i++;
          else if(*(int*)(a1->resistencia)/4 < *(int*)(a2->resistencia)) j++;

    }
    else if(res == false && res1 == true){
          if (*(int*)a1->resistencia > *(int*)(a2->resistencia)/4) i++;
          else if(*(int*)a1->resistencia < *(int*)(a2->resistencia)/4) j++;

    }
    else if (res == false && res1 == false){
        if (*(int*)a1->resistencia > *(int*)a2->resistencia) i++;
        else if(*(int*)a1->resistencia < *(int*)a2->resistencia) j++;
    
    }
       
    
    if (i > j ) return 0;
    else {
        return 1;
    }
}

int getNum(struct Animal*a, char c){
    bool fuerza,vel,res = false;
    bool fuerza2,vel2,res2 = false;
    bool fuerza3,vel3,res3 = false;
    int val;
    
    // bloque de caracter
    if(a->tipo_fuerza == 'c')fuerza = true;
    if(a->tipo_velocidad == 'c')vel = true;
    if(a->tipo_resistencia == 'c')res = true;

    if(fuerza == true && c =='f'){
        val = (*(int*)a->fuerza)/4;
    }
    else if(vel == true && c =='v'){
        val = (*(int*)a->velocidad)/4;
    }
    else if(res == true && c =='r'){
        val = (*(int*)a->resistencia)/4;
    }
    //bloque float
    if(a->tipo_fuerza == 'f')fuerza2 = true;
    if(a->tipo_velocidad == 'f')vel2 = true;
    if(a->tipo_resistencia == 'f')res2 = true;

     if(fuerza2 == true && c =='f'){
        val = *(int*)a->fuerza;
    }
    else if(vel2 == true && c =='v'){
        val = *(int*)a->velocidad;
    }
    else if(res2 == true && c =='r'){
        val = *(int*)a->resistencia;
    }

    //bloque int

    if(a->tipo_fuerza == 'f')fuerza3 = true;
    if(a->tipo_velocidad == 'f')vel3 = true;
    if(a->tipo_resistencia == 'f')res3 = true;

     if(fuerza3 == true && c =='f'){
        val = *(int*)a->fuerza;
    }
    else if(vel3 == true && c =='v'){
        val = *(int*)a->velocidad;
    }
    else if(res3 == true && c =='r'){
        val = *(int*)a->resistencia;
    }

    return val;

}
  

void reproduccionSimple(struct Animal* padre,struct Animal * madre,struct Animal* hijo){
    int n;
     n = comparar(padre,madre);

     if (n ==0){
         hijo->fuerza = padre->fuerza;
         hijo ->velocidad = padre->velocidad;
         hijo ->resistencia = padre->resistencia;



         //tipos
         hijo ->tipo_fuerza = padre ->tipo_fuerza;
         hijo ->tipo_velocidad = padre ->tipo_velocidad;
         hijo ->tipo_resistencia = padre ->tipo_resistencia;

     }
     else if (n ==1) {
         hijo->fuerza = madre->fuerza;
         hijo ->velocidad = madre->velocidad;
         hijo ->resistencia = madre->resistencia;

         //tipos
         hijo ->tipo_fuerza = madre ->tipo_fuerza;
         hijo ->tipo_velocidad = madre ->tipo_velocidad;
         hijo ->tipo_resistencia = madre ->tipo_resistencia;

     }




}

void reproduccionCruzada(struct Animal*padre,struct Animal*madre, struct Animal* hijo){
    int n = comparar(padre,madre);
    if (n ==0){
         hijo->fuerza = padre->fuerza;
         hijo ->velocidad = padre->velocidad;
         hijo ->resistencia = madre->resistencia;
         hijo->reproduccion = padre ->reproduccion;
         hijo -> comerHuir = madre-> comerHuir;
         
         //tipos
         hijo ->tipo_fuerza = padre ->tipo_fuerza;
         hijo ->tipo_velocidad = padre ->tipo_velocidad;
         hijo ->tipo_resistencia = madre ->tipo_resistencia;

     }
     else if (n ==1) {
         hijo->fuerza = madre->fuerza;
         hijo ->velocidad = madre->velocidad;
         hijo ->resistencia = padre->resistencia;
         hijo -> comerHuir = padre-> comerHuir;
         hijo ->reproduccion = madre ->reproduccion;

        //tipos
         hijo ->tipo_fuerza = madre ->tipo_fuerza;
         hijo -> tipo_velocidad = madre ->tipo_velocidad;
         hijo -> tipo_resistencia = padre ->tipo_resistencia;

     }


}
void reproducir(struct Animal *a1, struct Animal *a2, struct Animal *hijo){
    int n;
    n = chanche50();

    if (n == 0)
    {
        //gano primer animal
        (a1->reproduccion)(a1,a2,hijo);
        printf("Se uso la funcion del primer animal");
    }
    else if (n == 1){
        //Gano segundo animal
        (a2->reproduccion)(a2,a1,hijo);
        printf("Se uso la funcion del segundo animal");
    }
    
}
void borrarAnimal(struct Animal *a){
    
  

    a->fuerza = NULL;
    a->velocidad = NULL;
    a->resistencia = NULL;
    a->reproduccion = NULL;
    a->comerHuir = NULL;
    a->tipo_fuerza = 'z';
    a->tipo_velocidad = 'z';
    a->tipo_resistencia = 'z';
    a->desfase = 0;

    free(a->fuerza);
    free(a->velocidad);
    free(a->resistencia);
 
   
    
   
}

void comerSiempre(struct Animal* a1,struct Animal* a2) {
  
    int val_a1,val_a2;
    val_a1 = getNum(a1,'f');
    val_a2 = getNum(a2,'r');

     if (val_a1 > val_a2)  borrarAnimal(a2);
    // muere animal 2
    else if (val_a1 < val_a2) borrarAnimal(a1);
    //Muere animal 1

    
}


void huirSiempre(struct Animal* a1, struct Animal* a2){

     int vel_a1,vel_a2;

    vel_a1 = getNum(a1,'v');
    vel_a2 = getNum(a2,'v');

    if (a1->velocidad > a2->velocidad)   a1->desfase = 1;
        //poner contador dentro de struct x ,y que hay que moverse
       
    // a1 se debe mover a la casilla izq <- o espacio libre

    if (vel_a2 >= vel_a1 ) borrarAnimal(a1);   // animal a1 se muere free(a1);

}

void comerAleatorio(struct Animal* a1,struct  Animal* a2){
    int n,m;
 
   
    int a1_f,a1_v,a1_r;
    int a2_f,a2_v,a2_r;
    a1_f = getNum(a1,'f');
    a1_v = getNum(a1,'v');
    a1_r = getNum(a1,'r');
    a2_f = getNum(a2,'f');
    a2_v = getNum(a2,'v');
    a2_r = getNum(a2,'r');
    n = chanche3();
    m = chanche3();
    
    
    for(int i = 0; i<=n; i++){
        if (i == n){
            for(int j =0; j<=m;j++){
                if(j == m ){
                    switch (i)
                    {
                    case 0:
                        if (m == 0){
                            if (a1_f > a2_f) {
                                borrarAnimal(a2);
                                    
                                }
                            else if (a2_f > a1_f) {
                                borrarAnimal(a1);
                                
                            }

                        }
                        else if(m ==1){
                             if (a1_f >a2_v) {
                             borrarAnimal(a2);
                             
                            }
                            else if (a2_v > a1_f) {
                                borrarAnimal(a1);
                                
                                }
                        }
                        else if(m == 2){
                            if (a1_f > a2_r) {
                                borrarAnimal(a2);
                                
                                }
                            else if (a2_r > a1_f) {
                                borrarAnimal(a1);
                                
                                }
                        }
                        break;
                    case 1:
                        if (m == 0){
                            if (a1_v > a2_f) {
                                
                               borrarAnimal(a2);
                                }
                            else if (a2_f > a1_v) {
                                borrarAnimal(a1);
                                
                            }
                        }
                        else if(m ==1){
                             if (a1_v > a2_v) {
                                 borrarAnimal(a2);
                                 
                             }
                            else if (a2_v > a1_f){
                                borrarAnimal(a1);
                                
                            }

                        }
                        else if(m == 2){
                            if (a1_v > a2_r) {
                                borrarAnimal(a2);
                                
                            }
                            else if (a2_r > a1_v){
                                borrarAnimal(a1);
                                
                            }
                        }
                        break;
                    case 2:
                        if (m == 0){
                            if (a1_r > a2_f) {
                                borrarAnimal(a2);
                                
                            }
                            else if (a2_f > a1_r){
                                borrarAnimal(a1);
                                
                            }

                        }
                        else if(m ==1){
                             if (a1_r > a2_v) {
                                 borrarAnimal(a2);
                                 
                             }
                            else if (a2_v > a1_r) {
                                borrarAnimal(a1);
                                
                            }


                        }
                        else if(m == 2){
                            if (a1_r > a2_r) {
                                borrarAnimal(a2);
                                
                            }
                            else if (a2_r > a1_r) {
                                borrarAnimal(a1);
                                
                            }

                        }

                    default:
                        borrarAnimal(a1);
                        break;
                    }
                }
            }
        }
    }
    

}


void comerOHuir(struct Animal *a1, struct Animal *a2){
    int n;
    n = chanche50();

    if (n == 0)
    {
        //gano primer animal
        (a1->comerHuir)(a1,a2);
        printf("Se uso la funcion del primer animal");
    }
    else if (n == 1){
        //Gano segundo animal
        (a2->comerHuir)(a2,a1);
        printf("Se uso la funcion del segundo animal");
    }
    
}
void mostrarAnimal(struct Animal *a){
   
    char c;
    //fuerza
    
    c = a->tipo_fuerza;
    if(c == 'e'){
        printf("fuerza: %d  \n", *(int*)a->fuerza);
    }
    else if (c == 'f'){
        printf("fuerza: %f  \n", *(float*)a->fuerza);
    }
    else if (c == 'c' ){

        printf("fuerza: %c  \n", *(char*)a->fuerza);
    }

   //Velocidad


    c = a->tipo_velocidad;
    if(c == 'e'){
        printf("velocidad: %d  \n", *(int*)a->velocidad);
    }
    else if (c == 'f'){
        printf("velocidad: %f  \n", *(float*)a->velocidad);
    }
    else if (c == 'c' ){
   
        printf("velocidad: %c  \n", *(char*)a->velocidad);
        
    }


    //Resistencia

    c = a->tipo_resistencia;
    if(c == 'e'){
        printf("resistencia: %d  \n", *(int*)a->resistencia);
    }
    else if (c == 'f'){
        printf("resistencia: %f  \n", *(float*)a->resistencia);
    }
    else if (c == 'c' ){
        printf("resistencia: %c  \n", *(char*)a->resistencia);

    }

}


/*
void (*reproduccionSimple)(struct Animal*padre,struct Animal*madre,struct Animal* hijo);
void (*reproduccionCruzada)(struct Animal*padre,struct Animal*madre,struct Animal* hijo);
*/

void crearAnimal(struct Animal *a1){
    //Toma de input para rellenar struct

    printf("Ingrese tipo_fuerza: ");
    char c;
    int e;
    float f;

    scanf("%s",&c);
    
    a1->tipo_fuerza = c; 
    
    
    if(a1->tipo_fuerza == 'e'){
        a1->fuerza = malloc(sizeof(int));
        printf("Ingrese Valor: ");
        scanf("%d", &e);
        *(int*)a1->fuerza = e;
       
        
    }
    else if(a1->tipo_fuerza == 'f'){
        a1->fuerza = malloc(sizeof(float));
        printf("Ingrese Valor: ");
        scanf("%f", &f);
        *(float*)a1->fuerza = f;
        
       
    }
    
    else if(a1->tipo_fuerza == 'c'){
        a1->fuerza = malloc(sizeof(char));
        printf("Ingrese Valor: ");
        scanf("%s", &c);
        //c = (int)c/4;
        
        *(char*)a1->fuerza = c;
       
       
    
    }
     printf("\n");
    printf("\n");
       

    printf("Ingrese tipo de velocidad: ");
    scanf("%s",&c);
    
    a1->tipo_velocidad = c; 
    
    printf("%c\n", a1->tipo_velocidad);
    if(a1->tipo_velocidad == 'e'){
        a1->velocidad = malloc(sizeof(int));
        printf("Ingrese Valor: ");
        scanf("%d", &e);
        *(int*)a1->velocidad = e;
        
        
    }
    else if(a1->tipo_velocidad == 'f'){
        a1->velocidad = malloc(sizeof(float));
        printf("Ingrese Valor: ");
        scanf("%f", &f);
        *(float*)a1->velocidad = f;
       
       
    }
    
    else if(a1->tipo_velocidad == 'c'){
        a1->velocidad = malloc(sizeof(char));
       printf("Ingrese Valor: ");
        scanf("%s", &c);
        
        *(char*)a1->velocidad = c;
        
       
    
    }

     printf("\n");
    printf("\n");
       

    
    
    printf("Ingrese tipo de resistencia: ");
    scanf("%s",&c);
    
    a1->tipo_resistencia = c; 
    
    
    if(a1->tipo_resistencia == 'e'){
        a1->resistencia = malloc(sizeof(int));
        printf("Ingrese valor: ");
        scanf("%d", &e);
        *(int*)a1->resistencia = e;
        
        
    }
    else if(a1->tipo_resistencia == 'f'){
        a1->resistencia = malloc(sizeof(float));
        printf("Ingrese valor: ");
        
        scanf("%f", &f);
        *(float*)a1->resistencia = f;
       
       
    }
    
    else if(a1->tipo_resistencia == 'c'){
        a1->resistencia = malloc(sizeof(char));
        printf("Ingrese valor: ");
       
        scanf("%s", &c);
        
        *(char*)a1->resistencia = c;
        
       
    
    }

   a1->desfase = 0;
   
    //Area de pruebas comentadas
    /*
    printf("char %c : \n",c);
    printf("int %d : \n",e);
    printf("float %f : \n",f);
    c = 'u';
    e = 19;
    f = 2.78;
    
    printf("\n");
    printf("\n");
       
        //Termino area toma de Datos
    

        
    printf("char %c : \n",c);
    printf("int %d : \n",e);
    printf("float %f : \n",f);
    printf("\n");
    printf("\n");

    printf("%c\n", a1->tipo_fuerza);
    printf("int %d : \n",*(int*)a1->fuerza);
    printf("float %f : \n",*(float*)a1->fuerza);
    printf("char %c : \n",*(char*)a1->fuerza);

 
    printf("\n");
    printf("\n");

    printf("%c\n", a1->tipo_velocidad);
    printf("int %d : \n",*(int*)a1->velocidad);
    printf("float %f : \n",*(float*)a1->velocidad);
    printf("char %c : \n",*(char*)a1->velocidad);

    printf("\n");
    printf("\n");

    printf("%c\n", a1->tipo_resistencia);
    printf("int %d : \n",*(int*)a1->resistencia);
    printf("float %f : \n",*(float*)a1->resistencia);
    printf("char %c : \n",*(char*)a1->resistencia);
    */
    
    
    //comenzar puntero a resproduccion
    printf("Area de reproduccion: \n");
    printf("Ingrese 1 para SR o 2 para MR : \n");

    

    
	scanf("%c\n", &c);
	printf("%c\n", c);
    
    if (c== '1'){
      //a1 ->reproducir = malloc(sizeof(*reproduccionSimple));
      a1->reproduccion = reproduccionSimple;

    
    }
    else if(c == '2'){
      
      //a1 ->reproducir = malloc(sizeof(*reproduccionCruzada));
      a1 ->reproduccion = reproduccionCruzada;
    
     


    }
    printf("Area de Comer o huir: \n");
    printf("Ingrese 1 para comerSiempre ; 2 para huirSiempre; 3 para comerAleatorio:  \n");

	scanf("%d\n", &e);
  
    if(e == 1){
        a1 -> comerHuir = comerSiempre;

    }
    else if(e == 2) {
        a1-> comerHuir = huirSiempre;

    }
    else if(e == 3) {
        a1 -> comerHuir = comerAleatorio;
    }





   
    //free(a1->reproducir);
    //free(a1->comerHuir);
}



/*
void crearSimple(Animal * a1,void (*reproduccionSimple)(Animal*padre,Animal*madre,Animal* hijo)){
    a1->reproducir= reproduccionSimple;
}

void crearCruzado(Animal *a1 , void (*reproduccionCruzada)(Animal*padre,Animal*madre,Animal* hijo)){
    a1 ->reproducir = reproduccionCruzada;
}

*/

/*
int main() {

    

    Animal*b = (Animal*)malloc(sizeof(Animal));

    crearAnimal(b);
    mostrarAnimal(b);
    borrarAnimal(b);

    
    return 0;
}

*/




