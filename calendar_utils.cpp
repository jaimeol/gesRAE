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
	res = ((day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12) - day)
			% 7);
	return (res);
}

void	print_first_points(int &pipe, int &line_chars, int &total_digits,
		int &new_line, int month, int year)
{
	for (int first_day = zeller_algo(1, month,
			year); first_day >= 1; first_day--)
	{
		if (line_chars == 0)
		{
			printf("\t  ");
		}
		if (pipe % 8 == 0)
		{
			printf(" . ");
			printf("| ");
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

int	print_numbers(TypeBuilding buildings, int id, TypeArray indexes, int month, int year, int days_num, int &pipe, int &line_chars, int &new_line, int &total_digits)
{
	bool reserved;
    int count;
	int	entry_year, entry_month, entry_day;
	int	exit_year, exit_month, exit_day;

    count = 0;
	for (int day = 1; day <= days_num; day++)
	{
		reserved = false;
		for (int i = 0; indexes[i] != -1; i++)
		{
			entry_year = buildings[id].reservations[indexes[i]].entry_year;
			exit_year = buildings[id].reservations[indexes[i]].exit_year;
			entry_month = buildings[id].reservations[indexes[i]].entry_month;
			exit_month = buildings[id].reservations[indexes[i]].exit_month;
			entry_day = buildings[id].reservations[indexes[i]].entry_day;
			exit_day = buildings[id].reservations[indexes[i]].exit_day;
			if ((entry_year < year || (entry_year == year
						&& entry_month < month) || (entry_year == year
						&& entry_month == month && entry_day <= day))
				&& (exit_year > year || (exit_year == year
						&& exit_month > month) || (exit_year == year
						&& exit_month == month && exit_day >= day)))
			{
				reserved = true;
			}
		}
		if (line_chars == 0)
			printf("\t  ");
		if (day < 10 && !reserved)
		{
			printf(" ");
		}
		if (reserved)
		{
			printf("\033[31mRe\033[0m ");
		}
		else
		{
			printf("\033[32m%d\033[0m ", day);
            count++;
		}
		if (pipe % 8 == 0 && day < 10)
		{
			printf("|");
			pipe = 1;
		}
		if (pipe % 8 == 0 && day >= 10)
		{
			printf("|");
			pipe = 1;
		}
		pipe++;
		printf(" ");
		line_chars++;
		if (new_line % 7 == 0)
		{
			printf("\n");
			line_chars = 0;
		}
		new_line++;
		total_digits++;
	}
    return (count);
}

void	print_last_points(int line_chars, int pipe, int new_line)
{
	if (line_chars != 0)
	{
		for (int i = line_chars; i < 7; i++)
		{
			if (pipe % 8 == 0)
			{
				printf(" .");
				printf(" | ");
				pipe = 1;
			}
			else if (i == 6)
			{
				printf(" .");
			}
			else
			{
				printf(" .  ");
			}
			pipe++;
			new_line++;
		}
	}
}
