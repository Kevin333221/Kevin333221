#include <stdio.h>
#include <string.h>

void cipher(char *s, int x) {
    int len = 0;
    while (s[len] != 0) {
        s[len] += x;
        len++;
    }

}

int main() {
    char my_string[] = "Hello World";
    printf("%s\n", my_string);
    cipher(my_string, 3);
    printf("%s\n", my_string);
    cipher(my_string, -3);
    printf("%s\n", my_string);
}
    
