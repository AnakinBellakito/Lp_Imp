package NPC;
import Player.Jugador;

public  abstract class NPC {
    public String nombre;
    public abstract void interaccion(Jugador a);

     /**************	
	* Agrupacion de Setters() y Getters()
	**************
	* Descripcion:
	* 	 	Funciones que Setean ciertos valores a los atributos de la clase NPC y herederos.
    *       Funciones que obtienen los valores de los atributos de la clase NPC y sus subclases. 
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	  String:  Setters toman input String.
 	**************
	* return:
	*    	setters: Void
    *       getters: String 
	***********************/
    public void setNombre(String name){
        this.nombre = name;
    }

    public String getNombre(){
        return this.nombre;
    }


}

