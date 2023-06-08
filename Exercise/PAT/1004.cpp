#include<cstdio>
using namespace std;
int c[105],ans[105];
bool r[105][105];
int deep,n,m;
void dfs(int root,int depth) {
	if(depth>deep) deep=depth;
	if(c[root]==0) {
		ans[depth]++;
		return;
	}
	for(int i=1;i<=n;i++) {
		if(r[root][i]) {
			dfs(i,depth+1);
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++) {
		scanf("%d",&x);
		scanf("%d",&c[x]);
		for(int j=1;j<=c[x];j++) {
			scanf("%d",&y);
			r[x][y]=1;
		}
	}
	dfs(1,1);
	for(int i=1;i<deep;i++) {
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[deep]);
	return 0;
}

