
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int size = 3;
	int sumBothArray = 0;
	int sumDifferenceArray = 0;
	vector<int> arrayA(size);
	vector<int> arrayB(size);
	vector<int> differenceArray(size);

	vector<int> arrayY;

	cout << endl;

	srand(static_cast<unsigned int>(time(nullptr)));

	

	for (int i = 0; i < size; i++) {
		arrayA[i] = rand() % 10 + 1;
		arrayB[i] = 10 - arrayA[i];
		differenceArray[i] = arrayA[i] - arrayB[i];
	}

	cout << "Array A: ";
	for (int i = 0; i < size; i++) {
		cout << arrayA[i] << " ";
	}
	cout << endl;

	cout << "Array B: ";
	for (int i = 0; i < size; i++) {
		cout << arrayB[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size; i++) {
		sumBothArray = arrayA[i] + arrayB[i];
	}

	cout << "Sum of both array is : " << sumBothArray << endl;

	for (int i = 0; i < size; i++) {
		differenceArray[i] = abs(differenceArray[i]);
	}

	cout << "Difference Array: ";
	for (int i = 0; i < size; i++) {
		cout << differenceArray[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size; i++) {
		sumDifferenceArray = sumDifferenceArray + differenceArray[i];
	}
	cout << "Sum of Difference Array: "<< sumDifferenceArray << endl;

	int maxDifference = differenceArray[0];
	for (int i = 1; i < size; i++) {
		if (differenceArray[i] > maxDifference) {
			maxDifference = differenceArray[i];
		}
	}
	cout << "Maximum Difference: " << maxDifference << endl;

	int targetSum = 10;
	vector<vector<int>> arrayX;

	for (int i = 0; i <= targetSum; i++) {
		for (int j = 0; j <= targetSum - i; j++) {
			int k = targetSum - i - j;
			if (i >= 0 && i <= 10 && j >= 0 && j <= 10 && k >= 0 && k <= 10) {
				vector<int> combination = { i, j, k };
				arrayX.push_back(combination);
			}
		}
	}

	cout << "Combinations of 3 values between 0 and 10 whose sum is 10 (stored in arrayX):" << endl;
	for (const vector<int>& combination : arrayX) {
		cout << combination[0] << " + " << combination[1] << " + " << combination[2] << " = 10" << endl;
	}

	for (int i = 0; i < arrayX.size(); i++) {
		for (int j = 0; j < arrayX.size(); j++) {
			if (i != j) {
				int sum1 = arrayX[i][0] + arrayX[i][1] + arrayX[i][2];
				int sum2 = arrayX[j][0] + arrayX[j][1] + arrayX[j][2];
				int sum3 = arrayX[j][0] + arrayX[j][1] + arrayX[j][2];

				int distance = abs(sum1 - sum2);
				//int distance = max(abs(arrayX[i][0] - arrayX[j][0]), abs(arrayX[i][1] - arrayX[j][1]), abs(arrayX[i][2] - arrayX[j][2]) );
				//arrayY.push_back(distance);

				int dif1_0 = abs(arrayX[i][0] - arrayX[j][0]);
				int dif1_1 = abs(arrayX[i][1] - arrayX[j][1]);
				int dif1_2 = abs(arrayX[i][2] - arrayX[j][2]);

				int maxi = max(dif1_0, dif1_1);
				int maxi1 = max(maxi, dif1_2);

				cout << "Maximum : "<<maxi1 << endl;
			}
		}
	}

	/*cout << "\nDistances between combinations (stored in arrayY):" << endl;
	for (int distance : arrayY) {
		cout << distance << " ";
	}*/

	




	return 0;	
}

