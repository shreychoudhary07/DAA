#include <iostream>
#include <tuple>

std::tuple<int, int> insertion_sort(int array[], int size) {
    int shifts = 0, comparisons = 0, temp = 0;
    for (int i = 1; i < size; i++) {
        temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
            shifts++;
            comparisons++;
        }
        comparisons++;
        array[j + 1] = temp;
    }
    return std::make_tuple(comparisons, shifts);
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

        tuple = insertion_sort(array, no_of_elements);

        for (int z = 0; z < no_of_elements; z++)
            std::cout << array[z] << " ";
        std::cout << "\ncomparisons = " << std::get<0>(tuple) << "\n";
        std::cout << "shifts = " << std::get<1>(tuple) << "\n";
    }
    return 0;
}