/*
* File: choice.h
* Author: Minh Phat
* Date: 5/4/2024
* Description: This file contains all the functions prototypes for search library.
*/
#ifndef __TREE_H
#define __TREE_H
#include "member.h"
typedef struct Membertree {
    char uid[20]; 
    char roomNumber[10];
    char name[50];
    char licensePlate[20]; 
} Membertree;

typedef struct CenterPoint {
    Membertree value;
    struct CenterPoint *left;
    struct CenterPoint *right;
} CenterPoint;

CenterPoint *buildTree(MemberNode* head , int start, int end);
CenterPoint *centerPoint(MemberNode *head);
CenterPoint *binarySearch(CenterPoint *root,const char* value) ;
void searchByUIDtree(CenterPoint* root, const char* uid);

#endif