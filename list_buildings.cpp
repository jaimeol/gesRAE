/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

void	display_list(TypeBuilding buildings)
{
	char option;
	int i = 0;
	system ("clear");
	printf("Id    Nombre    Aptos Basicos    Aptos Normales    Aptos de Lujo\n");
	while (i < 5)
	{
		if (buildings[i].id == i + 1)
		{
			printf("%-5d %-12s %-16d %-16d %-16d\n", buildings[i].id, buildings[i].name, buildings[i].basic, buildings[i].normal, buildings[i].luxury);
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
