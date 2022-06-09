#include <iostream>

int main() {
    int m, n, i, j, total, k = 0, x;
    std::cin >> m;
    int a[m];
    for (i = 0; i < m; i++) std::cin >> a[i];
    std::cin >> n;
    int b[n], c[n];
    for (i = 0; i < n; i++) std::cin >> b[i];
    std::sort(a, a + m);
    std::sort(b, b + n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                total = 0;
                for (x = 0; x < k; x++)
                    if (a[i] == c[x]) total++;
                if (total == 0) {
                    c[k] = a[i];
                    k++;
                }
            }
        }
    }
    for (i = 0; i < k; i++) std::cout << c[i] << " ";
    return 0;
}