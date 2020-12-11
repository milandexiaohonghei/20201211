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
	//1.遍历数组，结果为两个不同数的异或。
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	//寻找这两个不同数异或结果的一个位为1的位
	for (pos = 0; pos < 32; pos++)//整型32位，最多遍历32次
	{
		if (((ret >> pos) & 1) == 1)
		{
			break;
		}
	}
	for (i = 0; i < sz; i++)
	{
		//找到数组中pos位为1的数，并进行异或
		if (((arr[i] >> pos) & 1) == 1)
		{
			*p1 = arr[i];
		}
		//找到数组中pos位为0的数，并进行异或
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