from stack import Stack
import re


#posible patron ? (\?[UD<>]\d+X?[UD<>]?\d*\??Y?[UD<>]?\d*L?[ec]?S?[ec]?[ABRZ]*)*
# x2 \?[UD<>]\d+X?[UD<>]?\d*\??Y?[UD<>]?\d*L?[ec]?S?[ec]?[ABRZ]*
'''
Balanceo
------------------
str: string
pila: Tda tipo Stack
------------------
La funcion checkea si el string pasado por parametro tiene los parentesis balanceados,
retorna un Booleano respectivo a cada caso
'''
def balanceo(str):
    pila = Stack()

    for x in range(len(str)):
        if (str[x] == '('):
            pila.push(str[x])
        if (str[x] == ')' and '(' == pila.tope() ):
            pila.pop()

    if (pila.is_empty()):
        return True
    else:
        return False


'''
procesar
------------------
line: string

------------------
La funcion reordena las lineas del txt que contengan parentesis y genera una nueva linea reordenada.
Ademas Contempla todos los patrones de reconocimiento y los convierte en un iterador.
Procede a incluir en una lista todos los patrones encontrados ordenador por orden de span
Finalmente retorna una lista con las instrucciones de la line 

'''
def procesar(line):




        lista_f = []
        lista_aux = []
        flag = True
        flag2 = False

        balance = balanceo(line)

        initio = True
        x = 0
        y = 1000

        if ("(" in line and ")" in line):

            flag2 = True
            parentesis = re.findall(".",line)



        if (balance == True):
            i = 1000

            while(flag2 == True):


                while(len(parentesis) != 0):
                    m = 0
                    index = []
                    index_salida = []
                    pos = 0
                    for j in parentesis:

                        if(j == '('):
                            index.append(pos)

                        if (j == ')'):
                            index_salida.append(pos)

                        pos +=1
                    if(len(index)!=0 and len(index_salida)!= 0):
                        num = index_salida[0] - index[-1]
                        corte_x = index[-1]
                        corte_y = index_salida[0]
                        index.pop()
                        index_salida.pop(0)


                    pre_x = corte_x

                    for x in range(num-1):
                        if ("(" in parentesis or ")" in parentesis):
                            element = parentesis[corte_x+1]

                            corte_x +=1
                            lista_aux.append(element)
                        else:
                            break


                    del parentesis[pre_x:corte_y+1]




                    if("(" not in parentesis and ")" not in parentesis):
                        while(parentesis != []):
                            lista_aux.append(parentesis.pop())
                        line = "".join(lista_aux)
                        flag2 = False




            largo_str = len(line)

            while(i!=0):
                if (flag == True):
                    flag = False
                    initio = True


                augment = re.finditer("[A]", line)
                unaugment = re.finditer('[B]', line)
                up = re.finditer("U(0|[1-9][0-9]*)", line)
                down = re.finditer("D(0|[1-9][0-9]*)", line)
                left = re.finditer("<(0|[1-9][0-9]*)", line)  # ok
                right = re.finditer(">(0|[1-9][0-9]*)", line)  # ok
                multi = re.finditer("X([<>UD]\d+)+", line)
                division = re.finditer("Y([<>UD]\d+)+", line)
                reinicio_pos = re.finditer("R", line)
                reinicio_matriz = re.finditer("Z", line)
                print_puntual = re.finditer("L[ce]", line)
                print_general = re.finditer("S[ce]", line)
                condicional = re.finditer("((\?((U|D|<|>)0|(U|D|<|>)[1-9]\d*)+)+([AB]|([XY]((U|D|<|>)0|(U|D|<|>)[1-9]\d*)+)|((L|S)[ec])|(R|Z)))", line)


                #Bloque de for con la misma estructura, encargados de recorrer los iteradores
                #Ademas ordenan y agregan a la lista auxiliar mendiate x e y variables basado en orden span de los match


                for match in augment:


                    if (initio == True and match.start() == 0):
                        initio = False
                        x = match.start()
                        y = match.end()
                        lista_f.append(match.string[x:y])

                    if (y == match.start()):
                        x = y
                        y = match.end()
                        lista_f.append(match.string[x:y])

                for match in condicional:

                    if (initio == True and match.start() == 0):
                        initio = False
                        x = match.start()
                        y = match.end()
                        lista_f.append(match.string[x:y])

                    if (y == match.start()):
                        x = y
                        y = match.end()
                        lista_f.append(match.string[x:y])




                for match in multi:
                    if (initio == True and match.start() == 0):
                        initio = False
                        x = match.start()
                        y = match.end()
                        lista_f.append(match.string[x:y])

                    if (y == match.start()):
                        x = y
                        y = match.end()
                        lista_f.append(match.string[x:y])


                for match2 in unaugment:
                    if (initio == True and match2.start() == 0):
                        initio = False
                        x = match2.start()
                        y = match2.end()
                        lista_f.append(match2.string[x:y])

                    if (y == match2.start()):
                        x = y
                        y = match2.end()
                        lista_f.append(match2.string[x:y])





                for match in up:

                    if (initio == True and match.start() == 0):
                        initio = False
                        x = match.start()
                        y = match.end()
                        lista_f.append(match.string[x:y])

                    if (y == match.start()):
                        x = y
                        y = match.end()
                        lista_f.append(match.string[x:y])



                for match in down:
                    if (initio == True and match.start() == 0):
                        initio = False
                        x = match.start()
                        y = match.end()
                        lista_f.append(match.string[x:y])

                    if (y == match.start()):
                        x = y
                        y = match.end()
                        lista_f.append(match.string[x:y])


                for match in left:
                    if (initio == True and match.start() == 0):
                        initio = False
                        x = match.start()
                        y = match.end()
                        lista_f.append(match.string[x:y])


                    if (y == match.start()):
                        x = y
                        y = match.end()
                        lista_f.append(match.string[x:y])

                for match in right:

                    if (initio == True and match.start() == 0):
                        initio = False
                        x = match.start()
                        y = match.end()
                        lista_f.append(match.string[x:y])

                    if (y == match.start()):
                        x = y
                        y = match.end()
                        lista_f.append(match.string[x:y])


                for match in division :
                    if (initio == True and match.start() == 0):
                        initio = False
                        x = match.start()
                        y = match.end()
                        lista_f.append(match.string[x:y])

                    if (y == match.start()):
                        x = y
                        y = match.end()
                        lista_f.append(match.string[x:y])


                for match in reinicio_pos:
                    if (initio == True and match.start() == 0):
                        initio = False
                        x = match.start()
                        y = match.end()
                        lista_f.append(match.string[x:y])

                    if (y == match.start()):
                        x = y
                        y = match.end()
                        lista_f.append(match.string[x:y])


                for match in reinicio_matriz:
                    if (initio == True and match.start() == 0):
                        initio = False
                        x = match.start()
                        y = match.end()
                        lista_f.append(match.string[x:y])

                    if (y == match.start()):
                        x = y
                        y = match.end()
                        lista_f.append(match.string[x:y])


                for match in print_puntual:
                    if (y == match.start()):
                        x = y
                        y = match.end()
                        lista_f.append(match.string[x:y])

                    if (initio == True and match.start() == 0):
                        initio = False
                        x = match.start()
                        y = match.end()
                        lista_f.append(match.string[x:y])



                for match in print_general:
                    if (initio == True and match.start() == 0):
                        initio = False
                        x = match.start()
                        y = match.end()
                        lista_f.append(match.string[x:y])

                    if (y == match.start()):
                        x = y
                        y = match.end()
                        lista_f.append(match.string[x:y])





                if ("\n" in line):
                        if(y == largo_str - 1):
                            return lista_f
                elif ("\n" not in line):
                        if(y == largo_str):
                            return lista_f
                i = i-1
        else:
            return None
