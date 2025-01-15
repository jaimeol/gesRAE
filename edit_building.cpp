/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

void edit_building(TypeBuilding buildings)
{
	TypeName name;
	char option;
	int	id, basic, normal, luxury, stage;
	stage = 0;
	system ("clear");
	while (1)
	{
		switch (stage)
		{
			case 0:
				printf(" Editar Edificio:\n");
				printf("  Identificador (Numero entre 1 y 5): ");
				scanf("%d", &id);
				if (check_correct_id(id) == 1)
				{
					continue;
				}
				buildings[id - 1].id = id;
				stage++;
				break;
			case 1:
				printf("  Nombre (Entre 1 y 20 caracteres): ");
				scanf ("%s", name);
				if (check_name_len(name) == 1)
				{
					continue;
				}
				strcpy(buildings[id - 1].name, name);
				stage++;
				break;
			case 2:
				printf("  Numero de apartamentos basicos: ");
				scanf("%d", &basic);
				buildings[id - 1].basic = basic;
				stage++;
				break;
			case 3:
				printf("  Numero de apartamentos normales: ");
				scanf("%d", &normal);
				buildings[id - 1].normal = normal;
				stage++;
				break ;
			case 4:
				printf("  Numero de apartamentos de lujo: ");
				scanf("%d", &luxury);
				buildings[id - 1].luxury = luxury;
				if (check_total_apartments(buildings, id - 1) == 1)
				{
					stage = 2;
					continue ;
				}
				else if (check_total_apartments(buildings, id - 1) == 2)
				{
					return ;
				}
				stage++;
				break ;
			case 5:
				printf(" \033[31mIMPORTANTE:\033[0m Esta opcion borra los datos anteriores.\nSon correctos los nuevos datos?(S/N) ");
				scanf(" %c", &option);
				if (option == 'N')
				{
					system("clear");
					printf("Por favor introduzca los datos correctos\n");
					sleep(1);
					stage = 0;
					continue;
				}
				else if (option == 'S')
				{
					system("clear");
					printf("Guardando informacion\n");
					sleep (1);
					return ;
				}
				else
				{
					printf("\033[31mInput incorrecto\033[0m\n");
					printf("Por favor vuelva a introducir si los datos son correctos\n");
				}
				break;
		}
	}
}
