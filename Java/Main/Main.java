package Main;


import java.util.*;
import java.util.Scanner;


import Enemy.Monstruo;
import Enemy.JefeFinal;
import Tierra.Planicie;
import Tierra.Montana;
import Tierra.Bosque;
import Tierra.Tierra;
import Player.Mago;
import Player.Druida;
import Player.Guerrero;
import NPC.Bueno;
import NPC.Malo;
import NPC.Neutro;
import Main.*;


//Arreglar construccion del mundo?


//comentar lo que pasa en momentos de la simulacion




public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String aux;
        float prob;
        String str;
        int temp;
        Tierra terra;
 
        Mago mago = new Mago();
        Druida druida =new Druida();
        Guerrero guerrero = new Guerrero();
       
        
        Tierra[] mundo2;
        List<Tierra> mundo3;



        System.out.println("Hola DM, Ingresa tamano del mundo");
        System.out.println(" ");
        int largo = sc.nextInt();
        sc.nextLine();
        mundo2 = new Tierra[largo];
    



        // tenemos tamano del mapa
       
       
         
        
        for(int i = 0; i< largo; i++) {
            System.out.println("Que tipo de bioma es esta casilla? ");
            System.out.println("Montana => mont ||| Planicie  => plan ||| Bosque => bos ");
            System.out.println("Ingrese (mont/plan/bos)");
           

            aux = sc.nextLine();
            
            if (aux.equalsIgnoreCase("mont")){
                //casilla montana
            	System.out.println("Entre en Montana");
               terra = new Montana();
                mundo2[i] = new Montana();
       
            }
            else if (aux.equalsIgnoreCase("plan")){
                //casilla planicie
            	System.out.println("Entre en Planicie");
            	terra = new Planicie();
                mundo2[i] =  terra;
         
            }
            else if (aux.equalsIgnoreCase("bos")){
                //casilla bosque
            	System.out.println("Entre en Bosque");
            	terra = new Montana();
                mundo2[i] = new Bosque();
               
            }
            
         
           
          
            

            System.out.println(" ");
            System.out.println("Probabilidad que aparezca un enemigo en esta casilla ?");
            System.out.println("Ingrese flotante entre 0-1");
            System.out.println(" ");
            prob = sc.nextFloat();
            sc.nextLine();

           
            
            mundo2[i].setProb(prob);
            
            System.out.println(" ");
            System.out.println("Que tipo de enemigo puede aparecer ?");
            System.out.println("Ingrese (jefe/normal)");
            System.out.println(" ");
            str = sc.nextLine();

            if (str.equalsIgnoreCase("jefe")){
                System.out.println("Ingresa atributos!");
                System.out.println(" ");
                //mundo.get(i).jefeFinal = new JefeFinal();
                mundo2[i].jefeFinal = new JefeFinal();
                System.out.println("Ingresa nombre del jefe !");
                System.out.println(" ");
                str = sc.nextLine();
               // mundo.get(i).jefeFinal.setNombre(str);
                mundo2[i].jefeFinal.setNombre(str);
                System.out.println("Ingresa vida del jefe !");
                System.out.println(" ");
                temp = sc.nextInt();
                sc.nextLine();
               // mundo.get(i).jefeFinal.setVida(temp);
                mundo2[i].jefeFinal.setVida(temp);
                System.out.println("Ingresa el damage base !");
                System.out.println(" ");
                temp = sc.nextInt();
                sc.nextLine();
                //mundo.get(i).jefeFinal.setDano(temp);
                
                mundo2[i].jefeFinal.setDano(temp);
                




            }
            else if (str.equalsIgnoreCase("normal")){
                System.out.println("Ingresa atributos!");
                System.out.println(" ");
                //mundo.get(i).monster = new Monstruo();
                mundo2[i].monster = new Monstruo();
                System.out.println("Ingresa vida del monstruo !");
                System.out.println(" ");
                temp = sc.nextInt();
                sc.nextLine();
                mundo2[i].monster.setVida(temp);
                System.out.println("Ingresa el damage base !");
                System.out.println(" ");
                temp = sc.nextInt();
                sc.nextLine();
                mundo2[i].monster.setDano(temp);
                




            }

            System.out.println(" ");
            System.out.println("Deseas un NPC en esta casilla?");
            System.out.println("Ingresa entero entre ||0 -> no quieres|| 1 -> si quieres ");
            System.out.println(" ");
            temp = sc.nextInt();
            sc.nextLine();

            
            if(temp == 0 ){
                //no hay npc
            }
            else if (temp == 1){

                int tempAni;
                System.out.println(" ");
                System.out.println("Que tipo de NPC?");
                System.out.println("Ingresa entero entre ||0 -> Bueno|| 1 -> Malo || 2 -> Neutro ");
                System.out.println(" ");
                tempAni = sc.nextInt();
                sc.nextLine();
                
                
                if(tempAni == 0){
                	 mundo2[i].bueno = new Bueno();
             
                    System.out.println("Ingresa atributos!");
                    System.out.println("Ingresa nombre del NPC !");
                    System.out.println(" ");
                    str = sc.nextLine();
                    mundo2[i].bueno.setNombre(str);
                    System.out.println("Ingresa atributo del npc|| xp/vida/energia/mana !");
                    System.out.println(" ");
                    str = sc.nextLine();
                    if(str.equalsIgnoreCase("xp")){ 
                    	 mundo2[i].bueno.setAtributo("xp");
        
                    }
                    else if(str.equalsIgnoreCase("vida")){
                    	 mundo2[i].bueno.setAtributo("vida");
                    }
                    else if(str.equalsIgnoreCase("energia")){ mundo2[i].bueno.setAtributo("energia");}
                    else if(str.equalsIgnoreCase("mana")){ mundo2[i].bueno.setAtributo("mana");}
                    System.out.println(" ");
                    System.out.println("Que cantidad de " + str + " el npc debe agregar");
                    System.out.println("Ingresa un entero!");
                    System.out.println(" ");
                    temp = sc.nextInt();
                    sc.nextLine();
                    mundo2[i].bueno.setCantidad(temp);

                }
                else if(tempAni == 1){
                    mundo2[i].malo = new Malo();
                   
                    System.out.println("Ingresa atributos!");
                    System.out.println("Ingresa nombre del NPC !");
                    System.out.println(" ");
                    str = sc.nextLine();
                    mundo2[i].malo.setNombre(str);
                    System.out.println("Ingrese cantidad de energia");
                    System.out.println("Ingresa un entero!");
                    System.out.println(" ");
                    temp = sc.nextInt();
                    sc.nextLine();
                    mundo2[i].malo.setCantidadEnergia(temp);
                    System.out.println("Ingrese cantidad de mana");
                    System.out.println("Ingresa un entero!");
                    System.out.println(" ");
                    temp = sc.nextInt();
                    sc.nextLine();
                    mundo2[i].malo.setCantidadMana(temp);
                  
                }
                else if (tempAni == 2){
                	mundo2[i].neutro = new Neutro();
                    
                    System.out.println("Ingresa atributos!");
                    System.out.println("Ingresa nombre del NPC !");
                    System.out.println(" ");
                    str = sc.nextLine();
                    mundo2[i].neutro.setNombre(str);
                    System.out.println("Ingrese requisito de mision");
                    System.out.println("Ingresa un entero ||  1 -> LLegar a cierta casilla || 2 -> Matar mounstros !");
                    System.out.println(" ");
                    temp = sc.nextInt();
                    sc.nextLine();
                    if (temp == 1) {
                    	 mundo2[i].neutro.setRequisito('v');
                    }
                    else if (temp == 2) {
                    	 mundo2[i].neutro.setRequisito('m');
                    	
                    }
                    
                    System.out.println("Ingrese valor para completar mision considere largo del mundo:" + largo);
                    System.out.println("Ingresa un entero!");
                    System.out.println(" ");
                    temp = sc.nextInt();
                    sc.nextLine();
                    mundo2[i].neutro.setValor(temp);
                    System.out.println("Ingrese Recompensa");
                    System.out.println("Ingresa un entero!");
                    System.out.println(" ");
                    temp = sc.nextInt();
                    sc.nextLine();
                    mundo2[i].neutro.setRecompensa(temp);


                    
                }

              
            }

            

        }
  //aqui codear el menu
  System.out.println("Hola DM, Ingresa posicion inical del Jugador");
  System.out.println(" ");
  int pos = sc.nextInt();
  sc.nextLine();
  System.out.println("Ingresa el nombre del jugador");
  System.out.println(" ");
  String name = sc.nextLine();
  System.out.println("Ingresa Clase del jugador|| mago -> 1 ||druida -> 2 || warrior -> 3 ");
  System.out.println("(1/2/3)");
  System.out.println(" ");
  temp = sc.nextInt();
  sc.nextLine();
  boolean mage,warrior,druid;
  mage = warrior = druid = false;
  
  if (temp == 1){
      
      mago.setNombre(name);
      mago.setPos(pos);
      mage = true;
  }
  else if(temp == 2){
         
      druida.setNombre(name);
      druida.setPos(pos);
      druid = true;
  }
  else if (temp == 3){

  
      guerrero.setNombre(name);
      guerrero.setPos(pos);
      warrior = true;
  }

  System.out.println("El resto de los atributos se asignan automaticamente segun clase");
  int count;
  System.out.println("Comienza la simulacion ");
  boolean continuar = true;
  int izq, der;
  while(continuar) {

     
      System.out.println("________________________");
      System.out.println("1.- Moverse izquierda");
      System.out.println("2.- Moverse derecha");
      System.out.println("3.- Mostrar Atributos ");
      System.out.println("________________________");
      System.out.println("Ingrese un entero");
      
      temp = sc.nextInt();
      sc.nextLine();
      boolean flag;
      
      
      
      if (temp == 1 && mage) {
          pos = mago.getPos();
          izq = pos -1;
          if(pos == 0 ) {
              izq = largo-1;
          }
          
          
          
          flag = mundo2[izq].accion(mago);
          if (flag){
              mago.setPos(izq);
              count = mago.checkMision();
              if(count  != 0) {mago.subirExperiencia(count);}
              continue;}
          else{
              if(mago.getVida() == 0){break;}
              else{continue;}
          }
          
      } else if (temp == 2 && mage ) {
          pos = mago.getPos();
          der = pos+1;
          if(pos == largo-1 ) {
              der = 0;
          }
          flag = mundo2[der].accion(mago);
          if (flag){
              
              count = mago.checkMision();
              if(count  != 0) {mago.subirExperiencia(count);}
              mago.setPos(der);
              continue;}
          else{
              if(mago.getVida() == 0){break;}
              else{continue;}
          }
          
          
      }
      else if(temp == 3 && mage ) {
          mago.display();
          System.out.println(" ");

      }

      if (temp == 1 && druid) {
          pos = druida.getPos();
          izq = pos-1;
          if(pos == 0 ) {
              izq = largo-1;
          }
          flag = mundo2[izq].accion(druida);
          if (flag){
              druida.setPos(izq);
              count = druida.checkMision();
              if(count  != 0) {druida.subirExperiencia(count);}
              continue;}
          else{
              if(druida.getVida() == 0){break;}
              else{continue;}
          }
          
      } else if (temp == 2 && druid ) {
          pos = druida.getPos();
          der = pos+1;
          if(pos == largo-1 ) {
              der = 0;
          }
          flag = mundo2[der].accion(druida);
          if (flag){
              druida.setPos(der);
              count = druida.checkMision();
              if(count  != 0) {druida.subirExperiencia(count);}
              continue;}
          else{
              if(druida.getVida() == 0){break;}
              else{continue;}
          }
          
          
      }
      else if(temp == 3 && druid ) {
          druida.display();
          System.out.println(" ");

      }

      if (temp == 1 && warrior) {
          pos = guerrero.getPos();
          
          izq = pos-1;
          if(pos == 0 ) {
              izq = largo-1;
          }
          flag = mundo2[izq].accion(guerrero);
          if (flag){
              guerrero.setPos(izq);
              count = guerrero.checkMision();
              if(count  != 0) {guerrero.subirExperiencia(count);}
              continue;}
          else{
              if(guerrero.getVida() == 0){break;}
              else{continue;}
          }
          
          
      } else if (temp == 2 && warrior ) {
          pos = guerrero.getPos();
          der = pos+1;
          if(pos == largo-1 ) {
              der = 0;
          }
          flag = mundo2[der].accion(guerrero);
          if (flag){
              guerrero.setPos(der);
              count = guerrero.checkMision();
              if(count  != 0) {guerrero.subirExperiencia(count);}
              continue;}
          else{
              if(guerrero.getVida() == 0){break;}
              else{continue;}
          }
          
          
      }
      else if(temp == 3 && warrior ) {
          guerrero.display();
          System.out.println(" ");
      }
      

  }
  sc.close();
}

}