'''
Comienza Main
'''
#Cambiar archivo de lectura <- Aca
file = open("ejemplo1.txt","r")


i = 0
n_errores = 0

fp = open("errores.txt", 'w')
fp.write("")
fp.close()

matrix = []
#valores para posicion de matriz
x_mat = 0
y_mat = 0

for line in file:


    # Creamos la matriz
    fila = []
    if (i == 0):
        for n in range(int(line)):
            matrix.append([])
            for j in range(int(line)):
                matrix[n].append(0)

   #Largo de matriz sera usado para matriz circular
    lenn_matriz = len(matrix)

    if (i !=0):
        listax = procesar(line)
        print(listax)

        #Control encargado de anadir errores
        if(listax == None):

            fp = open("errores.txt", 'a')
            fp.write(str(i) + " " + line)
            n_errores += 1
            fp.close()


        if(listax != None):
            #Recorremos lista de instrucciones
            for x in listax:

                #caso simple Aumentar
                if(x == "A"):
                    matrix[y_mat][x_mat] += 1

                #Caso simple Disminuir
                elif (x == "B"):
                    matrix[y_mat][x_mat] -= 1

                #Caso simple de Reinciar posicion actual, comando R
                elif ("R" == x):
                    matrix[y_mat][x_mat] = 0

                #Caso simple de reinciar matriz completa, comando Z
                elif ("Z" == x):
                    for j in range(lenn_matriz):
                        for k in range(lenn_matriz):
                            matrix[j][k] = 0

                #Caso Multiplicacion
                elif (x[0] == "X"):

                    #Consideramos una cantidad variable de DIR
                    count = 0
                    y_cond = y_mat
                    x_cond = x_mat
                    dir = re.search("([<>UD]\d+)+", x)
                    largo_dir = dir.end() - dir.start()
                    string_dir = x[dir.start():dir.end()]


                    #Bloque de if anidados dentro de ciclo que se encarga moverse por posiciones relativas
                    #Obtener el valor buscado y Multiplicar la pos actual por el valor encontrado

                    for n in range(largo_dir):

                        if (string_dir[n] == "U"):
                            nume = int(string_dir[n + 1])
                            y_cond = (y_cond - nume) % lenn_matriz
                            count += 2
                            if (count == largo_dir):
                                nume = matrix[y_cond][x_cond]
                                matrix[y_mat][x_mat] *=nume

                        elif (string_dir[n] == "D"):
                            nume = int(string_dir[n + 1])
                            y_cond = (y_cond + nume) % lenn_matriz
                            count += 2
                            if (count == largo_dir):
                                nume = matrix[y_cond][x_cond]
                                matrix[y_mat][x_mat] *= nume


                        elif (string_dir[n] == "<"):
                            nume = int(string_dir[n + 1])
                            x_cond = (x_cond - nume) % lenn_matriz
                            count += 2
                            if (count == largo_dir):
                                nume = matrix[y_cond][x_cond]
                                matrix[y_mat][x_mat] *= nume

                        elif (string_dir[n] == ">"):
                            nume = int(string_dir[n + 1])
                            x_cond = (x_cond + nume) % lenn_matriz
                            count += 2
                            if (count == largo_dir):
                                nume = matrix[y_cond][x_cond]
                                matrix[y_mat][x_mat] *= nume
                #Caso Division
                elif (x[0] == "Y"):
                    #Variables para considerar Dir de largo variable y posiciones relativas en matriz
                    count = 0
                    y_cond = y_mat
                    x_cond = x_mat
                    dir = re.search("([<>UD]\d+)+", x)
                    largo_dir = dir.end() - dir.start()
                    string_dir = x[dir.start():dir.end()]

                    #Reutilizacion de codigo multiplicacion varia en que divide pos actual por valor encontrado y toma excepcion de 0
                    for n in range(largo_dir):

                        if (string_dir[n] == "U"):
                            nume = int(string_dir[n + 1])
                            y_cond = (y_cond - nume) % lenn_matriz
                            count += 2
                            if (count == largo_dir):
                                nume = matrix[y_cond][x_cond]
                                if(nume > 0):
                                    matrix[y_mat][x_mat] //= nume

                        elif (string_dir[n] == "D"):
                            nume = int(string_dir[n + 1])
                            y_cond = (y_cond + nume) % lenn_matriz
                            count += 2
                            if (count == largo_dir):
                                nume = matrix[y_cond][x_cond]
                                if (nume > 0):
                                    matrix[y_mat][x_mat] //= nume


                        elif (string_dir[n] == "<"):
                            nume = int(string_dir[n + 1])
                            x_cond = (x_cond - nume) % lenn_matriz
                            count += 2
                            if (count == largo_dir):
                                nume = matrix[y_cond][x_cond]
                                if (nume > 0):
                                    matrix[y_mat][x_mat] //= nume

                        elif (string_dir[n] == ">"):
                            nume = int(string_dir[n + 1])
                            x_cond = (x_cond + nume) % lenn_matriz
                            count += 2
                            if (count == largo_dir):
                                nume = matrix[y_cond][x_cond]
                                if (nume > 0):
                                    matrix[y_mat][x_mat] //= nume


                #bloque encargado de mover la posicion actual de la matriz hacia <- en la cantidad dada por patron
                elif("<" == x[0] and ("X" not in x or "Y" not in x)):
                    patron = re.search("\d+",x)
                    pat = patron.string[patron.start():patron.end()]
                    pat = int(pat)
                    x_mat = (x_mat - pat)%lenn_matriz


                #bloque encargado de mover la posicion actual de la matriz hacia -> en la cantidad dada por patron
                elif (">" == x[0] and ("X" not in x or "Y" not in x)):
                    patron = re.search("\d+", x)
                    pat = patron.string[patron.start():patron.end()]
                    pat = int(pat)
                    x_mat = (x_mat + pat)%lenn_matriz

                # bloque encargado de mover la posicion actual de la matriz hacia ARRIBA en la cantidad dada por patron
                elif ("U" == x[0] and ("X" not in x or "Y" not in x)):
                    patron = re.search("\d+", x)
                    pat = patron.string[patron.start():patron.end()]
                    pat = int(pat)
                    y_mat = (y_mat - pat) % lenn_matriz

                #bloque encargado de mover la posicion actual de la matriz hacia ABAJO en la cantidad dada por patron
                elif ("D" == x[0] and ("X" not in x or "Y" not in x)):
                    patron = re.search("\d+", x)
                    pat = patron.string[patron.start():patron.end()]
                    pat = int(pat)
                    y_mat = (y_mat + pat) % lenn_matriz



                #Bloque encargado para el print general o comando S
                elif("S"  == x[0]):
                    lis_aux = []
                    #Control para caso caracter que recorre matriz y concatena palabra mediante Lista
                    if(x[1] == "c"):

                        for j in matrix:
                            for k in j:
                                if(k == 127):
                                    lis_aux.append("\n")
                                if(32 < k < 127):
                                    lis_aux.append(chr(k))

                        string = "".join(lis_aux)
                        print(string)
                    #Control para caso entero que recorre matriz, concatena numeros mediante lista y finaliza con casteo a int
                    elif(x[1] == "e"):

                        for j in matrix:
                            for k in j:
                                lis_aux.append(str(k))

                        string = "".join(lis_aux)
                        n_string = int(string)
                        print(n_string)

                #Bloque de control encargado de printeo puntual o comando L
                elif ("L" == x[0]):
                    #Bloque encargado subcaso caracter
                    if (x[1] == "c"):

                        k = matrix[y_mat][x_mat]
                        if (32 < k < 127):
                            k1 = chr(k)
                            print(k1,end="")
                        elif(k == 127):
                            print("\n",end="")
                    # Bloque encargado subcaso caracter
                    elif (x[1] == "e"):

                        num = matrix[y_mat][x_mat]
                        print(num,end="")




                #caso Condicional
                if("?" == x[0]):
                    #Continua en ciclo hasta desaparecer ? de la linea
                    while("?" in x):
                        count = 0
                        y_cond = y_mat
                        x_cond = x_mat
                        aplica = False
                        dir = re.search("([<>UD]\d+)+",x)

                        largo_dir = dir.end() - dir.start()
                        string_dir = x[dir.start():dir.end()]

                        #Bloque revisa Dir variable y decide si cumple condicion para ejecutar comando
                        for n in range(largo_dir):
                            #Aprovechamos la paridad de Dir
                            if(string_dir[n] == "U"):
                                nume = int(string_dir[n+1])
                                y_cond = (y_cond - nume) % lenn_matriz
                                count +=2
                                if(count == largo_dir):
                                    nume = matrix[y_cond][x_cond]
                                    if(nume > 0):
                                        aplica = True

                            elif(string_dir[n] == "D"):
                                nume = int(string_dir[n + 1])
                                y_cond = (y_cond + nume) % lenn_matriz
                                count += 2
                                if (count == largo_dir):
                                    nume = matrix[y_cond][x_cond]
                                    if (nume > 0):
                                        aplica = True

                            elif(string_dir[n] == "<"):
                                nume = int(string_dir[n + 1])
                                x_cond = (x_cond - nume) % lenn_matriz
                                count += 2
                                if (count == largo_dir):
                                    nume = matrix[y_cond][x_cond]
                                    #Si el valor encontrado por el condicional es menor a 0 no pasara a ejecutar comando
                                    if (nume > 0):
                                        aplica = True

                            elif(string_dir[n] == ">"):
                                nume = int(string_dir[n + 1])
                                x_cond = (x_cond + nume) % lenn_matriz
                                count += 2
                                if (count == largo_dir):
                                    nume = matrix[y_cond][x_cond]
                                    if (nume > 0):
                                        aplica = True


                        #Bloque encargado de realizar comando y cortar string actual
                        if(aplica == True):
                            pattern = re.compile("\?"+ string_dir)
                            x = pattern.sub("",x)

                            #Si entra en control de if hay un ? anidado en el line
                            #por lo tanto hay que volver a procesar dir
                            if(x[0] == "?"):
                                aplica = False

                            #caso simple Aumentar dentro de Condicional
                            elif(x[0] == "A"):
                                matrix[y_mat][x_mat] += 1

                            #caso simple Disminuir dentro de Condicional
                            elif (x[0] == "B"):
                                matrix[y_mat][x_mat] -= 1

                            #caso simple Reinicio puntual dentro de Condicional
                            elif ("R" == x):
                                matrix[y_mat][x_mat] = 0
                            #caso simple Reinicio general dentro de Condicional
                            elif ("Z" == x):
                                for j in range(lenn_matriz):
                                    for k in range(lenn_matriz):
                                        matrix[j][k] = 0


                            #Casos complejos dentro de condicional
                            else:
                                patron = re.search("X([<>UD]\d+)+|Y([<>UD]\d+)+|L[ce]|S[ce]",x)
                                mach = patron.string[patron.start():patron.end()]
                                y_cond = y_mat
                                x_cond = x_mat
                                count = 0
                                dir = re.search("([<>UD]\d+)+", x)
                                largo_dir = dir.end() - dir.start()
                                string_dir = x[dir.start():dir.end()]

                                #Caso multiplicacion para Comando
                                if(mach[0] == "X"):
                                    for n in range(largo_dir):
                                        if (string_dir[n] == "U"):
                                            nume = int(string_dir[n + 1])
                                            y_cond = (y_cond - nume) % lenn_matriz
                                            count += 2
                                            if (count == largo_dir):
                                                nume = matrix[y_cond][x_cond]
                                                matrix[y_mat][x_mat] *= nume

                                        elif (string_dir[n] == "D"):
                                            nume = int(string_dir[n + 1])
                                            y_cond = (y_cond + nume) % lenn_matriz
                                            count += 2
                                            if (count == largo_dir):
                                                nume = matrix[y_cond][x_cond]
                                                matrix[y_mat][x_mat] *= nume


                                        elif (string_dir[n] == "<"):
                                            nume = int(string_dir[n + 1])
                                            x_cond = (x_cond - nume) % lenn_matriz
                                            count += 2
                                            if (count == largo_dir):
                                                nume = matrix[y_cond][x_cond]
                                                matrix[y_mat][x_mat] *= nume

                                        elif (string_dir[n] == ">"):
                                            nume = int(string_dir[n + 1])
                                            x_cond = (x_cond + nume) % lenn_matriz
                                            count += 2
                                            if (count == largo_dir):
                                                nume = matrix[y_cond][x_cond]
                                                matrix[y_mat][x_mat] *= nume

                                if(mach[0] == "Y"):
                                    for n in range(largo_dir):

                                        if (string_dir[n] == "U"):
                                            nume = int(string_dir[n + 1])
                                            y_cond = (y_cond - nume) % lenn_matriz
                                            count += 2
                                            if (count == largo_dir):
                                                nume = matrix[y_cond][x_cond]
                                                if (nume > 0):
                                                    matrix[y_mat][x_mat] //= nume

                                        elif (string_dir[n] == "D"):
                                            nume = int(string_dir[n + 1])
                                            y_cond = (y_cond + nume) % lenn_matriz
                                            count += 2
                                            if (count == largo_dir):
                                                nume = matrix[y_cond][x_cond]
                                                if (nume > 0):
                                                    matrix[y_mat][x_mat] //= nume


                                        elif (string_dir[n] == "<"):
                                            nume = int(string_dir[n + 1])
                                            x_cond = (x_cond - nume) % lenn_matriz
                                            count += 2
                                            if (count == largo_dir):
                                                nume = matrix[y_cond][x_cond]
                                                if (nume > 0):
                                                    matrix[y_mat][x_mat] //= nume

                                        elif (string_dir[n] == ">"):
                                            nume = int(string_dir[n + 1])
                                            x_cond = (x_cond + nume) % lenn_matriz
                                            count += 2
                                            if (count == largo_dir):
                                                nume = matrix[y_cond][x_cond]
                                                if (nume > 0):
                                                    matrix[y_mat][x_mat] //= nume


                                #Bloque de Print puntual dentro de condicional
                                elif ("L" == mach[0]):

                                    if (mach[1] == "c"):
                                        k = matrix[y_mat][x_mat]
                                        if (32 < k < 127):
                                            k1 = chr(k)
                                            print(k1)
                                        elif (k == 127):
                                            print("\n")


                                    elif (mach[1] == "e"):

                                        num = matrix[y_mat][x_mat]
                                        print(num)


                                #Bloque encargado del print general dentro del condicional
                                elif ("S" == mach[0]):
                                    lis_aux = []
                                    if (mach[1] == "c"):

                                        for j in matrix:
                                            for k in j:
                                                if (32 < k < 127):
                                                    lis_aux.append(chr(k))
                                                elif(k == 127):
                                                    lis_aux.append("\n")

                                        string = "".join(lis_aux)
                                        print(string)
                                    elif (mach[1] == "e"):

                                        for j in matrix:
                                            for k in j:
                                                lis_aux.append(str(k))

                                        string = "".join(lis_aux)
                                        n_string = int(string)
                                        print(n_string)

                        #Si el valor encontrado por el condicional final es 0 rompe el ciclo
                        elif(aplica == False):
                            break
    i +=1
file.close()

#Bloque encargado de escribir en txt si no hay errores
if(n_errores == 0):
    fp = open("errores.txt", 'a')
    fp.write("No hay errores!")
    fp.close()


#Bloque encargado de escribir en txt si solo hay errores
if(n_errores == lenn_matriz):
    fp = open("errores.txt", 'a')
    fp.write("No hay lineas correctas :c")
    fp.close()
