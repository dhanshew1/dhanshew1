/** Daryan Hanshew
    TCES202
    Winter 2015
     */
/*
 * global.h
 *
 *  Created on:
 *      Author:
 *
 */


#ifndef Global_LIST_H_INCLUDED
#define Global_LIST_H_INCLUDED

struct Product{
    char *ID;
    char *name;
    int num_unit;
    float price;
};

struct Transaction{
    char* f_name;
    char* l_name;
    char* address;
    float pay;
    int dd, mm, yy;
    struct Product * p;
};

typedef struct Product* Prod;
typedef struct Transaction* Trans;

#endif
