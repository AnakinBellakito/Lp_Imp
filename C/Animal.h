#ifndef ANIMAL_H
#define ANIMAL_H

#include <stdio.h>
#include <math.h>

typedef struct Animal{
    void * fuerza;
    char tipo_fuerza;
    void * velocidad;
    char tipo_velocidad;
    void* resistencia;
    char tipo_resistencia;
    int desfase;
    void (*reproduccion)(struct Animal *,struct Animal* ,struct Animal* );
    void (*comerHuir)(struct Animal *, struct Animal*);
}Animal;

/*************
* void crearAnimal
**************
* Funcion debe asignar valores a struct Animal, variables y punteros, en referecia a lo ingresado por el usuario.
**************
* Input:
*  Animal * a: Puntero animal que sera pasado por referencia
**************
* return:
*    void, no retorna nada, procesa por dentro
**************/
void crearAnimal(struct Animal *a);// ok




/*************
* void borrarAnimal
**************
* Funcion debe liberar memoria de punteros internos de struct.
**************
* Input:
*  Animal * a: Puntero animal que sera pasado por referencia
**************
* return:
*    void, no retorna nada, procesa por dentro
**************/
void borrarAnimal(struct Animal *a); // ok





/*************
* void mostrarAnimal
**************
* Funcion debe mostrar atributos propios del animal con un cierto formato
**************
* Input:
*  Animal * a: Puntero animal que sera pasado por referencia
**************
* return:
*    void, no retorna nada, procesa por dentro
**************/
void mostrarAnimal (struct Animal*a); // ok





/*************
* void reproducir
**************
* Funcion encargada de invocar el puntero-funcion reproduccion de uno de los 2 animales al azar, 
    *printear por pantalla cual uso
**************
* Input:
*  Animal * a1: Puntero animal que sera pasado por referencia
*  Animal * a2: Puntero animal que sera pasado por referencia
*  Animal * hijo : Puntero animal que sera pasado por referencia
**************
* return:
*    void, no retorna nada, procesa por dentro
**************/
void reproducir(struct Animal *a1,struct Animal* a2,struct Animal* hijo);// ok || puede faltar (*funcion)







/*************
* void comerOHuir
**************
* Funcion encargada de invocar el puntero-funcion comerHuir de uno de los 2 animales al azar, 
 * printear por pantalla cual uso
**************
* Input:
*  Animal * a1: Puntero animal que sera pasado por referencia
*  Animal * a2: Puntero animal que sera pasado por referencia
**************
* return:
*    void, no retorna nada, procesa por dentro
**************/
void comerOHuir(struct Animal *a1,struct Animal *a2); //ok || puede faltar (*funcion)










/*************
* int comparar
**************
* Funcion encargada de comparar atributos de 2 animales casteando cuando es necesario y llevar la cuenta del ganador
**************
* Input:
*  Animal * a1: Puntero animal que sera pasado por referencia
*  Animal * a2: Puntero animal que sera pasado por referencia
**************
* return:
*    int retorna 0 si gano a1 o 1 si gano a2
**************/
int comparar(struct Animal *a1,struct Animal *a2); // ok












/*************
* void reproduccionSimple
**************
* Funcion encargada de invocar a comparar si es 0 el animal hijo recibe todo de a1 sino recibe todo de a2
**************
* Input:
*  Animal * padre: Puntero animal que sera pasado por referencia
*  Animal * madre: Puntero animal que sera pasado por referencia
*  Animal * hijo : Puntero animal que sera pasado por referencia
**************
* return:
*    void, no retorna nada, procesa por dentro
**************/
void reproduccionSimple(struct Animal *padre,struct Animal*madre,struct Animal*hijo); //ok













/*************
* void reproduccionCruzada
**************
* Funcion encargada de invocar a comparar si es 0 el hijo recibe una serie de atributos de padre y madre.
*        Si es 1 recibe otra serie predefinida de atributos de padre y madre
**************
* Input:
*  Animal * padre: Puntero animal que sera pasado por referencia
*  Animal * madre: Puntero animal que sera pasado por referencia
*  Animal * hijo : Puntero animal que sera pasado por referencia
**************
* return:
*    void, no retorna nada, procesa por dentro
**************/
void reproduccionCruzada( struct Animal *padre,struct Animal*madre,struct Animal*hijo);//ok

















/*************
* void huirSiempre
**************
* Funcion encargada de comparar la velocidad de a1 y a2, si a1>a2 prueba posiciones vacias en la matriz asi <- ^ -> v y se mueve si la encuentra
*   Si a1<a2 a1 se muere
**************
* Input:
*  Animal * a1: Puntero animal que sera pasado por referencia
*  Animal * a2: Puntero animal que sera pasado por referencia
*  Animal * hijo : Puntero animal que sera pasado por referencia
**************
* return:
*    void, no retorna nada, procesa por dentro
**************/
void huirSiempre(struct Animal *a1,struct Animal *a2);//ok












/*************
* void comerSiempre
**************
* Funcion encargada comparar la fuerza de a1 con resistencia de a2, si a1> a2 => a2 muere
*                                                                   si a2> a1 => a1 muere
**************
* Input:
*  Animal * a1: Puntero animal que sera pasado por referencia
*  Animal * a2: Puntero animal que sera pasado por referencia
**************
* return:
*    void, no retorna nada, procesa por dentro
**************/
void comerSiempre(struct Animal *a1,struct Animal *a2);//ok








/*************
* void comerAleatorio
**************
* Funcion encargada de tomar un atributo al azar de cada animal y compararlo
*         Si a1>a2 => a2 muere || Si a1< a2  => a1 se muere || empate a1 se muere
**************
* Input:
*  Animal * a1: Puntero animal que sera pasado por referencia
*  Animal * a2: Puntero animal que sera pasado por referencia
**************
* return:
*    void, no retorna nada, procesa por dentro
**************/
void comerAleatorio(struct Animal *a1,struct Animal *a2);//ok


    




#endif // ANIMAL_H
