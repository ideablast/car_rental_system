#include"ALL.h"

CUSTOMER * find_car_func_pointer(CUSTOMER *login_info, LIST_OF_CAR *car_list)
{
	int search_idx = 0;
	int search_end = login_info->dealer[0]->num_of_car;
	int recommend_idx = 0;
	int answer = 0;

	CAR **temp;
	CAR *selected_car;

	temp = search_menu_func_pointer(&search_end, login_info->dealer[0]->list_of_car);
	printf("%d 건의 추천 차량\n", search_end);
	printf("1. 차량 선택 2.다른 딜러의 차량 검색");
	printf("입력:"); scanf("%d", &answer); clear_buf();
	if (answer == 1)//차량 선택
	{
		selected_car = select_car(&search_end, temp);
		if (selected_car != NULL)
			login_info->rental[0] = selected_car;
		else
		{
			puts("다른 딜러의 차량(혹은 다른 옵션의 차량)을 찾아보시겠습니까?");
			answer = 0;
			printf("1. YES 2. NO\n");
			printf("입력:"); scanf("%d", &answer); clear_buf();
			if (answer == 1)
			{
				search_end = car_list->num_of_car;
				temp = search_menu(&search_end, car_list->ary_of_car);
				selected_car = select_car(&search_end, temp);
			}
			else
				login_info->rental[0] = NULL;
		}
	}
	else//다른 딜러의 차량 검색
	{
		search_end = car_list->num_of_car;
		temp = search_menu(&search_end, car_list->ary_of_car);
		selected_car = select_car(&search_end, temp);
	}

	if (selected_car != NULL)
		login_info->rental[0] = selected_car;
	else
		login_info->rental[0] = NULL;

	return login_info;
}
CAR* select_car(int *search_end, CAR **recommendation_list)
{
	int idx;
	int sel = 0;
	int answer = 0;
	CAR *result;

	while (1)
	{
		printf("리스트 중에서 차량을 선택하기 위해서는 번호를 잘 기억해주세요\n");
		for (idx = 0; idx < *search_end; idx++)
		{
			printf("===========");
			printf("번호: %d\n",idx);
			printf("===========");
			Print_Car_info(recommendation_list[idx]);
		}
		printf("번호를 입력해주세요.\n");
		printf("입력:"); scanf("%d", &sel); clear_buf();
		Print_Car_info(recommendation_list[sel]);
		printf("이 차량이 맞습니까?\n");
		printf("1. YES    2. NO    3.나가기\n선택:"); scanf("%d", &answer); clear_buf();
		if (answer == 1)
		{
			result = recommendation_list[sel];
			break;
		}
		else if (answer == 3)
		{
			result = NULL;
			break;
		}
		else
		{
			sel = 0;
			answer = 0;
			system("cls");
		}
	}

	return result;
}
CAR** search_menu_func_pointer(int *search_end, CAR** recommendation_list)
{
	int idx = 0;
	int mode = 0;
	int sel = 0;
	CAR **temp;

	//제일 처음에 고객란이 NULL인 차량으로 recommendation_list를 렌탈 가능 차량으로 목록을 바꾼다.
	temp = search_engine_func_pointer(mode, search_end, recommendation_list);

	while (1)
	{
		puts("검색 옵션 선택");
		puts("0.초기화 1.사이즈 2.연료 종류 3.차량 상태 4.연료량 5.검색 종료");
		printf("선택: "); scanf("%d", &mode); clear_buf();

		if (mode == 0)
			temp = search_engine_func_pointer(mode, search_end, recommendation_list);
		else if (mode == 5)
			break;
		else
			temp = search_engine_func_pointer(mode, search_end, temp);

		printf("검색 결과: %d 건",*search_end);
		printf("검색 결과를 보시겠습니까?"); 
		printf("1. YES    2. NO    선택:");scanf("%d", &sel); clear_buf();

		if (sel == 1)
		{
			printf("리스트 중에서 차량을 선택하기 위해서는 번호를 잘 기억해주세요\n");
			for (idx = 0; idx < *search_end; idx++)
			{
				printf("===========");
				printf("번호: %d\n",idx);
				printf("===========");
				Print_Car_info(temp[idx]);
			}
		}
		else
			sel = 0;

	}
	system("pause");
	return temp;
}
CAR** search_engine_func_pointer(int mode, int *search_end, CAR** recommendation_list)
{
	CAR ** (*search_option[5])(int*, CAR**);//(int my_option, int *search_end, CAR **recommendation_list)
	CAR ** temp;

	search_option[0] = initial_setting;
	search_option[1] = search_car_type;
	search_option[2] = search_fuel_type;
	search_option[3] = search_car_status;
	search_option[4] = search_amount_of_fuel;

	temp = search_option[mode](search_end, recommendation_list);

	return temp;
}

