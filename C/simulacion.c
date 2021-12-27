#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <math.h>
#include "Animal.h"
#include <stdbool.h>


#define MAXSIZE 1000
Animal ** world;

/*************
* int chance4
**************
* Funcion que genera un valor al azar entre 0 
**************
* Input:
* 
**************
* return:
*    int 0 o 1 al azar
**************/
int chanche4(){ // probabilidad 1/4
        srand(time(0));
        int bajo = 0, alto = 3;
        int num = (rand() %(alto-bajo + 1))+ bajo;
        return num;
}
 
/*************
* bool isOcupado
**************
* Funcion checkea si uno de los tipos tiene valor z => esta desocupado
* otro caso ocupado
**************
* Input:
*  Animal * a1: Puntero animal que sera pasado por referencia
**************
* return:
*    bool retorna true si lo esta || false desocupado
**************/
bool isOcupado(struct Animal* a1){

    bool flag =  true;
    if(a1->tipo_resistencia == 'z'){
        flag = false;

    }
    return flag;

}
/*************
* void getMemoria
**************
* Funcion que asigna memoria a los punteros fuerza,velocidad,resistencia
        Asigna memoria a la posicion [x2][y2] repecto al tipo de [x][y]
****************
* Input:
*  Animal ** mundo: Puntero de punteros animal que sera pasado por referencia 
*  int x : posicion x matriz;
*  int y : posicion y matriz;
*  int x2 : posicion x2 matriz;
*  int y2 : posicion y2 matriz;
**************
* return:
*    void , no retorna nada, pide memoria y nada mas.
**************/
void getMemoria(Animal ** mundo, int x, int y,int x2,int y2) {
    
    
    if(mundo[x][y].tipo_fuerza == 'e'){
            mundo[x2][y2].fuerza =malloc(sizeof(int));
        
        }
        else if (mundo[x][y].tipo_fuerza== 'f'){
            mundo[x2][y2].fuerza =malloc(sizeof(float));

        }
        else if (mundo[x][y].tipo_fuerza  == 'c'){
            mundo[x2][y2].fuerza =malloc(sizeof(char));
        }


            //Asiganmos memoria a los nuevos punteros resistencia
        if(mundo[x][y].tipo_resistencia == 'e'){
            mundo[x2][y2].resistencia =malloc(sizeof(int));
        
        }
        else if (mundo[x][y].tipo_resistencia == 'f'){
            mundo[x2][y2].resistencia =malloc(sizeof(float));

        }
        else if (mundo[x][y].tipo_resistencia  == 'c'){
            mundo[x2][y2].resistencia =malloc(sizeof(char));
        }


            //Asiganmos memoria a los nuevos punteros velocidad
        if(mundo[x][y].tipo_velocidad == 'e'){
            mundo[x2][y2].velocidad =malloc(sizeof(int));
        
        }
        else if (mundo[x][y].tipo_velocidad == 'f'){
            mundo[x2][y2].velocidad =malloc(sizeof(float));

        }
        else if (mundo[x][y].tipo_velocidad  == 'c'){
            mundo[x2][y2].velocidad =malloc(sizeof(char));
        }


}

