#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, b, answer;
    char symbol;
    char error;

    printf("Enter first number: ");
    scanf("%lf", &a);

    printf("Enter symbol (+, -, *, /): ");
    scanf(" %c", &symbol);

    printf("Enter second number: ");
    scanf("%lf", &b);

    if (symbol == '+') 
        {
        answer = a + b;
        } 
    else if (symbol == '-') 
    {
        answer = a - b;
    } 
        else if (symbol == '*') 
            {
                answer = a * b;
            } 
        else if (symbol == '/') 
            {
        if (b == 0) {
            error = "Error: Cannot divide by zero!";
        } else {
            answer = a / b;
        }
    } 
        else 
    {
        error = "Error: Unknown operator. Use +, -, *, or /";
    }

    if (error) {
        printf("%s\n", error);
        return 1;
    }

    printf("Answer: %g\n", answer);

    return 0;
}