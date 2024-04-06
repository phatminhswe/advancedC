/*
* File: member.c
* Author: Minh Phat
* Date: 5/4/2024
* Description: This file contains all the functions/methods for Membership management
*/
#include "member.h"
#include "tree.h"

/*
* Description: Create a new member node with the given member data.
* Input: A Member struct representing the data of the new member.
* Output: A pointer to the newly created MemberNode.
*/
MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

/*
* Description: Prompt the user to input member information and store it in the given member struct.
* Input: A pointer to a Member struct where the input data will be stored.
* Output: A pointer to the same Member struct containing the input data.
*/
Member* input(Member* member) {
    printf("Nhap thong tin cu dan\n");
    printf("Enter UID: ");  scanf("%s", member->uid);
    printf("Enter roomNumber: ");  scanf("%s", member->roomNumber);
    printf("Enter name: ");  scanf("%s", member->name);
    printf("Enter licensePlate: ");  scanf("%s", member->licensePlate);
    return member;
}

/*
* Description: Add a new member to the member list.
* Input: A pointer to a pointer to the head of the member list.
* Output: None.
*/
void addMember(MemberNode** head) {
    Member newMember;
    input(&newMember);

    MemberNode* newNode = createMemberNode(newMember);

    if (newNode == NULL) {
        printf("Failed to create new member node.\n");
        return;
    }

    if (*head == NULL || strcmp(newNode->data.uid, (*head)->data.uid) < 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        MemberNode* current = *head;
        while (current->next != NULL && strcmp(newNode->data.uid, current->next->data.uid) > 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

/*
* Description: Delete a member with the given UID from the member list.
* Input: A pointer to a pointer to the head of the member list and the UID of the member to delete.
* Output: None.
*/
void deleteMember(MemberNode** member, const char* uid) {
    if (*member == NULL) {
        printf("Danh sach rong, khong co thanh vien nao de xoa.\n");
        return;
    }

    MemberNode* current = *member;
    MemberNode* previous = NULL;

    while (current != NULL && strcmp(current->data.uid, uid) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Khong tim thay thanh vien voi UID %s.\n", uid);
        return;
    }

    if (previous == NULL) {
        *member = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Thanh vien voi UID %s da duoc xoa.\n", uid);
}

/*
* Description: Edit the information of a member with the given UID in the member list.
* Input: A pointer to the head of the member list and the updated member data.
* Output: None.
*/
void editMember(MemberNode* member, Member updatedMember) {
    if (member == NULL) {
        printf("Danh sach rong, khong co thanh vien nao de chinh sua.\n");
        return;
    }

    MemberNode* current = member;

  
    while (current != NULL && strcmp(current->data.uid, updatedMember.uid) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Khong tim thay thanh vien voi UID %s.\n", updatedMember.uid);
        return;
    }

   
    strcpy(current->data.roomNumber, updatedMember.roomNumber);
    strcpy(current->data.name, updatedMember.name);
    strcpy(current->data.licensePlate, updatedMember.licensePlate);

    printf("Thanh vien voi UID %s da duoc chinh sua.\n", updatedMember.uid);
}

/*
* Description: Display the list of members in the member list.
* Input: A pointer to the head of the member list.
* Output: None.
*/
void displayMemberList(MemberNode* member) {
    if (member == NULL) {
        printf("Danh sach thanh vien rong.\n");
        return;
    }

    printf("\nDanh sach thanh vien:\n");
    printf("%-20s%-10s%-50s%-20s\n", "UID", "Room", "Name", "License Plate");
    printf("-------------------------------------------------------------\n");

    MemberNode* current = member;
    while (current != NULL) {
        printf("%-20s%-10s%-50s%-20s\n", current->data.uid, current->data.roomNumber, current->data.name, current->data.licensePlate);
        current = current->next;
    }
}

/*
* Description: Search for members with the given license plate in the member list and print their information.
* Input: A pointer to the head of the member list and the license plate to search for.
* Output: None.
*/
void searchByLicensePlate(MemberNode* memberList, const char* licensePlate) {
    if (memberList == NULL) {
        printf("Danh sach thanh vien rong.\n");
        return ;
    }

    MemberNode* current = memberList;
    int found = 0;

    printf("\nThong tin thanh vien voi License Plate %s:\n", licensePlate);
    printf("%-20s%-10s%-50s%-20s\n", "UID", "Room", "Name", "License Plate");
    printf("-------------------------------------------------------------\n");

    while (current != NULL) {
        if (strcmp(current->data.licensePlate, licensePlate) == 0) {
            printf("%-20s%-10s%-50s%-20s\n", current->data.uid, current->data.roomNumber, current->data.name, current->data.licensePlate);
            found = 1; 
        }
        current = current->next;
    }

    if (!found) {
        printf("Khong tim thay thanh vien voi License Plate %s.\n", licensePlate);
    }
}

/*
* Description: Search for members with the given UID in the member list and return their information.
* Input: A pointer to the head of the member list and the UID to search for.
* Output: None.
*/
void searchByUID(MemberNode* memberList, const char* uid) {
   
    printf("\nThong tin thanh vien voi UID %s:\n", uid);
    printf("%-20s%-10s%-50s%-20s\n", "UID", "Room", "Name", "License Plate");
    printf("-------------------------------------------------------------\n");
    
    CenterPoint* root = centerPoint(memberList);

    searchByUIDtree(root, uid);
}
/*
* Description: Search for members with the given UID/licensePlate in the member list and return their information.
* Input: A pointer to the head of the member list and the UID/licensePlate to search for.
* Output: None.
*/
void searchMember( void (*searchFunc) (MemberNode* ,const char*) , MemberNode* memberList, const char* value ){
    searchFunc(memberList,value);
}