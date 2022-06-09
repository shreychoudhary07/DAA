// #include <time.h>

#include <iostream>

int total_swaps = 0;
int comparisons = 0;

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int partition(int array[], const int startIndex, const int endIndex) {
    // srand(time(NULL));
    // int random_index = rand() % 15;
    // array[endIndex] = array[random_index];
    int pivot = array[endIndex];
    int i = startIndex - 1;
    for (int j = startIndex; j < endIndex; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
            total_swaps++;
        }
        comparisons++;
    }
    swap(array[i + 1], array[endIndex]);
    total_swaps++;
    return i + 1;
}

void quick_sort(int array[], const int startIndex, const int endIndex) {
    if (startIndex >= endIndex) return;
    int pi = partition(array, startIndex, endIndex);
    quick_sort(array, startIndex, pi - 1);
    quick_sort(array, pi + 1, endIndex);
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int no_of_elements;
        std::cin >> no_of_elements;
        int array[no_of_elements];
        for (int j = 0; j < no_of_elements; j++) std::cin >> array[j];
        quick_sort(array, 0, no_of_elements - 1);
        std::cout << "Comparisons = " << comparisons << "\nSwaps = " << total_swaps;
        std::cout << "\n";
        comparisons = 0;
        total_swaps = 0;
    }
    return 0;
}