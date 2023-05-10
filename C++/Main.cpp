#include <bits/stdc++.h>
using namespace std;

class Customer
{

    int id ;
    char name[20], password[20], username[20];

public :


    int getId()
    {
        return id;
    }

    char* getName()
    {
        return name;
    }

    char* getPassword()
    {
        return password;
    }

    char* getUsername()
    {
        return username;
    }


    bool searchId(int val)
    {

        ifstream inFile("Customer.txt", ios::in);

        if(inFile.is_open())
        {
            Customer c1 ;
            while(!inFile.eof())
            {
                inFile.read( (char *)&c1, sizeof(c1) );

                if(c1.getId() == val) return true;
            }

        }
        //    else
        //      cout <<"Cann't be opened the file \n" ;
        inFile.close();

        return false;
    }


    bool validId(double val)
    {
        return val > 0 and int(val)==val and !searchId(val) ;
    }

    void setID() // new user only
    {
        double x ;
        cout << "Enter ID : ";
        cin >> x;


        while(!validId(x))
        {
            cout <<"Invalid Id , please try again \n";
            cout << "Enter ID : ";
            cin >> x;

        }
        id = int(x);
    }


    void setName()
    {
        cout <<"Enter Name : ";
        cin >> name;
    }

    bool validUsername(char val[20])    // search if found same username in the file
    {

        ifstream inFile("Customer.txt", ios::in);

        if(inFile.is_open())
        {
            Customer c1 ;
            while(!inFile.eof())
            {
                inFile.read( (char *)&c1, sizeof(c1) );

                if(strcmp(c1.getUsername(), val)==0 ) return false;
            }
        }
        //   else
        //      cout <<"Cann't be opened the file \n" ;

        inFile.close();

        return true;
    }

    void setUsername( int option )
    {
        if(option == 1) // new user -> check if valid username
        {
            char temp[20];
            cout <<"Enter username : " ;
            cin >> temp;

            while(!validUsername(temp))
            {
                cout <<"Invalid username , please try again \n";
                cout << "Enter username : ";
                cin >> temp;
            }

            for(int i=0; i< 20; i++) username[i]=temp[i];

        }

        else  // old user
        {
            cout << "Enter username : ";
            cin >> username;
        }
    }

    void setPassword()
    {
        cout <<"Enter Password : ";
        cin >> password;
    }


    bool validLogin( char user[20], char pass [20] )
    {
        ifstream inFile("Customer.txt", ios::in);

        if(inFile.is_open())
        {
            Customer c1 ;
            while(!inFile.eof())
            {
                inFile.read( (char *)&c1, sizeof(c1) );

                if(strcmp(c1.getUsername(), user)==0
                and strcmp(c1.getPassword(), pass)==0)
                {
                    cout << "\n\tLogged in Successfully \n\t\tWelcome\n\n";
                    cout << "Id\tname\tusername\tpassword\n";
                    cout << c1.getId() << '\t' << c1.getName() << '\t' <<
                         c1.getUsername() << '\t' << c1.getPassword() << "\n\n";
                    return true;
                }
            }
        }

        //  else
        //     cout <<"Cann't be opened the file \n" ;

         inFile.close();

        return false;
    }

    string decrypted(string s)
    {
        for(int i=0 ; i < 20 ; i++ )
            s[i]+='&';
        return s;
    }

    string incrypted(string s)
    {
        for(int i=0 ; i < 20 ; i++ )
            s[i]-='&';
        return s;
    }
    void printCustomers()
    {
        ifstream inFile("Customer.txt", ios::in);
        if(inFile.is_open())
        {
            Customer c1 ;
            cout <<"ID\tName\tUsername\tpassword\n\n";
            while(!inFile.eof())
            {
                inFile.read((char *)&c1, sizeof(c1));


                string temp  = c1.getPassword();

                if(!inFile.eof())
                    cout <<c1.getId() <<'\t' << c1.getName() <<'\t' <<
                         c1.getUsername() << '\t' << decrypted(temp) << "\n";
            }
        }
        //     else cout <<"Cann't opened this file\n";

        inFile.close();

    }

};


