#include<iostream>
#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int main()
{
    int arr[61];
    // cout<<sin(6)<<endl;
    for(int i =0 ;i<4;i++)
    {
        for(int j =0 ;j<15;j++)
        {
            arr[i*15+j] = 512+511*sin((3.1415/180)*j*6);
        }
    }

    for(int i =0;i<60;i++)
    {
        cout<<"sine"<<i*6<<": "<<arr[i]<<endl;
    }
    return 0;
}