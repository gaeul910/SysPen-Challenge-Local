#include <stdio.h>
#include <unistd.h>

int flag()
{
    printf("This is flag!");
}

int vul()
{
    char username[0x20];
    char password[0x20];
    printf("Login as User: \n");
    fflush(stdout);
    printf("Enter username >>");
    read(0, username, 100);
    fflush(stdout);
    printf("Enter password >>");
    read(0, password, 100);
    fflush(stdout);
    
    return 0;
}

int main()
{
    vul();
}