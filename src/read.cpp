#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include "colors.h"
using namespace std;
int main()
{
	FILE *ptr;
	ptr = fopen("Menucard.txt","r");
	if(ptr==NULL)
	{
		exit(99);
	}
	char heading[20];
	int id;
	char item[20];
	char name[20];
	cout <<BOLD<<"\n\n\t\t\t\tMENU CARD\t\t\t"<<RESET<<endl;
	cout <<BOLD<<"********************************************************************************\n"<<RESET<<endl;
	
	fscanf(ptr,"%s",heading);
	cout <<"\t\t\t\t" << BBLUE << heading<<RESET<< "\t\t\t\t" <<endl;
	cout <<BOLD<<"--------------------------------------------------------------------------------"<<RESET<<endl;
	
	cout << BYELLOW <<"CODE" << "\t" << "ITEM NAME"<< RESET <<endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout <<"00" << id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout << "00" << id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout << "00" << id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout << "00" << id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout << "00" << id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout << "00" << id << "\t" << BCYAN << item << " " << name << RESET << endl;
		
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout << "00" << id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout << "00" << id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout << "0" << id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	cout << endl;
	//******************************************************************************************************************************************************//
	char third[20];
	fscanf(ptr,"%s",heading);
	cout <<"\t\t\t\t" << BMAGENTA << heading<<RESET<< "\t\t\t\t" <<endl;
	cout <<BOLD<<"--------------------------------------------------------------------------------"<<RESET<<endl;
	
	cout << BYELLOW <<"CODE" << "\t" << "ITEM NAME"<< RESET <<endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout <<"0"<<id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	fscanf(ptr,"%d %s %s %s",&id,item,name,third);
	cout <<"0"<<id << "\t" << BCYAN << item << " " << name << " " << third<< RESET << endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout <<"0"<<id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	fscanf(ptr,"%d %s",&id,item);
	cout <<"0"<<id << "\t" << BCYAN << item << RESET << endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout <<"0"<<id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
//************************************************************************************************************************************************************//
fscanf(ptr,"%s",heading);
	cout <<"\t\t\t\t" << BGREEN << heading<<RESET<< "\t\t\t\t" <<endl;
	cout <<BOLD<<"--------------------------------------------------------------------------------"<<RESET<<endl;
	
	cout << BYELLOW <<"CODE" << "\t" << "ITEM NAME"<< RESET <<endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout <<"0"<< id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout <<"0"<< id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	fscanf(ptr,"%d %s",&id,item);
	cout << "0"<<id << "\t" << BCYAN << item << RESET << endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout <<"0"<< id << "\t" << BCYAN << item << " " << name << RESET << endl;
	
	fscanf(ptr,"%d %s %s",&id,item,name);
	cout <<"0" <<id << "\t" << BCYAN << item << " " << name << RESET << endl;
		
	fscanf(ptr,"%d %s",&id,item);
	cout <<"0"<< id << "\t" << BCYAN << item << RESET << endl;
	
	
	//cout << endl;
	cout <<BOLD<<"********************************************************************************"<<RESET<<endl;
	fclose(ptr);
}
