#include<bits/stdc++.h>
using namespace std;
class person{
	string name;
	int age;
	char gender;
	string mob;
	public :
		 void getdetail(string n,int ag,char g,string m)
		{
			name=n;
			age=ag;
			gender=g;
			mob=m;
		}
		void change_gender(char ch)
		{
			this->gender=ch;
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
class instagram{
	string id;
	person p;
	vector< pair <string,string > > msgsend ;
    vector< pair <string,string > > msgrecieved ;
	string images;
	public:
		instagram(string id,string name,int age,char gender,string m)
		{
			this->id=id;
			//this->name=name;
			p.getdetail(name,age,gender,m);
			//msg="";
			images="";
		}
		string getname()
		{
			return p.getname();
		}
	 void uploadimage(string image)
	{
		this->images+=image;
		cout<<"image has been uploaded\n";
	}

	void change_gender(char ch)
		{
			p.change_gender(ch);
		}
		void change_name(string name)
		{
			p.change_name(name);
		}
		void change_age(int age)
		{
			p.change_age(age);
		}
		void sendmsg(string  msg, instagram &to)
		{
			string rec_name=to.getname();
			msgsend.push_back({msg,rec_name});
			to.recieve(msg,p.getname());
		}
		void recieve(string msg,string name)
		{
			msgrecieved.push_back(make_pair(msg,name));
		}
		void about()
		{
			cout<<"name :"<<p.getname()<<"\n";
			cout<<"age :"<<p.getage()<<"\n";
			cout<<"gender :"<<p.getgender()<<"\n";
			cout<<"id :"<<id<<"\n";
		}
		void showimages()
		{
			for(int i=0;i<images.size();i++)
			{
				cout<<images[i]<<" ";
			}
			cout<<"\n";
		}
};
int main()
{
	instagram f1("pankajmaran@gmail.com","pankaj",22,'M',"12331412");
	instagram f2("abc@gmail.com","abc",22,'F',"23423434");
	f1.about();
	f2.about();
	f2.change_name("xyz");
	f1.uploadimage("image1");
	f1.uploadimage("image2");
	f1.showimages();
	f1.sendmsg("message",f2);
	f2.about();
	return 0;
}
