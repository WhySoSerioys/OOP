#include <iostream>

using namespace std;
//Задание В
int main() {
 setlocale(LC_ALL, "Ru");
 int x = 10;
 short* n = new short[x];
 for (short i = 0; i < 10; i++) {
    cin >> n[i];
 }
 for (short i = 0; i < 10; i++) {
    cout << endl << i + 1 << " Элемент: " << n[i] << "; Адрес: " << &n[i] << ";Дистанция от первого элемента(в байтах) : " << (&n[i] - &n[0]) * sizeof(short);
 }
 delete n;
}
