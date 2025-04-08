#pragma once

#include <iostream>
#include <cstddef>
#include <initializer_list>
#include <algorithm>

namespace la
{
    template <typename K, std::size_t N, std::size_t M>
    struct Matrix
    {
        K data[N][M];
    };
}
