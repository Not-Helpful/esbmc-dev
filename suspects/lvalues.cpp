#include <source_location>

void f() {
    auto loc = std::source_location::current();
}

int main() {}
