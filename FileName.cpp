#include <iostream>
#include <string>

template<typename T> 
concept ComplexConcept = !std::has_virtual_destructor<T>::value && requires (T t)
{
    {t.hash()}->std::convertible_to<long>;
    {t.toString()}->std::same_as<std::string>;
};

struct y
{
    int z = 0;
    std::string toString() { return std::to_string(z); }
    int hash() { return 1; };
};

void print(ComplexConcept  auto& t)
{
    std::cout << t.toString() << std::endl;
}

int main()
{
    y x{ 20 };
    print(x);
}