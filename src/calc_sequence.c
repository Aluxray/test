/*
** EPITECH PROJECT, 2023
** calc_sequence
** File description:
** calculs the sequence of the polynomial coefficients
*/

#include "transfer.h"
#include "error_handling.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

static double calc_next_term(vector_t *num_list, vector_t *den_list,
                            double next_coeff)
{
    double num_result = 0;
    double den_result = 0;
    double total = 0;

    for (int i = 0; i < num_list->len; i++)
        num_result += num_list->values[i] * pow(next_coeff, i);
    for (int i = 0; i < den_list->len; i++)
        den_result += den_list->values[i] * pow(next_coeff, i);
    if (!den_result)
        exit(ERROR);
    total = num_result / den_result;
    return total;
}

static void display_result(double i, double result)
{
    printf("%.3f -> %.5f\n", i, result);
}

void calc_sequence(vector_t **values, int nb_values)
{
    double xn = 0;

    for (double i = 0.0; i < 1.001; i += 0.001) {
        xn = calc_next_term(values[0], values[1], i);
        for (int j = 2; j < nb_values; j += 2)
            xn *= calc_next_term(values[j], values[j + 1], i);
        display_result(i, xn);
    }
}
