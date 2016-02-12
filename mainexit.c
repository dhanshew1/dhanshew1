/** Daryan Hanshew
    TCES202
    Winter 2015
     */
#include "global.h"
#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include "owner.h"
#include <string.h>
#include "mainexit.h"



void saveProdlist(np head)
{
    char file[] = "/Users/Daryan/Desktop/product.txt";
    FILE *fp;
    fp = fopen(file,"w");
    if(fp==NULL){
        printf("Error!");
        exit(1);
    }

    printf("File opened : Updating....\n");

    while(head != NULL)
    {
        //char str[];
        fprintf(fp, "%s\t%s\t%d\t%f\n",head->p->ID,head->p->name,head->p->num_unit,head->p->price);
        head = head->next;
    }

    printf("Product file updated\n");

    fclose(fp);
}
