#include <stdio.h>
#include <assert.h>

int add5(int a){
    return a + 5;
}

int add6(int a){
    return a + 6;
}

int applyit(int (*f)(int ), int x)
{ // type of the return value (first int), type of the parameter 
    return f(x);
}

int main(void)
{    
    assert(1 == 0); // will stop the program
    int (*g)(int) = add6;
    printf("%d\n", applyit(add5, 2));
    printf("%d\n", g(12)); 
}