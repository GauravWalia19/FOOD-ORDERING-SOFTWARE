//this is admin mode
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	char passwd[]="gaurav";
	cout << "Enter the password: "<< endl;
	char password[20];
	cin.getline(password,20);
	//VERIFICATION	
	if(strcmp(passwd,password)==0)
	{
		cout << "Access Granted" << endl;
	}
	else
	{
		cout << "Access Denied!!!" << endl;
		exit(99);
	}
	cout << "............................................................................." << endl;
	int choice;
	cout << "ADMIN OPTIONS" << endl;
	
	cout << "0. Exit" << endl;
	cout << "1. Add new item in database" << endl;
	cout << "2. Delete old item in database" << endl;
	cout << "3. Check Remaining Stock" << endl;
	cout << "4. Read main code" << endl; 
	cout << "5. Read License" << endl; 
	 
	cout << "Enter your choice" << endl;
	cin >> choice;
	if(choice==0)
	{
		exit(0);
	}
	else if(choice==1)
	{
		FILE *ptr;
		char fullname[] = "DATABASE/";
		char itemname[20];
		cout << "Enter the new name of the item";
		cin >> itemname;
		strcat(fullname,itemname);
		//cout << fullname;
		ptr = fopen(fullname,"w"); //check if name exists then not permit
		fclose(ptr);
	}
	else if(choice==2)
	{
	}
	else if(choice==3)
	{
	}
	else if(choice==4)
	{
	}
	else if(choice==5)
	{
	}
	else
	{
	}
}
