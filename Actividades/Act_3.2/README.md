## Análisis de complejidad temporal 

**Push**

Peor caso: Logaritmica O(log n)
Pone el valor deseado en la raíz de el arbol y despus comparar elementos para hacer un swap (en caso de ser necesario) a cada uno de los niveles manteniendo un orden. 

**Pop**

Peor caso: Logaritmica O(log n)
Se sigue una serie de la misma manera que el push pero elminando un valor, despues se evalua para usar la funcion swap y tener el mismo orden restandole el punto deseado. 

**Top**

Peor caso: Constante O(1)
Al verificar el contenido del elemento de una lista se hace con la misma cantidad de casos en cualquier situacion. El no hacer un recorrido de mas de un elemento lo deja como constante 

**Empty**

Peor caso: Constante O(1)
Al ser una consulta de informacion y devolver 0 o 1 el proceso se hace en un paso dando un resultado constante .

**Size**

Peor caso: Constante O(1)
Al debolver un contador es meramente una extraccionde informacion que se hace en un paso. Dando e resultado constante 