## Analisis de complejidad Temporal 

**Add**

>Peor caso: Logaritmico O(log n)
Al acomodarlo como arbol bst el recorrido es unilateral y nunca va a recorrer el arbol completo, reduciendo el recorrido de forma drastica, ademas de que la.

**Remove**

>Peor caso: Logaritmico O(log n)
Se busca primero que el valor si exista viendo si está en la derecha o izquierda, partiendo el árbol, para su posterior eliminación y reacomodo, de modo que su complejidad en el peor de los casos es O(log(n)) <-- Logarítmica.

**Find**

>Peor caso: Logaritmico O(log n)
Como los elementos más buscados o más recientes se encontrarán más cerca de la raíz, los tiempos son más cortos, de modo que en peor de los casos, simplemente se irá diviendo en dos partes hasta encontrar el valor deseado, de modo que su complejidad en el peor de los casos es O(log(n)) <-- Logarítmica

**Size**

>Peor caso: Constante O(1)
Ésta función simplemente retorna el tamaño del Splay Tree al momento de ir agregando nodos, de modo que su complejidad en el peor de los casos es O(1) <-- Constante. Solo realiza un paso siempre.