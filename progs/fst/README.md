## Construcción de un autómata controlador

EAMartinez 20200622

### Objetivo

El objetivo es la construcción de un autómata controlador de tránsito

El ejemplo se ha tomado de las filminas de clase que están en el archivo _FiniteAutomata.pdf_
que se encuentra en el directorio _class_ mediante el diagrama de estados que se encuentra en la filmina 16.

Se ha tomado este ejemplo sencillo para mostrar cómo se realiza un controlador _que no posee estado final_
sino que funciona en un _loop_ infinito y además, se quiere mostrar la realización de un trasductor tipo _Mealy_
donde las salidas son función del estado actual y de las entradas.

### Implementación

En este caso, y por una mayor sencillez de implementación, las salidas se han realizado mediante una función o rutina de acción
que se invoca en cada una de las transiciones.

Como en el caso visto anteruiormente, se trata de hacer un _motor_ que sea independiente del caso particular de autómata,
lo cual se realiza mediante los archivos _fst\_mealy.h_ y _fst\_mealy.c_.

La idiosincracia particular del controlador de tránsito está colocada en el archivo de inclusión _traffic\_def.h_.

El programa principal con la función _main_ se encuentra en _traffic.c_ donde se incluye el archivo _traffic\_def.h_.

Como se necesita un _timer_, se implementa una interrupción periódica cada segundo, lo cual se encuentra en el archivo
_clock.c_.

Las rutinas de acción que se encuentran en las transiciones de estado, se ebcuentran en el archivo _actions.c_, mientras
que le manejo del _timer_, se encuentra en _act\_tiner.c_.

Por último, el manejo de los semáforos se encuentra implementado en _lights.c_

El _makefile_ permite la compilación del conjunto

 




