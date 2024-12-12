#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int evaluateExpression();
int evaluateTerm();
int evaluateFactor();
int getNumber();


int currentChar;

void getNextChar() {
    currentChar = getchar();
    while (currentChar == ' '){
        currentChar = getchar();
    }
}

// Main function
int evaluateExpression(){
    int result = evaluateTerm();

    while (currentChar == '+' || currentChar == '-'){
        char operator = currentChar;
        getNextChar();
        int term = evaluateTerm();

        if (operator == '+'){
            result += term;
        } else {
            result -= term;
        }
    }

    return result;
}

int evaluateTerm(){
    int result = evaluateFactor();

    while (currentChar == '*' || currentChar == '/' || currentChar == '%'){
        char operator = currentChar;
        getNextChar();
        int factor = evaluateFactor();

        if (operator == '*'){
            result *= factor;
        } else if (operator == '/'){
            if (factor == 0){
                printf("Error: Division by zero\n");
                exit(1);
            }
            result /= factor;
        } else if (operator == '%'){
            if (factor == 0){
                printf("Error: Division by zero\n");
                exit(1);
            }
            result %= factor;
        }
    }

    return result;
}

int evaluateFactor(){
    if (currentChar == '('){
        getNextChar();
        int result = evaluateExpression();
        if (currentChar == ')'){
            getNextChar();
        } else{
            printf("Error: Missing closing parenthesis\n");
            exit(1);
        }
        return result;
    } else{
        return getNumber();
    }
}

// For multi digit num
int getNumber(){
    int result = 0;

    while (isdigit(currentChar)){
        result = result * 10 + (currentChar - '0');
        getNextChar();
    }

    return result;
}

int main(){
    printf("Enter expressions in infix format (3 + 4 * (2 - 1)).\n");

    while (1){
        printf("Enter expression: ");
        getNextChar();

        if (currentChar == EOF){
            break;
        }

        int result = evaluateExpression();

        while (currentChar == ' '){
            getNextChar();
        }

        if (currentChar != '\n' && currentChar != EOF){
            printf("Error: Invalid character in expression\n");
            exit(1);
        }

        printf("Result: %d\n", result);
    }

    printf("End of input detected. Exiting the program.\n");
    return 0;
}