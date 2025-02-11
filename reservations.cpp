/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

static int res_i = 0;

static void cancel_reservation(TypeReserv res, int res_i)
{
	res[res_i].number = 0;
	res[res_i].entry_day = 0;
	res[res_i].entry_month = 0;
	res[res_i].entry_year = 0;
	res[res_i].length = 0;
	res[res_i].exit_day = 0;
	res[res_i].exit_month = 0;
	res[res_i].exit_year = 0;
	res[res_i].apartment_type = -1;
	strcpy(res[res_i].ref, "");
}

void do_reservation(TypeBuilding buildings)
{
 	char apartment_type, action;
	int id, entry_day, entry_month, entry_year, length, stage;
	stage = 0;
	system("clear");
	printf("Reservar Apartamento:\n");
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
				if (buildings[id].id == -1)
				{
					printf ("Edificio no disponible, por favor introduzca un edificio valido\n");
					continue;
				}
				stage++;
				break;
			case 1:
				printf("  Tipo de apartamento (B-Basico/N-Normal/L-Lujo): ");
				scanf(" %c", &apartment_type);
				if (check_correct_type(apartment_type) == 1)
				{
					continue;
				}
				assign_apartment_type(buildings, apartment_type, id - 1, res_i);
				stage++;
				break;
			case 2:
				printf("  Dia de entrada: ");
				scanf("%d", &entry_day);
				if (entry_day < 1 || entry_day > 31)
				{
					printf ("\033[31mError\033[0m: Dia de entrada fuera de limites, por favor vuelva a introducirlo\n");
					continue;
				}
				stage++;
				break;
			case 3:
				printf("  Mes de entrada: ");
				scanf("%d", &entry_month);
				if (entry_month < 1 || entry_month > 12)
				{
					printf ("\033[31mError\033[0m: Mes de entrada fuera de limites, por favor vuelva a introducirlo\n");
					continue;
				}
				stage++;
				break;
			case 4:
				printf("  Año de entrada: ");
				scanf("%d", &entry_year);
				if (entry_year < 1601 || entry_year > 3000)
				{
					printf ("\033[31mError\033[0m: Año de entrada fuera de limites, por favor vuelva a introducirlo\n");
					continue;
				}
				if (check_possible_date(entry_day, entry_month, entry_year) == 1)
				{
				  stage = 2;
				  continue;
				}
				stage++;
				break;
			case 5:
				printf("  Longitud de la estancia: ");
				scanf("%d", &length);
				stage++;
				break;
      case 6:
				buildings[id - 1].reservations[res_i].number = assign_res_number(buildings, entry_year, id - 1);
				buildings[id - 1].reservations[res_i].entry_month = entry_month;
				buildings[id - 1].reservations[res_i].entry_day = entry_day;
				buildings[id - 1].reservations[res_i].entry_year = entry_year;
				buildings[id - 1].reservations[res_i].length = length;
				get_exit_date(buildings[id - 1].reservations, res_i);
				printf("      Datos de la Reserva:\n");
				print_reservation_number(buildings[id - 1].reservations, res_i);
				assign_reserv_ref(buildings, id - 1, apartment_type, res_i);
				printf("  Edificio: %s (Id = %d)\n", buildings[id - 1].name, id);
				printf("  Referencia apartamento: %s\n", buildings[id - 1].reservations[res_i].ref);
				printf("  Fecha entrada: %d/%d/%d\n", entry_day, entry_month, entry_year);
				printf("  Duracion de estancia: %d dias\n", length);
				printf("  Fecha salida: %d/%d/%d\n", buildings[id - 1].reservations[res_i].exit_day,
				buildings[id - 1].reservations[res_i].exit_month, buildings[id - 1].reservations[res_i].exit_year);
				printf("Es correcta la operacion(S/N)? ");
				scanf(" %c", &action);
				if (action == 'S')
				{
				  system("clear");
				  printf("Realizando reserva\n");
				  res_i++;
				  sleep(1);
				  return ;
				}
				else
				{
					printf("Reserva cancelada\n");
					cancel_reservation(buildings[id - 1].reservations, res_i);
					sleep(1);
					return ;
				}
				break ;
		}
	}
}

void get_exit_date(TypeReserv res, int i)
{
	int total_days = month_days(res[i].entry_month, res[i].entry_year);
	int aux_entry_month = res[i].entry_month;
	int aux_entry_year = res[i].entry_year;
  	res[i].exit_day = res[i].entry_day + res[i].length;

	while (res[i].exit_day > total_days)
	{
		res[i].exit_day = res[i].exit_day - total_days;
		aux_entry_month++;
		if (aux_entry_month > 12)
		{
			aux_entry_month = 1;
			aux_entry_year++;
		}
		total_days = month_days(aux_entry_month, aux_entry_year);
	}
	res[i].exit_month = aux_entry_month;
	res[i].exit_year = aux_entry_year;
}
