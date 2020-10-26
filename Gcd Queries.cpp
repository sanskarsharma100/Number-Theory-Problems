#include<bits/stdc++.h>
using namespace std;
int pre[100001],suf[100001],a[100001];

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int t,n,q,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>a[i];
        pre[0]=suf[n+1]=0;
        for(int i=1;i<=n;i++) pre[i]=gcd(pre[i-1],a[i]);
        for(int i=n;i>=1;i--) suf[i]=gcd(a[i],suf[i+1]);
        while(q--)
        {
            cin>>l>>r;
            cout<<gcd(pre[l-1],suf[r+1])<<endl;
        }
    }
}