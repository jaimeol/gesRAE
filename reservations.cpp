/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.hpp"

static int res_i = 0;

void do_reservation(building buildings[], int id, int entry_day, int entry_month, int entry_year, int length)
{
	int exit_day, exit_month, exit_year;
	char apartment_type;

	system("clear");
	printf("Reservar Apartamento:\n");
	printf("  Identificador de edificio: %d\n", id);
	printf("  Tipo de apartamento (B-Básico/N-Normal/L-Lujo): ");
	scanf(" %c", &apartment_type);
	printf("  Dia de entrada: %d\n", entry_day);
	printf("  Mes de entrada: %d\n", entry_month);
	printf("  Año de entrada: %d\n", entry_year);
	printf("  Longitud de la estancia: %d\n", length);
	printf("\tDatos de la Reserva:\n");
	printf("  Numero de reserva: ");
}

void	direct_reservation(building buildings[])
{
	char apartment_type, action;
	int	id, entry_day, entry_month, entry_year, length, res_num;

	system("clear");
	printf("Reservar Apartamento:\n");
	printf("  Identificador de edificio: ");
	scanf("%d", &id);
	printf("  Tipo de apartamento (B-Básico/N-Normal/L-Lujo): ");
	scanf(" %c", &apartment_type);
	buildings[id - 1].reservations[res_i].apartment_type = apartment_type;
	printf("  Dia de entrada: ");
	scanf("%d", &entry_day);
	buildings[id - 1].reservations[res_i].entry_day = entry_day;
	printf("  Mes de entrada: ");
	scanf("%d", &entry_month);
	buildings[id - 1].reservations[res_i].entry_month = entry_month;
	printf("  Año de entrada: ");
	scanf("%d", &entry_year);
	buildings[id - 1].reservations[res_i].entry_year = entry_year;
	printf("  Longitud de la estancia: ");
	scanf("%d", &length);
	buildings[id - 1].reservations[res_i].length = length;
	get_exit_date(buildings[id - 1].reservations, res_i);
	printf("\tDatos de la Reserva:\n");
	buildings[id - 1].reservations[res_i].number = res_i + 1;
	print_reservation_number(buildings[id - 1].reservations, res_i);
	assign_reserv_ref(buildings, id, apartment_type, res_i);
	printf("  Edificio: %s (Id = %d)\n", buildings[id - 1].name, id);
	printf("  Referencia apartamento: %s\n", buildings[id - 1].reservations[res_i].ref);
	printf("  Fecha entrada: %d/%d/%d\n", buildings[id - 1].reservations[res_i].entry_day, buildings[id - 1].reservations[res_i].entry_month, buildings[id - 1].reservations[res_i].entry_year);
	printf("  Duración de estancia: %d días\n", buildings[id - 1].reservations[res_i].length);
	printf("  Fecha salida: %d/%d/%d\n", buildings[id - 1].reservations[res_i].exit_day, buildings[id - 1].reservations[res_i].exit_month, buildings[id - 1].reservations[res_i].exit_year);
	printf("Es correcta la operación(S/N)? ");
	scanf(" %c", &action);
	if (action == 'S')
	{
		system("clear");
		printf("Realizando reserva\n");
		res_i++;
		sleep(1);
		return ;
	}
}

void get_exit_date(reservation res[], int i)
{
	int total_days = month_days(res[i].entry_month, res[i].entry_year);
	res[i].exit_day = res[i].entry_day + res[i].length;


	if (res[i].exit_day > total_days)
	{
		res[i].exit_day -= total_days;
		res[i].entry_month++;
		if (res[i].entry_month > 12)
		{
			res[i].exit_month = 1;
			res[i].exit_year = res[i].entry_year + 1;
		}
	}
	else
	{
		res[i].exit_month = res[i].entry_month;
		res[i].exit_year = res[i].entry_year;
	}
}
