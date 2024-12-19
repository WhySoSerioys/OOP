#include <iostream>
#include <string>
using namespace std;
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
class Book: public Publication {
public:
 int pages;
 void getdata() {
 Publication::getdata();
 cout << "Введите количество страниц: ";
 cin >> pages;
cin.ignore();
 }
 void putdata() {
 Publication::putdata();
 cout << "Количество страниц: " << pages << std::endl;
 }
};
class Type : public Publication {
public:
 int duration;
 void getdata() {
 Publication::getdata();
 cout << "Введите время записи (в минутах): ";
 cin >> duration;
cin.ignore();
 }
 void putdata() {
 Publication::putdata();
 cout << "Продолжительность записи: " << duration << " минут." << std::endl;
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