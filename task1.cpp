#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool findExpression(vector<int> numbers, int target, int currentSum, string currentExpression, vector<bool>& used) {
    // Базовый случай: если текущая сумма равна целевому значению, значит решение найдено
    if (currentSum == target) {
        cout << currentExpression << " = " << target << endl;
        return true;
    }

    //перебираем все возможные действия
    for (int i = 0; i < numbers.size(); i++) {
        //число уже использовано, пропускаем его
        if (used[i]) continue;

        //cложение
        used[i] = true;
        if (findExpression(numbers, target, currentSum + numbers[i], currentExpression + "+" + to_string(numbers[i]), used))
            return true;
        used[i] = false;

        //умножение
        used[i] = true;
        if (findExpression(numbers, target, currentSum * numbers[i], currentExpression + "*" + to_string(numbers[i]), used))
            return true;
        used[i] = false;
    }

    return false;
}

int main() {
    int count, target;
    cout << "Input count two-digit numbers: ";
    cin >> count;
    cout << "Input total score of sum of prod: ";
    cin >> target;

    vector<int> numbers(count);
    vector<bool> used(count, false);
    cout << "Input " << count << " two-digit numbers: ";
    
    for (auto& number : numbers) {
        cin >> number;
        while (number < 10 || number > 99) {
            cout << "Number is not a two-digit number. Please input again: ";
            cin >> number;
        }
    }

    // Пробуем каждое число в качестве начального числа в выражении
    for (int i = 0; i < numbers.size(); i++) {
        used[i] = true;
        if (findExpression(numbers, target, numbers[i], to_string(numbers[i]), used))
            return 0;
        used[i] = false;
    }

    cout << "It is impossible to get a score through add or multiplication." << endl;

    return 0;
}