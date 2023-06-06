#include "storage/circular_queue.h"

#include <stdlib.h>
#include <string.h>

circular_queue *cq_create(uint64_t size, uint64_t stride)
{
    uint64_t byte_size = size * stride;
    void *buffer = malloc(byte_size);

    circular_queue *queue = (circular_queue *)malloc(sizeof(circular_queue));

    if (queue == NULL)
        return NULL;

    queue->buffer = buffer;
    queue->size = size;
    queue->stride = stride;
    queue->front = UINT64_MAX;
    queue->rear = UINT64_MAX;

    return queue;
}

void cq_destroy(circular_queue *queue)
{
    free(queue->buffer);
    free(queue);
}

bool cq_is_full(circular_queue *queue)
{
    if (queue->front == 0 && queue->rear == queue->size - 1)
    {
        return true;
    }
    if (queue->front == queue->rear + 1)
    {
        return true;
    }

    return false;
}

bool cq_is_empty(circular_queue *queue)
{
    if (queue->front == UINT64_MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void cq_enqueue(circular_queue *queue, void *value)
{
    if (queue->front == UINT64_MAX)
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->size;
    }

    uint64_t address = (uint64_t)queue->buffer;
    address += (queue->rear * queue->stride);

    memcpy((void *)address, &value, queue->stride);
}

void *cq_dequeue(circular_queue *queue)
{
    void *value = malloc(queue->stride);

    if (value == NULL)
        return NULL;

    uint64_t address = (uint64_t)queue->buffer;
    address += (queue->front * queue->stride);
    memcpy(value, (void *)address, queue->stride);

    if (queue->front == queue->rear)
    {
        queue->front = UINT64_MAX;
        queue->rear = UINT64_MAX;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->size;
    }

    return value;
}
