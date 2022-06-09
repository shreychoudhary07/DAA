#include <iostream>
#include <tuple>
#include <vector>

std::pair<std::string, int> binary_search(int arr[], int lower_bound, int upper_bound, int key) {
    int count = 0;
    while (lower_bound <= upper_bound) {
        int mid = (lower_bound + upper_bound) / 2;
        count++;
        if (arr[mid] == key) {
            return std::make_tuple("Present", count);
        } else if (arr[mid] < key)
            lower_bound = mid + 1;
        else if (arr[mid] > key)
            upper_bound = mid - 1;
    }
    return std::make_tuple("Not Present", count);
}

int main() {
    std::pair<std::string, int> pair;
    std::vector<std::pair<std::string, int> > vec;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int no_of_elements;
        std::cin >> no_of_elements;
        int arr[no_of_elements];
        for (int j = 0; j < no_of_elements; j++) {
            int element;
            std::cin >> element;
            arr[j] = element;
        }

        int key;
        std::cin >> key;

        pair = binary_search(arr, 0, no_of_elements - 1, key);
        vec.push_back(pair);
    }

    for (auto v : vec) {
        std::cout << v.first << " " << v.second << "\n";
    }

    return 0;
}