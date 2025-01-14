/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

static int	zeller_algo(int day, int month, int year)
{
	int a, m, y, res;
	a = (14 - month) / 12;
	y = year - a;
	m = month + (12 * a) - 2;
	res = ((day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12) - day)
			% 7);
	return (res);
}

void CalendarioMes::print_first_points(int month, int year)
{
	for (int first_day = zeller_algo(1, month, year); first_day >= 1; first_day--)
	{
		if (data.line_chars == 0)
		{
			printf("\t  ");
		}
		if (data.pipe % 8 == 0)
		{
			printf(" . ");
			printf("| ");
			data.pipe = 1;
		}
		else
		{
			printf(" .  ");
		}
		data.pipe++;
		data.new_line++;
		data.total_digits++;
		data.line_chars++;
	}
}

void	CalendarioMes::print_numbers(TypeBuilding buildings, int id, int month, int year)
{
	bool reserved;
	int	entry_year, entry_month, entry_day;
	int	exit_year, exit_month, exit_day;
	int i;

	for (int day = 1; day <= data.days_num; day++)
	{
	  	i = 0;
		reserved = false;
		while (data.indexes[i] != -1)
		{
			entry_year = buildings[id].reservations[data.indexes[i]].entry_year;
			exit_year = buildings[id].reservations[data.indexes[i]].exit_year;
			entry_month = buildings[id].reservations[data.indexes[i]].entry_month;
			exit_month = buildings[id].reservations[data.indexes[i]].exit_month;
			entry_day = buildings[id].reservations[data.indexes[i]].entry_day;
			exit_day = buildings[id].reservations[data.indexes[i]].exit_day;
			if ((entry_year < year || (entry_year == year
						&& entry_month < month) || (entry_year == year
						&& entry_month == month && entry_day <= day))
				&& (exit_year > year || (exit_year == year
						&& exit_month > month) || (exit_year == year
						&& exit_month == month && exit_day >= day)))
			{
				reserved = true;
			}
			i++;
		}
		if (data.line_chars == 0)
		{
			printf("\t  ");
		}
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
            data.free_days++;
		}
		if (data.pipe % 8 == 0 && day < 10)
		{
			printf("|");
			data.pipe = 1;
		}
		if (data.pipe % 8 == 0 && day >= 10)
		{
			printf("|");
			data.pipe = 1;
		}
		data.pipe++;
		printf(" ");
		data.line_chars++;
		if (data.new_line % 7 == 0)
		{
			printf("\n");
			data.line_chars = 0;
		}
		data.new_line++;
		data.total_digits++;
	}
}

void	CalendarioMes::print_last_points()
{
	if (data.line_chars != 0)
	{
		for (int i = data.line_chars; i < 7; i++)
		{
			if (data.pipe % 8 == 0)
			{
				printf(" .");
				printf(" | ");
				data.pipe = 1;
			}
			else if (i == 6)
			{
				printf(" .");
			}
			else
			{
				printf(" .  ");
			}
			data.pipe++;
			data.new_line++;
		}
	}
}

void CalendarioMes::get_res_indexes(TypeBuilding buildings, TypeRef ref, int id)
{
	int count = 0;
	for (int i = 0; i < 366; i++)
	{
		if (strcmp(buildings[id].reservations[i].ref, ref) == 0)
		{
    		data.indexes[count] = i;
    		count++;
		}
	}
}

void CalendarioMes::print_month_reservations(TypeBuilding buildings, int id, int month, int year)
{
	int	exit_year, exit_month;
	int	entry_year, entry_month, entry_day;
	int	number, length;

	data.reserved_days = data.days_num - data.free_days;
	for (int i = 0; data.indexes[i] != -1; i++)
	{
		entry_year = buildings[id].reservations[data.indexes[i]].entry_year;
		exit_year = buildings[id].reservations[data.indexes[i]].exit_year;
		entry_month = buildings[id].reservations[data.indexes[i]].entry_month;
		exit_month = buildings[id].reservations[data.indexes[i]].exit_month;
		entry_day = buildings[id].reservations[data.indexes[i]].entry_day;
		number = buildings[id].reservations[data.indexes[i]].number;
		length = buildings[id].reservations[data.indexes[i]].length;
		if ((entry_year == year || exit_year == year) 
			&& (entry_month <= month && exit_month >= month))
		{
			if (number < 10)
			{
				printf("Reserva 0%d/%d: Fecha entrada %d/%d/%d y de %d días\n", number, entry_year, entry_day, entry_month, entry_year, length);
			}
			else
			{
				printf("Reserva %d/%d: Fecha entrada %d/%d/%d y de %d días\n", number, entry_year, entry_day, entry_month, entry_year, length);
			}
		}
	}
	printf("Total días reservados del mes: %d días\n", data.reserved_days);
	printf("Total días libres del mes: %d días\n", data.free_days);
}

void CalendarioMes::init_data(int month, int year)
{
	data.free_days = 0;
	data.days_num = month_days(month, year);
	data.pipe = 4;
	data.line_chars = 0;
	data.new_line = 1;
	data.total_digits = 1;
	for (int i = 0; i < 366; i++)
	{
		data.indexes[i] = -1;
	}
}
