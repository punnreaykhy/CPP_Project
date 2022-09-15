#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void cls();                 //this function is used to clear screen for both Win and Unix system
string currentDateTime();   //this function is used to get current time
#include "productManagement.h"
#include "bookManagement.h"
#include "numberTesting.h"
#include "basicMath.h"
#include "mathSuit.h"
#include "numberConverter.h"
void MENU();

int main(){
    MENU();
}

void MENU(){
    int option;
    a:
    cls();
    cout<<"\t\t--------------------------------------"<<endl;
    cout<<"\t\t============ Main_Program ============"<<endl;
    cout<<"\t\t--------------------------------------"<<endl;
    cout<<"\t\t| 1. Product Management              |"<<endl;
    cout<<"\t\t| 2. Book Store Management           |"<<endl;
    cout<<"\t\t| 3. Number Testing                  |"<<endl;
    cout<<"\t\t| 4. Basic Math                      |"<<endl;
    cout<<"\t\t| 5. Math Suite Cumputation          |"<<endl;
    cout<<"\t\t| 6. Number Conversion               |"<<endl;
    cout<<"\t\t======================================"<<endl;
    cout<<"\tPlease enter your option (enter:0 ->exit): ";  cin>>option;

    if(option==1){
        cls();
        prductManagementMENU();
    }else if(option==2){
        cls();
        bookManagementMENU();
    }else if(option==3){
        cls();
        numTestingMENU();
    }else if(option==4){
        cls();
        basicMathMENU();
    }else if(option==5){
        cls();
        mathSuiteMENU();
    }else if(option==6){
        cls();
        numConverterMENU();
    }
    if(option!=0) goto a;
}

void cls(){     //this function is used to clear screen for both Win and Unix system
    system("cls");
    cout<<"\x1b[H\x1b[2J\x1b[3J";    //used for unix clear screen
}

string currentDateTime() {     //this function is used to get current time
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}