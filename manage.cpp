/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

static void check_actions(char action, TypeBuilding buildings)
{
  switch (action)
  {
    case 'E':
      edit_building(buildings);
      break;
    case 'L':
      display_list(buildings);
      break;
    case 'A':
      display_available(buildings);
      break;
    case 'R':
      do_reservation(buildings);
      break;
    case 'M':
      monthly_reservations(buildings);
      break;
    case 'S':
      exit(0);
      break;
  }
}

int main()
{
	TypeBuilding buildings;
	char action;
	init_data(buildings);
	while (1)
	{
		system ("clear");
		printf("¿Que acción desea realizar?\n");
		printf("  Editar edificio(E)\n");
		printf("  Listar edificios(L)\n");
		printf("  Apartamentos disponibles(A)\n");
		printf("  Reservar Apartamento(R)\n");
		printf("  Reservas Mensuales Apartamento(M)\n");
		printf("  Salir(S)\n");
		printf("Teclear una opción válida (E|L|A|R|M|S)? ");
		scanf("%c", &action);
		check_actions(action, buildings);
	}
}
