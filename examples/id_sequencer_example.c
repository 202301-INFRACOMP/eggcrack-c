
#include <stdio.h>

#include "../include/factory/id_sequencer.h"

const char *platform;
void execute_singlethreaded()
{
    id_sequencer *s = sequencer_create();

    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));
    printf("%zd\n", sequencer_get_id(s));

    sequencer_destroy(s);
}

#ifdef WINDOWS_PLATFORM
#include <windows_wrapper.h>

platform = "WINDOWS";

DWORD WINAPI get_id(LPVOID lpParam)
{
    id_sequencer *s = (id_sequencer *)lpParam;

    printf("%zd\n", sequencer_get_id(s));

    return 0;
}

void execute_multithreaded()
{
    id_sequencer *s = sequencer_create();

    const int threadNumber = 11;
    HANDLE threads[threadNumber];

    for (int i = 0; i < 11; ++i)
    {
        threads[i] = CreateThread(NULL, 0, get_id, s, 0, NULL);
    }

    WaitForMultipleObjects(threadNumber, threads, TRUE, INFINITE);

    for (int i = 0; i < threadNumber; ++i)
    {
        CloseHandle(threads[i]);
    }

    sequencer_destroy(s);
}
#endif

#ifdef POSIX_PLATFORM
#include <pthread.h>

void *get_id(void *arg)
{
    id_sequencer *s = (id_sequencer *)arg;
    printf("%zd\n", sequencer_get_id(s));
    return NULL;
}

void execute_multithreaded()
{
    pthread_t threads[11];
    id_sequencer *s = sequencer_create();

    for (int i = 0; i < 11; ++i)
    {
        if (pthread_create(&threads[i], NULL, get_id, s) != 0)
        {
            fprintf(stderr, "Error creating thread %d\n", i);
        }
    }

    for (int i = 0; i < 11; ++i)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            fprintf(stderr, "Error joining thread %d\n", i);
        }
    }

    sequencer_destroy(s);
}
#endif

int main(int argc, char **argv)
{
    printf("[id_sequencer_example] - %s\n\n", platform);
    printf("Executing single threaded version...\n");
    execute_singlethreaded();

    printf("\nExecuting multi threaded version...\n");
    execute_multithreaded();

    return 0;
}
