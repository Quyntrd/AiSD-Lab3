#include <generates.cpp>
#include <vector>


using namespace std;


stats shake_sort(vector<int>& vec) {
	stats stats;
	int left = 0, right = vec.size() - 1;
	int flag = 1;
	while (left < right && flag > 0) {
		flag = 0;
		for (int i = left; i < right; ++i) {
			stats.comp_count += 1;
			if (vec[i] > vec[i + 1]) {
				swap(vec[i], vec[i + 1]);
				flag = 1;
				stats.copy_count += 1;
			}
		}
		--right;
		for (int i = right; i > left; --i) {
			stats.comp_count += 1;
			if (vec[i - 1] > vec[i]) {
				swap(vec[i - 1], vec[i]);
				flag = 1;
				stats.copy_count+=1;
			}
		}
		++left;
	}
	return stats;
}

template<typename Iterator>
stats shake_sort(Iterator begin, Iterator end) {
	stats stats;
	auto left = begin, right = end - 1;
	int flag = 1;
	while (left < right && flag > 0) {
		flag = 0;
		for (auto i = left; i != right; ++i) {
			stats.comp_count += 1;
			if (*i > *(i+1)) {
				iter_swap(i, i + 1);
				flag = 1;
				stats.copy_count += 1;
			}
		}
		--right;
		for (auto i = right; i > left; --i) {
			stats.comp_count += 1;
			if (*(i-1) > i) {
				iter_swap(i - 1, i);
				flag = 1;
				stats.copy_count += 1;
			}
		}
		++left;
	}
	return stats;
}