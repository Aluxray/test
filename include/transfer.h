/*
** EPITECH PROJECT, 2023
** transfer
** File description:
** prototypes transfer functions
*/

#ifndef TRANSFER_
    #define TRANSFER_

typedef struct vector_s {
    double *values;
    int len;
} vector_t;

int transfer(int ac, char **av);
void calc_sequence(vector_t **values, int nb_values);

#endif /* TRANSFER_ */
