#include<iostream>
using namespace std;

template<class T> class node
{ private:
  T itemid,quantity;
  node* nptr; 
 
 public:
 void setvalue(T it,T iq)
 {itemid=it;
  quantity=iq;
 nptr=NULL;
 }
 void nextptr(node* t)
 {nptr=t;}
 
 void data()
 {cout<<endl;
  cout<<BYELLOW<<"itemid: "<<RESET<<itemid<<" quantity: "<<quantity<<endl;}
 
node* nextnode()
 {return nptr;}

T giveitemid()
{return itemid;}

T givequantity()
{return quantity;}

}; 

template<class T> class list
{ private:
  node<T> *start,*tail;
 
  public:
  
list(){start=NULL; tail=NULL;}
 void add(int iid,int iiq)//this function add items in basket
 { 
   if(start==NULL)
   {
     start=new node<T>;
     start->setvalue(iid,iiq);
     tail=start; 
   }
  else
  { node<T> *temp=new node<T>;
     temp->setvalue(iid,iiq);
     tail->nextptr(temp);
    tail=temp;
   }

  }
 void traverse()
 { node<T> *t=start;
  while(t!=NULL)
  {t->data();

   t=t->nextnode();
  }
 }

 node<T>* pick() //this whole function return address of various nodes in basket
 {node<T>* temp;  
  temp=start;
  if(start!=NULL)
  {start=start->nextnode();}
  return temp;
  }

};

