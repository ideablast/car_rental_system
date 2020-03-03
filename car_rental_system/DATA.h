#pragma once

#define TRUE 1
#define FALSE 0
#define NONE -1

#define NAME_MAX 11
#define CONTACT_NUMBER_MAX 14
#define MAX_RAND_CAR 300
#define DEALER_MAX 100
#define MAX_RAND_CUSTOMER 100

//#과 ##연산자 활용 연습
#define STRING(a) #a
#define PASTER(a, b)  a##b



#ifndef __DATA_H__
#define __DATA_H__
/*자동차 이름*/


/*자동차 상태 정보*/
typedef enum {S,M,L,RV,SUV}CAR_TYPE;
typedef enum {DISEL,GASOLINE,LPG}FUEL_TYPE;
typedef enum {HIGH_10,HIGH_8,MID,LOW}AMOUNT_OF_FUEL;
typedef enum {GOOD,NOMAL,BAD}CAR_STATUS;
typedef enum {PLATINUM,DIAMOND,GOLD,BASIC}TYPE_OF_INSURANCE;
//char *owner_list[3] = { "쏘카","KB차차차","그린카" };

/*각각의 데이터가 가지고 다닐 정보 구조체*/
//구조체 내부의 구조체 선언 주의
typedef struct _LIST_OF_DEALER {
	int num_of_dealer;
	struct _DEALER **ary_of_dealer;
}LIST_OF_DEALER;

typedef struct _LIST_OF_CUSTOMER {
	int num_of_customer;
	struct _CUSTOMER **ary_of_customer;
}LIST_OF_CUSTOMER;

typedef struct _LIST_OF_CAR {
	int num_of_car;
	struct _CAR **ary_of_car;
}LIST_OF_CAR;

typedef struct _DEALER {
	char *company_name;
	int id;
	char *pw;
	int num_of_car;
	struct _CAR **list_of_car ;
	struct _CAR_LINK *head_node;
	char *slogan;

}DEALER;

typedef struct _CAR {
	struct _DEALER **company_info;//소유하고 있는 딜러
	struct _CUSTOMER **customer_info;//빌려간 고객 이름
	char *period;
	char *car_name;
	int id;
	CAR_TYPE car_type;
	FUEL_TYPE fuel_type;
	AMOUNT_OF_FUEL amount_of_fuel;
	CAR_STATUS car_status;
	char *rental_history; 

}CAR;// 자동차를 기준으로 다시 설계

typedef struct _CUSTOMER {
	char *customer_name;
	char *contact_number;
	char *pw;
	int id;
	int age;
	char *customer_address;
	char *history;

	TYPE_OF_INSURANCE insurance;
	char* duration_start;
	char* duration_end;

	struct _DEALER **dealer;
	struct _CAR **rental;


}CUSTOMER;

typedef struct _CAR_LINK {
	struct _CAR_LINK *L_Next;
	struct _CAR **CUR;
	struct _CAR_LINK *R_Next;
}CAR_LINK;

/*각 데이터의 리스트 관리 구조체*/
//주소값만 들고다니려면 **이중 포인터 필요


#endif
