#include <iostream>

using namespace std;

void clear_cin()
{
	while (cin.get() != '\n') {
		continue;
	}
}

class Student
{
	string name, class_name, dob, blood_group, contact_address, tel_no, dl_no;
	int roll_no;
	char *division;
	
 public:
	Student()
	{
		division = new char;
		read_info();
	}

	~Student()
	{
		delete division;
	}
		
	Student(Student &obj) : name(obj.name), class_name(obj.class_name), division(new char), roll_no(obj.roll_no), dob(obj.dob), blood_group(obj.blood_group), contact_address(obj.contact_address), tel_no(obj.tel_no), dl_no(obj.dl_no) { *division = *obj.division;}
	void read_info()
	{
		cout<<"Enter student's name: ";
		getline(cin, name);
		cout<<"Enter student's class: ";
		getline(cin, class_name);
		cout<<"Enter student's division: ";
		cin>>division;
		cout<<"Enter student's roll number: ";
		cin>>roll_no;
		clear_cin();
		cout<<"Enter student's date of birth: ";
		getline(cin, dob);
		cout<<"Enter student's blood group: ";
		getline(cin, blood_group);
		cout<<"Enter student's contact address: ";
		getline(cin, contact_address);
		cout<<"Enter student's telephone number: ";
		getline(cin, tel_no);
		cout<<"Enter student's driving license number: ";
		getline(cin, dl_no);
	}

	void display_info()
	{
		cout<<"\nName: "<<name<<endl;
		cout<<"Class: "<<class_name<<endl;
		cout<<"Divsion: "<<division<<endl;
		cout<<"Roll Number: "<<roll_no<<endl;
		cout<<"Date Of Birth: "<<dob<<endl;
		cout<<"Blood Group: "<<blood_group<<endl;
		cout<<"Contact Address: "<<contact_address<<endl;
		cout<<"Telephone Number: "<<tel_no<<endl;
		cout<<"Driving License Number: "<<dl_no<<endl;
	}
};

int main(void)
{
	Student s;
	s.display_info();

	Student new_s(s);
	new_s.display_info();
}
