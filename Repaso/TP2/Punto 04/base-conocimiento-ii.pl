cantElementos([], 0).
cantElementos([H | T], X) :-
	cantElementos(T, SubX),
	X is SubX + 1 .
	
	
sumaElementos([], 0).
sumaElementos([H | T], X) :-
	sumaElementos(T, SubX),
	X is SubX + H.
	
eliminarOcurrencia([], X, []).
eliminarOcurrencia([ H | T ], X, [H | Y]) :-
	H \= X,
	eliminarOcurrencia(T, X, Y).
eliminarOcurrencia([ H | T ], X, Y) :-
	H == X,
	eliminarOcurrencia(T, X, Y).
	
elementosMayoresQue([], X, []).
elementosMayoresQue([H | T], X, [H | Y]) :-
	H > X,
	elementosMayoresQue(T, X, Y).
elementosMayoresQue([H | T], X, Y) :-
	H =< X,
	elementosMayoresQue(T, X, Y).
	
invertirLista([], []).
invertirLista([H | T], Y) :-
	invertirLista(T, SubY),
	append(SubY, [H], Y).

	