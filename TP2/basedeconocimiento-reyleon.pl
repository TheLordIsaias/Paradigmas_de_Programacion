progenitor(ahadi, mufasa).
progenitor(uru, mufasa).
progenitor(ahadi,scar).
progenitor(uru, scar).
progenitor(mufasa, simba).
progenitor(sarabi, simba).
progenitor(scar, kovu).
progenitor(scar, nuka).
progenitor(scar, vitani).
progenitor(zira, kovu).
progenitor(zira, nuka).
progenitor(zira, vitani).
progenitor(simba, kopa).
progenitor(simba, klara).
progenitor(nala, kopa).
progenitor(nala, klara).

masculino(ahadi).
masculino(mufasa).
masculino(scar).
masculino(simba).
masculino(kopa).
masculino(kovu).
masculino(nuka).

femenino(uru).
femenino(sarabi).
femenino(zira).
femenino(nala).
femenino(klara).
femenino(vitani).

padreDe(Y, X) :- progenitor(Y, X), masculino(Y).
madreDe(Y, X) :- progenitor(Y, X), femenino(Y).
hijoDe(Y, X) :- padreDe(X, Y), masculino(Y).
hijaDe(Y, X) :- padreDe(X, Y), femenino(Y).
abueloDe(Z, X) :- padreDe(Z, Y), padreDe(Y, X).
abuelaDe(Z, X) :- madreDe(Z, Y), padreDe(Y, X).
hermanoDe(Z, Y) :- padreDe(X, Y), padreDe(X, Z), masculino(Y), Z \= Y. 
hermanaDe(Z, Y) :- padreDe(X, Y), padreDe(X, Z), femenino(Y), Z \= Y.
primoDe(Z, Y) :- abueloDe(Y, X), abueloDe(Z, X), masculino(Y), Z \= Y.
primaDe(Z, Y) :- abueloDe(Y, X), abueloDe(Z, X), femenino(Y), Z \= Y.
tioDe(Z, Y) :- abueloDe(X, Y), hijoDe(X, Z).
tiaDe(Z, Y) :- abueloDe(X, Y), hijaDe(X, Z).

bisabueloDe(Z, X) :- padreDe(Z, Y), abueloDe(Y, X).