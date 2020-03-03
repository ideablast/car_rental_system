#include"ALL.h"

#ifdef USE_CALLBACK
typedef int(*call_back)(int);
//Call Back�Լ��� �Լ��� �Լ��� ���ڷ� ���� �޾Ƽ� ȣ��
//�Լ��� ��Ȳ�� ���缭 �Լ��� ȣ�� �ϴ� ����
int Callback_function(call_back pCallback, int n)//CALLBACK�� �Լ� ������ �����ε� typedef�� �����ؼ� ���� ����ø��� ������ Ǯ������ �������� �� �ʿ䰡 ����.
{
	return pCallback(n);//�ƹ��� �Լ��� ���� n�� ���� ���ڷ� �ְ� �����ϴ� �Լ�.

						//pCallback��� �Լ� ������ �ڸ��� ���� �Լ��� ���� n�� �������ڷ� �ְ� ����
}
int input(int i)
{
	int ar[10];
	int j = 0;
	int sum = 0;
	int min = 999, max = -999;
	for (j = 0; j<i; j++) {
		printf("%d���� ���ڸ� �Է��Ͻÿ� :", j + 1);
		scanf("%d", &ar[j]);
		if (ar[j]<min)
			min = ar[j];
		if (ar[j]>max)
			max = ar[j];
		sum = sum + ar[j];
	}
	printf("�ִ밪�� %d, �ּҰ��� %d ����� %d�Դϴ�.\n", max, min, sum / j);
	return 0;
}

int modify(int i)
{
	if (i>10)
	{
		printf("���ڸ� �ٽ� �Է��� �ּ���. 10������ �ǿ� :");
		scanf("%d", &i);
		return modify(i);
	}
	else
		return i;
}

void max_min_sum_avg()
{
	int i;
	printf("��� ������ ����(�ִ밪,�ּҰ�,��,���)�� ���Ͻʴϱ�? ");
	scanf("%d", &i);
	i = Callback_function(modify, i);//Call Back function�� ������ ������ ���ϴ� �κа� ���� �Է� �޴� �κп��� ����ϰ� �ִ�.
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
	char *aszData[3] = { "���缮", "�ڸ��", "������" };
	TestFunc(3, aszData, CallBackFunc);

	for (i = 0; i < 3; ++i)
	{
		puts(aszData[i]);
	}
}
#endif
