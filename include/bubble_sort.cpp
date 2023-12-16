#include <stats.cpp>
#include <vector>


using namespace std;


stats bubble_sort(vector<int>& vec) {
	stats stat;

	size_t length = vec.size();
	for (size_t i = 0; i < length - i - 1; ++i) {
		for (size_t j = 0; j < length - i - 1; ++j) {
			if (vec[j] > vec[j + 1]) {
				swap(vec[j + 1], vec[j]);
				stat.copy_count += 1;
			}
			stat.comp_count += 1;
		}
	}
	return stat;
}


template<class Iterator>
stats bubble_sort(Iterator begin, Iterator end) {
	stats stat;
	for (Iterator i = begin; i != end; ++i) {
		for (Iterator j = begin; j < i; ++j) {
			if (*i < *j) {
				iter_swap(i, j);
				stat.copy_count += 1;
			}
			stat.copy_count += 1;
		}
	}
	return stat;
}