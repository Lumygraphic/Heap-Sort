#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
#include<iostream>
#include <iomanip>

using namespace std;

int hs[100];
//void BuildMaxheap(int A[], int len);
void heapAdjust(int A[], int k, int len);//������������д�ᱨ��
//void heapSort(int A[], int len);



void BuildMaxheap(int A[], int len)//���������
{
	for (int i = len / 2; i > 0; i--)//�����һ����Ҷ��㿪ʼ����������
	{
		heapAdjust(A, i, len);
	}
}

void heapAdjust(int A[], int k, int len)//���������
{
	A[0] = A[k];//A[0]�ݴ��������ڵ�
	for (int i = 2 * k; i <= len; i *= 2)//����A[k]Ϊ�����������е���
	{
		if (i < len && A[i] < A[i + 1])
		{
			i++;
		}
		if (A[0] >= A[i])
		{
			break;
		}
		else
		{
			A[k] = A[i];
			k = i;
		}

	}
	A[k] = A[0];//����ɸѡ����ֵ��������λ��
}

void heapSort(int A[], int len)//������
{
	BuildMaxheap(A, len);//��ʼ����

	for (int i = len; i > 1; i--)//n-1�˽������ѹ���
	{
		swap(A[i], A[1]);//����Ѷ�Ԫ�أ�ͨ���Ͷѵ�Ԫ�ؽ�����
		heapAdjust(A, 1, i - 1);//��������ʣ��i-1��Ԫ������ɶ�
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> hs[i];
	}
	cout << "����ǰ��" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << hs[i];
		if (i != n)
			cout << ",";
	}
	cout << endl;

	BuildMaxheap(hs, n);
	cout << "��һ�ν��ѣ�" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << hs[i];
		if (i != n)
			cout << ",";
	}
	cout << endl;

	heapSort(hs, n);
	cout << "�����" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << hs[i];
		if (i != n)
			cout << ",";
	}
	cout << endl;
	return 0;
}

