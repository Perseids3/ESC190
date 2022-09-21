// 3(a). (10 pts)
//    Consider the following graph:

//    A--B--C
//       |
//       |
//       D-F-G  
//    Write *two* possible depth-first traversals of the graph, starting from node A.

/*
Answer: DFT
1.A->B->D->F->G->C
2.A->B->C->D->F->G
*/

//    Write two possible breadth-first traversals of the graph, starting from node G.

/*
Answer: BFT
1.G->F->D->B->A->C
1.G->F->D->B->C->A
*/



// 3(b). (5 pts)

//    Explain why there can be more than one depth-first traversals.

//    Submit the file Q3.c which only contain the answers to Q3(a) and Q3(b), as comments.
//    Recall that you can make multi-line comments using
/*
    Ans: 3(b)
    COnsidering DFT, at node B, there will be two arbitrary options:
    1. B is connected to D, by the definition of logic, the next one to be visit will be the
    unvisitied node directly connected to D (if there exists). Then once we reach node G, it comes
    back to C.
    2. B is connected to C, but C has no other connection to unvisited node.
    Therefore it goes back to the connection of B, which gives D->F->G.
*/ 
   