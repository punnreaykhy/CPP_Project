void checkPrimary(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Number_Testing"<<"checkPrimary";
    h1.close();
    cls();
    int num,state=1;
    cout<<"\t\t<<<<|Primary Number Checker|>>>>\n";
    cout<<"\n\tInput a number: "; cin>>num;

    for(int j=2; j<num; j++){
        if(num%j==0) state=0;
    }
    if(state==1 && num>1) {
        cout<<"\t"<<num<<" is a prime number.\n";
    }else cout<<"\t"<<num<<" is not a prime number.\n";
    cout << "\n\nPress enter to exit..." << endl;
    cin.ignore();
    cin.ignore();
}

void checkPerfectN(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Number_Testing"<<"checkPerfectN";
    h1.close();
    int i,num,sum=0;

    cls();
    cout<<"\t\t<<<<|Perfect Number Checker|>>>>\n";
    cout<<"\n\tInput a number: "; cin>>num;
    for(i=1;i<=num/2;i++){
        if(num%i==0) sum=sum+i;
    }

    if(sum==num && num>0) cout<<"\t"<<num<<" is a perfect number.\n";
    else cout<<"\t"<<num<<" is not a perfect number.\n";

    cout << "\n\nPress enter to exit..." << endl;
    cin.ignore();
    cin.ignore();
}

void checkPalindrome(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Number_Testing"<<"checkPalindrome";
    h1.close();
    cls();
    cout<<"\t\t<<<<|Palindrome Number Checker|>>>>\n";
    int num,reverse=0,remainder,original;
    cout<<"\n\tInput a number: "; cin>>num;
    original=num;

    while(num!=0){
        remainder=num%10;
        reverse=reverse*10 + remainder;
        num=num/10;
    }
    if(reverse==original){
        cout<<"\t"<<original<<" is a palindrome.\n";
    }else cout<<"\t"<<original<<" is not a palindrome.\n";

    cout << "\n\nPress enter to exit..." << endl;
    cin.ignore();
    cin.ignore();
}

void numTestingMENU(){
    int option;
    a:
    cls();
    cout<<"\t\t--------------------------------"<<endl;
    cout<<"\t\t======== Number_Testing ========"<<endl;
    cout<<"\t\t--------------------------------"<<endl;
    cout<<"\t\t| 1. Check Primary Number      |"<<endl;
    cout<<"\t\t| 2. Check Perfect Number      |"<<endl;
    cout<<"\t\t| 3. Check Palindrome Number   |"<<endl;
    cout<<"\t\t================================"<<endl;
    cout<<"\tPlease enter your option (enter:0 ->exit): ";  cin>>option;

    if(option==1){
        checkPrimary();
    }else if(option==2){
        checkPerfectN();
    }else if(option==3){
        checkPalindrome();
    }
    if(option!=0) goto a;
}