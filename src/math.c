#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 100
typedef char string[MAX_CHAR+1];

const char* oncelik = "";

char peek() { return *oncelik; }
char get() { return *oncelik++; }
int expression();

int number() {
    int result = get() - '0';
    while (peek() >= '0' && peek() <= '9')
    {
        result = 10 * result + get() - '0';
    }
    return result;
}

int factor() {
    if (peek() >= '0' && peek() <= '9')
        return number();
    else if (peek() == '(')
    {
        get(); // '('
        int result = expression();
        get(); // ')'
        return result;
    }
    else if (peek() == '-')
    {
        get();
        return -factor();
    }
    return 0;
}

int term() {
    int result = factor();
    while (peek() == '*' || peek() == '/')
        if (get() == '*')
            result *= factor();
        else
            result /= factor();
    return result;
}

int expression() {
    int result = term();
    while (peek() == '+' || peek() == '-')
        if (get() == '+')
            result += term();
        else
            result -= term();
    return result;
}

int main() {
    string denklem;
	printf("gir: ");
	scanf("%s", denklem);
	
    oncelik = &denklem[0];

	printf("sonuc: %d", expression());   
    return 0;
}
