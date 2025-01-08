/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/


#include "gesRAE.h"

typedef char TypeString[21];

int	check_name_len(TypeString str)
{
	if (strlen(str) > 20)
	{
		printf("\033[31mError\033[0m: Nombre demasiado largo.\n");
		printf("Por favor vuelva introducir el nombre\n");
		return (1);
	}
	else if (strlen(str) < 1)
	{
		printf ("\033[31mError\033[0m: El nombre debe de estar conformado de al menos un caracter\n");
		printf("Por favor vuelva introducir el nombre\n");
		return (1);
	}
	return (0);
}

int	check_total_apartments(TypeBuilding buildings, int id)
{
	int total_apartments = buildings[id].basic + buildings[id].normal + buildings[id].luxury;
	if (total_apartments > 20)
	{
		printf ("\033[31mError\033[0m: No puede haber un numero mayor de 20 apartamentos\n");
		printf ("Por favor vuelva a introducir los datos\n");
		return (1);
	}
	else if (total_apartments < 1)
	{

		system ("cls");
		printf("Dando de baja el edificio\n");
		sleep(1);
		return (2);
	}
	return (0);
}

int	check_correct_id(int id)
{
	if (id < 1 || id > 5)
	{
		system("clear");
		printf("\033[31mError\033[0m: El id del edificio debe de ser un numero comprendido entre 1 y 5\n");
		printf("Por favor introduzca un id permitido\n");
		return (1);
	}
	return (0);
}


int	check_correct_type(char c)
{
	if (c != 'B' && c != 'N' && c != 'L')
	{
	  printf("%c\n", c);
		printf("Tipo de apartamento incorrecto por favor vuelva a introducir el tipo de apartamento que desea\n");
		return (1);
	}
	return (0);
}
