#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int z = 0; z < n; z++) {
        int no_of_elements;
        std::cin >> no_of_elements;
        int array[no_of_elements];
        for (int j = 0; j < no_of_elements; j++) std::cin >> array[j];

        int k;
        std::cin >> k;
        std::sort(array, array + no_of_elements);
        int i = 0, count = 0;
        while (count != k - 1) {
            if (array[i] != array[i + 1]) count++;
            i++;
        }
        std::cout << array[i] << "\n\n";
    }
    return 0;
}