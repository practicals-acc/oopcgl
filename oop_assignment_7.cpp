#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	string state_in;
	string state_lower = "";
	map<string, string> statePopulationMap;
	
	statePopulationMap["maharashtra"] = "112374333"; 
	statePopulationMap["rajasthan"] = "68548437";
	statePopulationMap["uttar pradesh"] = "199812341";
	statePopulationMap["gujarat"] = "60439692";
	statePopulationMap["goa"] = "1458545";
	statePopulationMap["andhra pradesh"] = "49577103";
	
	/* OR (using initializer lists supported in C++11)
	statePopulationMap = {
		{"maharashtra", "112374333"},
		{"rajasthan", "68548437"},
		{"uttar pradesh", "199812341"},
		{"gujarat", "60439692"},
		{"goa", "1458545"},
		{"andhra pradesh", "49577103"}
	};
	*/
	
	cout<<"Enter the name of the state: ";
	getline(cin, state_in);
	
	
	for (int i = 0; state_in[i] != '\0'; i++)
		state_lower += tolower(state_in[i]);
	/* OR (using range based for-loops supported in C++11)
	for (char ch: state_in)
		state_lower += tolower(ch);
	*/

	if (statePopulationMap.find(state_lower) != statePopulationMap.end()) {
		cout<<"Population: "<<statePopulationMap[state_lower]<<endl;
	} else {
		cout<<"Population not found/available"<<endl;
	}
	return 0;
}
