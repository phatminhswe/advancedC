/*
* File: receptionist.cpp
* Author: Minh Phat
* Date: 22/04/2024
* Description: This file contains all the functions/methods that help receptionists manage customers 
*/

#include "receptionist.h"
using namespace std;

/*
* Function: Receptionist::setAccountt
* Description: Sets the account/phone number of the receptionist.
* Input: _accountt - an integer representing the account/phone number.
* Output: None
*/
void Receptionist::setAccountt(int _accountt) {
    accountt = _accountt;
}

/*
* Function: Receptionist::setPasswordd
* Description: Sets the password of the receptionist.
* Input: _passwordd - an integer representing the password.
* Output: None
*/
void Receptionist::setPasswordd(int _passwordd) {
    passwordd = _passwordd;
}

/*
* Function: Receptionist::getAccountt
* Description: Retrieves the account/phone number of the receptionist.
* Input: None
* Output: Returns an integer representing the account/phone number.
*/

int Receptionist::getAccountt() {
    return accountt;
}

/*
* Function: Receptionist::getPasswordd
* Description: Retrieves the password of the receptionist.
* Input: None
* Output: Returns an integer representing the password.
*/
int Receptionist::getPasswordd() {
    return passwordd;
}

/*
* Function: Receptionist::checkShift
* Description: Displays the weekly shift timetable for employees.
* Input: database - a Database object containing employee information.
* Output: None
*/
void Receptionist::checkShift(Database database) {
    database.employee.tableShift();
}

/*
* Function: Receptionist::makeCheckIn
* Description: Handles the check-in process for customers, allowing them to choose a room.
* Input: database - a Database object containing room information.
* Output: None
*/
void Receptionist::makeCheckIn(Database& database) {
    database.room.showRoom();
    cout << "\t\t\tPlease choose one of these Room ID: ";
    string _ID = "";
    cin.ignore(); cin >> _ID;
    database.room.setCustomerInformationforRoom(_ID);
    
}

/*
* Function: Receptionist::makeService
* Description: Handles the service setup process for customers in a room.
* Input: database - a Database object containing service and room information, _phoneCustomer - an integer representing the customer's phone number.
* Output: None
*/
void Receptionist::makeService(Database& database, int _phoneCustomer) {
    database.room.addOderfromCustomertoRoom(database.service, _phoneCustomer);
}

/*
* Function: Receptionist::makeCheckOut
* Description: Handles the check-out process for customers, displaying their information.
* Input: database - a Database object containing room information.
* Output: None
*/
void Receptionist::makeCheckOut(Database& database) {
    int _phoneCustomer;
    cout << "Please enter customer phone number:";
    cin.ignore(); cin >> _phoneCustomer;

    database.room.getCustomerInformationfromRoom(_phoneCustomer);
               
    return;
          
}

/*
* Function: Receptionist::showRoom
* Description: Displays the list of available rooms.
* Input: database - a Database object containing room information.
* Output: None
*/
void Receptionist::showRoom(Database database) {
    database.room.showRoom();
}

