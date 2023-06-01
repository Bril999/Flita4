#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_VERTICES 10000

struct Edge {
    int u;
    int v;
};