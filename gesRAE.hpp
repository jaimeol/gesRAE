/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/

#pragma once
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

typedef char TypeName[20];
typedef char TypeRef[8];

typedef struct reservation
{
	int number;
	int entry_day;
	int entry_month;
	int entry_year;
	int length;
	int exit_day;
	int exit_month;
	int exit_year;
	TypeRef ref;
	char apartment_type;
};

typedef reservation TypeReserv[366]; //vector de reservas con un máximo de 366 por si hubiese una reserva por dia en cada año

typedef struct building
{
	int id;
	TypeName name;
	int basic;
	int normal;
	int luxury;
	int basic_available;
	int normal_available;
	int luxury_available;
	TypeReserv reservations;
};


void do_reservation(building buildings[], int id, int entry_day, int entry_month, int entry_year, int length);
void direct_reservation(building buildings[]);
void get_exit_date(reservation res[], int i);

void edit_building(building buidings[]);
void display_list(building buildings[]);
void display_available(building buildings[]);
void init_data(building buildings[]);

void print_normal_spaces(int num);
void print_basic_spaces(int num);
void print_name_spaces(building buildings[], int i);
int	check_name_len(char str[]);
int	check_total_apartments(building buildings[], int id);
int	check_correct_id(int id);

bool leap_year(int year);
int	month_days(int month, int year);
void print_date_format(int month);
void print_reservation_number(reservation res[], int i);
void assign_reserv_ref(building buildings[], int id, char apartment_type, int res_i);


void debug_reservations(building buildings[], int id);