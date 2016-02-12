/** Daryan Hanshew
    TCES202
    Winter 2015*/
#include "global.h"
#include "linkedlist.h"

#ifndef owner_h
#define owner_h

int owner_menu(np headP, nt headT);
void dispProd_o(np head);
void addProd(np head);
void delProd(np * head);
void editProd(np head);
void viewTrans(nt head);
void deleteRecentTrans(nt * head);
void viewAllTrans(nt head);
void deleteAllTrans(nt head);
void exitOwner();


#endif

