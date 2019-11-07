#include<bits/stdc++.h>

using namespace std;

#define MAXX 10000
typedef long long ll;

ll n, m, sr, sc, tr, tc;
ll xmax, ymax, xmin, ymin;
ll dp[MAXX][MAXX];
bool visited[MAXX][MAXX];
map<pair<ll, ll>, vector<ll>> s;

bool isinvalid(ll r, ll c)
{
    return (r>xmax || r<xmin || c>ymax || c<ymin); 
}

ll rec(ll r, ll c)
{
    if(dp[r][c] != -1) return dp[r][c];
    ll minn = abs(tr-r) + abs(tc-c);

    if(s.find({r,c}) != s.end())
    {
        ll x = s[{r,c}][0];
        ll y = s[{r,c}][1];
        ll z = s[{r,c}][2];

        if(!visited[x][y])
        {
            visited[x][y] = true;
            minn = min(minn, rec(x,y)+z);
            visited[x][y] = false;
        }
    }

    if(r<xmax && !visited[r+1][c]) {visited[r+1][c] = true; minn = min(minn, 1 + rec(r+1, c)); visited[r+1][c] = false;}
    if(c<ymax && !visited[r][c+1]) {visited[r][c+1] = true; minn = min(minn, 1 + rec(r, c+1)); visited[r][c+1] = false;}
    if(r>xmin && !visited[r-1][c]) {visited[r-1][c] = true; minn = min(minn, 1 + rec(r-1, c)); visited[r-1][c] = false;}
    if(c>ymin && !visited[r][c-1]) {visited[r][c-1] = true; minn = min(minn, 1 + rec(r, c-1)); visited[r][c-1] = false;}

    
    dp[r][c] = minn;
    return dp[r][c];
}

int main()
{
    cin>>sr>>sc>>tr>>tc;
    xmax = max(sr, tr);
    ymax = max(sc, tc);

    xmin = min(sr, tr);
    ymin = min(sc, tc);
    cin>>n;
    ll x1,y1,x2, y2,c;
    for(ll i=0; i<n; i++)
    {
        cin>>x1>>y1>>x2>>y2>>c;
        s[{x1,y1}] = {x2,y2, c};
        s[{x2,y2}] = {x1,y1, c};
        xmax = max(xmax, max(x1,x2));
        ymax = max(ymax, max(y1,y2));
        xmin = min(xmin, min(x1, x2));
        ymin = min(ymin, min(y1, y2));
    }

    cout<<"Xmax = "<<xmax<<" XMIN = "<<xmin<<endl;
    cout<<"Ymax = "<<ymax<<" YMIN = "<<ymin<<endl;

    for(ll i=xmin; i<=xmax; i++)
    {
        for(ll j=ymin; j<=ymax; j++)
            dp[i][j] = -1;
    }

    for(ll i=ymin; i<=ymax; i++)
    {
        cout<<i<<" : ";
        for(ll j=xmin; j<=xmax; j++)
            cout<<dp[j][i]<<"\t";
        cout<<endl;
    }
    

    for(ll i=xmin; i<=xmax; i++)
    {
        for(ll j=ymin; j<=ymax; j++)
            visited[i][j] = false;
    }

    for(ll i=xmin; i<=xmax; i++)
    {
        cout<<i<<" : ";
        for(ll j=ymin; j<=ymax; j++)
            cout<<visited[i][j]<<" ";
        cout<<endl;
    }
      

    dp[tr][tc] = 0;
    visited[sr][sc] = true;
    ll ans = rec(sr, sc);
    
    for(ll i=ymin; i<=ymax; i++)
    {
        cout<<i<<" : ";
        for(ll j=xmin; j<=xmax; j++)
            cout<<dp[j][i]<<"\t";
        cout<<endl;
    }

    cout<<"ANSWER = "<<ans<<endl;
    return 0;
}

// test case 1
// 0 0 3 3
// 1
// 1 1 2 2 1


// test case 2
// 0 0 100 100
// 3
// 1 2 120 120 5
// 4 5 120 100 21
// 6 8 150 180 23