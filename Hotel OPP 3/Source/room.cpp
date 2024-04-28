/*
* File: room.cpp
* Author: Minh Phat
* Date: 22/04/2024
* Description: This file contains all the functions/methods that help receptionists I handle customer information
*/

#include "room.h"
using namespace std;

/*
* Function: setNameCustomer
* Description: Sets the name of the customer.
* Input: _name - a string representing the name of the customer.
* Output: None
*/
void Customer::setNameCustomer(string _name) {
    nameCustomer = _name;
}

/*
* Function: getNameCustomer
* Description: Retrieves the name of the customer.
* Input: None
* Output: Returns a string representing the name of the customer.
*/
string Customer::getNameCustomer() {
    return nameCustomer;
}
/*
* Function: setPhoneCustomer
* Description: Sets the phone number of the customer.
* Input: _phone - an integer representing the phone number of the customer.
* Output: None
*/
void Customer::setPhoneCustomer(int _phone) {
    phoneCustomer = _phone;
}
/*
* Function: getPhoneCustomer
* Description: Retrieves the phone number of the customer.
* Input: None
* Output: Returns an integer representing the phone number of the customer.
*/
int Customer::getPhoneCustomer() {
    return phoneCustomer;
}

/*
* Function: setCheckIn
* Description: Sets the check-in time for the customer.
* Input: _checkIn - a CheckTime object representing the check-in time.
* Output: None
*/
void Customer::setCheckIn(CheckTime _checkIn) {
    checkIn = _checkIn;
}

/*
* Function: setCheckOut
* Description: Sets the check-out time for the customer.
* Input: _checkOut - a CheckTime object representing the check-out time.
* Output: None
*/
void Customer::setCheckOut(CheckTime _checkOut) {
    checkOut = _checkOut;
}
/*
* Function: getCheckIn
* Description: Retrieves the check-in time for the customer.
* Input: None
* Output: Returns a CheckTime object representing the check-in time.
*/
CheckTime Customer::getCheckIn() {
    return checkIn;
}
/*
* Function: getCheckOut
* Description: Retrieves the check-out time for the customer.
* Input: None
* Output: Returns a CheckTime object representing the check-out time.
*/
CheckTime Customer::getCheckOut() {
    return checkOut;
}
/*
* Function: setFeedback
* Description: Sets the feedback provided by the customer.
* Input: _feedback - a string representing the feedback provided by the customer.
* Output: None
*/
void Customer::setFeedback(string _feedback) {
    feedback = _feedback;
}
/*
* Function: getFeedback
* Description: Retrieves the feedback provided by the customer.
* Input: None
* Output: Returns a string representing the feedback provided by the customer.
*/
string Customer::getFeedback() {
    return feedback;
}
/*
* Function: setRoomID
* Description: Sets the ID of the room.
* Input: _roomID - a string representing the ID of the room.
* Output: None
*/

void Room::setRoomID(string _roomID) {
    roomID = _roomID;
}
/*
* Function: getRoomID
* Description: Retrieves the ID of the room.
* Input: None
* Output: Returns a string representing the ID of the room.
*/
string Room::getRoomID() const {
    return roomID;
}

