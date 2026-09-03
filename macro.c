#include "header.h"

void macro_replacement(char *p)
{
    char *t, *m_start, *m_value, *q;
    char replace[20], value[100];
    char temp[1000];
    int i;

    t=strstr(p,"#define");

    while(t!=0)
    {
        m_start=t+8;
        i=0;
        while(m_start[i] != ' ' && m_start[i] != '\n' && m_start[i] != '\0')
        {
            replace[i]=m_start[i];
            i++;
        }

        replace[i] = '\0';

        while(*m_start== ' ')
            m_start++;

        m_value=m_start+strlen(replace);

        while(*m_value==' ')
            m_value++;

        i = 0;

        while(m_value[i]!='\n' && m_value[i]!='\0')
        {
            value[i] = m_value[i];
            i++;
        }

        value[i] = '\0';
       
        q=strchr(t,'\n');

        if (q!=0)
        {
            strcpy(t,q+1);
        }
        else
        {
            *t = '\0';
        }

    q = strstr(p,replace);

        while (q!=0)
        {
            strcpy(temp,q+strlen(replace));

            strcpy(q,value);

       

            strcpy(q+strlen(value),temp);

            q=strstr(q+strlen(value),replace);
        }

        t = strstr(p,"#define");
    }
}

