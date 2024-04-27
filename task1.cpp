//Имеются N двузначных чисел. Можно ли их соединить знаками сложения и умножения, чтобы получить заданное число S?

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool checkExpression(vector<int>& numbers, vector<char>& operations, int targetResult, int currentIndex, int currentResult) {
    if (currentIndex == numbers.size() - 1) {
        return currentResult == targetResult;
    }

    for (int i = currentIndex + 1; i < numbers.size(); i++) {
        operations.emplace_back('+');
        if (checkExpression(numbers, operations, targetResult, i, currentResult + numbers[i])) {
            return true;
        }
        operations.pop_back();

        operations.emplace_back('*');
        if (checkExpression(numbers, operations, targetResult, i, currentResult * numbers[i])) {
            return true;
        }
        operations.pop_back();
    }

    return false;
}

int main() {

    int N;
    cout << "Input count of number (N): ";
    cin >> N;

    vector<int> numbers(N);
    cout << "Input " << N << " numbers: ";
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    int targetResult;
    cout << "Input total number (S): ";
    cin >> targetResult;
    vector<char> operations;

    if (checkExpression(numbers, operations, targetResult, 0, numbers[0])) {
        cout << "Expression: ";
        for (int i = 0; i < numbers.size() - 1; i++) {
            cout << numbers[i] << " " << operations[i] << " ";
        }
        cout << numbers.back() << " = " << targetResult << endl;
    } else {
        cout << "An expression that is equal to was not found " << targetResult << endl;
    }

    return 0;
}