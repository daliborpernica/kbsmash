#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct node node;
struct node
{
    void *data;
    node *next;
    node *prev;
};

typedef struct list
{
    node *first;
    node *last;
    node *get;
} list;

list *list_create();
void list_free(list *l, void (*action)(node *n));
void list_free_with_data(list *l);
void list_push(list *l, void *data);
void list_remove(list *l, node *n, void (*action)(node *n));
void list_remove_with_data(list *l, node *n);
void list_iterate(list *l, void (*action)(node *n));
void list_iterate_data(list *l, void (*action)(void *data));
void list_riterate(list *l, void (*action)(node *n));
void list_init_get(list *l);
node *list_get(list *l);
void *list_get_data(list *l);

#endif