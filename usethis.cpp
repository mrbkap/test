#include <cstdio>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

void
c_stdio(const char *fname)
{
    FILE *f, *out;
    int i;
    int numnodes, numedges;
    int edge1, edge2;
    int c;

    f = fopen(fname, "r");
    out = fopen("c_out", "w");
    if (!f || !out) {
        printf("Unable to open %s\n", f ? "c_out" : fname);
        return;
    }

    i = 0;
    while (fgetc(f) == 'g') {
        fscanf(f, "%d %d", &numnodes, &numedges);
        fprintf(out, "Graph %d has %d nodes and %d edges\n", i++, numnodes, numedges);

        while (numedges--) {
            fscanf(f, "%d %d", &edge1, &edge2);
            fprintf(out, "Read edge (%d, %d)\n", edge1, edge2);
        }

        while (isspace(c = fgetc(f)))
            continue;
        if (c != EOF)
            ungetc(c, f);
    }

    fclose(f);
}

void
cpp_streams(const char *fname)
{
    ifstream f(fname);
    ofstream out("cpp_streams");

    char ch;
    int i = 0;
    while (f >> ch) {
        assert(ch == 'g');

        int numnodes, numedges;
        f >> numnodes >> numedges;

        out << "Graph " << i++ << " has " << numnodes << " nodes and " << numedges << " edges\n";
        while (numedges--) {
            int edge1, edge2;
            f >> edge1 >> edge2;
            out << "Read edge (" << edge1 << ", " << edge2 << ")\n";
        }
    }
}

int
main(int argc, const char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    c_stdio(argv[1]);
    cpp_streams(argv[1]);

    return 0;
}
