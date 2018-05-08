//this is admin mode
#include <iostream>
#include <cstdlib>
#include <cstring>
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
		cout << "verified";
	}
	else
	{
		cout << "Access Denied!!!" << endl;
		exit(99);
	}
	int choice;
	cout << "ADMIN OPTIONS" << endl;
	
	cout << "1. Add new item in database"<< endl;
	cout << "2. Delete old item in database" << endl;
	cout << "3. Check Remaining Stock" << endl;
	cout << "4. Read main code" << endl; 
	cout << "5. Read License" << endl; 
	 
	cout << "Enter your choice" << endl;
	cin >> choice;
	switch()
	{
		case 0:
		break;
		case 1:
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
		break;
		case 5:
		break;
		default:
		break;
	}
}
