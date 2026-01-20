#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<cstdio>
#include"Customer.h"
#include"Order.h"
#include"Employee.h"
using namespace std;


int main()
{
    Customer c;
    int choice;
    while (1)
    {
    	system("cls");
        cout << "\tWelcome to SUPERCART";

        cout << "\n\n\n1)SIGNUP WITH SUPERCART\n";
        cout << "2)LOGIN \n3)EXIT\n\n";
        cout << "Enter your choice\t";
        cin >> choice;

        // Switch Cases
        switch (choice) {

            // For Signup Function
        case 1: {
        	system("cls");
            c.signup();
            break;
        }

              // For Login Function
        case 2: {
        	int a=0;
            a = c.login();
            if(a == 1)
            {
            	placeorder();
			}
			if(a == 2)
			{
				admin_emp();
			}
			if(a == 3)
			{
				admin_menu();
			}
            break;
        }
        case 3: {
            cout << "Thankyou for visiting SUPERCART";
            exit(1);
        }
        default: {
            cout << "\nEnter a valid choice\n\n";
            break;
        }
        }

    }
    return 1;

}

