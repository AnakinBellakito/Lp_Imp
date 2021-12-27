all: build

# Crear Jar (v=verbose, e=clase de entrada).
# Crea jar respecto a las clases que estan en carpeta build
jar: build
	jar cfve Simulacion.jar Main/Main -C build .

# Compila el Todos los packages para simulacion
build: Main/Main.java
	javac -d ./build Main/Main.java
	javac -d ./build Tierra/*.java
	javac -d ./build Enemy/*.java

# Corre el jar e inicia el programa
run: jar
	java -jar Simulacion.jar

# Remueve la carpeta buid
clean:
	rmdir /s /q build