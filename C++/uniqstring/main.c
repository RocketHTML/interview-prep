#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void partition(char *s, int start, int end)
{
    int wall = start;
    char pivot = s[end];
    int i;
    char tmp;

    if (start == end)
        return;

    if (end - start <= 2)
    {
        if (s[start] > s[end])
        {
            tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
        }
        return;
    }


    for(i = start; i <= end; i++)
    {
        if (s[i] < pivot)
        {
            tmp = s[i];
            s[i] = s[wall];
            s[wall] = tmp;
            wall++;
        }
    }

    partition(s, start, wall - 2); // left side
    partition(s, wall, end);
}

int isUniq(char *s)
{
    int start = 0;
    int end = strlen(s)- 2;
    partition(s, start, end);
    printf("%s\n", s);
    for (start = 0; start <= end - 1; start++)
    {
        if (s[start] == s[start + 1])
            return 0;
    }
    return 1;
}

int main()
{
    char one[] = "popopy";
    char two[] = "abcde";
    int ans1 = isUniq(one);
    int ans2 = isUniq(two);
    printf("%s is uniq: %d\n", one, ans1);
    printf("%s is uniq: %d\n", two, ans2);
}
