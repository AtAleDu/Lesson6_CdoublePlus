#include <iostream>
#include <cmath>

using namespace std;

class Polynomial {
private:
    int stepen; // Степень полинома
    double* coefficients; // Массив для хранения коэффициентов
public:
    // Конструктор для инициализации степени полинома
    Polynomial(int stepen) : stepen(stepen) { // Конструктор класса Polynomial
        coefficients = new double[stepen + 1]; // Выделение памяти для массива коэффициентов
        for (int i = 0; i <= stepen; i++) { // Заполнение массива нулями
            coefficients[i] = 0.0;
        }
    }


    // Деструктор для освобождения памяти
    ~Polynomial() {
        delete[] coefficients;
    }

    // Метод для установки коэффициентов для каждого члена полинома
    void setCoefficients(double* coeff) {
        for (int i = 0; i <= stepen; i++) {
            coefficients[i] = coeff[i];
        }
    }

    // Перегрузка оператора + для выполнения сложения двух полиномов
    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = max(stepen, other.stepen);
        Polynomial result(maxDegree);

        for (int i = 0; i <= maxDegree; i++) {
            if (i <= stepen && i <= other.stepen) {
                result.coefficients[i] = coefficients[i] + other.coefficients[i];
            }
            else if (i <= stepen) {
                result.coefficients[i] = coefficients[i];
            }
            else if (i <= other.stepen) {
                result.coefficients[i] = other.coefficients[i];
            }
            else {
                result.coefficients[i] = 0;
            }
        }
        return result;
    }

    // Метод для вычисления значения полинома для заданного значения x
    double evaluate(double x) const {
        double result = 0;
        for (int i = 0; i <= stepen; i++) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    // Метод для вывода полинома в удобочитаемом формате
    void display() const {
        for (int i = stepen; i >= 0; i--) {
            if (coefficients[i] != 0) {
                if (i == stepen) {
                    cout << coefficients[i];
                }
                else {
                    cout << " + " << coefficients[i] << "x^" << i;
                }
            }
        }
        cout << endl;
    }
};

// Пример использования:
int main() {
    int stepen = 3;
    double coeffs1[] = { 1, 2, 3, 4 };
    double coeffs2[] = { 2, 1, 1, 0 };

    Polynomial p1(stepen);
    Polynomial p2(stepen);
    p1.setCoefficients(coeffs1);
    p2.setCoefficients(coeffs2);

    Polynomial p3 = p1 + p2;

    p1.display(); 
    p2.display(); 
    p3.display(); 

    cout << "Значение p1 при x=2: " << p1.evaluate(2) << endl; // 49
    cout << "Значение p2 при x=2: " << p2.evaluate(2) << endl; // 7
    cout << "Значение p3 при x=2: " << p3.evaluate(2) << endl; // 166

    return 0;
}
