package Enemy;

import java.util.Scanner;

import Player.Jugador;

public class Monstruo implements Enemigo {
    private int vida;
    private int dano;

     /**************	
	* Agrupacion de Setters() y Getters()
	**************
	* Descripcion:
	* 	 	Funciones que Setean ciertos valores a los atributos de la clase Monstruo 
    *       Funciones que obtienen los valores de los atributos de la clase Monstruo 
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	  int:  Setters toman input entero.
 	**************
	* return:
	*    	setters: Void
    *       getters: int 
	***********************/
    public void setVida(int n){
        this.vida = n;
    }
    public void setDano(int n){
        this.dano = n;
    }
    public int getVida(){
        return this.vida;
    }
    public int getDano(){
        return this.dano;
    }

     /**************	
	*   combate
	**************
	* Descripcion:
	* 	 	Funcion inicia un loop que funciona por turnos que no termina hasta que muere el jugador o jefeFinal
    *       Ademas da otorga la opcion de decicir si quiere realizar ataque o hechizo
    *       procede bajando vida a la clase respectiva que es atacada.
    *       
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	  Jugador : a el combatiente de jefeFinal
 	**************
	* return:
	*    	void
	***********************/
    public  void combate(Jugador a){ 
        boolean turno1 = true;
        boolean turno2 = false;
        Scanner sc = new Scanner(System.in);
       
        int temp,aux;
        System.out.println("!!!!! Combate !!!! ");
        while(a.getVida() > 0 && this.getVida() > 0){
            if(turno1 == true && turno2 == false){
                //turno jugador
            	
                System.out.println("Turno Jugador ");
                System.out.println("Vida Jugador:  "+ a.getVida() );
                
                System.out.println("(a/h) || Ataque --> 1 | Hechizo --> 2");
                aux = sc.nextInt();
                sc.nextLine();

                if(aux == 1){
                    temp = this.getVida() - a.ataque();
                    System.out.println("DMG ataque: " + a.ataque());
                    System.out.println(" ");

                    this.setVida(temp);


                }
                else if(aux == 2){
                    temp = this.getVida() - a.hechizo();
                    System.out.println("DMG ataque: " + a.hechizo());
                    System.out.println(" ");
                    this.setVida(temp);


                }

            

                
                turno1 =false;
                turno2 = true;

            }
            else if(turno2 == true && turno1 == false){
            	  System.out.println("Turno Monstruo ");
                  System.out.println(" ");
                temp = a.getVida() - this.getDano(); 
                System.out.println("Dmg ataque " + this.getDano());
                  System.out.println(" ");
                a.setVida(temp);
                turno1 =true;
                turno2 = false;


            }
        }
        
    }
   

    

   
    
}
