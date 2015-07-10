#include <iostream>
#include <assert.h>
template <class T>
int partition(T a[], T l, T h)
{
	assert (l<=h);
	T standard = a[l];
	int i=l;
	int j=h;
	while (i<j)
	{
		while(i<j && a[j]>standard) j--;
		a[i] = a[j];
		while(i<j && a[i]<standard) i++;
		a[j] = a[i];
	}
	a[i] = standard;
	return i;
}


template <class T>
void QuickSort(T a[], int l, int h)
{
	int position = 0;
	if (l<h)
	{
		position = partition(a, l, h);
		QuickSort(a, l, position-1);
		QuickSort(a, position+1, h);
	}
}

template <class T>
void print(T a[], int len)
{
	for (int i = 0; i<len; i++)
	{
		std::cout << a[i] << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {1, 3, 4, 8, 2, 6};
	std::cout << "Before sort:" << std::endl;
	print(a, sizeof(a)/sizeof(int));
	std::cout << "after sort:" << std::endl;
	QuickSort(a, 0, sizeof(a)/sizeof(int));
	print(a, sizeof(a)/sizeof(int));

	return 0;
}
