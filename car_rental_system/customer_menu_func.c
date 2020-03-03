#include"ALL.h"
/*
*함수 원형:
*리턴 값:
*설   명:
*메   모:
*/



CUSTOMER * find_customer_information(const LIST_OF_CUSTOMER *customer_list, char *contact_number, char *pw)
{
	int search_idx = 0;
	int search_end = customer_list->num_of_customer;
	CUSTOMER *temp = NULL;
	//맞는 id와 비밀 번호를 찾으면 그 정보를 리턴한다.
	for (search_idx = 0; search_idx < search_end; search_idx++)
	{
		if (strcmp(customer_list->ary_of_customer[search_idx]->contact_number, contact_number) == 0)//맞는 id를 찾음
		{
			if (strcmp(customer_list->ary_of_customer[search_idx]->pw, pw) == 0)//비밀번호 확인
			{
				temp = customer_list->ary_of_customer[search_idx];
			}
		}
	}

	return temp;
}
CUSTOMER * customer_login_function(const LIST_OF_CUSTOMER *customer_list)
{
	char *contact_number = "01075047177";
	char *pw = "csqJuaRp";
	int exit_cnt = 0;
	CUSTOMER *login_info = NULL;

	while (1)
	{
		//printf("ID(연락처)를 입력해주세요:"); contact_number = get_string_return_ptr(); 
		//printf("PW를 입력해주세요:"); pw = get_string_return_ptr();
		login_info = find_customer_information(customer_list, contact_number, pw);
		exit_cnt++;
		system("cls");

		if (login_info != NULL)
			break;

		if (exit_cnt >= 5)
		{
			puts("ID 혹은 비밀 번호를 확인해주세요");
			break;
		}	
	}
	
	return login_info;
}

CUSTOMER* customer_login_page(LIST_OF_CUSTOMER *customer_list,LIST_OF_DEALER *dealer_list, LIST_OF_CAR *car_list)
{
	int sel;
	CUSTOMER *login_info = NULL;
	
	customer_login_page_print_out();
	/*
	printf("고객용 로그인 페이지\n");
	printf("1. 로그인\n");
	printf("2. 회원 가입\n");
	printf("3. 뒤로 가기\n");
	printf("메뉴를 선택해주세요:");
	*/
	scanf("%d", &sel);
	clear_buf();

	switch (sel)
	{
	case 1:
		login_info = customer_login_function(customer_list);//
		if (login_info != NULL)
			customer_function_page(login_info, dealer_list, car_list);
		break;
	case 2:
		login_info = Add_Customer(customer_list);
		puts("회원 가입 완료");
		break;
	case 3:
		break;
	}

	return login_info;
}


CUSTOMER* find_dealer(CUSTOMER *login_info, LIST_OF_DEALER *dealer_list)
{
	int search_idx = 0;
	int search_end = dealer_list->num_of_dealer;
	int sel;
	while (1)
	{
		printf("딜러를 선택해주세요\n\n");
		for (search_idx = 0; search_idx < search_end; search_idx++)
		{
			printf("%d번\n", search_idx + 1);
			printf("회사 이름:%s\n", dealer_list->ary_of_dealer[search_idx]->company_name);
			printf("슬로건:%s\n\n\n", dealer_list->ary_of_dealer[search_idx]->slogan);
		}
		printf("딜러 선택: "); scanf("%d", &sel);

		if (sel >= 1 && sel <= search_end)
		{
			login_info->dealer[0] = dealer_list->ary_of_dealer[sel - 1];
			system("cls");
			break;
		}
		else
		{
			puts("잘못된 번호를 입력하셨습니다.");
			system("pause");
			system("cls");
		}
	}

	return login_info;
}

