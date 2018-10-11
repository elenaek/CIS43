#pragma once
#ifndef FINAL_H
#define FINAL_H
//prototype functions
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

bool checkFile(string);
vector<string> parseString(string);
int inputMenu();
int searchActNo(string);
int searchActName(string);
void displayDatabase(string);



static string fName;



static int actSize = 0;
static vector<string> actNo;
static vector<string> actNa;
static vector<string> actBal;


#endif