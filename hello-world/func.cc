#include "io.h"
#include <iostream>

int main(){
    auto user_int1 = std::int32_t();
    auto user_int2 = std::int32_t{};

    user_int1 = readNumber();
    user_int2 = readNumber();

    writeNumber(user_int1 + user_int2);

    return 0;
}
