#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <limits>
using namespace std;

struct MultiplicationTable {
    vector<string> rows;
};

void show_menu() {
    cout << "=== ГЛАВНОЕ МЕНЮ ===" << endl;
    cout << "1. Генерация таблицы" << endl;
    cout << "2. Тестирование" << endl;
    cout << "3. Выход" << endl;
    cout << "====================" << endl;
    cout << "Выберите действие (1-3): ";
}

MultiplicationTable generate_multiplication_table(int n) {
    MultiplicationTable table;
    if (n < 1 || n > 20) {
        return table;
    }

    int max_val = n * n;
    int width = static_cast<int>(to_string(max_val).length()) + 1;
    if (width < 2) width = 2;

    for (int i = 1; i <= n; ++i) {
        ostringstream row;
        for (int j = 1; j <= n; ++j) {
            row << setw(width) << (i * j);
        }
        table.rows.push_back(row.str());
    }

    return table;
}

void test_multiplication_table() {
    cout << "\n=== ТЕСТИРОВАНИЕ ===" << endl;

    // Некорректные входные данные — должны возвращать пустую таблицу
    auto t1 = generate_multiplication_table(-5);
    cout << "Тест 1 (N = -5): " << (t1.rows.empty() ? "✅ Обработка ошибки" : "❌ Ошибка") << endl;

    auto t2 = generate_multiplication_table(0);
    cout << "Тест 2 (N = 0):  " << (t2.rows.empty() ? "✅ Обработка ошибки" : "❌ Ошибка") << endl;

    auto t3 = generate_multiplication_table(25);
    cout << "Тест 3 (N = 25): " << (t3.rows.empty() ? "✅ Обработка ошибки" : "❌ Ошибка") << endl;

    auto t4 = generate_multiplication_table(100);
    cout << "Тест 4 (N = 100): " << (t4.rows.empty() ? "✅ Обработка ошибки" : "❌ Ошибка") << endl;

    // Корректные тесты — выводим ВСЮ таблицу
    cout << "\nТест 5 (N = 1):" << endl;
    auto t5 = generate_multiplication_table(1);
    for (const auto& row : t5.rows) {
        cout << "\"" << row << "\"" << endl;
    }

    cout << "\nТест 6 (N = 3):" << endl;
    auto t6 = generate_multiplication_table(3);
    for (const auto& row : t6.rows) {
        cout << "\"" << row << "\"" << endl;
    }

    cout << "\nТест 7 (N = 20):" << endl;
    auto t7 = generate_multiplication_table(20);
    if (!t7.rows.empty()) {
        cout << "Полная таблица умножения 20×20:" << endl;
        for (const auto& row : t7.rows) {
            cout << "\"" << row << "\"" << endl;
        }
    } else {
        cout << "❌ Не удалось сгенерировать таблицу 20×20" << endl;
    }

    // Дополнительный тест на очень большое число
    auto t8 = generate_multiplication_table(5000);
    cout << "\nТест 8 (N = 5000): " << (t8.rows.empty() ? "✅ Отклонено корректно" : "❌ Должно быть пусто") << endl;

    cout << endl;
}

void get_user_input_and_generate() {
    int n;
    while (true) {
        cout << "Введите размер таблицы (от 1 до 20): ";
        if (cin >> n) {
            if (n < 1 || n > 20) {
                cout << "Ошибка: разрешены только значения от 1 до 20." << endl;
                continue;
            }

            MultiplicationTable table = generate_multiplication_table(n);
            cout << "\nСгенерированная таблица (" << n << "x" << n << "):" << endl;
            for (const string& row : table.rows) {
                cout << "\"" << row << "\"" << endl;
            }
            cout << endl;
            break;
        } else {
            cout << "Ошибка: введите целое число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    int choice;
    while (true) {
        show_menu();
        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice == 1) {
                get_user_input_and_generate();
            }
            else if (choice == 2) {
                test_multiplication_table();
            }
            else if (choice == 3) {
                cout << "\nВыход из программы. До свидания!" << endl;
                return 0;
            }
            else {
                cout << "\nОшибка: введите число от 1 до 3." << endl << endl;
            }
        }
        else {
            cout << "\nОшибка: введите число от 1 до 3." << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