/*
* Function: setStatus
* Description: Sets the status of the room.
* Input: _status - a Status enum representing the status of the room.
* Output: None
*/
void Room::setStatus(Status _status) {
    status = _status;
}
/*
* Function: getStatus
* Description: Retrieves the status of the room.
* Input: None
* Output: Returns a Status enum representing the status of the room.
*/
Status Room::getStatus() {
    return status;
}
/*
* Function: addCustomer
* Description: Adds a customer to the room.
* Input: None
* Output: None
*/
void Room::addCustomer() {
    setStatus(U);

    Customer newCustomer;

    string _name; int _num;
    cout << "Please enter customer name: ";
    cin >> _name;
    cout << "Please enter customer phone number: ";
    cin.ignore(); cin >> _num;

    CheckTime _checkTime;
    cout << "Please enter time customer Check in: ";
    cin.ignore(); cin >> _checkTime.Time;
    cout << "Please enter date customer Check in: ";
    cin.ignore(); cin >> _checkTime.Date;

    newCustomer.setNameCustomer(_name);
    newCustomer.setPhoneCustomer(_num);
    newCustomer.setCheckIn(_checkTime);

    customerList.push_back(newCustomer);
}
/*
* Function: getCustomer
* Description: Retrieves customer information for the room.
* Input: None
* Output: None
*/
void Room::getCustomer() {
    for (auto& it : customerList) {
        
        cout << "Customer Details:" << endl;
        cout << "Name: " << it.getNameCustomer() << endl;
        cout << "Phone Number: " << it.getPhoneCustomer() << endl;
        cout << "Time checkin: " << it.getCheckIn().Time << " - " << it.getCheckIn().Date << endl;
        CheckTime _checkTime;
        cout << "Please enter time customer Check in: ";
        cin.ignore(); cin >> _checkTime.Time;
        cout << "Please enter date customer Check in: ";
        cin.ignore(); cin >> _checkTime.Date;
        it.setCheckOut(_checkTime);
        cout << "Bill: " << "" << endl;
        it.getBill();
        string _Feedback;
        cout << "Please enter Feedback: ";
        cin >> _Feedback;
        it.setFeedback(_Feedback);
       
        
    }

}
/*
* Function: inforCustomer
* Description: Retrieves and displays customer information for the room.
* Input: None
* Output: None
*/
void Room::inforCustomer() {
    for (auto& it : customerList) {

        cout << "Customer Details:" << endl;
        cout << "Name: " << it.getNameCustomer() << endl;
        cout << "Phone Number: " << it.getPhoneCustomer() << endl;
        cout << "Time checkin: " << it.getCheckIn().Time << " - " << it.getCheckIn().Date << endl;
        cout << "Bill: ";
        it.getBill();
        cout << " Feedback: " << it.getFeedback() << endl;  
    }

}
/*
* Function: getphoneCustomer
* Description: Retrieves the phone number of the customer staying in the room.
* Input: None
* Output: Returns an integer representing the phone number of the customer.
*/
int Room::getphoneCustomer() {
    for (auto& it : customerList) {
        
        return it.getPhoneCustomer();
    }

}
/*
* Function: addOderfromCustomer
* Description: Adds orders made by the customer to the room.
* Input: manageService - a ManageService object managing available services.
* Output: None
*/
void Room::addOderfromCustomer(ManageService manageService) {
    for (auto& it : customerList) {

        it.addOrder(manageService);
    }
}

/*
* Function: resetRoom
* Description: Resets the status of the room to available.
* Input: None
* Output: None
*/
void Room::resetRoom() {
    setStatus(A);
}

