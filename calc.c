#include <stdio.h>
#include <stdlib.h>

double getNumber(const char *prompt) {
    char line[100];
    char *end;
    double value;

    while (1) {
        printf("%s", prompt);
        if (fgets(line, sizeof(line), stdin) == NULL) exit(1);

        value = strtod(line, &end);

        if (end == line) {
            printf("That's not a number, try again.\n");
            continue;
        }

        while (*end == ' ' || *end == '\t') end++;

        if (*end != '\n' && *end != '\0') {
            printf("That's not a number, try again.\n");
            continue;
        }

        return value;
    }
}

char getChar(const char *prompt) {
    char line[100];
    int i = 0;

    printf("%s", prompt);
    if (fgets(line, sizeof(line), stdin) == NULL) exit(1);

    while (line[i] == ' ' || line[i] == '\t') i++;
    return line[i];
}

int main() {
    double a, b, answer;
    char symbol;
    char again;
    const char *error = NULL;

    do {
        error = NULL;

        a = getNumber("Enter first number: ");

        symbol = getChar("Enter symbol (+, -, *, /): ");
        while (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') {
            printf("Unknown operator. Use +, -, *, or /\n");
            symbol = getChar("Enter symbol (+, -, *, /): ");
        }

        b = getNumber("Enter second number: ");

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
                if (b == 0) 
                    {
                        error = "Error: Cannot divide by zero!";
                    } 
                else 
                {
                    answer = a / b;
                }
            }

        if (error) {
            printf("%s\n", error);
        } else {
            printf("Answer: %g\n", answer);
        }

        do {
            again = getChar("\nAnother operation? (y/n): ");
        } while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');
        printf("\n");

    } while (again == 'y' || again == 'Y');

    printf("Bye!\n");
    system("pause");
    return 0;
}
