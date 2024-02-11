#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a1k[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a1k[i]);
    }

    int a2set[n];
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        int check = 0;
        for (int j = 0; j < size; j++)
        {
            if(a2set[j]==a1k[i]){
                check = 1;
                break;
            }
        }
        if (check == 0 )
        {
            a2set[size] = a1k[i];
            size++;
        }
    }

    printf("%d",size);
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",a2set[i]);
    }
    printf("\n");
    return 0;
}

