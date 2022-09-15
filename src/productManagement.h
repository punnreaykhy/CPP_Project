struct Product{
    string ID;
    string name;
    float price;
    string expDate;
};

void header1(){
    cout<<"\t----------------------------------------------------------------------"<<endl;
    cout<<"\t|  "<<left<<setw(16)<<"Product.ID"<<setw(16)<<"Product.Name"<<setw(16)<<"Price"<<"Product.EXP.Date  |" <<endl;
    cout<<"\t----------------------------------------------------------------------"<<endl;
}

void createProduct(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Product_Management"<<"createProduct";
    h1.close();
    cls();
    Product p;
    fstream f1;
    f1.open("productList.txt", ios::app);
    int n;
    cout<<"\tHow many product you want to create?\t==>"; cin>>n;
    for(int i=1; i<=n; i++){
        cout<<"#"<<i<<" Product\n";
        cout<<"\tEnter product ID: ";                     cin>>p.ID;
        cout<<"\tEnter product name: ";                   cin>>p.name;
        cout<<"\tEnter product price($): ";                  cin>>p.price;
        cout<<"\tEnter product exp.Date(dd.mm.yy): ";     cin>>p.expDate;

        f1<<"\n"<<left<<setw(16)<<p.ID;
        f1<<setw(16)<<p.name;
        f1<<setw(16)<<p.price;
        f1<<p.expDate;
    }
    f1.close();
}

void displayProduct(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Product_Management"<<"displayAllProducts";
    h1.close();
    cls();
    Product p;
    fstream f1;
    f1.open("productList.txt", ios::in);
    header1();
	while(!f1.eof()){
		f1>>p.ID;
		f1>>p.name;
		f1>>p.price;
		f1>>p.expDate;
		cout<<"\t|  "<<left<<setw(16)<<p.ID<<setw(16)<<p.name<<setw(16)<<p.price<<setw(18)<<p.expDate<<"|"<<endl;
	}
    cout<<"\t----------------------------------------------------------------------"<<endl;
	f1.close();
    cout << "Press enter to exit..." << endl;
    cin.ignore();
    cin.ignore();
}

