/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.hpp"

static int res_i = 0;

void direct_reservation(building buildings[])
{
    char apartment_type, action;
    int id, entry_day, entry_month, entry_year, length;

    system("clear");
    printf("Reservar Apartamento:\n");
    printf("  Identificador de edificio: ");
    scanf("%d", &id);  // Leer el ID del edificio
    printf("  Tipo de apartamento (B-Básico/N-Normal/L-Lujo): ");
    scanf(" %c", &apartment_type);  // Leer el tipo de apartamento
    printf("  Dia de entrada: ");
    scanf("%d", &entry_day);
    printf("  Mes de entrada: ");
    scanf("%d", &entry_month);
    printf("  Año de entrada: ");
    scanf("%d", &entry_year);
    printf("  Longitud de la estancia: ");
    scanf("%d", &length);

    // Asignar los valores a la reserva
    buildings[id - 1].reservations[res_i].apartment_type = apartment_type;
    buildings[id - 1].reservations[res_i].entry_day = entry_day;
    buildings[id - 1].reservations[res_i].entry_month = entry_month;
    buildings[id - 1].reservations[res_i].entry_year = entry_year;
    buildings[id - 1].reservations[res_i].length = length;
    
    // Calcular la fecha de salida
    get_exit_date(buildings[id - 1].reservations, res_i);

    // Mostrar la reserva antes de confirmarla
    printf("\tDatos de la Reserva:\n");
	buildings[id - 1].reservations[res_i].number = res_i + 1;
	print_reservation_number(buildings[id - 1].reservations, res_i);
	assign_reserv_ref(buildings, id, apartment_type, res_i);
	printf("  Edificio: %s (Id = %d)\n", buildings[id - 1].name, id);
	printf("  Referencia apartamento: %s\n", buildings[id - 1].reservations[res_i].ref);
    printf("  Fecha entrada: %d/%d/%d\n", entry_day, entry_month, entry_year);
    printf("  Duración de estancia: %d días\n", length);
    printf("  Fecha salida: %d/%d/%d\n", buildings[id - 1].reservations[res_i].exit_day, 
           buildings[id - 1].reservations[res_i].exit_month, buildings[id - 1].reservations[res_i].exit_year);
    printf("Es correcta la operación(S/N)? ");
    scanf(" %c", &action);
    if (action == 'S') {
        system("clear");
        printf("Realizando reserva\n");
        res_i++;  // Incrementar el índice para la siguiente reserva
        sleep(1);
    } else {
        printf("Reserva cancelada\n");
    }
}


void get_exit_date(reservation res[], int i)
{
	int total_days = month_days(res[i].entry_month, res[i].entry_year);
	res[i].exit_day = res[i].entry_day + res[i].length;
	int aux_entry_month = res[i].entry_month;
	int aux_entry_year = res[i].entry_year;


	while (res[i].exit_day > total_days)
	{
		res[i].exit_day -= total_days;
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
