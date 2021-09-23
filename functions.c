#include <stdio.h>
#include <math.h>

// Just wanted to color the text to make it fun
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int is_active = 0;

void compare_values(int x, int y) {
    // Checking if x is bigger than y
    if (x > y) {
        printf("%i is the largest\n\n", x);
    } else {
        printf("%i is the largest\n\n", y);
    }
}

void myTriangles(int numlines) {
    int num_stars = 1;
    
    // For each line of stars, I add another star to it by nesting the loops
    for (int i = 0; i < numlines; i++){
        for (int j = 0; j < num_stars; j++){
            printf("*");
        }
        num_stars++;
        printf("\n");
    }
}

int myPrimeFactor(int number, int primeFactor) {
    // Check if the remainder of the number given is 0, if it is, then it is divisble
    if ((number % primeFactor) == 0) {
        return 1;
    } else {
        return 0;
    }  
}

void myNumbers(int startnum, int endnum) {

    for (int i = startnum; i < endnum; i++) {
        // Check if the number is divisble by 2
        if ((i % 2) == 0) {
            printf("%i is even and ", i);
        } else {
            printf("%i is odd and ", i);
        }

        // Check if the number is divisble by 5
        if ((i % 5) == 0) {
            printf("5 is a prime factor\n");
        } else {
            printf("5 is not a prime factor\n");
        }
    }
}

int myLog2(unsigned int n) {
    for (int i = 0; i < n; i++) {
        // Checking to see if any new bit is less than the given number
        if (pow(2,i) <= n) {
            // This does nothing execept increasing the counter "i"
        } else {
            // When the bit is larger than the given number, then i know i went to far, so i subtract one "bit" by it to get to the most significant bit
            i--;
            printf("%i is the most significant bit\n", i);
            // This is to stop the counter
            i = n;
        }
    }
}

int get_string_length(char string[]) {
    int c = 0;

    // Counting the string length until i stumble upon an empty spot in the array
    while (string[c] != '\0')
        c++;
    return c;
}

void reverseString(char string[]) {

    int count, end, begining;

    // Just made a separate function to find out the length of the given string
    count = get_string_length(string);
    
    // I set the size to be 100 just to make sure it's enough
    char rev_string[1000];
    
    // Taking one off the length (since even tho there is for example 5 elements in the array, the last position of the last element is in position 4)
    end = count - 1;

    // Assigning the first element from the original string to the last position of the new reversed string
    for (begining = 0; begining < count; begining++) {
        rev_string[begining] = string[end];
        end--;
    }

    // I saw an example online on how to reverse a string without strrev and i don't fully understand why i need this line of code 
    // but without it i notice there is a spot at the end of the reversed string that have a non element in it
    // so i figured, the last spot needs to be removed, but im not quite sure why and how
    rev_string[begining] = '\0';

    printf("%s is the original string\n", string);
    printf("%s is the reversed string\n", rev_string);
}

void menu() {
    while (is_active != 1) {
        char first_string[0];
        int firstnum, secondnum, answer, input;

        printf(RED "\nHello User\n" RESET);
        printf(GRN "What program do you wanna use?\n" RESET);
        printf(YEL "1: Compare Values\n" RESET);
        printf(BLU "2: Make a triangle\n" RESET);
        printf(MAG "3: Find the primefactor to a chosen number\n" RESET);
        printf(CYN "4: Find out if the number is even or odd between a chosen range and it's divisble by 5\n" RESET);
        printf(WHT "5: Find the most significat bit in binary to a base 10 number\n" RESET);
        printf(RED "6: Reverse a string\n" RESET);
        printf(WHT "7: End Program\n" RESET);

        scanf("%d", &input);

        // I searched on the internet that if i use the "getchar();" after a scanf(), it will clear out the extra (\n) that gets stored in the next scanf() later on in the switch
        // If i don't have it, then if the user types a non interger value, then the program will store the (\n) in the next iteration of the while loop
        // So it will loop indefinitely without the "getchar();" spamming the terminal
        getchar();

        // Compare the input from the user to the different cases
        switch (input) {
            case 1:
                printf("What two numbers do you wanna compare?\n");

                printf("Enter the first number:\n");
                scanf("%d", &firstnum);

                printf("Enter the second number:\n");
                scanf("%d", &secondnum);

                compare_values(firstnum, secondnum);
            break;

            case 2:
                printf("How many lines would you like to have on your triangle?\n");
                scanf("%d", &firstnum);
                myTriangles(firstnum);
            break;S

            case 3:
                printf("Enter the first number:\n");
                scanf("%d", &firstnum);

                printf("Enter the number you wanna check if that is divisible to the first number:\n");
                scanf("%d", &secondnum);

                answer = myPrimeFactor(firstnum, secondnum);
                if (answer == 1) {
                    printf("Is True\n\n");
                } else {
                    printf("Is False\n\n");
                }
            break;

            case 4:
                printf("Enter the smallest boundary:\n");
                scanf("%d", &firstnum);

                printf("Enter the highest boundary:\n");
                scanf("%d", &secondnum);

                myNumbers(firstnum, secondnum);
            break;

            case 5:
                printf("Enter the first number you wanna find the most significant bit to:\n");
                scanf("%d", &firstnum);

                myLog2(firstnum);
            break;

            case 6:
                printf("Enter a string you wanna reverse:\n");
                scanf("%s", first_string);

                reverseString(first_string);
            break;

            case 7:
                printf("Goodbye!\n");
                
                // Breaking the while loop
                is_active = 1;
            break;

            // If the input doesn't match any of the cases, e.g., 
            default:
                printf("Invalid Command\n\n");
            break;
        }
    }
}

int main() {
    menu();
}
