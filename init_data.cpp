/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.hpp"

void init_reservations(reservation reservations[])
{
	int i = 0;
	while (i < 365)
	{
		reservations[i].number = 0;
		reservations[i].entry_day = 0;
		reservations[i].entry_month = 0;
		reservations[i].entry_year = 0;
		reservations[i].length = 0;
		reservations[i].exit_day = 0;
		reservations[i].exit_month = 0;
		reservations[i].exit_year = 0;
		i++;
	}
}

void init_data(building buildings[])
{
	char names[5][10] = {"Apolo", "Atenea", "Zeus", "Efesto", "Hermes"};
	int i = 0;
	while (i < 4)
	{
		buildings[i].id = i + 1;
		buildings[i].basic = 10;
		buildings[i].normal = 5;
		buildings[i].luxury = 5;
		buildings[i].basic_available = buildings[i].basic;
		buildings[i].normal_available = buildings[i].normal;
		buildings[i].luxury_available = buildings[i].luxury;
		strcpy(buildings[i].name, names[i]);
		init_reservations(buildings[i].reservations);
		i++;
	}
}
