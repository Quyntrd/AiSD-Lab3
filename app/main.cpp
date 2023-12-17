#include <iostream>
#include <random>
#include <vector>
#include <sorts.cpp>


#define SIZE 1000;

using namespace std;


int main() {
	stats stat1;
	vector<int> arr = { 1, 3, 5, 2, 20, 9, 10, 43, 4, 7 , 11};
	vector<int> arr1 = { 1, 3, 5, 2, 20, 9, 10, 43, 4, 7 , 11};
	vector<int> arr2 = { 1, 3, 5, 2, 20, 9, 10, 43, 4, 7 , 11};
	//ѕроверка работоспособности сортировок
	stat1 = bubble_sort(arr);
	cout << "comp count " << stat1.comp_count << " copy count " << stat1.copy_count << endl;
	stat1 = shake_sort(arr1);
	cout << "comp count " << stat1.comp_count << " copy count " << stat1.copy_count << endl;
	stat1 = comb_sort(arr2);
	cout << "comp count " << stat1.comp_count << " copy count " << stat1.copy_count << endl;
	for (int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
	cout << endl;
	for (int i = 0; i < arr1.size(); ++i) cout << arr1[i] << " ";
	cout << endl;
	for (int i = 0; i < arr2.size(); ++i) cout << arr2[i] << " ";
	cout << endl;
}