#include<iostream>
#include<vector>
#include<random>

using namespace std;

/*
1) Quick Sort is not a stable sort
2) Quick Sort is in place sort and has space complexity of O(1).
3) Quick Sort takes worst case time complexity of O(n^2) , but this can be mitigated by randomizing the selection of pivot element.
Average case complexity is O(nlogn)

T(n) = 2T(n/2) + c;
T(1) = c;
*/

int partition(vector<int> &a,int start, int end)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(start,end); // define the range
    int pSelect = distr(eng);
    cout << "pSelect," << pSelect << endl;
    int pivot = a[pSelect];
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
