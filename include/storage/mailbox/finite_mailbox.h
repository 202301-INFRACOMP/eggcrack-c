#pragma once

#include "storage/circular_queue.h"

#include <stdbool.h>
#include <stdint.h>

typedef circular_queue finite_mailbox;

finite_mailbox *finite_mailbox_create(uint64_t size, uint64_t stride);

void finite_mailbox_destroy(finite_mailbox *mailbox);

bool finite_mailbox_is_full(finite_mailbox *mailbox);

bool finite_mailbox_is_empty(finite_mailbox *mailbox);

void finite_mailbox_send(finite_mailbox *mailbox, void *value);

void *finite_mailbox_get(finite_mailbox *mailbox);
