/*
* File: staff.cpp
* Author: Minh Phat
* Date: 21/04/2024
* Description: This file contains all the functions/methods of class Staff
*/
 #include "staff.h"

/*
* Function: Staff::getNumTable
* Description: Initializes the tableList vector with a specified number of tables.
* Input: _numTable - an integer representing the number of tables to be added.
* Output: None
*/
void Staff::getNumTable(int _numTable) {
    for (int i = 0; i < (_numTable); i++) {
        Table newTable;
            tableList.push_back(newTable);  
    }
}

/*
* Function: Staff::displayTable
* Description: Displays the status of all tables (occupied or vacant).
* Input: None
* Output: None
*/
void Staff::displayTable() {
    cout << "Table ID" << "\t\t";
    int n = tableList.size();
    for (int i = 0; i < n; i++) {
        cout << i+1 << "\t";
    }

    cout << "\n Status " << "\t\t";
    for (auto it : tableList) {
        if (it.getStatus() == Free) cout << "O" << "\t";
        else cout << "X" << "\t";
    }

    cout << "\n\nX means booked";
    cout << "\nO means free";
}

/*
* Function: Staff::isFull
* Description: Checks if all tables are occupied.
* Input: None
* Output: Returns true if all tables are occupied, false otherwise.
*/
bool Staff::isFull() {
    for (auto it : tableList) {
        if (it.getStatus() == Free) return false;
    }
    return true;
}

/*
* Function: Staff::chooseTable
* Description: Marks a specified table as booked.
* Input: _tableID - an integer representing the ID of the table to be booked.
* Output: None
*/
void Staff::chooseTable(int _tableID) {
    for (auto &i : tableList) {
        if (i.getTableID() == _tableID) {
            i.setStatus(Booked);
        }
    }
}

/*
* Function: Staff::getDishInformationfromtheTable
* Description: Retrieves the list of ordered dishes for a specified table and displays it.
* Input: _tableID - an integer representing the ID of the table, menu - a list of Dish objects representing the menu.
* Output: None
*/
void Staff::getDishInformationfromtheTable (int _tableID,list <Dish> menu) {
    for (auto &it : tableList) {
        if (it.getTableID() == _tableID) {
            it.orderDish(menu);
            it.getOrderList(_tableID);
        }
    }
}

/*
* Function: Staff::cancelDishfromtheTable
* Description: Cancels a specified dish from the order of a table and updates the order list.
* Input: _tableID - an integer representing the ID of the table, ID_input - an integer representing the ID of the dish to cancel.
* Output: None
*/
void Staff::cancelDishfromtheTable(int _tableID,int ID_input) {
    for (auto &it : tableList) {
        if (it.getTableID() == _tableID) {
            it.changeNum(ID_input);
            it.getOrderList(_tableID);
        }
    }
}

/*
* Function: Staff::displayDishfromtheTable
* Description: Displays the list of ordered dishes for a specified table.
* Input: _tableID - an integer representing the ID of the table.
* Output: None
*/
void Staff::displayDishfromtheTable(int _tableID) {
    for (auto &it : tableList) {
        if (it.getTableID() == _tableID) {
            
            it.getOrderList(_tableID);
        }
    }
}

/*
* Function: Staff::payDishfromtheTable
* Description: Handles the payment process for the dishes ordered at a specified table.
* Input: _tableID - an integer representing the ID of the table.
* Output: None
*/
void Staff::payDishfromtheTable(int _tableID) {
    for (auto &it : tableList) {
        if (it.getTableID() == _tableID) {
            
            it.getBill(_tableID);
        }
    }
}