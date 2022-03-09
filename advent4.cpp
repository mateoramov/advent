/*#include<iostream>
using namespace std;
#define FILENAME "advent4.txt"
int main() {
	FILE *fp;
	char ch;
	int br = 0;
	string arr[50] = {};
	string str;
	int i = 0;
	//open file in read more
	fp = fopen(FILENAME, "r");
	if (fp == NULL) {
		printf("File \"%s\" does not exist!!!\n", FILENAME);
		return -1;
	}
	//read character by character and check for new line
	while ((ch = fgetc(fp)) != EOF) {
		
		str += ch;
		if (str[br] == '\n'&& str[br - 1] == '\n') {
			arr[i] = str;
			str = "";
			i++;
			br = -1;
		}
		br++;
			
	}
	//close the file
	fclose(fp);
	//print number of lines
	for (int j = 0; j < 20; j++) {
		printf("%c", arr[j]);
	}
	
	
	return 0;
}*/




#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

void tokenize(std::string const &str, const char delim,
	std::vector<std::string> &out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

int main() {
	const char delim = ':';
	map<string, string> strMap;
	

	/*
	strMap["Monday"] = "Montag";
	strMap["Tuesday"] = "Dienstag";
	strMap["Wednesday"] = "Mittwoch";
	strMap["Thursday"] = "Donnerstag";
	strMap["Friday"] = "Freitag";
	strMap["Saturday"] = "Samstag";
	// strMap.insert(make_pair("Sunday", "Sonntag"));
	strMap.insert(pair<string, string>("Sunday", "Sonntag"));

	for (map<string, string>::iterator p = strMap.begin();
		p != strMap.end(); ++p) {
		cout << "English: " << p->first
			<< ", German: " << p->second << endl;
	}

	cout << endl;

	strMap.erase(strMap.find("Tuesday"));

	for (map<string, string>::iterator p = strMap.begin();
		p != strMap.end(); ++p) {
		cout << "English: " << p->first
			<< ", German: " << p->second << endl;
	}
	*/
	string filename = "advent4.txt";
	ifstream input;
	int counter = 0;
	char ch;
	int br = 0;
	string arr[50] = {};
	string str;
	int i = 0;
	fstream fin(filename, fstream::in);
	while (fin >> noskipws >> ch) {
		arr[i] += ch;
		if (ch == '\n') {
			i++;
			br = -1;
		}
		br++;
	}
	//cout << arr[0] << arr[3] << endl;
	input.open(filename);
	int k = 0;
	for (int j = 0; j < 10; j++)
	{
		if (arr[j + 1] != "\n") {
			arr[k] = arr[j] + arr[j + 1];
		}
		else
		{
			k++;
		}
	}

	if (!input.is_open()) {
		return -1;
	}
	/*
	while (input) {
		string line;
		std::vector<std::string> out;
		
		getline(input, line);

		cout << line;


		while (getline(input, line,'\n')) {   // get a whole line
			std::stringstream ss(line);
			while (getline(ss, line, ' ')) {
				std::stringstream ss(line);
				while (getline(ss, line, ':')) {
					cout << line;
				}
				cout << endl;
				cout << endl;
			}
			cout << endl;
		}
		//getline(input, line,' ');
		//getline(input, line2, ' ');*/
	/*
		if (!input)
			break;
		int num1 = stoi(line);
		int num2 = stoi(line2);
		char a = line3[0];
		char b = line4[num1];
		char c = line4[num2];

		if ((a == b) != (a == c)) {
			counter++;
		}
		
		//tokenize(line, delim, out);

		//for (auto &line : out) {
			//std::cout << line ;
		//}
		//strMap[out.at[0]] = out.at[1];
		//cout << out[0]<< out[1]<< endl;

		//cout << line <<" --- " ;
		


	}
	for (map<string, string>::iterator p = strMap.begin();
		p != strMap.end(); ++p) {
		cout << p->first
			<< " ---- " << p->second << endl;
	}*/
	input.close();
	return 0;
}