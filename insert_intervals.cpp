#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    cout<<n<<" "<<m<<endl;
    int st[1000], en[1000];

    int st_n[1000], en_n[1000];
    int stt[1000], enn[1000];
    for(int i=0; i<n; i++)
    {
        cin>>st[i];
        cin>>en[i];
    }

    for(int i=0; i<m; i++)
    {
        cin>>st_n[i];
        cin>>en_n[i];
    }


    for(int o=0; o<n; o++)
        cout<<st[o]<<" "<<en[o]<<endl;
    cout<<"-----------------------\n";
    for(int o=0; o<m; o++)
        cout<<st_n[o]<<" "<<en_n[o]<<endl;
            
    //merge all intervals befor start of first one;

    int i = 0, j=0, k=0;
    while(j<m&&i<n)
    {
        // case1          ------------------
        //          ----
        if(en_n[j] < st[i])
        {
            stt[k] = st_n[j];
            enn[k] = en_n[j];
            j++;
            k++;
        }

        // case 2         ---------------
        //                                   --------

        else if(st_n[j] > en[i])
        {
            stt[k] = st[i];
            enn[k] = en_n[i];
            k++;
            i++;
        }

        // case 3          -----------------
        //          ------------

        else if(st_n[j]<st[i] && en_n[j]>st[i] && en_n[j]<en[i])
        {
            st[i] = st_n[j];
            j++;
        }

        // case 4  ------------------
        //                     -----------

        else if(st_n[j]>st[i] && st_n[j]<en[i] && en_n[j] > en[i])
        {
            int l = i;
            en[l] = en_n[j];
            // cout<<"en[j]="<<en[j]<<endl;
            // cout<<"en[l]="<<en[l]<<endl;
            i++;
            while(i<n && en[l]>st[i])
            {
                en[l] = max(en[l], en[i]);
                i++;
            }

            stt[k] = st[l];
            enn[k] = en[l];
            k++;
            j++;
        }

        //case 5  ------------------
        //            ----------
        else if(st[i]<st_n[i] && en[i]>en_n[j]) j++;
        
        // case 6        ----------
        //            ----------------
        else if(st_n[j]<st[i] && en_n[j]>en[i]) i++;
    }

    while(j<m)
    {
        stt[k] = st_n[j];
        enn[k] = en_n[j];
        j++;
    }

    while(i<n)
    {
        stt[k] = st[i];
        enn[k] = en[i];
        i++;
    }

    cout<<"-----------------------\n";

    for(int o=0; o<k; o++)
        cout<<stt[o]<<" "<<enn[o]<<endl;


}