#include <iostream>
#include <vector>

int difference(int arr[], int size, int key) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i] - arr[j] == key)
                count++;
        }
    }
    return count;
}

int main() {
    std::vector<int> vec;

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

        int key;
        std::cin >> key;

        int count = difference(array, no_of_elements, key);
        vec.push_back(count);
    }

    for (auto v : vec) {
        if (v == 0) {
            std::cout << "No pair found."
                      << "\n";
        } else
            std::cout << v << "\n";
    }
    return 0;
}