#include"ALL.h"
/*
*�Լ� ����:
*���� ��:
*��   ��:
*��   ��:
*/
DEALER * dealer_login_page(LIST_OF_DEALER *dealer_list)
{
	int sel;
	dealer_login_page_print_out();
	scanf("%d", &sel); clear_buf();

	switch (sel)
	{
	case 1:
		login_info = dealer_login_function(dealer_list);
		break;
	case 2:


		break;
	

	}
}


DEALER * dealer_login_function(const LIST_OF_DEALER *dealer_list)
{
	int id;
	char *pw;
	int exit_cnt = 0;
	DEALER *login_info = NULL;

	while (1)
	{
		printf("ID�� �Է����ּ���:"); scanf("%d", &id); clear_buf();
		printf("PW�� �Է����ּ���:"); pw = get_string_return_ptr();
		login_info = find_dealer_information(dealer_list, id, pw);
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

DEALER * find_dealer_information(const LIST_OF_DEALER *dealer_list, int id, char *pw)
{
	int search_idx = 0;
	int search_end = dealer_list->num_of_dealer;
	DEALER *temp = NULL;
	//�´� id�� ��� ��ȣ�� ã���� �� ������ �����Ѵ�.
	for (search_idx = 0; search_idx < search_end; search_idx++)
	{
		if (dealer_list->ary_of_dealer[search_idx]->id == id)
		{
			if (strcmp(dealer_list->ary_of_dealer[search_idx]->pw, pw) == 0)//��й�ȣ Ȯ��
			{
				temp = dealer_list->ary_of_dealer[search_idx];
			}
		}
	}

	return temp;
}


void search_car_information(DEALER *login_info)
{
	CAR_LINK *pointing_node = login_info->head_node;
	int idx = 0;

	if (pointing_node->R_Next == NULL)
		puts("����Ʈ�� �׸��� �����ϴ�.");
	else//����Ʈ ���ο� ��尡 �ִ� ���
	{
		pointing_node = pointing_node->R_Next;
		while (pointing_node->R_Next != NULL)
		{
			pointing_node = pointing_node->R_Next;
		}
		
	}

}

