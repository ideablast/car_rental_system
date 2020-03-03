#include"ALL.h"


void make_rand_info_car()
{
	FILE *fp;
	int i;
	int id, owner, name;
	fp = fopen("car_save.txt", "w");
	AMOUNT_OF_FUEL amount_of_fuel;
	FUEL_TYPE type_of_fuel;
	CAR_STATUS status_of_car;
	CAR_TYPE type_of_car;


	for (i = 0; i < MAX_RAND_CAR; i++)
	{
		id = i;
		owner = rand() % 3;
		type_of_car = rand() % 5;
		//S,M,L,RV,SUV
		type_of_fuel = rand() % 3;
		//DISEL,GASILINE,LPG
		amount_of_fuel = rand() % 4;
		//HIGH_10, HIGH_8, MID, LOW
		status_of_car = rand() % 3;
		//GOOD,NOMAL,BAD
		name = rand() % 4;

		fprintf(fp, "%d %d %d %d %d %d %d\n", id, owner, type_of_car, type_of_fuel, amount_of_fuel, status_of_car, name);
	}

	fclose(fp);
}

void load_car_info(LIST_OF_CAR *car_list, int id, int owner, CAR_TYPE type_of_car, FUEL_TYPE type_of_fuel, AMOUNT_OF_FUEL amount_of_fuel, CAR_STATUS status_of_car, int name)
{
	//차량 정보에 들어갈 소유주, 대여자, 대여 히스토리는 나중에 따로 입력
	
	const char *car_name_S[5] = { "K3 1.6", "레이 1.0", "아반떼AD 1.6", "올뉴모닝 1.0", "크루즈 1.4" };
	const char *car_name_M[5] = { "K5 2.0", "SM6", "쏘나타 뉴 라이즈 2.0", "쏘나타 스마트스트림 2.0" ,"올뉴 그랜져" };
	const char *car_name_L[5] = { "GENESIS G70 2.0", "GENESIS G80 3.3", "K7 2.4", "K9 3.3", "그랜저IG 2.4" };
	const char *car_name_RV[5] = { "스타렉스 11인승", "스타렉스 12인승", "올 뉴 카니발R 11인승 ", "올 뉴 카니발R 9인승","봉고 15인승" };
	const char *car_name_SUV[5] = { "QM6 2.0", "스포티지 1.6", "싼타페 2.0", "쏘렌토R 2.0", "투싼 1.6" };
	const char **car_name_list[5] = { car_name_S, car_name_M, car_name_L, car_name_RV, car_name_SUV };


	if (car_list->num_of_car == 0)
		car_list->ary_of_car = (CAR**)malloc((car_list->num_of_car + 1) * sizeof(CAR*));
	else
		car_list->ary_of_car = (CAR**)realloc(car_list->ary_of_car, (car_list->num_of_car + 1) * sizeof(CAR*));

	car_list->ary_of_car[car_list->num_of_car] = (CAR*)malloc(sizeof(CAR));
	car_list->ary_of_car[car_list->num_of_car]->id = id;

	car_list->ary_of_car[car_list->num_of_car]->company_info = (DEALER**)malloc(sizeof(DEALER*));
	car_list->ary_of_car[car_list->num_of_car]->customer_info = (CUSTOMER**)malloc(sizeof(CUSTOMER*));
	car_list->ary_of_car[car_list->num_of_car]->customer_info[0] = NULL;
	car_list->ary_of_car[car_list->num_of_car]->car_name = (char *)malloc((strlen(car_name_list[type_of_car][name]) + 1) * sizeof(char));
	strcpy(car_list->ary_of_car[car_list->num_of_car]->car_name, car_name_list[type_of_car][name]);
	car_list->ary_of_car[car_list->num_of_car]->car_status = status_of_car;
	car_list->ary_of_car[car_list->num_of_car]->amount_of_fuel = amount_of_fuel;
	car_list->ary_of_car[car_list->num_of_car]->fuel_type = type_of_fuel;
	car_list->ary_of_car[car_list->num_of_car]->car_type = type_of_car;
	car_list->num_of_car++;
}

void file_read_car_info(LIST_OF_CAR *car_list)
{
	FILE *fp;
	int id, owner, type_of_car, type_of_fuel, status_of_car, amount_of_fuel, size, name;
	fp = fopen("car_save.txt", "r");

	while (!feof(fp))
	{
		fscanf(fp, "%d %d %d %d %d %d %d", &id, &owner, &type_of_car, &type_of_fuel, &amount_of_fuel, &status_of_car, &name);
		load_car_info(car_list, id, owner, type_of_car, type_of_fuel, amount_of_fuel, status_of_car, name);
	}

}

void allocation_random_car(LIST_OF_CAR *car_list, LIST_OF_DEALER *dealer_list)
{
	int idx;

	for (idx = 0; idx < DEALER_MAX; idx++)
	{
		car_list->ary_of_car[idx]->company_info[0] = dealer_list->ary_of_dealer[0];
		dealer_list->ary_of_dealer[0]->list_of_car[idx % DEALER_MAX] = car_list->ary_of_car[idx];
	}
	for (idx = DEALER_MAX*1; idx < DEALER_MAX*2; idx++)
	{
		car_list->ary_of_car[idx]->company_info[0] = dealer_list->ary_of_dealer[1];
		dealer_list->ary_of_dealer[1]->list_of_car[idx % DEALER_MAX] = car_list->ary_of_car[idx];
	}
	for (idx = DEALER_MAX*2; idx < DEALER_MAX*3; idx++)
	{
		car_list->ary_of_car[idx]->company_info[0] = dealer_list->ary_of_dealer[2];
		dealer_list->ary_of_dealer[2]->list_of_car[idx % DEALER_MAX] = car_list->ary_of_car[idx];
	}
}

void allocation_random_car_Link_ver(LIST_OF_CAR *car_list, LIST_OF_DEALER *dealer_list)
{
	int idx;
	int dealer_idx = dealer_list->num_of_dealer;
	int i;

	for (i = 0; i < dealer_idx; i++)
	{
		dealer_list->ary_of_dealer[i]->head_node = Add_new_doubly_node();
	}
	for (idx = 0; idx < 100; idx++)
	{
		Add_doubly_node_First(dealer_list->ary_of_dealer[0]->head_node, car_list->ary_of_car[idx]);
	}
	for (idx = 100; idx < 200; idx++)
	{
		Add_doubly_node_First(dealer_list->ary_of_dealer[1]->head_node, car_list->ary_of_car[idx]);
	}
	for (idx = 200; idx < 300; idx++)
	{
		Add_doubly_node_First(dealer_list->ary_of_dealer[2]->head_node, car_list->ary_of_car[idx]);
	}
}