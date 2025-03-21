#include <vector>
#include <cassert>
#include <iostream>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

// I learnt merge from https://www.w3schools.com/cpp/ref_algorithm_merge.asp

string vec_to_string(const vector<int>& vec){
    string s="{";
    for (int i=0;i<vec.size();i++){
        s+=to_string(vec[i]); //concatenate the next element as string
        if (i!=vec.size()-1){ //as long as we aren't on the last element, keep using commas
            s+=",";
        }
    }
    s+="}";
    return s;
}

int find_next_dividend_position(const vector<int>& inputVector,int dividend,int pos){
    int next_dividend_position=-1;   //declare index
    for (int j=pos;j<inputVector.size();j++){   
        if (min(abs(inputVector[j]),abs(dividend))!=0){   // prevent division by 0
            if (max(abs(inputVector[j]),abs(dividend))%min(abs(inputVector[j]),abs(dividend))==0){
                // this divides the larger of the two numbers by the smaller automatically
                // also, using absolute value allows division with negative integers (via their magnitude) as well
                next_dividend_position=j; // update our index for the next dividend position
                break;
            }
        }
    }
    return next_dividend_position; 
    //returning -1 means that there's no next dividend, but returning anything else mean that there is
}

vector<int> longest_vector(const vector<vector<int>>& candidates){
    int index=0; //default index
    int max_size=candidates[0].size(); // default vector size (see next line's comment)
    vector<int> longest_vec=candidates[0]; // basically, candidates[0] is default vector
    for (int i=1;i<candidates.size();i++){
        if (max_size<candidates[i].size()){ // for updating everything if a new maximum vector size is found
            index=i;
            longest_vec=candidates[i];
            max_size=candidates[i].size();
        }
    }
    return longest_vec;
}

vector<int> bdc_helper(const vector<int>& inputVector){
    if (inputVector.size()==0||inputVector.size()==1){ // Basecase: when there's nothing else for subsetting
        return inputVector;
    }
    vector<vector<int>> candidates;
    for (int i=0;i<inputVector.size()-1;i++){
        vector<int> L={inputVector[i]}; //  a small vector with input[i] as the only item
        int j=find_next_dividend_position(inputVector,inputVector[i],i + 1); 
        // from the position i+1
        // find the position of next number in the input vector which is divisible by input[i]
        if (j==-1){  // if there is no next dividend
            if (!candidates.empty()) // if there are possibly longer vectors other than L
                return longest_vector(candidates); 
            else
                return L;  // L is the longest vector otherwise
        }
        vector<int> Rin(inputVector.begin()+j,inputVector.end()); //extract the sub vector from position j to the rest
        vector<int> R=bdc_helper(Rin); // call the recursive function with a subproblem (a smaller input vector)
        vector<int> cand_v(L.size()+R.size());  // combine input[i] with all the numbers which are divisible by input[i] and
        merge(L.begin(),L.end(),R.begin(),R.end(),cand_v.begin());  // form a conglomerate
        candidates.push_back(cand_v); // append the conglomerate to the list/vector
    }
    return longest_vector(candidates); // returns the longest conglomerate inside the candidates
}




vector<int> biggest_divisible_conglomerate(vector<int> inputVector){
    sort(inputVector.begin(),inputVector.end());  //sort vector before starting
    return bdc_helper(inputVector);
}




