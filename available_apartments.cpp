/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.hpp"

static void check_available(building buildings[], int id, int entry_day, int entry_month, int entry_year, int length) {
    int basic_available = buildings[id - 1].basic_available;
    int normal_available = buildings[id - 1].normal_available;
    int luxury_available = buildings[id - 1].luxury_available;
    int i = 0;

    while (i < 366)
	{
        if (buildings[id - 1].reservations[i].entry_year == entry_year && 
            buildings[id - 1].reservations[i].entry_month == entry_month)
			{
            if ((buildings[id - 1].reservations[i].entry_day >= entry_day) && 
                (buildings[id - 1].reservations[i].exit_day <= (entry_day + length))) {
                if (buildings[id - 1].reservations[i].apartment_type == 'B')
				{
                    basic_available--;
				}
                else if (buildings[id - 1].reservations[i].apartment_type == 'N')
				{
                    normal_available--;
				}
                else if (buildings[id - 1].reservations[i].apartment_type == 'L')
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


void display_available(building buildings[])
{
	system("clear");
	int id, entry_day, entry_month, entry_year, length;
	char option;
	printf("Apartamentos disponibles:\n");
	printf("  Identificador de edificio: ");
	scanf("%d", &id);
	printf("  Día de entrada: ");
	scanf("%d", &entry_day);
	printf("  Mes de entrada: ");
	scanf("%d", &entry_month);
	printf("  Año de entrada: ");
	scanf("%d", &entry_year);
	printf("  Duración de estancia (Dias): ");
	scanf("%d", &length);
	printf("El edificio %s desde el %d/%d/%d y de %d días de estancia, tendría disponibles:\n", buildings[id - 1].name, entry_day, entry_month, entry_year, length);
	check_available(buildings, id, entry_day, entry_month, entry_year, length);
	printf("¿Es correcta la operación?(S/N) ");
	scanf(" %c", &option);
	if (option == 'S')
	{
		return ;
	}
}
