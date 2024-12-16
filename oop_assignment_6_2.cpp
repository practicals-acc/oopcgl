#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ItemRecord
{
  private:
	int itemCode;
	string name;
	double cost;
	int quantity;

  public:
	ItemRecord(int code, string n, double c, int q) : itemCode(code), name(n), cost(c), quantity(q) {}

	int getItemCode() const { return itemCode; }
	string getName() const { return name; }
	double getCost() const { return cost; }
	int getQuantity() const { return quantity; }

	void display() const {
		cout << "Item Code: " << itemCode << ", Name: " << name
			 << ", Cost: " << cost << ", Quantity: " << quantity << endl;
	}
};

void displayRecords(const vector<ItemRecord>& records)
{
	for (size_t i = 0; i < records.size(); ++i) {
		records[i].display();
	}
}

// Comparison function for sorting by name
bool compareByName(const ItemRecord& a, const ItemRecord& b)
{
	return a.getName() < b.getName();
}

int main()
{
	vector<ItemRecord> records = {
		ItemRecord(101, "Laptop", 50000.0, 10),
		ItemRecord(102, "Smartphone", 20000.0, 25),
		ItemRecord(103, "Tablet", 15000.0, 15)
	};

	// Sorting records by name using a comparison function
	sort(records.begin(), records.end(), compareByName);

	cout << "Sorted Records:\n";
	displayRecords(records);

	// Searching for an item by name
	string searchName;
	cout << "\nEnter item name to search: ";
	cin >> searchName;

	vector<ItemRecord>::iterator it = find_if(records.begin(), records.end(), [&searchName](const ItemRecord& record) {
		return record.getName() == searchName;
	});

	if (it != records.end()) {
		cout << "\nItem Found:\n";
		it->display();
	} else {
		cout << "\nItem not found." << endl;
	}

	return 0;
}
