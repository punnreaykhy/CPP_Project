
void suit1(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Math_Suite"<<"1+2+3+...+n";
    h1.close();

    int n,sum=0;
    cls();
    cout<<"\t\t<<<<|Suite: 1+2+3+...+n|>>>>\n";
    cout<<"\n\tInput n: ";  cin>>n;
    for(int i=1; i<=n; i++){
        sum=sum+i;
    }
    cout<<"\tResult = "<<sum<<endl;
}

void suit2(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Math_Suite"<<"1+3+5+...+n";
    h1.close();
    int n,sum=0;
    cout<<"\t\t<<<<|Suite: 1+3+5+...+n|>>>>\n";
    cout<<"\n\tInput n: ";  cin>>n;
    for(int i=1; i<=n; i+=2){
        sum=sum+i;
    }
    cout<<"\tResult = "<<sum<<endl;
}

void suit3(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Math_Suite"<<"1^2+2^2+...+n^2";
    h1.close();
    int n,sum=0;
    cout<<"\t\t<<<<|Suite: 1^2 + 2^2 +...+ n^2|>>>>\n";
    cout<<"\n\tInput n: ";  cin>>n;
    for(int i=1; i<=n; i++){
        sum=sum+(i*i);
    }
    cout<<"\tResult = "<<sum<<endl;
}

void suit4(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Math_Suite"<<"sumPrimaryTo_n";
    h1.close();
    int n,sum=0;
    cout<<"\t\t<<<<|Sum all primary numbers in between 1 to n|>>>>\n";
    cout<<"\n\tInput n: ";  cin>>n;
    for(int i=2; i<=n; i++){
        int prime=1;
        for(int j=2;j<i;j++){
            if(i%j==0) prime=0;
        }
        if(prime==1){
            sum=sum+i;
        }
    }
    cout<<"\tResult = "<<sum<<endl;
}

void mathSuiteMENU(){
    int option;
    a:
    cls();
    cout<<"\t\t--------------------------------------------------"<<endl;
    cout<<"\t\t============= Compute_the_Math_Suite ============="<<endl;
    cout<<"\t\t--------------------------------------------------"<<endl;
    cout<<"\t\t| 1. Suite: 1+2+3+...+n                          |"<<endl;
    cout<<"\t\t| 2. Suite: 1+3+5+...+n                          |"<<endl;
    cout<<"\t\t| 3. Suite: 1^2 + 2^2 +...+ n^2                  |"<<endl;
    cout<<"\t\t| 4. Sum all primary numbers in between 1 to n   |"<<endl;
    cout<<"\t\t=================================================="<<endl;
    cout<<"\tPlease enter your option (enter:0 ->exit): ";  cin>>option;

    if(option==1){
        cls();
        suit1();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }else if(option==2){
        cls();
        suit2();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }else if(option==3){
        cls();
        suit3();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }else if(option==4){
        cls();
        suit4();
        cout << "\n\nPress enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }
    if(option!=0) goto a;
}
