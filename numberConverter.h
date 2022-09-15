
void base2to10(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Number_Converter"<<"base2to10";
    h1.close();

    cout<<"\t\t<<<<|Base2 to Base10 Converter|>>>>\n";
    int b2NUM,b10NUM=0,base=1,remainder;

    cout<<"\n\tInput a base2 number: ";   cin>>b2NUM;

    while(b2NUM!=0){
        remainder=b2NUM%10;
        b10NUM=b10NUM+remainder*base;
        b2NUM=b2NUM/10;
        base=base*2;
    }
    cout<<"\tThe base10 number is "<<b10NUM<<endl;
}

void base8to10(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Number_Converter"<<"base8to10";
    h1.close();
    cout<<"\t\t<<<<|Base8 to Base10 Converter|>>>>\n";
    int b8NUM,b10NUM=0,base=1,remainder;

    cout<<"\n\tInput a base8 number: ";   cin>>b8NUM;

    while(b8NUM!=0){
        remainder=b8NUM%10;
        b10NUM=b10NUM+remainder*base;
        b8NUM=b8NUM/10;
        base=base*8;
    }
    cout<<"\tThe base10 number is "<<b10NUM<<endl;
}

void base10to16(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Number_Converter"<<"base10to16";
    h1.close();
    int b10NUM;
    char hex[]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string b16NUM;
    cout<<"\t\t<<<<|Base10 to Base16 Converter|>>>>\n";
    cout<<"\n\tInput a base10 number: ";   cin>>b10NUM;


    while(b10NUM!=0){
        b16NUM.push_back(hex[b10NUM%16]);
        b10NUM=b10NUM/16;
    }
    reverse(b16NUM.begin(),b16NUM.end());
    cout<<"\tThe base16 number is "<<b16NUM<<endl;
}

void base10to2(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Number_Converter"<<"base10to2";
    h1.close();
    int b10NUM;
    stack<int> b2NUM;

    cout<<"\t\t<<<<|Base10 to Base2 Converter|>>>>\n";
    cout<<"\n\tInput a base10 number: ";   cin>>b10NUM;

    while(b10NUM!=0){
        b2NUM.push(b10NUM%2);
        b10NUM=b10NUM/2;
    }
    cout<<"\tThe base2 number is ";
    while (!b2NUM.empty()) {
        cout <<b2NUM.top();
        b2NUM.pop();
    }
    cout<<endl;
}

void base10to8(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Number_Converter"<<"base10to8";
    h1.close();
    int b10NUM;
    stack<int> b8NUM;

    cout<<"\t\t<<<<|Base10 to Base8 Converter|>>>>\n";
    cout<<"\n\tInput a base10 number: ";   cin>>b10NUM;

    while(b10NUM!=0){
        b8NUM.push(b10NUM%8);
        b10NUM=b10NUM/8;
    }
    cout<<"\tThe base8 number is ";
    while (!b8NUM.empty()) {
        cout <<b8NUM.top();
        b8NUM.pop();
    }
    cout<<endl;
}

void numConverterMENU(){
    int option;
    a:
    cls();
    cout<<"\t\t----------------------------------"<<endl;
    cout<<"\t\t======== Number_Converter ========"<<endl;
    cout<<"\t\t----------------------------------"<<endl;
    cout<<"\t\t| 1. Base 2 to Base 10           |"<<endl;
    cout<<"\t\t| 2. Base 10 to Base 2           |"<<endl;
    cout<<"\t\t| 3. Base 8 to Base 10           |"<<endl;
    cout<<"\t\t| 4. Base 10 to Base 8           |"<<endl;
    cout<<"\t\t| 5. Base 10 to Base 16          |"<<endl;
    cout<<"\t\t=================================="<<endl;
    cout<<"\tPlease enter your option (enter:0 ->exit): ";  cin>>option;

    if(option==1){
        cls();
        base2to10();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }else if(option==2){
        cls();
        base10to2();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }else if(option==3){
        cls();
        base8to10();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }else if(option==4){
        cls();
        base10to8();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }else if(option==5){
        cls();
        base10to16();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }
    if(option!=0) goto a;
}
