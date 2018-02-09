#include<iostream>
#include<vector>

using namespace std;


/*

 [6 1 3 5 8 4 9 2]
  
 [ 6 1 3 5]      [ 8 4 9 2]  
  
 [6 1] [ 3 5]    [ 8 4 ] [ 9 2 ]
 
 [6] [1] [3] [5]  [8] [4]  [9] [2] 


1) Merge Sort is stable sort
2) Merge Sort is not in place and has space complexity of O(n)
3) Merge Sort takes worst case time complexity of O(nlogn)

*/



// merge 2 sorted arrays
void merge(vector<int> &a,const  vector<int> &left,const vector<int> &right)
{
    int l=0,r=0,k=0;
    int lSize = left.size();
    int rSize = right.size();
    int aSize = a.size();

    while((l<lSize) && (r < rSize))
    {
        if(left[l] <= right[r])
        {
            a[k] = left[l];
           l++; 
        }
        else
        {
            a[k] = right[r];
            r++; 
        }
        k++;
    }

    while(l < lSize)
    {
       a[k] = left[l];
       k++;l++; 
    }

    while(r < rSize)
    {
       a[k] = right[r];
       k++;r++; 
    }
}

void pVector(const vector<int> &a)
{
  cout << "[ "; 
  for(int i = 0;i<a.size();i++)
  {
     cout << a[i] << " ";
  }
  cout << " ] " << endl;
}


void mergeSort(vector<int> &a)
{
    int aSize = a.size();
    int middle = aSize/2;

    if(aSize < 2){
    return;
    }
    pVector(a);
    vector<int> left(a.begin(),a.begin()+middle); // [first,last) last is not included
    vector<int> right(a.begin()+middle, a.begin()+aSize); 
    mergeSort(left);
    mergeSort(right);
    merge(a,left,right);
    pVector(a);
}


int main()
{
 vector<int> a = {8,3,9,1,10,11,5,2,6,4,7,12};
 mergeSort(a);
 cout << "Result" << endl;
 pVector(a); 
 return 0;
}
