/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

void	print_name_spaces(TypeBuilding buildings, int i)
{
	int	space_num;
	int	j;

	space_num = 16 - strlen(buildings[i].name);
	j = 0;
	while (j < space_num)
	{
		printf(" ");
		j++;
	}
}

void	print_basic_spaces(int num)
{
	int	space_num;
	int	i;

	i = 0;
	if (num > 10)
	{
		space_num = 15;
	}
	else
	{
		space_num = 16;
	}
	while (i < space_num)
	{
		printf(" ");
		i++;
	}
}

void	print_normal_spaces(int num)
{
	int	space_num;
	int	i;

	i = 0;
	if (num > 10)
	{
		space_num = 16;
	}
	else
	{
		space_num = 17;
	}
	while (i < space_num)
	{
		printf(" ");
		i++;
	}
}

void	print_reservation_number(TypeReserv res, int i)
{
	if (res[i].number < 10)
	{
		printf("  Numero de reserva: 0%d/%d\n", res[i].number,
			res[i].entry_year);
	}
	else
	{
		printf("  Numero de reserva: %d/%d\n", res[i].number,
			res[i].entry_year);
	}
}

void	assign_reserv_ref(TypeBuilding buildings, int id, char apartment_type,
		int res_i)
{
	TypeRef	aux_ref;

	int number = 1;
	aux_ref[0] = 'A';
	aux_ref[1] = 'P';
	aux_ref[2] = 'T';
	aux_ref[3] = '0';
	aux_ref[4] = '0' + (id + 1 % 10);
	if (apartment_type == 'B')
	{
		aux_ref[5] = 'B';
	}
	else if (apartment_type == 'N')
	{
		aux_ref[5] = 'N';
	}
	else if (apartment_type == 'L')
	{
		aux_ref[5] = 'L';
	}
	for (int i = 0; i < 366; i++)
	{
		if (i != res_i)
		{
			if ((buildings[id].reservations[res_i].entry_year == buildings[id].reservations[i].entry_year
					|| buildings[id].reservations[res_i].exit_year == buildings[id].reservations[i].exit_year)
				&& (buildings[id].reservations[res_i].entry_month == buildings[id].reservations[i].entry_month
					|| buildings[id].reservations[res_i].exit_month == buildings[id].reservations[i].exit_month))
			{
				if ((buildings[id].reservations[res_i].entry_day >= buildings[id].reservations[i].entry_day
						&& buildings[id].reservations[res_i].entry_day <= buildings[id].reservations[i].exit_day)
					|| (buildings[id].reservations[res_i].exit_day >= buildings[id].reservations[i].entry_day
						&& buildings[id].reservations[res_i].exit_day <= buildings[id].reservations[i].exit_day))
				{
					number++;
				}
			}
		}
	}
	aux_ref[6] = '0' + (number / 10);
	aux_ref[7] = '0' + (number % 10);
	strcpy(buildings[id].reservations[res_i].ref, aux_ref);
}

void	assign_apartment_type(TypeBuilding buildings, char type, int id,
		int res_i)
{
	if (type == 'B')
	{
		buildings[id].reservations[res_i].apartment_type = 0;
	}
	else if (type == 'N')
	{
		buildings[id].reservations[res_i].apartment_type = 1;
	}
	else if (type == 'L')
	{
		buildings[id].reservations[res_i].apartment_type = 2;
	}
}

int	check_reference(TypeBuilding buildings, TypeRef ref)
{
	int i, j;
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 366)
		{
			if (strcmp(buildings[i].reservations[j].ref, ref) == 0)
			{
				return (1);
			}
		}
	}
	printf("Referencia de apartamento no encontrada por favor introduzca una válida\n");
	return (0);
}

int	assign_res_number(TypeBuilding buildings, int entry_year, int id)
{
	int i, number;
	i = 0;
	number = 1;
	while (i < 366)
	{
		if (entry_year == buildings[id].reservations[i].entry_year)
			number++;
		i++;
	}
	return (number);
}
