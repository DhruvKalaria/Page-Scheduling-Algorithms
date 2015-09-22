#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>


using namespace std;

int MAX_PAGES=5000;
int FRAMES= 100;
int n; // Total number of pages
int pg[5000]; // Number of Pages
int fr[100],pframe; //frames and the size of frame

void fifo(); //First In First Out Scheduling Algorithm
void lru(); // Least Recently Used Scheduling Algorithm
void optimal(); // Optimal Scheduling Algorithm
void autoinput(); // Generates pseudo random frame numbers

int main()
{
	int ch; //Used for selecting the Algorithm
	cout << "\nEnter size of page frame:";
	cin >> pframe;

	autoinput();

	do
	{
		cout << "\n\tMENU\n";
		cout <<"\n1)FIFO";
		cout <<"\n2)OPTIMAL";
		cout <<"\n3)LRU";
		cout <<"\n4)Exit";
		cout <<"\nEnter your choice:";
		cin >> ch;
		switch(ch)
		{
		case 1: fifo();
		break;
		case 2: optimal();
		break;
		case 3: lru();
		break;
		}
	}
	while(ch!=4);
	return 0;
}

void autoinput()
{

	int rande;
	cout <<"\nEnter total number of pages:";
	cin >> n;
	srand(time(0));

	cout << "\n\n Pages coming in order are: ";
	rande = rand() % 100; // Randomness seed - 100
	for(int i = 0; i < n; i++)
	{
		pg[i]=rande;
		rande = rand() % 100; // Randomness seed - 100
	}


	for(int i = 0 ; i < n; i++)
	{
		cout<<pg[i]<<",";
	}
}

void optimal()	{

	int i;
	int j,flag=0,pf=0;
	int max,lp[MAX_PAGES],index,m;

	// initialize the first row to -1
	for(i=0;i<pframe;i++)
	{
		fr[i]=-1; // initialize the first row to -1
	}

	// Set the first row of size equal to pframe without any modification
/*
	for(j=0;j<pframe;j++)
	{

		fr[j]=pg[j];
		flag=1;
		pf++;
		for(i=0;i<pframe;i++)
		{
			cout << fr[i] << "	";
		}
		cout << endl;
	}
*/

	for(j=0;j<n;j++)
	{
		flag=0;
		for(i=0;i<pframe;i++)
		{
			if(fr[i]==pg[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			for(i=0;i<pframe;i++)
				lp[i]=0;
			for(i=0;i<pframe;i++)
			{
				for(m=j+1;m<n;m++)
				{
					if(fr[i]==pg[m])
					{
						lp[i]=m-j;
						break;
					}
				}
			}
			max=lp[0];
			index=0;
			for(i=0;i<pframe;i++)
			{
				if(lp[i]==0)
				{
					index=i;
					break;
				}
				else
				{
					if(max<lp[i])
					{
						max=lp[i];
						index=i;
					}
				}
			}
			fr[index]=pg[j];
			pf++;
			for(i=0;i<pframe;i++)
			{
				cout << fr[i] << "	 ";
			}
			cout << endl;
		}
	}
	cout << "page faults:" << pf;
}

void fifo()
{
	int i,f,r,s,count,flag,num;
	f=0;
	r=0;
	s=0;
	flag=0;
	count=0;
	for(i=0;i<pframe;i++)
	{
		fr[i]=-1;
	}
	cout <<"The pages in Frame\n";
	while(s<n)
	{
		flag=0;
		num=pg[s];
		for(i=0;i<pframe;i++)
		{
			if(num==fr[i])
			{
				s++;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			if(r<pframe)
			{
				fr[r]=pg[s];
				r++;
				s++;
				count++;
			}
			else
			{
				if(f<pframe)
				{
					fr[f]=pg[s];
					s++;
					f++;
					count++;
				}
				else
					f=0;
			}
		}
		cout << endl;

		for(i=0;i<pframe;i++)
		{
			cout << fr[i] << "	";
		}
	}
	cout << "\nPage Faults=" << count;
}

void lru()
{
	int q[MAX_PAGES],c=0,c1,i,j,k=0,r,t,b[100],c2[100];
	q[k]=pg[k];
	cout << "\n		" << q[k] << endl;
	c++;
	k++;
	for(i=1;i<n;i++)
	{
		c1=0;
		for(j=0;j<pframe;j++)
		{
			if(pg[i]!=q[j])
				c1++;
		}
		if(c1==pframe)
		{
			c++;
			if(k<pframe)
			{
				q[k]=pg[i];
				k++;
				for(j=0;j<k;j++)
					cout << "	" << q[j] << endl;
			}
			else
			{
				for(r=0;r<pframe;r++)
				{
					c2[r]=0;
					for(j=i-1;j>=0;j--)
					{
						if(q[r]!=pg[j])
							c2[r]++;
						else
							break;
					}
				}
				for(r=0;r<pframe;r++)
					b[r]=c2[r];
				for(r=0;r<pframe;r++)
				{
					for(j=r;j<pframe;j++)
					{
						if(b[r]<b[j])
						{
							t=b[r];
							b[r]=b[j];
							b[j]=t;
						}
					}
				}
				for(r=0;r<pframe;r++)
				{
					if(c2[r]==b[0])
						q[r]=pg[i];
					cout << "	" << q[r];
				}
				cout << endl;
			}
		}
	}
	cout << "\nThe no of page faults is=" << c;
}