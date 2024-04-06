/*
* File: member.h
* Author: Minh Phat
* Date: 5/4/2024
* Description: This file contains all the functions prototypes for Membership management library.
*/
#ifndef __MEMBER_H
#define __MEMBER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Member {
    char uid[20]; 
    char roomNumber[10];
    char name[50];
    char licensePlate[20]; 
} Member;

typedef struct MemberNode {
    Member data;
    struct MemberNode* next;
} MemberNode;

MemberNode* createMemberNode(Member member);
Member* input(Member* member);
void addMember(MemberNode** head);
void deleteMember(MemberNode** member, const char* uid);
void editMember(MemberNode* member, Member updatedMember);
void displayMemberList(MemberNode* member);
void searchByLicensePlate(MemberNode* memberList, const char* licensePlate);
void searchByUID(MemberNode* memberList, const char* uid);
void searchMember( void (*searchFunc) (MemberNode* ,const char*) , MemberNode* memberList, const char* value );
#endif