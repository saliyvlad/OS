#include <iostream>
#include <cmath>
using namespace std;

class Parallelogram {
private:
    double a; // сторона a
    double b; // сторона b
    double alpha; // угол между сторонами в градусах

public:
    // Конструктор по умолчанию
    Parallelogram() : a(1.0), b(1.0), alpha(90.0) {}

    // Конструктор с параметрами
    Parallelogram(double sideA, double sideB, double angle) 
        : a(sideA), b(sideB), alpha(angle) {}

    // Метод для проверки, является ли параллелограмм квадратом
    bool isSquare() const {
        return (a == b) && (alpha == 90.0);
    }

    // Метод для проверки, является ли параллелограмм прямоугольником
    bool isRectangle() const {
        return (alpha == 90.0) && (a != b);
    }

    // Метод для вычисления площади параллелограмма
    double area() const {
        return a * b * sin(alpha * M_PI / 180.0);
    }

    // Метод для вывода информации о параллелограмме
    void printInfo() const {
        cout << "Стороны: a = " << a << ", b = " << b 
             << ", угол = " << alpha << "°, площадь = " << area() << endl;
    }
};

int main() {
    int N;
    cout << "Введите количество параллелограммов: ";
    cin >> N;

    // Создаем массив указателей на объекты Parallelogram
    Parallelogram** parallelograms = new Parallelogram*[N];
    
    // Создание N параллелограммов
    for (int i = 0; i < N; i++) {
        double a, b, alpha;
        cout << "\nПараллелограмм " << i + 1 << ":" << endl;
        cout << "Введите сторону a: ";
        cin >> a;
        cout << "Введите сторону b: ";
        cin >> b;
        cout << "Введите угол между сторонами (в градусах): ";
        cin >> alpha;
        
        // Создаем объект в динамической памяти
        parallelograms[i] = new Parallelogram(a, b, alpha);
    }

    // Подсчет квадратов и прямоугольников
    int k1 = 0; // количество квадратов
    int k2 = 0; // количество прямоугольников

    cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Параллелограмм " << i + 1 << ": ";
        parallelograms[i]->printInfo();
        
        if (parallelograms[i]->isSquare()) {
            cout << "  -> Это КВАДРАТ" << endl;
            k1++;
        } else if (parallelograms[i]->isRectangle()) {
            cout << "  -> Это ПРЯМОУГОЛЬНИК" << endl;
            k2++;
        } else {
            cout << "  -> Это обычный параллелограмм" << endl;
        }
    }

    cout << "\n=== СТАТИСТИКА ===" << endl;
    cout << "Общее количество параллелограммов: " << N << endl;
    cout << "Количество квадратов (k1): " << k1 << endl;
    cout << "Количество прямоугольников (k2): " << k2 << endl;
    cout << "Количество других параллелограммов: " << N - k1 - k2 << endl;

    // Освобождение памяти
    for (int i = 0; i < N; i++) {
        delete parallelograms[i]; // удаляем каждый объект
    }
    delete[] parallelograms; // удаляем массив указателей

    return 0;
}
