#include <iostream>
#include <vector>

class NullException : public std::exception {
public:
    NullException() : std::exception("Ошибка: Деление на 0!") {}
};

class OutOfRange : public std::exception {
public:
    OutOfRange() : std::exception("Ошибка: Выход за пределы диапазона!") {}
};

double calculate_f(double x, double N, int k) {
    if (x < 0 || x > k) {
        throw OutOfRange();
    }
    if (x == N) {
        throw NullException();
    }
    return 1 / (x - N);
}

int main() {
    setlocale(LC_ALL, "ru");

    double N = 10;
    int k;

    std::cout << "Введите k (до 20): ";
    std::cin >> k;

    if (k < 0 || k > 20) {
        std::cerr << "Ошибка: значение k должно быть в диапазоне от 0 до 20." << std::endl;
        return 1;
    }

    std::vector<double> f(k + 1);

    for (int x = 0; x <= k; ++x) {
        try {
            f[x] = calculate_f(x, N, k);
            std::cout << "f[" << x << "] = " << f[x] << std::endl;
        }
        catch (const  NullException& e) {
            std::cerr << "При x = " << x << ": " << e.what() << std::endl;
        }
        catch (const OutOfRange& e) {
            std::cerr << "При x = " << x << ": " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Произошла непредвиденная ошибка: " << e.what() << std::endl;
        }
    }

    return 0;
}
