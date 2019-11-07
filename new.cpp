#include<bits/stdc++.h>

using namespace std;



int main()
{
	int n,m;
	cin>>n;
	vector<int> st(1000000, -1);
	vector<int> en(1000000, -1);

	vector<int> st_n(1000000, -1);
	vector<int> en_n(1000000, -1);


	for(int i=0; i<n; i++)
	{
		cin>>st[i];
		cin>>en[i];
	}

	cin>>m;
	for(int i=0; i<m; i++)
	{
		cin>>st_n[i];
		cin>>en_n[i];
	}

	cout<<"Original Interval set"<<endl;
	for(int i=0; i<n; i++)
		cout<<st[i]<<" "<<en[i]<<endl;
	cout<<"Delete Interval set"<<endl;
	for(int i=0; i<m; i++)
		cout<<st_n[i]<<" "<<en_n[i]<<endl;

	int i=0, j=0;
	while(j<m)
	{
		//case 1 :        ----------
		//          ---- 
		if(st[i] >= en_n[j])
			j++;


		//case 2  -----------------
		//                           ----
		else if(en[i]<=st_n[j])
			i++;

		// case 3        -------------------
		//         ------------
		else if(st[i] <= en_n[j] && st[i] > st_n[j] && en_n[j] > st[i] && en_n[j] < en[i])
		{
			st[i] = en_n[j];
			j++;
		}

		// case 4   ----------------------
		//                       ---------------
		else if(st_n[j] > st[i] && st_n[j] < en[i] && en[i] >= st[j] && en[i] < en_n[j])
		{
			en[i] = st_n[j];
			i++;
		}


		//case 5        ------------
		//        ----------------------
		else if(st_n[j] <= st[i] && en_n[j] >= en[i])
		{
			st[i] = -1;
			en[i] = -1;
		}


		//case 6        -------------------
		//                   --------
		else if(st[i]<=st_n[j] && en[i] >= en_n[j])
		{

			for(int k = n-1; k>=i+1; k--)
			{
				st[k+1] = st[k];
				en[k+1] = en[k];
			}

			// cout<<"IN here"<<endl;
			st[i+1] = en_n[j];
			en[i+1] = en[i];
			en[i] = st_n[j];
			
			
			i++;
			j++;
			n++;
		}
	}

	// cout<<"n = "<<n<<endl;
	cout<<"The new interval set is as follows"<<endl;
	for(int i=0; i<n; i++)
	{
		if(st[i] != -1 && en[i] != -1)
			cout<<st[i]<<" "<<en[i]<<endl;
	}


}