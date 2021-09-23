#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// typedef struct node node_t;

// struct node {
//     char *tekst;
//     node_t *next;
// };

#define max_input_length = 100;

struct phone_book {
    char *name;
    int *number;
    phone_book_t *next;
};

phone_book_t *add_contact(char *input, phone_book_t *start) {
    phone_book_t *new_contact = malloc(sizeof(phone_book_t));
    printf("Enter your name:\n");
    fgets(phone_book_t, max_input_length, stdin);

}


int main() {

    phone_book_t = *first;


    // node_t *first;
    // first = malloc(sizeof(node_t));

    // first->next = NULL;
    
    // for (int i = 0; i < 1000; i++) {
    //     node_t *cur_elem = malloc(sizeof(node_t));
    //     cur_elem-> next = first;
    //     first = cur_elem;
    // }

    // node_t *current = first;
    // while (current != 0) {
    //     printf("I'm a on a node\n");
    //     current = current->next;
    // }
}