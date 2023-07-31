#include <stdio.h>

#include <factory/id_sequencer.h>

int main(int argc, char **argv)
{
    id_sequencer *s = sequencer_create();

    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));

    sequencer_destroy(s);

    return 0;
}
