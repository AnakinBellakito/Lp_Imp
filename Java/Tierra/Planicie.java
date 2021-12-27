package Tierra;
import Player.*;

/**************	
* boolean accion
**************
*Descripcion:
* 	Funcion debe procesar si el jugador que recibe como param puede llegar a la casilla dependiendo de su energia, y mana 
* 	Luego debe decidir en cuanto a 2 probabilidades si hay combate, a depender del resultado de estas sub-acciones produce retornos distintos 
**************
*	Acceso: 
*		Public 
*************
* Input:
*  Jugador p:Intanciacion de la clase jugador o sus subaclases Mago,Druida,Guerrero pasada como referecnia 
**************
* return:
*    boolean, retorna true en caso de salir vivo y cumplir condiciones, de otra forma false.
*************/

public class Planicie extends Tierra{
    
    public boolean accion(Jugador p){
       boolean flag = true;
       System.out.println("puedes cruzar normalmente bienvenido a la planicie ");
       System.out.println(" ");

       if(this.bueno != null){
        System.out.println("Aparece alguien bueno en las sombras ..... ");
        System.out.println(" ");
            this.bueno.interaccion(p);
       }
       else if (this.malo != null){
        System.out.println("Aparece alguien malo en las sombras ..... ");
        System.out.println(" ");
           this.malo.interaccion(p);

       }
       else if (this.neutro != null){
        System.out.println("Aparece alguien imparcial en las sombras ..... ");
        System.out.println(" ");
           this.neutro.interaccion(p);
       }

       
        float aux = (float)Math.random();
        

        if( aux >= this.getProb()){
            //hay pelea
            if(this.monster != null){
                this.monster.combate(p);
            }
            else if(this.jefeFinal != null){
                this.jefeFinal.combate(p);
            }

            if(p.getVida() == 0){
              System.out.println("Perdiste el combate has muerto.");
               System.out.println(" ");
            flag = false;
            return flag;
            }
            else if(p.getVida() != 0) {
            	System.out.println("Has Ganado el combate.");
            	System.out.println(" ");
            	
            }
        } 
        else if(aux <= this.getProb()){
            System.out.println("No hay combate..... ");
            System.out.println(" ");
        }

        return flag;

    }
}
