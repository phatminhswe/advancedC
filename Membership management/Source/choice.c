/*
* File: choice.c
* Author: Minh Phat
* Date: 5/4/2024
* Description: This file contains all the functions/methods for program display
*/
#include "choice.h"

/*
* Description: Read member data from a file and populate the member list.
* Input: A pointer to a pointer to the head of the member list and the filename of the file to read from.
* Output: None.
*/
void readFile(MemberNode** memberList, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong mo duoc file %s de doc.\n", filename);
        return;
    }

    char line[100]; 
    Member member;
    while (fgets(line, sizeof(line), file) != NULL) {
        
        if (sscanf(line, "%[^,],%[^,],%[^,],%s", member.uid, member.roomNumber, member.name, member.licensePlate) == 4) {
          
            MemberNode* newNode = createMemberNode(member);
            if (newNode == NULL) {
                printf("Failed to create new member node.\n");
                fclose(file);
                return;
            }

            if (*memberList == NULL) {
                *memberList = newNode;
            } else {
                MemberNode* current = *memberList;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = newNode;
                //p
            }
        }
    }

    fclose(file);
    printf("Du lieu da duoc doc tu file %s.\n", filename);
}

/*
* Description: Write member data from the member list to a file.
* Input: A pointer to the head of the member list and the filename of the file to write to.
* Output: None.
*/
void writeFile(MemberNode* memberList, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong mo duoc file %s de ghi.\n", filename);
        return;
        //h
    }

    MemberNode* current = memberList;
    while (current != NULL) {
        fprintf(file,"%s,%s,%s,%s\n", current->data.uid, current->data.roomNumber, current->data.name, current->data.licensePlate);
        current = current->next;
    }

    fclose(file);
    printf("Du lieu da duoc ghi vao file %s.\n", filename);
}

/*
* Description: Display the main menu of the program.
* Input: None.
* Output: None.
*/
void displayMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Them thanh vien\n");
    printf("2. Xoa thanh vien\n");
    printf("3. Chinh sua thong tin thanh vien\n");
    printf("4. Display\n");
    printf("5. Tim kiem bang uid\n");
    printf("6. Tim kiem bang licensePlate\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
    //a
}

void choice(const char  *filename,MemberNode *memberList){

    readFile(&memberList,filename);

    int choice;
    char uid[20];
    char licensePlate[20];
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMember(&memberList);
                break;
            case 2:
                printf("Nhap UID cua thanh vien can xoa: ");
                scanf("%s", uid);
                deleteMember(&memberList, uid);
                break;
            case 3:
                {
                    Member updatedMember;
                    printf("Nhap UID cua thanh vien can chinh sua: ");
                   	
                    input(&updatedMember);
                    editMember(memberList, updatedMember);
                }
                break;
            case 4:
                displayMemberList(memberList);
                break;   
            
            case 5:
                printf("Nhap UID cua thanh vien can tim: ");
                scanf("%s", uid);
                searchMember(searchByUID,memberList,uid);
                
                break;
            case 6:
                printf("Nhap License Plate cua thanh vien can tim: ");
                scanf("%s", licensePlate);
                searchMember(searchByLicensePlate,memberList,licensePlate);
                break;
             
            default:
                printf("Thoat.\n");
                break;
        }
    } while (choice != 7);

    writeFile(memberList,filename); //t
    
    MemberNode* current = memberList;
    while (current != NULL) {
        MemberNode* next = current->next;
        free(current);
        current = next;
    }
}