#pragma once

typedef struct product
{
    size_t id;
    char *message;
} product;

void product_print(product p)
{
    printf("╔\n"
           "║Product\n"
           "║->id: %zu\n"
           "║->message: %s\n"
           "╚\n",
           p.id, p.message);
}
