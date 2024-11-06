#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <assert.h>
#include <stdint.h>
#include <math.h>


#include "list.h"
#include "dump_file.h"

void list_ctor(List* list)
{
    assert(list != NULL);

    list->node = (Elem_list*)calloc(SIZE_LIST, sizeof(Elem_list));
    assert(list->node != NULL);

    list->node[0].next = 0;
    for (size_t i = 1; i < SIZE_LIST; i++) 
    { 
        list->node[i].next = (int64_t)(i + 1); 
    }

    list->free = 1;
}

void list_dtor(List* list)
{
    assert(list != NULL);

    free(list->node);
    list = NULL;
}

void insert_middle_elem(List* list, list_elem_tipe new_elem, int64_t index_elem)
{
    assert(list != NULL);

    int64_t old_next = list->node[index_elem].next;
    int64_t new_free = list->node[list->free].next;

    list->node[list->free].elem = new_elem;
    
    list->node[index_elem].next = list->free;
    list->node[list->free].prev = index_elem;
    list->node[list->free].next = old_next;
    list->node[old_next].prev = list->free;
    
    list->free = new_free;

    dump(list);
}

void insert_tail_elem(List* list, list_elem_tipe new_elem)
{
    assert(list != NULL);

    insert_middle_elem(list, new_elem, list->node[0].prev);

    dump(list);
}

void insert_head_elem(List* list, list_elem_tipe new_elem)
{
    assert(list != NULL);

    insert_middle_elem(list, new_elem, 0);

    dump(list);
}

void erase_middle_elem(List* list, int64_t index_elem)// не проверенная
{
    assert(list != NULL);

    int64_t index_before_elem_to_del = list->node[index_elem].prev;
    int64_t index_after_elem_to_del = list->node[index_elem].next;
    list->node[index_before_elem_to_del].next = index_after_elem_to_del;
    list->node[index_after_elem_to_del].prev = index_before_elem_to_del;

    list->node[index_elem].next = list->free;
    list->free = index_elem;

    dump(list);
}

void erase_head_elem(List* list)// не проверенная
{
    assert(list != NULL);

    erase_middle_elem(list, list->node[0].next);

    dump(list);
}

void erase_tail_elem(List* list)// не проверенная
{
    assert(list != NULL);

    erase_middle_elem(list, list->node[0].prev);

    dump(list);
}

int64_t ix_next_elem(List* list, int64_t index_elem)// не проверенная
{
    return list->node[index_elem].next;
}

int64_t ix_last_elem(List* list, int64_t index_elem)// не проверенная
{
    return list->node[index_elem].prev;
}

list_elem_tipe element(List* list, int64_t index_elem)// не проверенная
{
    return list->node[index_elem].elem;
}

void modify_elem(List* list, list_elem_tipe new_elem, int64_t index_elem)// не проверенная
{
    list->node[index_elem].elem = new_elem;

    dump(list);
}