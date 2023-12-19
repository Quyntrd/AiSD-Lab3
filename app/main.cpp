#include <iostream>
#include <random>
#include <vector>
#include <sorts.cpp>


#define SIZE 3000
#define SEED 10

using namespace std;


int main() {
	stats stat1;
	vector<int> arr = { 1, 3, 5, 2, 20, 9, 10, 43, 4, 7 , 11};
	vector<int> arr1 = { 1, 3, 5, 2, 20, 9, 10, 43, 4, 7 , 11};
	vector<int> arr2 = { 1, 3, 5, 2, 20, 9, 10, 43, 4, 7 , 11};
	vector<int> arr3 = { 1, 3, 5, 2, 20, 9, 10, 43, 4, 7 , 11 };
	vector<int> arr4 = { 1, 3, 5, 2, 20, 9, 10, 43, 4, 7 , 11 };
	vector<int> arr5 = { 1, 3, 5, 2, 20, 9, 10, 43, 4, 7 , 11 };
	vector<int> arrrand = generate_random(20, SEED);
	//Проверка работоспособности сортировок
	stat1 = bubble_sort(arr);
	cout << "comp count for bubble " << stat1.comp_count << " copy count " << stat1.copy_count << endl;
	stat1 = shake_sort(arr1);
	cout << "comp count for shake " << stat1.comp_count << " copy count " << stat1.copy_count << endl;
	stat1 = comb_sort(arr2);
	cout << "comp count for comb " << stat1.comp_count << " copy count " << stat1.copy_count << endl;
	for (int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
	cout << endl;
	for (int i = 0; i < arr1.size(); ++i) cout << arr1[i] << " ";
	cout << endl;
	for (int i = 0; i < arr2.size(); ++i) cout << arr2[i] << " ";
	cout << endl;

	stats stat12 = bubble_sort_it(arr3.begin(), arr3.end());
	cout << "comp count for bubble " << stat12.comp_count << " copy count " << stat12.copy_count << endl;
	stat1 = shake_sort_it(arr4.begin(), arr4.end());
	cout << "comp count for shake " << stat1.comp_count << " copy count " << stat1.copy_count << endl;
	stat1 = comb_sort_it(arr5.begin(), arr5.end());
	cout << "comp count for comb " << stat1.comp_count << " copy count " << stat1.copy_count << endl;
	for (int i = 0; i < arr3.size(); ++i) cout << arr3[i] << " ";
	cout << endl;
	for (int i = 0; i < arr4.size(); ++i) cout << arr4[i] << " ";
	cout << endl;
	for (int i = 0; i < arr5.size(); ++i) cout << arr5[i] << " ";
	cout << endl;
	cout << "rand arr: " << endl;
	for (int i = 0; i < arrrand.size(); ++i) cout << arrrand[i] << " ";
	cout << endl;
	stat12 = bubble_sort(arrrand);
	cout << "comp count for bubble " << stat12.comp_count << " copy count " << stat12.copy_count << endl;
	for (int i = 0; i < arrrand.size(); ++i) cout << arrrand[i] << " ";
	cout << endl;

	//Сортировка пузырьком для 100 случайных, 1 отсортированного и 1 инвертированного векторов
	{
		cout << "Bubble sort tests" << endl << endl;
		size_t sum_comparison = 0, sum_copy = 0;
		for (int i = 0; i < 100; ++i) {
			vector<int> arr = generate_random(SIZE, SEED);
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
	//Сортировка расческой для 100 случайных, 1 отсортированного и 1 инвертированного
	{
		cout << "Comb sort tests" << endl << endl;
		size_t sum_comparison = 0, sum_copy = 0;
		for (int i = 0; i < 100; ++i) {
			vector<int> arr = generate_random(SIZE, SEED);
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
	// Шейкерная сортировка для 100 случайных, 1 отсортированного и 1 инвертированного
	{
		cout << "Shake sort tests" << endl << endl;
		size_t sum_comparison = 0, sum_copy = 0;
		for (int i = 0; i < 100; ++i) {
			vector<int> arr = generate_random(SIZE, SEED);
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