CUSTOMER* choose_insurance_plan(CUSTOMER *login_info)
{
	int sel;
	char *insurance_plan[4] = { "PLATINUM", "DIAMOND", "GOLD", "BASIC" };
	TYPE_OF_INSURANCE insurance;
	printf("보험에 가입하시겠습니까?\n");
	printf("1. YES          2. NO\n");
	printf("선택:"); scanf("%d", &sel);
	clear_buf();

	if (sel == 1)
	{
		while (1)
		{
			printf("가입할 보험 플랜을 골라주세요.\n");
			printf("PLATINUM, DIAMOND, GOLD, BASIC\n");
			printf("좌측부터 0~3의 순서\n");
			scanf("%d", &insurance);
			clear_buf();
			if (insurance > 3 || insurance < 0)
			{
				puts("잘못된 입력값입니다. 다시 입력해주세요");
				system("cls");
			}
			else
			{
				printf("%s 플랜에 가입되었습니다.\n", insurance_plan[insurance]);
				login_info->insurance = insurance;
				break;
			}	
		}

	}
	else
		login_info->insurance = NONE;

	return login_info;
}

CUSTOMER* select_rental_duration(CUSTOMER *login_info)
{
	printf("20200211과 같은 형식으로 렌탈 시작 날짜를 입력해주세요.");
	login_info->duration_start = get_string_return_ptr();
	printf("20200311과 같은 형식으로 반납 날짜를 입력해주세요.");
	login_info->duration_end = get_string_return_ptr();

	return login_info;
}
CUSTOMER * customer_function_page(CUSTOMER *login_info, LIST_OF_DEALER *dealer_list, LIST_OF_CAR *car_list)
{
	int sel;

	while (1)
	{
		customer_function_page_print_out();
		/*
		printf("메뉴\n");
		printf("1. 차량 렌탈하기\n");
		printf("2. 렌탈 정보 확인\n");
		printf("3. 렌탈 연장\n");
		printf("4. 렌탈 이력\n");
		printf("5. 이전 메뉴\n");
		printf("메뉴를 선택해주세요:");
		*/
		scanf("%d", &sel); clear_buf();
		switch (sel)
		{
		case 1:
			login_info = rental_car_func(login_info, dealer_list, car_list);
			break;
		case 2:
			show_rental_info(login_info);
			break;
		case 3:
			extend_rental(login_info);
			break;
		case 4:
			break;
		case 5:
			return login_info;
			break;

		}
		system("cls");
	}
	

	

}
void show_rental_info(const CUSTOMER *login_info)
{
	Print_Car_info(login_info->rental[0]);
}
CUSTOMER * extend_rental(CUSTOMER *login_info)
{
	printf("렌탈 완료 날짜: %s\n", login_info->duration_end);
	free(login_info->duration_end);
	printf("연장된 렌탈 날짜:");
	login_info->duration_end = get_string_return_ptr();
	printf("연장된 렌탈 날짜 확인: %s\n", login_info->duration_end);
	puts("날짜 연장 완료");

	return login_info;
}

CUSTOMER * rental_car_func(CUSTOMER *login_info, LIST_OF_DEALER *dealer_list, LIST_OF_CAR *car_list)
{
	login_info = find_dealer(login_info, dealer_list);
	login_info = choose_insurance_plan(login_info);
	login_info = select_rental_duration(login_info);
	login_info = find_car(login_info, car_list);

	return login_info;
}


