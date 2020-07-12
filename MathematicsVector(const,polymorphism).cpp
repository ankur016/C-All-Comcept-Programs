#include<bits/stdc++.h>
using namespace std;
class Vector
{
private:
	int x,y,z;
public:
	Vector(int,int,int);
	Vector();
	void GetData();
	Vector operator+(const Vector &v)const;
	Vector operator-(const Vector &v)const;

	Vector operator*(const int k)const;
	Vector operator*(const Vector &v)const;
	Vector operator-()const;
	void DotProd(Vector);

	ostream & Show(ostream & out)const;
	friend Vector operator*(const int k,const Vector &v);
	friend ostream & operator<<(ostream & out,const Vector &v)
	{
		v.Show(out);
	    return out;
	}
};




int main()
{
	system("cls");
	Vector A,B,C;
	int k,ch;
	char choice = 'y';
	do
	{
		if(choice == 'y' || choice == 'Y')
		{
			cout<<"INPUT VECTOR\n";
			cout<<"ENTER THE FIRST VECTOR.\n";
			A.GetData();
			cout<<"ENTER THE SECOND VECTOR.\n";
			B.GetData();
		}

		system("cls");
		cout<<"PROGRAM FOR VECTOR OPERATIONS.\n";
		cout<<"First Vector(A)= "<<A<<"	\nSecond Vector(B)= "<<B<<" ";
		cout<<"	1.Addition Of Two Vectors.\n";
		cout<<"	2.Subtraction Of Two Vectors.\n";
		cout<<"	3.Multiplication Of A Vector With The Scalar.\n";
		cout<<"	4.Cross Product Of Two Vectors.\n";
		cout<<"	5.Scalar(or Dot) Product Of Two Vectors.\n";
		cout<<"	6.Negative Of Vectors.\n";
		cout<<"	7.Exit\n\n";
		cout<<"Enter The Choice. ";
		cin>>ch;
	    switch(ch)
		{
			case 1:
				cout<<"ADDITION OF TWO VECTORS.\n\n";
				C = A + B;
				cout<<"The Value Of A+B Is: "<<C;
				break;
			case 2:
				cout<<"\nSUBTRACTION OF TWO VECTORS.";
				C = A - B;
				cout<<"\nThe Value Of A-B Is: "<<C;
				break;
			case 3:
				cout<<"\nMULTIPLICATION OF A VECTOR WITH A SCALAR.";
				cout<<"\nEnter The Value Of The Scalar: ";
				cin>>k;
				C = A * k;
				cout<<"\nThe Value Of Ak Is (k Is the Scaler): "<<C;
				C = k * B;
				cout<<"\nThe Value Of kB Is (k Is the Scaler): "<<C;
				break;
			case 4:
				cout<<"CROSS PRODUCT OF TWO VECTORS.\n\n";
				C = A * B;
				cout<<"\nThe Value Of A*B(Cross Product) Is: "<<C;
				break;
			case 5:
				cout<<"\nSCALAR(OR DOT) PRODUCT OF TWO VECTORS.";
				A.DotProd(B);
				break;
			case 6:
				cout<<"NEGATIVE OF A VECTOR.\n\n";
				C = -A;
				cout<<"\nThe Value Of -A Is: "<<C;
				C = -B;
				cout<<"\nThe Value Of -B Is: "<<C;
				break;
			case 7:
				return 0;
			default:
				cout<<"WRONG CHOICE.\n";
				break;

		}
		cout<<"\nDO YOU WANT TO ENTER A NEW VECTOR (y/n): ";
		cin>>choice;
		system("cls");
	}while(1);
	return 0;
}





Vector::Vector():x(0),y(0),z(0)
{

}

Vector Vector::operator +(const Vector &v)const
{
	Vector res;
	res.x = x + v.x;
	res.y = y + v.y;
	res.z = z + v.z;
	return res;
}

Vector Vector::operator -(const Vector &v)const
{
	Vector res;
	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;
	return res;
}

Vector Vector::operator *(const int k)const
{
	Vector res;
	res.x = k * x;
	res.y = k * y;
	res.z = k * z;
	return res;
}

void Vector::GetData()
{
	cout<<"\nEnter The Value Of x : ";
	cin>>x;
	cout<<"\nEnter The Value Of y : ";
	cin>>y;
	cout<<"\nEnter The Value Of z : ";
	cin>>z;
}

Vector operator *(int k,const Vector &v)
{
	return v * k;
}

Vector Vector::operator -()const
{
	Vector res;
	res.x = -x;
	res.y = -y;
	res.z = -z;
	return res;
}

Vector Vector::operator *(const Vector &v)const
{
	Vector res;
	res.x = (y * v.z) - (z * v.y);
	res.y = (z * v.x) - (x * v.z);
	res.z = (x * v.y) - (y * v.x);
	return res;
}

void Vector::DotProd(Vector v2)
{
	int v1v2;
	v1v2 = (x * v2.x)+(y * v2.y)+(z * v2.z);
	cout<<"\nThe Value Of A.B Is: "<<v1v2;
}

ostream & Vector::Show(ostream & out)const
{
	if((x<0) && (y<0) && (z<0))
	out<<x<<"I"<<y<<"J"<<z<<"K\n";

	if((x<0) && (y<0) && (z>=0))
	out<<x<<"I"<<y<<"J+"<<z<<"K\n";

	if((x<0) && (y>=0) && (z<0))
	out<<x<<"I+"<<y<<"J"<<z<<"K\n";

	if((x<0) && (y>=0) && (z>=0))
	out<<x<<"I+"<<y<<"J+"<<z<<"K\n";

	if((x>=0) && (y<0) && (z<0))
	out<<x<<"I"<<y<<"J"<<z<<"K\n";

	if((x>=0) && (y<0) && (z>=0))
	out<<x<<"I"<<y<<"J+"<<z<<"K\n";

	if((x>=0) && (y>=0) && (z<0))
	out<<x<<"I+"<<y<<"J"<<z<<"K\n";

	if((x>=0) && (y>=0) && (z>=0))
	out<<x<<"I+"<<y<<"J+"<<z<<"K\n";

	return out;
}






