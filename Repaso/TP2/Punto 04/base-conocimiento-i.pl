contarDigitos(0, 0).
contarDigitos(N, Cant) :-
	N > 0,
	N =< 10,
	Cant is 1.
contarDigitos(N, Cant) :-
	N >= 10,
	N1 is N // 10,
	contarDigitos(N1, SubCant),
	Cant is SubCant + 1.

productoDigitos(0, 0).
productoDigitos(N, Prod) :-
	N > 0,
	N =< 10,
	Prod is N.
productoDigitos(N, Prod) :-
	N > 10,
	Dig is N mod 10,
	N1 is N // 10,
	productoDigitos(N1, SubProd),
	Prod is Dig * SubProd.
	
tieneCero(X, true) :-
	X < 10,
	X == 0 .
tieneCero(X, false) :-
	X < 10,
	X \= 0 .
tieneCero(X, true) :-
	X >= 10,
	Dig is X mod 10,
	Dig == 0 .
tieneCero(X, Y) :-
	X >= 10,
	Dig is X mod 10,
	Dig \= 0,
	X1 is X // 10,
	tieneCero(X1, Y).
	
menorValor(X, Y) :-
	X < 10,
	Y is X.
menorValor(X, Y) :-
	X >= 10,
	Dig is X mod 10,
	X1 is X // 10,
	menorValor(X1, SubY),
	Dig < SubY,
	Y is Dig.
menorValor(X, Y) :-
	X >= 10,
	Dig is X mod 10,
	X1 is X // 10,
	menorValor(X1, SubY),
	Dig > SubY,
	Y is SubY.
	
nPrimeros(0, []).
nPrimeros(X, [ H | T ]) :-
	X > 0,
	X1 is X-1,
	H is X,
	nPrimeros(X1, T).
	
