#include "data.h"

int degrees[MAX_VERTICES + 1];
int odd_degrees[MAX_VERTICES];
int num_odd_degrees = 0;

int cmpfunc (const void * a, const void * b) {
    return (degrees[*(int*)a] - degrees[*(int*)b]); //for qsort
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]); //check for finding the file
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Could not open file %s\n", argv[1]); //check for opening the file
        exit(1);
    }

    int count = 1;
    while (! feof(fp))
    {
        if (fgetc(fp) == '\n')
            count++; //how many strings in file
    }

    fseek(fp, 0, 0); //return to the beginning of the code

    struct Edge *edges = malloc(count * sizeof(struct Edge));

    int u, v;
    for (int i = 0; i < count; i++) {
        fscanf(fp, "%d %d", &u, &v);
        edges[i].u = u;
        edges[i].v = v;
        degrees[u]++;
        degrees[v]++;
    }

    fclose(fp);

    for (int i = 1; i <= MAX_VERTICES; i++) {
        if (degrees[i] % 2 == 1) {
            odd_degrees[num_odd_degrees] = i; //check for odd
            num_odd_degrees++;
        }
    }

    qsort(odd_degrees, num_odd_degrees, sizeof(int), cmpfunc); //sorting

    printf("Vertices with odd degrees (in ascending order):\n");
    for (int i = 0; i < num_odd_degrees; i++) {
        printf("%d ", odd_degrees[i]); //printing data
    }
    puts("\n");

    free(edges);

    return 0;
}