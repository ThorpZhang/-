#include"2048_alg.h"
namespace ManagementSystemV5 {
	int rand0_n_1(int n)        //����һ��С��n�������
	{
		return rand() % n;
	}
	int width(int n)        //���ֿ��
	{
		int k;
		for (k = 0; n; n /= 10)
			k++;
		return k;
	}
	
}