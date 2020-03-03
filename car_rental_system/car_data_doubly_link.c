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
		puts("리스트 내부에 노드가 없어 리스트의 첫노드로 삽입했습니다.");
		pointing_node->R_Next = temp;
	}
	else//리스트 내부에 노드가 있는 경우
	{
		pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
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
		puts("리스트 내부에 노드가 없어 리스트의 첫노드로 삽입했습니다.");
		pointing_node->R_Next = temp;
	}
	else
	{
		pointing_node = pointing_node->R_Next;
		while (pointing_node->R_Next != NULL)//pointing_node가 가장 마지막 노드에 도착하면 while루프를 돌지 않음
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
		puts("리스트에 항목이 없습니다.");
	else//리스트 내부에 노드가 있는 경우
	{
		pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
		while (pointing_node->R_Next != NULL)//pointing_node가 가장 마지막 노드에 도착하면 while루프를 돌지 않음
		{
			Print_Car_info(pointing_node->CUR[0]);
			printf("\n");
			pointing_node = pointing_node->R_Next;
			//i++;
			//printf("%d", i);
		}
		//리스트의 마지막 노드에서의 처리
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
		puts("리스트에 항목이 없습니다.");
	else//리스트 내부에 노드가 있는 경우
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
		puts("리스트에 항목이 없습니다.");
	else//리스트 내부에 노드가 있는 경우
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
		puts("리스트에 항목이 없습니다.");
	else//리스트 내부에 노드가 있는 경우
	{
		pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
		while (pointing_node->R_Next != NULL)//pointing_node가 가장 마지막 노드에 도착하면 while루프를 돌지 않음
		{
			cnt++;
			pointing_node = pointing_node->R_Next;
		}
		//리스트의 마지막 노드에서의 처리
		cnt++;
	}

	return cnt;
}

void Delete_doubly_node(CAR_LINK *head_node, CAR *car)
{
	CAR_LINK *pointing_node = head_node;

	if (pointing_node->R_Next == NULL)
		puts("리스트에 항목이 없습니다.");

	else//리스트 내부에 노드가 있는 경우
	{
		pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
		while (pointing_node->R_Next != NULL)//pointing_node가 가장 마지막 노드에 도착하면 while루프를 돌지 않음
		{

			if (pointing_node->CUR[0] == car)//pointing_node 왼쪽에 노드 삽입
			{
				if (pointing_node->L_Next == NULL)//리스트의 첫번째 노드인 경우
				{
					head_node->R_Next = pointing_node->R_Next;//헤드가 가리키는 노드의 변경을 고려해줘야 한다.
					pointing_node->R_Next->L_Next = NULL;
					//노드의 데이터값 중복 허용을 고려하려면 free전에 오른쪽으로 pointing_node를 옮겨 놓을것
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
		puts("리스트에 항목이 없습니다.");

	else//리스트 내부에 노드가 있는 경우
	{
		pointing_node = pointing_node->R_Next;//pointing_node가 첫번째 노드를 가리킴
		head_node->R_Next = NULL;
		while (pointing_node->R_Next != NULL)//pointing_node가 가장 마지막 노드에 도착하면 while루프를 돌지 않음
		{
			pointing_node = pointing_node->R_Next;
			free(pointing_node->L_Next);
		}
		free(pointing_node);
	}
}


