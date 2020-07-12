//Friend function
#include<bits/stdc++.h>
using namespace std;

class Date;
class Novel
{
    char *name;
    float price;
    char *author;
    int copies;
    float rating;

public:

    static int count_novels; //static variable

    Novel(char *n, char *a, float p, int c)
    {
        count_novels++;
        name=new char;
        author=new char;
        strcpy(name, n);
        strcpy(author, a);
        price=p;
        copies=c;
    }

    void Purchase(int q)
    {
        cout<<q<<"copies sold"<<endl;
        copies-=q;
    }

    void Rate(float r)
    {
        cout<<"Rating done"<<endl;
        rating=r;
    }

    void Show()
    {
        cout<<"Name :"<<name<<endl;
        cout<<"Author :"<<author<<endl;
        cout<<"Price :"<<price<<endl;
        cout<<"Rating :"<<rating<<endl;
        cout<<"Copies remaining :"<<copies<<endl;
    }

    ~Novel() //Destructor
    {
        cout<<"Destructor"<<endl;
        delete(name);
        delete(author);
    }

    static Count_types()
    {
        cout<<"Types of novel we have :"<<count_novels<<endl;
    }

    friend class Date;
};

int Novel::count_novels=0;

class Date
{
    int d, m, y;

public:

    void get_date(int x, int y, int z)
    {
        d=x;
        m=y;
        this->y=z;
    }

    friend class Novel;
};

int main()
{
    char n[20], a[20];
    float p;
    int c, q, r;
    cout<<"Adding novel"<<endl;
    cout<<"Enter the novel name"<<endl;
    cin>>n;
    cout<<"Enter the author name"<<endl;
    cin>>a;
    cout<<"Enter the novel price"<<endl;
    cin>>p;
    cout<<"Enter the novel copies"<<endl;
    cin>>c;
    Novel n1(n,a, p, c);
    cout<<"Enter the copies you want to purchase"<<endl;
    cin>>q;
    n1.Purchase(q);
    cout<<"Rate the novel"<<endl;
    cin>>r;
    n1.Rate(r);
    n1.Show();
    cout<<"Enter the novel name"<<endl;
    cin>>n;
    cout<<"Enter the author name"<<endl;
    cin>>a;
    cout<<"Enter the novel price"<<endl;
    cin>>p;
    cout<<"Enter the novel copies"<<endl;
    cin>>c;
    Novel n2(n, a, p, c);
    cout<<"Enter the copies you want to purchase"<<endl;
    cin>>q;
    n2.Purchase(q);
    cout<<"Rate the novel"<<endl;
    cin>>r;
    n2.Rate(r);
    n1.Show();
    Novel::Count_types();
 return 0;
}
