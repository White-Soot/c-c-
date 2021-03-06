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



    if(head!=NULL){
       struct Node *p_node= head;

       head = head->next;

       free(p_node);
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






int main()
{
    int ile,i,var;

    char command[16];

   scanf("%u ", &ile);
   for(i= 0; i< ile;i++){
       scanf("%s %u", &command, &var);

       if(strcmp(&command,"insert")==0){
           append(var);
       }else if(strcmp(&command,"delete_head")==0){
           delete_head();
       }else if(strcmp(&command,"delete_tail")==0){
         delete_tail();
       }else if(strcmp(&command,"print")==0){
            show();
       }else if(strcmp(&command,"count")==0){
            count();
       }else if(strcmp(&command,"insert_head")==0){
            add_new_head(var);
       }
       }

    return 0;
}
