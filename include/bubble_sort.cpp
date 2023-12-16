#include <vector>
#include <generates.cpp>


using namespace std;


stats bubble_sort(std::vector<int>& vec) {
	stats stats;

	size_t length = vec.size();
	for (size_t i = 0; i < length - i - 1; ++i) {
		for (size_t j = 0; j < length - i - 1; ++j) {
			if (vec[j] > vec[j + 1]) {
				swap(vec[j + 1], vec[j]);
				stats.copy_count += 1;
			}
			stats.comp_count+=1;
		}
	}
	return stats;
}



template<class Iterator>
stats bubble_sort(Iterator begin, Iterator end) {
	stats stats;
	for (Iterator i = begin; i != end; ++i) {
		for (Iterator j = begin; j < i; ++j) {
			if (*i < *j) {
				iter_swap(i, j);
				stats.copy_count += 1;
			}
			stats.copy_count += 1;
		}
	}
	return stats;
}