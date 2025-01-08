/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

static void check_actions(char action, building buildings[])
{
	if (action == 'E')
		edit_building(buildings);
	else if (action == 'L')
		display_list(buildings);
	else if (action == 'A')
		display_available(buildings);
	else if (action == 'R')
		do_reservation(buildings);
	else if (action == 'S')
		exit (0);
}

int main()
{
	building buildings[5];
	init_data(buildings);
	while (1)
	{
		system ("clear");
		char action;
		printf("¿Que acción desea realizar?\n");
		printf("  Editar edificio(E)\n");
		printf("  Listar edificios(L)\n");
		printf("  Apartamentos disponibles(A)\n");
		printf("  Reservar Apartamento(R)\n");
		printf("  Reservas Mensuales Apartamento(M)\n");
		printf("  Salir(S)\n");
		scanf("%c", &action);
		check_actions(action, buildings);
	}
}