class Employee
{

    int id ;
    char name[20], password[20], username[20];

public :


    int getId()
    {
        return id;
    }

    char* getName()
    {
        return name;
    }

    char* getPassword()
    {
        return password;
    }

    char* getUsername()
    {
        return username;
    }



    // search about id in file of customers
    bool searchId(int val)
    {

        ifstream inFile("Employee.txt", ios::in);

        if(inFile.is_open())
        {
            Employee e1 ;
            while(!inFile.eof())
            {
                inFile.read( (char *)&e1, sizeof(e1) );

                if(e1.getId() == val) return true;
            }

        }
        //  else
        //    cout <<"Cann't be opened the file \n" ;
        inFile.close();

        return false;
    }


    bool validId(double val)
    {
        return val > 0 and int(val)==val and !searchId(val) ;
    }

    void setID() // new user only
    {
        double x ;
        cout << "Enter ID : ";
        cin >> x;


        while(!validId(x))
        {
            cout <<"Invalid Id , please try again \n";
            cout << "Enter ID : ";
            cin >> x;

        }
        id = int(x);
    }


    void setName()
    {
        cout <<"Enter Name : ";
        cin >> name;
    }

    bool validUsername(char val[20])    // search if found same username in the file
    {

        ifstream inFile("Employee.txt", ios::in);

        if(inFile.is_open())
        {
            Employee e1 ;
            while(!inFile.eof())
            {
                inFile.read( (char *)&e1, sizeof(e1) );

                if(strcmp(e1.getUsername(), val)==0 ) return false;
            }
        }
        // else
        //   cout <<"Cann't be opened the file \n" ;

        inFile.close();

        return true;
    }

    void setUsername( int option )
    {
        if(option == 1) // new user -> check if valid username
        {
            char temp[20];
            cout <<"Enter username : " ;
            cin >> temp;

            while(!validUsername(temp))
            {
                cout <<"Invalid username , please try again \n";
                cout << "Enter username : ";
                cin >> temp;
            }

            for(int i=0; i< 20; i++) username[i]=temp[i];

        }

        else  // old user
        {
            cout << "Enter username : ";
            cin >> username;
        }
    }

    void setPassword()
    {
        cout <<"Enter Password : ";
        cin >> password;
    }


    bool validLogin( char user[20], char pass [20] )
    {
        ifstream inFile("Employee.txt", ios::in);

        if(inFile.is_open())
        {
            Employee e1 ;
            while(!inFile.eof())
            {
                inFile.read( (char *)&e1, sizeof(e1) );

                if(strcmp(e1.getUsername(), user)==0
                        and strcmp(e1.getPassword(), pass)==0)
                {
                    cout << "\tLogged in Successfully \n\t\t\tWelcome\n";
                    cout << "Id\tname\tusername\tpassword\n";
                    cout << e1.getId() << '\t' << e1.getName() << '\t' <<
                         e1.getUsername() << '\t' << e1.getPassword() << "\n";
                    return true;
                }
            }
        }
        //  else
        //    cout <<"Cann't be opened the file \n" ;

        inFile.close();

        return false;
    }

    string decrypted(string s)
    {
        for(int i=0 ; i < 20 ; i++ )
            s[i]+='&';
        return s;
    }

    string incrypted(string s)
    {
        for(int i=0 ; i < 20 ; i++ )
            s[i]-='&';
        return s;
    }
    void printEmployee()
    {
        ifstream inFile("Employee.txt", ios::in);
        if(inFile.is_open())
        {
            Employee e1 ;
            cout <<"ID\tName\tUsername\tpassword\n\n";
            while(!inFile.eof())
            {
                inFile.read((char *)&e1, sizeof(e1));


                string temp  = e1.getPassword();

                if(!inFile.eof())
                    cout <<e1.getId() <<'\t' << e1.getName() <<'\t' <<
                         e1.getUsername() << '\t' << decrypted(temp) << "\n";
            }
        }
        //    else cout <<"Cann't opened this file\n";

        inFile.close();

    }

};






