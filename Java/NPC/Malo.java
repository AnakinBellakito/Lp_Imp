package NPC;
import Player.Jugador;

public class Malo extends NPC {
    public int cantidadEnergia;
    public int cantidadMana;
     /**************	
	* Malo()
	**************
	* Descripcion:
	* 	 	Constructor de clase Malo, inicializa atributos random por defecto. 
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	
 	**************
	* return:
	*    	Instanciacion de clase Malo
	***********************/
    public Malo(){
        this.cantidadEnergia = 1;
        this.cantidadMana = 1;
        this.setNombre("pepe");
    }
     /**************	
	* Interaccion()
	**************
	* Descripcion:
	* 	 	Funcion que hace interactuar al NPC malo con un jugador o sus subclases, y le disminuye mana y energia
    *       basado en una probabilidad de 6 o +
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
    public void interaccion(Jugador x){
        int aux;
        System.out.println(this.getNombre() + " :" + "Soy malo te voy a disminuir tu energia en: "+ this.cantidadEnergia +" y mana en: "  + this.cantidadMana +"!!!");
        
        for(int m =0; m< 2; m++){
            aux = 1 + (int)(Math.random()*10);
            if(aux <= 6 && m ==0){
                x.setEnergia(x.getEnergia() - this.cantidadEnergia);

            }
            else if (aux <= 6 && m == 1){
                x.setMana(x.getMana() - this.cantidadMana);
            }
        }
    }
    

    /**************	
	* Agrupacion de Setters() y Getters()
	**************
	* Descripcion:
	* 	 	Funciones que Setean ciertos valores a los atributos de la clase Malo 
    *       Funciones que obtienen los valores de los atributos de la clase Malo  
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	  int:  Setter toma input entero.
 	**************
	* return:
	*    	setters: Void
    *       getters: int 
	***********************/
    public void setCantidadEnergia(int s){
        this.cantidadEnergia = s;
    }
    public void setCantidadMana(int c){
        this.cantidadMana = c;

    }

    public int getEnergia(){
        return this.cantidadEnergia;
    }
    public int getMana(){
        return this.cantidadMana;

    }
}