/*
* Function: addOrder
* Description: Adds an order for services requested by the customer during their stay.
* Input: manageService - a ManageService object managing available services.
* Output: None
*/
void Customer::addOrder(ManageService manageService) {
    int ans = 0;
    do {
        cout << "\t\t\tSelect the type of service you want to use from the categories below" << endl;
        cout << "\t\t\t1. Food and Beverage" << endl;
        cout << "\t\t\t2. Pool" << endl;
        cout << "\t\t\t3. Gym" << endl;
        cout << "\t\t\t4. Laundry" << endl;
        cout << "\t\t\tPlease Enter Your Choice: " << endl;
        cin >> ans;
    } while (ans < 1 || ans > 4);

    Order newOrder; int _ID; int _num;

    switch (ans) {
    case 1: {
        cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
        manageService.showService(manageService.getDish());

        cout << "\n\n\t\t\tEnter ID of Dish you want: ";
        cin >> _ID;
        list<Service> listDish = manageService.getDish();
        list<Service>::iterator it;
        for (it = listDish.begin(); it != listDish.end(); ++it) {
            if (it->getID() == _ID) {
                newOrder.typeService.setID(it->getID());
                newOrder.typeService.setName(it->getName());
                newOrder.typeService.setPrice(it->getPrice());
                break;
            }
        }

        cout << "Enter quantity of dish you want: ";
        cin >> _num;
        newOrder.numService = _num;

        orderService.push_back(newOrder);

        break;
    }

    case 2: {
        cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
        manageService.showService(manageService.getPool());

        cout << "\n\n\t\t\tEnter ID's type of Pool services you want: ";
        cin >> _ID;
        list<Service> listPool = manageService.getPool();
        list<Service>::iterator it;
        for (it = listPool.begin(); it != listPool.end(); ++it) {
            if (it->getID() == _ID) {
                newOrder.typeService.setID(it->getID());
                newOrder.typeService.setName(it->getName());
                newOrder.typeService.setPrice(it->getPrice());
                break;
            }
        }

        cout << "Enter quantity for type of Pool services you want: ";
        cin >> _num;
        newOrder.numService = _num;

        orderService.push_back(newOrder);

        break;
    }

    case 3: {
        cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
        manageService.showService(manageService.getGym());

        cout << "\n\n\t\t\tEnter ID's type of Gym services you want: ";
        cin >> _ID;
        list<Service> listGym = manageService.getGym();
        list<Service>::iterator it;
        for (it = listGym.begin(); it != listGym.end(); ++it) {
            if (it->getID() == _ID) {
                newOrder.typeService.setID(it->getID());
                newOrder.typeService.setName(it->getName());
                newOrder.typeService.setPrice(it->getPrice());
                break;
            }
        }

        cout << "Enter quantity for type of Gym services you want: ";
        cin >> _num;
        newOrder.numService = _num;

        orderService.push_back(newOrder);

        break;
    }

    case 4: {
        cout << "\n\n--------------------------------------------- Menu ----------------------------------------------------" << endl;
        manageService.showService(manageService.getLaundry());

        cout << "\n\n\t\t\tEnter ID's type of Laundry services you want: ";
        cin >> _ID;
        list<Service> listLaundry = manageService.getLaundry();
        list<Service>::iterator it;
        for (it = listLaundry.begin(); it != listLaundry.end(); ++it) {
            if (it->getID() == _ID) {
                newOrder.typeService.setID(it->getID());
                newOrder.typeService.setName(it->getName());
                newOrder.typeService.setPrice(it->getPrice());
                break;
            }
        }

        cout << "Enter quantity for type of Laundry services you want: ";
        cin >> _num;
        newOrder.numService = _num;

        orderService.push_back(newOrder);

        break;
    }

    default:
        break;
    }
}
/*
* Function: getOrderList
* Description: Retrieves the list of orders made by the customer.
* Input: None
* Output: None
*/
void Customer::getOrderList() {
    int count = 0;
    cout << "\t\t\t\t\tList Of Your Used Service" << endl << endl;
    cout << "No" << "\t\tName" << "\t\tPrice" << "\t\tQuantity" << endl;
    for (auto &i : orderService) {
        count++;
        cout << count << "\t\t" << i.typeService.getName() << "\t\t" << i.typeService.getPrice() << "\t\t" << i.numService << endl;
    }
}
static void tachNgayThangNam(string date, int& day, int& month, int& year) {
    // Khởi tạo stringstream với chuỗi cần tách
    istringstream ss(date);

    // Biến lưu trữ các phần tách ra
    string day_str, month_str, year_str;

    // Tách ngày, tháng, năm từ chuỗi
    getline(ss, day_str, '/');
    getline(ss, month_str, '/');
    getline(ss, year_str);

    // Chuyển đổi các phần thành số nguyên
    day = stoi(day_str);
    month = stoi(month_str);
    year = stoi(year_str);
}
static void tachGioPhut(string time, int& hour, int& minutes) {
    // Khởi tạo stringstream với chuỗi cần tách
    istringstream ss(time);

    // Biến lưu trữ các phần tách ra
    string hour_str, minutes_str;

    // Tách ngày, tháng, năm từ chuỗi
    getline(ss, hour_str, 'h');
    getline(ss, minutes_str);
   

    // Chuyển đổi các phần thành số nguyên
    hour = stoi(hour_str);
    minutes = stoi(minutes_str);
    
}
static bool namNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

