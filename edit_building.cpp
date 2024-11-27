/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.hpp"

void edit_building(building buildings[])
{
	char name[20];
	char option;
	int	id, basic, normal, luxury, stage;
	stage = 0;
	system ("clear");
	while (1)
	{
		switch (stage)
		{
			case 0:
				printf("Editar Edificio:\n");
				printf("  Identificador (Número entre 1 y 5): ");
				scanf("%d", &id);
				if (check_correct_id(id) == 1)
					break ;
				buildings[id - 1].id = id;
				stage++;
				break;
			case 1:
				printf("  Nombre (Entre 1 y 20 caracteres): ");
				scanf ("%s", name);
				if (check_name_len(name) == 1)
					break ;
				strcpy(buildings[id - 1].name, name);
				stage++;
				break;
			case 2:
				printf("  Número de apartamentos básicos: ");
				scanf("%d", &basic);
				buildings[id - 1].basic = basic;
				buildings[id - 1].basic_available = basic;
				stage++;
				break;
			case 3:
				printf("  Número de apartamentos normales: ");
				scanf("%d", &normal);
				buildings[id - 1].normal = normal;
				buildings[id - 1].normal_available = normal;
				stage++;
				break ;
			case 4:
				printf("  Número de apartamentos de lujo: ");
				scanf("%d", &luxury);
				buildings[id - 1].luxury = luxury;
				buildings[id - 1].luxury_available = luxury;
				if (check_total_apartments(buildings, id - 1) == 1)
				{
					stage = 2;
					break ;
				}
				else if (check_total_apartments(buildings, id - 1) == 2)
				{
					printf("Aqui\n");
					return ;
				}
				stage++;
				break ;
			case 5:
				printf("\033[31mIMPORTANTE:\033[0m Esta opción borra los datos anteriores.\n¿Son correctos los nuevos datos?(S/N) ");
				scanf(" %c", &option);
				if (option == 'N')
				{
					system("clear");
					printf("Por favor introduzca los datos correctos\n");
					sleep(1);
					stage = 0;
					break;
				}
				else if (option == 'S')
				{
					system("clear");
					printf("Guardando información\n");
					sleep (1);
					return ;
				}
				else
				{
					printf("Input incorrecto\n");
					printf("Por favor vuelva a introducir si los datos son correctos\n");
				}
				break;
		}
	}
}