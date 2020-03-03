#pragma once
#ifndef __FUNCTION_H__
#define __FUNCTION_H__
/*계정 추가 기능*/
void Add_Dealer(LIST_OF_DEALER *dealer_list);
CUSTOMER* Add_Customer(LIST_OF_CUSTOMER *customer_list);
void Add_Car(LIST_OF_CAR *car_list);

/*랜덤 차량 정보 생성*/
void make_rand_info_car();
void load_car_info(LIST_OF_CAR *car_list, int id, int owner, CAR_TYPE type_of_car, FUEL_TYPE type_of_fuel, AMOUNT_OF_FUEL amount_of_fuel, CAR_STATUS status_of_car, int name);
void file_read_car_info(LIST_OF_CAR *car_list);
void allocation_random_car(LIST_OF_CAR *car_list, LIST_OF_DEALER *dealer_list);

/*랜덤 고객 생성*/
void input_zero(char*temp, int i);
char* make_rand_contact();
void make_rand_info_customer();
void load_customer_info(LIST_OF_CUSTOMER *customer_list, int id, int name, int addr, int age, char *contact, char* pw);
void file_read_customer_info(LIST_OF_CUSTOMER *customer_list);

/*딜러 정보 생성*/
void file_read_dealer_info(LIST_OF_DEALER *dealer_list);
void load_dealer_info(LIST_OF_DEALER *dealer_list, int id, int number_of_car, char *slogan, char *pw);

/*고객 페이지 기능*/
CUSTOMER * find_customer_information(const LIST_OF_CUSTOMER *customer_list, char *contact_number, char *pw);
CUSTOMER * customer_login_function(const LIST_OF_CUSTOMER *customer_list);
CUSTOMER* customer_login_page(LIST_OF_CUSTOMER *customer_list, LIST_OF_DEALER *dealer_list, LIST_OF_CAR *car_list);
CUSTOMER* find_dealer(CUSTOMER *login_info, LIST_OF_DEALER *dealer_list);
CUSTOMER* choose_insurance_plan(CUSTOMER *login_info);
CUSTOMER* select_rental_duration(CUSTOMER *login_info);
CUSTOMER * customer_function_page(CUSTOMER *login_info, LIST_OF_DEALER *dealer_list, LIST_OF_CAR *car_list);
void show_rental_info(const CUSTOMER *login_info);
CUSTOMER * extend_rental(CUSTOMER *login_info);

CUSTOMER * rental_car_func(CUSTOMER *login_info, LIST_OF_DEALER *dealer_list, LIST_OF_CAR *car_list);
CUSTOMER * find_car(CUSTOMER *login_info, LIST_OF_CAR *car_list);
CAR** search_menu(int *search_end, CAR** recommendation_list);
CAR** search_engine(int mode, int my_option, int *search_end, CAR** recommendation_list);
/*차량 매매, 매입 관리를 위한 리스트 함수*/
CAR_LINK *Add_new_doubly_node();
void Add_doubly_node_First(CAR_LINK *head_node, CAR *car);
void Add_doubly_node_Last(CAR_LINK *head_node, CAR *car);
void Print_doubly_node(CAR_LINK *head_node);
void Delete_doubly_node(CAR_LINK *head_node, CAR *car);
void allocation_random_car_Link_ver(LIST_OF_CAR *car_list, LIST_OF_DEALER *dealer_list);
int Count_doubly_node(CAR_LINK *head_node);
void Delete_all_doubly_node(CAR_LINK *head_node);

/*함수 포인터 연습*/
CUSTOMER * find_car_func_pointer(CUSTOMER *login_info, LIST_OF_CAR *car_list);
CAR* select_car(int *search_end, CAR **recommendation_list);
CAR** search_menu_func_pointer(int *search_end, CAR** recommendation_list);
CAR** search_engine_func_pointer(int mode, int *search_end, CAR** recommendation_list);
CAR** initial_setting(int *search_end, CAR **recommendation_list);
CAR** search_car_type(int *search_end, CAR **recommendation_list);
CAR** search_fuel_type(int *search_end, CAR **recommendation_list);
CAR** search_car_status(int *search_end, CAR **recommendation_list);
CAR** search_amount_of_fuel(int *search_end, CAR **recommendation_list);

/*정보 출력 함수*/
void main_menu_print_out();
void Print_Car_info(CAR *car);
void customer_login_page_print_out();
void customer_function_page_print_out();


/*간단한 기능의 함수*/
void get_string(char**str_ptr);
char* get_string_return_ptr();
void clear_buf();

#endif