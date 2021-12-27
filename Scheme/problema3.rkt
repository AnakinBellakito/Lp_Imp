#lang scheme
;;(sol n s)
;;funcion que toma los parametros y ejecuta una division simple 
;;retorna el resultado de la division 1/n^s

(define sol(lambda (n s) {/ 1 (expt n s)}))

;;(zeta_simple i s)
;;funcion que crea un ambiente con variables locales y ejecuta recursion simple sobre ese ambiente una cantidad de veces dada por parametros. 
;;retorna el resultado de la sumatoria de 1/n^s 
(define zeta_simple (lambda (i s)
                      (let rimm((index i ) (pow s) (n 1))
                        (if (= index 0)
                            0
                            (if (= index n) (+ (sol n pow))
                                (exact->inexact(+ (sol n pow) (rimm index  pow (+ n 1)) ))))
                        
                        )))



;;(zeta_cola i s)
;;funcion que crea un ambiente con variables locales y ejecuta recursion de cola sobre ese ambiente una cantidad de veces dada por parametros. 
;;retorna el resultado de la sumatoria de a qeu se va actualizando recursivamente.

(define zeta_cola (lambda (i s)
                      (let rimm((index i ) (pow s) (n 1) (a 0))
                        (if (= index 0)
                            0
                            (if (= index n) (exact->inexact( + a (sol n pow) ))
                                (rimm index pow (+ n 1) (+ a (sol n pow ))))
                        
                        ))))



;;(zeta_simple 2 3)
;;(zeta_cola 2 3)

;;(zeta_simple 3 2)
;;(zeta_cola 3 2)

