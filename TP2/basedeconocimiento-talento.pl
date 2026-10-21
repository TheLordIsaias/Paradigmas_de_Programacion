talento(juan, cantar).
talento(juan, pintar).
talento(pedro, escribir).
talento(pedro, cantar).
talento(patricia, pintar).
talento(luisa, escribir).
talento(maria, cantar).
talento(lucas, bailar).
talento(ana, escribir).

talentoso(X) :- talento(X, Y), talento(X, Z), Y \= Z.
semejantes(X, Y) :- talento(X, Z), talento(Y, Z), X \= Y.
