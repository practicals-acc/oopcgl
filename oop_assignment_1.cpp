#include <iostream>

using namespace std;

class Complex
{
	float a, b;
 public:
	Complex()
	{
		a = 0;
		b = 0;
	}
	
	Complex operator+(const Complex c)
	{
		Complex sum;
		sum.a = a + c.a;
		sum.b = b + c.b;
		return sum;
	}
	
	Complex operator*(const Complex c)
	{
		Complex product;
		product.a = (a * c.a) - (b * c.b);
		product.b = (b * c.a) - (a * c.b);	
		return product;
	}

	friend istream& operator>>(istream& in, Complex& c)
	{
		cout<<"Enter real part: ";
		in>>c.a;
		cout<<"Enter imaginary part: ";
		in>>c.b;
	}

	friend ostream& operator<<(ostream& out, Complex& c)
	{
		out<<c.a<<"+"<<c.b<<"i";
	}
};

int main(void)
{
	Complex c1, c2, c3, c4;
	cout<<"\nEnter first complex number: \n";
	cin>>c1;
	cout<<"\nEnter second complex number: \n";
	cin>>c2;

	cout<<"\nFirst number: ";
	cout<<c1<<endl;
	cout<<"Second number: ";
	cout<<c2<<endl;

	c3 = c1 + c2;
	c4 = c1 * c2;

	cout<<"\nAddition = ";
	cout<<c3<<endl;
	cout<<"Multiplication = ";
	cout<<c4<<endl;

	return 0;
}
