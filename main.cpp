#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <assert.h>
#include <stdint.h>
#include <math.h>


#include "list.h"
#include "dump_file.h"
#include "write_html.h"

int main()
{
    write_before_body();
    write_body();
    
    List list = {};
    list_ctor(&list);

    insert_head_elem(&list, 25);
    insert_head_elem(&list, -7);
    insert_head_elem(&list, 40);
    insert_tail_elem(&list, -1);
    insert_tail_elem(&list, 87);
    insert_head_elem(&list, 333);
    insert_middle_elem(&list, 250, 4);



    
    dump(&list);
    write_body();
    write_html();

    list_dtor(&list);

    return 0;
}