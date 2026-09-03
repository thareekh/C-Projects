#include "header.h"
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

