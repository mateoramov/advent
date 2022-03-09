#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;


int main() {
	map<string, int> strMap;
	strMap.insert(pair<string, int>("forward", 0));
	strMap.insert(pair<string, int>("aim", 0));
	string filename = "advent4_2021.txt";
	ifstream input;
	input.open(filename);
	string line, line2, line3;
	while (getline(input, line, '\n')) {   // get a whole line
		std::stringstream ss(line);
		getline(ss, line2, ' ');
		getline(ss, line3, '\n');
		if (line2 == "down") {
			strMap["aim"] += stoi(line3);
		}
		else if (line2 == "up") {
			strMap["aim"] -= stoi(line3);
		}
		else {
			int num = stoi(line3);
			strMap[line2] += num;
			strMap["depth"] += num*strMap["aim"];
		}


	}
	cout << endl;

	for (map<string, int>::iterator p = strMap.begin();
		p != strMap.end(); ++p) {
		cout << p->first
			<< " ---- " << p->second << endl;
	}


	cout << "result:" << strMap["forward"] * strMap["depth"] << endl;



	input.close();
	return 0;
}