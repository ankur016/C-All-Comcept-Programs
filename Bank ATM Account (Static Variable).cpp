#include <bits/stdc++.h>
using namespace std;

class Atm
{
    string cardnumber,username,accno;
    int pin;
    float balance;
    public:
        void read()
        {
            cout<<"Enter Card Number of User = ";
            cin>>cardnumber;
            cout<<"Enter Pin of User = ";
            cin>>pin;
            cout<<"Enter User Name of User = ";
            cin>>username;
            cout<<"Enter Account Number of User = ";
            cin>>accno;
            cout<<"Enter Balance of User = ";
            cin>>balance;
        }
        float getBalance()
        {
            return balance;
        }
        void withdrawMoney()
        {
            int amt,pin0;
            cout<<"\nEnter Pin = ";
            cin>>pin0;
            if(pin0==pin)
            {
                cout<<"\nEnter Amount to be withdrawan = ";
                cin>>amt;
                if(amt%100==0)
                {
                    if(balance-amt>=0)
                    {
                        balance=balance-amt;
                    }
                }
                else
                {
                    cout<<"\nIncorrect Amount. Try Again.";
                    withdrawMoney();
                }
            }
            else
            {
                cout<<"\nWrong Pin.";
            }
        }
        void depositMoney(int amt)
        {
            int pin0;
            cout<<"\nEnter Pin = ";
            cin>>pin0;
            if(pin0==pin)
            {
                balance=balance+amt;
            }
            else
            {
                cout<<"\nWrong Pin.";
            }
        }
        void changePin(int newpin)
        {
            pin=newpin;
        }
};
class customer
{
	string name;
	float balance;
	static float rate;
	float interest_recieved;
	static int count,total_cust;
	int account_no;
	static float min_balance;
	public:
	customer()
	{
		balance=0;
		count=count+1;
		total_cust++;
		account_no=count;
		interest_recieved=0;
	}
	void add_cust()
	{
		cout<<"enter name :-";
		getline(cin,name);
	}
	void deposit_money(float x)
	{
		balance+=x;
	}
	void withdraw_money(int amt)
	{
		if(balance-amt>min_balance)
		{
			balance-=amt;
			cout<<"remaining balance is:-"<<balance<<"\n";
		}
		else
		 cout<<"Insufficient balance ";
	}
	void interest_recieve()
	{
		interest_recieved+=balance*rate;
		cout<<"interest recieved "<<interest_recieved<<"\n";
	}
	void showdata()
	{
		cout<<"account number:- "<<account_no<<"\n name :-"<<name<<"\n balance :-"<<balance<<"\n interest recieved:- "<<interest_recieved;
	    cout<<"\n";

	}

	static void totalcustomer()
	{
		cout<<"total number of customers is :-"<<total_cust<<"\n";
	}
};
int customer:: count=752300000;
int customer:: total_cust=0;
float customer:: rate=.10;
//int customer:: total_cust=0;
float customer:: min_balance=3000;

int main() {

	  Atm a;
    a.read();
    a.depositMoney(500);
    a.withdrawMoney();
    cout<<"\nCurrent Balance = "<<a.getBalance();
    a.changePin(2357);
	customer c1;
	int x;
	int choice;
	c1.add_cust();
	do{


	cout<<"MENU for customer \n";
	cout<<"1.exit\n2.deposit\n3.withdraw\n4.interest recieved\n5.details of customer\n6.total customer\n choice:-";
	cin>>choice;
	switch(choice)
	{
		case 2: cout<<"enter money you want to deposit ";
		        cin>>x;
		        c1.deposit_money(x);
		        break;
	   case 3:
	         cout<<"enter money you want to withdraw ";
	         cin>>x;
	         c1.withdraw_money(1000);
	         break;
	    case 4:c1.interest_recieve();
	       break;
	       case 5:c1.showdata();
	       break;
	      case 6:
	      c1.deposit_money(3000);

	}



	}
	while(choice!=1);



	return 0;
}
