#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	fstream file;
	
	file.open("output_file.txt", ios::out);
	file<<"This is some information"<<endl;
	file<<"in the output_file.txt";
	file.close();

	file.open("output_file.txt", ios::in);
	string line;
	while (getline(file, line) != 0)
		cout<<line<<endl;
	file.close();
	return 0;
}
