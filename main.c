/*
** EPITECH PROJECT, 2023
** main
** File description:
** transfer main function
*/

#include "transfer.h"
#include "error_handling.h"

int main(int ac, char **av)
{
    if (!are_parameters_correct(ac, av))
        return ERROR;
    return transfer(ac, av);
}
