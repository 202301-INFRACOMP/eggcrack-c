#include <windows_wrapper.h>

#include <stdio.h>
#include <stdlib.h>

#include <factory/id_sequencer.h>

#if defined WINDOWS_PLATFORM

typedef struct id_sequencer
{
    size_t id;
    CRITICAL_SECTION mutex;
} id_sequencer;

id_sequencer *sequencer_create()
{
    id_sequencer *s = malloc(sizeof(id_sequencer));

    if (s == NULL)
    {
        return NULL;
    }

    s->id = 0;

#ifdef NDEBUG
    InitializeCriticalSectionEx(&s->mutex, 4000, CRITICAL_SECTION_NO_DEBUG_INFO);
#else
    InitializeCriticalSectionEx(&s->mutex, 4000, 0);
#endif

    return s;
}

void sequencer_destroy(id_sequencer *s)
{
    DeleteCriticalSection(&s->mutex);
    free(s);
}

size_t sequencer_get_id(id_sequencer *s)
{
    EnterCriticalSection(&s->mutex);
    size_t value = s->id;
    s->id += 1;
    LeaveCriticalSection(&s->mutex);

    return value;
}
#elif defined POSIX_PLATFORM

#endif
