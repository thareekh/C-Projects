#include <stdio.h>
#include <stdlib.h>
void macro_replacement(char *)
void comment_removal(char *);
int main(int argc, char **argv)
{
    FILE *sf, *df;
    char *p;
    int n, ch, i;
    if (argc != 2)
    {
        printf("USAGE: ./a.out abc.c\n");
        return 1;
    }


    sf = fopen(argv[1], "r");
    fseek(sf,0,SEEK_END);
    n = ftell(sf);
    rewind(sf);

    df = fopen("abc.i", "w");

    p = malloc(n+1);
    i = 0;

    while ((ch = fgetc(sf)) != EOF)
    {
        p[i] = ch;
        i++;
    }
    p[i]=0;

comment_removal(p);

    printf("\n");
    printf("%s",p);
    printf("\n");
  

    return 0;
}

void comment_removal(char *p)
{
    char*q,*k;

    q=p;

    while(*q)
    {
        if(*q=='/' && *(q+1)=='/')
        {
            while(*q && *q!='\n')
            {
                *q=' ';
                q++;
            }
        }
        else if (*q=='/' && *(q+1)=='*')
        {
            k=q+2;

            while(*k)
            {
                if(*k=='*' && *(k+1) =='/')
                    break;

                k++;
            }

            if (*k=='*' && *(k+1)=='/')
            {
                while(q<=k+1)
                {
                    *q=' ';
                    q++;
                }
            }
        }
        else
        {
            q++;
        }
    }
}

void macro_replacement(char *p)
{
    char q[10]="#define ";
    char *k;
    k=p;
    while(*q!=*p)
        q++;



}


