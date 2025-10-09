#include <stdio.h>

int vul()
{
    char username[0x10];
    char user_id[0x10];
    printf("Enter Username: ");
    read(0, username, 0x100);
    printf("Enter User ID: ");
    read(0, user_id, 0x100);
    return 0;
}

int get_flag()
{
    printf("This is Flag!");
    return 0;
}

int main()
{
    vul();

    return 0;
}
