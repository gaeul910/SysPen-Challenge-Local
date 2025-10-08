#include <stdio.h>

int vul()
{
    char username[0x10];
    char user_id[0x10];
    printf("Enter Username: ");
    gets(username);
    printf("Enter User ID: ");
    gets(user_id);
    return 0;
}
int main()
{
    vul();

    return 0;
}