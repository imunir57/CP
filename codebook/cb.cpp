--------------0-1 Knapsack---------------
int n;
int dp[101][1001];
int weight[1001], cost[101];
int cap;
int func(int i,int w)
{
    if(i==n+1)return 0;
    if(dp[i][w]!=-1)return dp[i][w];
    int prof1=0,prof2=0;
    if(w+weight[i]<=cap)
        prof1=cost[i]+func(i+1,w+weight[i]);
    prof2=func(i+1,w);
    dp[i][w]=max(prof1,prof2);
    return dp[i][w];
}
main()
{
    func(1,0);
}
#####################################GRAPH############################################
-----------BFS----------------
-------1D---------------
bool visited[N];
int dist[N];
vi adj[N];
queue<int>q;
void bfs(int root)
{
    q.push(root);
    dist[root]=0;
    visited[root]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        loopv(i,adj[t])
        {
            if(!visited[i])
            {
                visited[i]=1;
                q.push(i);
                dist[i]=dist[t]+1;
            }
        }
    }

}
-----------2D------------------
queue<pii>qi;
bool vis[100][100];
int dis[100][100];
void bfs(int x,int y)
{
    qi.push(mk(x,y));
    vis[x][y]=1;
    dis[x][y]=0;
    while(!qi.empty())
    {
        pii t=qi.front();
        qi.pop();
        loop(i,0,4)
        {
            int nx=x4[i]+t.X;
            int ny=y4[i]+t.Y;
            if(!vis[nx][ny])
            {
                vis[nx][ny]=1;
                dis[nx][ny]=dis[t.X][t.Y]+1;
                qi.push(mk(nx,ny));
            }
        }
    }
}
---------------Dijkstra--------------
int par[N],dist[N];
vi adj[N],cost[N];
int n,m,s,d;
void dijkstra(int s)
{
    loop(i,0,n)par[i]=dist[i]=-1;

    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push(mk(0,s));
    dist[s]=0;
    while(!q.empty())
        {
            pii t=q.top();
            q.pop();
            int u=t.Y;
            for(int i=0; i<adj[u].size(); i++)
                {
                    int v=adj[u][i];
                    if(dist[u]+cost[u][i]<dist[v]||dist[v]==-1)
                        {
                            dist[v]=dist[u]+cost[u][i];
                            par[v]=u;
                            q.push(mk(dist[v],v));
                        }
                }
        }
}
--------------MST-Prims--------------
vector<pii>e[N];
bool vis[N];
int prims()
{
    priority_queue<pii,vector<pii>,greater<pii> >p;
    p.push(mk(0,1)); ///weight,node
    int mst_cost=0;
    while(!p.empty())
    {
        pii t=p.top();p.pop();
        int node=t.Y,cost=t.X;
        if(vis[node])continue;
        mst_cost+=cost;
        vis[node]=1;
        loop(i,0,e[node].size())
        {
            int u=e[node][i].Y;
            if(!vis[u])p.push(e[node][i]);
        }
    }
    return mst_cost;
}
-------------SSC-------------------
vi e[N],dfs_num,dfs_low,s,visited;

int c,scc;
void tarjanSCC(int u)
{
    dfs_low[u]=dfs_num[u]=c++;
    s.pb(u);
    visited[u]=1;
    loop(i,0,e[u].size())
    {
        int v=e[u][i];
        if(!dfs_num[v])tarjanSCC(v);
        if(visited[v])dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_low[u]==dfs_num[u])
    {
        cout<<"SCC "<<++scc<<line;
        while(1)
        {
            int v=s.back();s.pop_back();visited[v]=0;
            cout<<space<<v<<line;
            if(u==v)break;
        }
        cout<<line;
    }

}
int main() {
    int n,edg;cin>>n>>edg;
    loop(i,0,edg)
    {
        int x,y;cin>>x>>y;
        e[x].pb(y);
    }
    dfs_num.assign(N,0),dfs_low.assign(N,0),visited.assign(N,0);
    scc=c=0;
    loop(i,0,n)
        if(!dfs_num[i])tarjanSCC(i);

    return 0;
    }
	
-----------------------BellmanFord------------------------------
vi dist(V, INF); dist[s] = 0;
for (int i = 0; i < V - 1; i++) // relax all E edges V-1 times
for (int u = 0; u < V; u++) // these two loops = O(E), overall O(VE)
for (int j = 0; j < (int)AdjList[u].size(); j++) {
ii v = AdjList[u][j]; // record SP spanning here if needed
dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
}
// after running the O(VE) Bellman Ford’s algorithm shown above
bool hasNegativeCycle = false;
for (int u = 0; u < V; u++) // one more pass to check
for (int j = 0; j < (int)AdjList[u].size(); j++) {
ii v = AdjList[u][j];
if (dist[v.first] > dist[u] + v.second) // if this is still possible
hasNegativeCycle = true; // then negative cycle exists!
}
printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");

----------------------FloydWar------------------------
void floyd(){
    for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			p[i][j] = i; // initialize the parent matrix
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]) {
					AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
					p[i][j] = p[k][j]; // update the parent matrix
	}
	
