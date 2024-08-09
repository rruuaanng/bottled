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
#include <stdio.h>
#include <common/qfixed.h>


int main(int argc, char const *argv[])
{
    qfixed x1, x2;

    x1 = q15(0.13125);
    x2 = q15(0.31541);
    
    printf("result: %.4f ", 
        q15_fixed_to_float(q15_fixed_add(x1, x2)));   // 0.4466
    return 0;
}
```
