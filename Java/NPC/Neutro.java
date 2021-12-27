
package NPC;
import Player.Jugador;
import java.util.Scanner;

import Main.Mision;

public class Neutro extends NPC {
    
    private char requisito;
    private int valor;
    private int recompensa;
    private boolean yaDioMision;
     /**************	
	* Neutro()
	**************
	* Descripcion:
	* 	 	Constructor de clase Neutro, inicializa 1 atributo a false 
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	
 	**************
	* return:
	*    	Instanciacion de clase Neutro
	***********************/
    public Neutro(){
        this.yaDioMision = false;
       
    }
    /**************	
	* Agrupacion de Setters() y Getters()
	**************
	* Descripcion:
	* 	 	Funciones que Setean ciertos valores a los atributos de la clase Neutro 
    *       Funciones que obtienen los valores de los atributos de la clase Neutro  
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	  int:  Setter toma input entero.
    *     char: Setter toma input char
 	**************
	* return:
	*    	setters: Void
    *       getters: int, char,Boolean
	***********************/
    public boolean getYaDioMision(){
        return this.yaDioMision;

    }
    public int getRecompensa(){
        return this.recompensa;
        
    }
    public char getRequisito(){
        return this.requisito;
        
    }
    public int getValor(){
        return this.valor;
        
    }
    public void setYaDioMision(){
        this.yaDioMision = true;
    }

    public void setRequisito(char c){
        this.requisito = c;
    }
    public void setValor(int n ){
        this.valor = n;
    }
    public void setRecompensa(int n){
        this.recompensa = n;
    }
    
    /**************	
	* Interaccion()
	**************
	* Descripcion:
	* 	 	Funcion que hace interactuar al NPC Neutro con un jugador o sus subclases, y le otorga una mision
    *       si el jugador acepta, la mision ya esta predefinida en los atributos de Neutro, sino acepta continua como estaba.
    *       Si el jugador vuelve y ya obtuvo mision de este npc, Neutro le informa tal situacion
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	   Jugador: a1, Instanciacion a la que otorgara mision o
 	**************
	* return:
	*    	void.
	***********************/
    public void interaccion(Jugador x){
      
        Scanner sc = new Scanner(System.in);
        if(this.getRequisito() == 'v' && this.getYaDioMision() == false){
            
            System.out.println(this.getNombre() + ": hola " + " Quieres cumplir esta mision? Deberas llegar a " + this.getValor() + " del mundo y recibiras "+
            this.getRecompensa() +" puntos  experiencia !!!");
            
            System.out.println("si para aceptar || no para rechazar ||--> (si/no)");
            String respuesta = sc.nextLine();
            
            if(respuesta.equalsIgnoreCase("si")){
                Mision mision = new Mision();
                mision.setRequisito(this.requisito);
                mision.setValor(this.valor);
                mision.setRecompensa(this.recompensa);

                x.addList(mision);
                this.setYaDioMision();
            }
            else if(respuesta.equalsIgnoreCase("no")){
                //hacer nada rechazar
    
            }
        }

        else if(this.getRequisito() == 'm' && this.getYaDioMision() == false){
            System.out.println(this.getNombre() + ": hola " + " Quieres cumplir esta mision? Deberas matar a " + this.getValor() + "de Monstruos y recibiras "+
            this.getRecompensa() +" puntos de experiencia !!!");

            System.out.println("si para aceptar || no para rechazar ||--> (si/no)");
            String respuesta = sc.nextLine();
            
            if(respuesta.equalsIgnoreCase("si")){
                    
                Mision mision = new Mision();
                mision.setRequisito(this.requisito);
                mision.setValor(this.valor);
                mision.setRecompensa(this.recompensa);
                mision.setCantidad(0);

                x.addList(mision);
                this.setYaDioMision();
            }
            else if(respuesta.equalsIgnoreCase("no")){
                //hacer nada rechazar
    
            }
        }
        else if(this.getYaDioMision() == true){
            System.out.println(this.getNombre() + ": ya te di mision,saludos.");
        }

        

    }

}
