#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
class person{
	string name;
	int age;
	char gender;
	string mob;
	public :
		getdetail(string n,int ag,char g,string m)
		{
			name=n;
			age=ag;
			gender=g;
			mob=m;
		}
		void change_gender(char gender)
		{
			this->gender=gender;
		}
		void change_name(string name)
		{
			this->name=name;
		}
		void change_age(int age)
		{
			this->age=age;
		}
		string getname()
		{
			return name;
		}
		int getage()
		{
			return age;
		}
		char getgender()
		{
			return gender;
		}
};
class canteen{
	//string canteenname;
	string na;
	vector<string> menu;
	 int total_persons;
	vector<person> reg_stud;
	public :

		canteen()
		{
			//this->canteenname=canteenname;
			cout<<"Enter Menu For And Press 1 To Exit :-\n";
			while(1)
			{
				string dish;
				cout<<"enter dish name :";
				cin>>dish;
				if(dish[0]=='1'){
					break; }
				else
				{
					menu.push_back(dish);
				}
			}
			total_persons=0;
		}
		void registration()
		{
			cout<<"\nenter name:-";
			cin>>na;
			int age;
			cout<<"\nenter age:-";
			cin>>age;
			char gender;
			cout<<"\nenter gender M/F:-";
			cin>>gender;
			cout<<"enter mobile no:-";
			string mob;
			cin>>mob;
			total_persons++;
			//cout<<"total no of person="<<total_persons;
			person s;
			s.getdetail(na,age,gender,mob);
			reg_stud.push_back(s);

		}
	    void show_menu(){
			cout<<"\n Menu is as follows :-\n";
			for(int i=0;i<menu.size();i++)
			{
				cout<<menu[i]<<"\n";
			}
		}
		void add_dish(string dish)
		{
		 menu.push_back(dish);
		}
	   void remove_dish(string dish)
		{
			int i;
			for(i=0;i<menu.size();i++)
			if(dish==menu[i])
			break;
			menu.erase(menu.begin()+i);
		}
	    void show_person_detail()
		{
			int i;
			cout<<"name \t"<<"age \t"<<"gender \n";
			for(i=0;i<reg_stud.size();i++)
			{
				cout<<reg_stud[i].getname()<<" \t";
				cout<<reg_stud[i].getage()<<" \t";
				cout<<reg_stud[i].getgender()<<" \n";
			}
		}
		void  count()
		{
			cout<<"total persons registered is :="<<total_persons;

		}
};
int main()
{
    canteen mm1;
    string dish1;
    label :
    cout<<"\n1.for exit\n2.for person registration\n3.for adding dish in menu only for canteen\n4.for removing menu\n5.for showing menu\n";
    cout<<"6.for knowing person detail\n";
    cout<<"Please Enter Your Choice:-";
    int choice; cin>>choice;
    switch(choice)
    {
    	case 1:
    		exit(1);
    		break;
        case 2 :
    	mm1.registration();
    	break;
    	case 3 :
    	cout<<"\nplease enter your dish name:-";
    	cin>>dish1;
    	mm1.add_dish(dish1);
    	break;
    	case 4:
    	cout<<"\nplease enter your dish name:-";
    	cin>>dish1;
    	mm1.remove_dish(dish1);
    	break;
    	case 5:
    	mm1.show_menu();
    	break;
    	case 6:
    	mm1.show_person_detail();
    	mm1.count();

    }
    goto label;



}
