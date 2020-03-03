#include"ALL.h"

void Print_Car_info(CAR *car)
{
	char *type_of_insurance[4] = { "PLATINUM", "DIAMOND", "GOLD", "BASIC" };
	char *type_of_car[5] = { "S","M","L","RV","SUV" };
	char *type_of_fuel[3] = { "DISEL", "GASOLINE", "LPG" };
	char *amount_of_fuel[4] = { "HIGH_10", "HIGH_8", "MID", "LOW" };
	char *car_status[3] = { "GOOD", "NOMAL", "BAD" };


	puts("[차량 정보 출력]");
	if (car->company_info[0] != NULL)
		printf("차량 소유 회사: %s\n", car->company_info[0]->company_name);
	else
	{
		printf("차량 소유 회사: 없음\n");
	}

	if (car->customer_info[0] != NULL)
	{
		printf("차량 렌탈 고객: %s\n", car->customer_info[0]->customer_name);
		printf("차량 렌탈 종료일: %s\n", car->period);
		printf("가입한 보험 종류: %s\n", type_of_insurance[car->customer_info[0]->insurance]);
	}
	else
	{
		printf("차량 렌탈 고객: 없음\n");
	}
	printf("차량 종류: %s\n", type_of_car[car->car_type]);
	printf("차량 이름: %s\n", car->car_name);
	printf("연료 종류: %s\n", type_of_fuel[car->fuel_type]);
	printf("연료량: %s\n", amount_of_fuel[car->amount_of_fuel]);
	printf("차량 상태: %s\n", car_status[car->car_status]);

}

/*메인 페이지*/
void main_menu_print_out()
{
	puts("차량 렌탈 프로그램\n");
	printf("1. 고객용 2. 딜러용 3. 프로그램 종료 4. 관리자 메뉴\n");
	printf("선택:");
}
/*고객 로그인 페이지*/
void customer_login_page_print_out()
{
	printf("고객용 로그인 페이지\n");
	printf("1. 로그인\n");
	printf("2. 회원 가입\n");
	printf("3. 뒤로 가기\n");
	printf("메뉴를 선택해주세요:");
}
void customer_function_page_print_out()
{
	printf("메뉴\n");
	printf("1. 차량 렌탈하기\n");
	printf("2. 렌탈 정보 확인\n");
	printf("3. 렌탈 연장\n");
	printf("4. 렌탈 이력\n");
	printf("5. 이전 메뉴\n");
	printf("메뉴를 선택해주세요:");
}
void Print_Customer_info(CAR *car)
{

}

/*딜러용 로그인 페이지*/
void dealer_login_page_print_out()
{
	printf("딜러용 로그인 페이지\n");
	printf("1. 로그인\n");
	printf("2. 뒤로 가기\n");
	printf("메뉴를 선택해주세요:");
}

void dealer_function_page_print_out()
{
	printf("메뉴\n");
	printf("1. 차량 대여 현황 확인\n");
	printf("2. 차량 정보 등록\n");
	printf("3. 차량 정보 조회, 수정, 삭제\n");
	printf("4. 홍보 문구 수정\n");
	printf("5. 차량별 이용 고객 히스토리\n");
	printf("메뉴를 선택해주세요:");
}