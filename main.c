#include<stdio.h>

#define R_MAX 2000
#define C_MAX 200
#define INT_MAX 2100000000

int cost[R_MAX+1][C_MAX+1];
int r_sum[R_MAX+1];
int r,c;

int trans_y(int n){
	return (n==1)?0:1;
}

int dist(int sx, int sy, int ex, int ey){
	return (sy==ey)?cost[ex][ey*(c-1)+1]:cost[ex][ey*(c-1)+1]+r_sum[ex];
}

int shortest(int nx,int ny, int x,int y){
	int di[R_MAX+1][2]={0};
	int xx,yy;
	int check[R_MAX+1][2]={0};
	int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
	int tmp;
	int cnt,flag;

	cnt = r*2;

	for(int i=1;i<=r;i++){
		di[i][0] = INT_MAX;
		di[i][1] = INT_MAX;
	}

	di[nx][trans_y(ny)] = 0;
	while(cnt != 0){
		flag = 0;
		for(int i=1;i<=r;i++){
			for(int j=0;j<1;j++){
				if(check[i][j] == 0){
					if(flag == 0){
						xx = i;
						yy = j;
						flag = 1;
						continue;
					}
					if(di[i][j] < di[xx][yy]){
						xx = i;
						yy = j;
					}
				}
			}
		}
		check[xx][yy] = 1;
		cnt--;

		for(int i=0;i<4;i++){
			if(xx+dx[i] >=1 && xx+dx[i] <= r && yy+dy[i] >= 0 && yy+dy[i] <= 1){
				tmp = dist(xx,yy,xx+dx[i],yy+dy[i]);
				if(tmp+di[xx][yy] < di[xx+dx[i]][yy+dy[i]])
					di[xx+dx[i]][yy+dy[i]] = tmp+di[xx][yy];
			}
		}
	}

	for(int i=1;i<=r;i++){
		printf("%d %d\n",di[i][0],di[i][1]);
	}
	printf("\n\n\n");

	tmp = 0;
	for(int i=2;i<y;i++){
		tmp+=cost[x][i];
	}

	return (di[x][0]+tmp+cost[x][y] < di[x][1]+r_sum[x]-tmp)?di[x][0]+tmp+cost[x][y]:di[x][1]+r_sum[x]-tmp;
}

int sh_path(int nx, int ny, int x, int y){
	int a,b;

	a = shortest(nx,1,x,y);
	b = shortest(nx,c,x,y);

	return (a<b)?a:b;
	
}

int main()
{
	int d;
	int x,y;
	int nx,ny;
	int res=0;
	int sum;

	scanf("%d %d",&r,&c);
	for(int i=1;i<=r;i++){
		sum = 0;
		for(int j=1;j<=c;j++){
			scanf("%d",&cost[i][j]);
			if(j != 1 && j != c)
				sum+=cost[i][j];
		}
		r_sum[i] = sum;
	}
	res += cost[1][1];

	scanf("%d",&d);

	nx = 1;
	ny = 1;
	for(int i=0;i<d;i++){
		scanf("%d %d",&x,&y);
		res+=sh_path(nx,ny,x,y);
		nx = x;
		ny = y;
	}

	printf("%d\n",res);

	return 0;

}
