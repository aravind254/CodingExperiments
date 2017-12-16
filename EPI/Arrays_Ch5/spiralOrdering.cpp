#include<iostream>
#include<vector>
#include "arrUtil.h"
#include<unordered_map>
#include<array>
#include <utility> 

using namespace std;

enum class DOT
{
 colInc,
 rowInc,
 colDec,
 rowDec
};

DOT updateDOT(int i,int j,int n,int level)
{
 DOT doTIndex;
 int mSize = n-(level*2);
 int iStart = level;
 int jStart = level;
 cout << "mSize = " << mSize << endl;
 cout << "iStart = " << iStart << endl;
 cout << "jStart = " << jStart << endl;
 cout << "i = " << i << endl;
 cout << "j = " << j << endl;
  

 if((i == iStart) && (j < (mSize-1+level)))
 {
	doTIndex = DOT::colInc ;
 }
 else if((j == (mSize-1+level)) && (i < (mSize-1+level)))
 {
	doTIndex = DOT::rowInc;
 }
 else if((j > jStart) && (i == (mSize-1+level)))
 {
	doTIndex = DOT::colDec;
 }
 else if((j == jStart) && (i > iStart))
 {
	doTIndex = DOT::rowDec;
 }

 return doTIndex;
}

inline unsigned int keyGen(int i,int j) {return ((unsigned int)(i << 16) |(unsigned int) j);}



// Alternative Algo : n-1 elements from first row, n-1 elements from last column,n-1 elements in reverse order from last row, n-1 elements in reverse order in first colum
// Repeat this for next level.
// Time Complexity : O(n^2)
// Space Complexity : O(1)

// Time Complexity : O(n^2)
// Space Complexity : O(n^2). This can be improved to O(1), if we can overrwrite M.
vector<int> spiralOrdering(const vector<vector<int>> &M)
{
 int i=0,j=0,n = M.size(),m = M[0].size();
 DOT dotIndex;
 int level = 0;
 int maxElements = n*m;
 int key =-1; 
 
 unordered_map<unsigned int,bool> vMap;

 vector<int> result;
 
 if(n != m)
 return result;
 

 result.assign(0,n*m);


 // If Visited Cell is next, then change the level if level is available
 while(((n - (2*level)) > 0) && (vMap.size() < maxElements))
 {
     if(vMap.find(keyGen(i,j)) != vMap.end())
     {
	     level++;
             i = level;
 	     j = level;
	     continue;
     }

     result.emplace_back(M[i][j]);
     vMap[keyGen(i,j)] = true;
     cout << "Visiting i,"<<i<<",j,"<<j<<endl;
    
     // update i,j depending on doT
     dotIndex = updateDOT(i,j,n,level);
     switch(dotIndex)
    {
        case DOT::rowInc:
        i++;
        break;

        case DOT::colInc:
        j++;
        break;

        case DOT::rowDec:
        i--;
        break;

        case DOT::colDec:
        j--;
        break;

        default:
        cout << "Unexpected dOT" << endl;
        break;
    }
}
 cout << "level = " << level << endl;
 return result;
}
 
int main()
{
 vector<vector<int>> M1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
 vector<vector<int>> M2 = {{1,2,3},{4,5,6},{7,8,9}};
 vector<vector<int>> M3 = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}}; 
 vector<int> result1 = spiralOrdering(M1); 
 printVector(result1);
 vector<int> result2 = spiralOrdering(M2); 
 printVector(result2);
 vector<int> result3 = spiralOrdering(M3); 
 printVector(result3);
}
