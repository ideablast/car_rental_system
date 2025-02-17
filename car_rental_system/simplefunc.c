#include"ALL.h"

void get_string(char**str_ptr)//문자열의 길이에 따라서 능동적으로 배열의 할당 메모리를 조절하여 입력받는 함수
{
	//받아서 쓰는 방식이 좋을까 
	//내부에서 입력 받은 것을 리턴하는 방식이 좋을까?
	unsigned int str_len = 2;//문자열의 길이 정보를 저장하고 있는 배열

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

char* get_string_return_ptr()//문자열의 길이에 따라서 능동적으로 배열의 할당 메모리를 조절하여 입력받는 함수
{
	//이 방식이 좀더 안정적일것 같은 느낌적인 느낌?
	//받아서 쓰는 방식이 좋을까 
	//내부에서 입력 받은 것을 리턴하는 방식이 좋을까?

	char *temp;
	unsigned int str_len = 2;//문자열의 길이 정보를 저장하고 있는 배열
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

void clear_buf()//버퍼 비우기
{
	while (getchar() != '\n');
}

int get_keyboard()//키 값을 받아서 반환 한다
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