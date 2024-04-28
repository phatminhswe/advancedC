/*
* File: manager.h
* Author: Minh Phat
* Date: 21/04/2024
* Description: This file is a manager header file that program is used for set restaurant's information
*/

#ifndef _MANAGER_H
#define _MANAGER_H
#include "table.h"

using namespace std;


class Manager {
private:
    list <Dish> menu;
    int numTable;

public:
    Manager() {
        this->numTable = 0;
    }
    list <Dish> getMenu(); 
    void setNumTable (int _numTable);
    void addDish();
    void showMenu();
    void editDish(int ID_input);
    void deleteDish(int ID_input);
 
 
};

#endif