CUSTOMER * find_car(CUSTOMER *login_info, LIST_OF_CAR *car_list)
{
	int search_idx = 0;
	int search_end = login_info->dealer[0]->num_of_car;
	int recommend_idx = 0;
	int answer;
	int selected_car;

	char *size[5] = { "S","M","L","RV","SUV" };//0
	char *fuel[3] = { "DISEL","GASOLINE","LPG" };//1
	char *condition[3] = { "GOO","NOMAL","BAD" };//2
	char *amount_of_fuel[4] = { "HIGH_10","HIGH_8","MID","LOW" };//3

	CAR **temp;
	
	temp = search_menu(&search_end, login_info->dealer[0]->list_of_car);
	if (search_end < 1)
	{
		puts("죄송합니다. 찾으시는 차량이 현재 저의 회사에는 준비되어있지 않습니다.");
		puts("다른 딜러의 차량(혹은 다른 옵션의 차량)을 찾아보시겠습니까?");
		puts("1. YES     2. NO");
		scanf("%d", &answer);
		clear_buf();
		if (answer == 1)
		{
			search_end = car_list->num_of_car;
			temp = search_menu(&search_end, car_list->ary_of_car);
		}
	}
	
	for (search_idx = 0; search_idx < search_end; search_idx++)
	{
		printf("추천후보 %d번째 차량\n", search_end + 1);
		printf("차량 종류: %s\n", size[temp[search_idx]->car_type]);
		printf("차량 이름: %s\n", temp[search_idx]->car_name);
		printf("연료 종류: %s\n", fuel[temp[search_idx]->fuel_type]);
		printf("연료 상태: %s\n", amount_of_fuel[temp[search_idx]->amount_of_fuel]);
		printf("차량 상태: %s\n", condition[temp[search_idx]->car_status]);
		puts("마음에 드는 차량을 골라주세요.");
		scanf("%d", &selected_car);
		clear_buf();
	}
	if (search_end < 1)
	{
		puts("찾으시는 차량이 없습니다. 다른 옵션을 검토해주세요.");
		puts("정말 죄송합니다.");
		login_info->rental[0] = NULL;
	}
		
	else
	{
		temp[selected_car - 1]->period = (char*)malloc((strlen(login_info->duration_end) + 1) * sizeof(char));
		strcpy(temp[selected_car - 1]->period, login_info->duration_end);
		login_info->rental[0] = temp[selected_car-1];
	}
		

	return login_info;
}

CAR** search_menu(int *search_end, CAR** recommendation_list)
{
	char *size[5] = { "S","M","L","RV","SUV" };//0
	char *fuel[3] = { "DISEL","GASOLINE","LPG" };//1
	char *condition[3] = { "GOOD","NOMAL","BAD" };//2
	char *amount_of_fuel[4] = { "HIGH_10","HIGH_8","MID","LOW" };//3
	int my_option=-1;
	int mode = 0;
	CAR **temp;

	CAR_TYPE car_type;
	FUEL_TYPE fuel_type;
	CAR_STATUS car_status;
	AMOUNT_OF_FUEL percent_of_fuel;

	while (mode < 5)
	{
		if (mode == 0)
		{
			temp = search_engine(mode, my_option, search_end, recommendation_list);//초기화
		}
		else if (mode == 1)
		{
			printf("렌탈 차량 옵션을 입력해주세요.\n");
			printf("차량 크기(S,M,L,RV,SUV) 0 ~ 4 선택: "); scanf("%d", &car_type); printf("\n");
			printf("선택한 차량의 크기는 '%s' 입니다.\n", size[car_type]);
			my_option = car_type;
			temp = search_engine(mode, my_option, search_end, temp);
		}
		else if (mode == 2)
		{
			printf("렌탈 차량 옵션을 입력해주세요.\n");
			printf("연료 종류(DISEL,GASOLINE,LPG) 0 ~ 2 선택: "); scanf("%d", &fuel_type); printf("\n");
			printf("선택한 연료의 종류는 '%s' 입니다.\n", fuel[fuel_type]);
			my_option = fuel_type;
			if (*search_end <= 1)
			{
				puts("탐색 대상이 1개 이하 입니다.");
				break;
			}
				
			temp = search_engine(mode, my_option, search_end, temp);
		}
		else if (mode == 3)
		{
			printf("렌탈 차량 옵션을 입력해주세요.\n");
			printf("차량 상태(GOOD,NOMAL,BAD) 0 ~ 2 선택: "); scanf("%d", &car_status); printf("\n");
			printf("선택한 차량의 상태는 '%s' 입니다.\n", condition[car_status]);
			my_option = car_status;
			if (*search_end <= 1)
			{
				puts("탐색 대상이 1개 이하 입니다.");
				break;
			}

			temp = search_engine(mode, my_option, search_end, temp);
		}
		else
		{
			printf("렌탈 차량 옵션을 입력해주세요.\n");
			printf("연료량(HIGH_10,HIGH_8,MID,LOW) 0 ~ 3 선택: "); scanf("%d", &percent_of_fuel); printf("\n");
			printf("선택한 차량의 연료량은 '%s' 입니다.\n", amount_of_fuel[percent_of_fuel]);
			my_option = percent_of_fuel;
			if (*search_end <= 1)
			{
				puts("탐색 대상이 1개 이하 입니다.");
				break;
			}

			temp = search_engine(mode, my_option, search_end, temp);
		}
		mode++;
	}

	return temp;
}

