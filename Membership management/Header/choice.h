/*
* File: choice.h
* Author: Minh Phat
* Date: 5/4/2024
* Description: This file contains all the functions prototypes for program display library.
*/
#ifndef __CHOICE_H
#define __CHOICE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "member.h"

void readFile(MemberNode** memberList, const char* filename);
void writeFile(MemberNode* memberList, const char* filename);
void displayMenu();
void choice(const char  *filename,MemberNode *memberList);
#endif