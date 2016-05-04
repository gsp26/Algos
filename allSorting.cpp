#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> a)
{
    for(int i=0;i<a.size();i++)
        cout << a[i] <<  " ";
    cout << "\n\n";
}


void selectionSort(vector<int> &a)
{
    int n = a.size();
    for(int i=0;i<n-1;i++)
    {
        int imin = i;
        for(int j = i+1;j<n;j++)
        {
            if(a[j] < a[imin])
                imin = j;
        }
        int temp = a[i];
        a[i] = a[imin];
        a[imin] = temp;
    }

}

void insertionSort(vector<int> &a)
{
    int n = a.size();
    for(int i = 0;i<n-1;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

}

void bubbleSort(vector<int> &a)
{
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        bool flag = false;
        for(int j=0;j<n-i-2;j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = true;
            }
        }
        if(!flag)
            break;
    }

}
            
void Merge(vector<int> left,vector<int> right , vector<int> &a)
{
    int nl = left.size();
    int nr = right.size();
    int i=0,j=0,k=0;
    while(i< nl && j < nr)
    {
        if(left[i] <= right[j])  a[k++] = left[i++];
        else a[k++] = right[j++];
    }
    while(i<nl)
        a[k++]=left[i++];
    while(j<nr)
        a[k++] = right[j++];
}
void mergeSort(vector<int> &a)
{
    int n = a.size();
    if(n<2)
        return;
    int mid = n/2;
    vector<int> left;
    vector<int> right;
    for(int i = 0;i<mid;i++)
        left.push_back(a[i]);
    for(int i = mid;i<n;i++)
        right.push_back(a[i]);
    mergeSort(left);
    mergeSort(right);
    Merge(left,right,a);
}

int partition(vector<int> &a, int start, int end)
{
    int pvt = a[end];
    int pIndex = start;
    for(int i = start ; i < end;i++)
    {
        if(a[i] <=pvt)
        {
            int temp = a[i];
            a[i] = a[pIndex];
            a[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = a[end];
    a[end] = a[pIndex];
    a[pIndex] = temp;
    return pIndex;
}   

void quickSort(vector<int> &a,int start, int end)
{
    if(start<end)
    {
        int pIndex = partition(a,start,end);
        quickSort(a,start,pIndex-1);
        quickSort(a,pIndex+1,end);
    }
}

int main()
{
    cout << "All Sorting algorithms " << endl;
    vector<int> a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(1);
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    a.push_back(3);
    a.push_back(12);
    a.push_back(112);
    cout <<"Original vector: " << endl;
    print(a);

    cout<<"after quickSort" << endl;
    quickSort(a,0,a.size()-1);
    print(a);


    cout<<"after Selection Sort" << endl;
    selectionSort(a);
    print(a);


    cout<<"after bubbleSort" << endl;
    bubbleSort(a);
    print(a);


    cout<<"after insertionSort" << endl;
    insertionSort(a);
    print(a);

    cout<<"after mergeSort" << endl;
    mergeSort(a);
    print(a);





    return 0;
}


