#include"ALL.h"

void file_read_dealer_info(LIST_OF_DEALER *dealer_list)
{
	FILE *fp;
	int id,number_of_car;
	char slogan[40] = { 0 };
	char pw[9] = { 0 };

	fp = fopen("dealer_save.txt", "r");

	while (!feof(fp))
	{
		fscanf(fp, "%d%d%s", &id, &number_of_car, pw);
		fgetc(fp);//scanf후 버퍼에 남은 엔터를 없애는것과 같은 기능
		fgets(slogan, sizeof(slogan), fp);
		load_dealer_info(dealer_list, id, number_of_car, slogan, pw);
	}

	fclose(fp);
}


void load_dealer_info(LIST_OF_DEALER *dealer_list, int id, int number_of_car, char *slogan, char *pw)
{
	const char *company_list[3] = { "SK엔카","쏘카","그린카" };

	if (dealer_list->num_of_dealer == 0)
		dealer_list->ary_of_dealer = (DEALER**)malloc((dealer_list->num_of_dealer + 1) * sizeof(DEALER*));
	else
		dealer_list->ary_of_dealer = (DEALER**)realloc(dealer_list->ary_of_dealer, (dealer_list->num_of_dealer + 1) * sizeof(DEALER*));

	dealer_list->ary_of_dealer[dealer_list->num_of_dealer] = (DEALER*)malloc(sizeof(DEALER));

	dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->id = id;

	dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->company_name = (char*)malloc((strlen(company_list[id]) + 1) * sizeof(char));
	strcpy(dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->company_name, company_list[id]);

	dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->pw = (char*)malloc((strlen(pw) + 1) * sizeof(char));
	strcpy(dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->pw, pw);

	dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->num_of_car = number_of_car;
	dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->list_of_car = (CAR**)malloc(number_of_car * sizeof(CAR*));

	dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->slogan = (char*)malloc((strlen(slogan) + 1) * sizeof(char));
	strcpy(dealer_list->ary_of_dealer[dealer_list->num_of_dealer]->slogan, slogan);

	dealer_list->num_of_dealer++;
}