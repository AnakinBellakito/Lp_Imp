
package Player;
import java.util.ArrayList;
import java.util.List;
import Main.Mision;

public abstract class Jugador {
    private String nombre;
    private int vida;
    private int xp;
    private int fuerza;
    private int nivel;
    private int inteligencia;
    private int energia;
    private int mana;
    private int pos;
    private int vidaMax;
    private int energiaMax;
    private int manaMax;
    protected List <Mision> list;

    /**************	
	* Jugador()
	**************
	* Descripcion:
	* 	 	Constructor de clase Jugador  
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	
 	**************
	* return:
	*    	Instanciacion de clase Jugador
	***********************/
    public Jugador(){

        setVida(1);
        setFuerza(1);
        setInteligencia(1);
        setEnergia(1);
        setMana(1);
        this.xp = 0;
        list = new ArrayList<>();
    
     }
    /**************	
	* Agrupacion de Setters() y Getters()
	**************
	* Descripcion:
	* 	 	Funciones que Setean ciertos valores a los atributos de la clase jugador y herederos.
    *       Funciones que obtienen los valores de los atributos de la clase jugador y sus subclases. 
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

    public int getPos(){
        return this.pos;
    }
    public void setPos(int n ){
        this.pos = n;

    }

    public void setEnergiaMax(int n){
        this.energiaMax = n;
    }
    public int getEnergiaMax(){
        return this.energiaMax;
    }
    public void setVidaMax(int n){
        this.vidaMax = n;
    }
    public int getVidaMax(){
        return this.vidaMax;
    }
    public void setManaMax(int n){
        this.manaMax = n;
    }
    public int getManaMax(){
        return this.manaMax;
    }

    public int getNivel(){
        return this.nivel;
    }
    public void setNivel(int n ){
        this.nivel = n;

    }
    
    // nombre
    public void setNombre(String n ){
        this.nombre = n;

    }
    public String getNombre(){
        return this.nombre;
    }
    //vida
    
    public void setVida(int n ){
    	 if(n > this.vidaMax){
             this.vida = this.vidaMax; 
         }
         else if (n < 0) {
         	this.vida = 0;
         }
         else {this.vida = n ;}

    }
    public int getVida(){

        return this.vida;
    }
    //xp
    public int getXp(){
        return this.xp;
    }
    public void setXp(int n) {

        this.xp = n;
    }
    
    //fuerza
    public void setFuerza(int n ){
        this.fuerza = n;
    }
    public int getFuerza(){
        return this.fuerza;
    }
    // intel
    public void setInteligencia(int n ){
        this.inteligencia = n;
    }
    public int getInteligencia(){
        return this.inteligencia;
    }
    //energia
    public void setEnergia(int n ){
        if(n > this.energiaMax){
            this.energia =this.energiaMax; 
        }
        else if (n < 0) {
        	this.energia = 0;
        }
        else {this.energia = n ;}
        
    }
    public int getEnergia(){
        return this.energia;
    }
    // mana
    public void setMana(int n ){
        if(n > this.manaMax){
            this.mana =this.manaMax; 
        }
        else if (n < 0) {
        	this.mana = 0;
        }
        else {this.mana = n ;}
        
        
    }
    public int getMana(){
        return this.mana;
    }


     /**************	
	* addList()
	**************
	* Descripcion:
	* 	 	Funciones que Agrega una mision a la lista de misiones del Jugador o sus subclases
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	  Mision:  m
 	**************
	* return:
	*    	Boolean: true si logro agregarla, false sino
	***********************/
    public boolean addList(Mision m){
        boolean flag;
        flag = list.add(m);

        return flag;
    }
     /**************	
	* rmList()
	**************
	* Descripcion:
	* 	 	Funciones que remueve una mision pasada por parametro a la lista de misiones del Jugador o sus subclases
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	  Mision:  m
 	**************
	* return:
	*    	Boolean: true si logro eliminarla, false sino
	***********************/
    public boolean rmList(Mision m){
        boolean flag;
        flag = list.remove(m);

        return flag;
    }
     /**************	
	* checkMision()
	**************
	* Descripcion:
	* 	 	Funciones que recorre la lista de misiones del Jugador, si alguna esta completa, suma la recompensa a un contador posteriormente la remueve
    *       de la lista de misiones del jugador
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	  
 	**************
	* return:
	*    	int, retorna la cantidad de xp total a aumentar por las misiones completadas.
	***********************/
    public int checkMision(){
        
        int temp = 0;
        for(int x = 0;x< list.size(); x++) {
        	if(list.get(x).verificarRequisito()) {
        		temp += list.get(x).getRecompensa();
        		this.rmList(list.get(x));
        	}
        }
        
       return temp;

       
    }
  
     /**************	
	* display()
	**************
	* Descripcion:
	* 	 	Funcione que muestra por pantalla los atributos y los valores actuales de Jugador o sus subclases
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	  
 	**************
	* return:
	*    	void
	***********************/
    public void display(){
        System.out.println("Nombre:  " + this.getNombre());
        System.out.println("Nivel:  " + this.getNivel());
        System.out.println("Vida:  " + this.getVida());
        System.out.println("Experiencia:  " + this.getXp());
        System.out.println("Fuerza:  " + this.getFuerza());
        System.out.println("Inteligencia:  " + this.getInteligencia());
        System.out.println("Mana:  " + this.getMana());
        System.out.println("Energia:  " + this.getEnergia());
        System.out.println("Pos:  " + this.getPos());
    
    }

    public abstract int ataque();
    public abstract int hechizo();
    public abstract void subirExperiencia(int n );
    

    
    



    



}


    
