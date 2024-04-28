#include "menu.h"
#include <stdlib.h>
#include <iostream>


void mainMenu (Database &database) {
    while (1) {
        Title title = managerWork;

        do {
        menu_Start:
            system("cls");

            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t| RESTAURANT MANAGEMENT SYSTEM |" << endl;
            cout << "\t\t\t-----------------------------" << endl;
            cout << "\t\t\t 1. Manager" << endl;
            cout << "\t\t\t 2. Staff" << endl;
            cout << "\t\t\t 3. Exit program" << endl;
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;

            if (choice == 3 ) exit(0);

        } while (choice != 1 && choice != 2);

        if (choice == 1) title = managerWork;
        else title = staffWork;

        switch (title) {
            case managerWork:

                menuManager(database);
                goto menu_Start;

                break;
            
            case staffWork:
                menuStaff(database);
                break;

            default:
                break;
        }
    }
}

void menuManager (Database &database) {
menuManager_start:
    do {
        system("cls");

        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t|       MANAGER WORKING      |" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t 1. Set up table" << endl; // 1. Set up số bàn
        cout << "\t\t\t 2. Add dish" << endl; // 2. Thêm món
        cout << "\t\t\t 3. Edit dish" << endl; // 3. Sửa món
        cout << "\t\t\t 4. Delete dish" << endl; // 4. Xóa món
        cout << "\t\t\t 5. List of dishes" << endl; // 5. Danh sách món
        cout << "\t\t\t 0. Turn back" << endl; // 6. 	Quay lại
        cout << "\t\t\t 7. Exit program" << endl;
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> choice;
    } while (choice < 1 || choice > 8);
   
    
    switch(choice) {

            

        case 1:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "----------------------------------------- Set up table ------------------------------------------------" << endl;
            cout << "\t\t\tEnter quantity of table you want to set up: ";
            cin >> database.numTable;
            database.managerData.setNumTable(database.numTable);
            database.staffaData.getNumTable(database.numTable); 
            do {
                cout << "\n\t\t\t 1. Turn back manager menu" << endl;
                cout << "\t\t\t 2. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> choice;   
                
                if (choice == 2) exit(0);

            } while (choice != 1);

            goto menuManager_start;
        
            break;
        case 2:
            add_menu:
            cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
            database.managerData.showMenu();
            cout << endl << endl;

            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "----------------------------------------- Add dish ------------------------------------------------" << endl;
            database.managerData.addDish();

            do {
                cout << "\n\n\t\t\t 1. Continue Adding Another Dish " << endl;
                cout << "\n\t\t\t 2. Turn back manager menu" << endl;
                cout << "\t\t\t 3. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> choice;

                if (choice == 3) exit(0);

            } while (choice != 1 && choice != 2);

            if (choice == 1) goto add_menu;
            else goto menuManager_start;
            break;
        case 3:
            edit_menu:
            cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
            database.managerData.showMenu();
            cout << endl << endl;

            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "------------------------------------------ Edit dish --------------------------------------------------" << endl;
            cout << "\nEnter ID of Dish you want to edit: ";
            int ID_input; cin >> ID_input;

            database.managerData.editDish(ID_input);

            do {
                cout << "\n\n\t\t\t 1. Continue Editing Another Dish " << endl;
                cout << "\n\t\t\t 2. Turn back manager menu" << endl;
                cout << "\t\t\t 3. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> choice;

                if (choice == 3) exit(0);

            } while (choice != 1 && choice != 2);

            if (choice == 1) goto edit_menu;
            else goto menuManager_start;
            break;
        
        
        case 4:{
        delete_menu:
            cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
            database.managerData.showMenu();
            cout << endl << endl;

            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "----------------------------------------- Delete dish -------------------------------------------------" << endl;
            cout << "\nEnter ID of Dish you want to delete: ";
            int ID_input ; cin >> ID_input;

            database.managerData.deleteDish(ID_input);

            do {
                cout << "\n\n\t\t\t 1. Continue Deleting Another Dish " << endl;
                cout << "\n\t\t\t 2. Turn back manager menu" << endl;
                cout << "\t\t\t 3. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> choice;

                if (choice == 3) exit(0);

            } while (choice != 1 && choice != 2);

            if (choice == 1) goto delete_menu;
            else goto menuManager_start;
            break;
        }
        case 5:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
            database.managerData.showMenu();
            
            do {
                cout << "\n\t\t\t 1. Turn back manager menu" << endl;
                cout << "\t\t\t 2. Exit program" << endl;
                cout << "\t\t\tPlease Enter Your Choice: ";
                cin >> choice;   
                
                if (choice == 3) exit(0);

            } while (choice != 1);

            goto menuManager_start;
            break;  
        default:
            std::cout << "Số bạn nhập không nằm trong phạm vi từ 0 đến 5." << std::endl;
            break;
    }
    }



