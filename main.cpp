// Counting-Inversions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
struct vector_and_value {
	vector<int> vect;
	int val;
};
vector<int> first_half_vector(vector<int> v) {
	vector<int> first_half = {};
	int n = v.size();
	int middle = n / 2;
	for (int i = 0; i<middle; i++) {
		first_half.push_back(v[i]);
	}
	return first_half;
}
vector<int> second_half_vector(vector<int> v) {
	vector<int> second_half = {};
	int n = v.size();
	int middle = n / 2;
	for (int i = middle; i<v.size(); i++) {
		second_half.push_back(v[i]);
	}
	return second_half;
}
void print_vector(vector<int> v) {
	cout << "printing started\n";
	for (int i = 0; i<v.size(); i++) {
		cout << v[i] << "\n";
	}
	cout << "printing finished\n";
}
vector_and_value merge_and_count(vector<int> v1, vector<int> v2) {
	int i = 0, j = 0;
	vector_and_value result;
	result.val = 0;
	result.vect = {};
	while (i<v1.size() && j<v2.size()) {
		if (v1[i] <= v2[j]) {
			result.vect.push_back(v1[i]);
			i++;
		}
		else {
			result.vect.push_back(v2[j]);
			(result.val) = result.val+(v1.size()-i);
			j++;
		}
	}
	if (!(i < v1.size())) {
		while (j < v2.size()) {
			result.vect.push_back(v2[j]);
			j++;
		}
	}
	else if(!(j<v2.size())){
		while (i < v1.size()) {
			result.vect.push_back(v1[i]);
			i++;
		}
	}
	return result;
}
vector_and_value sort_and_count(vector<int> v) {
	vector_and_value result;
	result.vect = {};
	result.val = 0;
	if (v.size() == 1) {
		result.vect = v;
		return result;
	}
	else {
		vector<int> first_half = first_half_vector(v);
		vector<int> second_half = second_half_vector(v);
		vector_and_value result_of_first_half = sort_and_count(first_half);
		vector_and_value result_of_second_half = sort_and_count(second_half);
		vector_and_value result_of_combine = merge_and_count(result_of_first_half.vect,result_of_second_half.vect);
		result.val = result_of_first_half.val+result_of_second_half.val+result_of_combine.val;
		result.vect = result_of_combine.vect;
	}
	return result;
}
int main()
{
	vector<int> input = { 1,5,4,8,10,2,6,9,12,11,3,7 };;
	vector_and_value count_inversions = sort_and_count(input);
	cout << count_inversions.val;
	system("PAUSE");
    return 0;
}

