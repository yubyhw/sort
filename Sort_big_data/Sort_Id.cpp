#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && arr[left] < pivot)
            left++;
        while (right >= left && arr[right] > pivot)
            right--;
        if (left >= right)
            break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

/* Hàm thực hiện giải thuật quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high);

        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    ifstream In;
    ofstream Out;
    int a[30000];
    In.open("D:\\CTDL&GT\\Sort\\Sort_big_data\\List_Id.txt");
    int n = 0;
    while (In >> a[n])
        n++;
    In.close();

    quickSort(a, 0, n - 1);

    Out.open("D:\\CTDL&GT\\Sort\\Sort_big_data\\Id_Sort.txt");  
    int x;
    for (x = 0; x < n; x++)
        Out << a[x] << "\n";
    Out.close();

    cout << "Id is sorted in file Id_Sort.txt" << endl;
}
