#include <iostream>
#include <string>
using namespace std;
class Sales {
public:
 int quantity[3];
 float cash[3];
 void getdata() {
 cout << "Введите количество проданных копий в 1-ом месяце: ";
 cin >> quantity[0];
 cout << "Введите количество проданных копий в 2-ом месяце: ";
 cin >> quantity[1];
 cout << "Введите количество проданных копий в 3-ом месяце: ";
 cin >> quantity[2];
 }
 void putdata() {
 cout << "Количество проданных копий в 1, 2, 3 месяцах: " << quantity[0] << ", " << quantity[1] << ", " <<
quantity[2] << endl;
 }
};
class Publication {
public:
 string title;
 float price;
 void getdata() {
 cout << "Введите название: ";
 getline(cin, title);
 cout << "Введите цену: ";
 cin >> price;
 }
 void putdata() {
 cout << "Название: " << title << endl;
 cout << "Цена: " << price << " руб." << endl;
 }
};
class Book : public Publication, public Sales {
public:
 int pages;
 void getdata() {
 Publication::getdata();
 cout << "Введите количество страниц: ";
 cin >> pages;
 Sales::getdata();
 cash[0] = quantity[0] * price;
 cash[1] = quantity[1] * price;
 cash[2] = quantity[2] * price;
 cin.ignore();
 }
 void putdata() {
 Publication::putdata();
 cout << "Количество страниц: " << pages << std::endl;
 Sales::putdata();
 cout << "Выручка с данных продаж по месяцам: " << cash[0] << " руб., " << cash[1] << " руб., " <<
cash[2] << " руб." << endl;
 }
};
class Type : public Publication, public Sales {
public:
 int duration;
 void getdata() {
 Publication::getdata();
 cout << "Введите время записи (в минутах): ";
 cin >> duration;
 Sales::getdata();
 cash[0] = quantity[0] * price;
 cash[1] = quantity[1] * price;
 cash[2] = quantity[2] * price;
 cin.ignore();
 }
 void putdata() {
 Publication::putdata();
 cout << "Продолжительность записи: " << duration << " минут." << endl;
 Sales::putdata();
 cout << "Выручка с данных продаж по месяцам: " << cash[0] << " руб., " << cash[1] << " руб., " <<
cash[2] << " руб." << endl;
 }
};
int main() {
 setlocale(LC_ALL, "ru");
 Book Book1;
 Type Book2;
 Book1.getdata();
 cout << endl;
 Book1.putdata();
 cout << endl;
 Book2.getdata();
 cout << endl;
 Book2.putdata();
}