/*************
* int lugarHijo
**************
* Funcion que debe buscar el espacio vacio en la matriz siguiendo este orden <- ^ -> v devuelve 0 , 1 , 2, 3 respectivamente
**************
* Input:
*  Animal ** mundo: Puntero de punteros animal que sera pasado por referencia 
*  int i : posicion i matriz;
*  int j : posicion j matriz;
**************
* return:
*    int retorna 0 o 1 o 2 o 3 para espacio vacio en matriz
**************/
int lugarHijo(Animal** mundo,int i, int j){//pasar casilla central
    int nx_up,nx_down,ny_left,ny_right,pos;
    bool flag;
    
    nx_up = i + 1;
    nx_down = i -1;
    ny_left = j -1;
    ny_right = j+1;
    
    if (i == 0) nx_up = 999;
    else if (i == 999) nx_down = 0;
    
    if ( j == 0) ny_left = 999;
    else if(j == 999) ny_right = 0;
  


    for (int t = 0; t < 4; t++)
    {
        pos = t;
        if (t == 0)
        { 
            flag = isOcupado(&mundo[i][ny_left]);
            
        }
         else if (t == 1)
        { 
            flag = isOcupado(&mundo[nx_up][j]);
        }
         else if (t == 2)
        { 
            flag = isOcupado(&mundo[i][ny_right]);
        }
         else if (t == 3)
        { 
            flag = isOcupado(&mundo[nx_down][j]);

        }

        if(flag == false){
            break;
        }
      
    }
    if (flag == true){
        pos = -1;
    }

    return pos;
    
}
/*************
* void movAbajo
**************
* Funcion que debe copiar los contenidos de la matriz [i][j] una posicion abajo
**************
* Input:
*  Animal ** mundo: Puntero de punteros animal que sera pasado por referencia 
*  int x : posicion x matriz;
*  int y : posicion y matriz;
**************
* return:
*    void no retorna nada
**************/
void movAbajo(Animal ** mundo,int x,int y){
   





        
    if(x == 999){
        int sig = 0;
       

        int ny;
        ny = y;
         getMemoria(mundo,x,y,sig,ny);



        mundo[sig][y].fuerza = mundo[x][y].fuerza;
        mundo[sig][y].velocidad = mundo[x][y].velocidad;
        mundo[sig][y].resistencia = mundo[x][y].resistencia;
        mundo[sig][y].tipo_fuerza = mundo[x][y].tipo_fuerza;
        mundo[sig][y].tipo_resistencia = mundo[x][y].tipo_resistencia;
        mundo[sig][y].tipo_velocidad = mundo[x][y].tipo_velocidad;
        mundo[sig][y].reproduccion = mundo[x][y].reproduccion;
        mundo[sig][y].comerHuir = mundo[x][y].comerHuir;

        mundo[x][y].fuerza = NULL;
        mundo[x][y].velocidad= NULL;
        mundo[x][y].resistencia= NULL;
        mundo[x][y].tipo_fuerza= 'z';
        mundo[x][y].tipo_resistencia= 'z';
        mundo[x][y].tipo_velocidad= 'z';
        mundo[x][y].reproduccion= NULL;
        mundo[x][y].comerHuir= NULL;



    }
    else{
         int nx = x+1;
           
           int ny;
            ny = y;
         getMemoria(mundo,x,y,nx,ny);

        

         mundo[nx][y].fuerza = mundo[x][y].fuerza;
        mundo[nx][y].velocidad = mundo[x][y].velocidad;
        mundo[nx][y].resistencia = mundo[x][y].resistencia;
        mundo[nx][y].tipo_fuerza = mundo[x][y].tipo_fuerza;
        mundo[nx][y].tipo_resistencia = mundo[x][y].tipo_resistencia;
        mundo[nx][y].tipo_velocidad = mundo[x][y].tipo_velocidad;
        mundo[nx][y].reproduccion = mundo[x][y].reproduccion;
        mundo[nx][y].comerHuir = mundo[x][y].comerHuir;

        mundo[x][y].fuerza = NULL;
        mundo[x][y].velocidad= NULL;
        mundo[x][y].resistencia= NULL;
        mundo[x][y].tipo_fuerza= 'z';
        mundo[x][y].tipo_resistencia= 'z';
        mundo[x][y].tipo_velocidad= 'z';
        mundo[x][y].reproduccion= NULL;
        mundo[x][y].comerHuir= NULL;


    }
    borrarAnimal(&mundo[x][y]);
}

