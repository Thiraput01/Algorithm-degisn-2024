#include <iostream>
#include <string>

using namespace std;

string generateG(int k) {
    if (k == 0) {
        return "g a a";
    } else {
        string prev = generateG(k - 1);
        string result = prev + " g a";
        for (int i = 0; i < k + 2; ++i) {
            result += " a";
        }
        return result;
    }
}

int findSmallestK(int n) {
    int k = 0;
    while (true) {
        string sequence = generateG(k);
        if (sequence.length() >= n) {
            return k;
        }
        k++;
    }
}

char getCharAtIndex(int n, int index) {
    int k = findSmallestK(n);
    string sequence = generateG(k);
    if (index >= 1 && index <= sequence.length()) {
        return sequence[index - 1]; // Adjust index to zero-based
    } else {
        return '\0'; // Return null character if index is out of bounds
    }
}

int main() {
    int n, index;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the index to find character: ";
    cin >> index;

    char character = getCharAtIndex(n, index);
    if (character != '\0') {
        cout << "Character at index " << index << " in G(n) is: " << character << endl;
    } else {
        cout << "Index out of bounds!" << endl;
    }

    return 0;
}