void printPath(int i, int j) {
	if (i != j) printPath(i, p[i][j]);
	printf(" %d", j);
}
###Transitive Closure
for (int k = 0; k < V; k++)
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			AdjMat[i][j] |= (AdjMat[i][k] & AdjMat[k][j]);
##MiniMax-----
for (int k = 0; k < V; k++)
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			AdjMat[i][j] = min(AdjMat[i][j], max(AdjMat[i][k], AdjMat[k][j]));

#####################################DS############################################
-------------BIT--------------------
int a[N];
int quary(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=a[idx];
        idx-=idx &(-idx);
    }
    return sum;
}
void update(int idx,int x,int n)
{
    while(idx<=n)
    {
        a[idx]+=x;
        idx+=idx & (-idx);
    }

}
---------------SegmentTree----------
int a[N],n;
vi seg;
void build(int p,int l,int r)
{
    if(l==r)seg[p]=a[l];
    else
    {
        int mid=(l+r)/2,left=p*2,right=left+1;
        build(left,l,mid);
        build(right,mid+1,r);
        seg[p]=min(seg[left],seg[right]);
    }
}
int rmq(int p,int l,int r,int i,int j)
{
    if(i>r||j<l)return MOD;
    if(l>=i&&r<=j)return seg[p];
    int mid=(l+r)/2,left=p*2,right=left+1;
    int p1=rmq(left,l,mid,i,j);
    int p2=rmq(right,mid+1,r,i,j);
    return min(p1,p2);
}

int rmq(int i,int j)
{
    return rmq(1,0,n-1,i,j);
}
int main() {

    seg.assign(4*n,0);
    build(1,0,n-1);
    cout<<rmq(0,3);
    return 0;
    }

--------------Trie------------------
struct node
{
    bool endmark;
    node *next[26];
    int c;
    node()
    {
        c=0;
        endmark=0;
        loop(i,0,26)next[i]=NULL;
    }
}*root;

void insert(string str,int len)
{
    node *curr=root;
    loop(i,0,len)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr->c++;
        curr=curr->next[id];
    }
    curr->endmark=1;
}
bool search(string str,int len)
{
    node *curr=root;
    loop(i,0,len)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)return false;
        curr=curr->next[id];
    }
	return curr->endmark;
}
void del(node *curr)
{
    loop(i,0,26)
        if(curr->next[i])
            del(curr->next[i]);
        delete(curr);
}
main(){
	root=new node();
	del(root);
}

---------------KMP------------------
int b[N];

void KMPprocess(char p[],int m)
{
    int i=0,j=-1;
    b[0]=-1;
    while(i<m)
    {
        while(j>=0&&p[i]!=p[j])j=b[j];
        i++;j++;
        b[i]=j;
    }
}

void KMPsearch(char t[],char p[],int n,int m)
{
    KMPprocess(p,m);
    int i=0,j=0;
    while(i<n)
    {
        while(j>=0&&t[i]!=p[j]) j=b[j];
        i++;j++;
        if(j==m)
        {
            cout<<"found at index "<<i-j<<line;
            j=b[j];
        }
    }
}
int main()
{
    char a[]="ACABAABABDABABA";
    char c[]="ABBAA";
    KMPsearch(a,c,strlen(a),strlen(c));
    loop(i,1,6)cout<<b[i]<<space;
}
-------------------MergeSort----------------
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];   /// create temp arrays

    for(i = 0; i < n1; i++) /// Copy data to temp arrays L[] and R[]
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /// Merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];  /// Copy the remaining elements of L[], if there are any

    while (j < n2)
        arr[k++] = R[j++];  /// Copy the remaining elements of R[], if there are any
}



void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
---------------------NumberTheory-----------------------
-------------------------NumDiv---------------------------
ll numDiv(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1; 
	while (PF * PF <= N) {
		ll power = 0; 
		while (N % PF == 0) { N /= PF; power++; }
		ans *= (power + 1);
		PF = primes[++PF_idx];
	}
	if (N != 1) ans *= 2; 
	return ans;
}
-----------------------SumDiv---------------------------
ll sumDiv(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
	while (PF * PF <= N) {
		ll power = 0;
		while (N % PF == 0) { N /= PF; power++; }
		ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
		PF = primes[++PF_idx];
	}
	if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); 
return ans;
}
----------------------EulerPhi--------------------------------
ll EulerPhi(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = N; 
	while (PF * PF <= N) {
		if (N % PF == 0) ans -= ans / PF;
		while (N % PF == 0) N /= PF;
		PF = primes[++PF_idx];
	}
	if (N != 1) ans -= ans / N; 
return ans;
}
------------------ExtendedEuclide------------------------------
int x,y,d;
void extendedEuclid(int a, int b) {
	if (b == 0) { x = 1; y = 0; d = a; return; } 
	extendedEuclid(b, a % b); 
	int x1 = y;
	int y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}
-----------------BitOperation-----------------------------
int s;
turn on j-th bit     s|=(1<<j);
turn off j-th bit     s&=~(1<<j);
check j-th bit is on(t!=0) or off(t=0)    t=s&(1<<j);
flip the j-th bit       s^=(1<<j);
lsb which is on       t=(s&(-s));
power of 2 (s&(s-1))==0
turn off the last bit s&(s-1) 10100->10000
turn on the last bit  s|(s+1) 1010->1011
turn off the last consecutive run of 1's s&(s+1) 100111->100000
turn on the last consecutive run of 0's  s|(s-1) 100100->100111 
