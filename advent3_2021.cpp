
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

string func(vector<string> vect, int number) { 
	string str,line2;
	char c,ch,ch2;
	int num=0;
	int br = 0;
	if (number == 1) {
		ch = '0';
		ch2 = '1';
	}
	else {
		ch = '1';
		ch2 = '0';
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < vect.size(); j++) {
			line2 = vect[j];
			c = line2[i];
			if (c == '0') {
				num--;
			}
			else
				num++;
		}
		int k = vect.size();
		if (num >= 0 && k>1) {
				for (int y = 0; y < k; y++)
				{
					line2 = vect[y];
					c = line2[br];
					if (c == ch) {
						vect.erase(vect.begin() + y);
						k--;
						y--;
					}
				}
				br++;

			
		}
		else if (num <0 && k>1) {
				for (int y = 0; y < k; y++)
				{
					line2 = vect[y];
					c = line2[br];
					if (c == ch2) {
						vect.erase(vect.begin() + y);
						k--;
						y--;
					}
				}
				br++;
			

		}
		num = 0;

	}
	str = vect[0];
	return str;
}

int main() {
	map<string, int> strMap;
	vector<string> numbers;
	string filename = "advent3_2021.txt";
	ifstream input;
	input.open(filename);
	string line, line2, line3;
	while (getline(input, line, '\n')) {   // get a whole line
		numbers.push_back(line);
	}
	line2 = func(numbers,1);
	line3 = func(numbers, 0);
	cout << line2 << " "<< line3<<endl;
	
	long binnum = stol(line2,0,2);
	long binnum2 = stol(line3,0,2);
	cout << binnum * binnum2<<  endl;
	
	input.close();
	return 0;
}