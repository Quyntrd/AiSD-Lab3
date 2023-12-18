#include <vector>


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
	stats& operator=(const stats& right) {
		comp_count = right.comp_count;
		copy_count = right.copy_count;
		return *this;
	}
};


stats bubble_sort(vector<int>& vec) {
	stats stat;

	size_t length = vec.size();
	for (size_t i = 0; i < length; ++i) {
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
stats bubble_sort_it(Iterator begin, Iterator end) {
	stats stat;
	int i1 = 0;
	for (auto i = begin; i != end; ++i) {
		for (auto j = begin; j != end - i1 - 1; ++j) {
			if (*j > *(j+1)) {
				iter_swap(j+1, j);
				stat.copy_count += 1;
			}
			stat.comp_count += 1;
		}
		++i1;
	}
	return stat;
}

stats shake_sort(vector<int>& vec) {
	stats stat;
	int left = 0, right = vec.size() - 1;
	int flag = 1;
	while (left < right && flag > 0) {
		flag = 0;
		for (int i = left; i < right; ++i) {
			stat.comp_count += 1;
			if (vec[i] > vec[i + 1]) {
				swap(vec[i], vec[i + 1]);
				flag = 1;
				stat.copy_count += 1;
			}
		}
		--right;
		for (int i = right; i > left; --i) {
			stat.comp_count += 1;
			if (vec[i - 1] > vec[i]) {
				swap(vec[i - 1], vec[i]);
				flag = 1;
				stat.copy_count += 1;
			}
		}
		++left;
	}
	return stat;
}

template<typename Iterator>
stats shake_sort_it(Iterator begin, Iterator end) {
	stats stat;
	auto left = begin, right = end - 1;
	while (left <= right) {
		for (auto i = left; i != right; ++i) {
			stat.comp_count += 1;
			if (*i > *(i + 1)) {
				iter_swap(i, i + 1);
				stat.copy_count += 1;
			}
		}
		--right;
		for (auto i = right; i > left; --i) {
			stat.comp_count += 1;
			if (*(i - 1) > *i) {
				iter_swap(i - 1, i);
				stat.copy_count += 1;
			}
		}
		++left;
	}
	return stat;
}

stats comb_sort(vector<int>& vec) {
	stats stat;
	auto n = vec.size();
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
stats comb_sort_it(Iterator begin, Iterator end) {
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