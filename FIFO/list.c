#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
#define DPF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
#define DPF(format, ...)
#endif


/*
    model wezla
*/
struct Node{

  int value;
  struct Node *next;  // wskaznik na nastepnik w liscie

};

struct Node *head = NULL; // wskaznik na heda


/*
    dodawanie kolejnego elementu listy
*/
void append(int val){

    if(head == NULL){

        head = malloc(sizeof (struct Node));
        head->value = val;
        head->next  = NULL;

        return;
    }

    struct Node **p_node = &(head->next);

    while(*p_node != NULL){

        p_node = &((*p_node)->next);


    }
    (*p_node) = malloc(sizeof (struct Node));
    (*p_node)->value = val;
    (*p_node)->next = NULL;
}


 void add_new_head (int val){

        if(head == NULL){

        head = malloc(sizeof (struct Node));
        head->value = val;
        head->next  = NULL;

        return;
        }
    struct Node *p_node = malloc(sizeof (struct Node));

       p_node->value = val;
       p_node->next = head;
       head = p_node;

    return;
    }

void delete_head(void){

    struct Node *p_node = malloc(sizeof (struct Node));

    if(head!=NULL){


       p_node->value= (head->next)->value;
       p_node->next = (head->next)->next;
       head = p_node;
        return;
    }else{
        printf("0 \n");
    }

}

void delete_tail(){

    struct Node *p_node = head;

    if(p_node !=NULL){

    if(p_node->next != NULL){

        while(p_node->next->next != NULL){

            p_node= p_node->next;

        }
        free(p_node->next);
        p_node->next=NULL;
    }else{

        p_node = NULL;
        head = NULL;

        printf("0 \n");


    }

    }

}


/*
    wyswietlanie
*/

void show(void){

    struct Node *l_head = head;
     printf("List contains : \n");

    while(l_head != NULL){

        printf("Value = %d \n", l_head->value);
        l_head = l_head->next;

    }

}

/*
    zwalnianie pamieci
*/


void release(void){

    struct Node *l_head = head;
    struct Node *n_next;
    while(l_head != NULL){


        n_next = l_head->next;
        free(l_head);
        l_head = n_next;

    }
    head = NULL;
}

void count(void){

    int count = 0;

    struct Node *l_head = head;

    while(l_head != NULL){

        count++;
        l_head = l_head->next;

    }
    printf("Count : %d /n",count);
    return ;
}




