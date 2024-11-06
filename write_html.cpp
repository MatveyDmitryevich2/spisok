#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <assert.h>
#include <stdint.h>
#include <math.h>


#include "write_html.h"

void write_before_body()
{
    FILE* html_file = fopen("dump.html", "a+");
    fprintf(html_file, "<!DOCTYPE html>\n<html lang=\"en\">\n\n<head>\n<meta charset=\"utf-8\">\n"
                       "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
                       "<title>list dump</title>\n<link rel=\"stylesheet\" href=\"styles.css\">\n</head>\n\n");
    fclose(html_file);
}

void write_body()
{
    FILE* html_file = fopen("dump.html", "a+");
    fprintf(html_file, "<body>\n");

    fclose(html_file);
}

void write_html()
{
    FILE* html_file = fopen("dump.html", "a+");
    fprintf(html_file, "</html>\n");
    
    fclose(html_file);
}