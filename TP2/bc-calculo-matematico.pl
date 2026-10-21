contarDigitos(N, Cant) :-
	N < 10,
	Cant is 1.

contarDigitos(N, Cant) :-
	N >= 10,
	X is N // 10,
	contarDigitos(X, SubCant),
	Cant is SubCant + 1.

calcularProductoDigitos(N, Prod) :-
	N < 10,
	Prod is N.

calcularProductoDigitos(N, Prod) :-
	N > 10,
	X is N // 10,
	Y is N mod 10,
	calcularProductoDigitos(X, SubProd),
	Prod is Y * SubProd.
	
tieneCeros(N) :-
	N < 10,
	N \= 0,
	!.

tieneCeros(N) :-
	N < 10,
	N = 0,
	!.
	
tieneCeros(N, X) :-
	N >= 10,
	D is N mod 10,
	D = 0,
	!.

tieneCeros(N) :-
	N >= 10,
	D is N mod 10,
	D \= 0,
	tieneCeros(N // 10).

