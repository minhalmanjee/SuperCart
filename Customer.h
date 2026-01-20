#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<cstdio>
using namespace std;


class Customer {
protected:
    char fname[20], lname[20], email[25], pass[20], pass2[20], mobile[11], gender[7];
    int x, i, k, error = 0;
public:
    Customer()
    {
        strcpy(fname, "no fname");      //incase data doesnot store these values will initialize.
        strcpy(lname, "no lname");
        strcpy(email, "no email");
        strcpy(mobile, "no num");
        strcpy(gender, "no gen");
        strcpy(pass, "no pass");
        strcpy(pass2, "no pass2");

    }
    void getdata()
    {
        cout << "\tFOR SIGNING UP PLEASE FILL THE FORM BELOW\n";
        cout << "Enter Your First Name :";
        cin >> fname;
        cout << "\nEnter Your Last Name :";
        cin >> lname;
        this->emailvalid(); //email validation
        int flag = 1;       //password validation
        Passvalid();
        do
        {
            cout << "\nConfirm Password : ";
            cin.getline(pass2, 20);
            if (strcmp(pass, pass2) == 0)
                flag = 0;
        } while (flag != 0);
        cout << "\nThe Passwords match";
        Numvalid();     //number validation
        cout << "\nEnter your gender(male or female): ";
        cin >> gender;
        do {
            int k = 1;
            if (strcmp(gender, "male") == 0)
            {
                k--;
                break;
            }
            if (strcmp(gender, "female") == 0)
            {
                k--;
                break;
            }
            cout << "\nEnter a valid gender: ";
            cin >> gender;
        } while (k > 0);
   


        cout << "\n\n\n******************Your account has been successfully created*****************\n\n\n";


    }
    void emailvalid()
    {
        char tempmail[25]; int j, count = 0;
        cout << "\nEnter your email id: ";
        do{
            cin.getline(tempmail, 25);
            for (j = 0; tempmail[j] != '\0'; j++)
            {
                if (tempmail[j] == '@' || tempmail[j] == '.')
                    count++;
            }
        } while (count < 2);
        strcpy(email, tempmail);
    }

    void Passvalid()
    {
        int i, number, special, capital, sm;
        number = 0;
        special = 0;
        capital = 0;
        sm = 0;
        puts("Your Password must contain\n an uppercase\n a lowercase\n a number\n a special char \n");
        puts("Enter Password : ");
        while (number == 0 || special == 0 || capital == 0 || sm == 0 || strlen(pass) < 8)
        {
            cin.getline(pass, 20);

            for (i = 0; pass[i] != '\0'; i++)
            {
                if (pass[i] >= '0' && pass[i] <= '9')
                    number = 1;
                if (pass[i] >= 'a' && pass[i] <= 'z')
                    sm = 1;
                if (pass[i] >= 'A' && pass[i] <= 'Z')
                    capital = 1;
                if (pass[i] == '!' || pass[i] == '@' || pass[i] == '#' || pass[i] == '$' || pass[i] == '%' || pass[i] == '*')
                    special = 1;
            }

        }

    }

    void Numvalid()
    {
        int c = 0;
        do
        {
            c = 0;
            cout << "\nEnter mobile number : ";
            cin >> mobile;
            if (strlen(mobile) != 11)
            {
                c++;
                printf("Enter correct 11 digit contact number \n");
            }
            for (k = 0; k < 11; k++)
            {
                if (mobile[k] < '0' && mobile[k]>'9')
                {
                    c++;
                    printf("invalid number\n");
                    break;
                }
            }

        } while (c > 0);
    }

    void signup()
    {
        system("cls");
        getdata();
        store();
    }

    int login()
    {
        system("cls");
        cout << "\n\n\tTO LOG IN TO YOUR SUPERCART ACCOUNT PLEASE ENTER YOUR \n";
        char logemail[25], logpass[20];
        int i;
        ifstream fin("Customersignup.dat", ios::binary | ios::in);
        cout << "\n Email: ";
        cin >> logemail;
        cout << "\n Password: ";
        cin >> logpass;
        while (fin.read((char*)this, sizeof(*this)))
        {
            if (strcmp(logemail, email) == 0 && strcmp(logpass, pass2) == 0)
            {
                printf("\n\n\n**********you are successfully logged in*********** ");
                return 1;
						break;
        	}
        }
        if (strcmp(logemail, "Admin") == 0 && strcmp(logpass, "AdminPanel786!") == 0)
        {
            system("cls");
            int atc = 0;
            cout << "\n\n\n ADMIN MENU\n\n\n";
            cout << "1. EMPLOYEE DATABASE";
            cout << "\n2. STOCK DATABASE";
            cout << "\n3. Exit";
            cout << "\n\n Your Choice : ";
            cin >> atc;
            switch (atc)
            {
            case 1: {
               return 2;
                break;
            }
            case 2: {
				return 3;
                break;
            }
            case 3: {
                exit(1);
                break;
            }
            default: {
                cout << "\nEnter a valid choice : ";
                break;
            }
            }
        }
    }

    void store()
    {
        ofstream fout("Customersignup.dat", ios::binary | ios::app);
        fout.write((char*)this, sizeof(*this));
    }
};


