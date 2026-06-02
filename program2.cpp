#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

using namespace std;

class Equation {
public:
    double k2, k1, k0;
    Equation(double a, double b, double c) : k2(a), k1(b), k0(c) {}
};

struct Roots {
    double t1, t2;
};

Roots solve(Equation eq) {
    if (eq.k2 == 0) {
        throw runtime_error("Ошибка: Коэффициент при старшей степени равен нулю (уравнение не квадратное).");
    }

    double D = eq.k1 * eq.k1 - 4 * eq.k2 * eq.k0;

    if (D < 0) {
        throw runtime_error("Ошибка: Дискриминант меньше нуля. Действительных корней нет.");
    }

    Roots r;
    r.t1 = (-eq.k1 + sqrt(D)) / (2 * eq.k2);
    r.t2 = (-eq.k1 - sqrt(D)) / (2 * eq.k2);
    return r;
}

int main() {
    try {
        double a, b;
        cout << "Введите числа a и b: ";
        if (!(cin >> a >> b)) {
            throw invalid_argument("Ошибка: Некорректный ввод данных. Ожидались числовые значения.");
        }

        Equation eq1(1, -1, a);
        Roots rx = solve(eq1);

        Equation eq2(2, 1, -b);
        Roots ry = solve(eq2);

        double denominator = (b - ry.t1) * (b - ry.t2);

        if (abs(denominator) < 1e-9) {
            throw runtime_error("Ошибка: Знаменатель равен нулю. Деление на ноль невозможно.");
        }

        double z = ((a - rx.t1) * (a - rx.t2)) / denominator;
        cout << "Результат z = " << z << endl;

    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}