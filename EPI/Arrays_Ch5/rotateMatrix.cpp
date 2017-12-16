#include<iostream>
#include<vector>
#include "arrUtil.h"

using namespace std;

void rotateElement(vector<vector<int>> &M,int iStart,int jStart,int n,int offset)
{
 cout << "rotateElement iStart,"<<iStart<<",jStart,"<<jStart<<",n,"<<n<<",offset,"<<offset<<endl;
 int i = iStart,j = jStart;

 // Inc Col
 int nextJ = jStart + (n - 1 - offset);
 int nextI = iStart + offset;
 int temp  = M[nextI][nextJ];
 M[nextI][nextJ] = M[i][j];
 cout <<"Move "<< M[i][j] << "to " << "nextI,"<<nextI<<",nextJ,"<<nextJ<<endl;
 
 // Inc Row
 nextI = nextI + (n - 1 - offset);
 nextJ = nextJ - offset;
 int temp2  = M[nextI][nextJ];
 M[nextI][nextJ] = temp;
 cout <<"Move "<< temp << "to " << "nextI,"<<nextI<<",nextJ,"<<nextJ<<endl;

 // Dec Col
 nextJ = nextJ - (n-1-offset);
 nextI = nextI - (offset);
 temp = M[nextI][nextJ];
 M[nextI][nextJ] = temp2;
 cout <<"Move "<< temp2 << "to " <<"nextI,"<<nextI<<",nextJ,"<<nextJ<<endl;

 // Dec Row
 nextI = nextI - (n-1-offset);
 nextJ = nextJ + offset;
 M[nextI][nextJ] = temp;
  cout <<"Move "<< temp<< "to "<< "nextI,"<<nextI<<",nextJ,"<<nextJ<<endl;
}

void rotateMatrixElements(vector<vector<int>> &M,int iStart,int jStart,int n)
{
 int offset = 0;
 cout << "rotateMatrixElements iStart,"<<iStart<<",jStart,"<<jStart<<",n,"<<n<<endl;
 if(n == 2)
 {
   rotateElement(M,iStart,jStart,n,offset);
   return;
 }

 for(int j = jStart;j<=(jStart+(n-1)-1);j++)
 {
	rotateElement(M,iStart,j,n,offset);
 	offset++;
 }

}

void rotateMatrix(vector<vector<int>> &M)
{
 int n = M.size();
 int m = M[0].size();
 int level = 0;
 cout << "rotateMatrix n,"<<n<<",m,"<<m<< endl;

 if(n != m)
 return;

 // Travese levels (i.e SubMatrices) 
 for(int i = n; i>1;i=i-2)
 {
   rotateMatrixElements(M,level,level,i);
   level++;
 } 
}

void printM(const vector<vector<int>> &M)
{
        int n = M.size();
        int value;
        cout << "printM n," << n << endl;
        for(int i = 0;i<n;i++)
        {
         for(int j = 0;j<n;j++)
         {
           value =  M[i][j];
 	   cout << value << " ";
         }
         cout << endl;
        }
        cout << endl;
}

int main()
{
 vector<vector<int>> M1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
 vector<vector<int>> M2 = {{1,2,3},{4,5,6},{7,8,9}};
 vector<vector<int>> M3 = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
 rotateMatrix(M1);
 rotateMatrix(M2);
 rotateMatrix(M3);
 printM(M1);
 printM(M2);
 printM(M3);
}
