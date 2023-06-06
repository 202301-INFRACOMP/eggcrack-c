#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct circular_queue
{
    void *buffer;
    uint64_t size;
    uint64_t stride;
    uint64_t front;
    uint64_t rear;
} circular_queue;

circular_queue *cq_create(uint64_t size, uint64_t stride);

void cq_destroy(circular_queue *queue);

bool cq_is_full(circular_queue *queue);

bool cq_is_empty(circular_queue *queue);

void cq_enqueue(circular_queue *queue, void *value);

void *cq_dequeue(circular_queue *queue);
