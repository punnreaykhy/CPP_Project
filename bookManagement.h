struct Book{
    string ID,ISBN,title,author_name;
    int published_year;
    float price;
};

void header(){
    cout<<"\t-----------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t|  "<<left<<setw(16)<<"ID"<<setw(16)<<"ISBN"<<setw(16)<<"Title"<<setw(16)<<"Author_Name"<<setw(19)<<"Published_Year"<<"Price   |" <<endl;
    cout<<"\t-----------------------------------------------------------------------------------------------"<<endl;
}

void createBook(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Book_Management"<<"createBook";
    h1.close();
    cls();
    Book b;
    fstream f1;
    f1.open("bookList.txt", ios::app);
    int n;
    cout<<"\tHow many book you want to create?\t==>"; cin>>n;
    for(int i=1; i<=n; i++){
        cout<<"#"<<i<<" Book\n";
        cout<<"\tEnter book ID: ";                     cin>>b.ID;
        cout<<"\tEnter book ISBN: ";                   cin>>b.ISBN;
        cout<<"\tEnter book title: ";                  cin>>b.title;
        cout<<"\tEnter book author_name: ";            cin>>b.author_name;
        cout<<"\tEnter book published_year: ";         cin>>b.published_year;
        cout<<"\tEnter book price($): ";               cin>>b.price;

        f1<<"\n"<<left<<setw(16)<<b.ID;
        f1<<setw(16)<<b.ISBN;
        f1<<setw(16)<<b.title;
        f1<<setw(16)<<b.author_name;
        f1<<setw(19)<<b.published_year;
        f1<<b.price;
    }
    f1.close();
}

void displayBook(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Book_Management"<<"displayBook";
    h1.close();
    cls();
    Book b;
    fstream f1;
    f1.open("bookList.txt", ios::in);
    header();
	while(!f1.eof()){
		f1>>b.ID;
		f1>>b.ISBN;
		f1>>b.title;
		f1>>b.author_name;
		f1>>b.published_year;
		f1>>b.price;
		cout<<"\t|  "<<left<<setw(16)<<b.ID<<setw(16)<<b.ISBN<<setw(16)<<b.title<<setw(16)<<b.author_name<<setw(19)<<b.published_year<<setw(8)<<b.price<<"|"<<endl;
	}
    cout<<"\t-----------------------------------------------------------------------------------------------"<<endl;

	f1.close();
    cout << "Press enter to exit..." << endl;
    cin.ignore();
    cin.ignore();
}

void deleteBookByID(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Book_Management"<<"deleteBookByID";
    h1.close();
    cls();
    string find;
    loop:
    cout<<"Enter ID of book to delete (enter:0 ->exit): ";    cin>>find;
    if(find!="0"){
        fstream f1,f2;
        Book b;
        f1.open("bookList.txt", ios::in);
        f2.open("temp.txt", ios::out);
        int count=0;
        while(!f1.eof()){
            f1>>b.ID;
            f1>>b.ISBN;
            f1>>b.title;
            f1>>b.author_name;
            f1>>b.published_year;
            f1>>b.price;

            if(b.ID!=find){
                f2<<"\n"<<left<<setw(16)<<b.ID;
                f2<<setw(16)<<b.ISBN;
                f2<<setw(16)<<b.title;
                f2<<setw(16)<<b.author_name;
                f2<<setw(16)<<b.published_year;
                f2<<b.price;
            }else{
                int a;
                a:
                cout<<"(enter:1 ->delete)__(enter:0 ->exit): ";
                cin>>a;
                if(a==0){
                    f2<<"\n"<<left<<setw(16)<<b.ID;
                    f2<<setw(16)<<b.ISBN;
                    f2<<setw(16)<<b.title;
                    f2<<setw(16)<<b.author_name;
                    f2<<setw(16)<<b.published_year;
                    f2<<b.price;
                }else if(a==1){
                    cout<<"\n\t\tBook deleted!\n";
                    cout << "Press enter to exit..." << endl;
                    cin.ignore();
                    cin.ignore();
                }
                if(a<0 || a>1) goto a;
                count=1;
            }
        }
        f1.close();
        f2.close();

        remove("bookList.txt");
        rename("temp.txt", "bookList.txt");

        if(count==0){
            cout<<"\nID not found! Please enter again!\n";
            goto loop;
        }
    }
}

