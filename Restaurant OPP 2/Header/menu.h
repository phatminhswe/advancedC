/*
* File: menu.h
* Author: Minh Phat
* Date: 21/04/2024
* Description: This file is a menu header file that program is used for display restaurent's information
*/
#ifndef _MENU_H
#define _MENU_H
#include "manager.h"
#include "staff.h"
using namespace std;
static int choice;

typedef enum {
    managerWork,
    staffWork
} Title;

typedef struct {
    int numTable;
    Manager managerData;
    Staff staffaData;
} Database;

void mainMenu (Database &database);
void menuStaff (Database &database);
void menuManager (Database &database);

#endif