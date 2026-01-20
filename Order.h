#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<cstdio>
using namespace std;



class product
    {protected:
        int pno, pq;
        char name[50];
        float price, qty, tax, dis;
        public:
            void create_product()
            {
                cout << "\nPlease Enter The SKU of The Product ";
                cin >> pno;
                pno = unisku(pno);
                cout << "\n\nPlease Enter The Name of The Product ";
                cin>>gets(name);
                cout << "\nPlease Enter The Price of The Product ";
                cin >> price;
                cout << "\nPlease Enter The Discount (%) ";
                cin >> dis;
                cout << "\nPlease Enter The Quantity ";
                cin >> pq;
            }
            

        void show_product()
        {
            cout << "\nThe Product SKU of The Product : " << pno;
            cout << "\nThe Name of The Product : ";
            puts(name);
            cout << "\nThe Price of The Product : " << price;
            cout << "\nDiscount : " << dis;
            cout << "\nInventory Quantity : " << pq;
        }
        
        int retpq()
        {
        	return pq;
		}

        int retpno()
        {
            return pno;
        }

        float retprice()
        {
            return price;
        }

        char * retname()
        {
            return name;
        }

        int retdis()
        {
            return dis;
        }
        
        int unisku(int p)
        {
        	fstream fc;
        	product pr;
        	fc.open("aps.dat",ios::in);
        	fc.read((char*)&pr, sizeof(product));
        	while(!fc.eof())
        	{
        		if(p == pr.retpno())
        		{
        			cout << "Enter a unique SKU : ";
        			cin >> p;
					fc.seekg(0);        			
				}
				fc.read((char*)&pr, sizeof(product));				
			}
			return p;
		}

    }; //class ends here
//hierarchical Inheritance
//polymorphism
class household:public product{
	public:
		void create_product()
            {
                cout << "\nPlease Enter The SKU of The Product ";
                cin >> pno;
                pno = unisku(pno);
                cout << "\n\nPlease Enter The Name of The Product ";
                cin>>gets(name);
                cout << "\nPlease Enter The Price of The Product ";
                cin >> price;
                cout << "\nPlease Enter The Discount (%) ";
                cin >> dis;
                cout << "\nPlease Enter The Quantity ";
                cin >> pq;
            }
void show_product()
        {
            cout << "\nThe Product SKU of The Product : " << pno;
            cout << "\nThe Name of The Product : ";
            puts(name);
            cout << "\nThe Price of The Product : " << price;
            cout << "\nDiscount : " << dis;
            cout << "\nInventory Quantity : " << pq;
        }};
class crockery:public product{
	public:
		void create_product()
            {
                cout << "\nPlease Enter The SKU of The Product ";
                cin >> pno;
                pno = unisku(pno);
                cout << "\n\nPlease Enter The Name of The Product ";
                cin>>gets(name);
                cout << "\nPlease Enter The Price of The Product ";
                cin >> price;
                cout << "\nPlease Enter The Discount (%) ";
                cin >> dis;
                cout << "\nPlease Enter The Quantity ";
                cin >> pq;
            }
void show_product()
        {
            cout << "\nThe Product SKU of The Product : " << pno;
            cout << "\nThe Name of The Product : ";
            puts(name);
            cout << "\nThe Price of The Product : " << price;
            cout << "\nDiscount : " << dis;
            cout << "\nInventory Quantity : " << pq;
        }};
class food:public product{
	public:
		void create_product()
            {
                cout << "\nPlease Enter The SKU of The Product ";
                cin >> pno;
                pno = unisku(pno);
                cout << "\n\nPlease Enter The Name of The Product ";
                cin>>gets(name);
                cout << "\nPlease Enter The Price of The Product ";
                cin >> price;
                cout << "\nPlease Enter The Discount (%) ";
                cin >> dis;
                cout << "\nPlease Enter The Quantity ";
                cin >> pq;
            }
void show_product()
        {
            cout << "\nThe Product SKU of The Product : " << pno;
            cout << "\nThe Name of The Product : ";
            puts(name);
            cout << "\nThe Price of The Product : " << price;
            cout << "\nDiscount : " << dis;
            cout << "\nInventory Quantity : " << pq;
        }};


fstream fp, fc;
product pr;
household hh;
crockery ck;
food f;