// Hàm tính số ngày của tháng
static int soNgayCuaThang(int thang, int nam) {
    switch (thang) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return namNhuan(nam) ? 29 : 28;
    default:
        return -1; // Trường hợp không hợp lệ
    }
}

// Hàm tính số ngày từ ngày bắt đầu đến ngày kết thúc
static int tinhSoNgay(int ngayBatDau, int thangBatDau, int namBatDau, int ngayKetThuc, int thangKetThuc, int namKetThuc) {
    int soNgay = 0;

    // Tính số ngày từ ngày bắt đầu đến cuối tháng
    for (int i = ngayBatDau; i <= soNgayCuaThang(thangBatDau, namBatDau); ++i) {
        soNgay++;
    }

    // Tính số ngày từ tháng sau đến tháng trước khi kết thúc
    for (int i = thangBatDau + 1; i < thangKetThuc; ++i) {
        soNgay += soNgayCuaThang(i, namKetThuc);
    }

    // Tính số ngày từ ngày 1 đến ngày kết thúc
    for (int i = 1; i <= ngayKetThuc; ++i) {
        soNgay++;
    }

    return soNgay;
}
/*
* Function: getBill
* Description: Calculates and displays the bill for the customer's stay, including room charges and service charges.
* Input: None
* Output: None
*/
void Customer::getBill() {
    int _totalBill = 0;
    for (auto &i : orderService) {
        _totalBill += i.typeService.getPrice() * i.numService;
        
        
    }

    string dateIn = getCheckIn().Date;  int dayIn = 0, monthIn = 0, yearIn = 0; tachNgayThangNam(dateIn, dayIn, monthIn, yearIn);
    string timeIn = getCheckIn().Time;  int hourIn = 0, minutesIn = 0; tachGioPhut(timeIn, hourIn, minutesIn);
    string dateOut = getCheckOut().Date; int dayOut = 0, monthOut = 0, yearOut = 0; tachNgayThangNam(dateOut, dayOut, monthOut, yearOut);
    string timeOut = getCheckOut().Time; int hourOut = 0, minutesOut = 0; tachGioPhut(timeOut, hourOut, minutesOut);
    int day = tinhSoNgay(dayIn, monthIn, yearIn, dayOut, monthOut, yearOut);
    int totalRoom = 0;
    int totalminute = 0; totalminute = ((day - 2) * 1440 + (1440 - (hourIn * 60 + minutesIn)) + (hourOut * 60 + minutesOut));
    totalRoom = (totalminute *10);
    int dayy = 0,  hour= 0,  minute = 0;
    dayy = round(totalminute / 1440);
    hour = round((totalminute - (dayy * 1440)) / 60);
    minute = ((totalminute - (dayy * 1440)) - (hour * 60));
    
    int total = 0; total = totalRoom + _totalBill;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tTime: " << dayy << "\tngay\t" << hour << "\tgio\t" << minute <<"\tphut"<< endl; // thành tiền
    cout << "\t\t\tGia : 60 nghin dong/ 1 hour" << endl;
    cout << "\t\t\tRoom: " << totalRoom << endl; // tổng tiền thanh toán
    
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    getOrderList();
    cout << "\t\t\tService: " << _totalBill << endl;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tTotal: " << total << endl; // thành tiền
    cout << "\t\t\tVAT: 10%" << endl;
    cout << "\t\t\tGrand total: " << (110  * total)/100 << endl; // tổng tiền thanh toán
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
}

