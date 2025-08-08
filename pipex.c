#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s infile cmd1 cmd2 outfile\n", argv[0]);
        return 1;
    }
    // ここにパイプ処理を実装していきます
    return 0;
}