void menuStaff (Database &database) {
menuStaff_start:
int _tableID = 0; 

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|       STAFF WORKING       |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    
    do {
        cout << "\t\t\tHave you booked a table?" << endl;
        cout << "\t\t\t1. Yes" << endl;
        cout << "\t\t\t2. No" << endl;
        cout << "\t\t\t............................" << endl;
        cout << "\t\t\tPlease Enter Your Choice: ";
        cin >> choice;
    } while (choice != 1 && choice !=2);

    if (choice == 1) {
        cout << "\t\t\tPlease Enter Your Table ID: ";
        cin >> _tableID;
        database.staffaData.chooseTable(_tableID);
    }

    else {
        database.staffaData.displayTable();
        
        if (database.staffaData.isFull()) {
            cout <<"Sorry. There are no tables available." << endl;
            cin >> _tableID;
        }

        else {
            cout << "\t\t\tPlease choose one of these Table ID: ";
            cin >> _tableID;
            database.staffaData.chooseTable(_tableID);
        }
    }
orderMenu_start:
        do {
            cout << "\t\t\t 1. Add dish" << endl; 
            cout << "\t\t\t 2. Cancel dish " << endl; 
            cout << "\t\t\t 3. Edit dish" << endl; 
            cout << "\t\t\t 4. List of dish" << endl; 
            cout << "\t\t\t 5. Pay the bill" << endl;
            cout << "\t\t\t 6. Turn back staff menu" << endl;
            cout << "\t\t\t 7. Turn back main menu" << endl; 
            cout << "\t\t\t 8. Exit program" << endl;
            cout << "\t\t\t............................" << endl;
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;
        } while (choice < 1 || choice > 8);    

        switch (choice) {
            case 1: // 1. Gọi món
            add_order:
                cout << "--------------------------------------------- Menu ----------------------------------------------------" << endl;
                database.managerData.showMenu();
                cout << endl << endl;

                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "----------------------------------------- Add dish ------------------------------------------------" << endl;
                database.staffaData.getDishInformationfromtheTable(_tableID,database.managerData.getMenu());
               
                do {
                    cout << "\n\n\t\t\t 1. Continue Adding Another Order " << endl;
                    cout << "\n\t\t\t 2. Turn back Order menu" << endl;
                    cout << "\n\t\t\t 3. Turn back Staff menu" << endl;
                    cout << "\t\t\t 4. Exit program" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> choice;

                    if (choice == 4) exit(0);

                } while (choice != 1 && choice != 2 && choice != 3);

                if (choice == 1) goto add_order;
                else if (choice == 2) goto orderMenu_start;
                else goto menuStaff_start;
                break;
            case 2:
             delete_order:
                cout << "--------------------------------------------- Order ----------------------------------------------------" << endl;
                database.staffaData.displayDishfromtheTable(_tableID);
                cout << endl << endl;

                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "---------------------------------------- Delete order -------------------------------------------------" << endl;
                cout << "\nEnter ID of order you want to delete: ";
                int ID_input; cin >> ID_input;

                database.staffaData.cancelDishfromtheTable(_tableID,ID_input);

                do {
                    cout << "\n\n\t\t\t 1. Continue Deleting Another Order " << endl;
                    cout << "\n\t\t\t 2. Turn back Order menu" << endl;
                    cout << "\n\t\t\t 3. Turn back Staff menu" << endl;
                    cout << "\t\t\t 4. Exit program" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> choice;

                    if (choice == 4) exit(0);

                } while (choice != 1 && choice != 2 && choice != 3);

                if (choice == 1) goto delete_order;
                else if (choice == 2) goto orderMenu_start;
                else goto menuStaff_start;
                break;
        case 3:
            std::cout << "Bạn đã chọn số 3.\n";
            break;
        case 4:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "--------------------------------------------- Order ---------------------------------------------------" << endl;
                database.staffaData.displayDishfromtheTable(_tableID);
                
                do {
                    cout << "\n\t\t\t 1. Turn back Order menu" << endl;
                    cout << "\n\t\t\t 2. Turn back Staff menu" << endl;
                    cout << "\t\t\t 3. Exit program" << endl;
                    cout << "\t\t\tPlease Enter Your Choice: ";
                    cin >> choice;

                    if (choice == 3) exit(0);

                } while (choice != 1 && choice != 2);

                if (choice == 1) goto orderMenu_start;
                else goto menuStaff_start;
                break;
            break;
        case 5:
            cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "\n-------------------------------------------Payment-----------------------------------------------------" << endl;
                database.staffaData.payDishfromtheTable(_tableID);
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                break;
            break;
        case 6:
            std::cout << "Bạn đã chọn số 6.\n";
            break;
        case 7:
            std::cout << "Bạn đã chọn số 7.\n";
            break;
        case 8:
            std::cout << "Bạn đã chọn số 8.\n";
            break;
        default:
            std::cout << "Số bạn đã nhập không nằm trong khoảng từ 1 đến 8.\n";
    }
        
}