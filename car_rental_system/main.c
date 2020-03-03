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

	//메모리 크기이자 인덱스 초기화
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
	//랜덤 정보 입력
	make_rand_info_customer();
	make_rand_info_car();

	
	for (i = 0; i < 120; i++)
	{
		printf("%d번 차량 소유 회사:%s\n", i, car_list.ary_of_car[i]->company_name[0]->company_name);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 40; j++)
		{
			printf("%s 딜러가 소유한 차량: %s\n", dealer_list.ary_of_dealer[i]->company_name, dealer_list.ary_of_dealer[i]->list_of_car[j]->car_name);
		}
	}

	//저장된 정보 로딩
	temp = select_rental_duration(choose_insurance_plan(find_dealer(login_function(&customer_list), &dealer_list)));

	temp = find_car(temp, &car_list);

	printf("고객이름: %s\n", temp->customer_name);
	printf("고객나이: %d\n", temp->age);
	printf("고객주소: %s\n", temp->customer_address);
	printf("딜러이름: %s\n", temp->dealer[0]->company_name);
	printf("차량이름: %s\n", temp->rental[0]->car_name);
	printf("차량소유회사: %s\n", temp->rental[0]->company_name);
	//고객의 수정 삭제 조회는 관리자 모드에서 만들고
	//차량 풀에서의 삭제 조회는 관리자 모드에서 가능하게 만들자

	//차량의 수정 삭제 조회는 딜러가 가능 하게 구현
	//지금은 배열 형식인 자료 구조를 연결리스트로 바꿔보자
	allocation_random_car_Link_ver(&car_list, &dealer_list);
	Print_doubly_node(dealer_list.ary_of_dealer[0]->head_node);
	Print_doubly_node(dealer_list.ary_of_dealer[1]->head_node);
	Print_doubly_node(dealer_list.ary_of_dealer[2]->head_node);
	//자동차 매입 메뉴 만들기(업자 자동차 매입 페이지를 하나 만들자)
	//이진파일 읽기 쓰기 함수 만들기	
	
#endif	
	

}