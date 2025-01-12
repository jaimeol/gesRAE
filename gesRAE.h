/**************************************
 * NOMBRE: #Jaime#
 * PRIMER APELLIDO: #Olivares#
 * SEGUNDO APELLIDO: #Cepeda#
 * DNI: #53805743A#
 * EMAIL: #jolivares142@alumno.uned.es#
 ***************************************/


#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
// #include <windows.h>

typedef char TypeName[20];
typedef char TypeRef[9];
typedef char TypeString[21];
typedef int TypeArray[366];

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
	int apartment_type;
	TypeRef ref;
};

typedef reservation TypeReserv[366];

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
	int	number_res;
	TypeReserv reservations;
};

typedef building TypeBuilding[5];

void do_reservation(TypeBuilding buildings);
void get_exit_date(TypeReserv res, int i);

void edit_building(TypeBuilding buildings);
void display_list(TypeBuilding buildings);
void display_available(TypeBuilding buildings);
void init_data(TypeBuilding buildings);

void print_normal_spaces(int num);
void print_basic_spaces(int num);
void print_name_spaces(TypeBuilding buildings, int i);
int	check_name_len(TypeString str);
int	check_total_apartments(TypeBuilding buildings, int id);
int	check_correct_id(int id);
int	check_correct_type(char c);

bool leap_year(int year);
int	month_days(int month, int year);
void print_date_format(int month);
int	assign_res_number(TypeBuilding buildings, int entry_year, int id);
void print_reservation_number(TypeReserv res, int i);
void assign_reserv_ref(TypeBuilding buildings, int id, char apartment_type, int res_i);
void assign_apartment_type(TypeBuilding buildings, char type, int id, int res_i);
int	get_id(TypeBuilding buildings, TypeRef ref);
void get_res_indexes(TypeBuilding buildings, TypeRef ref, TypeArray &indexes, int id);

int	zeller_algo(int day, int month, int year);
void monthly_reservations(TypeBuilding buildings);
void print_first_points(int &pipe, int &line_chars, int &total_digits, int &new_line, int month, int year);
int print_numbers(TypeBuilding buildings, int id, TypeArray indexes, int month, int year, int days_num, int &pipe, int &line_chars, int &new_line, int &total_digits);
void print_last_points(int line_chars, int pipe, int new_line);
void print_month_reservations(TypeBuilding buildings, TypeArray indexes, int free_days, int id, int month, int year);