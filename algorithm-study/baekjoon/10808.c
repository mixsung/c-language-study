/*
no.10808
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);

    int res_arr[26];
    int i = 0;
    while (i < 26)   // int array 초기화
    {
        res_arr[i] = 0;
        i++;
    }
    i = 0;
    while (argv[1][i])  // 알파벳 배열을 따로 만들지 않고 바로 넣기로 수정함
    {
        char tmp = argv[1][i];
        res_arr[tmp - 'a']++;
        i++;
    }
    i = 0;
    while (i < 26)   // 출력으로 결과확인
    {
        printf("%d ", res_arr[i]);
        i++;
    }

    return (0);
}