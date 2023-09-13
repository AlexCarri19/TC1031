## Analisis de complejidad temporal 

**Visit**
Peor caso: Lineal O(n)
Al hacer el display de los datos de las distintas formas posibles tiene que recorrer el arbol dato por dato. Dejandonos con unca complejidad lineal. 

Pre-order 
In-order 
Pos-torder
Level by level

**Height**
Peor caso: Lineal  O(n)
Para determinar la altura del arbol el algoritmo recorre todo el arbol punto por punto 

**Ancestors**
Peor caso: n/2 = O(n)
Al buscar en una mitad del conjunto de datos la busqueda se limita a la mitad sin embargo el comportamiento es igual solamente que tiene una pendiente más pronunciada (si lo  queremos ver de forma grafica, respecto al analisis temporal) manteniendo el comportamiento lineal 

**Level**
Peor caso: Lineal O(n)
Al buscar un elemento y regresar el nivel del arbol se comporta de forma lineal ya que debe de recorrer todo el arbol en el peor de los casos