#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <assert.h>
#include <stdint.h>
#include <math.h>


#include "list.h"

void list_ctor(Info_list* list)
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

void list_dtor(Info_list* list)
{
    assert(list != NULL);

    free(list->node);
    list = NULL;
}

void new_middle_elem(Info_list* list, spisok_elem_tipe new_elem, int64_t index_elem)
{
    assert(list != NULL);

    int64_t old_next = list->node[index_elem].next;
    int64_t new_free = list->node[list->free].next;

    list->node[list->free].list = new_elem;
    
    list->node[index_elem].next = list->free;
    list->node[list->free].prev = index_elem;
    list->node[list->free].next = old_next;
    list->node[old_next].prev = list->free;
    
    list->free = new_free;
}

void new_tail_elem(Info_list* list, spisok_elem_tipe new_elem)
{
    assert(list != NULL);

    new_middle_elem(list, new_elem, list->node[0].prev);
}

void new_head_elem(Info_list* list, spisok_elem_tipe new_elem)
{
    assert(list != NULL);

    new_middle_elem(list, new_elem, 0);
}

void erase_middle_elem(Info_list* list, int64_t index_elem)// не проверенная
{
    assert(list != NULL);

    int64_t index_before_elem_to_del = list->node[index_elem].prev;
    int64_t index_after_elem_to_del = list->node[index_elem].next;
    list->node[index_before_elem_to_del].next = index_after_elem_to_del;
    list->node[index_after_elem_to_del].prev = index_before_elem_to_del;

    list->node[index_elem].next = list->free;
    list->free = index_elem;
}

void erase_head_elem(Info_list* list)// не проверенная
{
    assert(list != NULL);

    erase_middle_elem(list, list->node[0].next);
}

void erase_tail_elem(Info_list* list)// не проверенная
{
    assert(list != NULL);

    erase_middle_elem(list, list->node[0].prev);
}

int64_t ix_next_elem(Info_list* list, int64_t index_elem)// не проверенная
{
    return list->node[index_elem].next;
}

int64_t ix_last_elem(Info_list* list, int64_t index_elem)// не проверенная
{
    return list->node[index_elem].prev;
}

spisok_elem_tipe element(Info_list* list, int64_t index_elem)// не проверенная
{
    return list->node[index_elem].list;
}

void modify_elem(Info_list* list, spisok_elem_tipe new_elem, int64_t index_elem)// не проверенная
{
    list->node[index_elem].list = new_elem;
}

void dump(Info_list* list)
{
    for (int64_t i = 0; i < SIZE_LIST; i++) { fprintf(stderr, "%-7ld", i); }
    fprintf(stderr, "\n");
    fprintf(stderr, "\n");

    for (int64_t i = 0; i < SIZE_LIST; i++) { fprintf(stderr, "%-6ld ", list->node[i].list); }
    fprintf(stderr, "\n");

    for (int64_t i = 0; i < SIZE_LIST; i++) { fprintf(stderr, "%-6ld ", list->node[i].next); }
    fprintf(stderr, "\n");
    
    for (int64_t i = 0; i < SIZE_LIST; i++) { fprintf(stderr, "%-6ld ", list->node[i].prev); }
    fprintf(stderr, "\n");

    fprintf(stderr, "\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "--------------------------------------\n");

    fprintf(stderr, "--------------------------------------\n");
}