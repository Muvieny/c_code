//每次询问选手实力都加一，找出初始最强的选手，选手数为2的倍数
//通过淘汰赛比拼，最后活下来的增加的实力都是相同的
#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n+1];
    int b[n+1];
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int cnt=n;
    while(cnt>1){
        int x=a[1],y=a[cnt];
        for(int i=1;i<=cnt/2;i++){
            printf("? %d %d\n",a[i],a[cnt-i+1]);
            fflush(stdout);
            int r;
            scanf("%d",&r);
            if(r==1){
                b[i]=a[i];
            }
            else if(r==2){
                b[i]=a[cnt-i+1];
            }
            else if(r==0){
                b[i]=a[i];
            }
            else{
                return 0;
            }
        }
        for(int i=1;i<=cnt/2;i++){
            a[i]=b[i];
        }
        cnt=cnt/2;
    }
    printf("! %d\n",a[1]);
    return 0;
}