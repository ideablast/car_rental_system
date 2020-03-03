#include"ALL.h"

void get_string(char**str_ptr)//���ڿ��� ���̿� ���� �ɵ������� �迭�� �Ҵ� �޸𸮸� �����Ͽ� �Է¹޴� �Լ�
{
	//�޾Ƽ� ���� ����� ������ 
	//���ο��� �Է� ���� ���� �����ϴ� ����� ������?
	unsigned int str_len = 2;//���ڿ��� ���� ������ �����ϰ� �ִ� �迭

	char ch = 0;
	unsigned int cnt = 0;

	*str_ptr = (char*)malloc(str_len * sizeof(char));

	while (ch != '\n')
	{
		if (str_len > cnt)
		{
			ch = getchar();
			*str_ptr[cnt] = ch;
			cnt++;
		}

		else
		{
			str_len += 5;
			*str_ptr = (char*)realloc(*str_ptr, (str_len) * sizeof(char));
		}
	}

	*str_ptr[cnt - 1] = '\0';
	str_len = strlen(*str_ptr);
	*str_ptr = (char*)realloc(*str_ptr, (str_len + 1) * sizeof(char));
	cnt = 0;
	ch = 0;

}

char* get_string_return_ptr()//���ڿ��� ���̿� ���� �ɵ������� �迭�� �Ҵ� �޸𸮸� �����Ͽ� �Է¹޴� �Լ�
{
	//�� ����� ���� �������ϰ� ���� �������� ����?
	//�޾Ƽ� ���� ����� ������ 
	//���ο��� �Է� ���� ���� �����ϴ� ����� ������?

	char *temp;
	unsigned int str_len = 2;//���ڿ��� ���� ������ �����ϰ� �ִ� �迭
	char ch = 0;
	unsigned int cnt = 0;


	temp = (char*)malloc(str_len * sizeof(char));

	while (ch != '\n')
	{
		if (str_len > cnt)
		{
			ch = getchar();
			temp[cnt] = ch;
			cnt++;
		}

		else
		{
			str_len += 5;
			temp = (char*)realloc(temp, (str_len) * sizeof(char));
		}
	}

	temp[cnt - 1] = '\0';
	str_len = strlen(temp);
	temp = (char*)realloc(temp, (str_len + 1) * sizeof(char));
	cnt = 0;
	ch = 0;

	return temp;
}

void clear_buf()//���� ����
{
	while (getchar() != '\n');
}

int get_keyboard()//Ű ���� �޾Ƽ� ��ȯ �Ѵ�
{
	int point;

	while (1)
	{
		point = _getch();
		if (point != 224)
			break;
	}

	return point;
}