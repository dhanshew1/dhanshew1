/** Daryan Hanshew
    TCES202
    Winter 2015
    Project Programing */
// customer.h

// #include <global.h>
//Include in the End

#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "linkedlist.h"
#include "owner.h"
#include "mainexit.h"
#include <string.h>


int main()
{


  // Product.txt reading

    //Prod p;
    np root = (np)malloc(sizeof(struct nodeP));
    root->next = NULL;


    char file[] = "/Users/Daryan/Desktop/product.txt";
    FILE *fp;
    fp = fopen(file,"r");
    char c;

    //char oneword3[100];
    //char oneword4[100];
    if( fp == NULL )
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while(c!=EOF)
    {
        struct Product *prod = (struct Product *)malloc(sizeof(struct Product));
        char *oneword1 = malloc(sizeof(char)*100);
        char *oneword2 = malloc(sizeof(char)*100);
        char *oneword3 = malloc(sizeof(char)*100);
        char *oneword4 = malloc(sizeof(char)*100);

        //   struct Product * prod = malloc(sizeof(struct Product));
        c = fscanf(fp,"%s",oneword1);
        prod->ID = oneword1;
        c = fscanf(fp,"%s",oneword2);
        prod->name = oneword2;
        c = fscanf(fp,"%s",oneword3);
        prod->num_unit = atoi(oneword3);
        c = fscanf(fp,"%s",oneword4);
        prod->price = atof(oneword4);

       if( prod->num_unit != 0|| prod->price != 0.0)
           {
        if(i==0)
        {
            root->p = prod;
            root->next = NULL;
        }
        else
            pushP(root,prod);

       // printf("%s,%s,%d,%f\n",prod->ID,prod->name,prod->num_unit,prod->price);
               }
        i++;

    }


    //printP(root);
mainlabel:
    printf("Welcome to Shopping System.\nPlease choose among these options :\n") ;
    printf("Press 1 -> Customer's Fucntions\n");
    printf("Press 2 -> Owner's Fucntions\n");
    printf("Press 3 -> Exit\n");

    int main_in;

    scanf("%d",&main_in);

    nt rootT = (nt)malloc(sizeof(struct nodeT));
    rootT = NULL;

    int flag;
    switch (main_in)
    {
        case 1:
        {
            printf("Customer function not ready yet\n");
        }

        case 2:
        {
            flag = owner_menu(root,rootT);
            printf("%d",flag);
            if(flag == 9 ) goto mainlabel;
            break;
        }
        case 3:
        {
            saveProdlist(root);
            break;
        }
    }


    return 0;
}
