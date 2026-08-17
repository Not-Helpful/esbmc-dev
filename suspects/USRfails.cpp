#include <iostream>

template<auto Operation>
struct Algorithm
{
    static int run(int x)
    {
        return Operation(x);
    }
};

constexpr auto square = [](int x) {
    return x * x;
};

constexpr auto increment = [](int x) {
    return x + 1;
};

int main()
{
    std::cout << Algorithm<square>::run(7) << "\n";
    std::cout << Algorithm<increment>::run(5) << "\n";    
}

// #include <iostream>
// #include <functional>

// void apply(std::function<int(int)> f)
// {
//     std::cout << f(5) << "\n";
// }

// int main()
// {
//     apply([](int x) {
//         return x * 2;
//     });
// }
