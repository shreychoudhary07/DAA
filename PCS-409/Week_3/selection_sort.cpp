#include <iostream>

std::tuple<int, int> selection_sort(int array[], int size) {
    int min = 0, min_element_position = 0;
    int swaps = 0, comparisons = 0;
    for (int i = 0; i < size - 1; i++) {
        min = array[i];
        min_element_position = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < min) {
                min = array[j];
                min_element_position = j;
            }
            comparisons++;  // comparisons = n * (n - 1) / 2
        }
        array[min_element_position] = array[i];
        array[i] = min;
        swaps++;  // swaps = n - 1
    }
    return std::make_tuple(comparisons, swaps);
}

int main() {
    std::tuple<int, int> tuple;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int no_of_elements;
        std::cin >> no_of_elements;
        int array[no_of_elements];

        for (int j = 0; j < no_of_elements; j++) {
            int element;
            std::cin >> element;
            array[j] = element;
        }

        tuple = selection_sort(array, no_of_elements);

        for (int k = 0; k < no_of_elements; k++) {
            std::cout << array[k] << " ";
        }
        std::cout << "\ncomparisons = " << std::get<0>(tuple) << "\nswaps = " << std::get<1>(tuple) << "\n";
    }
    return 0;
}