#include <iostream>
#include <string>
using namespace std;
int tech = 0;
int lit = 0;
//2 Задание, Вариант А,Б
void list(int a) {
 if (a == 1) {
 lit++;
 }
 else if (a == 2) {
 tech++;
 }
}
class book {
public:
 string auth;
 string name;
 string type;
 int n;
 book(string x, string y, string z) {
 auth = x;
 name = y;
 type = z;
 if (z == "Художественная") {
 n = 1;
 }
 else if (z == "Техническая") {
 n = 2;
 }
 list(n);
 }
};
int main() {
 setlocale(LC_ALL, "ru");
 int i = 1;
 book book1("Пушкин", "Евгений Онегин", "Художественная");
 book book2("Рыжов", "Стали и спавы энергетического оборудования", "Техническая");
 book book3("Винокуров", "Энциклопедия 'Машиностроение'", "Техническая");
 cout << "Для вывода количества технической литературы введите 1; Для вывода количества художественной литературы введите 2; Для прекращения работы введите 0" << endl;
 while (i != 0) {
 cin >> i;
 cout << endl;
 switch (i) {
 case 2:
 cout << "Количество художественной литературы: " << lit << endl;
 break;
 case 1:
 cout << "Количество технической литературы: " << tech << endl;
 break;
 case 0:
 break;
 default:
 cout << "Ошибка, неверное число" << endl;
 break;
 }
 }
}