/*
** EPITECH PROJECT, 2023
** error_handling
** File description:
** verifies the arguments validity
*/

#include "error_handling.h"

static int is_correct_char(char c)
{
    char correct[] = {'0', '1', '2', '3', '4', '5', '6',
                        '7', '8', '9', '*', '-', '.', '\0'};

    for (int i = 0; correct[i] != '\0'; i++) {
        if (c == correct[i])
            return 1;
    }
    return 0;
}

static int parse_string(char **av, int i)
{
    for (int j = 0; av[i][j]; j++) {
        if (!is_correct_char(av[i][j]))
            return ERROR;
    }
    return SUCCESS;
}

int are_parameters_correct(int ac, char **av)
{
    if (ac == 1 || !(ac % 2))
        return 0;
    for (int i = 1; av[i]; i++) {
        if (parse_string(av, i) == ERROR)
            return 0;
    }
    return 1;
}
