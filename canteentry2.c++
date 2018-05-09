#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include"colors.h"
#include<fstream>
#include "stllist.h"//our self made standard template library
using namespace std;


/******************************************* CUSTOMER CLASS ******************************************************/
class Customer
{ 
	private:
	string name;
   list<int> basket;  //this is implemented using stllist.h and this is linklist with two fields -itemid and quantity             
  	public: 
	Customer()
	{
		cout<<"Enter your name : ";
		cin>>name;  
	}
 	void shop(int itemid,int quantity)
 	{ 
 		basket.add(itemid,quantity);
   }//adding in linklist
   
  	void showitem()
  	{ 
  		basket.traverse();
   }//printing data in linklist

 	node<int>* pickfrombasket()
  	{ 
  		return  basket.pick();
  	} //pick from linklist

   friend class FILES;
};

/***************************** DISCOUNT CLASS ************************************************************/
class Discount
{
	private :
  		int *darr;
  		int *discount;
	public:
	Discount()
	{
		int t=100;
	 	darr=new int[4];
	 	discount=new int[4];
	 	int i;
	 	for(i=0;i<4;i++)
	 	{
	 		darr[i]=(i)*t*10;
			discount[i]=t*(i);
	 	}
	 	//discount[i]=t*(i+1);
	}
	int dcomputate(int t)
	{ 
		int i=0; 
		while((t>=darr[i]) && (i<4))
		{
			i++;
		}
	return discount[i-1];
	}
};

/*********************************** FILES CLASS *********************************************************************/
class FILES:protected Discount
{ 
	private:
	fstream itemlist;
	string line;
	fstream pricelist;
        ofstream sale;
        fstream quantitylist;
  	public:
  	FILES()
  	{
   	pricelist.open("pricelist.txt");
        sale.open("salelist.txt",ios::app);
        quantitylist.open("quantities.txt");
   	if(pricelist.is_open() && sale.is_open() && quantitylist.is_open()) //check that all files are opened or not
   	{
   		cout<<"file opened"<<endl;
   	}   
  }
  void bill(Customer &c)
  { int total =0;
     node<int>* t; 
      t=c.pickfrombasket();  //pick address from basket
  
while(t!=NULL)
    { 
      total =total + getprice(t->giveitemid()) * (t->givequantity()); //get values in basket 
        t=c.pickfrombasket(); 
     }
     cout <<BOLD<< "--------------------------------------------------"<<RESET<<endl;
 	cout<<BGREEN<<"TOTAL: Rs. "<<total<<RESET<<endl;
 int d=dcomputate(total);
cout<<BYELLOW<<"Discount: Rs. "<<d<<RESET<<endl;  
 cout<<BBLUE<<"Netpayable: Rs. "<<total-d<<RESET<<endl;
 cout <<BOLD<< "--------------------------------------------------"<<RESET<<endl;
   sale<<total<<endl;
}
  int getprice(int id)   //used get price of particular id from file PRICELIST 
  { int i=1,price;
    string s;
  for(i=1;i!=id;i++)
  {getline(pricelist,s);}  
   pricelist>>i>>price;
   return price;
  }
/************************************************************/
int check(int itemid,int quantity)
{ int i,itemq;
  string s;
  for(i=1;i<itemid;i++)
  {getline(quantitylist,s);}
  quantitylist>>i>>itemq;
  if(itemq>quantity)
  { return 1;}
  else
  {return 0;}
/*************************************************************/
}  


};

/******************************************* MAIN PROGRAM ***************************************************************/
int main()
{ 
	Customer c1;
  	int itemid,quantity,itemq;
  	FILES filesystem;
  	cout<<"SHOP NOW"<<endl;
  	cout<<"Enter itemid:";
   cin >> itemid; 	
	while(itemid) //do this unvalid itemid
  	{ 
		cout<<"quantity:";
		cin>>quantity;
 		
 		if(filesystem.check(itemid,quantity))
                {
                c1.shop(itemid,quantity); //adding item with quantity in basket of customer
              
 		}
                else
                {cout<<endl<<"Item quantity available is  unavailable"<<endl<<endl;} 
                cout<<"Enter itemid:";
		cin>>itemid;
                
       }
	c1.showitem();	
	filesystem.bill(c1);
 
return 0;
}
