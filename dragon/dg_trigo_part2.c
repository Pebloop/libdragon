/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** maths functions : trigonometry
*/

#include "dg_math.h"

const double PI = 3.14159265359;

double dg_arccos(double x)
{
    return ((PI / 2) - dg_arcsin(x));
}

double dg_tan(double x)
{
	return (dg_sin(x) / dg_cos(x));
}