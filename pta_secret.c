#include <stdio.h>
#include <string.h>
int main() {
    char r[100];
    scanf("%s", r);
    if(strcmp(r,"first")==0){
        int x;
        scanf("%d", &x);
        char s[100];
        int idx = 0;
        while(idx<60){
            s[idx++] = '0';
        }
        s[idx++] = '1';//idx=60
        //idx=61
        for(int i=29;i>=0;i--){//30
            s[idx++] = ((x >> i) & 1) ? '1' : '0';
        }
        s[idx] = '\0';
        printf("%s\n", s);
    }
    else{
        char s[100];
        scanf("%s", s);
        int l=strlen(s);
        int x = 0;
        int cnt = 0;
        while(1){
            if(s[x%l]=='0'){
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt>=60&&s[(x+1)%l]=='1'){
                x+=2;
                break;
            }
            x++;
        }
        int sum=0;
        for(int i=0;i<30;i++){
            sum = (sum<<1)+(s[(x+i)%l]-'0');
        }
        printf("%d\n", sum);
    }
}