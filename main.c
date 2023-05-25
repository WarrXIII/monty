#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token = NULL;
    int line_number = 0;
    stack_t *head = NULL;

    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        line_number++;
        token = get_tokens(line, line_number);
        if (token != NULL)
            get_func(token, &head, line_number);
    }

    fclose(fp);
    free_stack(head);

    return 0;
}

