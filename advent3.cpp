#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>


using namespace std;

int func(int a, int b, char array[323][31]) {
	int i = 0, j = 0;
	int counter = 0;
	while (i < 322) {
		j = j + a;
		i=i+b;
		cout << array[i][j];
		if (array[i][j] == '#')
			counter++;
		if (j > (31-a-1))
			j = j - 31;
	}
	cout << endl << counter << endl;
	return counter;
}

int main()
{
	string filename = "advent3.txt";
	ifstream input;
	int counter2 = 0;
	char array[323][31] = {};
	int abc = 0;
	int rez=1;

	input.open(filename);

	if (!input.is_open()) {
		return -1;
	}

	for (int i = 0; i <323; i++) {
		for (int j = 0; j < 31; j++) {
			input >> array[i][j];
		}
	}

	input.close();
	
	for (int i = 0; i < 323; i++) {
		for (int j = 0; j < 31; j++) {
			cout << array[i][j];
		}
		cout << endl;
	}
	int a = 1, b = 1;
	for (int k = 0; k < 5; k++) {
		cout << endl;
		abc = func(a, b, array);
		a += 2;
		if (k == 3) {
			b = 2;
			a = 1;
		}
		rez = rez * abc;

	}
	
	cout <<endl<<rez<< endl;

	//cout << array[1][3] << array[2][6] << array[3][9] << array[4][1] << array[5][4] << array[6][7] << array[7][10] << array[8][2] << array[9][5] << array[10][8] << endl;

	return 0;
}