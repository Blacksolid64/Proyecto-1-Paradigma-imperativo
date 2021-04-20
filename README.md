# Proyecto-1-Paradigma-imperativo
Descripción   del   problema:   La   teoría   matemática   permite   predecir   algunos   resultados experimentales en el mundo real. Esto se torna muy interesante cuando estos resultados involucran eventos aleatorios, dada la naturaleza impredecible de estos. Cuando se formula el resultado teórico queda aún la duda del significado de ese resultado con respecto al mundo real, y la forma en que se puede comprobar. La computadora ofrece una oportunidad de experimentación extraordinaria,debido a su gran velocidad y a la facilidad de programarla para que lleve a cabo una cantidad suficientemente grande de experiencias simuladas que permiten poner a prueba los resultados teóricos.
Descripción del proyecto:  Se requiere un programa que haga una verificación experimental de algunos resultados teóricos de probabilidad discreta, relacionados con manos de poker, y que juzgue si tales resultados son coherentes desde el punto de vista de la estadística.
Propósito didáctico: 
1.Principal: reconsiderar el paradigma de programación imperativa, desde el punto de vista del desarrollo de software estructurado.
2.Secundarios:
1.Fomentar en el estudiante el uso de la computadora como herramienta de experimentación matemática.
2.Que el estudiante conozca algunos conceptos básicos de probabilidad discreta.
3.Ahondar en las relaciones entre la probabilidad y la estadística como disciplinas importantes para hacer afirmaciones racionales sobre la ocurrencia de fenómenos imprevisibles.Descripción detallada:Lenguaje de programación: C.Qué deberá hacer exactamente el programa: Se conoce la probabilidad de varias manos depoker, deduciéndolas como la probabilidad de una extracción de cinco cartas, en un muestreo sin repetición, de una baraja (inglesa) correcta. Estas probabilidades pueden expresarse como cocientes de productos de coeficientes binomiales. Las manos que nos interesan son: dos pares, full house,cuatro cartas (quad/poker) y la escalera real. La labor del programa es:
1.Calcular   la   probabilidad   teórica   de   cada   mano   basado   en   la   fórmula   de   coeficientes binomiales. Es   decir,  hay  que  calcular  al  menos   un coeficiente  binomial  y  hacer  las multiplicaciones y divisiones necesarias.
2.Hacer m simulaciones del lanzamiento de n manos de poquer. En cada simulación hay que:
1.Simular el lanzamiento de n manos de poquer, contando en cuántas manos aparecen las combinaciones dichas arriba. Hay que justificar a las cuántas manos se reinicializa la baraja (o sea, barajar de nuevo el mazo), y hay que justificar también (mediante criterios estadísticos) el valor de n. El simular el lanzamiento de cada mano de poker significa la implementación de un muestreo aleatorio sin reposición.
2.Cuando se termine la simulación el programa calculará la probabilidad empírica de las manos a partir de la simulación.
3.Con los valores de todas las simulaciones se calculará la media y la varianza de las probabilidades empíricas.
4.Se comparará la media con la probabilidad teórica, anunciándo al usuario la media, la varianza, el valor teórico, el error de la media con respecto al valor teórico.
Requerimiento de diseño: el programa deberá ser diseñado usando la técnica de programación estructurada,   documentando   esta   mediante   diagramas   de   Nassi-Schneiderman,   donde   la documentación interna del programa deberá permitir ubicar cada bloque de código en el diagrama correspondiente.  Esto implica  que cada  diagrama deberá  tener  un título, y ese título  deberá corresponder   a   un   nombre   de   procedimiento,   nombre   de   función   o   deberá   aparecer   en   un comentario al inicio del bloque de instrucciones que implementa un diagrama específico. En el caso de los procedimientos y funciones, un comentario deberá indicar el número de diagrama en que se encuentra el algoritmo. Los nombres de bloque deberán ser relevantes, es decir, deberán tener sentido para una persona que esté verificando la implementación del algoritmo.
Interface de usuario:  es una interfase simple, al inicio el programa anuncia su propósito y los valores de sus parámetros:  m  y  n, y cuando termina de hacer las simulaciones anuncia susresultados: valor teórico, media, varianza, error de la media respecto al valor teórico, para cada una de   las   cuatro   manos   solicitadas.   Sin   embargo,   si   el   programa   tarda   mucho   para   hacer   las simulaciones, deberá mostrar algún tipo de indicador de actividad.
Evaluación
Ejecucion (60%)
Resultados correctos de Dos pares, Full house, Cuatro cartas (quad/poker) y la Escalera real, 15% cada uno.
Documentación (40%)
Juego completo de diagramas N-S (15%)
Descripción y justificación informal del algoritmo de muestreo sin reposición. (10%)
Correspondencia entre la documentación interna y externa. (15%)
Fecha y forma de entrega: 12 de Mayo de 20
