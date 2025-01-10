/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

bool leap_year(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int	month_days(int month, int year)
{

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return (31);
	else if (month == 2)
	{
		if (leap_year(year) == 1)
		{
			return (29);
		}
		else
		{
			return (28);
		}
	}
	else
		return (30);
}

void	print_date_format(int month)
{
	switch (month)
	{
		case 1:
			printf("ENERO");
		for (int x = 1; x < 19; x++)
		{
			printf(" ");
		}
		break ;
		case 2:
			printf("FEBRERO");
		for (int x = 1; x < 17; x++)
		{
			printf(" ");
		}
		break ;
		case 3:
			printf("MARZO");
		for (int x = 1; x < 19; x++)
		{
			printf(" ");
		}
		break ;
		case 4:
			printf("ABRIL");
		for (int x = 1; x < 19; x++)
		{
			printf(" ");
		}
		break ;
		case 5:
			printf("MAYO");
		for (int x = 1; x < 20; x++)
		{
			printf(" ");
		}
		break ;
		case 6:
			printf("JUNIO");
		for (int x = 1; x < 19; x++)
		{
			printf(" ");
		}
		break ;
		case 7:
			printf("JULIO");
		for (int x = 1; x < 19; x++)
		{
			printf(" ");
		}
		break ;
		case 8:
			printf("AGOSTO");
		for (int x = 1; x < 18; x++)
		{
			printf(" ");
		}
		break ;
		case 9:
			printf("SEPTIEMBRE");
		for (int x = 1; x < 14; x++)
		{
			printf(" ");
		}
		break ;
		case 10:
			printf("OCTUBRE");
		for (int x = 1; x < 17; x++)
		{
			printf(" ");
		}
		break ;
		case 11:
			printf("NOVIEMBRE");
		for (int x = 1; x < 15; x++)
		{
			printf(" ");
		}
		break ;
		case 12:
			printf("DICIEMBRE");
		for (int x = 1; x < 15; x++)
		{
			printf(" ");
		}
		break ;
	}
}

static void	print_calendar(TypeBuilding buildings,TypeRef ref , int month, int year)
{
	int days_num, final_day, pipe, new_line, total_digits, line_chars;
	printf("\t  ");
	print_date_format(month);
	printf("%-1d\n", year);
	printf("\t  ===========================\n");
	printf("\t  LU  MA  MI  JU  VI | SA  DO\n");
	printf("\t  ===========================\n");
	days_num = month_days(month, year);
	pipe = 4;
	line_chars = 0;
	new_line = 1;
	total_digits = 1;
	print_first_points(pipe, line_chars, total_digits, new_line, month, year);
	for (int day = 1; day <= days_num; day++)
	{
		if (line_chars == 0)
			printf("\t  ");
		if (day < 10)
		{
			printf (" ");
		}
		if (day < 10 && new_line == 1 && line_chars != 0)
		{
			printf (" %i ", day);
		}
		else
			printf ("%i ", day);
		if (pipe % 8 == 0 && day < 10)
		{
			printf ("|");
			pipe = 1;
		}
		if (pipe % 8 == 0 && day >= 10)
		{
			printf ("|");
			pipe = 1;
		}
		pipe++;
		printf (" ");
		line_chars++;
		if (new_line % 7 == 0)
		{
			printf("\n");
			line_chars = 0;
		}
		new_line++;
		total_digits++;
	}
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
	printf("\n");
}

void	monthly_reservations(TypeBuilding buildings)
{
	int stage, month, year, id;
	char action;
	TypeRef ref;

	stage = 3;
	system("clear");
	printf("Reservas mensuales apartamento:\n");
	while (1)
	{
		switch (stage)
		{
			case 0:
				printf("Referencia apartamento? ");
				scanf (" %s", ref);
				id = check_reference(buildings, ref);
				if (id == -1)
				{
					continue;
				}
				stage++;
				break;
			case 1:
				printf("Selección mes? ");
				scanf ("%d", &month);
				if (month < 1 || month > 12)
				{
					printf ("Mes no válido\n");
					continue;
				}
				stage++;
				break;
			case 2:
				printf("Selección año? ");
				scanf("%d", &year);
				if (year < 1600 || year > 3000)
				{
					printf("Año no válido\n");
					continue;
				}
				stage++;
				break;
			case 3:
				printf("\tEstado Mensual Apartamento: %s\n", "APT01B01");
				printf("\t\tEdificio: %s\n", "Apolo");
				print_calendar(buildings, "APT01B01", 2, 2011);
				while (1);
		}
	}
}