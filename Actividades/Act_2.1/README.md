## Analisis de complejidad Temporal

**Insertion**

Pero caso: lineal O(n)
Debido a que se tiene que recorrer toda la lista y añadir el nuevo nodo, a menos que sea el primer elemeto.


**Search**

Peor Caso: Lineal O(n)
Debido a que en el peor de los casos el elemento que se esta buscando estaria al final de la lista.


**Update**

Peor caso: Lineal O(n)
En el caso de que el elemento a actualizar este en el ultimo lugar de la lista es que se tienen el peor caso. 

**Delete All**

Peor caso: Lineal O(n)
Igual que en los otros analisis, el peor caso se da cuando el elemento esta al final de la lista ligada. Debido a que tiene que buscar el elemento (en caso de ser uno) o llegar al ultimo elemento para borrar todo. 