#include<stdio.h>
#include<windows.h>



//int test(){
//	static int a = 4;
//	a++;
//	return a;
//}
//
//int main(){
//	
//	
//	
//	//int a = test();
//	//printf("%d\n", a);
//	//int b = test();
//	//printf("%d\n", b);
//	//int i;
//	///*static char str[] = "hello world" ;
//	//printf("%s", str);*/
//	//static char str[10];
//	//printf("integer: %d;  string: (begin)%s(end)", a, str);
//
//	//
//	///*char p[] = "hello world";
//	//for (int i = 0; i < 5; i++){
//	//	printf("%d", i);
//	//	static int a = 4;
//	//}
//	//printf("%d", a);*/
//
//	system("pause");
//	return 0;
//}


void Find_single_num(int arr[], int sz, int*p1, int*p2)
{
	int i = 0;
	int pos = 0;
	int ret = 0;
	//1.�������飬���Ϊ������ͬ�������
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	//Ѱ����������ͬ���������һ��λΪ1��λ
	for (pos = 0; pos < 32; pos++)//����32λ��������32��
	{
		if (((ret >> pos) & 1) == 1)
		{
			break;
		}
	}
	for (i = 0; i < sz; i++)
	{
		//�ҵ�������posλΪ1���������������
		if (((arr[i] >> pos) & 1) == 1)
		{
			*p1 = arr[i];
		}
		//�ҵ�������posλΪ0���������������
		else
		{
			*p2 = arr[i];
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 1, 2, 3, 4, 6, 7 };
	int num1 = 0;
	int num2 = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	Find_single_num(arr, sz, &num1, &num2);
	printf("%d %d\n", num1, num2);
	system("pause");
	return 0;
}