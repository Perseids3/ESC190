#include <stdio.h>
void swap(int *p_a, int *p_b)
{
    int temp = *p_a;
    *p_a = *p_b;
    *p_b = temp;
}

int main(void){
    int a = 5;
    int *p_a = &a;
    printf("%d\n",a);
    printf("address of a: %ld\n", p_a);
    *p_a = 4; //a becomes 4
    // Notice that an address also has an address,
    // the logic here is: int ** means the address of a type --- address
    int **pp_a = &p_a;
    printf("the address of address of a: %ld\n",pp_a);
    printf("the value at the address of the address of a: %ld\n",*pp_a);
    printf("%d\n",a);

    int b = 6;
    swap(&a, &b);
    printf("%d\n",a);
    swap(&a, &b);
    printf("%d\n",a);

    return 0;
}

