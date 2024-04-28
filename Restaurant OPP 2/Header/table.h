/*
* File: table.h
* Author: Minh Phat
* Date: 21/04/2024
* Description: This file is a table header file that program is used for storing table's information
*/

#ifndef _TABLE_H
#define _TABLE_H

#include "dish.h"
#include <list>

typedef enum {
    Booked,
    Free
} Status;


class Table {
private:
    int tableID;
    Status status;
    list <Order> orderList;
    int totalBill;

public:
    Table() {
        static int _tableID = 1;
        this->tableID = _tableID;
        _tableID++;

        status = Free;
        this->totalBill = 0;
    }
    void resetTable ();
    int getTableID();
    void setStatus(Status _status); 
    Status getStatus();  
    void orderDish(list <Dish> menu);
    void getOrderList(int ID_input);
    void changeNum(int ID_input);
    void getBill(int ID_input);
};

#endif