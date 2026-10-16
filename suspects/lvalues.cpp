#include <source_location>

constexpr std::source_location loc =
    std::source_location::current();

int main() {
    return loc.line();
}
