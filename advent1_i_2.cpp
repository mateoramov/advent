#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>


using namespace std;

int countOccurrences( char c, string &str)
{
	int count = 0;

	for (char i : str)
		if (i == c)
			count++;

	return count;
}
int main()
{
	string filename = "advent1_i_2.txt";
	ifstream input;
	int counter = 0;

	input.open(filename);

	if (!input.is_open()) {
		return -1;
	}

	while (input) {
		string line, line2, line3, line4;
		

		getline(input, line, '-');
		getline(input, line2, ' ');
		getline(input, line3, ':');
		getline(input, line4);
		if (!input)
			break;
		int num1 = stoi(line);
		int num2 = stoi(line2);
		char a = line3[0];
		char b = line4[num1 ];
		char c = line4[num2 ];

		if((a==b)!=(a==c)){
			counter++;
		}
		

	

		cout << line << line2 << line3 << line4 <<" "<< a << " " << b << " " << c <<endl;


	}
	cout << counter << endl;
	input.close();
	/*for (int k = 0; k < 1000; k++) {
		cout << line[k] << line2[k] << line3[k] << line4[k] << endl;
		//int n = std::count(line4[k].begin(), line4[k].end(), 'f');
		//if (n >= stoi(line[k]) && n <= stoi(line2[k])) {
		//	counter++;
		//}

	}
	cout << counter << endl;



		/*if (myfile.is_open())
		{
			while (!myfile.eof())
			{
				getline(myfile, line);
				array[loop] = line;
				cout << array[loop] << endl;
				loop++;
			}
			myfile.close();
		}
		/*loop = 0;
		for (int i = 0; i < 200; i++) {
			for (int j = i + 1; j < 200; j++) {
				for (int k = j + 1; k < 200; k++) {
					if (array[i] + array[j] + array[k] == 2020) {
						cout << array[i] << endl;
						cout << array[j] << endl;
						cout << array[k] << endl;
						loop = array[i] * array[j] * array[k];
					}
				}

			}
		}
		cout << loop << endl;*/

		return 0;
	}