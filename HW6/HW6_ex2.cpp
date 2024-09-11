#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class NullException : public std::exception {
public:
    NullException() : std::exception("Ошибка: Деление на ноль") {}
};

class InvalidInput : public std::exception {
public:
    InvalidInput() : std::exception("Ошибка: Ввод должен быть целым числом") {}
};

class OutOfBounds : public std::exception {
public:
    OutOfBounds() : std::exception("Ошибка: Выход за границы массива") {}
};

class InvalidType : public std::exception {
public:
    InvalidType() : std::exception("Ошибка: Неверный тип входных параметров") {}
};

double division(int num, int den) {
    if (den == 0) {
        throw NullException();
    }
    return (double)num / den;
}

int getInput() {
    int number;
    cout << "Введите целое число: ";
    if (!(cin >> number)) {
        throw InvalidInput();
    }
    return number;
}

void matrixElement(const vector<vector<int>>& matrix, int row, int col) {
    if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size()) {
        throw OutOfBounds();
    }

    cout << "Элемент матрицы [" << row << "][" << col << "] = " << matrix[row][col] << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

   vector<vector<int>> matrix = {
        {1, 2},
        {3, 4}
    };

    try {
        cout << "ПРИМЕР ДЕЛЕНИЯ: " << endl;
        int numerator = getInput();
        int denominator = getInput();
        cout << "Результат деления: " << division(numerator, denominator) << endl;

        cout << endl << "---------------------------------------------" << endl << endl;

        cout << "ПРИМЕР ДОСТУПА К ЭЛЕМЕНТУ МАТРИЦЫ: " << endl;
        int row = getInput();
        int col = getInput();
        matrixElement(matrix, row, col);
    }
    catch (const NullException& e) {
        std::cerr << e.what() << endl;
    }
    catch (const InvalidInput& e) {
        std::cerr << e.what() << endl;
    }
    catch (const OutOfBounds& e) {
        std::cerr << e.what() << endl;
    }
    catch (const InvalidType& e) {
        std::cerr << e.what() << endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Произошла ошибка: " << e.what() << endl;
    }

    return 0;
}
