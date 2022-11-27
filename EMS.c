#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#define MAX_EMP_SZ 100
#define MAX_ENTRIES_SZ 10

int n,code;
char temp;
struct Employee {
    char empName[MAX_EMP_SZ], empDesignation[MAX_EMP_SZ], empExperience[MAX_EMP_SZ];
    int empCode, empAge;
};

void showMenuDisplay();
Employee emp[MAX_EMP_SZ];

void empBuildTable()
{

   	printf("\n\t\t");
    printf("Maximum Entries: ");
    printf("%d",MAX_ENTRIES_SZ);
  	printf("\n\t\t");   
   	printf("Enter no. of entries required:\t");
   	scanf("%d",&n);
    if (n <= 0 || n > MAX_ENTRIES_SZ)
    {
    	printf("\n\t\t");
		printf("Invalid Input. Try Again!\n");
    	empBuildTable();
	}
	else{
		printf("\n\t\t");
    	printf("Enter the following data:\n");
    	for (int i = 0; i < n; i++) 
		{
			printf("\n\t\t"); 
			printf("Employee Name\t\t:\t");
			scanf("%c",&temp);
			scanf("%[^\n]",emp[i].empName);
			printf("\t\t");
			printf("Employee ID\t\t:\t");
			scanf("%d",&emp[i].empCode); 
			printf("\t\t"); 
			printf("Employee Designation\t:\t");
			scanf("%c",&temp);
			scanf("%[^\n]",emp[i].empDesignation);
			printf("\t\t"); 
			printf("Employee Experience\t:\t");
			scanf("%c",&temp);
			scanf("%[^\n]",emp[i].empExperience);
			printf("\t\t"); 
			printf("Employee Age\t\t:\t");
			scanf("%d",&emp[i].empAge);
			
		}
	}
  	//Back to Menu
	showMenuDisplay();
}

//Search Record Of Employee
void empSearchRecord()
{	
	printf("\n\t\t");
	printf("Enter the Employee ID to Search Record: ");
    scanf("%d",&code);
  
    for (int i = 0; i < n; i++) 
	{
        // If the data is found
        if (emp[i].empCode == code) 
		{	
			printf("\n\t\t"); 
	  		printf("Employee ID\t\t:\t%d",emp[i].empCode);
	  		printf("\n\t\t");
	  		printf("Employee Name\t\t:\t");
			puts(emp[i].empName);
	  		printf("\t\t");
	  		printf("Employee Designation\t:\t");
			puts(emp[i].empDesignation);
			printf("\t\t");
	  		printf("Employee Experience\t:\t");
			puts(emp[i].empExperience);
			printf("\t\t");
	  		printf("Employee Age\t\t:\t%d",emp[i].empAge);
	  		//Back to menu after searching ID and it was found
            return showMenuDisplay();
        }
	}
		
	printf("\t\t");
	printf("Employee ID not found!");			
	printf("\n"); 
    showMenuDisplay();
}

//Delete Employee Record

void empDeleteRecord()
{	
	printf("\n\t\t");
	printf("Enter the Employee ID to Delete Record: ");
	scanf("%d", &code);
	printf("\n\t\t");
	for (int i = 0; i <= n; i++)
	{		
		if(code ==emp[i].empCode )
		{	           					
			emp[i].empCode = 0;
			strcpy(emp[i].empName, "");
			strcpy(emp[i].empDesignation, "");
			strcpy(emp[i].empExperience, "");
			emp[i].empAge = 0;
			printf("Employee Data Record Deleted Successfully.\n");
			//Back to menu after deleted
	    	return showMenuDisplay();
		}			    
	}
	
	printf("Employee ID not found!");
	printf("\n");
	showMenuDisplay();
}

//Insert Employee Record
void empInsert()
{
    if (n < MAX_ENTRIES_SZ) {
        int i = n;
        n++;
  			printf("\n\t\t"); 
			printf("Employee Name\t\t:\t");
			scanf("%c",&temp);
			scanf("%[^\n]",emp[i].empName);
			printf("\t\t");
			printf("Employee ID\t\t:\t");
			scanf("%d",&emp[i].empCode); 
			printf("\t\t"); 
			printf("Employee Designation\t:\t");
			scanf("%c",&temp);
			scanf("%[^\n]",emp[i].empDesignation);
			printf("\t\t"); 
			printf("Employee Experience\t:\t");
			scanf("%c",&temp);
			scanf("%[^\n]",emp[i].empExperience);
			printf("\t\t"); 
			printf("Employee Age\t\t:\t");
			scanf("%d",&emp[i].empAge);
    
    }
    else{
        printf("Employee Table Full\n");
    }
    showMenuDisplay();
}

void showMenuDisplay()
{
  	printf("\n\t\t");
    printf("===============================================================================================");
    printf("\n");
    printf("\t\t=                                                                                             =");
    printf("\n");
    printf("\t\t=                                                                                             =");
	printf("\n");
	printf("\t\t=\t\t\tARJUN ROSELL EMPLOYMENT MANAGEMENT SYSTEM \t\t\t      =");
	printf("\n");
    printf("\t\t=                                                                                             =");
    printf("\n");
    printf("\t\t=                                                                                             =");
	printf("\n\t\t");
    printf("===============================================================================================");
  	printf("\n\n");
    printf ("\t\tAvailable Options:\n\n");
    printf ("\t\tBuild Table         (1)\n");
    printf ("\t\tInsert New Entry    (2)\n");
    printf ( "\t\tDelete Entry        (3)\n");
    printf ( "\t\tSearch a Record     (4)\n");
    printf ("\t\tExit                (5)\n");
    int option;
  	printf("\n\t\t");
    printf("Enter number to choose\t:\t");
    scanf("%d",&option);
  
    if (option == 1) 
	{
        empBuildTable();
    }
    else if (option == 2) 
	{
        empInsert();
    }
    else if (option == 3) 
	{
        empDeleteRecord();
    }
    else if (option == 4) 
	{
        empSearchRecord();
    }
    else if (option == 5) {
        return;
    }
    else {
    	printf("\n\t\t");		 
        printf("Invalid Input!");
        printf("\n\t\t");
        showMenuDisplay();
    }
}

int main()
{
    showMenuDisplay();
    return 0;
}
