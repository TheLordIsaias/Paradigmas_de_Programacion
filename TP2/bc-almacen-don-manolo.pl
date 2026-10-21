% Base de Conocimiento ALMACEN DON MANOLO

producto(lacteo, leche).
producto(lacteo, manteca).
producto(lacteo, crema).
producto(lacteo, yogurt).
producto(fiambre, queso).
producto(fiambre, jamonCrudo).
producto(fiambre, jamonCocido).
producto(fiambre, salame).
producto(panaderia, pan).
producto(panaderia, factura).
producto(panaderia, tortilla).
producto(panaderia, galleta).
producto(bebida, agua).
producto(bebida, gaseosa).
producto(bebida, jugo).
producto(bebida, soda).
producto(golosina, chocolate).
producto(golosina, caramelo).
producto(golosina, mantecol).
producto(golosina, bombones).
producto(golosina, nugaton).

precio(leche, 77).
precio(manteca, 62).
precio(crema, 95).
precio(yogurt, 53).
precio(queso, 80).
precio(jamonCrudo, 170).
precio(jamonCocido, 100).
precio(salame, 85).
precio(pan, 80).
precio(factura, 20).
precio(tortilla, 10).
precio(galleta, 75).
precio(agua, 86).
precio(gaseosa, 130).
precio(jugo, 98).
precio(soda, 100).
precio(chocolate, 116).
precio(caramelo, 35).
precio(mantecol, 87).
precio(bombones, 140).
precio(nugaton, 51).

precioRangoBebida(Producto, Min, Max) :- 
	producto(bebida, Producto), precio(Producto, Y), Y > Min, Y < Max.

montoAPagar([], 0).

montoAPagar([ Cabecera | Cola], Total) :-
	precio(Cabecera, Precio),
	montoAPagar(Cola, Subtotal),
	Total is Subtotal + Precio.

esGolosina(X) :-
	producto(golosina, X).

eliminarGolosinas([], []).

eliminarGolosinas([X | Cola], Resultado) :-
	esGolosina(X),
	eliminarGolosinas(Cola, Resultado).
	
eliminarGolosinas([X | Cola], [X | Resultado]) :-
	\+ esGolosina(X),
	eliminarGolosinas(Cola, Resultado).
	
tienenMismaCategoria(X, Y) :-
	producto(A, X),
	producto(B, Y),
	A = B.
	
promoSemanal(X, Y, Total) :- 
	tienenMismaCategoria(X, Y),
	precio(X, A),
	precio(Y, B),
	A < B,
	Total is A*0.3 + B.

promoSemanal(X, Y, Total) :- 
	tienenMismaCategoria(X, Y),
	precio(X, A),
	precio(Y, B),
	B < A,
	Total is A + B*0.3.
	
promoSemanal(X, Y, Total) :- 
	tienenMismaCategoria(X, Y),
	precio(X, A),
	precio(Y, B),
	B = A,
	Total is A + B*0.3.
	
promoSemanal(X, Y, Total) :- 
	\+ tienenMismaCategoria(X, Y),
	precio(X, A),
	precio(Y, B),
	Total is A + B.

	
	
	