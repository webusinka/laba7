#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool findExpression(vector<int>& numbers, int target, int currentSum, string currentExpression) {
    // Базовый случай: если текущая сумма равна целевому значению, возвращаем true
    if (currentSum == target) {
        cout << currentExpression << " = " << target << endl;
        return true;
    }

    // Если текущая сумма больше целевого значения, возвращаем false
    if (currentSum > target) {
        return false;
    }

    // Рекурсивный случай: перебираем все оставшиеся числа
    for (int i = 0; i < numbers.size(); i++) {
        // Если текущий символ первый, используем его без операции
        if (currentExpression.empty()) {
            if (findExpression(numbers, target, currentSum + numbers[i], to_string(numbers[i]))) {
                return true;
            }
        }
        // Иначе используем операции сложения и умножения
        if (findExpression(numbers, target, currentSum + numbers[i], currentExpression + "+" + to_string(numbers[i]))) {
            return true;
        }
        if (findExpression(numbers, target, currentSum * numbers[i], currentExpression + "*" + to_string(numbers[i]))) {
            return true;
        }
    }

    // Если ни один вариант не подошел, возвращаем false
    return false;
}

int main() {
    system("chcp 65001");
    int n, s;
    cout << "Введите количество чисел: ";
    cin >> n;
    cout << "Введите целевое число: ";
    cin >> s;

    vector<int> numbers(n);
    cout << "Введите числа: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    if (!findExpression(numbers, s, 0, "")) {
        cout << "Не удалось найти подходящее выражение" << endl;
    }

    return 0;
}