void displayProductByID(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Product_Management"<<"displayProductByID";
    h1.close();
    cls();
    string find;
    loop:
    cout<<"Enter product ID to display (enter:0 ->exit): ";  cin>>find;
    if(find!="0"){
        Product p;
        fstream f1;
        f1.open("productList.txt", ios::in);
        int count=0;
        
        while(!f1.eof()){
            f1>>p.ID;
            if(p.ID==find){
                if(count==0) header1();
                count=1;
                f1>>p.name;
                f1>>p.price;
                f1>>p.expDate;
                cout<<"\t|  "<<left<<setw(16)<<p.ID<<setw(16)<<p.name<<setw(16)<<p.price<<setw(18)<<p.expDate<<"|"<<endl;
            }else{
                f1>>p.ID;
                f1>>p.ID;
                f1>>p.ID;
            }
        }
        cout<<"\t----------------------------------------------------------------------"<<endl;
        f1.close();
        if(count==0){
            cout<<"\nID not found! Please enter again!\n";
            goto loop;
        }

        cout << "Press enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }
}

void deleteProductByID(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Product_Management"<<"deleteProductByID";
    h1.close();
    cls();
    string find;
    loop:
    cout<<"Enter ID of product to delete (enter:0 ->exit): ";    cin>>find;
    if(find!="0"){
        fstream f1,f2;
        Product p;
        f1.open("productList.txt", ios::in);
        f2.open("temp.txt", ios::out);
        int count=0;
        while(!f1.eof()){
            f1>>p.ID;
            f1>>p.name;
            f1>>p.price;
            f1>>p.expDate;

            if(p.ID!=find){
                f2<<"\n"<<left<<setw(16)<<p.ID;
                f2<<setw(16)<<p.name;
                f2<<setw(16)<<p.price;
                f2<<p.expDate;
            }else{
                int a;
                a:
                cout<<"(enter:1 ->delete)__(enter:0 ->exit): ";
                cin>>a;
                if(a==0){
                    f2<<"\n"<<left<<setw(16)<<p.ID;
                    f2<<setw(16)<<p.name;
                    f2<<setw(16)<<p.price;
                    f2<<p.expDate;
                }else if(a==1){
                    cout<<"\n\t\tProduct deleted!\n";
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

        remove("productList.txt");
        rename("temp.txt", "productList.txt");

        if(count==0){
            cout<<"\nID not found! Please enter again!\n";
            goto loop;
        }
    }
}

void updateProductByID(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Product_Management"<<"updateProductByID";
    h1.close();
    cls();
    string find;
    
    loop:
    cout<<"Enter ID of product to update (enter:0 ->exit): ";    cin>>find;
    if(find!="0"){
        fstream f1,f2;
        Product p;
        f1.open("productList.txt", ios::in);
        f2.open("temp.txt", ios::out);
        int count=0;
        while(!f1.eof() && find!="0"){
            f1>>p.ID;
            f1>>p.name;
            f1>>p.price;
            f1>>p.expDate;

            if(p.ID!=find){
                f2<<"\n"<<left<<setw(16)<<p.ID;
                f2<<setw(16)<<p.name;
                f2<<setw(16)<<p.price;
                f2<<p.expDate;
            }else{
                if(count==0) header1();
                count=1;
                int option;
                a:
                cls();
                header1();
                cout<<"\t|  "<<left<<setw(16)<<p.ID<<setw(16)<<p.name<<setw(16)<<p.price<<setw(18)<<p.expDate<<"|"<<endl;
                cout<<"\t----------------------------------------------------------------------"<<endl;
                do{
                    cout<<"1. Edit product ID\n";
                    cout<<"2. Edit product name\n";
                    cout<<"3. Edit product price\n";
                    cout<<"4. Edit product expire date\n";
                    cout<<"Please enter your option (enter:0 ->exit): ";  cin>>option;
                    if(option==1){
                        cout<<"Enter new ID: "; cin>>p.ID;
                    }else if(option==2){
                        cout<<"Enter new name: "; cin>>p.name;
                    }else if(option==3){
                        cout<<"Enter new price($): "; cin>>p.price;
                    }else if(option==4){
                        cout<<"Enter new exp.Date(dd.mm.yy): "; cin>>p.expDate;
                    }
                    if(option>0 && option<5){
                        count=2;    //to check it update or not
                        goto a;
                    }
                }while(option!=0);
                

                f2<<"\n"<<left<<setw(16)<<p.ID;
                f2<<setw(16)<<p.name;
                f2<<setw(16)<<p.price;
                f2<<p.expDate;

                if(count==2){
                    cout<<"\n\t\tProduct updated!\n";
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
        remove("productList.txt");
        rename("temp.txt", "productList.txt");

    }
}

void searchForProduct(){
    fstream h1;
    h1.open("historyOfProgram.txt", ios::app);
    h1<<"\n"<<left<<setw(25)<<currentDateTime()<<setw(20)<<"Product_Management"<<"searchForProduct";
    h1.close();
    cls();
    string find;
    loop:
    cout<<"Enter product info to search (enter:0 ->exit): "; cin>>find;
    if(find!="0"){
        Product p;
        fstream f1;
        f1.open("productList.txt", ios::in);
        int count=0;
        while(!f1.eof()){
            string price;
            f1>>p.ID;
            f1>>p.name;
            f1>>price;
            f1>>p.expDate;
            if(p.ID==find || p.name==find || price==find || p.expDate==find){
                if(count==0) header1();
                count=1;
                cout<<"\t|  "<<left<<setw(16)<<p.ID<<setw(16)<<p.name<<setw(16)<<price<<setw(18)<<p.expDate<<"|"<<endl;
            }
        }
        f1.close();
        cout<<"\t----------------------------------------------------------------------"<<endl;
        if(count==0){
            cout<<"\nInfo not found! Please enter again!\n";
            goto loop;
        }
        cout << "Press enter to exit..." << endl;
        cin.ignore();
        cin.ignore();
    }
    
}

void prductManagementMENU(){
    int option;
    a:
    cls();
    cout<<"\t\t----------------------------------------"<<endl;
    cout<<"\t\t========== Product_Management =========="<<endl;
    cout<<"\t\t----------------------------------------"<<endl;
    cout<<"\t\t| 1. Create product                    |"<<endl;
    cout<<"\t\t| 2. Display all products              |"<<endl;
    cout<<"\t\t| 3. Display a product by ID           |"<<endl;
    cout<<"\t\t| 4. Update a product by ID            |"<<endl;
    cout<<"\t\t| 5. Delete a product by ID            |"<<endl;
    cout<<"\t\t| 6. Search for a product              |"<<endl;
    cout<<"\t\t========================================"<<endl;
    cout<<"\tPlease enter your option (enter:0 ->exit): ";  cin>>option;

    if(option==1){
        createProduct();
    }else if(option==2){
        displayProduct();
    }else if(option==3){
        displayProductByID();
    }else if(option==4){
        updateProductByID();
    }else if(option==5){
        deleteProductByID();
    }else if(option==6){
        searchForProduct();
    }
    if(option!=0) goto a;
}