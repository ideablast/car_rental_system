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
	printf("%d ���� ��õ ����\n", search_end);
	printf("1. ���� ���� 2.�ٸ� ������ ���� �˻�");
	printf("�Է�:"); scanf("%d", &answer); clear_buf();
	if (answer == 1)//���� ����
	{
		selected_car = select_car(&search_end, temp);
		if (selected_car != NULL)
			login_info->rental[0] = selected_car;
		else
		{
			puts("�ٸ� ������ ����(Ȥ�� �ٸ� �ɼ��� ����)�� ã�ƺ��ðڽ��ϱ�?");
			answer = 0;
			printf("1. YES 2. NO\n");
			printf("�Է�:"); scanf("%d", &answer); clear_buf();
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
	else//�ٸ� ������ ���� �˻�
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
		printf("����Ʈ �߿��� ������ �����ϱ� ���ؼ��� ��ȣ�� �� ������ּ���\n");
		for (idx = 0; idx < *search_end; idx++)
		{
			printf("===========");
			printf("��ȣ: %d\n",idx);
			printf("===========");
			Print_Car_info(recommendation_list[idx]);
		}
		printf("��ȣ�� �Է����ּ���.\n");
		printf("�Է�:"); scanf("%d", &sel); clear_buf();
		Print_Car_info(recommendation_list[sel]);
		printf("�� ������ �½��ϱ�?\n");
		printf("1. YES    2. NO    3.������\n����:"); scanf("%d", &answer); clear_buf();
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

	//���� ó���� ������ NULL�� �������� recommendation_list�� ��Ż ���� �������� ����� �ٲ۴�.
	temp = search_engine_func_pointer(mode, search_end, recommendation_list);

	while (1)
	{
		puts("�˻� �ɼ� ����");
		puts("0.�ʱ�ȭ 1.������ 2.���� ���� 3.���� ���� 4.���ᷮ 5.�˻� ����");
		printf("����: "); scanf("%d", &mode); clear_buf();

		if (mode == 0)
			temp = search_engine_func_pointer(mode, search_end, recommendation_list);
		else if (mode == 5)
			break;
		else
			temp = search_engine_func_pointer(mode, search_end, temp);

		printf("�˻� ���: %d ��",*search_end);
		printf("�˻� ����� ���ðڽ��ϱ�?"); 
		printf("1. YES    2. NO    ����:");scanf("%d", &sel); clear_buf();

		if (sel == 1)
		{
			printf("����Ʈ �߿��� ������ �����ϱ� ���ؼ��� ��ȣ�� �� ������ּ���\n");
			for (idx = 0; idx < *search_end; idx++)
			{
				printf("===========");
				printf("��ȣ: %d\n",idx);
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
			recommend_idx++;//�ɼ� �ϳ� ������ ������ ������ ��ҵ�
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

	printf("��Ż ���� �ɼ��� �Է����ּ���.\n");
	printf("���� ũ��(S,M,L,RV,SUV) 0 ~ 4 ����: "); scanf("%d", &car_type); printf("\n");
	printf("������ ������ ũ��� '%s' �Դϴ�.\n", size[car_type]);
	

	for (search_idx = 0; search_idx < mem_size; search_idx++)
	{
		if (recommendation[search_idx]->car_type == car_type)
		{
			temp[recommend_idx] = recommendation[search_idx];
			recommend_idx++;//�ɼ� �ϳ� ������ ������ ������ ��ҵ�
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

	printf("��Ż ���� �ɼ��� �Է����ּ���.\n");
	printf("���� ����(DISEL,GASOLINE,LPG) 0 ~ 2 ����: "); scanf("%d", &fuel_type); printf("\n");
	printf("������ ������ ������ '%s' �Դϴ�.\n", fuel[fuel_type]);

	for (search_idx = 0; search_idx < mem_size; search_idx++)
	{
		if (recommendation[search_idx]->fuel_type == fuel_type)
		{
			temp[recommend_idx] = recommendation[search_idx];
			recommend_idx++;//�ɼ� �ϳ� ������ ������ ������ ��ҵ�
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

	printf("��Ż ���� �ɼ��� �Է����ּ���.\n");
	printf("���� ����(GOOD,NOMAL,BAD) 0 ~ 2 ����: "); scanf("%d", &car_status); printf("\n");
	printf("������ ������ ���´� '%s' �Դϴ�.\n", condition[car_status]);

	for (search_idx = 0; search_idx < mem_size; search_idx++)
	{
		if (recommendation[search_idx]->car_status == car_status)
		{
			temp[recommend_idx] = recommendation[search_idx];
			recommend_idx++;//�ɼ� �ϳ� ������ ������ ������ ��ҵ�
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

	printf("��Ż ���� �ɼ��� �Է����ּ���.\n");
	printf("���ᷮ(HIGH_10,HIGH_8,MID,LOW) 0 ~ 3 ����: "); scanf("%d", &percent_of_fuel); printf("\n");
	printf("������ ������ ���ᷮ�� '%s' �Դϴ�.\n", amount_of_fuel[percent_of_fuel]);

	for (search_idx = 0; search_idx < mem_size; search_idx++)
	{
		if (recommendation[search_idx]->amount_of_fuel == percent_of_fuel)
		{
			temp[recommend_idx] = recommendation[search_idx];
			recommend_idx++;//�ɼ� �ϳ� ������ ������ ������ ��ҵ�
		}
	}

	free(recommendation);

	temp = (CAR**)realloc(temp, recommend_idx * sizeof(CAR*));
	*search_end = recommend_idx;

	return temp;
}

