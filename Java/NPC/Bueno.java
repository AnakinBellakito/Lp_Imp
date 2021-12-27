package NPC;
import Player.Jugador;

public class Bueno extends NPC {
    private String atributo;
    private  int cantidad;
     /**************	
	* Bueno()
	**************
	* Descripcion:
	* 	 	Constructor de clase Bueno, inicializa atributos random por defecto. 
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	
 	**************
	* return:
	*    	Instanciacion de clase Bueno
	***********************/
    public Bueno(){
        this.atributo = "vida";
        this.cantidad = 5;
        this.setNombre("Pepe");
    }


     /**************	
	* Interaccion()
	**************
	* Descripcion:
	* 	 	Funcion que hace interactuar al NPC bueno con un jugador o sus subclases, y le otorga un boost
    *       a algun atributo en particular un cierta cantidad
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	   Jugador: a1, Instanciacion a la que otorgara el boost
 	**************
	* return:
	*    	void.
	***********************/
    public void interaccion(Jugador a1){
        System.out.println(this.getNombre() + " :" + "Creo que nesecitas un poco de ayuda te subire " + " " + this.cantidad+ "a tu " + this.atributo +"!!!");
        int aux;
        if(this.atributo == "vida"){
            
            aux = a1.getVida() + this.cantidad;
            a1.setVida(aux);

        }
        else if(this.atributo =="xp"){
            
           a1.subirExperiencia(this.cantidad);

        }

        else if(this.atributo == "mana"){
            
            aux = a1.getMana() + this.cantidad;
            a1.setMana(aux);
        }
        else if(this.atributo =="energia"){
            
            aux = a1.getEnergia() + this.cantidad;
            a1.setEnergia(aux);
        }

    }
     /**************	
	* Agrupacion de Setters() y Getters()
	**************
	* Descripcion:
	* 	 	Funciones que Setean ciertos valores a los atributos de la clase Bueno 
    *       Funciones que obtienen los valores de los atributos de la clase Bueno  
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	  int:  Setter toma input entero.
    *     string: Setter toma input String
 	**************
	* return:
	*    	setters: Void
    *       getters: String,int 
	***********************/
    public void setAtributo(String s){
        this.atributo = s;
    }
    public void setCantidad(int c){
        this.cantidad = c;

    }

    public String getAtributo(){
        return this.atributo;
    }
    public int getCantidad(){
        return this.cantidad;

    }
}