/*************
* void movIzquierdo
**************
* Funcion que debe copiar los contenidos de la matriz [i][j] una posicion a la izquierda
**************
* Input:
*  Animal ** mundo: Puntero de punteros animal que sera pasado por referencia 
*  int x : posicion x matriz;
*  int y : posicion y matriz;
**************
* return:
*    void no retorna nada
**************/
void movIzquierda(Animal ** mundo,int x,int y){
   
    if(y == 0){
        int sig = 999;
        
        int nx;
        nx = x;
    
         getMemoria(mundo,x,y,nx,sig);
        
        mundo[x][sig].fuerza = mundo[x][y].fuerza;
        mundo[x][sig].velocidad = mundo[x][y].velocidad;
        mundo[x][sig].resistencia = mundo[x][y].resistencia;
        mundo[x][sig].tipo_fuerza = mundo[x][y].tipo_fuerza;
        mundo[x][sig].tipo_resistencia = mundo[x][y].tipo_resistencia;
        mundo[x][sig].tipo_velocidad = mundo[x][y].tipo_velocidad;
        mundo[x][sig].reproduccion = mundo[x][y].reproduccion;
        mundo[x][sig].comerHuir = mundo[x][y].comerHuir;

        mundo[x][y].fuerza = NULL;
        mundo[x][y].velocidad= NULL;
        mundo[x][y].resistencia= NULL;
        mundo[x][y].tipo_fuerza= 'z';
        mundo[x][y].tipo_resistencia= 'z';
        mundo[x][y].tipo_velocidad= 'z';
        mundo[x][y].reproduccion= NULL;
        mundo[x][y].comerHuir= NULL;



    }
    else{
         int ny = y-1;
           int nx;
            nx =x;

         getMemoria(mundo,x,y,nx,ny);

         mundo[x][ny].fuerza = mundo[x][y].fuerza;
        mundo[x][ny].velocidad = mundo[x][y].velocidad;
        mundo[x][ny].resistencia = mundo[x][y].resistencia;
        mundo[x][ny].tipo_fuerza = mundo[x][y].tipo_fuerza;
        mundo[x][ny].tipo_resistencia = mundo[x][y].tipo_resistencia;
        mundo[x][ny].tipo_velocidad = mundo[x][y].tipo_velocidad;
        mundo[x][ny].reproduccion = mundo[x][y].reproduccion;
        mundo[x][ny].comerHuir = mundo[x][y].comerHuir;

        mundo[x][y].fuerza = NULL;
        mundo[x][y].velocidad= NULL;
        mundo[x][y].resistencia= NULL;
        mundo[x][y].tipo_fuerza= 'z';
        mundo[x][y].tipo_resistencia= 'z';
        mundo[x][y].tipo_velocidad= 'z';
        mundo[x][y].reproduccion= NULL;
         mundo[x][y].comerHuir= NULL;


    }
     borrarAnimal(&mundo[x][y]);
}


/*************
* void movDerecha
**************
* Funcion que debe copiar los contenidos de la matriz [i][j] una posicion derecha
**************
* Input:
*  Animal ** mundo: Puntero de punteros animal que sera pasado por referencia 
*  int x : posicion x matriz;
*  int y : posicion y matriz;
**************
* return:
*    void no retorna nada
**************/
void movDerecha(Animal ** mundo,int x,int y){
   
    if(y == 999){
        int sig = 0;

          
          
          

         getMemoria(mundo,x,y,x,sig);
        mundo[x][sig].fuerza = mundo[x][y].fuerza;
        mundo[x][sig].velocidad = mundo[x][y].velocidad;
        mundo[x][sig].resistencia = mundo[x][y].resistencia;
        mundo[x][sig].tipo_fuerza = mundo[x][y].tipo_fuerza;
        mundo[x][sig].tipo_resistencia = mundo[x][y].tipo_resistencia;
        mundo[x][sig].tipo_velocidad = mundo[x][y].tipo_velocidad;
        mundo[x][sig].reproduccion = mundo[x][y].reproduccion;
        mundo[x][sig].comerHuir = mundo[x][y].comerHuir;

        mundo[x][y].fuerza = NULL;
        mundo[x][y].velocidad= NULL;
        mundo[x][y].resistencia= NULL;
        mundo[x][y].tipo_fuerza= 'z';
        mundo[x][y].tipo_resistencia= 'z';
        mundo[x][y].tipo_velocidad= 'z';
        mundo[x][y].reproduccion= NULL;
        mundo[x][y].comerHuir= NULL;



    }
    else{
         int ny = y+1;
        
          
         getMemoria(mundo,x,y,x,ny);

         mundo[x][ny].fuerza = mundo[x][y].fuerza;
        mundo[x][ny].velocidad = mundo[x][y].velocidad;
        mundo[x][ny].resistencia = mundo[x][y].resistencia;
        mundo[x][ny].tipo_fuerza = mundo[x][y].tipo_fuerza;
        mundo[x][ny].tipo_resistencia = mundo[x][y].tipo_resistencia;
        mundo[x][ny].tipo_velocidad = mundo[x][y].tipo_velocidad;
        mundo[x][ny].reproduccion = mundo[x][y].reproduccion;
        mundo[x][ny].comerHuir = mundo[x][y].comerHuir;

        mundo[x][y].fuerza = NULL;
        mundo[x][y].velocidad= NULL;
        mundo[x][y].resistencia= NULL;
        mundo[x][y].tipo_fuerza= 'z';
        mundo[x][y].tipo_resistencia= 'z';
        mundo[x][y].tipo_velocidad= 'z';
        mundo[x][y].reproduccion= NULL;
        mundo[x][y].comerHuir= NULL;


    }
     borrarAnimal(&mundo[x][y]);
}


