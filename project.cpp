/*FOOD ORDERING SYSTEM*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include "colors.h"
#include <dirent.h>
using namespace std;
/************************************************************** ITEM CLASS ******************************************************************************/
class ITEM
{
	char name[50];
	int presentquantity;
	int price;
	float discount;
	int available;
	vector<string>avail;
	float bill;
	
	public:
	//CONSTRUCTER
	ITEM()
	{
		presentquantity=0;
		price=0;
		discount=0;
		available=0;
		bill=0;
	}
	void readDatabase()//reading the database files if they are available --DONE
	{
		cout << BCYAN	<<"................................................................................"<<RESET<<endl;
		cout << BYELLOW<<"................................................................................"<<endl;
		cout << "\t\t\t\t   MENU CARD\t\t\t\t"	 << endl;
		cout << "ITEM\t\t\t\tPRICE" << RESET<<endl;
		//reading all files in directory
		struct dirent *de;
		DIR *dr = opendir("DATABASE");
		if(dr==NULL)
		{
			cout << "cannot open current directory";
		}
		while ((de = readdir(dr)) != NULL)
		{
      	if(strcmp(de->d_name,".")==0 || strcmp(de->d_name,"..")==0)
      	{
      		//FOR NOT SHOWING . ..
      	}
      	else
      	{	
      		//
      		FILE *pt;
      		available=0;
      		char straw[]="DATABASE/";
      		strcat(straw,de->d_name);
      		//cout << straw << endl; //straw opening file name
      		pt = fopen(straw,"r");
      		fscanf(pt,"%s",name);
				fscanf(pt,"%d",&presentquantity);
				fscanf(pt,"%d",&price);
				fscanf(pt,"%f",&discount);
      		fscanf(pt,"%d",&available);
      		//cout << name;
      		if(available == 1)
      		{
      			avail.push_back(name);  //ADD DATA IN AVAILBILITYVECTOR
      			cout <<BCYAN<<name<<RESET<<"\t\t\t";
      			cout <<BGREEN << price << RESET<<endl; 
      		}
      		else if(available==0)
      		{
      			cout <<BRED<< name << " not available"<<RESET<<endl;
      			available=0;		
      		}
      		fclose(pt);
      	}
 		}
    	closedir(dr);
    	cout << BYELLOW<<"................................................................................"<<RESET<<endl;
    	cout << BCYAN	<<"................................................................................"<<RESET<<endl;	 		
	}
	/************************************************************************************************************************************************/
	void checkdatabase(char *itemname,int quantity) //checking of the user entered data 
	{
		
		int chk=0;
		//CHECKING IN VECTOR OR MY DATABASE
		for(register int i=0;i<avail.size();i++)
		{
			if(avail[i] == itemname)
			{
				chk=1;
			}
		}
		cout << "... CHECKING ..."<<endl;
		//AVAILABLE
		if(chk==1)
		{
			FILE *fgg;
			char straw[]="DATABASE/";
			strcat(straw,itemname);
			fgg = fopen(straw,"r");
      	fscanf(fgg,"%s",name);
			fscanf(fgg,"%d",&presentquantity);
			fscanf(fgg,"%d",&price);
			fscanf(fgg,"%f",&discount);
      	fscanf(fgg,"%d",&available);
      	
      	//CALCULATIONS
      	//RECENT BILL
      	if(quantity<=presentquantity)
      	{
      		bill=bill+(price*quantity);
      	}
      	else
      	{
      		//bill=0;
      	}
      	
      	fclose(fgg);
      	
      	//READED THE PRESENT ITEM DATA
      	//cout << name << presentquantity << price << discount << available << endl;
      	//checking the items quantity is availble or not
      	if(quantity<=presentquantity)
      	{
      		cout << "ITEM AND QUANTITY AVAILABLE"<<endl;
      		presentquantity = presentquantity - quantity;
      		//WRTING THE SOURCE FILE AGAIN
      		FILE *fpt;
      		char straw[]="DATABASE/";
				strcat(straw,itemname);
				fpt = fopen(straw,"w");
				fprintf(fpt,"%s\n",name);
				fprintf(fpt,"%d\n",presentquantity);
				fprintf(fpt,"%d\n",price);
				fprintf(fpt,"%f\n",discount);
      		fprintf(fpt,"%d\n",available);
				fclose(fpt);
      	}
      	else
      	{	
      		cout << "OUT OF STOCK" <<endl;
      		//WRTING THE SOURCE FILE AGAIN FOR OUT OF STOCK TO MAKE AVAILABLE 0
      		FILE *fpt;
      		char straw[]="DATABASE/";
				strcat(straw,itemname);
				fpt = fopen(straw,"w");
				fprintf(fpt,"%s\n",name);
				fprintf(fpt,"%d\n",presentquantity);
				fprintf(fpt,"%d\n",price);
				fprintf(fpt,"%f\n",discount);
				available=0;
      		fprintf(fpt,"%d\n",available);
				fclose(fpt);
      	}
		}
		//NOT AVAILABLE
		else
		{
			//bill=0;
			cout << "SORRY!!!ITEM NOT AVAILABLE IN THE SHOP"<<endl;
		}
		
	//OUTPUTTING
	cout << "RECENT BILL:"<<bill<<endl;	
	}
	//CHECKING AVAIL VECTOR
	int availvalue(char *itemname)
	{
		int ck=0;
		//CHECKING IN VECTOR OR MY DATABASE
		for(register int i=0;i<avail.size();i++)
		{
			if(avail[i] == itemname)
			{
				ck=1;
			}
			else
			{
				ck=0;
			}
		}
		return ck;
	}
	
