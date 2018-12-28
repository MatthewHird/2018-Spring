attach([],X,X).
attach([H|T1],X,[H|T2]):- attach(T1,X,T2).



%size([],

size([], 0).
size([_|T], S1) :-
    size(T, S2),
    S1 is S2 + 1.



halves(L,F,B):-
	append(F,B,L),
	size(L,S),
	FS is ceiling(S/2),
	size(F,FS).
	
	
