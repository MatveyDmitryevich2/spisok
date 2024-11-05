#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <assert.h>
#include <stdint.h>
#include <math.h>


#include "list.h"
#include "dump_file.h"

int main()
{
    Info_list list = {};
    list_ctor(&list);

    new_head_elem(&list, 25);
    new_head_elem(&list, -7);
    new_head_elem(&list, 40);
    new_tail_elem(&list, -1);
    new_tail_elem(&list, 87);
    new_head_elem(&list, 333);
    new_middle_elem(&list, 250, 4);
    new_tail_elem(&list, -1);



    dump(&list);

    list_dtor(&list);

    return 0;
}