CAR **initial_setting(int *search_end, CAR **recommendation_list)
{
	CAR **recommendation;
	CAR **temp;
	int mem_size = *search_end;
	int search_idx = 0;
	int recommend_idx = 0;

	recommendation = (CAR**)malloc(mem_size *sizeof(CAR*));
	memcpy(recommendation, recommendation_list, mem_size *sizeof(CAR*));

	temp = (CAR**)malloc(mem_size *sizeof(CAR*));
	memset(temp, NULL, mem_size *sizeof(CAR*));

	for (search_idx = 0; search_idx < mem_size; search_idx++)
	{
		if (recommendation[search_idx]->customer_info == NULL)
		{
			temp[recommend_idx] = recommendation[search_idx];
			recommend_idx++;//옵션 하나 선택할 때마다 범위가 축소됨
		}
	}

	free(recommendation);

	temp = (CAR**)realloc(temp, recommend_idx * sizeof(CAR*));
	*search_end = recommend_idx;

	return temp;
}
CAR **search_car_type(int *search_end, CAR **recommendation_list)
{
	CAR **recommendation;
	CAR **temp;
	int mem_size = *search_end;
	int search_idx = 0;
	int recommend_idx = 0;
	CAR_TYPE car_type;
	char *size[5] = { "S","M","L","RV","SUV" };//0
	
	recommendation = (CAR**)malloc(mem_size * sizeof(CAR*));
	memcpy(recommendation, recommendation_list, mem_size * sizeof(CAR*));

	temp = (CAR**)malloc(mem_size * sizeof(CAR*));
	memset(temp, NULL, mem_size * sizeof(CAR*));

	printf("렌탈 차량 옵션을 입력해주세요.\n");
	printf("차량 크기(S,M,L,RV,SUV) 0 ~ 4 선택: "); scanf("%d", &car_type); printf("\n");
	printf("선택한 차량의 크기는 '%s' 입니다.\n", size[car_type]);
	

	for (search_idx = 0; search_idx < mem_size; search_idx++)
	{
		if (recommendation[search_idx]->car_type == car_type)
		{
			temp[recommend_idx] = recommendation[search_idx];
			recommend_idx++;//옵션 하나 선택할 때마다 범위가 축소됨
		}
	}

	free(recommendation);

	temp = (CAR**)realloc(temp, recommend_idx * sizeof(CAR*));
	*search_end = recommend_idx;

	return temp;
}
CAR **search_fuel_type(int *search_end, CAR **recommendation_list)
{
	CAR **recommendation;
	CAR **temp;
	int mem_size = *search_end;
	int search_idx = 0;
	int recommend_idx = 0;
	FUEL_TYPE fuel_type;
	char *fuel[3] = { "DISEL","GASOLINE","LPG" };//1

	recommendation = (CAR**)malloc(mem_size * sizeof(CAR*));
	memcpy(recommendation, recommendation_list, mem_size * sizeof(CAR*));

	temp = (CAR**)malloc(mem_size * sizeof(CAR*));
	memset(temp, NULL, mem_size * sizeof(CAR*));

	printf("렌탈 차량 옵션을 입력해주세요.\n");
	printf("연료 종류(DISEL,GASOLINE,LPG) 0 ~ 2 선택: "); scanf("%d", &fuel_type); printf("\n");
	printf("선택한 연료의 종류는 '%s' 입니다.\n", fuel[fuel_type]);

	for (search_idx = 0; search_idx < mem_size; search_idx++)
	{
		if (recommendation[search_idx]->fuel_type == fuel_type)
		{
			temp[recommend_idx] = recommendation[search_idx];
			recommend_idx++;//옵션 하나 선택할 때마다 범위가 축소됨
		}
	}

	free(recommendation);

	temp = (CAR**)realloc(temp, recommend_idx * sizeof(CAR*));
	*search_end = recommend_idx;

	return temp;
}
CAR **search_car_status(int *search_end, CAR **recommendation_list)
{
	CAR **recommendation;
	CAR **temp;
	int mem_size = *search_end;
	int search_idx = 0;
	int recommend_idx = 0;
	CAR_STATUS car_status;
	char *condition[3] = { "GOOD","NOMAL","BAD" };//2

	recommendation = (CAR**)malloc(mem_size *sizeof(CAR*));
	memcpy(recommendation, recommendation_list, mem_size *sizeof(CAR*));

	temp = (CAR**)malloc(mem_size *sizeof(CAR*));
	memset(temp, NULL, mem_size *sizeof(CAR*));

	printf("렌탈 차량 옵션을 입력해주세요.\n");
	printf("차량 상태(GOOD,NOMAL,BAD) 0 ~ 2 선택: "); scanf("%d", &car_status); printf("\n");
	printf("선택한 차량의 상태는 '%s' 입니다.\n", condition[car_status]);

	for (search_idx = 0; search_idx < mem_size; search_idx++)
	{
		if (recommendation[search_idx]->car_status == car_status)
		{
			temp[recommend_idx] = recommendation[search_idx];
			recommend_idx++;//옵션 하나 선택할 때마다 범위가 축소됨
		}
	}

	free(recommendation);

	temp = (CAR**)realloc(temp, recommend_idx * sizeof(CAR*));
	*search_end = recommend_idx;

	return temp;
}
CAR **search_amount_of_fuel(int *search_end, CAR **recommendation_list)
{
	CAR **recommendation;
	CAR **temp;
	int mem_size = *search_end;
	int search_idx = 0;
	int recommend_idx = 0;
	AMOUNT_OF_FUEL percent_of_fuel;
	char *amount_of_fuel[4] = { "HIGH_10","HIGH_8","MID","LOW" };//3

	recommendation = (CAR**)malloc(mem_size *sizeof(CAR*));
	memcpy(recommendation, recommendation_list, mem_size *sizeof(CAR*));
	
	temp = (CAR**)malloc(mem_size *sizeof(CAR*));
	memset(temp, NULL, mem_size *sizeof(CAR*));

	printf("렌탈 차량 옵션을 입력해주세요.\n");
	printf("연료량(HIGH_10,HIGH_8,MID,LOW) 0 ~ 3 선택: "); scanf("%d", &percent_of_fuel); printf("\n");
	printf("선택한 차량의 연료량은 '%s' 입니다.\n", amount_of_fuel[percent_of_fuel]);

	for (search_idx = 0; search_idx < mem_size; search_idx++)
	{
		if (recommendation[search_idx]->amount_of_fuel == percent_of_fuel)
		{
			temp[recommend_idx] = recommendation[search_idx];
			recommend_idx++;//옵션 하나 선택할 때마다 범위가 축소됨
		}
	}

	free(recommendation);

	temp = (CAR**)realloc(temp, recommend_idx * sizeof(CAR*));
	*search_end = recommend_idx;

	return temp;
}

