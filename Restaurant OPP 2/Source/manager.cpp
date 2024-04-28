/*
* File: manager.cpp
* Author: Minh Phat
* Date: 21/04/2024
* Description: This file contains all the functions/methods of class Manager
*/
#include "manager.h"
/*
* Class: Manager
* Function: getMenu
* Description: Returns the menu list.
* Input: None
* Output: Returns a list of Dish objects representing the menu.
*/
list <Dish> Manager::getMenu() {
    return menu;
}
/*
* Class: Manager
* Function: setNumTable
* Description: Sets the number of tables.
* Input: _numTable - an integer representing the number of tables.
* Output: None
*/
void Manager::setNumTable (int _numTable) {
    numTable = _numTable;
}
/*
* Class: Manager
* Function: addDish
* Description: Adds a new dish to the menu.
* Input: None
* Output: None
*/
void Manager::addDish() {
    Dish newDish;

    cout << "Enter name of dish you want: ";
    string _name;
    cin.ignore(); 
    getline(cin,_name);
    
    newDish.setName(_name);

    cout << "Enter price of dish you want: ";
    int _price; cin >> _price;
    cin.ignore();
    newDish.setPrice(_price);

    menu.push_back(newDish);
} 
/*
* Class: Manager
* Function: showMenu
* Description: Displays the list of ordered dishes.
* Input: None
* Output: None
*/
void Manager::showMenu(){
     int count = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tList of your ordered dishes" << endl << endl;
    cout << "No" << "\t\tID" << "\t\tName" << "\t\tPrice" << endl;
    for (auto i : menu) {
        count++;
        cout << count << "\t\t" << i.getID() << "\t\t" << i.getName() << "\t\t" << i.getPrice() << endl;
    }
}

/*
* Class: Manager
* Function: editDish
* Description: Modifies the price of a dish with the specified ID.
* Input: ID_input - an integer representing the ID of the dish to be edited.
* Output: None
*/
void Manager::editDish(int ID_input) {
    for (auto &i : menu) {
        if (i.getID() == ID_input) {
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\tData is founded " << endl << endl;
            cout << "ID" << "\t\t\tName" << "\t\t\tPrice" << endl;
            cout << i.getID() << "\t\t\t" << i.getName() << "\t\t\t" << i.getPrice();
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

            cout << "\n\t\t\tPlease re-enter Price of dish you want to change: ";
            int _price; cin >> _price; 
            i.setPrice(_price);
            return;
        }
    }
} 
/*
* Class: Manager
* Function: deleteDish
* Description: Deletes a dish with the specified ID from the menu.
* Input: ID_input - an integer representing the ID of the dish to be deleted.
* Output: None
*/
void Manager::deleteDish(int ID_input) {
    list<Dish>::iterator it;
    for (it = menu.begin(); it != menu.end(); ++it) {
        if (it->getID() == ID_input) {
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\tData is founded " << endl << endl;
            cout << "ID" << "\t\t\tName" << "\t\t\tPrice" << endl;
            cout << it->getID() << "\t\t\t" << it->getName() << "\t\t\t" << it->getPrice();
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

            cout << "\n\t\t\tAre you sure you want to delete this item?" << endl;
            int ans = 0;
            do {
                cout << "\t\t\t1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "\t\t\tPlease Enter Your Choice: " << endl;
                cin >> ans;
                if (ans == 2) return;
            } while (ans != 1);
            
            menu.erase(it);
            return;
        }
    }
}