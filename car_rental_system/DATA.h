#pragma once

#define TRUE 1
#define FALSE 0
#define NONE -1

#define NAME_MAX 11
#define CONTACT_NUMBER_MAX 14
#define MAX_RAND_CAR 300
#define DEALER_MAX 100
#define MAX_RAND_CUSTOMER 100

//#�� ##������ Ȱ�� ����
#define STRING(a) #a
#define PASTER(a, b)  a##b



#ifndef __DATA_H__
#define __DATA_H__
/*�ڵ��� �̸�*/


/*�ڵ��� ���� ����*/
typedef enum {S,M,L,RV,SUV}CAR_TYPE;
typedef enum {DISEL,GASOLINE,LPG}FUEL_TYPE;
typedef enum {HIGH_10,HIGH_8,MID,LOW}AMOUNT_OF_FUEL;
typedef enum {GOOD,NOMAL,BAD}CAR_STATUS;
typedef enum {PLATINUM,DIAMOND,GOLD,BASIC}TYPE_OF_INSURANCE;
//char *owner_list[3] = { "��ī","KB������","�׸�ī" };

/*������ �����Ͱ� ������ �ٴ� ���� ����ü*/
//����ü ������ ����ü ���� ����
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
	struct _DEALER **company_info;//�����ϰ� �ִ� ����
	struct _CUSTOMER **customer_info;//������ �� �̸�
	char *period;
	char *car_name;
	int id;
	CAR_TYPE car_type;
	FUEL_TYPE fuel_type;
	AMOUNT_OF_FUEL amount_of_fuel;
	CAR_STATUS car_status;
	char *rental_history; 

}CAR;// �ڵ����� �������� �ٽ� ����

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

/*�� �������� ����Ʈ ���� ����ü*/
//�ּҰ��� ���ٴϷ��� **���� ������ �ʿ�


#endif