CAR** search_engine(int mode, int my_option, int *search_end, CAR** recommendation_list)
{
	CAR **recommendation;
	CAR **temp;
	int search_idx = 0;
	int recommend_idx = 0;

	recommendation = (CAR**)malloc((*search_end) * sizeof(CAR*));
	memcpy(recommendation, recommendation_list, *search_end * sizeof(CAR*));

	temp = (CAR**)malloc((*search_end) * sizeof(CAR*));
	memset(temp, NULL, (*search_end) * sizeof(CAR*));
	if (mode == 0)
	{
		for (search_idx = 0; search_idx < *search_end; search_idx++)
		{
			if (recommendation[search_idx]->customer_info == NULL)
			{
				temp[recommend_idx] = recommendation[search_idx];
				recommend_idx++;//옵션 하나 선택할 때마다 범위가 축소됨
			}
		}
	}

	else if (mode == 1)
	{
		for (search_idx = 0; search_idx < *search_end; search_idx++)
		{
			if (recommendation[search_idx]->car_type == my_option)
			{
				temp[recommend_idx] = recommendation[search_idx];
				recommend_idx++;//옵션 하나 선택할 때마다 범위가 축소됨
			}
		}
	}
	else if (mode == 2)
	{
		for (search_idx = 0; search_idx < *search_end; search_idx++)
		{
			if (recommendation[search_idx]->fuel_type == my_option)
			{
				temp[recommend_idx] = recommendation[search_idx];
				recommend_idx++;//옵션 하나 선택할 때마다 범위가 축소됨
			}
		}
	}
	else if (mode == 3)
	{
		for (search_idx = 0; search_idx < *search_end; search_idx++)
		{
			if (recommendation[search_idx]->car_status == my_option)
			{
				temp[recommend_idx] = recommendation[search_idx];
				recommend_idx++;//옵션 하나 선택할 때마다 범위가 축소됨
			}
		}
	}

	else 
	{
		for (search_idx = 0; search_idx < *search_end; search_idx++)
		{
			if (recommendation[search_idx]->amount_of_fuel == my_option)
			{
				temp[recommend_idx] = recommendation[search_idx];
				recommend_idx++;//옵션 하나 선택할 때마다 범위가 축소됨
			}
		}

	}
	
	free(recommendation);

	temp = (CAR**)realloc(temp, recommend_idx * sizeof(CAR*));
	*search_end = recommend_idx;

	return temp;
}




#ifdef NOTYET

recommendation = (CAR**)malloc(search_end * sizeof(CAR*));
memcpy(recommendation, login_info->dealer[0]->list_of_car, search_end * sizeof(CAR*));
temp = (CAR**)malloc(search_end * sizeof(CAR*));
memset(temp, NULL, search_end * sizeof(CAR*));

for (search_idx = 0; search_idx < search_end; search_idx++)
{
	if (recommendation[search_idx]->car_type == car_type)
	{
		temp[recommend_idx] = recommendation[search_idx];
		recommend_idx++;//옵션 하나 선택할 때마다 범위가 축소됨
	}
}
search_end = recommend_idx;


recommendation = (CAR**)malloc(search_end * sizeof(CAR*));
memcpy(recommendation, login_info->dealer[0]->list_of_car, search_end * sizeof(CAR*));
temp = (CAR**)malloc(search_end * sizeof(CAR*));
memset(temp, NULL, search_end * sizeof(CAR*));


for (search_idx = 0; search_idx < search_end; search_idx++)
{
	if (recommendation[search_idx]->fuel_type == fuel_type)
	{
		temp[recommend_idx] = login_info->dealer[0]->list_of_car[search_idx];
		recommend_idx++;//옵션 하나 선택할 때마다 범위가 축소됨
	}
}
#endif

