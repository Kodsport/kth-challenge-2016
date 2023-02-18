#include "validator.h"

void run() {
    Float(-10000, 10000, 4); Space();
    Float(-10000, 10000, 4); Space();
    Float(-10000, 10000, 4); Space();
    Float(-10000, 10000, 4); Endl();
    int n = Int(1,10000); Endl();
    SpacedFloats(n-1, -10000, 10000, 4); 
    SpacedFloats(n, -10000, 10000, 4);
}
