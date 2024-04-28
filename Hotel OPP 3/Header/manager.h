/*
* File: manager.h
* Author: Minh Phat
* Date: 22/04/2024
* Description: This file is a Manager header file which helps hotel system work
*/

#ifndef _MANAGER_H
#define _MANAGER_H

#include "employee.h"
#include "room.h"
#include "service.h"

typedef enum {
    Employee_function,
    Room_function,
    Service_function,
    Back_menu
} Function;

/*
* Struct: Database
* Description: This struct is used for containing data of hotel
    employee: data of employees
    room: data of rooms
    service: data of services
*/
typedef struct {
    ManageEmployee employee;
    ManageRoom room;
    ManageService service;
} Database;

/*
*Class: Manager
*Description: This class contains basic properties and methods that help manager manages hotel system
*/
class Manager {
private:
    int account;
    int password;

public:
    Manager() {
        this->account = 1;
        this->password = 1;
    }

    int getAccount();
    int getPassword();

    void menuManager(Database& database);
};

#endif
