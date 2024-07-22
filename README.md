# nongfu spring



## quick start

integrate directly into the project directory, for example:
```
my-project
    -- user_code
        -- include
        -- src
        -- ...
    -- lib
        -- nongfu_spring
        -- ...
```

## example

```C
#include <iostream>
#include <q_fixed.h>


int main(int argc, char const *argv[])
{
    float a;
    q_fixed y;
    q_fixed(x1, 245, 13);       // 0.0299072265625
    q_fixed(x2, 525, 15);       // 0.016021728515625
    q_fixed_mul(&y, x1, x2);    
    q_fixed_to_float(&a, y);    // 0.000479165
    std::cout << a;

    return 0;
}
```