void write_product()
{
   char choice3;
   cout << "\n\n\n\tSELECT CATAGORY ";
        cout << "\n\n\t01. HOUSEHOLD ITEMS";
        cout << "\n\n\t02. CROCKERY ITEMS";
        cout << "\n\n\t03. FOOD ITEMS";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        choice3 = getche();
        switch (choice3)
        {
        case '1':
        fp.open("household.dat", ios::out | ios::app);
            hh.create_product();
            fc.open("aps.dat",ios::out|ios::app);
            fc.write((char * ) & hh, sizeof(household));
            fp.write((char * ) & hh, sizeof(household));
            fp.close();
            fc.close();
            cout << "\n\nThe Product Has Been Created ";
            getch();
            break;
        case '2':
            fp.open("crockery.dat", ios::out | ios::app);
            ck.create_product();
            fp.write((char * ) & ck, sizeof(crockery));
            fc.open("aps.dat",ios::out|ios::app);
            fc.write((char * ) & ck, sizeof(crockery));
            fc.close();
            fp.close();
            cout << "\n\nThe Product Has Been Created ";
            getch();
            break;
        case '3':
            fp.open("food.dat", ios::out | ios::app);
            f.create_product();
            fc.open("aps.dat",ios::out|ios::app);
            fp.write((char * ) & f, sizeof(food));
            fc.write((char * ) & f, sizeof(food));
            fc.close();
            fp.close();
            cout << "\n\nThe Product Has Been Created ";
            getch();
        default:
            cout << "\a";
        }
}
//////////////////////////////////////////////////////////////////////////////////////
void ordermenu()
{
		cout << "\n\n\tWelcome to Shop at SuperCart";
		cout << "\n\n\t HouseHold Articles";
		fp.open("household.dat", ios:: in );
		cout<<"\n\n\nProduct Number:\t\tName:\t\tPrice:"<<endl;
        while (fp.read((char * ) & hh, sizeof(household)))
            {
            	cout<<"\t"<<hh.retpno()<<"\t\t"<<hh.retname()<<"\t\t"<<hh.retprice()<<endl;
                cout << "\n";
            }
        fp.close();
        fp.open("crockery.dat", ios:: in );
        cout << "\n\tCrockery Articles";
       	cout<<"\n\n\nProduct Number:\t\tName:\t\tPrice:"<<endl;
        while (fp.read((char * ) & ck, sizeof(crockery)))
            {
                cout<<"\t"<<ck.retpno()<<"\t\t"<<ck.retname()<<"\t\t"<<ck.retprice()<<endl;
                cout << "\n";
            }
        fp.close();
        cout << "\n\tFood Articles";
               	cout<<"\n\n\nProduct Number:\t\tName:\t\tPrice:"<<endl;
        fp.open("food.dat", ios:: in );
            while (fp.read((char * ) & f, sizeof(food)))
            {
                cout<<"\t"<<f.retpno()<<"\t\t"<<f.retname()<<"\t\t"<<f.retprice()<<endl;
                cout << "\n";
            }
        fp.close(); 
}

void placeorder()
{
	system("cls");
	int tq[50], sku[50], c=0;
	float total, after, final=0, temp;
	int nq;
	char o = 'y';
	int fd = 0;
	ordermenu();
	cout << "\n\nTo Place Your Order";
	do{
		fp.open("aps.dat",ios::in);
    	fp.read((char*)&pr,sizeof(product));
		cout << "\n\nEnter the Product Number : ";
		cin >> sku[c];
		cout << "\n\nEnter the Product quantity : ";
		cin >> tq[c];
		while(!fp.eof())
		{
			if(sku[c] == pr.retpno() && tq[c] > pr.retpq())
			{
				cout << "Enter Quantity less than " << pr.retpq() << " : ";
				cin >> tq[c];				
			}
			fp.read((char*)&pr,sizeof(product));
		}
		cout << "Would you like to order something else(y/n): ";
		cin >> o;
		c++;
		fp.close();
	}while(o == 'y' || o == 'Y');
	 cout<<"Reciept"<<endl;
    cout<<"Product SKU\tProduct Name\tQuantity\tPrice\tAmount\tAmount after discount"<<endl;
    for(int x=0;x<=c;x++)
    {
    	fd = 0;
    	fp.open("aps.dat",ios::in);
    	fp.read((char*)&pr,sizeof(product));
        while(!fp.eof())
        {
        	if(pr.retpno() == sku[x])
        	{
        		fd = 1;
        		total = pr.retprice() * tq[x];
        		temp = pr.retprice() * tq[x];
        		for(int y=0; y<tq[x]; y++)
        		{
        			after = after + (pr.retprice()-(pr.retprice()*pr.retdis()/100));
				}
        		cout<<"\n"<<"\t"<<sku[x]<<"\t"<<pr.retname()<<"\t\t"<<tq[x]<<"\t\t"<<pr.retprice()<<"\t"<<total<<"\t\t"<<after;
        		final+=after;
			}
			fp.read((char*)&pr,sizeof(product));
		}
//		if(fd == 0)
//		{
//			cout << "\n\nProduct Unavailable";
//		}
		fp.close();
	}
	cout<<"\n\n\t\t\t\t\tTotal:"<<final << endl << endl;
	getch();
	
}