/*************
* void movArriba
**************
* Funcion que debe copiar los contenidos de la matriz [i][j] una posicion arriba
**************
* Input:
*  Animal ** mundo: Puntero de punteros animal que sera pasado por referencia 
*  int x : posicion x matriz;
*  int y : posicion y matriz;
**************
* return:
*    void no retorna nada
**************/
void movArriba(Animal ** mundo,int x,int y){
  
    
    if(x == 0){
        int sig = 999;
           getMemoria(mundo,x,y,sig,y);
        mundo[sig][y].fuerza = mundo[x][y].fuerza;
        mundo[sig][y].velocidad = mundo[x][y].velocidad;
        mundo[sig][y].resistencia = mundo[x][y].resistencia;
        mundo[sig][y].tipo_fuerza = mundo[x][y].tipo_fuerza;
        mundo[sig][y].tipo_resistencia = mundo[x][y].tipo_resistencia;
        mundo[sig][y].tipo_velocidad = mundo[x][y].tipo_velocidad;
        mundo[sig][y].reproduccion = mundo[x][y].reproduccion;
        mundo[sig][y].comerHuir = mundo[x][y].comerHuir;

        mundo[sig][y].fuerza = NULL;
        mundo[sig][y].velocidad= NULL;
        mundo[sig][y].resistencia= NULL;
        mundo[sig][y].tipo_fuerza= 'z';
        mundo[sig][y].tipo_resistencia= 'z';
        mundo[sig][y].tipo_velocidad= 'z';
        mundo[sig][y].reproduccion= NULL;
        mundo[sig][y].comerHuir= NULL;



    }
    else{
         int nx = x-1;
           getMemoria(mundo,x,y,nx,y);
         mundo[nx][y].fuerza = mundo[x][y].fuerza;
        mundo[nx][y].velocidad = mundo[x][y].velocidad;
        mundo[nx][y].resistencia = mundo[x][y].resistencia;
        mundo[nx][y].tipo_fuerza = mundo[x][y].tipo_fuerza;
        mundo[nx][y].tipo_resistencia = mundo[x][y].tipo_resistencia;
        mundo[nx][y].tipo_velocidad = mundo[x][y].tipo_velocidad;
        mundo[nx][y].reproduccion = mundo[x][y].reproduccion;
        mundo[nx][y].comerHuir = mundo[x][y].comerHuir;

        mundo[x][y].fuerza = NULL;
        mundo[x][y].velocidad= NULL;
        mundo[x][y].resistencia= NULL;
        mundo[x][y].tipo_fuerza= 'z';
        mundo[x][y].tipo_resistencia= 'z';
        mundo[x][y].tipo_velocidad= 'z';
        mundo[x][y].reproduccion= NULL;
        mundo[x][y].comerHuir= NULL;


    }

    borrarAnimal(&mundo[x][y]);
}




/*************
* void borrarMundo
**************
* Funcion que debe liberar la memoria de los 1000 punteros 
**************
* Input:
*  Animal ** mundo: Puntero de punteros animal que sera pasado por referencia 
**************
* return:
*    void no retorna nada
**************/

void borrarMundo(Animal ** mundo){
    
    
    for(int i = 0; i<MAXSIZE;i++){
        for(int j = 0; j < MAXSIZE;j++){ 
            if(isOcupado(&mundo[i][j])== false){
                free(mundo[i][j].resistencia);
                free(mundo[i][j].fuerza);
                free(mundo[i][j].velocidad);

            }  
        
        }
        free(mundo[i]);
    }
};