class Product
{
    int id, price;
    char name[20];

public:

    void setId()
    {
        cout << "Enter ID : ";
        cin >> id;
    }

    int getId()
    {
        return id;
    }



    void setPrice()
    {
        cout << "Enter price : ";
        cin >> price;
    }

    int getPrice()
    {
        return price;
    }

    void setName()
    {
        cout << "Enter name : ";
        cin >> name;
    }

    char *getName()
    {
        return name;
    }


};

void writeProduct()
{
    fstream out("Product.txt", ios::out | ios::app);
    Product p1;
    char ch;
    do
    {
        p1.setId();
        p1.setName();
        p1.setPrice();

        out.write((char *)&p1, sizeof(p1));
        cout << "if you want to enter another data\tpress Y/N \n";
        cin >> ch;
    }
    while (ch == 'Y' || ch == 'y');
    out.close();
}

void readProduct()
{
    ifstream in("Product.txt", ios::in);

    if (in.is_open())
    {
        Product p2;
        cout << "Id\tName\tPrice\n";
        while (!in.eof())
        {
            in.read((char *)&p2, sizeof(p2));
            if (!in.eof())
                cout << p2.getId() << '\t' << p2.getName() << '\t' << p2.getPrice() << "\n";
        }
    }
    //else
    //   cout << "Can't open the file \n";

    in.close();
}

void searchProduct()
{
    ifstream in2("Product.txt", ios::in);

    if (in2.is_open())
    {
        Product p3;
        bool found = false;
        char str[20];

        cout << "Enter name to search for : ";
        cin >> str;

        in2.read((char *)&p3, sizeof(p3));
        while (!in2.eof())
        {
            if (strcmp(str, p3.getName()) == 0)
            {
                cout << p3.getId() << '\t' << p3.getName() << '\t' << p3.getPrice() << "\n";
                found = true;
                break;
            }

            in2.read((char *)&p3, sizeof(p3));
        }

        if (!found)
            cout << "Name not found\n";

        in2.close();
    }
    // else
    //     cout << "Cannot open this file\n";
}

void updateProduct()
{
    Product p4;
    fstream f("Product.txt", ios::in | ios::out);
    if (f.is_open())
    {
        char str[20];
        cout << "Enter the product name to update his record : ";
        cin >> str;
        bool found = false;
        while (!f.eof())
        {
            f.read((char *)&p4, sizeof(p4));

            if (strcmp(str, p4.getName()) == 0)
            {
                p4.setPrice();
                 int curpos = f.tellg(), stusize = sizeof(p4);

                f.seekp(curpos - stusize, ios::beg);
                f.write((char *)&p4, sizeof(p4));
                found = true;
                break;
            }
        }
        f.close();
        if (!found)
            cout << "Product name does not exist.\n";
    }
}

void deleteRecord()
{
    fstream in("Product.txt", ios::in);
    ofstream out("Product Temp.txt", ios::out);
    if (in.is_open())
    {
        Product p5;

        int num;
        cout << "Enter the id of product to delete his record : ";
        cin >> num;

        while (in.read((char *)&p5, sizeof(p5)))
            if (num!=p5.getId())
                out.write((char *)&p5, sizeof(p5));

        in.close();
        out.close();
        remove("Product.txt");
        rename("Product Temp.txt", "Product.txt");
    }
}


