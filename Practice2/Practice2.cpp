// Practice2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void task1();
void task2();
void task3();
void task4();

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите номер задачи для выбора: ";
    int taskNumber;
    std::cin >> taskNumber;

    switch (taskNumber)
    {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        default: std::cout << "Такого задания не существует.";
    }
}


// Задание - 1. Найдите максимальный элемент в одномерном массиве.
void task1() {
    const int size = 5;
    int arr[size] = { 10, 5, 8, 15, 3 };

    int maxElement = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    std::cout << "Максимальный элемент в массиве: " << maxElement << std::endl;
}


// Задание - 2. Проверьте, является ли многомерный массив симметричным относительно главной диагонали.
void task2() {
    const int depth = 3;
    const int rows = 3;
    const int cols = 3;

    int arr[depth][rows][cols] = {
        {
            {1, 2, 3},
            {2, 4, 5},
            {3, 5, 6}
        },
        {
            {7, 8, 9},
            {8, 10, 11},
            {9, 11, 12}
        },
        {
            {13, 14, 15},
            {14, 16, 17},
            {15, 17, 18}
        },
    };

    for (int k = 0; k < depth; k++) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[k][i][j] != arr[k][j][i]) {
                    std::cout << "Массив не симметричен относительно главной диагонали.";
                    return;
                }
            }
            
        }
    }

    std::cout << "Массив симметричен относительно главной диагонали.";
}


// Задание - 3. Создайте структуру "Rectangle" с полями "width" (вещественное число) и "height" (вещественное число). 
//              Напишите программу на C++, которая находит площадь прямоугольника.
struct Rectangle {
    double width;
    double height;
};

void task3() {
    Rectangle myRectangle;

    std::cout << "Введите ширину прямоугольника: ";
    std::cin >> myRectangle.width;

    std::cout << "Введите высоту прямоугольника: ";
    std::cin >> myRectangle.height;

    double area = myRectangle.width * myRectangle.height;
    if (area < 0) {
        std::cout << "Введены неверные значения";
        return;
    }

    std::cout << "Площадь прямоугольника: " << area;
}


// Задание - 4. Создайте класс "BankAccount" с приватными полями "accountNumber" (массив символов) и "balance" (вещественное число) 
//              и публичными методами для пополнения и снятия денег со счета.
class BankAccount {
private:
    char accountNumber[20];
    double balance;

public:
    BankAccount(const char inputAccountNumber[], double inputBalance) {
        strcpy_s(this -> accountNumber, inputAccountNumber);
        this -> balance = inputBalance;
    }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Счет успешно пополнен. Новый баланс: " << balance << std::endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Вы успешно сняли деньги. Новый баланс: " << balance << std::endl;
        }
        else {
            std::cout << "Недостаточно средств на счете." << std::endl;
        }
    }
};


void task4() {
    BankAccount myAccount("123456789", 1000.0);

    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    myAccount.withdraw(800.0);
    myAccount.withdraw(501.0);
}