#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &a,int start, int end)
{
    // TBD: Add randomization in picking the pivot to avoid the worst case Time Complexity of O(n^2)
    int pivot = a[end];
    int pIndex = 0,i = 0;
    while(i<end)
    {
       if(a[i] <= pivot)
       {
           swap(a[i],a[pIndex]);
           pIndex++;
       }
       i++;
    }
    swap(a[pIndex],a[end]);
    return pIndex;
}

void QuickSort(vector<int> &a, int start, int end)
{
  if(start < end)
  {
      int pIndex = partition(a,start,end);
      QuickSort(a,start,pIndex-1);
      QuickSort(a,pIndex+1,end);
  }
}


int main()
{
 vector<int> a = {8,3,9,1,10,11,5,2,6,4,7,12};
 QuickSort(a,0,a.size() - 1);
 
 for(int i = 0;i<a.size();i++)
 {
   cout << a[i] << " " ;
 }
 cout << endl;
 return 0;
}
