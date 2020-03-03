#include"ALL.h"



int main()
{

	LIST_OF_DEALER dealer_list;
	LIST_OF_CAR car_list;
	LIST_OF_CUSTOMER customer_list;
	//int i,j;
	CUSTOMER *temp;
	int sel;

	srand((unsigned int)time(NULL));

	//�޸� ũ������ �ε��� �ʱ�ȭ
	dealer_list.num_of_dealer = 0;
	car_list.num_of_car = 0;
	customer_list.num_of_customer = 0;
	file_read_car_info(&car_list);
	file_read_customer_info(&customer_list);
	file_read_dealer_info(&dealer_list);
	allocation_random_car(&car_list, &dealer_list);
	allocation_random_car_Link_ver(&car_list, &dealer_list);
	
	while (1)
	{
	main_menu_print_out();
	scanf("%d", &sel); 
	clear_buf();
	
		switch (sel)
		{
		case 1:
			customer_login_page(&customer_list, &dealer_list, &car_list);
				break;
		case 2:

			break;
		case 3:
			break;
		case 4:
			return 0;
		}
	}
	
	


#ifdef TEST
	//���� ���� �Է�
	make_rand_info_customer();
	make_rand_info_car();

	
	for (i = 0; i < 120; i++)
	{
		printf("%d�� ���� ���� ȸ��:%s\n", i, car_list.ary_of_car[i]->company_name[0]->company_name);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 40; j++)
		{
			printf("%s ������ ������ ����: %s\n", dealer_list.ary_of_dealer[i]->company_name, dealer_list.ary_of_dealer[i]->list_of_car[j]->car_name);
		}
	}

	//����� ���� �ε�
	temp = select_rental_duration(choose_insurance_plan(find_dealer(login_function(&customer_list), &dealer_list)));

	temp = find_car(temp, &car_list);

	printf("���̸�: %s\n", temp->customer_name);
	printf("������: %d\n", temp->age);
	printf("���ּ�: %s\n", temp->customer_address);
	printf("�����̸�: %s\n", temp->dealer[0]->company_name);
	printf("�����̸�: %s\n", temp->rental[0]->car_name);
	printf("��������ȸ��: %s\n", temp->rental[0]->company_name);
	//���� ���� ���� ��ȸ�� ������ ��忡�� �����
	//���� Ǯ������ ���� ��ȸ�� ������ ��忡�� �����ϰ� ������

	//������ ���� ���� ��ȸ�� ������ ���� �ϰ� ����
	//������ �迭 ������ �ڷ� ������ ���Ḯ��Ʈ�� �ٲ㺸��
	allocation_random_car_Link_ver(&car_list, &dealer_list);
	Print_doubly_node(dealer_list.ary_of_dealer[0]->head_node);
	Print_doubly_node(dealer_list.ary_of_dealer[1]->head_node);
	Print_doubly_node(dealer_list.ary_of_dealer[2]->head_node);
	//�ڵ��� ���� �޴� �����(���� �ڵ��� ���� �������� �ϳ� ������)
	//�������� �б� ���� �Լ� �����	
	
#endif	
	

}