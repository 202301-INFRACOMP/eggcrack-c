#include <stdio.h>

int main(int argc, char **argv)
{
    printf("========================================================================\n"
           "                                       _                                \n"
           "                                      | |                               \n"
           "   ___  __ _  __ _  ___ _ __ __ _  ___| | __                            \n"
           "  / _ \\/ _` |/ _` |/ __| '__/ _` |/ __| |/ /                           \n"
           " |  __/ (_| | (_| | (__| | | (_| | (__|   <                             \n"
           "  \\___|\\__, |\\__, |\\___|_|  \\__,_|\\___|_|\\_\\                    \n"
           "        __/ | __/ |                                                     \n"
           "       |___/ |___/                                                      \n"
           "========================================================================\n\n");

    printf("Welcome to eggcrack - C implementation\n");
    printf("For more information see: https://github.com/202301-INFRACOMP/eggcrack-c\n");

    printf("\nWork finished!!!\n");
    printf("Press enter to exit...\n");

    while (getchar() != '\n')
    {
    }

    return 0;
}
