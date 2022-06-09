#include <iostream>

void merge(int array[], const int low, const int mid, const int high) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int leftArray[n1];
    int rightArray[n2];

    for (i = 0; i < n1; i++)
        leftArray[i] = array[low + i];

    for (j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++];
        } else
            array[k++] = rightArray[j++];
    }

    while (i < n1) {
        array[k++] = leftArray[i++];
    }

    while (j < n2) {
        array[k++] = rightArray[j++];
    }
}

void merge_sort(int array[], const int low, const int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    merge_sort(array, low, mid);
    merge_sort(array, mid + 1, high);
    merge(array, low, mid, high);
}

bool has_duplicate(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] == array[i + 1]) return true;
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int no_of_elements, element;
        std::cin >> no_of_elements;
        int array[no_of_elements];

        for (int j = 0; j < no_of_elements; j++) {
            std::cin >> element;
            array[j] = element;
        }

        merge_sort(array, 0, no_of_elements - 1);
        has_duplicate(array, no_of_elements) ? std::cout << "YES\n" : std::cout << "NO\n";
    }
    return 0;
}