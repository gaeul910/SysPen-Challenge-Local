#include <stdio.h>
#include <unistd.h>
int vul()
{
    char username[0x10];
    char user_id[0x10];
    printf("Enter Username: ");
    fflush(stdout);
    read(0, username, 0x100);
    printf("Username is %s", username);
    printf("Enter User ID: ");
    fflush(stdout);
    read(0, user_id, 0x100);
    printf("Username: %s", username);
    printf("User_ID: %s", user_id);
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
