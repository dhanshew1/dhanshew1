
/** Daryan Hanshew
    TCES202
    Winter 2015
     */
/*

 linkedlist.h

 */

#include "global.h"

#ifndef linkedlist_h
#define linkedlist_h



//extern struct Prod;
//extern struct Trans;
struct nodeP{
    Prod p;
    struct nodeP *next;
};

struct nodeT{
    Trans t;
    struct nodeT *next;
};


void pushP(struct nodeP *head, Prod p);
void printP(struct nodeP *head);
void pushT(struct nodeT *head, Trans t);
void printT(struct nodeT *head);

typedef struct nodeP *np;
typedef struct nodeT *nt;


#endif
