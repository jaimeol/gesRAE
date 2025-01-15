/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#include "gesRAE.h"

int has_overlap(TypeReserv new_res, TypeReserv existing_res)
{
  if (existing_res->entry_year < new_res->entry_year && existing_res->exit_year > new_res->exit_year)
  {
    return (1);
  }
  if (existing_res->entry_year == new_res->entry_year || existing_res->exit_year == new_res->exit_year)
  {
    if (existing_res->entry_month < new_res->entry_month && existing_res->exit_month > new_res->exit_month)
    {
      return (1);
    }
    else if (existing_res->entry_month == new_res->entry_month || existing_res->exit_month == new_res->exit_month)
    {
      if ((existing_res->entry_day <= new_res->exit_day && existing_res->exit_day >= new_res->entry_day)
        || (new_res->entry_day <= existing_res->exit_day && new_res->exit_day >= existing_res->entry_day))
      {
        return (1);
      }
    }
  }
  if (existing_res->entry_year <= new_res->exit_year && existing_res->exit_year >= new_res->entry_year)
  {
    if (existing_res->entry_month <= new_res->exit_month && existing_res->exit_month >= new_res->entry_month)
    {
      if ((existing_res->entry_day <= new_res->exit_day && existing_res->exit_day >= new_res->entry_day)
        || (new_res->entry_day <= existing_res->exit_day && new_res->exit_day >= existing_res->entry_day))
        {
          return (1);
        }
    }
  }
    return (0);
}

void	print_reservation_number(TypeReserv res, int i)
{
	if (res[i].number < 10)
	{
		printf("  Numero de reserva: 0%d/%d\n", res[i].number,
			res[i].entry_year);
	}
	else
	{
		printf("  Numero de reserva: %d/%d\n", res[i].number,
			res[i].entry_year);
	}
}

void	assign_reserv_ref(TypeBuilding buildings, int id, char apartment_type,
		int res_i)
{
	TypeRef	aux_ref;
	int		found_reference;
	int		is_overlap;

	int number = 1;
	aux_ref[0] = 'A';
	aux_ref[1] = 'P';
	aux_ref[2] = 'T';
	aux_ref[3] = '0';
	aux_ref[4] = '0' + (id + 1 % 10);
	aux_ref[5] = apartment_type;
	found_reference = 0;
	while (!found_reference)
	{
		found_reference = 1;
		for (int i = 0; i < 366; i++)
		{
			if (i != res_i)
			{
				if ((buildings[id].reservations[res_i].entry_year == buildings[id].reservations[i].entry_year
						&& buildings[id].reservations[res_i].entry_month == buildings[id].reservations[i].entry_month
						&& buildings[id].reservations[res_i].entry_day >= buildings[id].reservations[i].entry_day
						&& buildings[id].reservations[res_i].entry_day <= buildings[id].reservations[i].exit_day)
					|| (buildings[id].reservations[res_i].exit_year == buildings[id].reservations[i].entry_year
						&& buildings[id].reservations[res_i].exit_month == buildings[id].reservations[i].exit_month
						&& buildings[id].reservations[res_i].exit_day >= buildings[id].reservations[i].entry_day
						&& buildings[id].reservations[res_i].exit_day <= buildings[id].reservations[i].exit_day))
				{
					number++;
					continue;
				}
			}
		}
		aux_ref[6] = '0' + (number / 10);
		aux_ref[7] = '0' + (number % 10);
		aux_ref[8] = '\0';
		strcpy(buildings[id].reservations[res_i].ref, aux_ref);
	}
}

void	assign_apartment_type(TypeBuilding buildings, char type, int id, int res_i)
{
	if (type == 'B')
	{
		buildings[id].reservations[res_i].apartment_type = 0;
	}
	else if (type == 'N')
	{
		buildings[id].reservations[res_i].apartment_type = 1;
	}
	else if (type == 'L')
	{
		buildings[id].reservations[res_i].apartment_type = 2;
	}
}
