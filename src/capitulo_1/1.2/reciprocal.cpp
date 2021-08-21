#include <cassert>
#include "../1.3/reciprocal.hpp"
double reciprocal(int i)
{
    // I should be non-zero.
    assert(i != 0);
    return 1.0 / i;
}