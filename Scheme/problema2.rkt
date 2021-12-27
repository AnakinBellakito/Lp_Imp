#lang scheme




;;(transformacion f1(x) f2(x) numeros)
;;La funcion debe aplicar la f1 y f2 para los numeros de la lista, guardandolo en r1 y de la misma manera cambiando el orden de las funciones y guardando en r2
;; y despues se procede a agregar el mayor entre r1 y r2 a una lista
;;Retorna lista con los match en el algoritmo
(define transformacion (lambda (f1 f2 numeros) 
      (cond ((null? numeros ) '())
           (else  (let rec
      (
       (r1 (f2 (f1 (car numeros ))))
       (r2 (f1 (f2 (car numeros ))))
        )
       
      (if (< r1 r2 )
           (cons r2 (transformacion f1 f2 (cdr numeros))) 
          (if (< r2 r1) (cons r1 (transformacion f1 f2 (cdr numeros)))
              ("Son iguales"))
          )

      )))))

