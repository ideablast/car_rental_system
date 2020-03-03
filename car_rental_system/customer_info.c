#include"ALL.h"
void input_zero(char*temp, int i)
{
	int idx = 0;
	for (idx = i; idx < 4; idx++)
		temp[idx] = '0';
	temp[idx] = '\0';
}

//8글자의 임의의 알파벳을 생성
char* make_rand_pw()
{
	int rand_num;
	char temp[9] = { 0 };
	char *pw;
	int i;

	for (i = 0; i < 8; i++)
	{
		while (1)
		{
			rand_num = rand() % 58 + 65;//65~122
			if (rand_num <= 90 || rand_num >= 97)
				break;
		}

		temp[i] = (char)rand_num;
	}
	pw = (char*)malloc(9 * sizeof(char));
	memset(pw, 0, 9);
	strcpy(pw, temp);

	return pw;
}

char* make_rand_contact()
{
	char *contact_number;
	char con_0[] = "010";
	char temp_1[5];
	char temp_2[5];
	int num_1, num_2;

	num_1 = rand() % 10000;
	num_2 = rand() % 10000;
	itoa(num_1, temp_1, 10);
	input_zero(temp_1, strlen(temp_1));
	itoa(num_2, temp_2, 10);
	input_zero(temp_2, strlen(temp_2));

	contact_number = (char*)malloc(12 * sizeof(char));
	memset(contact_number, 0, 12);
	strcat(contact_number, con_0);
	strcat(contact_number, temp_1);
	strcat(contact_number, temp_2);

	return contact_number;
}

void make_rand_info_customer()
{
	FILE *fp;
	int i;
	int id, name, addr, age;
	char *pw;
	char *contact;

	fp = fopen("customer_save.txt", "w");

	for (i = 0; i < MAX_RAND_CUSTOMER; i++)
	{
		id = i;
		name = rand() % 35;
		addr = rand() % 23;
		age = rand() % 70 + 20;
		contact = make_rand_contact();
		pw = make_rand_pw();
		fprintf(fp, "%d %d %d %d\n", id, name, addr, age);
		fprintf(fp, "%s\n", contact);
		fprintf(fp, "%s\n", pw);
	}

	fclose(fp);
}


void file_read_customer_info(LIST_OF_CUSTOMER *customer_list)
{
	FILE *fp;
	int id, name, addr, age;
	char contact[12] = { 0 };
	char pw[9] = { 0 };
	fp = fopen("customer_save.txt", "r");

	while (!feof(fp))
	{
		fscanf(fp, "%d %d %d %d", &id, &name, &addr, &age);
		fscanf(fp, "%s", contact);
		fscanf(fp, "%s", pw);
		load_customer_info(customer_list, id, name, addr, age, contact, pw);
	}
	fclose(fp);
}


void load_customer_info(LIST_OF_CUSTOMER *customer_list,int id, int name, int addr,  int age, char *contact, char* pw)
{
	//history, insurance, rental은 메뉴에서 직접 넣을것!
const char *customer_name_list[35] = { "박지안","최지안","이지안","김지안","최서아","박서아","김서아","이서아","황하윤","최하윤","박하윤","김하윤","이하윤","최서윤","박하은","서하린","신서연","신수아","강지우","강지유","김시아","이서현","박다은","김소율","박민서","이유주","조혜련","이예린","박유서","최새하","이유아","길소윤","조은서","조유나","황소윤" };
const char *addr_list[23] = { "강서구","오정구","소사구","양천구","구로구","금천구","영등포구","관악구","동작구","마포구","서대문구","종로구","성북구","강북구","용산구","서초구","강남구","송파구","광진구","중랑구","도봉구","노원구","강동구" };

if (customer_list->num_of_customer == 0)
customer_list->ary_of_customer = (CUSTOMER**)malloc((customer_list->num_of_customer + 1) * sizeof(CUSTOMER*));
else
customer_list->ary_of_customer = (CUSTOMER**)realloc(customer_list->ary_of_customer, (customer_list->num_of_customer + 1) * sizeof(CUSTOMER*));

customer_list->ary_of_customer[customer_list->num_of_customer] = (CUSTOMER*)malloc(sizeof(CUSTOMER));
customer_list->ary_of_customer[customer_list->num_of_customer]->id = id;
customer_list->ary_of_customer[customer_list->num_of_customer]->dealer = (DEALER**)malloc(sizeof(DEALER*));
customer_list->ary_of_customer[customer_list->num_of_customer]->rental = (CAR**)malloc(sizeof(CAR*));

customer_list->ary_of_customer[customer_list->num_of_customer]->customer_name = (char*)malloc((strlen(customer_name_list[name]) + 1) * sizeof(char));
strcpy(customer_list->ary_of_customer[customer_list->num_of_customer]->customer_name, customer_name_list[name]);

customer_list->ary_of_customer[customer_list->num_of_customer]->contact_number = (char*)malloc((strlen(contact) + 1) * sizeof(char));
strcpy(customer_list->ary_of_customer[customer_list->num_of_customer]->contact_number, contact);

customer_list->ary_of_customer[customer_list->num_of_customer]->pw = (char*)malloc((strlen(pw) + 1) * sizeof(char));
strcpy(customer_list->ary_of_customer[customer_list->num_of_customer]->pw, pw);

customer_list->ary_of_customer[customer_list->num_of_customer]->customer_address = (char*)malloc((strlen(addr_list[addr]) + 1) * sizeof(char));
strcpy(customer_list->ary_of_customer[customer_list->num_of_customer]->customer_address, addr_list[addr]);

customer_list->ary_of_customer[customer_list->num_of_customer]->age = age;


customer_list->num_of_customer++;
}




