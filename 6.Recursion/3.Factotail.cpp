/*Solve the above factorial problem using tail recursion*/
#include <iostream>
unsigned long long factorial(unsigned int n, unsigned long long a)
{
    if (n == 0)  
        return a;
    else
        return factorial(n-1, n*a); 
}

int main()
{
    unsigned int number;
    printf("Enter a positive integer: ");
    scanf("%u", &number);
    printf("Factorial of %u = %llu\n", number, factorial(number, 1));
    return 0;
}
