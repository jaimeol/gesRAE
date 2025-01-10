/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

int	zeller_algo(int day, int month, int year)
{
	int a, m, y, res;

	a = (14 - month) / 12;
	y = year - a;
	m = month + (12 * a) - 2;
	res = ((day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12) - day) % 7);
	return (res);
}

void print_first_points(int &pipe, int &line_chars, int &total_digits, int &new_line, int month, int year)
{
	for (int first_day = zeller_algo(1, month, year); first_day >= 1; first_day--)
	{
		printf("\t  ");
		if (pipe % 8 == 0)
		{
			printf(" . ");
			printf ("| ");
			pipe = 1;
		}
		else
			printf(" .  ");
		pipe++;
		new_line++;
		total_digits++;
		line_chars++;
	}
}