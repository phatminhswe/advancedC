/*
* File: staff.h
* Author: Minh Phat
* Date: 21/04/2024
* Description: This file is a staff header file that program is used for get restaurant's information
*/

#ifndef _STAFF_H
#define _STAFF_H
#include <vector>
#include "table.h"
using namespace std;

/*
* Class: Staff
* Description: Represents the staff responsible for managing tables and orders.
*/
class Staff {
    private:
    vector <Table> tableList;
    public:
        Staff() {}

        void getNumTable(int _numTable);

        void displayTable(); 
        bool isFull (); 

        void chooseTable (int _tableID); 
        void getDishInformationfromtheTable(int _tableID, list <Dish> menu);
        void cancelDishfromtheTable(int _tableID,int ID_input);
        void displayDishfromtheTable(int _tableID);
        void payDishfromtheTable(int _tableID);
};

#endif