////////////////////////////////////////////////////////////////////////////////////////

void display_all()
{
   char choice4;
   cout << "\n\n\n\tSELECT CATEGORY";
        cout << "\n\n\t01. HOUSEHOLDS ITEMS";
        cout << "\n\n\t02. CROCKERY ITEMS";
        cout << "\n\n\t03. FOOD ITEMS";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        choice4 = getche();
        switch (choice4)
        {
        case '1':
        cout << "\n\n\n\t\tDISPLAY ALL RECORDS OF HOUSEHOLD ITEMS !!!\n\n";
            fp.open("household.dat", ios:: in );
            while (fp.read((char * ) & hh, sizeof(household)))
               {
                hh.show_product();
                cout << "\n\n====================================\n";
                getch();
               }
                fp.close();
                getch();
            break;
        case '2':
            cout << "\n\n\n\t\tDISPLAY ALL RECORD OF CROCKERY ITEMS !!!\n\n";
            fp.open("crockery.dat", ios:: in );
            while (fp.read((char * ) & ck, sizeof(crockery)))
               {
                ck.show_product();
                cout << "\n\n====================================\n";
                getch();
               }
                fp.close();
                getch();
            break;
        case '3':
            cout << "\n\n\n\t\tDISPLAY ALL RECORD OF FOOD ITEMS !!!\n\n";
            fp.open("food.dat", ios:: in );
            while (fp.read((char * ) & f, sizeof(food)))
               {
                f.show_product();
                cout << "\n\n====================================\n";
                getch();
               }
                fp.close();
                getch();
        default:
            cout << "\a";
        }
}
/////////////////////////////////////////////////////////////////////////////////////////

