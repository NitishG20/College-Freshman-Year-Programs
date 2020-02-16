#include <bits/stdc++.h>
using namespace std;
float geti(int count[], int i)
{
    int c=0, j;
    for(int j=0; i<200; i++)
        if(c+=count[j]>i)
            break;
    return (float)j;
        
}
int activityNotifications(vector <int> expenditure, int d) {
    int count=0, i;
    int c[200];
    float median, median1, median2;
    for(i=0; i<200; i++)c[i]=0;
    for(i=0; i<d; i++)
        c[expenditure[i]]++;
     if(d%2==0)    
     {
         median1=geti(c,d/2);
         cout<<"Median1="<<(int)median1<<endl;
            median2=geti(c, (d/2)-1);
            cout<<"Median2="<<(int)median2<<endl;
            median=(median1+median2)/2;
            cout<<"Median="<<median<<endl;
     }
    
         else
            median=geti(c, (d-1)/2);
        if(expenditure[d]>=2*median)
            count++;
    for(i=d+1; i<expenditure.size(); i++)
    {
        c[expenditure[i-d-1]]--;
        c[expenditure[i-1]]++;
        if(d%2==0)
        { 
            median1=geti(c,d/2);
            median2=geti(c, (d/2)-1);
            median=(median1+median2)/2;
        }
         else
            median=geti(c, (d-1)/2);
        if(expenditure[i]>=2*median)
            count++;
    }
    return count;
    // Complete this function
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> expenditure(n);
    for(int expenditure_i = 0; expenditure_i < n; expenditure_i++){
       cin >> expenditure[expenditure_i];
    }
    int result = activityNotifications(expenditure, d);
    cout << result << endl;
    return 0;
}

