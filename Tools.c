#include <stdio.h>

int get_string_length(char *string) {
    int len = 0;
    while (string[len] != 0) {
        len++;
    }
    return len;
}

void remove_numbers_from_string(char *string) {
    // Removing the Numbers
    for (int i = 0; i <= get_string_length(string); i++) {
        for (int j = 48; j <= 57; j++) {
            if (string[i] == j) {
                string[i] = 32;
            }
        }
    }

    // Tightening the spaces pt.2  
    int counter = 0;
    int first = 0;
    for (int i = 0; i <= get_string_length(string); i++) {
        if ((string[i] == 32) && first == 0) {
            counter = i + 1;
            first = 1;
        }
        if (string[counter] == 32) {
            while (string[counter] == 32) {
                counter++;
            }
            string[i] = string[counter];
            counter++;
        } else {
            string[i] = string[counter];
            counter++;
        }
    }

    // Tightening the spaces
    // int len = 0;
    // for (int i = 0; i <= get_string_length(string); i++) {
    //     while (string[i] == 32) {
    //         if (string[i + len] == 32) {
    //             len++;
    //         } else {
    //             string[i] = string[i + len];
    //             string[i + len] = 32;
    //         }
    //     }
    // }
}

void remove_a_letter_from_a_string(char *string, char A) {
    for (int i = 0; i <= get_string_length(string); i++) {
        if (string[i] == A) {
            string[i] = 32;
        }
    }
}

int main () {

    // Find the strings length
    int len_off_string = get_string_length("Hello World");
    printf("%i\n", len_off_string);

    // Remove numbers from string
    char example_string[] = "H1el23l4o9";
    remove_numbers_from_string(example_string);
    printf("%s\n", example_string);

    // Remove a chosen letter from a string
    char string_with_letters[] = "Hallo Pappa";
    remove_a_letter_from_a_string(string_with_letters,'a');
    printf("%s\n", string_with_letters);


}