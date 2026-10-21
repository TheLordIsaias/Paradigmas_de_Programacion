progenitor(ahadi, mufasa).
progenitor(ahadi, scar).
progenitor(uru, mufasa).
progenitor(uru, scar).
progenitor(sarabi, simba).
progenitor(mufasa, simba).
progenitor(scar, kovu).
progenitor(scar, nuka).
progenitor(scar, vitani).
progenitor(zira, kovu).
progenitor(zira, nuka).
progenitor(zira, vitani).
progenitor(nala, kopa).
progenitor(nala, klara).
progenitor(simba, kopa).
progenitor(simba, klara).

femenino(uru).
femenino(sarabi).
femenino(zira).
femenino(nala).
femenino(vitani).
femenino(klara).

masculino(ahadi).
masculino(mufasa).
masculino(scar).
masculino(simba).
masculino(kovu).
masculino(nuka).
masculino(kopa).

padreDe(Y, X) :- progenitor(Y, X), masculino(Y).
madreDe(Y, X) :- progenitor(Y, X), femenino(Y).
hijoDe(Y, X) :- progenitor(X, Y), masculino(Y).
hijaDe(Y, X) :- progenitor(X, Y), femenino(Y).
abueloDe(Z, X) :- progenitor(Y, Z), progenitor(X, Y), masculino(X).
abuelaDe(Z, X) :- progenitor(Y, Z), progenitor(X, Y), femenino(X).
hermanoDe(Z, X) :- progenitor(Y, Z), progenitor(Y, X), masculino(X), X \= Z.
hermanaDe(Z, X) :- progenitor(Y, Z), progenitor(Y, X), femenino(X), X \= Z.
primoDe(Y, X) :- progenitor(T, Y), progenitor(S, X), progenitor(U, T), progenitor(U, S), masculino(Y).
primaDe(Y, X) :- progenitor(T, Y), progenitor(S, X), progenitor(U, T), progenitor(U, S), femenino(Y).
tioDe(Z, X) :- (primoDe(Y, X); primaDe(Y, X)), padreDe(Z, Y).
tiaDe(Z, X) :- (primoDe(Y, X); primaDe(Y, X)), madreDe(Z, Y).
bisabueloDe(Z, X) :- padreDe(Z, Y), (abueloDe(Y, X);abuelaDe(Y, X)).
bisabuelaDe(Z, X) :- madreDe(Z, Y), (abueloDe(Y, X);abuelaDe(Y, X)).