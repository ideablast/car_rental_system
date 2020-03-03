#include"ALL.h"

#ifdef USE_CALLBACK
typedef int(*call_back)(int);
//Call Back함수란 함수가 함수를 인자로 전달 받아서 호출
//함수가 상황에 맞춰서 함수를 호출 하는 형태
int Callback_function(call_back pCallback, int n)//CALLBACK이 함수 포인터 변수인데 typedef로 선언해서 변수 선언시마다 귀찮게 풀포인터 형식으로 쓸 필요가 없다.
{
	return pCallback(n);//아무개 함수에 정수 n을 전달 인자로 넣고 리턴하는 함수.

						//pCallback라는 함수 포인터 자리에 들어온 함수에 정수 n을 전달인자로 주고 리턴
}
int input(int i)
{
	int ar[10];
	int j = 0;
	int sum = 0;
	int min = 999, max = -999;
	for (j = 0; j<i; j++) {
		printf("%d번의 숫자를 입력하시오 :", j + 1);
		scanf("%d", &ar[j]);
		if (ar[j]<min)
			min = ar[j];
		if (ar[j]>max)
			max = ar[j];
		sum = sum + ar[j];
	}
	printf("최대값은 %d, 최소값은 %d 평균은 %d입니다.\n", max, min, sum / j);
	return 0;
}

int modify(int i)
{
	if (i>10)
	{
		printf("숫자를 다시 입력해 주세요. 10까지만 되요 :");
		scanf("%d", &i);
		return modify(i);
	}
	else
		return i;
}

void max_min_sum_avg()
{
	int i;
	printf("몇명 까지의 정보(최대값,최소값,합,평균)를 원하십니까? ");
	scanf("%d", &i);
	i = Callback_function(modify, i);//Call Back function을 숫자의 범위를 정하는 부분과 값을 입력 받는 부분에서 사용하고 있다.
	Callback_function(input, i);
	_getch();
}

int CallBackFunc(char *pszData1, char *pszData2)
{
	//return strcmp(pszData1, pszData2);
	return strcmp(pszData2, pszData1);
}

void TestFunc(int nCount, char* apszData[], int(*pfCallBack)(char*, char*))
{
	char *pszTmp = NULL;
	int i = 0, j = 0;
	for (i = 0; i < nCount - 1; ++i)
	{
		for (j = i + 1; j < nCount; ++j)
		{
			if (pfCallBack(apszData[i], apszData[j]) > 0)
			{
				pszTmp = apszData[i];
				apszData[i] = apszData[j];
				apszData[j] = pszTmp;
			}
		}
	}
}

void activate()
{
	int i = 0;
	char *aszData[3] = { "유재석", "박명수", "정형돈" };
	TestFunc(3, aszData, CallBackFunc);

	for (i = 0; i < 3; ++i)
	{
		puts(aszData[i]);
	}
}
#endif