/*************
* void mostrarMundo
**************
* Funcion que debe recorrer los 1000 punteros y chekear si la casilla esta ocupada,
*       Si lo esta muestra el animal de esa casilla
**************
* Input:
*  Animal ** mundo: Puntero de punteros animal que sera pasado por referencia 
**************
* return:
*    void no retorna nada
**************/
void mostrarMundo(Animal** mundo){
    
      for(int i = 0; i<MAXSIZE;i++){
        for(int j = 0; j < MAXSIZE;j++){   
            if(mundo[i][j].velocidad != NULL){
                mostrarAnimal(&mundo[i][j]);
                printf(" \n");
            }

        
        }
        
    }

};




/*************
* void move
**************
* Funcion que debe mover a los animales si deben un desfase despues de las acciones de comerOHuir
*************
* Input:
*  Animal ** mundo: Puntero de punteros animal que sera pasado por referencia 
**************
* return:
*    void no retorna nada
**************/
void move(Animal ** mundo, int i , int j){
    int pos2;
    
    if(mundo[i][j].desfase == 1){
        mundo[i][j].desfase = 0;
        pos2 = lugarHijo(mundo, i,j);

        if (pos2 == 0)
        {
            movIzquierda(mundo,i,j);
        }
        else if (pos2 == 1)
        {
            movArriba(mundo,i,j);
        }
        else if (pos2 == 2)
        {
            movDerecha(mundo,i,j);
        }
        else if (pos2 == 3){
            movAbajo(mundo,i,j);

        }
    }
   
    


}


