
#include "header.h"

void header_inclusion(char *p)
{
    char *q, *k;
    char filename[25];
    char path[50];
    FILE *hf, *df;
    int i;
    char ch;

    df = fopen("abc.i", "w");

    q = p;

    while (*q)
    {
        if (strncmp(q, "#include", 8) == 0)
        {
            k = q + 8;

            while (*k == ' ' || *k == '\t')
                k++;

            if (*k == '<')
            {
                k++;
                i = 0;

                while (*k && *k != '>')
                {
                    filename[i] = *k;
                    i++;
                    k++;
                }

                filename[i] = '\0';

                if (*k == '>')
                {
                    sprintf(path, "/usr/include/%s", filename);

                    hf = fopen(path, "r");

                    if (hf != NULL)
                    {
                        while ((ch = fgetc(hf)) != EOF)
                        {
                            fputc(ch, df);
                        }

                        fclose(hf);

                        while (q <= k)
                        {
                            *q = ' ';
                            q++;
                        }
                    }
                }
            }
        }
        else
        {
            q++;
        }
    }

    fprintf(df, "%s", p);

    fclose(df);
}
