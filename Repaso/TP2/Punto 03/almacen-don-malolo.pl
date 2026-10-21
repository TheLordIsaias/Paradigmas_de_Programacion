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

rangoBebidas(X, Y, Z) :-
	producto(bebida, Z),
	precio(Z, P),
	P >= X,
	P =< Y.
	
totalAPagar([], 0).
totalAPagar([ H | T ], Y) :-
	precio(H, SubY),
	totalAPagar(T, Total),
	Y is SubY + Total.
	
eliminarPorCategoria([], []).
eliminarPorCategoria([ H | T ], XS):-
	producto(golosina, H),
	eliminarPorCategoria(T, XS).
eliminarPorCategoria([ H | T ], [ H | XS ]) :-
	\+ producto(golosina, H),
	eliminarPorCategoria(T, XS).
	
promoSemanal(X, Y, Total) :-
	producto(Z, X),
	producto(Z, Y),
	precio(X, S),
	precio(Y, T),
	SubTotal is S + T,
	SubTotal < 200,
	Total is S + (T * 0.3).
	