	void totalbill()
	{
		cout << "TOTAL BILL: "<<bill<<endl;
	}	
};

/************************************************************** USER CLASS ******************************************************************************/
class USER:public ITEM
{
	char username[50];
	long phoneno;
	char itemname[50];
	int quantity;
	public:
	void get_user_data() ///getting user data
	{	
		cout << "Enter your username SIR/MADAM" << endl;
		cin >> username;
		cout << "Enter your phone no" <<endl;
		//CHECKING PHONE NUMBER IS VALID OR NOT
		while(1)
		{
			cin >> phoneno;
			int p = phoneno/1000000000;
			if(p>=1 && p<=9)
			{
				break;
			}
			else
			{
				cout << "ENTER A VALID PHONE NUMBER" << endl;
			}
		}	
	}
	void get_item_data()//GETTING USER ITEM BY USER
	{
		cout << "WHICH ITEM DO YOU LIKE U EAT SIR/MADAM" << endl;
		cin >> itemname;
		cout << "SIR/MADAM CAN YOU PLEASE TELL US QUANTITY" << endl;
		//CHECKING QUANTITY NOT BE 0
		while(1)
		{
			cin >> quantity;
			if(quantity != 0)
			{
				break;
			}
			cout << "ENTER VALID QUANTITY" << endl;
		}
	}
	void put_data_file() //WRITITNG DATA TO FILE OF USER
	{
		//GETTING AVAILABLE FROM ABOVE
		int av = availvalue(itemname);
			
		/*	
		//ONLY WRITE WHEN AVAILABLE
		if(av==1)
		{	
			char str[50]="ORDERS/";
			strcat(str,username);
			FILE *ptr;
			ptr = fopen(str,"a+");
			if(ptr == NULL)
			{
				cout << "SORRY EXISTING NOW" <<endl;
				exit(1);
			}
			//WRITING A FILE
			fprintf(ptr,"%s\n",itemname);
			fprintf(ptr,"%d\n\n",quantity);
			fclose(ptr);
		}
		*/
			char str[50]="ORDERS/";
			strcat(str,username);
			FILE *ptr;
			ptr = fopen(str,"a+");
			if(ptr == NULL)
			{
				cout << "SORRY EXISTING NOW" <<endl;
				exit(1);
			}
			//WRITING A FILE
			fprintf(ptr,"%s\n",itemname);
			fprintf(ptr,"%d\n\n",quantity);
			fclose(ptr);
	}
	void check()
	{
		checkdatabase(itemname,quantity);
	}
	void totaluserbill()
	{
		cout <<BOLD<< "\t\t\t\t  BILL"<<endl;
		cout << "--------------------------------------------------------------------------------"<<endl;
		cout <<"USERNAME: "<< username << endl;
		cout <<"PHONE NUMBER: " << phoneno << endl;
		
		////////////////////////////////////////////////////
		char strs[50]="ORDERS/";
		strcat(strs,username);
		FILE *ptr;
		ptr = fopen(strs,"r");
		char ch;
		while((ch=fgetc(ptr))!=EOF)
		{
			cout << ch;
		}
		fclose(ptr);
		////////////////////////////////////////////////////
		totalbill();
		cout << "--------------------------------------------------------------------------------"<<endl;
		cout << RESET;
		
		//cleaning the user data file
		char hell[50]="ORDERS/";
		strcat(hell,username);
		FILE *ggp;
		ggp = fopen(hell,"w");
		fclose(ggp);
	}
};

//THIS IS OUT MAIN FUNCTION NOT MULTITASKED !!!!!!!!!!!!!!ONLY FOR ONE USER AT A TIME
int main()
{
	USER A;
	char ans[5];   //VARIABLE FOR ANSWERING
	cout << BOLD <<"Welcome to our SHOP" << endl;
	cout << "Hope you like it!!!!"<< endl;
	cout << endl;
	cout << "WE HAVE TOO MUCH ITEMS IN OUT SHOP"<< endl;
	cout << "HERE IS THE MENU CARD" << RESET <<endl;
	A.get_user_data();  //GETTING USER INFORMATION
	//MENU CARD HERE -READ THE FILE IN DATABASE
	A.readDatabase(); 
	cout << "YOU CAN ORDER" << endl;
	while(1)
	{		
		A.get_item_data();  //GETTING DATA OF ONE ITEM BY the user
		A.put_data_file();	//PUTING USER DATA IN A FILE	
		A.check();  //CHECKING DATA RIGHT OR NOT AND MAKING BILL
		//*********************************************************************************************************************************************************************//
		cout << "Do you want more items(true/false)" << endl;
		cin >> ans;
		
		//checking answer string if it contain f or not
		int c=0;
		for(int k=0;k<strlen(ans);k++)
		{
			if(ans[k]=='F' || ans[k]=='f')
			{
				c=1;
				break;
			}
		}
		if(c==1)
		{
			break;
		}
	}
	//OUTPUT BILL
	A.totaluserbill();
}
