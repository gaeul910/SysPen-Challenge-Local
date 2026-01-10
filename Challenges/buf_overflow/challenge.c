#include <stdio.h>

int vul()
{
    char id[0x10];
    char user[0x10];
    printf("Enter your ID: ");
    scanf("%s", id);
    printf("Enter Desired Username: ");
    scanf("%s", user);

    printf("Your account has been created\n");
    printf("id = %s\n", id);
    printf("Username = %s\n", user);

    return 0;
}

int flag()
{
    printf("This is Flag");

    return 0;
}

int main()
{
    vul();
    return 0;
}