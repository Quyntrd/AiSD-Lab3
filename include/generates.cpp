#include <iostream>
#include <vector>
#include <random>


using namespace std;


struct stats {
	size_t comp_count = 0;
	size_t copy_count = 0;

	friend stats operator+(const stats& left, const stats& right)
	{
		stats stats;
		stats.comp_count = left.comp_count + right.comp_count;
		stats.copy_count = left.copy_count + right.copy_count;
		return stats;
	}
};


vector<int> generate_sorted(const int size) {
	vector<int> result;
	for (int i = 0; i < size; ++i) result.push_back(i);
	return result;
}
vector<int> generate_inverted(const int size) {
	vector<int> result;
	for (int i = size - 1; i >= 0; --i) result.push_back(i);
	return result;
}
vector<int> generate_random(const int size) {
	vector<int> result;
	for (int i = 0; i < size; ++i) result.push_back(rand() % size);
	return result;
}