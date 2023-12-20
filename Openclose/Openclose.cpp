// Openclose.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>


class Shape {
public:
    virtual double area() const = 0;
};


class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}

    double area() const override {
        return 3.14 * radius * radius;
    }

private:
    double radius;
};


class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double area() const override {
        return width * height;
    }

private:
    double width;
    double height;
};


class AreaCalculator {
public:
    double calculateArea(const std::vector<Shape*>& shapes) const {
        double totalArea = 0.0;
        for (const auto& shape : shapes) {
            totalArea += shape->area();
        }
        return totalArea;
    }
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    std::vector<Shape*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(&rectangle);

    AreaCalculator areaCalculator;
    double totalArea = areaCalculator.calculateArea(shapes);

    std::cout << "Total area: " << totalArea << std::endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
