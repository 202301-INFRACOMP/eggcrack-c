#include <windows_wrapper.h>

#include <stdio.h>

#include <factory/id_sequencer.h>

#define THREAD_NUMBER 11

void execute_singlethreaded()
{
    id_sequencer *s = sequencer_create();

    const int printNumber = THREAD_NUMBER;
    for (int i = 0; i < printNumber; ++i)
    {
        printf("%zd\n", sequencer_get_id(s));    
    }

    sequencer_destroy(s);
}

#if defined WINDOWS_PLATFORM
const char *platform = "WINDOWS";

DWORD WINAPI get_id(LPVOID lpParam)
{
    id_sequencer *s = (id_sequencer *)lpParam;

    printf("%zd\n", sequencer_get_id(s));

    return 0;
}

void execute_multithreaded()
{
    id_sequencer *s = sequencer_create();

    HANDLE threads[THREAD_NUMBER];

    for (int i = 0; i < 11; ++i)
    {
        threads[i] = CreateThread(NULL, 0, get_id, s, 0, NULL);
    }

    WaitForMultipleObjects(THREAD_NUMBER, threads, TRUE, INFINITE);

    for (int i = 0; i < THREAD_NUMBER; ++i)
    {
        CloseHandle(threads[i]);
    }

    sequencer_destroy(s);
}
#elif defined POSIX_PLATFORM
const char *platform = "POSIX";

void execute_multithreaded()
{
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
