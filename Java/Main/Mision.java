package Main;

public class Mision {
    private char requisito;
    private int valor;
    private int cantidad;
    private int recompensa;

     /**************	
	* verificarRequisito()
	**************
	* Descripcion:
	* 	 	Funcion que checkea si la cantidad requerida por la mision ha sido alcanzada
    *       Si es asi retorna true, de otra forma false. 
	**************
	*	Acceso: 
	*		Public 
	*************
	* Input:
	*  	  
 	**************
	* return:
	*    boolean: Retorna boleano
	***********************/
    public boolean verificarRequisito(){
        boolean temp = false;
        if (this.requisito == 'v'){
            if(valor == cantidad){
                temp = true;
                return temp;

            }

        }
        else if(this.requisito == 'm'){
            if (cantidad == valor){
                temp = true;
                return temp;
            }

        }

        return temp;

    }
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
    *     char: setters toma input caracter.
 	**************
	* return:
	*    	setters: Void
    *       getters: int 
	***********************/
    public void add(){
        this.cantidad++;

    }
    public void setRequisito(char c){
        this.requisito = c;

    }
    public void setValor(int n ){
        this.valor = n;

    }
    public void setCantidad(int n){
        this.cantidad = n;
    }
    public void setRecompensa(int n){
        this.recompensa = n;
    }


    public char getRequisito(){
        return this.requisito;

    }
    public int getValor( ){
        return this.valor ;

    }
    public int getCantidad(){
        return this.cantidad;
    }
    public int getRecompensa(){
        return this.recompensa ;
    }
}