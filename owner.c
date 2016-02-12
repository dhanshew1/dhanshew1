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

char * usr_name = "owner";
char* password = "owner";

int owner_menu(np headP, nt headT)
{
    char user[10];
    char pass[10];
    char charIN = 'y';
    int call_func;

    printf("Please insert the username :\n");
    scanf("%s",user);
    printf("Please insert the Password :\n");
    scanf("%s",pass);

    int ret1 = strcmp(user, usr_name);
    int ret2 = strcmp(pass, password);

    if(ret1 == 0 && ret2 == 0)
    {
       do
        {
            printf("*************** Owner's Page ***************\n");
            printf("1 . Display Products\n");
            printf("2 . Add new Products\n");
            printf("3 . Delete Products\n");
            printf("4 . Edit Products\n");
            printf("5 . View recent Transcations\n");
            printf("6 . Delete recent Transcations\n");
            printf("7 . View All Transcations\n");
            printf("8 . Delete All Transcations\n");
            printf("9 . Exit Owner Function\n");


            scanf("%d",&call_func);
            switch(call_func)
            {
                case 1:
                {
                    dispProd_o(headP);
                    //return 1;
                    break;
                }
                case 2:
                {
                    addProd(headP);
                    //return 2;
                    break;
                }

                case 3:
                {
                    delProd(&headP);
                    //return 3;
                    break;
                }
                case 4:
                {
                    editProd(headP);
                   // return 4;
                    break;
                }
                case 5:
                {
                    viewTrans(headT);
                    //return 5;
                    break;
                }
                case 6:
                {
                    deleteRecentTrans(&headT);
                    //return 6;
                    break;
                }

                case 7:
                {
                    printf("No Trnascation File found\n");
                    //viewAllTrans(headT);
                    //return 7;
                    break;
                }
                case 8:
                {
                    printf("No Trnascation File found\n");
                    //deleteAllTrans(headT);
                    //return 8;
                    break;
                }
                case 9:
                {
                    printf("Exit Done\n");
                    return 9;
                    break;
                }
                default:
                {
                    printf("\nWrong Input\n");
                    return 9;
                }

            }

            printf("Do you want to continue : (Y/N) : ");
            scanf(" %c",&charIN);
            printf("charIN taken\n");
        } while(charIN == 'Y' || charIN == 'y');


    }
    else
    {
        printf("\nWrong Username or Password\n");
        return -1;
    }

    return 9;
}



void dispProd_o(np head)
{
    printP(head);
}



void addProd(np head)
{
    char *prod_id = malloc(sizeof(char)*100);
    char *prod_name = malloc(sizeof(char)*100);
    int num_prod;
    float num_price;

    struct Product *p = (struct Product *)malloc(sizeof(struct Product));
    printf("Insert prod ID :\n");
    scanf("%s",prod_id);
    p->ID = prod_id;
    printf("Insert prod name :\n");
    scanf("%s",prod_name);
    p->name = prod_name;
    printf("Insert prod units :\n");
    scanf("%d",&num_prod);
    p->num_unit = num_prod;
    printf("Insert prod Price :\n");
    scanf("%f",&num_price);
    p->price = num_price;

    pushP(head,p);

    printP(head);
}



void delProd(np * head)
{
    char prod_id[20];
    printf("Insert prod ID of to be deleted prod :\n");
    scanf("%s",prod_id);

    np headOrig = *head;
    np temp = *head;
    int r;

    r = strcmp((*head)->p->ID,prod_id);
    if(r!=0)
    {
        int flag = 0;
        while((*head) != NULL)
        {
            r = strcmp((*head)->p->ID,prod_id);
            if(r == 0)
            {
                flag =1;
                break;
            }
            temp = (*head);
            (*head)= (*head)->next;
        }

        /*np temp_next = head->next;*/


        if(flag==0)
        {
            printf("\nNo such Prod ID is found\n");
        }
        else
        {
            temp->next = (*head)->next;
            (*head) = headOrig;
            printf("Prod deletion successful\n");
        }

        printP(*head);
    }
    else
    {
        (*head) = headOrig->next;
        printP(*head);
    }
}




void editProd(np head)
{
    char prod_id[20];
    printf("Insert prod ID of to be deleted prod :\n");
    scanf("%s",prod_id);

    np headOrig = head;
    int flag = 0;
    int num_prod;
    float num_price;
    int r;
    while(head != NULL)
    {
        r = strcmp(head->p->ID,prod_id);
        if(r == 0)
        {
            flag =1;
            break;
        }
        head= head->next;
    }

    if(flag == 0)
        printf("\nNo such Prod ID is found\n");
    else
    {
        printf("Insert prod units :\n");
        scanf("%d",&num_prod);
        head->p->num_unit = num_prod;
        printf("Insert prod Price :\n");
        scanf("%f",&num_price);
        head->p->price = num_price;
        printf("Prod successfully Updated\n");
        printP(headOrig);
    }


}

void viewTrans(nt head)
{
    printT(head);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void deleteRecentTrans(nt * head)
{
    *head = NULL;
    (*head)->next = NULL;
    printf("All recent transcations deleted successfully\n");
}

////////////////////////////////////////////////////////////////////////////////////////////
