#include<iostream>
#include<string>

using namespace std;

// Alpha Numeric characters are acceptable
// Skip non Alpha Numeric Characters

bool isPalindrome(const string A)
{
 int i = 0,j = A.size() - 1;
 while(i<j)
 {
    if(!isalnum(A[i])) i++;
    if(!isalnum(A[j])) j--;
    if(tolower(A[i]) == tolower(A[j]))
    {
        i++;j--;
    }
    else { return false; }
 }
 return true;
}

int main()
{
 string A = "1madam1";
 string B = "mada";
 cout << A << " isPalindrome= " << isPalindrome(A) << endl;
 cout << B << " isPalindrome= " <<  isPalindrome(B) << endl;
}
