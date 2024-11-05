#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "list.h"
#include "dump_file.h"

void dump(Info_list* list)
{
    FILE* file_dump = fopen("graph.dot", "w");

    fprintf(file_dump, "\n");
    fprintf(file_dump, "    digraph structs {\n");
    fprintf(file_dump, "    harset = \"UTF-8\";\n");
    fprintf(file_dump, "    rankdir=TB;\n");
    fprintf(file_dump, "    bgcolor = \"#0000aa\";\n");
    fprintf(file_dump, "    fontcolor = black;\n");
    fprintf(file_dump, "    fontsize = 18;\n");
    fprintf(file_dump, "    style = \"rounded\";\n");
    fprintf(file_dump, "    margin = 0.3;\n");
    fprintf(file_dump, "    splines = ortho;\n");
    fprintf(file_dump, "    ranksep = 1.0;\n");
    fprintf(file_dump, "    nodesep = 0.9;\n");
    fprintf(file_dump, "    bgcolor = \"#BFBA30\";\n");

    fprintf(file_dump, "    edge [color=\"#A600A6\", style=rounded, penwidth=2];\n");

    for (size_t i = 0; i < SIZE_LIST; i++)
    {
        fprintf(file_dump,"    node%lu [shape=record, style=rounded, label = \"{ip: %lu|<f1> data: %ld | <f2> next: %ld | <f3> prev: %ld}\"];\n", i, i,
        list->node[i].list,
        list->node[i].next, list->node[i].prev);
    }

    fprintf(file_dump, "\n");

    for (size_t i = 0; i < SIZE_LIST - 1; i++)
    {
        fprintf(file_dump, "    node%lu:f2 -> node%ld:f1 [tailport=e, headport=w];\n", i, list->node[i].next);
    }

    fprintf(file_dump, "    free [shape = record, label =\"free\n->\nnodes%ld\", style = rounded];\n", list->free);
    fprintf(file_dump, "    free -> node%ld [tailport=e, headport=w];\n", list->free);

    fprintf(file_dump, "    { rank = same; node0; node1; node2; node3; node4; node5; node6; node7; node8; node9; free;}\n");

    fprintf(file_dump, "}\n");
    fclose(file_dump);
}