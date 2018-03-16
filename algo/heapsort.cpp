#include <bits/stdc++.h>
using namespace std;
#define Max 100
int h[Max];
int size;
int parent(int i){return i/2;}
int leftchild(int i){return 2*i;}
int rightchild(int i){return 2*i+1;}
void shiftup(int i)
{
	while(i>1&&h[parent(i)]<h[i])
	{
		swap(h[parent(i)],h[i]);
		i=parent(i);
	}
}
void shiftdown(int i)
{
	int idx=i;
	int l=leftchild(i);
	if(l<=size&& h[l]>h[idx])
		idx=l;
	int r=rightchild(i);
	if(r<=size&& h[r]>h[idx])
		idx=r;
	if(i!=idx){
		swap(h[i],h[idx]);
		shiftdown(idx);
	}
}
void insert(int n)
{
	if(size==Max)return;
	size++;
	h[size]=n;
	shiftup(size);
}
int extractmax()
{
	int ret=h[1];
	h[1]=h[size];
	size--;
	shiftdown(1);
	return ret;
}

int main() {
	int n;cin>>n;
	size=1;
	for(int i=0;i<n;i++)
	{
		int x;cin>>x;
		insert(x);
	}
	int sorted[n];
	for(int i=0;i<n;i++)
	{
		sorted[i]=extractmax();
		cout<<sorted[i]<<' ';
	}
	return 0;
}