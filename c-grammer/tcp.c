#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char const *argv[])
{
    int lintenfd = socket(AF_INET, SOCK_STREAM, 0);
    return 0;
}
