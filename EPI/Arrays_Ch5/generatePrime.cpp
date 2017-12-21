#include<iostream>
#include<vector>
#include<array>
#include<cmath> // for sqrt
#include "arrUtil.h" // for printVector

using namespace std;

// Time Complexity  : O(n* n^1/2) i.e O(n^3/2)
// Space Complexity : O(n) 
void generatePrime(vector<int> &prime, int n)
{
 bool isPrime = true;
 for(int i=2;i<=n;i++)
 {
   isPrime = true;
   for(int j=2;j<=sqrt(i);j++)
   {
	if((i%j) == 0)
        {
		isPrime = false;
		break;
        }
   }
   if(isPrime)
   {
	prime.push_back(i);
   }
 } 
}

// Time Complexity  : O(nloglogn) [ n/2 + n/3 + n/5 + n/7 + ....]
// Space Complexity : O(n)
void generatePrimeImproved(vector<int> &prime, int n)
{
 int size = n+1;
 vector<bool> trackPrimes(size,true);

 trackPrimes[0] = false; trackPrimes[1] = false;
 for(int i=2;i<=size;i++)
 {
	if(trackPrimes[i] == true)
        {
		prime.push_back(i);
        	for(int j = 2*i;j<size;j+=i)
        	{
			trackPrimes[j] = false;
		}
        }

 }
}

int main()
{
  vector<int> Primes;
  generatePrime(Primes,18);
  printVector(Primes);
  Primes.erase(Primes.begin(),Primes.end());
  generatePrimeImproved(Primes,18);
  printVector(Primes);
  return 0;
}
