#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<cstdio>
using namespace std;





struct employee
{
    char name[50];
    char area[50];
    char id[5];
    int age;
    char status[10];
    float wage;
} employee;


void admin_emp()
{
	char emp_id[5], a, name[10], stat[10], view = 'y';
    int empsize = sizeof(struct employee);
    char add_record = 'y';
    char id[5];
    char place[50] = "pechs";
    
    
     FILE *fp, *fn;                                 //file for employee rcd
     fp = fopen("employee.txt", "rb+");
	 if(fp == NULL)
     {
        fp = fopen("employee.txt","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
        }
     }
         	system("cls");

    while(1)
    {
    	printf("\n\n\nChoose an option\n\n 1)Add A New Employee Record\n 2)View list of Employees\n 3)View Employee by name\n 4)View Employees by status(active or inactive)\n 5)Exit");
    	fflush(stdin);
        scanf("\n%c", &a);
		switch(a)
    	{
    	case '1':
    		system("cls");
    		add_record = 'y';
    		while(add_record == 'y' || add_record == 'Y')
    		{
    		fseek(fp,0,SEEK_END);
	        printf("\nName: ");
            scanf("%s", &employee.name);
            printf("Employee-ID: ");
            scanf("%s", &id);
            rewind(fp);
            while(fread(&employee, empsize, 1, fp))  //unique goods id
            {
				if(strcmp(id, employee.id) != 0)
            	continue;
            	else
            	{
            		printf("Enter unique Employee-id: ");
                    scanf("%s", &id);
                    rewind(fp);
				}
			}
			strcpy(employee.id, id);
            printf("Age: ");
            scanf("%d", &employee.age);
	        printf("Area of Delivery: ");
            scanf("%s", &employee.area);
            printf("Status: ");
            scanf("%s", &employee.status);
            printf("Base Salary: ");
            scanf("%f", &employee.wage);
            fwrite(&employee,empsize,1,fp);
            printf("\nWould you like to add another record(y/n):");
            fflush(stdin);
            scanf("%c", &add_record);
			}
			break;
		
		case '2':
			system("cls");
			rewind(fp);
			printf("\n\tName \tEmp-ID \tAge \tBase-Salary \tArea \tStatus");
			while( fread(&employee, empsize, 1, fp))
            {
			printf("\n\n\t %s", employee.name);
			printf("\t%s", employee.id);
            printf("\t%d", employee.age);
            printf("\t%.2f", employee.wage);
            printf("\t\t%s", employee.area);
            printf("\t%s", employee.status);
            }               	
			break;
		
		case '3':
			system("cls");
			view = 'y';
			while(view == 'y' || view == 'Y')
			{
				rewind(fp);
				printf("\nEnter the employee name to view details: ");
				fflush(stdin);
                scanf("%s", &name);
                while(fread(&employee, empsize, 1, fp))
                {
                	if(strcmp(name, employee.name) == 0)
                	{
			         printf("\n\nName:\t %s", employee.name);
			         printf("\nEmp-ID:\t %s", employee.id);
                     printf("\nAge:\t %d", employee.age);
                     printf("\nBase Salary:\t %.2f", employee.wage);
                     printf("\nDelivery Area:\t %s", employee.area);
                     printf("\nStatus: \t %s", employee.status);		                                    
					}
				}  
				printf("\n\nWould you like to view another record(y/n):");
                fflush(stdin);
                scanf("%c", &view);              
			}
			break;
		case '4':
			system("cls");
			view = 'y';
			while(view == 'y' || view == 'Y')
			{
				rewind(fp);
				printf("\nEnter the status to view employees ");
				fflush(stdin);
                scanf("%s", &stat);
                while(fread(&employee, empsize, 1, fp))
                {
                	if(strcmp(stat, employee.status) == 0)
                	{
			         printf("\n\nName:\t %s", employee.name);
			         printf("\nEmp-ID:\t %s", employee.id);
                     printf("\nAge:\t %d", employee.age);
                     printf("\nBase Salary:\t %.2f", employee.wage);
                     printf("\nDelivery Area:\t %s", employee.area);
                     printf("\nStatus: \t %s", employee.status);		                                    
					}
				}  
				printf("\n\nWould you like to pass your query again(y/n):");
                fflush(stdin);
                scanf("%c", &view);              
			}
			break;
			case '5':
			fclose(fp);
            exit(0);
		}
			
		}
	}

