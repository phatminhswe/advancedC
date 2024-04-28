/*
* File: dish.h
* Author: Minh Phat
* Date: 21/04/2024
* Description: This file is a dish header file that program is used for storing dish's information
*/

#ifndef _DISH_H
#define _DISH_H

#include <iostream>
#include <string>

using namespace std;


class Dish {
private:
    int ID;
    string name;
    int price;

public:
    Dish() {
        static int _ID = 1;
        this->ID = _ID;
        _ID++;

        this->name = "";
        this->price= 0;
    }
    void setID(int _ID);
    int getID();

    void setName(string _name);
    string getName();

    void setPrice(int _price);
    int getPrice();

    
};

typedef struct {
    int num;
    Dish dish;
} Order;

#endif
