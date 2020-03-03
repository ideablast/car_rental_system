#include"ALL.h"
/*
*�Լ� ����:
*���� ��:
*��   ��:
*��   ��:
*/



CUSTOMER * find_customer_information(const LIST_OF_CUSTOMER *customer_list, char *contact_number, char *pw)
{
	int search_idx = 0;
	int search_end = customer_list->num_of_customer;
	CUSTOMER *temp = NULL;
	//�´� id�� ��� ��ȣ�� ã���� �� ������ �����Ѵ�.
	for (search_idx = 0; search_idx < search_end; search_idx++)
	{
		if (strcmp(customer_list->ary_of_customer[search_idx]->contact_number, contact_number) == 0)//�´� id�� ã��
		{
			if (strcmp(customer_list->ary_of_customer[search_idx]->pw, pw) == 0)//��й�ȣ Ȯ��
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
		//printf("ID(����ó)�� �Է����ּ���:"); contact_number = get_string_return_ptr(); 
		//printf("PW�� �Է����ּ���:"); pw = get_string_return_ptr();
		login_info = find_customer_information(customer_list, contact_number, pw);
		exit_cnt++;
		system("cls");

		if (login_info != NULL)
			break;

		if (exit_cnt >= 5)
		{
			puts("ID Ȥ�� ��� ��ȣ�� Ȯ�����ּ���");
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
	printf("���� �α��� ������\n");
	printf("1. �α���\n");
	printf("2. ȸ�� ����\n");
	printf("3. �ڷ� ����\n");
	printf("�޴��� �������ּ���:");
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
		puts("ȸ�� ���� �Ϸ�");
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
		printf("������ �������ּ���\n\n");
		for (search_idx = 0; search_idx < search_end; search_idx++)
		{
			printf("%d��\n", search_idx + 1);
			printf("ȸ�� �̸�:%s\n", dealer_list->ary_of_dealer[search_idx]->company_name);
			printf("���ΰ�:%s\n\n\n", dealer_list->ary_of_dealer[search_idx]->slogan);
		}
		printf("���� ����: "); scanf("%d", &sel);

		if (sel >= 1 && sel <= search_end)
		{
			login_info->dealer[0] = dealer_list->ary_of_dealer[sel - 1];
			system("cls");
			break;
		}
		else
		{
			puts("�߸��� ��ȣ�� �Է��ϼ̽��ϴ�.");
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
	printf("���迡 �����Ͻðڽ��ϱ�?\n");
	printf("1. YES          2. NO\n");
	printf("����:"); scanf("%d", &sel);
	clear_buf();

	if (sel == 1)
	{
		while (1)
		{
			printf("������ ���� �÷��� ����ּ���.\n");
			printf("PLATINUM, DIAMOND, GOLD, BASIC\n");
			printf("�������� 0~3�� ����\n");
			scanf("%d", &insurance);
			clear_buf();
			if (insurance > 3 || insurance < 0)
			{
				puts("�߸��� �Է°��Դϴ�. �ٽ� �Է����ּ���");
				system("cls");
			}
			else
			{
				printf("%s �÷��� ���ԵǾ����ϴ�.\n", insurance_plan[insurance]);
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
	printf("20200211�� ���� �������� ��Ż ���� ��¥�� �Է����ּ���.");
	login_info->duration_start = get_string_return_ptr();
	printf("20200311�� ���� �������� �ݳ� ��¥�� �Է����ּ���.");
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
		printf("�޴�\n");
		printf("1. ���� ��Ż�ϱ�\n");
		printf("2. ��Ż ���� Ȯ��\n");
		printf("3. ��Ż ����\n");
		printf("4. ��Ż �̷�\n");
		printf("5. ���� �޴�\n");
		printf("�޴��� �������ּ���:");
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
	printf("��Ż �Ϸ� ��¥: %s\n", login_info->duration_end);
	free(login_info->duration_end);
	printf("����� ��Ż ��¥:");
	login_info->duration_end = get_string_return_ptr();
	printf("����� ��Ż ��¥ Ȯ��: %s\n", login_info->duration_end);
	puts("��¥ ���� �Ϸ�");

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
		puts("�˼��մϴ�. ã���ô� ������ ���� ���� ȸ�翡�� �غ�Ǿ����� �ʽ��ϴ�.");
		puts("�ٸ� ������ ����(Ȥ�� �ٸ� �ɼ��� ����)�� ã�ƺ��ðڽ��ϱ�?");
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
		printf("��õ�ĺ� %d��° ����\n", search_end + 1);
		printf("���� ����: %s\n", size[temp[search_idx]->car_type]);
		printf("���� �̸�: %s\n", temp[search_idx]->car_name);
		printf("���� ����: %s\n", fuel[temp[search_idx]->fuel_type]);
		printf("���� ����: %s\n", amount_of_fuel[temp[search_idx]->amount_of_fuel]);
		printf("���� ����: %s\n", condition[temp[search_idx]->car_status]);
		puts("������ ��� ������ ����ּ���.");
		scanf("%d", &selected_car);
		clear_buf();
	}
	if (search_end < 1)
	{
		puts("ã���ô� ������ �����ϴ�. �ٸ� �ɼ��� �������ּ���.");
		puts("���� �˼��մϴ�.");
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
			temp = search_engine(mode, my_option, search_end, recommendation_list);//�ʱ�ȭ
		}
		else if (mode == 1)
		{
			printf("��Ż ���� �ɼ��� �Է����ּ���.\n");
			printf("���� ũ��(S,M,L,RV,SUV) 0 ~ 4 ����: "); scanf("%d", &car_type); printf("\n");
			printf("������ ������ ũ��� '%s' �Դϴ�.\n", size[car_type]);
			my_option = car_type;
			temp = search_engine(mode, my_option, search_end, temp);
		}
		else if (mode == 2)
		{
			printf("��Ż ���� �ɼ��� �Է����ּ���.\n");
			printf("���� ����(DISEL,GASOLINE,LPG) 0 ~ 2 ����: "); scanf("%d", &fuel_type); printf("\n");
			printf("������ ������ ������ '%s' �Դϴ�.\n", fuel[fuel_type]);
			my_option = fuel_type;
			if (*search_end <= 1)
			{
				puts("Ž�� ����� 1�� ���� �Դϴ�.");
				break;
			}
				
			temp = search_engine(mode, my_option, search_end, temp);
		}
		else if (mode == 3)
		{
			printf("��Ż ���� �ɼ��� �Է����ּ���.\n");
			printf("���� ����(GOOD,NOMAL,BAD) 0 ~ 2 ����: "); scanf("%d", &car_status); printf("\n");
			printf("������ ������ ���´� '%s' �Դϴ�.\n", condition[car_status]);
			my_option = car_status;
			if (*search_end <= 1)
			{
				puts("Ž�� ����� 1�� ���� �Դϴ�.");
				break;
			}

			temp = search_engine(mode, my_option, search_end, temp);
		}
		else
		{
			printf("��Ż ���� �ɼ��� �Է����ּ���.\n");
			printf("���ᷮ(HIGH_10,HIGH_8,MID,LOW) 0 ~ 3 ����: "); scanf("%d", &percent_of_fuel); printf("\n");
			printf("������ ������ ���ᷮ�� '%s' �Դϴ�.\n", amount_of_fuel[percent_of_fuel]);
			my_option = percent_of_fuel;
			if (*search_end <= 1)
			{
				puts("Ž�� ����� 1�� ���� �Դϴ�.");
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
				recommend_idx++;//�ɼ� �ϳ� ������ ������ ������ ��ҵ�
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
				recommend_idx++;//�ɼ� �ϳ� ������ ������ ������ ��ҵ�
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
				recommend_idx++;//�ɼ� �ϳ� ������ ������ ������ ��ҵ�
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
				recommend_idx++;//�ɼ� �ϳ� ������ ������ ������ ��ҵ�
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
				recommend_idx++;//�ɼ� �ϳ� ������ ������ ������ ��ҵ�
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
		recommend_idx++;//�ɼ� �ϳ� ������ ������ ������ ��ҵ�
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
		recommend_idx++;//�ɼ� �ϳ� ������ ������ ������ ��ҵ�
	}
}
#endif

