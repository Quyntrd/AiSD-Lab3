#include <vector>


using namespace std;


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