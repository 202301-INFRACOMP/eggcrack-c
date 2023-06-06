#pragma once

#include <stdint.h>

typedef void priority_queue;

void *pq_create(uint64_t stride);

void pq_destroy(priority_queue *queue);

void *pq_peek(priority_queue *queue);

void pq_enqueue(priority_queue *queue, void *value);

void *pq_dequeue(priority_queue *queue);
