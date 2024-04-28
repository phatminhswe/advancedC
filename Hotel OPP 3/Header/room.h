/*
* File: room.h
* Author: Minh Phat
* Date: 22/04/2024
* Description: This file is a Room header file which manages rooms of hotel
*/

#ifndef _ROOM_H
#define _ROOM_H

#include "service.h"
#include <sstream>
#include < cmath >

using namespace std;

typedef struct {
    string Time;
    string Date;
} CheckTime;

typedef struct {
    Service typeService;
    int numService;
} Order;

/*
*Class: Customer
*Description: This class contains basic properties and methods of a Customer object
*/
class Customer {
private:
    string nameCustomer;
    int phoneCustomer;
    CheckTime checkIn;
    CheckTime checkOut;
    string feedback;
    list<Order> orderService;
    int totalBill;

public:
    Customer() {}

    void setNameCustomer(string _name);
    string getNameCustomer();

    void setPhoneCustomer(int _phone);
    int getPhoneCustomer();

    void setCheckIn(CheckTime _checkIn);
    void setCheckOut(CheckTime _checkOut);

    CheckTime getCheckIn();
    CheckTime getCheckOut();

    void setFeedback(string _feedback);
    string getFeedback();

    
    void addOrder(ManageService manageService);
    void getOrderList();
    void getBill();
};

typedef enum {
    U, // Unavailable
    A // Available
} Status;

inline string changeStatus(Status _status) {
    string status = "";
    if (_status == U) status = "U";
    else if (_status == A) status = "A";

    return status;
}

/*
*Class: Room
*Description: This class contains basic properties and methods of a Room object
*/
class Room {
private:
    string roomID; // ID phòng 
    Status status;
    list<Customer> customerList;

public:
    Room() {
        this->roomID = "";
        status = A;
    }

    void setRoomID(string _roomID);
    string getRoomID() const;
    void setStatus(Status _status);
    Status getStatus();

    void addCustomer();
    void getCustomer();
    void inforCustomer();
    int getphoneCustomer();
    void resetRoom();

    void addOderfromCustomer(ManageService manageService);

    
    bool operator < (const Room& other) {
        return this->getRoomID() < other.getRoomID();
    }
};

/*
*Class: ManageRoom
*Description: This class contains basic properties and methods that manage rooms of hotel
*/
class ManageRoom {
private:
    list <Room> roomList;

public:
    ManageRoom() {}


    list <Room> getRoomList();
    bool isFull();
    void addRoom(string _roomID);
    void deleteRoom(string _ID);
    void sort_room();
    void showRoom();

    void setCustomerInformationforRoom(string _roomID);
    void getCustomerInformationfromRoom(int _phoneCustomer);
    void addOderfromCustomertoRoom(ManageService manageService, int _phoneCustomer);

    void getInfor(string _ID);

    void menuManageRoom();
};

#endif
