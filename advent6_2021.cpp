
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
	std::vector<int> numbers = { 3,4,3,1,2 };
	int num = 5;
	for (int i = 0; i <18; i++) {
		int k = numbers.size();
		for (int j = 0; j < k;j++) {
			if (numbers[j] == 0) {
				numbers[j] == 6;
				num++;
			}
			else
				numbers[j]--;
		}

	}
		
	cout << endl << num<< endl;
	return 0;
}