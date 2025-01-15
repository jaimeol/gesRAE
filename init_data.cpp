/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

static void init_reservations(TypeReserv reservations)
{
	int i = 0;
	while (i < 366)
	{
		reservations[i].number = 0;
		reservations[i].entry_day = 0;
		reservations[i].entry_month = 0;
		reservations[i].entry_year = 0;
		reservations[i].length = 0;
		reservations[i].exit_day = 0;
		reservations[i].exit_month = 0;
		reservations[i].exit_year = 0;
		reservations[i].apartment_type = -1;
		i++;
	}
}

void init_data(TypeBuilding buildings)
{
	typedef char name[5][10];
	name names = {"Apolo", "Atenea", "Zeus", "Efesto", "Hermes"};
	int i = 0;
	while (i < 5)
	{
		buildings[i].id = i + 1;
		buildings[i].basic = 10;
		buildings[i].normal = 5;
		buildings[i].luxury = 5;
		buildings[i].number_res = 0;
		strcpy(buildings[i].name, names[i]);
		init_reservations(buildings[i].reservations);
		i++;
	}
}
