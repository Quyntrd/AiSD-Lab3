#include <iostream>
#include <random>
#include <vector>
#include <sorts.cpp>


#define SIZE 1000

using namespace std;


int main() {
	stats stat1;
	vector<int> arr = { 1, 3, 5, 2, 20, 9, 10, 43, 4, 7 , 11};
	vector<int> arr1 = { 1, 3, 5, 2, 20, 9, 10, 43, 4, 7 , 11};
	vector<int> arr2 = { 1, 3, 5, 2, 20, 9, 10, 43, 4, 7 , 11};
	//�������� ����������������� ����������
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


	//���������� ��������� ��� 100 ���������, 1 ���������������� � 1 ���������������� ��������
	{
		cout << "Bubble sort tests" << endl << endl;
		size_t sum_comparison = 0, sum_copy = 0;
		for (int i = 0; i < 100; ++i) {
			vector<int> arr = generate_random(SIZE);
			stats tmp = bubble_sort(arr);
			sum_comparison += tmp.comp_count;
			sum_copy += tmp.copy_count;
		}
		cout << "size: " << SIZE << endl;
		cout << "Average comparison quantity: " << sum_comparison / 100 << endl;
		cout << "Average copy quantity: " << sum_copy / 100 << endl;

		vector<int> sorted = generate_sorted(SIZE);
		stats sorted_stats = bubble_sort(sorted);
		cout << "size: " << SIZE << endl;
		cout << "comparison quantity for sorted vector: " << sorted_stats.comp_count << endl;
		cout << "copy quantity for sorted vector: " << sorted_stats.copy_count << endl;

		vector<int> inverted = generate_inverted(SIZE);
		stats inverted_stats = bubble_sort(inverted);
		cout << "size: " << SIZE << endl;
		cout << "comparison quantity for inverted vector: " << inverted_stats.comp_count << endl;
		cout << "copy quantity for inverted vector: " << inverted_stats.copy_count << endl << endl;
	}
	//���������� ��������� ��� 100 ���������, 1 ���������������� � 1 ����������������
	{
		cout << "Comb sort tests" << endl << endl;
		size_t sum_comparison = 0, sum_copy = 0;
		for (int i = 0; i < 100; ++i) {
			vector<int> arr = generate_random(SIZE);
			stats tmp = comb_sort(arr);
			sum_comparison += tmp.comp_count;
			sum_copy += tmp.copy_count;
		}
		cout << "size: " << SIZE << endl;
		cout << "Average comparison quantity: " << sum_comparison / 100 << endl;
		cout << "Average copy quantity: " << sum_copy / 100 << endl;

		vector<int> sorted = generate_sorted(SIZE);
		stats sorted_stats = comb_sort(sorted);
		cout << "size: " << SIZE << endl;
		cout << "comparison quantity for sorted vector: " << sorted_stats.comp_count << endl;
		cout << "copy quantity for sorted vector: " << sorted_stats.copy_count << endl;

		vector<int> inverted = generate_inverted(SIZE);
		stats inverted_stats = comb_sort(inverted);
		cout << "size: " << SIZE << endl;
		cout << "comparison quantity for inverted vector: " << inverted_stats.comp_count << endl;
		cout << "copy quantity for inverted vector: " << inverted_stats.copy_count << endl << endl;
	}
	// ��������� ���������� ��� 100 ���������, 1 ���������������� � 1 ����������������
	{
		cout << "Shake sort tests" << endl << endl;
		size_t sum_comparison = 0, sum_copy = 0;
		for (int i = 0; i < 100; ++i) {
			vector<int> arr = generate_random(SIZE);
			stats tmp = shake_sort(arr);
			sum_comparison += tmp.comp_count;
			sum_copy += tmp.copy_count;
		}
		cout << "size: " << SIZE << endl;
		cout << "Average comparison quantity: " << sum_comparison / 100 << endl;
		cout << "Average copy quantity: " << sum_copy / 100 << endl;

		vector<int> sorted = generate_sorted(SIZE);
		stats sorted_stats = shake_sort(sorted);
		cout << "size: " << SIZE << endl;
		cout << "comparison quantity for sorted vector: " << sorted_stats.comp_count << endl;
		cout << "copy quantity for sorted vector: " << sorted_stats.copy_count << endl;

		vector<int> inverted = generate_inverted(SIZE);
		stats inverted_stats = shake_sort(inverted);
		cout << "size: " << SIZE << endl;
		cout << "comparison quantity for inverted vector: " << inverted_stats.comp_count << endl;
		cout << "copy quantity for inverted vector: " << inverted_stats.copy_count << endl;
	}
	
}