/*
* Function: sort_room
* Description: Sorts the list of rooms.
* Input: None
* Output: None
*/
void ManageRoom::sort_room() {
    roomList.sort();
}
/*
* Function: getRoomList
* Description: Retrieves the list of rooms.
* Input: None
* Output: Returns a list of Room objects representing the rooms.
*/
list <Room> ManageRoom::getRoomList() {
    return roomList;
}
/*
* Function: isFull
* Description: Checks if all rooms are full.
* Input: None
* Output: Returns true if all rooms are full, false otherwise.
*/
bool ManageRoom::isFull() {
    for (auto &it : roomList) {
        if (it.getStatus() == A) return false;
    }
    return true;
}
/*
* Function: addRoom
* Description: Adds a new room to the list of rooms.
* Input: _roomID - a string representing the ID of the new room.
* Output: None
*/
void ManageRoom::addRoom(string _roomID) {
    Room newRoom;
    newRoom.setRoomID(_roomID);
    roomList.push_back(newRoom);
}
/*
* Function: deleteRoom
* Description: Deletes a room from the list of rooms.
* Input: _ID - a string representing the ID of the room to be deleted.
* Output: None
*/
void ManageRoom::deleteRoom(string _ID) {
    list<Room>::iterator it;
    for (it = roomList.begin(); it != roomList.end(); ++it) {
        if (it->getRoomID() == _ID) {
            cout << "\n-----------------------------------------Data is founded-----------------------------------------------" << endl << endl;
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
            roomList.erase(it);
        }
    }
}
/*
* Function: showRoom
* Description: Displays the status of all rooms.
* Input: None
* Output: None
*/
void ManageRoom::showRoom() {
    sort_room();

    for (int floor = 1; floor <= 9; floor++) {
        cout << "Floor " << floor << endl;



        for (auto &i : roomList) {


            int flooroom = stoi(std::string(1, i.getRoomID()[0]));

            if (flooroom == floor) {
                cout << "\t\t"; cout << i.getRoomID();
            }
        }
        cout << endl;

        for (auto &i : roomList) {
            int flooroomm = stoi(std::string(1, i.getRoomID()[0]));
            if (flooroomm == floor) {
                cout << "\t\t"; cout << changeStatus(i.getStatus());
            }
        }
        cout << endl << endl;
    }

    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tU - Unavailable" << endl;
    cout << "\t\t\tA - Available";
}
/*
* Function: setCustomerInformationforRoom
* Description: Sets customer information for a specific room.
* Input: _roomID - a string representing the ID of the room.
* Output: None
*/

void ManageRoom::setCustomerInformationforRoom(string _roomID) {
    for (auto& it : roomList) {
        if (it.getRoomID() == _roomID) {
            it.addCustomer();
        }
    }
}

/*
* Function: getCustomerInformationfromRoom
* Description: Retrieves customer information from a specific room.
* Input: _phoneCustomer - an integer representing the phone number of the customer.
* Output: None
*/
void ManageRoom::getCustomerInformationfromRoom(int _phoneCustomer) {
    int cnt = 0;
    for (auto& it : roomList) {
        
        if (it.getphoneCustomer() == _phoneCustomer) {
            cnt++;
            cout << "Room ID: " << it.getRoomID() << endl;
            it.getCustomer();
            cout << "\n\n-------------------------------------------------------------------------------------------------------" << endl;
            
            
            
            int ans = 0;
            do {
                cout << "\n\n\t\t\t1. Pay away" << endl;
                cout << "\t\t\t2. Turn back" << endl;
                cout << "\t\t\tPlease Enter Your Choice: " << endl;
                cin >> ans;
            } while (ans != 1);

            it.resetRoom();
            
        }
        

    }
    if (cnt == 0) {
        cout << "\n\n\t\t\tWrong Phone Number" << endl;
        return;
    }
}

/*
* Function: getInfor
* Description: Retrieves room information for a specific room.
* Input: _ID - a string representing the ID of the room.
* Output: None
*/
void ManageRoom::getInfor(string _ID) {
    cout << "\n-----------------------------------------Customer Information------------------------------------------" << endl << endl;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;

    for (auto& i : roomList) {
        if (i.getRoomID() == _ID) {
            i.inforCustomer();
            

    cout << "\n-------------------------------------------------------------------------------------------------------\n" << endl;

        }
    }
}

