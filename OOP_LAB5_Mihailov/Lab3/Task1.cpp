#include <iostream> 
#include <vector> 
#include <memory> 
#include <string> 
class Component { 
protected: 
Component() {} 
public: 
virtual ~Component() {} 
virtual void info() const = 0; 
};
class Part : public Component { 
protected: 
Part() : name("Unnamed part") {} 
Part(const std::string& name) : name(name) {} 
std::string name; 
public: 
virtual ~Part() {} 
void info() const override { 
std::cout << "Part: " << name << std::endl; 
} 
template<typename T, typename... Args> 
friend std::shared_ptr<T> createComponent(Args&&... args); 
};
class Assembly : public Component { 
protected: 
Assembly() : name("Unnamed assembly") {} 
Assembly(const std::string& name) : name(name) {} 
std::string name; 
public: 
virtual ~Assembly() {} 
void info() const override { 
std::cout << "Assembly: " << name << std::endl; 
} 
template<typename T, typename... Args> 
friend std::shared_ptr<T> createComponent(Args&&... args); 
}; 
template<typename T, typename... Args> 
std::shared_ptr<T> createComponent(Args&&... args) { 
static_assert(std::is_base_of<Component, T>::value, "T must be a Component"); 
return std::shared_ptr<T>(new T(std::forward<Args>(args)...)); 
} 
int main() { 
int i = 0; 
std::vector<std::shared_ptr<Component>> components; 
components.push_back(createComponent<Part>("Engine's part")); 
components.push_back(createComponent<Assembly>("Engines assembly")); 
components.push_back(createComponent<Part>("Wheel's Part")); 
components.push_back(createComponent<Assembly>("Wheels assembly")); 
components.push_back(createComponent<Part>("Brakes's Part")); 
components.push_back(createComponent<Assembly>("Brakes assembly")); 
for (const auto& component : components) { 
component->info(); 
if (i == 1) { 
std::cout << std::endl; 
i -= 2; 
} 
i++; 
} 
return 0; 
}