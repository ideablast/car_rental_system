#include"ALL.h"

void Print_Car_info(CAR *car)
{
	char *type_of_insurance[4] = { "PLATINUM", "DIAMOND", "GOLD", "BASIC" };
	char *type_of_car[5] = { "S","M","L","RV","SUV" };
	char *type_of_fuel[3] = { "DISEL", "GASOLINE", "LPG" };
	char *amount_of_fuel[4] = { "HIGH_10", "HIGH_8", "MID", "LOW" };
	char *car_status[3] = { "GOOD", "NOMAL", "BAD" };


	puts("[���� ���� ���]");
	if (car->company_info[0] != NULL)
		printf("���� ���� ȸ��: %s\n", car->company_info[0]->company_name);
	else
	{
		printf("���� ���� ȸ��: ����\n");
	}

	if (car->customer_info[0] != NULL)
	{
		printf("���� ��Ż ��: %s\n", car->customer_info[0]->customer_name);
		printf("���� ��Ż ������: %s\n", car->period);
		printf("������ ���� ����: %s\n", type_of_insurance[car->customer_info[0]->insurance]);
	}
	else
	{
		printf("���� ��Ż ��: ����\n");
	}
	printf("���� ����: %s\n", type_of_car[car->car_type]);
	printf("���� �̸�: %s\n", car->car_name);
	printf("���� ����: %s\n", type_of_fuel[car->fuel_type]);
	printf("���ᷮ: %s\n", amount_of_fuel[car->amount_of_fuel]);
	printf("���� ����: %s\n", car_status[car->car_status]);

}

/*���� ������*/
void main_menu_print_out()
{
	puts("���� ��Ż ���α׷�\n");
	printf("1. ���� 2. ������ 3. ���α׷� ���� 4. ������ �޴�\n");
	printf("����:");
}
/*�� �α��� ������*/
void customer_login_page_print_out()
{
	printf("���� �α��� ������\n");
	printf("1. �α���\n");
	printf("2. ȸ�� ����\n");
	printf("3. �ڷ� ����\n");
	printf("�޴��� �������ּ���:");
}
void customer_function_page_print_out()
{
	printf("�޴�\n");
	printf("1. ���� ��Ż�ϱ�\n");
	printf("2. ��Ż ���� Ȯ��\n");
	printf("3. ��Ż ����\n");
	printf("4. ��Ż �̷�\n");
	printf("5. ���� �޴�\n");
	printf("�޴��� �������ּ���:");
}
void Print_Customer_info(CAR *car)
{

}

/*������ �α��� ������*/
void dealer_login_page_print_out()
{
	printf("������ �α��� ������\n");
	printf("1. �α���\n");
	printf("2. �ڷ� ����\n");
	printf("�޴��� �������ּ���:");
}

void dealer_function_page_print_out()
{
	printf("�޴�\n");
	printf("1. ���� �뿩 ��Ȳ Ȯ��\n");
	printf("2. ���� ���� ���\n");
	printf("3. ���� ���� ��ȸ, ����, ����\n");
	printf("4. ȫ�� ���� ����\n");
	printf("5. ������ �̿� �� �����丮\n");
	printf("�޴��� �������ּ���:");
}