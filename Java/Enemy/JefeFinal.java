package Enemy;
import Player.*;

import java.util.Scanner;

public class JefeFinal implements Enemigo {
    private String nombre;
    private int vida;
    private int danoBase;
     /**************	
	* Agrupacion de Setters() y Getters()
	**************
	* Descripcion:
	* 	 	Funciones que Setean ciertos valores a los atributos de la clase JefeFinal 
    *       Funciones que obtienen los valores de los atributos de la clase JefeFinal 
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	  int:  Setters toman input entero.
    *     String: 1 solo setter toma input str
 	**************
	* return:
	*    	setters: Void
    *       getters: int 
	***********************/
    public void setNombre(String name){
        this.nombre = name;
    }
    public String getNombre(){
        return this.nombre;
    }

    public void setVida(int n){
        this.vida = n;
    }
    public void setDano(int n){
        this.danoBase = n;
    }
    public int getVida(){
        return this.vida;
    }
    public int getDano(){

        return this.danoBase;
    }
    
     /**************	
	*   combate
	**************
	* Descripcion:
	* 	 	Funcion inicia un loop que funciona por turnos que no termina hasta que muere el jugador o jefeFinal
    *       Ademas da otorga la opcion de decicir si quiere realizar ataque o hechizo
    *       procede bajando vida a la clase respectiva que es atacada
    *       El jefe final cuuenta con 2 fases las que se deciden en base a su vida
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
    public void combate(Jugador a){ 
        boolean turno1 = true;
        boolean turno2 = false;
         Scanner sc = new Scanner(System.in);
     
        int temp, aux;
        int fase = 2;
        int vidaInit = this.getVida();
        System.out.println("!!!!! Combate !!!! ");
        
        while(a.getVida() > 0 && this.getVida() > 0){
            if(turno1 == true && turno2 == false){
                //turno jugador
                System.out.println("Turno Jugador ");
                System.out.println("Vida Jugador:  "+ a.getVida() );
                System.out.println("Que quieres hacer || Ataque | Hechizo ");
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
            	
            	 System.out.println("Turno Jefe ");

                if (this.getVida() <= vidaInit/2 ){
                    fase = 1;
                }

                int dmg;
                dmg = (this.getDano()+2)* fase;
                temp = a.getVida() - dmg; 
                a.setVida(temp);
                System.out.println("Dmg ataque " + dmg);
                  System.out.println(" ");
                turno1 =true;
                turno2 = false;


            }
        }
        
    }
    
    
}
