/*
** EPITECH PROJECT, 2023
** transfer
** File description:
** polytechnical polynomials
*/

#include "error_handling.h"
#include "transfer.h"
#include <stdlib.h>
#include <string.h>

static vector_t *get_val_list(char *values)
{
    vector_t *val_list = malloc(sizeof(vector_t));
    int size = (int)strlen(values);
    char *token;
    int i = 0;

    if (!val_list || values[0] == '*' || values[size - 1] == '*')
        exit(ERROR);
    token = strtok(values, "*");
    val_list->values = malloc(sizeof(double) * (size / 2 + 1));
    if (!val_list->values)
        exit(ERROR);
    do {
        val_list->values[i] = strtod(token, NULL);
        i++;
    } while ((token = strtok(NULL, "*")) != NULL);
    val_list->len = i;
    return val_list;
}

static void process_transfer(int ac, char **av)
{
    vector_t **values = malloc(sizeof(double*) * (ac - 1));

    if (!values)
        exit(ERROR);
    for (int i = 1; i < ac; i++)
        values[i - 1] = get_val_list(av[i]);
    calc_sequence(values, ac - 1);
}

int transfer(int ac, char **av)
{
    process_transfer(ac, av);
    return SUCCESS;
}
