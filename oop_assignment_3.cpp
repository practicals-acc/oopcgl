#include <iostream>

using namespace std;

class Publication
{
	string title;
	float price;
	
 public:
	void read_info()
	{
		cout<<"\nEnter the title: ";
		getline(cin, title);
		cout<<"Enter the price: ";
		cin>>price;
	}
	void display_info()
	{
		cout<<"\nTitle: "<<title<<endl;
		cout<<"Price: "<<price<<endl;
	}
};

class Book: Publication
{
	int page_count;
 public:
	Book()
	{
		read_info();
	}
	void read_info()
	{
		Publication::read_info();
		cout<<"Enter the page count: ";
		cin>>page_count;
		while (cin.get() != '\n') {
			continue;
		}
	}
	void display_info()
	{
		Publication::display_info();
		cout<<"Page Count: "<<page_count<<endl;
	}

};

class Tape: Publication
{
	float playing_time;
 public:
	Tape()
	{
		read_info();
	}
	void read_info()
	{
		Publication::read_info();
		cout<<"Enter the playing time: ";
		cin>>playing_time;
		while (cin.get() != '\n') {
			continue;
		}
	}
	void display_info()
	{
		Publication::display_info();
		cout<<"Playing Time: "<<playing_time<<endl;
	}
};

int main(void)
{
	Book bk;
	Tape tp;
	bk.display_info();
	tp.display_info();
}
