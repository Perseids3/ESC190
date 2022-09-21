#include "Lec1.h" // "" This means look for lec1.h in the same directory with this file
#include <stdio.h> // <> This is for buily-in head files
// #include is like copy and paste all the stuff in that head file here

/*
C is a complied language:
Write a C program -> Run the compiler -> Generate a binary code -> Let's go operating system.
Python does not need that. Python execute like an operating system.
*/

/*
In terminal, you can do things like
1. Enter the directory of the files you want to compile together
2. input: gcc lec1.c functions.c -o lec1
This will give you a file called lec1
3. input ./lec1  -> run the compiled file lec1
*/

// In C, you have to declare the function before
// you use it in main(); you can do that by only declare it without 
// actually write it


// Pre-processor:
// This is a macro. C will substitute in 190 whenever you use COURSE. This is not like variable in the sense that what
// C does is simply find-and-replace before compilation.
// By convention, macros are written in all-caps (though that is not mandatory).
#define COURSE 190
#define ABS(x) if (x<0) -x else x
// This is equivalent to
// #define ABS(x) ((x>0)? (x):(-x))





// Aside on C syntax: 
/*
COND ? OUT1 : OUT2
   is the same as
if(COND){
    a = OUT1
}else{
    a = OUT2
}

That is, the value of COND ? OUT1 : OUT2 is OUT1 if COND is non-zero, and OUT2 otherwise

*/

//Function like macros: C will replace any MAX(a, b) with (((a) > (b))? (a):(b))
//before compiling
#define MAX(x, y) (((x) > (y))? (x):(y))


// This is not quite like MAX, because it only works with integers.
// Using a function can be slower (since the function needs to be called). Functions
// only take in specific types of inputs.
int max_fn(int a, int b)
{
    return (a > b) ? a : b;
}



int main(void){
    f();
    printf("%f\n", MAX(2.3, 5.4));
    printf("%d\n", COURSE);
    return 0;
}
