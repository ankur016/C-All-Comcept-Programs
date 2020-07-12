#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
standard Children
{
    int rno,standard;
    char Name[40];
public:
    Children(int r=0,int c=0,char *name="NULL")
    {
        rno=r;
        standard=c;
        strcpy(Name,name);
    }
    int getrno()
    {
        return rno;
    }
    char *getName()
    {
        return Name;
    }
    void display()
    {
        cout<<"Roll No: "<<rno<<"\tstandard: "<<standard<<"\nName: "<<Name<<endl;
    }
};
int main()
{
    int rno,cls,choice;
    char name[40];
    ofstream fout("Children.txt",ios::out|ios::binary|ios::app);
    char ch='y',ch2='y';
    while(ch2=='y'||ch2=='Y')
    {
        cout<<"\nChildren Menu\n1.Enter Records\n2.View Records\n3.Delete Record\n4.Search Record \n5.Exit\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            while(ch=='y'||ch=='Y')
            {
                cout<<"Enter Roll No and standard : ";
                cin>>rno>>cls;
                cout<<"Enter Name: ";
                cin>>name;
                Children stud(rno,cls,name);
                fout.write((char*)&stud,sizeof(stud));
                cout<<"Want to enter more records (y/n): ";
                cin>>ch;
            }
            fout.close();
        }   break;
        case 2:
        {
            ifstream fin("Children.txt",ios::in|ios::binary);
            if(!fin)
            {
                cout<<"Cannot open file!!!";
                break;
            }
            while(!fin.eof())
            {
                Children stud1;
                fin.read((char*)&stud1,sizeof(stud1));
                if(fin.eof())   break;
                stud1.display();
            }
            fin.close();
        }    break;
        case 3:
        {
            cout<<"Enter the Roll no that you want to delete : ";
            cin>>rno;
            ifstream fin("Children.txt",ios::in|ios::binary);
            ofstream fout("temp.txt",ios::out|ios::binary);
            int flag=1;
            while(!fin.eof())
            {
                Children stud;
                fin.read((char*)&stud,sizeof(stud));
                if(stud.getrno()!=rno)
                {
                    fout.write((char*)&stud,sizeof(stud));
                }
                else
                    flag=0;
                if(fin.eof())   break;
            }
            fin.close();
            remove("Children.txt");
            rename("temp.txt","Children.txt");
            if(flag==1)
                cout<<"Children Record Not found!!";
        }   break;
        case 4:
        {
            cout<<"Enter the Roll no that you want to search for : ";
            cin>>rno;
            ifstream fin1("Children.txt",ios::in|ios::binary);
            while(!fin1.eof())
            {
                Children stud1;
                fin1.read((char*)&stud1,sizeof(stud1));
                if(stud1.getrno()==rno)
                {
                    cout<<"Children Record found!! Details are:\n";
                    stud1.display();
                    system("pause");
                    break;
                }
                if(fin1.eof())   break;
            }
            if(fin1.eof())
                cout<<"Children Record Not found!!";
            fin1.close();
        }
        case 5:
            break;
        default:
            cout<<"Wrong input!!";
        }
        cout<<"\nWant to go back to menu (y/n) : ";
        cin>>ch2;
    }
    return 0;
}
