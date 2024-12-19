#include <iostream> 
#include <string> 
#include <vector> 
#include <memory> 
class Vehicle { 
protected: 
std::string creation; 
std::string model; 
public: 
Vehicle(std::string creation, std::string model) : creation(creation), model(model) {} 
virtual void display() const { 
std::cout << "Дата создания: " << creation << ", Модель: " << model << std::endl; 
} 
}; 
class Bike : public Vehicle { 
public: 
Bike(std::string creation, std::string model) : Vehicle(creation, model) {} 
void display() const override { 
std::cout << "Велосипед| "; 
Vehicle::display(); 
} 
}; 
class Car : public Vehicle { 
public: 
Car(std::string creation, std::string model) : Vehicle(creation, model) {} 
void display() const override { 
std::cout << "Машина| "; 
Vehicle::display(); 
} 
}; 
class Truck : public Vehicle { 
public: 
Truck(std::string creation, std::string model) : Vehicle(creation, model) {} 
void display() const override { 
std::cout << "Грузовик| "; 
Vehicle::display(); 
} 
}; 
template <typename T> 
class ArrayContainer { 
private: 
std::vector<std::shared_ptr<T>> elements; 
public: 
void add(std::shared_ptr<T> element) { 
elements.push_back(element); 
} 
std::shared_ptr<T>& operator[](size_t index) { 
return elements.at(index); 
} 
size_t size() const { 
return elements.size(); 
} 
}; 
int main() { 
setlocale(LC_ALL, "Russian"); 
auto bike = std::make_shared<Bike>("05.2032", "AX400"); 
auto car = std::make_shared<Car>("08.2038", "RK800"); 
auto truck = std::make_shared<Truck>("11.2038", "RK200"); 
ArrayContainer<Vehicle> Vehicles; 
Vehicles.add(bike); 
Vehicles.add(car); 
Vehicles.add(truck); 
for (size_t i = 0; i < Vehicles.size(); ++i) { 
Vehicles[i]->display(); 
} 
return 0; 
} 