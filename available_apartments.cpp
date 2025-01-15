/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

static void check_available(TypeBuilding buildings, int id, int entry_day, int entry_month, int entry_year, int length)
{
	int basic_available = buildings[id - 1].basic;
	int normal_available = buildings[id - 1].normal;
	int luxury_available = buildings[id - 1].luxury;
	int i = 0;

	while (i < 366)
	{
		if (buildings[id - 1].reservations[i].entry_year >= entry_year && buildings[id - 1].reservations[i].entry_month >= entry_month)
		{
			if ((buildings[id - 1].reservations[i].entry_day >= entry_day) && (buildings[id - 1].reservations[i].exit_day <= (entry_day + length)))
			{
				if (buildings[id - 1].reservations[i].apartment_type == 0)
				{
					basic_available--;
				}
				else if (buildings[id - 1].reservations[i].apartment_type == 1)
				{
					normal_available--;
				}
				else if (buildings[id - 1].reservations[i].apartment_type == 2)
				{
					luxury_available--;
				}
			}
		}
		i++;
	}
	printf("Disponibilidad en %s:\n", buildings[id - 1].name);
	printf("  %d apartamentos de tipo Básico\n", basic_available);
	printf("  %d apartamentos de tipo Normal\n", normal_available);
	printf("  %d apartamentos de tipo Lujo\n", luxury_available);
}


void display_available(TypeBuilding buildings)
{
	int id, entry_day, entry_month, entry_year, length;
	char option;
	int stage = 0;
	system("clear");
	printf("Apartamentos disponibles:\n");
	while (1)
	{
		switch (stage)
		{
			case 0:
				printf("  Identificador de edificio: ");
				scanf("%d", &id);
				if (check_correct_id(id) == 1)
				{
					continue;
				}
				stage++;
				break;
			case 1:
				printf("  Día de entrada: ");
				scanf("%d", &entry_day);
				if (entry_day < 1 || entry_day > 31)
				{
					printf("Dia de entrada fuera de límites\n");
					continue;
				}
				stage++;
				break;
			case 2:
				printf("  Mes de entrada: ");
				scanf("%d", &entry_month);
				if (entry_month < 1 || entry_month > 12)
				{
					printf("Mes de entrada fuera de límites, introduzca uno válido\n");
					continue;
				}
				stage++;
				break;
			case 3:
				printf("  Año de entrada: ");
				scanf("%d", &entry_year);
				if (entry_year < 1600 || entry_year > 3000)
				{
					printf("\033[31mError\033[0m: Año fuera de límites, introduzca uno válido\n");
					continue;
				}
				if (check_possible_date(entry_day, entry_month, entry_year) == 1)
				{
					stage = 1;
					continue;
				}
				stage++;
				break;
			case 4:
				printf("  Duración de estancia (Dias): ");
				scanf("%d", &length);
				if (length < 1)
				{
					printf("\033[31mError\033[0m: Longitud inválida, introduzca una válida\n");
					continue;
				}
				stage++;
				break;
			case 5:
				printf("El edificio %s desde el %d/%d/%d y de %d días de estancia, tendría disponibles:\n", buildings[id - 1].name, entry_day, entry_month, entry_year, length);
				check_available(buildings, id, entry_day, entry_month, entry_year, length);
				printf("¿Desea volver al menú principal?(S/N) ");
				scanf(" %c", &option);
				if (option == 'S')
				{
					return ;
				}
				break;
		}
	}
}
