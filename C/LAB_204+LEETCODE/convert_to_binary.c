#include <stdio.h>

void convert(int n)
{
    if (n == 0)
        return;
    convert(n / 2);
    printf("%d", n % 2);
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("%d in binary is ", num);
    if (num == 0)
        printf("0");  // special case for 0
    else
        convert(num);

    printf("\n");
    return 0;
}
