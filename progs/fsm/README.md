##  Construcción de un autómata finito

EAMartinez 20200622

### Objetivo

El objetivo es la construcción de un autómata finito aceptor con salidas en cada estado tipo Moore

En realidad, se realizarán los ejemplos vistos en clase de:

- Una máquina de venta de café
- Una tanteador de tennis

Se muestra que en el archivo _fsm\_moore.h_ se encuentra la definición
de las estructuras de datos que permitirán definir la funcionalidad del autómata
en forma indepemdiente del código ejecutable que se encuentra en _fsm\_moore.c_

Por lo tanto, la conjunción de ambos archivos mostrarán la realización de lo que
se denomina genéricamente un _motor_

La funcionalidad específica de cada autómata se encuentra en los archivos que se denominan
respectivamente _vend\_def.h_ para el caso de la máquina de venta y _game\_def.h_ para el caso
del tanteador de tennis

Estos archivos se incluyen respectivamente en _vend.c_ y en _game.c_ donde se encuentra el 
programa principal _main_; se puede observar mediante el simple comado:

~~~
    $ diff vend.c game.c
~~~

que los archivos son casi idénticos, salvo por la inclusión del _xxxx\_def.h_ que corresponde al proyecto
y por la diferencia de un par de comentarios en el encabezamiento

Por lo tanto, con el simple trabajo de redefinir solamente _xxxx\_def.h_ se puede implementar un autómata
para otro caso específico _sin cambiar el código del programa_

### Implementación

Puede verse en el _makefile_ los objetivos y recetas para este proyecto: se observa que el _make_
permitirá obtener la compilación de los dos ejecutables _vend_ y _game_.

Para el caso de _vend_, las entradas son mediante los códigos '1' y '2' que corresponden respectivamente
a las monedas de $1 y $2.

Para el caso de _game_ las entradas son mediante los códigos 's' y 'o' que corresponden respectivamente
al punto ganado por _servidor_ o por _oponente_.

Del resultado de poner toda la expresión terminada por _Enter_, el autómata mostrará todas las transiciones
y de resultas, terminará diciendo si _acepta_ la cadena de entrada, si la _rechaza_ o si hubo alguna entrada
que no corresponde al alfabeto admitido.

También, a los fines de prueba, se podrá redirigir la entrada _standard_ y/o la salida _standard_ a sendos archivos.
Para ello y para cada uno de los programas, se proveen los archivos _vend\_input_ y _game\_input_

De esta manera se puede trabajar por redireccionamiento:

~~~
    $ ./vend < vend_input
    $ ./vend > vend_output
    $ ./vend < vend_input > vend_output
~~~

Obviamente, lo mismo podrá hacerse en el caso de _game_

En el primer caso, se toma la entrada desde el archivo, mientras que la salida se muestra en pantalla.
En el segundo caso, se toma la entrada desde teclado pero la salida se la redirecciona a un archivo que se crea en ese momento.
En el tercer caso, se realizan las dos redirecciones.