void updateBookByID(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Book_Management"<<"updateBookByID";
    h1.close();
    cls();
    string find;
    
    loop:
    cout<<"Enter ID of book to update (enter:0 ->exit): ";    cin>>find;
    if(find!="0"){
        fstream f1,f2;
        Book b;
        f1.open("bookList.txt", ios::in);
        f2.open("temp.txt", ios::out);
        int count=0;
        while(!f1.eof() && find!="0"){
            f1>>b.ID;
            f1>>b.ISBN;
            f1>>b.title;
            f1>>b.author_name;
            f1>>b.published_year;
            f1>>b.price;

            if(b.ID!=find){
                f2<<"\n"<<left<<setw(16)<<b.ID;
                f2<<setw(16)<<b.ISBN;
                f2<<setw(16)<<b.title;
                f2<<setw(16)<<b.author_name;
                f2<<setw(16)<<b.published_year;
                f2<<b.price;
            }else{
                count=1;
                int option;
                a:
                cls();
                header();
                cout<<"\t|  "<<left<<setw(16)<<b.ID<<setw(16)<<b.ISBN<<setw(16)<<b.title<<setw(16)<<b.author_name<<setw(19)<<b.published_year<<setw(8)<<b.price<<"|"<<endl;
                cout<<"\t-----------------------------------------------------------------------------------------------"<<endl;
                do{
                    cout<<"1. Edit book ID\n";
                    cout<<"2. Edit book ISBN\n";
                    cout<<"3. Edit book title\n";
                    cout<<"4. Edit book author name\n";
                    cout<<"5. Edit book published year\n";
                    cout<<"6. Edit book price\n";
                    cout<<"Please enter your option (enter:0 ->exit): ";  cin>>option;
                    if(option==1){
                        cout<<"Enter new ID: "; cin>>b.ID;
                    }else if(option==2){
                        cout<<"Enter new ISBN: "; cin>>b.ISBN;
                    }else if(option==3){
                        cout<<"Enter new title: "; cin>>b.title;
                    }else if(option==4){
                        cout<<"Enter new author name: "; cin>>b.author_name;
                    }else if(option==5){
                        cout<<"Enter new published year: "; cin>>b.published_year;
                    }else if(option==6){
                        cout<<"Enter new price($): "; cin>>b.price;
                    }
                    if(option>0 && option<7){
                        count=2;    //to check it's update or not
                        goto a;
                    }
                }while(option!=0);
                
                f2<<"\n"<<left<<setw(16)<<b.ID;
                f2<<setw(16)<<b.ISBN;
                f2<<setw(16)<<b.title;
                f2<<setw(16)<<b.author_name;
                f2<<setw(16)<<b.published_year;
                f2<<b.price;

                if(count==2){
                    cout<<"\n\t\tBook updated!\n";
                    cout << "Press enter to exit..." << endl;
                    cin.ignore();
                    cin.ignore();
                }

            }
        }
        f1.close();
        f2.close();

        if(count==0){
            cout<<"\nID not found! Please enter again!\n";
            goto loop;
        }
        remove("bookList.txt");
        rename("temp.txt", "bookList.txt");

    }
}

void bookManagementMENU(){
    int option;
    a:
    cls();
    cout<<"\t\t-------------------------------------"<<endl;
    cout<<"\t\t========== Book_Management =========="<<endl;
    cout<<"\t\t-------------------------------------"<<endl;
    cout<<"\t\t| 1. Create book                    |"<<endl;
    cout<<"\t\t| 2. Display all books              |"<<endl;
    cout<<"\t\t| 3. Update a book by ID            |"<<endl;
    cout<<"\t\t| 4. Delete a book by ID            |"<<endl;
    cout<<"\t\t====================================="<<endl;
    cout<<"\tPlease enter your option (enter:0 ->exit): ";  cin>>option;

    if(option==1){
        createBook();
    }else if(option==2){
        displayBook();
    }else if(option==3){
        updateBookByID();
    }else if(option==4){
        deleteBookByID();
    }
    if(option!=0) goto a;
}