void modify_product()
{
    int no, found = 0;
    char choice5;
    cout << "\n\n\n\tSELECT CATEGORY";
        cout << "\n\n\t01. HOUSEHOLDS ITEMS";
        cout << "\n\n\t02. CROCKERY ITEMS";
        cout << "\n\n\t03. FOOD ITEMS";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        choice5 = getche();
        switch (choice5)
        {
        case '1':
        cout << "\n\n\tTo Modify household items ";
            cout << "\n\n\tPlease Enter The Product SKU";
            cin >> no;
            fp.open("household.dat", ios:: in | ios::out);
            while (fp.read((char * ) & hh, sizeof(household)) && found == 0)
            {
               if (hh.retpno() == no)
               {
                  hh.show_product();
                  cout << "\nPlease Enter The New Details of Product" << endl;
                  hh.create_product();
                  int pos = -1 * sizeof(hh);
                  fp.seekp(pos, ios::cur);
                  fp.write((char * ) & hh, sizeof(household));
                  cout << "\n\n\t Record Updated";
                  found = 1;
               }
            }
            fp.close();
            if (found == 0)
            cout << "\n\n Record Not Found ";
            getch();
            break;
        case '2':
            cout << "\n\n\tTo Modify crockery items ";
            cout << "\n\n\tPlease Enter The Product SKU";
            cin >> no;
            fp.open("crockery.dat", ios:: in | ios::out);
            while (fp.read((char * ) & ck, sizeof(crockery)) && found == 0)
            {
               if (ck.retpno() == no)
               {
                  ck.show_product();
                  cout << "\nPlease Enter The New Details of Product" << endl;
                  ck.create_product();
                  int pos = -1 * sizeof(ck);
                  fp.seekp(pos, ios::cur);
                  fp.write((char * ) & ck, sizeof(crockery));
                  cout << "\n\n\t Record Updated";
                  found = 1;
               }
            }
            fp.close();
            if (found == 0)
            cout << "\n\n Record Not Found ";
            getch();
            break;
        case '3':
            cout << "\n\n\tTo Modify food items ";
            cout << "\n\n\tPlease Enter The Product SKU";
            cin >> no;
            fp.open("food.dat", ios:: in | ios::out);
            while (fp.read((char * ) & f, sizeof(food)) && found == 0)
            {
               if (f.retpno() == no)
               {
                  f.show_product();
                  cout << "\nPlease Enter The New Details of Product" << endl;
                  f.create_product();
                  int pos = -1 * sizeof(f);
                  fp.seekp(pos, ios::cur);
                  fp.write((char * ) & f, sizeof(food));
                  cout << "\n\n\t Record Updated";
                  found = 1;
               }
            }
            fp.close();
            if (found == 0)
            cout << "\n\n Record Not Found ";
            getch();
        default:
            cout << "\a";
        }
   
}
//////////////////////////////////////////////////////////////////////////////////////////////
void delete_product()
{

    int no;
    char choice6;
    fstream fp2;
        cout << "\n\n\n\tSELECT CATAGORY";
        cout << "\n\n\t01. HOUSEHOLDS ITEMS";
        cout << "\n\n\t02. CROCKERY ITEMS";
        cout << "\n\n\t03. FOOD ITEMS";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        choice6 = getche();
        switch (choice6)
        {
        case '1':
        cout << "\n\n\n\tDelete Record from household";
            cout << "\n\nPlease Enter The product SKU You Want To Delete";
            cin >> no;
            fp.open("household.dat", ios:: in | ios::out);
            fp2.open("emptyhh.dat", ios::out);
            fp.seekg(0, ios::beg);
            while (fp.read((char * ) & hh, sizeof(household)))
            {
               if (hh.retpno() != no)
               {
                  fp2.write((char * ) & hh, sizeof(household));
               }
            }
            fp2.close();
            fp.close();
            remove("household.dat");
            rename("emptyhh.dat", "household.dat");
            cout << "\n\n\tRecord Deleted ..";
            getch();
            break;
        case '2':
            cout << "\n\n\n\tDelete Record from crockery";
            cout << "\n\nPlease Enter The product SKU You Want To Delete";
            cin >> no;
            fp.open("crockery.dat", ios:: in | ios::out);
            fp2.open("emptyck.dat", ios::out);
            fp.seekg(0, ios::beg);
            while (fp.read((char * ) & ck, sizeof(crockery)))
            {
               if (ck.retpno() != no)
               {
                  fp2.write((char * ) & ck, sizeof(crockery));
               }
            }
            fp2.close();
            fp.close();
            remove("crockery.dat");
            rename("emptyck.dat", "crockery.dat");
            cout << "\n\n\tRecord Deleted ..";
            getch();
            break;
        case '3':
            cout << "\n\n\n\tDelete Record from fooditems";
            cout << "\n\nPlease Enter The product SKU You Want To Delete";
            cin >> no;
            fp.open("food.dat", ios:: in | ios::out);
            fp2.open("emptyf.dat", ios::out);
            fp.seekg(0, ios::beg);
            while (fp.read((char * ) & f, sizeof(food)))
            {
               if (f.retpno() != no)
               {
                  fp2.write((char * ) & f, sizeof(food));
               }
            }
            fp2.close();
            fp.close();
            remove("food.dat");
            rename("emptyf.dat", "food.dat");
            cout << "\n\n\tRecord Deleted ..";
            getch();
        default:
            cout << "\a";
        }
}  
////////////////////////////////////////////////////////////////////////////////////////
void menu()
{
	system("cls");
    fp.open("Shop.dat", ios:: in );
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File ";

        cout << "\n\n\n Program is closing ....";
        getch();
    }

    cout << "\n\n\t\tProduct MENU\n\n";
    cout << "====================================================\n";
    cout << "P.NO.\t\tNAME\t\tPRICE\n";
    cout << "====================================================\n";

    while (fp.read((char * ) & pr, sizeof(product)))
    {
        cout << pr.retpno() << "\t\t" << pr.retname() << "\t\t" << pr.retprice() << endl;
    }
    fp.close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
void admin_menu()
{
		int yes = 1;
	while(yes == 1)
	{
		system("cls");
	    char choice2;
	    cout << "\n\n\n\tWELCOME TO STOCKS DATABASE";
	    cout << "\n\n\t1.ADD PRODUCT";
	    cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
	    cout << "\n\n\t3.UPDATE PRODUCT";
	    cout << "\n\n\t4.REMOVE PRODUCT";
	    cout << "\n\n\t5.BACK TO MAIN MENU";
	    cout << "\n\n\tPlease Enter Your Choice (1-5) ";
	    choice2 = getche();
	    switch (choice2)
	    {
	    case '1':
	    	system("cls");
	        write_product();
	        cout << "To return back to menu press 1";
	        cin >> yes;
	        break;
	    case '2':
	    	system("cls");
	        display_all();
	        cout << "To return back to menu press 1";
	        cin >> yes;
	        break;
	    case '3':
	    	system("cls");
	        modify_product();
	        cout << "To return back to menu press 1";
	        cin >> yes;
	        break;
	    case '4':
	    	system("cls");
	        delete_product();
	        cout << "To return back to menu press 1";
	        cin >> yes;
	        break;
	    case '5':
	    	yes = 0;
	        break;
	    default:
	        cout << "\a";
	        admin_menu();
	    }
	}
}
