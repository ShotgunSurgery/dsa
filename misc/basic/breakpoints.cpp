#include <iostream>
using namespace std;

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int x = 5;
    int y = 4;
    int result = multiply(x, y);
    cout << "Result: " << result << endl;
    return 0;
}
