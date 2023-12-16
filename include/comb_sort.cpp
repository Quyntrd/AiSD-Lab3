#include <stats.cpp>
#include <vector>


using namespace std;


stats comb_sort(vector<int>& vec){
	stats stat;
	auto n = vec.size() - 1;
	auto gap = n;
	bool flag = true;
	while (gap != 1 || flag) {
		gap = (gap * 10) / 13;
		if (gap < 1) gap = 1;
		flag = false;
		for (int i = 0; i < n - gap; ++i) {
			stat.comp_count += 1;
			if (vec[i] > vec[i + gap]) {
				swap(vec[i], vec[i + gap]);
				stat.copy_count += 1;
				flag = true;
			}
		}
	}
	return stat;
}

template <typename Iterator>
stats comb_sort(Iterator begin, Iterator end) {
	stats stat;
	auto n = distance(begin, end);
	auto gap = n;
	bool flag = true;
	while (gap > 1 || flag) {
		gap = (gap * 10) / 13;
		if (gap < 1)
			gap = 1;
		flag = false;
		for (auto i = begin; i != end - gap; ++i) {
			stat.comp_count += 1;
			if (*i > *(i + gap)) {
				iter_swap(i, i + gap);
				stat.copy_count += 1;
				flag = true;
			}
		}
	}
	return stat;
}