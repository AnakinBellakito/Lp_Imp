
package Tierra;

import Player.Jugador;
import Enemy.Monstruo;
import Enemy.JefeFinal;
import NPC.*;

public  abstract class Tierra {
    private double probabilidadEnemigo;
    public Monstruo monster;
    public JefeFinal jefeFinal;
    public Bueno bueno;
    public Malo malo;
    public Neutro neutro;
    
    public abstract boolean accion(Jugador a );
    /**************	
	* Tierra()
	**************
	* Descripcion:
	* 	 	Constructor de clase tierra manda todos atributos a -> null
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	
 	**************
	* return:
	*    	Instanciacion a de Tierra
	***********************/

    public Tierra(){
    	/*
    	
        
        monster = new Monstruo();
        jefeFinal = new JefeFinal();
     


        this.monster.setDano(2);
        this.monster.setVida(6);

        this.jefeFinal.setDano(3);
        this.jefeFinal.setNombre("pepito");
        this.jefeFinal.setVida(8);
         
        //inicializar atributos del npc 
        //como saber si es bueno malo o neutro
*/
    }
	/**************	
	* double setProb
	**************
	* Descripcion:
	* 	 	Funcion que setea la probabilidad de esta tierra o sus subclases dado un decimal
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	double : f parametro flotante
 	**************
	* return:
	*    	void
	***********************/
    public void setProb(double f){
        this.probabilidadEnemigo = f;
    }
	 
    /**************	
	* double getProb
	**************
	* Descripcion:
	* 	 	Funcion que obtiene la probabilidad de aparecer un enemigo en esta tierra o sus subclases
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  
	**************
	* return:
	*    	double 
	***********************/
    public double getProb(){
        return this.probabilidadEnemigo;
    }


}
