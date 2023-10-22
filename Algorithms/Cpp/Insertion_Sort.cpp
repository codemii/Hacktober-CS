#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to perform Insertion Sort
void insertionSort(vector<int> &arr)
{
    int arraySize = arr.size();

    for (int i = 1; i < arraySize; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main(void)
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> numbers(n);

    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < n; ++i)
    {
        numbers[i] = rand() % 1000;
    }

    cout << "Original numbers: ";
    for (int num : numbers)
    {
        cout << num << " ";
    }

    insertionSort(numbers);

    cout << "\nSorted numbers: ";
    for (int num : numbers)
    {
        cout << num << " ";
    }

    return 0;
}
