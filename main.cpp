#include <vector>
#include <cassert>
#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
#include "bdc.h"

using namespace std;

int main() {

	// Test 1 (example from assignment description)
	vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
	vector<int> ans = biggest_divisible_conglomerate(values);
	// cout << "input: " << vec_to_string(values) << endl;
	// cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet(ans.begin(), ans.end());
	set<int> soln = {56, 14, 7, 28};
	bool first = (answerSet == soln);
	soln = {56, 28, 14, 2};
	bool second = (answerSet == soln);
	assert(first || second);


	// Test 2
	values = {10, 5, 3, 15, 20};
	ans = biggest_divisible_conglomerate(values);
	// cout << "input: " << vec_to_string(values) << endl;
	// cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {20, 5, 10};
	set<int> answerSet2(ans.begin(), ans.end());
	assert(answerSet2 == soln);

	// write your own tests here!

    values = {3, 3, 6, 9};
	ans = biggest_divisible_conglomerate(values);
	// cout << "input: " << vec_to_string(values) << endl;
	// cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {3, 3, 6};
	set<int> answerSet3(ans.begin(), ans.end());
	assert(answerSet3 == soln);

    values = {};
    ans = biggest_divisible_conglomerate(values);
    // cout << "input: " << vec_to_string(values) << endl;
    // cout << "output: " << vec_to_string(ans) << endl << endl;
    soln = {};
	set<int> answerSet4(ans.begin(), ans.end());
	assert(answerSet4 == soln);

    values = {0};
    ans = biggest_divisible_conglomerate(values);
    // cout << "input: " << vec_to_string(values) << endl;
    // cout << "output: " << vec_to_string(ans) << endl << endl;
    soln = {0};
	set<int> answerSet5(ans.begin(), ans.end());
	assert(answerSet5 == soln);
    
    values = {69};
    ans = biggest_divisible_conglomerate(values);
    // cout << "input: " << vec_to_string(values) << endl;
    // cout << "output: " << vec_to_string(ans) << endl << endl;
    soln = {69};
	set<int> answerSet6(ans.begin(), ans.end());
	assert(answerSet6 == soln);

    values = {1,INT_MAX};
    ans = biggest_divisible_conglomerate(values);
    // cout << "input: " << vec_to_string(values) << endl;
    // cout << "output: " << vec_to_string(ans) << endl << endl;
    soln = {1,INT_MAX};
	set<int> answerSet7(ans.begin(), ans.end());
	assert(answerSet7 == soln);

	values = {-7,7,-14,14};
    ans = biggest_divisible_conglomerate(values);
    // cout << "input: " << vec_to_string(values) << endl;
    // cout << "output: " << vec_to_string(ans) << endl << endl;
    soln = {-14,-7,7,14};
    set<int> answerSet8(ans.begin(), ans.end());
	assert(answerSet8 == soln);
    
    values = {-1,0,1};
    ans = biggest_divisible_conglomerate(values);
    // cout << "input: " << vec_to_string(values) << endl;
    // cout << "output: " << vec_to_string(ans) << endl << endl;
    soln = {-1,1};
    set<int> answerSet9(ans.begin(), ans.end());
	assert(answerSet9 == soln);
    
    values = {7,11,17,3};
    ans = biggest_divisible_conglomerate(values);
    // cout << "input: " << vec_to_string(values) << endl;
    // cout << "output: " << vec_to_string(ans) << endl << endl;
    soln = {3};
    set<int> answerSet10(ans.begin(), ans.end());
	assert(answerSet10 == soln);
    
    cout<<"ALL TESTS PASSED!"<<endl;
	return 0;
}
