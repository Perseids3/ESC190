// Another A+ Please! 
#include <stdio.h>
// <stdio.h> is for output stuff 

#include <stdlib.h>
// There cannot be commands outside of function.

// When defining a variable, you need to declare the type:
    // double(float); char(character); int == bool;
    // A lot more to know about this shit

/* Multi-line comment:
hihihihihi end with */

// Every statement ends with a semi-colon ";"  MANDATORY.


// When defining a function, you also need to declare on what 
// type of value the function is expected to return.
// Here, "void" then requires the function to return nothing
void f(int a)
{
    printf("%d", 2*a);
} // The body of a function must be included in {}


// There must be a main function for a C program
int main() // same as int main(void), void just means "nothing"
{
    int a = 8; 

    // printf(): 

    // Apparently, you can directly print stuff with printf()
    // For example: printf("Guerzhoy wants to have a GPA of 4.0 in Praxis")
    // But you cannot do printf(12345), only string can be directly printed by printf()

    // If you want to use variable:
    // char* student = "Guerzhoy"; double GPA = 4.0; char* course = "Praxis"
    // printf("%s wants to have a GPA of %f in %s",student,GPA, course);
    // you need to indicate what is the structure of this print command 
    // by putting %d,%s... into '' For example, 
    // char* student = "Guerzhoy"; double GPA = 4.0; char* course = "Praxis";
    // printf("%s wants to have a GPA of %f in %s",student, GPA, course);


    // N O T I C E!!! Do not use single quotation mark in printf()!!! 
    // I don't know why for now, but just DO NOT do that! 
    // should print ("Guerzhoy wants to have a GPA of 4.0 in Praxis")


    printf("2*a = %d\n", 2*a);  // %d: decimal (int)
                                // %s: string
                                // %ld: long   (long int)
                                // %f: float
    // This line should print: "2 * a = 16"
    printf("name = %s, name2 = %s, course = %d\n", "mike", "jake", 190);

    // // for if statement:
    // 1. condition needs to be put in ()
    // 2. what will happen if the condition fits needs to be put in {}
    // 3. CANNOT do things like "100> grade > 60", will figure our this later
    int grade = 97;
    if(grade >= 200)
    {
        printf("You must be lying\n");
    }
    else if(grade > 60)
    {
    printf("Not bad\n");
    } 
    else
    {
        printf("You suck");
    }


/* A brief explanation of the memory model of C:
In Python, when we create a variable, the variable's name will be pointing at one address. This address is pointing at a value. 
When we change the value of the  variable, a different link is created between the variable's name and a different adress. 

In C, when we create a variable, the variable's name will be pointing at one address, and this address is pointing at a value. 
When we change the value of the variable, C will change the value of the address of the variable's name. */


    // Type: pointer
    int *p_a = &a;
    // & : the address of some variable
    // int * : the address of an integer 
    printf("%ld\n", p_a);
    // *: the value at the some address 
    // First, int* p_a tells that: 1. the name of the variable is p_a; 2. it is an address of an integer;
    // Second, &a is the address of the variable a
    // Third, * p_a means the value at the address p_a
    printf("%d\n", *p_a);

    return 0;
}