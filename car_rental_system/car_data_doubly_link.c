#include"ALL.h"

CAR_LINK *Add_new_doubly_node()
{
	CAR_LINK *temp;
	temp = (CAR_LINK*)malloc(sizeof(CAR_LINK));
	temp->CUR = (CAR**)malloc(sizeof(CAR*));

	temp->CUR[0] = NULL;
	temp->R_Next = NULL;
	temp->L_Next = NULL;

	return temp;

}
void Add_doubly_node_First(CAR_LINK *head_node, CAR *car)
{
	CAR_LINK *pointing_node = head_node;
	CAR_LINK *temp = Add_new_doubly_node();
	temp->CUR[0] = car;

	if (pointing_node->R_Next == NULL)
	{
		puts("����Ʈ ���ο� ��尡 ���� ����Ʈ�� ù���� �����߽��ϴ�.");
		pointing_node->R_Next = temp;
	}
	else//����Ʈ ���ο� ��尡 �ִ� ���
	{
		pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
		head_node->R_Next = temp;
		temp->R_Next = pointing_node;
		pointing_node->L_Next = temp;
	}
}
void Add_doubly_node_Last(CAR_LINK *head_node, CAR *car)
{
	CAR_LINK *pointing_node = head_node;
	CAR_LINK *temp = Add_new_doubly_node();
	temp->CUR[0] = car;

	if (pointing_node->R_Next == NULL)
	{
		puts("����Ʈ ���ο� ��尡 ���� ����Ʈ�� ù���� �����߽��ϴ�.");
		pointing_node->R_Next = temp;
	}
	else
	{
		pointing_node = pointing_node->R_Next;
		while (pointing_node->R_Next != NULL)//pointing_node�� ���� ������ ��忡 �����ϸ� while������ ���� ����
		{
			pointing_node = pointing_node->R_Next;
		}
		pointing_node->R_Next = temp;
		temp->L_Next = pointing_node;
	}
}
void Print_doubly_node(CAR_LINK *head_node)
{
	CAR_LINK *pointing_node = head_node;
	//static int i = 0;

	if (pointing_node->R_Next == NULL)
		puts("����Ʈ�� �׸��� �����ϴ�.");
	else//����Ʈ ���ο� ��尡 �ִ� ���
	{
		pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
		while (pointing_node->R_Next != NULL)//pointing_node�� ���� ������ ��忡 �����ϸ� while������ ���� ����
		{
			Print_Car_info(pointing_node->CUR[0]);
			printf("\n");
			pointing_node = pointing_node->R_Next;
			//i++;
			//printf("%d", i);
		}
		//����Ʈ�� ������ ��忡���� ó��
		Print_Car_info(pointing_node->CUR[0]);
		printf("\n");
		//i++;
		//printf("%d", i);
	}

}

void Cpy_list_to_ary(DEALER *login_info)
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
			login_info->list_of_car[idx] = pointing_node;
			idx++;
			pointing_node = pointing_node->R_Next;
		}
		login_info->list_of_car[idx] = pointing_node;
		idx++;
		login_info->num_of_car = idx;
		login_info->list_of_car = (CAR**)malloc((login_info->num_of_car) * sizeof(CAR*));
	}
}

void Cpy_ary_to_list(DEALER *login_info)
{
	CAR_LINK *pointing_node = login_info->head_node;
	int search_end = login_info->num_of_car;
	int idx = 0;

	if (pointing_node->R_Next == NULL)
		puts("����Ʈ�� �׸��� �����ϴ�.");
	else//����Ʈ ���ο� ��尡 �ִ� ���
	{
		pointing_node = pointing_node->R_Next;
		while (pointing_node->R_Next != NULL)
		{
			idx++;
			pointing_node = pointing_node->R_Next;
		}
		login_info->list_of_car[idx] = pointing_node;
		idx++;
		login_info->num_of_car = idx;
		login_info->list_of_car = (CAR**)malloc((login_info->num_of_car) * sizeof(CAR*));
	}
}

int Count_doubly_node(CAR_LINK *head_node)
{
	CAR_LINK *pointing_node = head_node;
	int cnt = 0;

	if (pointing_node->R_Next == NULL)
		puts("����Ʈ�� �׸��� �����ϴ�.");
	else//����Ʈ ���ο� ��尡 �ִ� ���
	{
		pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
		while (pointing_node->R_Next != NULL)//pointing_node�� ���� ������ ��忡 �����ϸ� while������ ���� ����
		{
			cnt++;
			pointing_node = pointing_node->R_Next;
		}
		//����Ʈ�� ������ ��忡���� ó��
		cnt++;
	}

	return cnt;
}

void Delete_doubly_node(CAR_LINK *head_node, CAR *car)
{
	CAR_LINK *pointing_node = head_node;

	if (pointing_node->R_Next == NULL)
		puts("����Ʈ�� �׸��� �����ϴ�.");

	else//����Ʈ ���ο� ��尡 �ִ� ���
	{
		pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
		while (pointing_node->R_Next != NULL)//pointing_node�� ���� ������ ��忡 �����ϸ� while������ ���� ����
		{

			if (pointing_node->CUR[0] == car)//pointing_node ���ʿ� ��� ����
			{
				if (pointing_node->L_Next == NULL)//����Ʈ�� ù��° ����� ���
				{
					head_node->R_Next = pointing_node->R_Next;//��尡 ����Ű�� ����� ������ �������� �Ѵ�.
					pointing_node->R_Next->L_Next = NULL;
					//����� �����Ͱ� �ߺ� ����� ����Ϸ��� free���� ���������� pointing_node�� �Ű� ������
					free(pointing_node);
					break;

				}
				else
				{
					pointing_node->L_Next->R_Next = pointing_node->R_Next;
					pointing_node->R_Next->L_Next = pointing_node->L_Next;
					free(pointing_node);
					break;
				}
			}
			pointing_node = pointing_node->R_Next;
		}
		if (pointing_node->CUR[0] == car)
		{
			pointing_node->L_Next->R_Next = NULL;
			free(pointing_node);
		}

	}
}

void Delete_all_doubly_node(CAR_LINK *head_node)
{
	CAR_LINK *pointing_node = head_node;
	if (pointing_node->R_Next == NULL)
		puts("����Ʈ�� �׸��� �����ϴ�.");

	else//����Ʈ ���ο� ��尡 �ִ� ���
	{
		pointing_node = pointing_node->R_Next;//pointing_node�� ù��° ��带 ����Ŵ
		head_node->R_Next = NULL;
		while (pointing_node->R_Next != NULL)//pointing_node�� ���� ������ ��忡 �����ϸ� while������ ���� ����
		{
			pointing_node = pointing_node->R_Next;
			free(pointing_node->L_Next);
		}
		free(pointing_node);
	}
}


