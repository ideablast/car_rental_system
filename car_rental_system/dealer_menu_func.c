#include"ALL.h"
/*
*함수 원형:
*리턴 값:
*설   명:
*메   모:
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
		printf("ID를 입력해주세요:"); scanf("%d", &id); clear_buf();
		printf("PW를 입력해주세요:"); pw = get_string_return_ptr();
		login_info = find_dealer_information(dealer_list, id, pw);
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

DEALER * find_dealer_information(const LIST_OF_DEALER *dealer_list, int id, char *pw)
{
	int search_idx = 0;
	int search_end = dealer_list->num_of_dealer;
	DEALER *temp = NULL;
	//맞는 id와 비밀 번호를 찾으면 그 정보를 리턴한다.
	for (search_idx = 0; search_idx < search_end; search_idx++)
	{
		if (dealer_list->ary_of_dealer[search_idx]->id == id)
		{
			if (strcmp(dealer_list->ary_of_dealer[search_idx]->pw, pw) == 0)//비밀번호 확인
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
		puts("리스트에 항목이 없습니다.");
	else//리스트 내부에 노드가 있는 경우
	{
		pointing_node = pointing_node->R_Next;
		while (pointing_node->R_Next != NULL)
		{
			pointing_node = pointing_node->R_Next;
		}
		
	}

}

