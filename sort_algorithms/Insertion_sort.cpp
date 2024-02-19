#include <bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int> &v){
    for(int pos=v.size()-2; pos>=0; pos--){
        int tmp = v[pos];
        size_t i = pos + 1;
        while (i < v.size() && v[i] < tmp)
        {
            v[i-1] = v[i]; //move to left
            i++;
        }
        v[i-1] = tmp;
    }
    /* EX.  <5,3,4,7,9> ...tmp = v[3] = 7
            <5,3,4,7,9> ...tmp = v[2] = 4
            <5,3,4,7,9> ...tmp = v[1] = 3
            <5,3,4,7,9> ...tmp = v[0] = 5
            <3,4,_,7,9> ... i = 2 then v[2] = 5
            <3,4,5,7,9>
    */
}

int main(){
    const int size = 5;

    // Create a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    vector<int> randomVector;
    randomVector.reserve(size);
    for (int i = 0; i < size; ++i) {
        randomVector.push_back(dis(gen));
    }
    cout << "INSERTION SORT\n";
    cout << "Before: ";
    for (int num : randomVector) {
        cout << num << " ";
    }
    cout << "\n";

    insertion_sort(randomVector);

    cout << "After: ";
    for(auto &i : randomVector){
        cout << i << " ";
    }

    cout << "\n";
}
