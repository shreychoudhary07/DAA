#include <iostream>
#include <vector>

std::tuple<int, int, int> sum(int arr[], int size) {
    for (int i = 0; i < size - 2; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            for (int k = i + 2; k < size; k++) {
                if (arr[i] + arr[j] == arr[k])
                    return std::make_tuple(i + 1, j + 1, k + 1);
            }
        }
    }
    return std::make_tuple(-1, -1, -1);
}
int main() {
    std::tuple<int, int, int> tuple;
    std::vector<std::tuple<int, int, int> > vec;

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

        tuple = sum(array, no_of_elements);
        vec.push_back(tuple);
    }

    for (auto v : vec) {
        if (std::get<0>(v) == -1) {
            std::cout << "No sequence found."
                      << "\n";
        } else
            std::cout << std::get<0>(v) << ", " << std::get<1>(v) << ", " << std::get<2>(v) << "\n";
    }
    return 0;
}