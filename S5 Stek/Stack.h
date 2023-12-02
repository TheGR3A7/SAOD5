#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Parking {
    int* cars;
    int top;
    int capacity;
};