#lang scheme




;;(divisible? n-list x)
;;Funxion que checkea si el resto al realizar div es 0
;;Retorna true si es 0 false sino

(define (divisible? n-list x)
  (zero? (remainder n-list x)))

;;(mazo cartas div)
;;Funcion que checkea se encarga de crear una lista con los numeros divisible por div, de forma recursiva directa
;;Retorna lista con match adentro (.....) o nula () 
(define mazo
  (lambda (cartas div)
    (if (null? cartas)
        '()
        (if (divisible? (car cartas) div) (cons (car cartas) (mazo (cdr cartas) div))
            (mazo(cdr cartas) div))))
         )


