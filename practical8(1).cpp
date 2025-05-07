#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void reverseUsingSTL(vector<int>& seq) {
    reverse(seq.begin(), seq.end());
    cout << "Reversed using std::reverse(): ";
    for (int num : seq)
        cout << num << " ";
    cout << endl;
}

void reverseUsingIterators(vector<int>& seq) {
    auto front = seq.begin();
    auto back = seq.end() - 1;
    while (front < back) {
        int temp = *front;
        *front = *back;
        *back = temp;
        ++front;
        --back;
    }

    cout << "Reversed using manual iterators: ";
    for (auto it = seq.begin(); it != seq.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main() {
    vector<int> sequence;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the sequence: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        sequence.push_back(value);
    }

    vector<int> seq1 = sequence;
    vector<int> seq2 = sequence;

    cout << "\n== Using std::reverse ==" << endl;
    reverseUsingSTL(seq1);

    cout << "\n== Using manual iterator reversal ==" << endl;
    reverseUsingIterators(seq2);

    return 0;
}

