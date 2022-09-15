void summation(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Basic_Calculator"<<"summation";
    h1.close();
    float num1,num2,result;
    cls();
    cout<<"\t\t<<<<|SUMMATION|>>>>\n";
    cout<<"\t\t#1number + #2number\n";
    cout<<"\n\tEnter #1number: "; cin>>num1;
    cout<<"\tEnter #2number: "; cin>>num2;
    result=num1+num2;
    cout<<"\t"<<num1<<" + "<<num2<<" = "<<result<<endl;
}

void subtraction(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Basic_Calculator"<<"subtraction";
    h1.close();
    float num1,num2,result;
    cls();
    cout<<"\t\t<<<<|SUBTRACTION|>>>>\n";
    cout<<"\t\t#1number - #2number\n";
    cout<<"\n\tEnter #1number: "; cin>>num1;
    cout<<"\tEnter #2number: "; cin>>num2;
    result=num1-num2;
    cout<<"\t"<<num1<<" - "<<num2<<" = "<<result<<endl;
}

void multiplication(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Basic_Calculator"<<"multiplication";
    h1.close();
    float num1,num2,result;
    cls();
    cout<<"\t\t<<<<|MULTIPLICATION|>>>>\n";
    cout<<"\t\t#1number x #2number\n";
    cout<<"\n\tEnter #1number: "; cin>>num1;
    cout<<"\tEnter #2number: "; cin>>num2;
    result=num1*num2;
    cout<<"\t"<<num1<<" x "<<num2<<" = "<<result<<endl;
}

void division(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Basic_Calculator"<<"division";
    h1.close();
    float num1,num2,result;
    cls();
    cout<<"\t\t<<<<|DIVISION|>>>>\n";
    cout<<"\t\t#1number / #2number\n";
    cout<<"\n\tEnter #1number: "; cin>>num1;
    cout<<"\tEnter #2number: "; cin>>num2;
    result=num1/num2;
    cout<<"\t"<<num1<<" / "<<num2<<" = "<<result<<endl;
}

void basicMathMENU(){
    int option;
    a:
    cls();
    cout<<"\t\t---------------------------------------"<<endl;
    cout<<"\t\t======== Basic_Math_Calculator ========"<<endl;
    cout<<"\t\t---------------------------------------"<<endl;
    cout<<"\t\t| 1. Summation(+)                     |"<<endl;
    cout<<"\t\t| 2. Subtraction(-)                   |"<<endl;
    cout<<"\t\t| 3. Multiplication(x)                |"<<endl;
    cout<<"\t\t| 4. Division(/)                      |"<<endl;
    cout<<"\t\t======================================="<<endl;
    cout<<"\tPlease enter your option (enter:0 ->exit): ";  cin>>option;

    if(option==1){
        summation();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }else if(option==2){
        subtraction();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }else if(option==3){
        multiplication();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }else if(option==4){
        division();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }
    if(option!=0) goto a;
}