#ifndef LIST_H
#define LIST_H

#include <stdint.h>

typedef int64_t spisok_elem_tipe; // FIXME транслит

static const int SIZE_LIST = 10;
static const int PHANTOM = -777;

struct Elem_list
{
    spisok_elem_tipe list; // FIXME list -> elem переименовать
    int64_t next;
    int64_t prev;
};

struct Info_list // FIXME просто List
{
    int64_t free;
    Elem_list* node;
};


void list_ctor(Info_list* list);
void list_dtor(Info_list* list);
void dump(Info_list* list);

// FIXME new -> insert
void new_middle_elem(Info_list* list, spisok_elem_tipe new_elem, int64_t index_elem);
void new_tail_elem(Info_list* list, spisok_elem_tipe new_elem);
void new_head_elem(Info_list* list, spisok_elem_tipe new_elem);

// NOTE if list is empty -> error
void erase_middle_elem(Info_list* list, int64_t index_elem);
void erase_head_elem(Info_list* list);
void erase_tail_elem(Info_list* list);

int64_t ix_next_elem(Info_list* list, int64_t index_elem);
int64_t ix_last_elem(Info_list* list, int64_t index_elem);

spisok_elem_tipe element(Info_list* list, int64_t index_elem);
void modify_elem(Info_list* list, spisok_elem_tipe new_elem, int64_t index_elem);

#endif //LIST_H