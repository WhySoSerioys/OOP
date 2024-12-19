#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <ctime> 

class Base { 
public: 
virtual ~Base() {} 
virtual void show() const { 
std::cout << "Base" << std::endl; 
} 
}; 
class Derived : public Base { 
public: 
void show() const override { 
std::cout << "Derived" << std::endl; 
} 
}; 
void add(std::vector<Base*>& storage, Base* obj) { 
storage.push_back(obj); 
} 
int main() { 
std::vector<Base*> storage; 
std::srand(static_cast<unsigned int>(std::time(0))); 
for (int i = 0; i < 10; ++i) {   
Base* obj; 
if (std::rand() % 2 == 0) {  
obj = new Base(); 
} 
else { 
obj = new Derived(); 
} 
add(storage, obj); 
} 
for (const auto& obj : storage) { 
obj->show(); 
} 
for (auto& obj : storage) { 
delete obj; 
} 
return 0; 
}