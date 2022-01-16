#include <stdlib.h>
#include "list.h"

void free_data(node *n)
{
    free(n->data);
}

list *list_create()
{
    list *newlist = (list*) malloc(sizeof(*newlist));
    newlist->first = NULL;
    newlist->last = NULL;

    return newlist;
}

void list_free(list *l, void (*action)(node *n))
{
    node *current = l->first;
    node *next;

    while(current != NULL)
    {
        next = current->next;
        if (action != NULL)
        {
            action(current);
        }
        free(current);
        current = next;
    }

    free(l);
    l = NULL;
}

void list_free_with_data(list *l)
{
    list_free(l, free_data);
}

void list_push(list *l, void *data)
{
    node *newitem = (node*)malloc(sizeof(*newitem));
    newitem->data = data;
    newitem->prev = l->last;
    newitem->next = NULL;

    if (l->first == NULL)
    {
        l->first = newitem;
    }
    if (l->last != NULL)
    {
        l->last->next = newitem;
    }

    l->last = newitem;
}

void list_remove(list *l, node *n, void (*action)(node *n))
{
    if (n->prev == NULL)
    {
        l->first = n->next;
    }
    else
    {
        n->prev->next = n->next;
    }
    if (n->next == NULL)
    {
        l->last = n->prev;
    }
    else
    {
        n->next->prev = n->prev;
    }
    if (l->get == n)
    {
        l->get = NULL;
    }
    if (action != NULL)
    {
        action(n);
    }
    free(n);
}

void list_remove_with_data(list *l, node *n)
{
    list_remove(l, n, free_data);
}

void list_iterate(list *l, void (*action)(node *n))
{
    node *current = l->first;
    while (current != NULL)
    {
        action(current);
        current = current->next;
    }  
}

void list_iterate_data(list *l, void (*action)(void *data))
{
    node *current = l->first;
    while (current != NULL)
    {
        action(current->data);
        current = current->next;
    }  
}

void list_riterate(list *l, void (*action)(node *n))
{
    node *current = l->last;
    while (current != NULL)
    {
        action(current);
        current = current->prev;
    }  
}

void list_init_get(list *l)
{
    l->get = l->first;
}

node *list_get(list *l)
{
    node *get = l->get;
    if (l->get != NULL)
    {
        l->get = l->get->next;
    }

    return get;
}

void *list_get_data(list *l)
{
    node *get = list_get(l);
    if (get != NULL)
    {
        return get->data;
    }

    return NULL;
}