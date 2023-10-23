#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Function to perform Bubble Sort
void bubbleSort(vector<int> &arr) {
    int arraySize = arr.size();
    bool isSwapped;

    for (int i = 0; i < arraySize - 1; ++i) {
        isSwapped = false;

        for (int j = 0; j < arraySize - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }

        if (!isSwapped) {
            break;
        }
    }
}

int main(void) {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> numbers(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 1000);

    for (int i = 0; i < n; ++i) {
        numbers[i] = dist(gen);
    }

    cout << "Original numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    bubbleSort(numbers);

    cout << "\nSorted numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    return 0;
}
