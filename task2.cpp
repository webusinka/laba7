#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void generatePermutations(vector<int>& numbers, vector<int>& permutation, vector<bool>& used, int depth, int k, int& count) {
    if (depth == numbers.size()) { //достигнут конец вектора
        count++;                   //счетчик перестановок
        if (count == k) {          //если нужная перестановка
            for (int num : permutation) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = 0; i < numbers.size(); ++i) {  //проходимся по количеству n
        if (!used[i]) {                         //если ложь
            used[i] = true;                     //присвой правду
            permutation[depth] = numbers[i];    //текущий шаг рекурсии - значение числа, которое будем переставлять
            generatePermutations(numbers, permutation, used, depth + 1, k, count); //зайди с глубиной +1
            used[i] = false;                   //верни ложь
        }
    }
}

int recyrctionRermutations(int n, int k) {
    vector<int> numbers(n);
    vector<int> permutation(n);
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }

    int count = 0;
    int depth = 0;
    generatePermutations(numbers, permutation, used, depth, k, count);
    
    return 0;
}

int main() {
    int n, k;
    do {
        cout << "Input n and k: ";
        cin >> n >> k;
        if (n < 1 || n > 9 || k < 1 || k > factorial(n)) {
            cout << "Wrong input!" << endl;
        }
    } while (n < 1 || n > 9 || k < 1 || k > factorial(n));
    
    recyrctionRermutations(n, k);

    return 0;
}