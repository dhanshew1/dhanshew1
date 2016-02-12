/** Daryan Hanshew
    TCES202
    Winter 2015
     */
// linkedlist.c

#include "global.h"
#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>



void pushP(struct nodeP *head,Prod p)
{
    struct nodeP *new_node = (struct nodeP*)malloc(sizeof(struct nodeP));
    new_node->p = p;
    np temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = NULL;
}

void printP(np head)
{
    while(head!= NULL)
    {
        printf("%s\t%s\t%d\t%f\n",head->p->ID,head->p->name,head->p->num_unit,head->p->price);
        head  = head->next;
    }

}

void pushT(struct nodeT *head, Trans t)
{
    struct nodeT *new_node = (struct nodeT*)malloc(sizeof(struct nodeT));
    new_node->t = t;
    nt temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->next = NULL;
}


void printT(nt head)
{

    if(head == NULL)
    {
        printf("No transcation as of now\n");
    }
    while(head!= NULL)
    {
        printf("%s\t%s\t%s\t%f\t%s\n",head->t->f_name,head->t->l_name,head->t->address,head->t->pay,head->t->p->ID);
        head  = head->next;
    }

}
