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
	{
		return (31);
	}
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
	{
		return (30);
	}
}

void	CalendarioMes::print_date_format(int month)
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

void CalendarioMes::print_calendar(TypeBuilding buildings, int id, TypeRef ref, int month, int year)
{
	get_res_indexes(buildings, ref, id);
	printf("\t  ");
	print_date_format(month);
	printf("%-1d\n", year);
	printf("\t  ===========================\n");
	printf("\t  LU  MA  MI  JU  VI | SA  DO\n");
	printf("\t  ===========================\n");
	data.free_days = 0;
	data.days_num = month_days(month, year);
	data.pipe = 4;
	data.line_chars = 0;
	data.new_line = 1;
	data.total_digits = 1;
	print_first_points(month, year);
	print_numbers(buildings, id, month, year);
	print_last_points();
	printf("\n");
	print_month_reservations(buildings, id, month, year);
}

void	monthly_reservations(TypeBuilding buildings)
{
	int stage, month, year, id;
	char action;
	TypeRef ref;
	CalendarioMes calendar;
	stage = 0;
	id = 0;
	system("clear");
	printf("Reservas mensuales apartamento:\n");
	while (1)
	{
		switch (stage)
		{
			case 0:
				printf("Referencia apartamento? ");
				scanf (" %s", ref);
				id = get_id(buildings, ref);
				if (id == -1)
				{
					continue;
				}
				stage++;
				break;
			case 1:
				printf("Seleccion mes? ");
				scanf ("%d", &month);
				if (month < 1 || month > 12)
				{
					printf ("Mes no valido\n");
					continue;
				}
				stage++;
				break;
			case 2:
				printf("Seleccion año? ");
				scanf("%d", &year);
				if (year < 1600 || year > 3000)
				{
					printf("Año no válido\n");
					continue;
				}
				stage++;
				break;
			case 3:
				printf("\tEstado Mensual Apartamento: %s\n", ref);
				printf("\t\tEdificio: %s\n", buildings[id].name);
				calendar.init_data(month, year);
				calendar.print_calendar(buildings, id, ref, month, year);
				stage++;
				break;
			case 4:
				printf("Mostrar otro mes? (S/N) ");
				scanf(" %c", &action);
				if (action == 'S')
				{
					monthly_reservations(buildings);
					return;
				}
				else if (action == 'N')
				{
					return;
				}
				else
				{
					printf("Acción no válida\n");
          continue;
				}
				break;
		}
	}
}
