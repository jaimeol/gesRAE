/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.hpp"

void	display_list(building buildings[])
{
	system ("clear");
	char option;
	int i = 0;
	printf("Id    Nombre    Aptos Básicos    Aptos Normales    Aptos de Lujo\n");
	while (i < 5)
	{
		if (buildings[i].id == i + 1)
		{
			printf("%d     %s", buildings[i].id, buildings[i].name);
			print_name_spaces(buildings, i);
			printf("%d", buildings[i].basic);
			print_basic_spaces(buildings[i].basic);
			printf("%d", buildings[i].normal);
			print_normal_spaces(buildings[i].normal);
			printf("%d\n", buildings[i].luxury);
		}
		i++;
	}
	printf("Son correctos los datos?(S/N) ");
	scanf(" %c", &option);
	if (option == 'N')
	{
		printf ("Redirigiendo al editor de edifcios\n");
		sleep(1);
		printf ("Por favor introduce los datos correctos\n");
		sleep(1);
		edit_building(buildings);
	}
}