/*
* Function: Receptionist::menuReceptionist
* Description: Displays the receptionist menu and handles user interactions.
* Input: database - a Database object containing various information.
* Output: None
*/
void Receptionist::menuReceptionist(Database& database) {
    registering: 
    int _passwordd = 0; int _accountt = 0; int _choicee = 0;

    cout << "\t\t\t\t\t\tLOG IN" << endl;

    cout << "\t\t\tPlease Enter Account / Phone number: ";
    cin >> _accountt;

    cout << "\t\t\tPlease Enter Password: ";
    cin >> _passwordd;

    if ((getAccountt() != _accountt) || (getPasswordd() != _passwordd)) {
        

        cout << "\t\t\t The Password Is Incorrect!" << endl;
        cout << "\t\t\t --------------------------" << endl;
        cout << "\t\t\t 1. Re-enter The Password" << endl;
        cout << "\t\t\t 2. Turn Back Main Menu " << endl;
        cout << "\t\t\t 3. Exit Program" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> _choicee;

        switch (_choicee) {
        case 1:
            goto registering;
            break;

        case 2:
            break;

        case 3:
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
            exit(0);
            break;

        default:
            break;
        }
    }

    else if ((getAccountt() == _accountt) && (getPasswordd() == _passwordd)) {
    menuReceptionist_start:
        do {
            system("cls");

            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t|    RECEPTIONIST WORKING   |" << endl;
            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t 1. Weekly Shift Timetable" << endl; // 1. Xem ca làm
            cout << "\t\t\t 2. Edit Receptionist Account" << endl;  // 2. Sửa thông tin
            cout << "\t\t\t 3. Check In For Customer" << endl; // 3. Đặt phòng cho khách
            cout << "\t\t\t 4. Set Service For Customer" << endl; // 4. Set dịch vụ
            cout << "\t\t\t 5. Check Out for Customer" << endl; // 5. Trả phòng cho khách
            cout << "\t\t\t 6. List Of Rooms" << endl; // 6. Danh sách phòng
            cout << "\t\t\t 7. Turn Back Main Menu" << endl; // 7. Về lại menu chính
            cout << "\t\t\t 8. Exit Program" << endl; // 8. Thoát ctr
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choicee;

        } while (_choicee < 1 || _choicee > 8);

        string _roomID; int numberPhone = 0;

        switch (_choicee) {
        case 1:
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------Weekly Shift Timetable --------------------------------------------" << endl;
            checkShift(database);
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

            do {
                cout << "\n\n\t\t\t Enter 1 To Turn Back Receptionist Menu " << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choicee;
            } while (_choicee != 1);

            goto menuReceptionist_start;
            break;

        case 2:
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "Please Enter New Account/ Phone Number You Want To Change: " << endl;
            cin >> _accountt; setAccountt(_accountt);

            cout << "Please Enter New Password You Want To Change" << endl;
            cin >> _passwordd; setPasswordd(_passwordd);
            cout << "\n----------------------------- Successfully Setting New Password ---------------------------------------" << endl;

            do {
                cout << "\n\n\t\t\t Enter 1 To Turn Back Receptionist Menu " << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choicee;
            } while (_choicee != 1);

            goto menuReceptionist_start;
            break;

        case 3:
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;

            if (database.room.isFull()) cout << "Sorry. There are no tables available.";

            else makeCheckIn(database);

            do {
                cout << "\n\n\t\t\t Enter 1 To Turn Back Receptionist Menu " << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choicee;
            } while (_choicee != 1);

            goto menuReceptionist_start;
            break;

        case 4: {
        add_service_order:
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter yourphone To Add Type Of Services: " << endl;
            cin.ignore(); cin >> numberPhone;
            makeService(database, numberPhone);
            do {
                cout << "\n\n\t\t\t 1. Continue Adding Another Type Of Service " << endl;
                cout << "\t\t\t 2. Turn Back Receptionist Menu " << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choicee;
            } while (_choicee != 1 && _choicee != 2);

            if (_choicee == 1) goto add_service_order;
            else goto menuReceptionist_start;
            break;
        }

        case 5:
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            makeCheckOut(database);
            

            do {
                cout << "\n\n\t\t\t Enter 1 To Turn Back Receptionist Menu " << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choicee;
            } while (_choicee != 1);

            goto menuReceptionist_start;
            break;

        case 6:
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            showRoom(database);

            do {
                cout << "\n\n\t\t\t Enter 1 To Turn Back Receptionist Menu " << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> _choicee;
            } while (_choicee != 1);

            goto menuReceptionist_start;
            break;

        case 7:
            break;

        case 8:
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------- Program Is Exit --------------------------------------------" << endl;
            exit(0);
            break;

        default:
            break;
        }

    } while (_choicee != 7);
}
