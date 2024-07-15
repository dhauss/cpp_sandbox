#include <iostream>
#include "io.h"

void writeNumber(std::int32_t num){
    std::cout << "Added your nums for you " << num << '\n';
}

std::int32_t readNumber(){
    auto num = std::uint32_t{};

    std::cout << "Type an int\n";
    std::cin >> num;

    return num;
}