int main(){
    
   //Creacion de matriz 1000 filas de punteros
    world = (Animal **)malloc(sizeof(Animal*)*MAXSIZE);
    for(int i = 0; i<MAXSIZE; i++){
        world[i] = (Animal*)malloc(sizeof(Animal)*MAXSIZE);   

    }
    //Llenamos datos con NULL
    for(int i = 0; i<MAXSIZE;i++){

        for(int j = 0; j < MAXSIZE;j++){
            world[i][j].fuerza = NULL;
            world[i][j].velocidad = NULL;
            world[i][j].resistencia = NULL;
            world[i][j].reproduccion = NULL;
            world[i][j].comerHuir = NULL;
            world[i][j].tipo_fuerza = 'z';
            world[i][j].tipo_velocidad = 'z';
            world[i][j].tipo_resistencia = 'z';
            world[i][j].desfase = 0;
        }
    }

    bool continuar = true;
    int n1;
     printf("Presiona enter para comenzar \n");
    while(continuar == true){
   
    while((getchar())!= '\n');// soluciona problema de buffer scanfgju,mtjgmh

    printf("===========================\n");
    printf("(1). Crear Animal\n");
    printf("(2). Avanzar 1 itearacion en el tiempo\n");
    printf("(3). Mostrar mundo \n");
    printf("(4). Borrar mundo\n");
    printf("===========================\n");

    printf("Ingresa opcion!");
  
    scanf(" %d", &n1);
      

        
        


            if(n1 == 1) {
                int x,y = 0;
                printf("\n");
                printf("Ingresaste 1 Crear Animal \n");
                printf("Ingrese cordenadas x e y:\n");
                
                
                scanf("%d %d", &x,&y);
             

        
                printf("%d %d\n", x,y);

                if( isOcupado(&world[x][y]) == false ) { // espacio vacio
                
                    crearAnimal(&world[x][y]);
                    }
                else{
                    //ocupado hacer algo
                }
                
            
            }
            else if(n1 == 2){
                printf("\n");
                printf("Seleccionaste 2 Avanzar en el tiempo \n");
                int num,ny_left,ny_right,nx_up,nx_down;
                bool flag;
                

              
                for(int i = 0;i <MAXSIZE;i++){
                    for(int j = 0;i <MAXSIZE; i++){
                        num = chanche4();

                
                    if(num == 0)//moversea la izq
                    {
                         nx_up = i + 1;
                         nx_down = i -1;
                         ny_left = j -1;
                         ny_right = j+1;

                        
                        flag =isOcupado(&world[i][ny_left]);

                        if(j == 0 ){
                            ny_left = 999;
                            flag =isOcupado(&world[i][ny_left]);
                                                                        //bloque encargado matriz ciclica en eje x
                        }
                        if(j == 999){
                            ny_right = 0;
                        }
                        if(i == 0){
                            nx_up = 999;

                        }
                        if( i == 999) {
                            nx_down = 0;
                        }
                       
                      
                        
                      

                       

                        if(flag == true){
                            //se reproducen y se pelean
                            int pos;
                            pos = lugarHijo(world,i,ny_left);

                            if(pos == 0){
                                reproducir(&world[i][j],&world[i][ny_left], &world[i][ny_left-1]); //el animal 2 es el central;
                                comerOHuir(&world[i][j],&world[i][ny_left]);
                                move(world,i,j);
                                move(world,i,ny_left);
                            
                                //checkear cntador de movimientos

                            }
                            else if(pos == 1){
                                 reproducir(&world[i][j],&world[i][ny_left], &world[nx_down][ny_left]);
                                 comerOHuir(&world[i][j],&world[i][ny_left]);// tal vez se tiene que mover en el comer o huir
                                 move(world,i,j);
                                 move(world,i,ny_left);
                                
                            }
                           
                            else if(pos == 3){
                                reproducir(&world[i][j],&world[i][ny_left], &world[nx_up][ny_left]);
                                comerOHuir(&world[i][j],&world[i][ny_left]);
                                move(world,i,j);
                                move(world,i,ny_left);
                            }
                            else if(pos == -1){
                                //no hay reproduccion se muere el animal
                                comerOHuir(&world[i][j],&world[i][ny_left]);
                                move(world,i,j);
                                move(world,i,ny_left);
                            }
                        }

                        movIzquierda(world, i,j);
                        
                    } // lista, revisada


                    else if (num == 1){// Mover arriba
                         
                         nx_up = i + 1;
                         nx_down = i -1;
                         ny_left = j -1;
                         ny_right = j+1;

                        
                        flag =isOcupado(&world[nx_down][j]);

                        if(j == 0 ){
                            ny_left = 999;
                            
                                                                        //bloque encargado matriz ciclica en eje x
                        }
                        if(j == 999){
                            ny_right = 0;

                        }
                        if(i == 0){
                            nx_down = 999;
                            flag =isOcupado(&world[nx_down][j]);

                        }
                        if( i == 999) {
                            nx_up = 0;
                        }
                       
                      
                        
                      

                       

                        if(flag == true){
                            //se reproduceny se pelean
                            int pos;
                            pos = lugarHijo(world,nx_down,j);

                            if(pos == 0){
                                reproducir(&world[i][j],&world[nx_down][j], &world[nx_down][j-1]); //el animal 2 es el central;
                                comerOHuir(&world[i][j],&world[nx_down][j]);
                                
                                move(world,i,j);
                                move(world,nx_down,j);
                            
                                

                            }
                            else if(pos == 1){
                                 reproducir(&world[i][j],&world[nx_down][j], &world[nx_down-1][j]);
                                 comerOHuir(&world[i][j],&world[nx_down][j]);// tal vez se tiene que mover en el comer o huir
                                 move(world,i,j);
                                 move(world,nx_down,j);
                                
                            }
                            else if(pos == 2){
                                reproducir(&world[i][j],&world[nx_down][j], &world[nx_down][j+1]);
                                comerOHuir(&world[i][j],&world[nx_down][j]);
                                move(world,i,j);
                                move(world,nx_down,j);
                            }
                
                            else if(pos == -1){
                                //no hay reproduccion se muere el animal
                                comerOHuir(&world[i][j],&world[i][nx_up]);
                                move(world,i,j);
                                move(world,i,nx_up);
                            }
                        }

                        movArriba(world, i,j);
                        //revisada lista
                        
                    }
                    
                    else if (num == 2){
                        //derecha
                        //se reproducen y se pelean

                        nx_up = i + 1;
                         nx_down = i -1;
                         ny_left = j -1;
                         ny_right = j+1;

                        
                        flag =isOcupado(&world[i][ny_right]);

                        if(j == 0 ){
                            ny_left = 999;
                            
                                                                        //bloque encargado matriz ciclica en eje x
                        }
                        if(j == 999){
                            ny_right = 0;
                            flag =isOcupado(&world[i][ny_right]);
                        }
                        if(i == 0){
                            nx_up = 999;

                        }
                        if( i == 999) {
                            nx_down = 0;
                        }
                       

                            int pos;
                            pos = lugarHijo(world,i,ny_right);

                         
                            if(pos == 1){
                                 reproducir(&world[i][j],&world[i][ny_right], &world[nx_down][ny_right]);
                                 comerOHuir(&world[i][j],&world[i][ny_right]);// tal vez se tiene que mover en el comer o huir
                                 move(world,i,j);
                                 move(world,i,ny_right);
                            }
                            else if(pos == 2){
                                reproducir(&world[i][j],&world[i][ny_right], &world[i][ny_right+1]);
                                comerOHuir(&world[i][j],&world[i][ny_right]);
                                move(world,i,j);
                                move(world,i,ny_right);
                            }
                            
                            
                           
                            else if(pos == 3){
                                reproducir(&world[i][j],&world[i][ny_right], &world[nx_up][ny_right]);
                                comerOHuir(&world[i][j],&world[i][ny_right]);
                                move(world,i,j);
                                move(world,i,ny_right);
                            }
                            else if(pos == -1){
                                //no hay reproduccion se muere el animal
                                comerOHuir(&world[i][j],&world[i][ny_right]);
                                move(world,i,j);
                                move(world,i,ny_right);
                            }
                        movDerecha(world,i,j);
                        //revisada

                    }
                   
                    else if (num == 3){
                        //abajo
                         
                         nx_up = i + 1;
                         nx_down = i -1;
                         ny_left = j -1;
                         ny_right = j+1;

                        
                        flag =isOcupado(&world[nx_down][j]);

                        if(j == 0 ){
                            ny_left = 999;
                            
                                                                        //bloque encargado matriz ciclica en eje x
                        }
                        if(j == 999){
                            ny_right = 0;
                        }
                        if(i == 0){
                            nx_down = 999;
                            
                          

                        }
                        if( i == 999) {
                            nx_up = 0;
                            flag =isOcupado(&world[nx_up][j]);
                             
                        }

                         //se reproduceny se pelean
                            int pos;
                            pos = lugarHijo(world,nx_up,j);

                            if(pos == 0){
                                reproducir(&world[i][j],&world[nx_up][j], &world[nx_up][j-1]); //el animal 2 es el central;
                                comerOHuir(&world[i][j],&world[nx_up][j]);
                                
                                move(world,i,j);
                                move(world,nx_up,j);
                            
                                //checkear cntador de movimientos

                            }
                        
                                
                            
                            else if(pos == 2){
                                reproducir(&world[i][j],&world[nx_up][j], &world[nx_up][j+1]);
                                comerOHuir(&world[i][j],&world[nx_up][j]);
                                move(world,i,j);
                                move(world,nx_up,j);
                            }
                            
                            else if(pos == 3){
                            reproducir(&world[i][j],&world[nx_up][j], &world[nx_up+1][j]);
                            comerOHuir(&world[i][j],&world[nx_up][j]);
                            move(world,i,j);
                            move(world,nx_up,j);
                            }
                
                            else if(pos == -1){
                                //no hay reproduccion se muere el animal
                                comerOHuir(&world[i][j],&world[i][nx_up]);
                                move(world,i,j);
                                move(world,i,nx_up);
                            }
                        }

                        movAbajo(world, i,j);
                        //revisada
                    }
                    

                }

            }

                
            
            else if(n1 == 3){
                printf("\n");
                printf("Seleccionaste 3 Mostrar el mundo\n ");
                mostrarMundo(world);
                
            }
            else if(n1 == 4){
                printf("\n");
                printf("Seleccionaste 4 Terminar simulacion \n");
                continuar = false;
                borrarMundo(world);
        }

            else{
                printf("\n");
                printf("input incorrrecto\n");
            }
        

    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    free(world);

    return 0;
















}