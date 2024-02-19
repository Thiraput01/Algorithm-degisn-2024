#include <bits/stdc++.h>

using namespace std;

void bogo_sort(vector<int> &v){
    bool is_sort = true;
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] > v[i + 1]){
            is_sort = false;
            break;
        }
    }
    if(is_sort){
        return;
    } else {
        random_device rd;
        default_random_engine rng(rd());
        shuffle(v.begin(), v.end(), rng);
        bogo_sort(v);
    }
}

int main(){
    const int size = 4;

    // Create a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    vector<int> randomVector;
    randomVector.reserve(size);
    for (int i = 0; i < size; ++i) {
        randomVector.push_back(dis(gen));
    }
    cout << "BOGO SORT\n";
    cout << "Before: ";
    for (int num : randomVector) {
        cout << num << " ";
    }
    cout << "\n";

    bogo_sort(randomVector);

    cout << "After: ";
    for(auto &i : randomVector){
        cout << i << " ";
    }

    cout << "\n";  // Add a newline for better formatting
}
