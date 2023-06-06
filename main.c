#include <stdio.h>

#include "storage/mailbox/finite_mailbox.h"

int main(int argc, char **argv)
{
    finite_mailbox *m = finite_mailbox_create(4, sizeof(int));

    finite_mailbox_send(m, (void *)1);
    finite_mailbox_send(m, (void *)2);
    finite_mailbox_send(m, (void *)4);
    finite_mailbox_send(m, (void *)3);

    if (finite_mailbox_is_full(m))
    {
        printf("ISFULL\n");
    }
    else
    {
        printf("NOTFULL\n");
    }

    while (!finite_mailbox_is_empty(m))
    {
        int *v = (int *)finite_mailbox_get(m);
        printf("%d\n", *v);
    }

    if (finite_mailbox_is_full(m))
    {
        printf("ISFULL\n");
    }
    else
    {
        printf("NOTFULL\n");
    }

    finite_mailbox_destroy(m);

    fputs("Helloo 😉!\n", stdout);

    getc(stdin);

    return 0;
}