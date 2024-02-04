
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

char displayOptions() {
    char option;
    printf("\nSelect one of the following items:\n");
        printf("B) - Binary Mathematical Operations\n");
        printf("U) - Unary Mathematical Operations\n");
        printf("A) - Advanced Mathematical Operations\n");
        printf("V) - Define variables and assign them values\n");
        printf("E) - Exit\n");
        printf("Please enter your option: ");

    while (1) {
        scanf(" %c", &option);

        if (option == 'B' || option == 'U' || option == 'V' || option == 'A' || option == 'E') {
            return option;
        } else {
            printf("Invalid option. Please enter a valid option: ");
            return 1;
        }
    }
}


float performBinaryOperation(float num1, float num2, char operation) {
    float ans;
    switch (operation) {
                    case '+': ans = num1 + num2; break;
                    case '-': ans = num1 - num2; break;
                    case '*': ans = num1 * num2; break;
                    case '/':
                        if (num2 == 0) {
                            printf("Division by zero is not allowed.\n");
                        }
                        ans = num1 / num2;
                        break;
                    case '%': ans = fmodf(num1, num2); break;
                    case 'P': ans = powf(num1, num2); break;
                    case 'X': ans = fmaxf(num1, num2); break;
                    case 'I': ans = fminf(num1, num2); break;
                    default: break;
                }
                printf("The result is %.2f\n", ans);
                
}

float performUnaryOperation(float num, char operation) {
    float unaryAns;
    switch (operation) {
                    case 'S': unaryAns = sqrtf(num); break;
                    case 'L':
                        if (num <= 0) {
                            printf("Error: Logarithm of a non-positive number\n");
                        }
                        unaryAns = logf(num);
                        break;
                    case 'E': unaryAns = expf(num); break;
                    case 'C': unaryAns = ceilf(num); break;
                    case 'F': unaryAns = floorf(num); break;
                    default: break;
                }
                printf("The result is %.2f\n", unaryAns);
}

void exitProgram() {
    printf("Thanks for using the calculator. Goodbye!\n");
}

char validateCharInput(char validOptions[], int size) {
    char option;
    bool isValid = false;

    while (!isValid) {
        scanf(" %c", &option);
        for (int i = 0; i < size; ++i) {
            if (option == validOptions[i]) {
                isValid = true;
                break;
            }
        }
        if (!isValid) {
            printf("Invalid option. Please enter a valid option: ");
        }
    }
    return option;
}

float validateFloatInput() {
    float num;
    bool isValid = false;

    while (!isValid) {
        if (scanf("%f", &num) == 1) {
            isValid = true;
        } else {
            printf("Invalid input. Please enter a valid floating point number: ");
            while (getchar() != '\n');
        }
    }
    return num;
}

int main() {
    char option = ' ';
    char operation = ' ';
    float memory[5] = {0.0};

    printf("Welcome to my Command-Line Calculator (CLC)\n");

    while (option != 'E') {
        option = displayOptions();

        switch (option) {
            case 'B':
                printf("Please enter the first number: ");
                float num1 = validateFloatInput();
                printf("Please enter the operation (+, -, *, /, %%, P, X, I): ");
                operation = validateCharInput("+-*/%PXI", 8);
                printf("Please enter the second number: ");
                float num2 = validateFloatInput();
                performBinaryOperation(num1, num2, operation);
            break;

            case 'U':
                printf("Please enter the operation (S, L, E, C, F): ");
                operation = validateCharInput("SLECF", 5);
                printf("Please enter a number: ");
                float num = validateFloatInput();
                performUnaryOperation(num, operation);
            break;

            case 'A':
                printf("Please enter the operation (B, U, E): ");
                operation = validateCharInput("BUE", 3);

                switch (operation) {
                    case 'B':
                        printf("Please enter the operation (+, -, *, /, %%, P, X, I): ");
                        char binOperation = validateCharInput("+-*/%PXI", 8);

                        printf("Please enter the first number or variable (a/b/c/d/e): ");
                        float numB1;
                        char inputB1 = validateCharInput("abcde", 5);
                        if (inputB1 >= 'a' && inputB1 <= 'e') {
                            numB1 = memory[inputB1 - 'a'];
                        } else {
                            printf("Enter a number: ");
                            if (scanf("%f", &numB1) != 1) {
                                printf("Invalid input. Please enter a valid number.\n");
                                while (getchar() != '\n');
                                continue;
                            }
                        }

                        printf("Please enter the second number or variable (a/b/c/d/e): ");
                        float numB2;
                        char inputB2 = validateCharInput("abcde", 5);
                        if (inputB2 >= 'a' && inputB2 <= 'e') {
                            numB2 = memory[inputB2 - 'a'];
                        } else {
                            printf("Enter a number: ");
                            if (scanf("%f", &numB2) != 1) {
                                printf("Invalid input. Please enter a valid number.\n");
                                while (getchar() != '\n');
                                continue;
                            }
                        }

                        float binAns;
                        switch (binOperation) {
                            case '+': binAns = numB1 + numB2; break;
                            case '-': binAns = numB1 - numB2; break;
                            case '*': binAns = numB1 * numB2; break;
                            case '/':
                                if (numB2 == 0) {
                                    printf("Division by zero is not allowed.\n");
                                    continue;
                                }
                                binAns = numB1 / numB2;
                                break;
                            case '%': binAns = fmodf(numB1, numB2); break;
                            case 'P': binAns = powf(numB1, numB2); break;
                            case 'X': binAns = fmaxf(numB1, numB2); break;
                            case 'I': binAns = fminf(numB1, numB2); break;
                            default: break;
                        }
                        printf("The result is %.2f\n", binAns);
                        break;

                    case 'U':
                        printf("Please enter the operation (S, L, E, C, F): ");
                        char unaryOperation = validateCharInput("SLECF", 5);
                        printf("Please enter the variable (a/b/c/d/e): ");
                        char varU = validateCharInput("abcde", 5);
                        float numU = memory[varU - 'a'];

                        float unaryAns;
                        switch (unaryOperation) {
                            case 'S': unaryAns = sqrtf(numU); break;
                            case 'L':
                                if (numU <= 0) {
                                    printf("Error: Logarithm of a non-positive number\n");
                                    continue;
                                }
                                unaryAns = logf(numU);
                                break;
                            case 'E': unaryAns = expf(numU); break;
                            case 'C': unaryAns = ceilf(numU); break;
                            case 'F': unaryAns = floorf(numU); break;
                            default: break;
                        }
                        printf("The result is %.2f\n", unaryAns);
                        break;

                    case 'E':
                        printf("Exiting Advanced Operations. Returning to main menu.\n");
                        break;

                    default:
                        printf("Invalid option. Please select a valid option.\n");
                        break;
                }
                break;
                    
                

            case 'V':
                printf("Please enter the variable (a/b/c/d/e): ");
                char var = validateCharInput("abcde", 5);
                printf("Please enter the value for variable %c: ", var);
                float value = validateFloatInput();

                switch (var) {
                    case 'a': memory[0] = value; break;
                    case 'b': memory[1] = value; break;
                    case 'c': memory[2] = value; break;
                    case 'd': memory[3] = value; break;
                    case 'e': memory[4] = value; break;
                    default: break;
                }
                printf("Value %.2f assigned to variable %c\n", value, var);
                break;

            case 'E':
                exitProgram();
                break;

            default:
                printf("Invalid option. Please select a valid option.\n");
                break;
        }
    }
    return 0;
}