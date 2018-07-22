//this is admin mode
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
using namespace std;

class item
{
	char itemname[50];
	int presentquantity;
	int price;
	float discount;
	int available;
	public:
	item()
	{
		presentquantity = 0;
		price = 0;
		discount = 0.000000;
		available = 0;
	}
	void one()
	{
		FILE *ptr;
		char fullname[] = "DATABASE/";
		
		cout << "Enter the new name of the item";
		cin >> itemname;
		strcat(fullname,itemname);
		//cout << fullname;
		ptr = fopen(fullname,"w"); //check if name exists then not permit
		
		fprintf(ptr,"%s\n",itemname);
		cout << "Enter the present quantity of the item" << endl;
		cin >> presentquantity;
		fprintf(ptr,"%d\n",presentquantity);
		
		cout << "Enter the price of the item" << endl;
		cin >> price;
		fprintf(ptr,"%d\n",price);
		
		cout << "Enter discount of the item" << endl;
		cin >> discount;
		fprintf(ptr,"%f\n",discount);
		
		cout << "Enter the availability" << endl;
		cout << "0 - NOT AVAILABLE " << endl;
		cout << "1 - AVAILABLE " << endl;		
		cin >> available;
		fprintf(ptr,"%d\n",available);
		
		fclose(ptr);
	}	
};

int main()
{
	item I; //CREATING item object
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
	cout << "1. Add new item in user mode" << endl;
	cout << "2. Check profit in a day" << endl;
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
		I.one();
	}
	else if(choice==2)
	{
		FILE *fptr;
		fptr = fopen("salelist.txt","r"); //open file for reading
		if(fptr == NULL)
		{
			exit(67);
		}
		int num;
		int sum=0;
		char ch = fgetc(fptr);
		while((ch=fgetc(fptr)) != EOF)
		{
			fscanf(fptr,"%d",&num);
			//cout << num<<endl;
			sum=sum+num;
		}
		fclose(fptr);
		cout << "TOTAL PROFIT: "<<sum<<endl;
		
		//time_t my_time = time(NULL);
 
    	// ctime() used to give the present time
    	//string hello = ctime(&my_time);
    	//cout << hello << endl;
	}
	else if(choice==3)
	{
	}
	else if(choice==4)
	{
		cout << "Choose the option" <<endl;
		int choice;
		cin >> choice;
		if(choice == 1)
		{
		}
		else if(choice == 2)
		{
		}
	}
	else if(choice==5)
	{
		FILE *fp;
		fp = fopen("LICENSE","r");
		char c;
		while((c=fgetc(fp))!=EOF)
		{
			cout << c;
		}
		fclose(fp);
	}
	else
	{
		exit(00);
	}
}
