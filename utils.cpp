/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

int	get_id(TypeBuilding buildings, TypeRef ref)
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
				return (i);
			}
			j++;
		}
		i++;
	}
	printf("\033[31mError\033[0m: Referencia de apartamento no encontrada por favor introduzca una valida\n");
	return (-1);
}

int	assign_res_number(TypeBuilding buildings, int entry_year, int id)
{
	int i, number;
	i = 0;
	number = 1;
	while (i < 366)
	{
		if (entry_year == buildings[id].reservations[i].entry_year)
		{
			number++;
		}
		i++;
	}
	return (number);
}
