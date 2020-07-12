#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class car
{
	string brand,dop,modelno;
	float price;
	static int cnt;
	int age;
	static float depriciation ;
	int currval;
	int currspeed;
	int gear;
	public :
		car()
		{
			cnt++;
		}
		car(string a,string d,float p,string mdno)
		{
			modelno=mdno;
			//model=t;
			brand=a;
			dop=d;
			currval=p;
			price = p;
			currspeed=0;
			age=0;
			
			cnt++;
		}
		read()
		{
			cout<<"\nenter car model no.:=";
			cin>>modelno;
			cout<<"\nenter brand:-";
			cin>>brand;
			cout<<"\nenter price:=";
			cin>>price;
			cout<<"\nenter Date Of Purchase:=";
			cin>>dop;
			cout<<"\nEnter Gear:=";
			cin>>gear;
			currspeed=0;
		}
		void showdetail()
		{
			cout<<"\ncar model:-";
			cout<<modelno;
			cout<<"\nbrand:-";
			cout<<brand;
			cout<<"\nprice:=";
			cout<<price;
			cout<<"\nDate of Purchase:=";
			cout<<dop<<"\n";
			cout<<"Current Gear:=";
			cout<<gear<<"\n";
			cout<<"Current Speed:=";
			cout<<currspeed<<"\n";
			//cout<<"Current Value Is:= ";
			//cout<<currval;
		    
			
		}
		int  calculate_years_in_market(string curdate)
		{
			int d,m,y;
			int cd,cm,cy;
			d=(dop[0]-'0')*10+(dop[1]-'0');
			m=(dop[3]-'0')*10+(dop[4]-'0');
			y=(dop[6]-'0')*1000+(dop[7]-'0')*100+(dop[8]-'0')*10+(dop[9]-'0');
			cd=(curdate[0]-'0')*10+(curdate[1]-'0');
			cm=(curdate[3]-'0')*10+(curdate[4]-'0');
			cy=(curdate[6]-'0')*1000+(curdate[7]-'0')*100+(curdate[8]-'0')*10+(curdate[9]-'0');
			if(cd<d)
			{
				cd+=30;
				cm--;
			}
			d=cd-d;
			if(cm<m)
			{
				cm+=12;
				cy--;
			}
			m=cm-m;
			y=cy-y;
			cout<<"No of Years Car In The Market:"<<y<<endl;
			return y;
		}
		static int noOfcarspurchaseed()
		{
			cout<<"Total "<< cnt <<" "<<"Cars has been Purchaseed\n";
			return cnt;
		}
		void speedup()
		{
			cout<<"speed increased \n";
			currspeed=currspeed+10;
		}
		void speeddown()
		{
			cout<<"speed decreased \n";
			currspeed=currspeed-10;
		}
		void gearup()
		{
			cout<<"gear increased \n";
			gear++;
		}
		void geardown()
		{
			cout<<"gear decreased \n";
			gear--;
		}
		static void set_depriciation_rate(float r)
		{
			depriciation = r;
		}
		void calculate_currvalue(string curdate)
		{
			age=calculate_years_in_market(curdate);
			currval=price-(price*depriciation*age)/100;
			cout<<"current vlue of car is :="<<currval<<"\n";
		}
};
int car::cnt=0;
float car::depriciation=5.00;
int main()
{
	car b1("Renault","12-04-2018",250000,"RNQ12345");
	//car b2(b1);
	
	string cur;
    car b3;b3.read();
    label:
    cout<<"please enter your choices"<<endl;
    cout<<"1.speedup\n2.speeddown\n3.gearup\n4.geradown\n5.car current details\n6.total no of cars\n7.exit\n";
    int choice; cin>>choice;
    
    switch(choice)
    {
    	case 1:
    		b3.speedup();
    		break;
    	case 2:
    		b3.speeddown();
    		break;
    	case 3:
    		b3.gearup();
    		break;
    	case 4:
    		b3.geardown();
    		break;
    	case 5:
    		b3.showdetail();
    		cout<<"enter current date:="; cin>>cur;
    		b3.calculate_years_in_market(cur);
		    b3.calculate_currvalue(cur);
    		break;
    	case 6:
    		b3.noOfcarspurchaseed();
    		break;
    		case 7:
    			exit(1);
    		
   	}
   	goto label;
	return 0;
}
