/*
* File: dish.cpp
* Author: Minh Phat
* Date: 21/04/2024
* Description: This file contains all the functions/methods of class Dish
*/
 
#include "dish.h"

/*
* Class: Dish
* Function: setID
* Description: This function is used for setting ID of dish
* Input:   _ID (ID of dish)
* Output:  return: None
*/
void Dish::setID (int _ID) {
    ID = _ID;
}
/*
* Class: Dish
* Function: getID
* Description: This function is used for getting ID of dish
* Input:   None
* Output:  return: ID (ID of dish)
*/
int Dish::getID() {
    return ID;
}
/*
* Class: Dish
* Function: setName
* Description: This function is used for setting name of dish
* Input:   _name (name of dish)
* Output:  return: None
*/
void Dish::setName(string _name) {
    name = _name;
}
/*
* Class: Dish
* Function: getName
* Description: This function is used for getting name of dish
* Input:   None
* Output:  return: name (name of dish)
*/
string Dish::getName(){
    return name;
}
/*
* Class: Dish
* Function: setPrice
* Description: This function is used for setting price of dish
* Input:   _price (price of dish)
* Output:  return: None
*/
void Dish::setPrice(int _price) {
    price = _price;
}
/*
* Class: Dish
* Function: getPrice
* Description: This function is used for getting price of dish
* Input:   None
*/
int Dish::getPrice(){
    return price;
}



