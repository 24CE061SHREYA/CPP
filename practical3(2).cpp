#include <iostream>
#include <vector>
using namespace std;

int recursiveSum(const vector<int>& arr, int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

int iterativeSum(const vector<int>& arr) {
    int sum = 0;
    for (int val : arr) {
        sum += val;
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int sumRec = recursiveSum(arr, size);
    int sumItr = iterativeSum(arr);

    cout << "\nSum using Recursion: " << sumRec;
    cout << "\nSum using Iteration: " << sumItr;

    cout << "\n\n24ce061_Shreya_Loriya";
    return 0;
}
