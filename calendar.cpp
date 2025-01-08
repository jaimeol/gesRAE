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