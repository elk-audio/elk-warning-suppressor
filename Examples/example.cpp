#include "elk-warning-suppressor/warning_suppressor.hpp"

int main()
{
    unsigned int one = 0;
    int two = 0;

    ELK_PUSH_WARNING
    ELK_DISABLE_SIGN_CONVERSION
    two = one; // This warning will be suppressed when building.
    ELK_POP_WARNING

    return 0;
}