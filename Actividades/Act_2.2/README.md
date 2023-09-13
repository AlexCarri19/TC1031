## Análisis de complejidad temporal

**Insertion**

Peor caso: Lineal O(n)
Debido al recorrido de la lista, en el caso de exeder la insertion al primer elemento el comportamiento lineal de la insertion hace ir nodo por nodo hasta insertar en el ultimo elemento. 

**Search**

Peor caso: Lineal O(n)
Debido a que en el peor de los casos el elemento que se esta buscando estaria al final de la lista tendria que recorrer punto por punto, nodo por nodo 

**Update**

Peor caso: Lineal O(n)
En el caso de que el elemento a actualizar este en el ultimo lugar de la lista, es que se tienen el peor caso ya que se tienen que recorrer todos los nodos. 

**DeleteAt**

Peor caso: Lineal O(n)
Igual que en los otros analisis, el peor caso se da cuando el elemento esta al final de la lista ligada. Debido a que tiene que recorrer elemento por elemento para llegar al ultimo elemento y terminar.