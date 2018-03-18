#include <iostream>
#include "Set.h"
#include <string>

using namespace std;

int main() {
	/* ====================== EXAMPLE USING INTEGERS ====================== */

	const int arr1[] = {5, -8, 56, 23, 88, 21, -8, 4};
	const int n1 = sizeof(arr1) / sizeof(arr1[0]);
	Set<int> set1(arr1, n1);

	cout << "set1: " << endl;
	cout << set1 << endl;

	const int arr2[] = {244, 58, -85, 23, 58, 244, 64, 2148};
	const int n2 = sizeof(arr2) / sizeof(arr2[0]);
	Set<int> set2(arr2, n2);

	cout << "set2: " << endl;
	cout << set2 << endl;

	Set<int> set3;
	cout << "set3: " << endl;
	cout << set3 << endl;

	set3 = set1 + set2;
	cout << "set3 = set1 + set2: " << endl;
	cout << set3 << endl;

	set3 = 3 * set2;
	cout << "set3 = 3 * set2: " << endl;
	cout << set3 << endl;

	set3 = set1 * 0.5;
	cout << "set3 = set1 * 0.5: " << endl;
	cout << set3;
	cout << "sum: " << set3.getSum() << endl;
	cout << "set3[2] = " << set3[2] << endl;
	cout << "set3[-2] = " << set3[-2] << endl
		 << endl;

	cout << "odd: " << endl
		 << set3.getOddNumbers() << endl;
	cout << "even: " << endl
		 << set3.getEvenNumbers() << endl;

	cout << "set1 < set2 = " << (set1 < set2) << endl;
	cout << "set2 > set3 = " << (set2 > set3) << endl;

	cout << "remove 56 from set1: " << endl;
	set1.remove(56);
	cout << set1 << endl;

	cout << "add 76 to set1: " << endl;
	set1.add(76);
	cout << set1 << endl;

	cout << "index of 76: ";
	cout << set1.indexOf(76) << endl;

	/* ====================== EXAMPLE EXAMPLE STRINGS ====================== */

	const string arrStr[] = { "lorem", "ipsum", "dolor", "sit", "dolor" };
	const int nStr = sizeof(arrStr) / sizeof(arrStr[0]);
	Set<string> setStr(arrStr, nStr);

	cout << "setStr: " << endl;
	cout << setStr << endl;

	cout << "remove \"consectetur\": " << endl;
	setStr.remove("consectetur");
	cout << setStr << endl;

	cout << "remove \"ipsum\": " << endl;
	setStr.remove("ipsum");
	cout << setStr << endl;

	cout << "add \"amet\": " << endl;
	setStr.add("amet");
	cout << setStr << endl;

	cout << "index of \"dolor\": ";
	cout << setStr.indexOf("dolor") << endl;

	system("pause");
	return 0;
}