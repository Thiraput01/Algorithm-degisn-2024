#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<int> &v){
    size_t pos = v.size()-1;
    for(;pos>0;pos--){
        //finding index of the max value
        int max_idx = 0;
        for(size_t i=0; i<=pos; i++){
            if(v[i] > v[max_idx]) max_idx = i;
        }
        //swap current pos with max idx
        swap(v[max_idx], v[pos]);
    }
}

int main(){
    const int size = 10;

    // Create a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    vector<int> randomVector;
    randomVector.reserve(size);
    for (int i = 0; i < size; ++i) {
        randomVector.push_back(dis(gen));
    }
    cout << "SELECTION SORT\n";
    cout << "Before: ";
    for (int num : randomVector) {
        cout << num << " ";
    }
    cout << "\n";

    selection_sort(randomVector);

    cout << "After: ";
    for(auto &i:randomVector){
        cout << i << " ";
    }
}