/*
* Function: addOderfromCustomertoRoom
* Description: Adds orders made by the customer to a specific room.
* Input: manageService - a ManageService object managing available services, _phoneCustomer - an integer representing the phone number of the customer.
* Output: None
*/
void ManageRoom::addOderfromCustomertoRoom(ManageService manageService, int _phoneCustomer) {
    int cnt = 0;
    for (auto& it : roomList) {
        if (it.getphoneCustomer() == _phoneCustomer) {
            it.addOderfromCustomer(manageService);
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "\n\n\t\t\tWrong Phone Number" << endl;
        return;
    }
}

/*
* Function: menuManageRoom
* Description: Displays a menu interface for managing rooms and performs various room management tasks based on user input.
* Input: None
* Output: None
*/
void ManageRoom::menuManageRoom() {
menuManageRoom_start:
    int _choice = 0;
    cout << "\t\t\t-------------------------------" << endl;
    cout << "\t\t\t|     SERVICE MANAGEMENT     |" << endl;
    cout << "\t\t\t-------------------------------" << endl;
    do {
        cout << "\t\t\t 1. Add Room" << endl; // 1. Thêm phòng
        cout << "\t\t\t 2. Delete Room" << endl; // 2. Xóa phòng
        cout << "\t\t\t 3. Room status" << endl; // 3. Xem trạng thái phòng
        cout << "\t\t\t 4. Turn Back Manager Menu" << endl; // 5. Thoát
        cout << "\t\t\t 5. Exit" << endl; // 5. Thoát
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> _choice;
    } while (_choice < 1 || _choice > 5);

    switch (_choice) {
    case 1:
    {
    add_room:
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------------------ROOM-----------------------------------------------------" << endl;
        showRoom();
        cout << endl << endl;

        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------------- Add room ------------------------------------------------" << endl;
        cout << "\t\t\tEnter ID of room you want: ";
        string _ID = ""; cin.ignore(); cin >> _ID;
        addRoom(_ID);
        cout << "\n----------------------------- Successfully Add New Employee Details -----------------------------------" << endl;

        do {
            cout << "\n\n\t\t\t 1. Continue Adding Another Room" << endl;
            cout << "\t\t\t 2. Turn Back Room Menu " << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choice;
        } while (_choice != 1 && _choice != 2);

        if (_choice == 1) goto add_room;
        else goto menuManageRoom_start;

        break;
    }

    case 2:
    {
    delete_room:
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Delete Employee Detail ------------------------------------------" << endl;
        cout << "\nEnter ID of room you want to delete: ";
        string _ID_input = ""; cin >> _ID_input;
        deleteRoom(_ID_input);
        cout << "\n---------------------------- Successfully Delete Employee Detail --------------------------------------" << endl;

        do {
            cout << "\n\n\t\t\t 1. Continue Deleting Another Room" << endl;
            cout << "\t\t\t 2. Turn Back Room Menu " << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choice;
        } while (_choice != 1 && _choice != 2);

        if (_choice == 1) goto delete_room;
        else goto menuManageRoom_start;

        break;
    }

    case 3:
    {
     infor_room:
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------------------ROOM-----------------------------------------------------" << endl;
        showRoom();

        do {
            cout << "\n\n\t\t\t 1. Get room information" << endl;
            cout << "\t\t\t 2. Turn Back Room Menu " << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choice;
        } while (_choice != 1 && _choice != 2);

        if (_choice == 1) {
            cout << "\t\t\tEnter ID of room you want: ";
            string _ID = ""; cin.ignore(); cin >> _ID;

            cout << "----------------------------------------------" << _ID << "-----------------------------------------------------" << endl << endl;
            getInfor(_ID);
        }
        do {
            cout << "\n\n\t\t\t 1. Continue Deleting Another Room" << endl;
            cout << "\t\t\t 2. Turn Back Room Menu " << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> _choice;
        } while (_choice != 1 && _choice != 2);

        if (_choice == 1) goto infor_room;
        else goto menuManageRoom_start;
        break;
    }



    case 4: // 8. Exit
        break;
    default:
        break;
    }
}
