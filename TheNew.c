#include <stdio.h>

int ten_to_the_power_of (int x) {
    int new_number = 1;
    for (int i = 1; i <= x; i++) {
        new_number = new_number * 10;
    }
    return new_number;
}

int main() {

    int number = -14913;
    int counter;
    int how_many_numbers;

    for (int i = 0; i < 9; i++) { 
        if (number > 0) {
            if (number <= ten_to_the_power_of(i)) {
                printf("There is %i numbers in that number\n", counter);
                i = 9;
            } else {
                printf("%i is less than %i\n", number, ten_to_the_power_of(i));
                counter++;
            }
        } else {
            printf("I times %i with -1\n", number);
            number *= -1;
        }
    }
}

