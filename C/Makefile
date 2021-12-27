simAnimal: Animal.o simulacion.o
	gcc Animal.o simulacion.o -o simAnimal 

Animal.o: Animal.c Animal.h
	gcc -c Animal.c -Wall

simulacion.o: simulacion.c Animal.h
	gcc -c simulacion.c -Wall

clean:
	rm *.o simAnimal