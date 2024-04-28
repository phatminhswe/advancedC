/*
* File: program.h
* Author: Minh Phat
* Date: 18/04/2024
* Description: This file is a Menu header file that program is used for managing students of school
*/

#ifndef _MENU_H
#define _MENU_H
#include <ostream>
#include <fstream>
#include "student.h"

using namespace std;

void program(list <Student>& database);

void insert(list <Student>& database);

void edit_detail (list<Student>::iterator it);
void modify (list <Student>& database, short int ID_input);

void deletee (list <Student>& database, short int ID_input);

void search_by_id_to_show(list <Student> database, short int ID_input);
void search_by_name_to_show(list <Student> database, string name_input);
void search_by_name(list <Student> database, string name_input); 

bool cmpName(const Student &a, const Student &b);
bool cmpMath(const Student &a, const Student &b);
bool cmpPhysic(const Student &a, const Student &b);
bool cmpChemical(const Student &a, const Student &b);
bool cmpAverScore(const Student& a, const Student &b);

void sort_name(list <Student> &database);
void sort_math_score(list <Student> &database);
void sort_physic_score(list <Student> &database);
void sort_mechical_score(list <Student> &database);
void sort_average_score(list <Student> &database);

void print_list(list <Student> database);

void saveCSV(list <Student> &database);

#endif
