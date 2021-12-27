package Player;

import java.util.ArrayList;

public class Guerrero extends Jugador {

     /**************	
	* Guerrero()
	**************
	* Descripcion:
	* 	 	Constructor de clase Guerrero hereda atributos de jugador, y los inicializa con cierto valor
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	
 	**************
	* return:
	*    	Instanciacion de clase Guerrero
	***********************/
     public Guerrero() {
        
        this.setManaMax(2);
        this.setEnergiaMax(10);
        this.setVidaMax(20);
        this.setXp(0);

        this.setVida(20);
        this.setFuerza(9);
        this.setInteligencia(1);
        this.setEnergia(10);
        this.setMana(2);
        this.list = new ArrayList<>();
       
      

    }
     /**************	
	*  ataque()
	**************
	* Descripcion:
	* 	 	Funcion que calcula el ataque realizado por el Guerrero en su estado actual.
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	
 	**************
	* return:
	*    	int: entero con el valor del ataque.
	***********************/
    public int ataque(){
        int aux;
        int fuerza;
    
        int energy;

        energy = this.getEnergia();
        if (energy == 0){
            return 0;
        }
        else {
            fuerza = this.getFuerza();

            aux = fuerza*2 + energy;
            this.setEnergia(energy-5);
            return aux;


        }
    }
     /**************	
	* hechizo()
	**************
	* Descripcion:
	* 	 	Funcion que calcula el hechizo realizado por el Guerrero en su estado actual.
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	
 	**************
	* return:
	*    	int: entero con el valor del hechizo.
	***********************/
    public int hechizo(){
        int aux;
        int fuerza;
        int mana;
        int intel;
        

        mana = this.getMana();
        if (mana == 0){
            return 0;
        }
        else {
            fuerza = this.getFuerza();
            intel = this.getInteligencia();
           

            aux = intel*(fuerza/4) + mana;
            this.setMana(mana-3);
            return aux;


        }
    }
     /**************	
	*  subirNivel()
	**************
	* Descripcion:
	* 	 	Funcion auxiliar a subir Experiencia, que sube los atributos de mago de acuerdo a su clase y su nivel actual
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	int: lvl es el nivel al que debe subir los atributos
 	**************
	* return:
	*    	void
	***********************/
    public void subirNivel(int lvl){
        int fuerza;
        int mana;
        int intel;
        int energy;
        int vida;

        fuerza = this.getFuerza();
        mana = this.getMana();
        intel = this.getInteligencia();
        energy = this.getEnergia();
        vida = this.getVida();

        this.setVidaMax( vida + 3*lvl);
        this.setFuerza(fuerza + 5*lvl);
        this.setInteligencia(intel + 1);
        this.setEnergiaMax(energy + 2*lvl);
        this.setManaMax( mana + 1);



    }
    /**************	
	*  subirExperiencia()
	**************
	* Descripcion:
	* 	 	Funcion que determina el nivel actual del jugador o sus subclases, si el nivel es distinto al que tenia 
    *       llama a la funcion auxiliar subir nivel
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	int: exp, experiencia que debe aumentar al jugador o sus subclases

 	**************
	* return:
	*    	void
	***********************/
    public void subirExperiencia(int exp){
        boolean llamar = false;
        int aux;
        aux = this.getNivel();

        if(this.getXp()  <=900  && this.getNivel() == 8){
            System.err.println("No puedes subir de lvl, ya eres nivel 8");
            return;
        }
        this.setXp(this.getXp()+exp);
        

        if(this.getXp() < 10){
           this.setNivel(1);
        }
        else if(10 <= this.getXp() && this.getXp() <25){
            this.setNivel(2);
        }
        else if(25 <= this.getXp() && this.getXp() <50){
            this.setNivel(3); 
        }
        else if(50 <= this.getXp() && this.getXp() <100){
            this.setNivel(4); 

        }
        else if(100 <= this.getXp() && this.getXp() <200){
            this.setNivel(5); 
        }
        else if(200 <= this.getXp() && this.getXp() <350){
            this.setNivel(6); 
        }
        else if(350 <= this.getXp() && this.getXp() <600){
            this.setNivel(7); 
        }
        else if(600 <= this.getXp() && this.getXp() < 900){
            this.setNivel(8); 
        }

        if (aux != this.getNivel()){
            llamar = true;
        }

        if (llamar) {
            subirNivel(this.getNivel());
        }
    }
    
}
