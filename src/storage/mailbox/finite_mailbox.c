#include "storage/mailbox/finite_mailbox.h"
#include "storage/circular_queue.h"

finite_mailbox *finite_mailbox_create(uint64_t size, uint64_t stride)
{
    return cq_create(size, stride);
}

void finite_mailbox_destroy(finite_mailbox *mailbox)
{
    cq_destroy(mailbox);
}

bool finite_mailbox_is_full(finite_mailbox *mailbox)
{
    return cq_is_full(mailbox);
}

bool finite_mailbox_is_empty(finite_mailbox *mailbox)
{
    return cq_is_empty(mailbox);
}

void finite_mailbox_send(finite_mailbox *mailbox, void *value)
{
    cq_enqueue(mailbox, value);
}

void *finite_mailbox_get(finite_mailbox *mailbox)
{
    return cq_dequeue(mailbox);
}
