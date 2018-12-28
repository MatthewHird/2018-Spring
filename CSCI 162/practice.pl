size([], 0).
size([_|T], S1) :-
    size(T, S2),
    S1 is S2 + 1.  
    
subsequence(_,[]).   
subsequence([X|T1], [X|T2]):- 
    subsequence(T1, T2).
subsequence([_|T1], [X|T2]):- 
    subsequence(T1, [X|T2]).
