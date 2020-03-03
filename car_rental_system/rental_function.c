#include"ALL.h"

void Add_Dealer(LIST_OF_DEALER *dealer_list)
{
	dealer_list->ary_of_dealer = (DEALER**)malloc((dealer_list->num_of_dealer + 1) * sizeof(DEALER*));
	dealer_list->ary_of_dealer[dealer_list->num_of_dealer] = (DEALER*)malloc(sizeof(DEALER));
	dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->id = dealer_list->num_of_dealer;

	dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->company_name = get_string_return_ptr();
	//dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->pw = get_string_return_ptr();
	dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->slogan = get_string_return_ptr();
	dealer_list->num_of_dealer++;
}

CUSTOMER* Add_Customer(LIST_OF_CUSTOMER *customer_list)
{
	CUSTOMER *temp;
	customer_list->ary_of_customer = (CUSTOMER**)malloc((customer_list->num_of_customer + 1) * sizeof(CUSTOMER*));
	customer_list->ary_of_customer[customer_list->num_of_customer] = (CUSTOMER*)malloc(sizeof(CUSTOMER));
	temp = customer_list->ary_of_customer[customer_list->num_of_customer];
	customer_list->ary_of_customer[customer_list->num_of_customer]->id = customer_list->num_of_customer;

	customer_list->ary_of_customer[customer_list->num_of_customer]->customer_name = get_string_return_ptr();
	customer_list->ary_of_customer[customer_list->num_of_customer]->contact_number = get_string_return_ptr();
	scanf("%d", &customer_list->ary_of_customer[customer_list->num_of_customer]->age);//
	customer_list->ary_of_customer[customer_list->num_of_customer]->customer_address = get_string_return_ptr();
	//customer_list->ary_of_customer[customer_list->num_of_customer]->pw = get_string_return_ptr();
	customer_list->num_of_customer++;
	//rental,insurance,history

	return temp;
}
void Add_Car(LIST_OF_CAR *car_list)
{
	car_list->ary_of_car = (CAR**)malloc((car_list->num_of_car + 1) * sizeof(CAR*));
	car_list->ary_of_car[car_list->num_of_car] = (CAR*)malloc(sizeof(CAR));
	car_list->ary_of_car[car_list->num_of_car]->id = car_list->num_of_car;

	car_list->ary_of_car[car_list->num_of_car]->car_name = get_string_return_ptr();
	scanf("%d", &car_list->ary_of_car[car_list->num_of_car]->car_type);
	scanf("%d", &car_list->ary_of_car[car_list->num_of_car]->fuel_type);
	scanf("%d", &car_list->ary_of_car[car_list->num_of_car]->amount_of_fuel);
	scanf("%d", &car_list->ary_of_car[car_list->num_of_car]->car_status);
	car_list->num_of_car++;
}
