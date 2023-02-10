/*
no.10808
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);

    char alpha_arr[26] = "abcdefghijklmnopqrstuvwxyz";
    int res_arr[26];

    int idx = 0;
    while (idx < 26)
    {
        res_arr[idx] = 0;
        idx++;
    }

    int i = 0;
    while (argv[1][i])
    {
        int j = 0;
        while (alpha_arr[j])
        {
            if (argv[1][i] == alpha_arr[j])
                res_arr[j]++;
            j++;
        }
        i++;
    }

    i = 0;
    while (i < 26)
    {
        printf("%d ", res_arr[i]);
        i++;
    }

    return (0);
}