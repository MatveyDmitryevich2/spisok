#ifndef LIST_H
#define LIST_H

#include <stdint.h>

typedef int64_t list_elem_tipe;

static const int SIZE_LIST = 10;
static const int PHANTOM = -777;

struct Elem_list
{
    list_elem_tipe elem;
    int64_t next;
    int64_t prev;
};

struct List
{
    int64_t free;
    Elem_list* node;
};


void list_ctor(List* list);
void list_dtor(List* list);

void insert_middle_elem(List* list, list_elem_tipe new_elem, int64_t index_elem);
void insert_tail_elem(List* list, list_elem_tipe new_elem);
void insert_head_elem(List* list, list_elem_tipe new_elem);

// NOTE if list is empty -> error
void erase_middle_elem(List* list, int64_t index_elem);
void erase_head_elem(List* list);
void erase_tail_elem(List* list);

int64_t ix_next_elem(List* list, int64_t index_elem);
int64_t ix_last_elem(List* list, int64_t index_elem);

list_elem_tipe element(List* list, int64_t index_elem);
void modify_elem(List* list, list_elem_tipe new_elem, int64_t index_elem);

#endif //LIST_H