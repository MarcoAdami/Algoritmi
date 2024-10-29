#include <iostream>
#include <vector> //#include <bits/stdc++.h> // use in terminal std=c++11
#include <fstream>
using namespace std;



void mergesort(vector<int>& arr, int start, int middle, int end)
{

    if (end - start >= 2)
    {
        mergesort(arr, start, (middle + start) / 2, middle);
        mergesort(arr, middle, (middle + end) / 2, end);

        int la = middle - start;
        int lb = end - middle;
        vector<int> A;
        vector<int> B;

        for (int i = start; i < middle; ++i)
        {
            A.push_back(arr[i]);
        }
        for (int i = middle; i < end; ++i)
        {
            B.push_back(arr[i]);
        }
        
        int i = start;
        int j = 0;
        int k = 0;

        while(j<la || k<lb){
            if ((A[j] <= B[k] && j<la) || k>=lb)
            {
                arr[i] = A[j];
                j++;
            }
            else
            {
                arr[i] = B[k];
                k++;
            }
            i++;
        }
    }
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        in >> arr[i];
    }

    mergesort(arr, 0, n / 2, n);

    for (int i = 0; i < n; ++i)
    {
        out << arr[i] << " ";
    }

    return 0;
}