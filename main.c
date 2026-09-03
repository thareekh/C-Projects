#include "header.h"

int main(int argc, char **argv)
{
    FILE *sf;
    char *p;
    int n, ch, i;
    if (argc != 2)
    {
        printf("USAGE: ./my_Preprocessor abc.c\n");
        return 1;
    }


    sf = fopen(argv[1], "r");
    fseek(sf,0,SEEK_END);
    n = ftell(sf);
    rewind(sf);

    p = malloc(n+1);
    i = 0;

    while ((ch = fgetc(sf)) != EOF)
    {
        p[i] = ch;
        i++;
    }
    p[i]=0;

    comment_removal(p);

    macro_replacement(p);
   
    header_inclusion(p);

    free(p);

    return 0;
}