int main()
{

    int ch;
    cout << "1.customer\t2.employee\nEnter Your choise : " ;
    cin >> ch;
    cout <<"\n";

    if(ch==1)  // customer
    {
        int totalPrice =0;
        int op;
        cout <<"1.log in\t2.sign up\nEnter Your choise : ";
        cin >> op;

        cout <<"\n";
        Customer c1;

        if(op==1)  // old user
        {
            c1.setUsername(2);
            c1.setPassword();

            while(!c1.validLogin(c1.getUsername(), c1.getPassword()))
            {
                cout << "Invalid log in , please try again :\n";
                c1.setUsername(2);
                c1.setPassword();
            }
        }

        else   // new user
        {
            c1.setID();
            c1.setName();
            c1.setUsername(1);
            c1.setPassword();

            ofstream i1("Customer.txt", ios::out | ios::app);
            i1.write( (char*)&c1, sizeof(c1));
            i1.close();

        }


        cout << "\nMenu for our products :\n\n";

        char con='Y';
        ofstream out("Sales.txt", ios::out ); // products that user buys it

        do
        {

            readProduct();

            int ID;
            cout <<"\nEnter id of the product that you want to buy it : " ;
            cin >> ID;


            ifstream in2("Product.txt", ios::in);
            if(in2.is_open())
            {
                Product p2 ;
                while(!in2.eof())
                {

                    in2.read((char *)&p2, sizeof(p2));

                    if(in2.eof())  break;

                    if(ID==p2.getId())
                    {
                        totalPrice+=p2.getPrice();
                        out.write( (char *)&p2, sizeof(p2));
                        break;
                    }

                }
            }
            //    else cout <<"Cann't open the file \n";


            in2.close();

            cout << "\nDo you want to buy other products  [ Y/N ] : ";
            cin >> con;

        }
        while(con=='Y');
        out.close();

        cout <<"\nYour sales :\n";

        ifstream In("Sales.txt", ios::in);
        if(In.is_open())
        {
            Product p;
            cout <<"ID\tName\tPrice : \n\n" ;

            while(!In.eof())
            {
                In.read( (char *)&p, sizeof(p) );
                if(!In.eof())
                    cout << p.getId() << "\t" << p.getName() << '\t' << p.getPrice() << "\n";
            }
            cout <<"\nTotal Price : " << totalPrice << "\n";
        }

        else cout <<"the file is empty \n";

        In.close();


        int want = 0;
        cout <<"\nif you want to know all users : press 1 ";
        cin >> want ;
        if(want)
        {
            Customer C;
            C.printCustomers();
        }
    }


    else  // employee
    {


        int op;
        cout <<"1.log in\t2.sign up\nEnter Your choise : ";
        cin >> op;

        cout <<"\n";
        Employee e1;

        if(op==1)  // old user
        {
            e1.setUsername(2);
            e1.setPassword();

            while(!e1.validLogin(e1.getUsername(), e1.getPassword()))
            {
                cout << "Invalid log in , please try again :\n";
                e1.setUsername(2);
                e1.setPassword();
            }
        }

        else   // new user
        {
            e1.setID();
            e1.setName();
            e1.setUsername(1);
            e1.setPassword();

            ofstream i1("Employee.txt", ios::out | ios::app);
            i1.write( (char*)&e1, sizeof(e1));
            i1.close();

        }

        char cn='Y';

        do
        {
            int opt;

            cout << "\n1.add new products \n";
            cout << "2.search about product by name  \n";
            cout << "3.know all products \n";
            cout << "4.update price of any product by name \n";
            cout << "5.delete any product by id \n";
            cout << "6.exit\n";
            cout << "7.know all Employees \n\n";
            cout << "Enter Your choice : \n";
            cin >> opt;



            if(opt==1)  // writeProduct
            {
                writeProduct();
                cout << "\n";
            }
            else if(opt==2)
            {
                searchProduct();
                cout << "\n";
            }
            else if(opt==3)
            {
                readProduct();
                cout << "\n";
            }
            else if(opt==4)
            {
                updateProduct();
                cout << "\n";
            }
            else if(opt==5)
            {
                deleteRecord();
            }
            else if(opt==7)
            {
                Employee e;
                e.printEmployee();
            }
            else
             return 0;

            cout <<"Do you want to do anything more : [ Y/N ] \n";
            cin >> cn;


        }
        while( cn=='Y');

    }

    return 0;
}
