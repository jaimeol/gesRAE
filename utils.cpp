/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.hpp"

void print_name_spaces(building buildings[], int i)
{
	int space_num = 16 - strlen(buildings[i].name);
	int j = 0;
	while (j < space_num)
	{
		printf(" ");
		j++;
	}
}

void print_basic_spaces(int num)
{
	int space_num;
	int i = 0; 
	if (num > 10)
		space_num = 15;
	else
		space_num = 16;
	while (i < space_num)
	{
		printf(" ");
		i++;
	}
}

void print_normal_spaces(int num)
{
	int space_num;
	int i = 0;
	if (num > 10)
		space_num = 16;
	else
		space_num = 17;
	while (i < space_num)
	{
		printf(" ");
		i++;
	}
}

void print_reservation_number(reservation res[], int i)
{
	if (res[i].number < 10)
		printf("  Numero de reserva: 0%d/%d\n", res[i].number, res[i].entry_year);
	else
		printf("  Numero de reserva: %d/%d\n", res[i].number, res[i].entry_year);
}

void assign_reserv_ref(building buildings[], int id, char apartment_type, int res_i)
{
	char aux_ref[8];

	aux_ref[0] = 'A';
	aux_ref[1] = 'P';
	aux_ref[2] = 'T';
	aux_ref[3] = '0';
	aux_ref[4] = '0' + (id % 10);

	if (apartment_type == 'B')
	{
		aux_ref[5] = 'B';
		aux_ref[6] = '0' + (((buildings[id - 1].basic - buildings[id - 1].basic_available) + 1) / 10);
		aux_ref[7] = '0' + (((buildings[id - 1].basic - buildings[id - 1].basic_available) + 1) % 10);
		buildings[id - 1].basic_available--;
	}
	else if (apartment_type == 'N')
	{
		aux_ref[5] = 'N';
		aux_ref[6] = '0' + (((buildings[id - 1].normal - buildings[id - 1].normal_available) + 1) / 10);
		aux_ref[7] = '0' + (((buildings[id - 1].normal - buildings[id - 1].normal_available) + 1) % 10);
		buildings[id - 1].normal_available--;
	}
	else if (apartment_type == 'L')
	{
		aux_ref[5] = 'L';
		aux_ref[6] = '0' + (((buildings[id - 1].luxury - buildings[id - 1].luxury_available) + 1) / 10);
		aux_ref[7] = '0' + (((buildings[id - 1].luxury - buildings[id - 1].luxury_available) + 1) % 10);
		buildings[id - 1].luxury_available--;
	}
	strcpy(buildings[id - 1].reservations[res_i].ref, aux_ref);
}
