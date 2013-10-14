#include <stdio.h>
#include <termios.h>
#include <unistd.h>
void clear()
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}
int main(int argc,char* argv[])
{
    if (argc != 2)
    {
        printf("Usage");
        return 1;
    }
    FILE* f = fopen(argv[1],"r");
    if (f == NULL)
    {
        printf("can't find");
        return 2;
    }
    clear();
    struct termios current_seeting,hacker_setting;
    tcgetattr(0, &current_seeting);
    hack_seeting = current_setting;

}

