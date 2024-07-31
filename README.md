# bottled

## overview

this repository primarily provides the following components:

- **control algorithm:** field-oriented control (FOC) for high-performance control of BLDC and PMSM.
- **fixed-point arithmetic:** optimized fixed-point arithmetic functions for efficient numerical computations.
- **coordinate transformation:** provides motor shaft coordinate transformations and space vector modulation algorithms.
- **observer:** implements commonly used observer algorithms in motor control, such as  the kalman filter, sliding mode observer (SMO), and flux linkage  observers.
- **controller:** high-performance current controllers, such as deadbeat controllers and PI controllers.
- **utility:** provides utility functions for operating with hardware peripheral registers.

## quick start

integrate directly into the project, for example:
```
my-project
    -- user_code
        -- include
        -- src
        -- ...
    -- lib
        -- bottled
        -- ...
```

## example

```C
#include <iostream>
#include <common/q_fixed.h>


int main(int argc, char const *argv[])
{
    float a;
    q_fixed y;
    q_fixed_var(x1, 245, 13);       // 0.0299072265625
    q_fixed_var(x2, 525, 15);       // 0.016021728515625
    q_fixed_mul(&y, x1, x2);    
    q_fixed_to_float(&a, y);    // 0.000479165
    std::cout << a;

    return 0;
}
```
