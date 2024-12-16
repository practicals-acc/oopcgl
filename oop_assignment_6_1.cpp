#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PersonalRecord
{
  private:
	string name;
	string dob;
	string phone;

  public:
	PersonalRecord(string n, string d, string p) : name(n), dob(d), phone(p) {}

	string getName() const { return name; }
	string getDOB() const { return dob; }
	string getPhone() const { return phone; }

	void display() const {
		cout << "Name: " << name << ", DOB: " << dob << ", Phone: " << phone << endl;
	}
};

void displayRecords(const vector<PersonalRecord>& records)
{
	for (size_t i = 0; i < records.size(); ++i) {
		records[i].display();
	}
}

// Comparison function for sorting
bool compareByName(const PersonalRecord& a, const PersonalRecord& b)
{
	return a.getName() < b.getName();
}

int main()
{
	vector<PersonalRecord> records = {
		PersonalRecord("Alice", "1995-06-15", "1234567890"),
		PersonalRecord("Bob", "1990-04-20", "9876543210"),
		PersonalRecord("Charlie", "1998-12-05", "5678901234")
	};

	// Sorting records by name using a comparison function
	sort(records.begin(), records.end(), compareByName);

	cout << "Sorted Records:\n";
	displayRecords(records);

	// Searching for a record by name
	string searchName;
	cout << "\nEnter name to search: ";
	cin >> searchName;

	vector<PersonalRecord>::iterator it = find_if(records.begin(), records.end(), [&](const PersonalRecord& record) {
		return record.getName() == searchName;
	}); // '[&]' capture all variables from the surrounding scope by reference

	if (it != records.end()) {
		cout << "\nRecord Found:\n";
		it->display();
	} else {
		cout << "\nRecord not found." << endl;
	}

	return 0;
}
