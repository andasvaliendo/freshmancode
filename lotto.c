#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void SortNum(int arr[], int size);
int main(void){
    int yournum[6];
    int lotto[6];
    int i=0;
    while (i<6){
        printf("Please input number %d:", i+1);
        scanf("%d",&yournum[i]);//input numbers
        for(int j=0; j<i; j++){//check numbers
            if(yournum[j]==yournum[i]){
                printf("You have already chosen number %d, please choose another number\n", yournum[i]);
                i--;
            }
        }
        if(yournum[i]<1 || yournum[i]>49){
            printf("The number must be 1~49 choose another number\n");
        }
        else{
            i++;
        }
    }
    
    srand(time(NULL));
    for(int a=0;a<=5;a++){
        lotto[a]=(rand()%49)+1;
        if(a>0){
            for(int b=0;b<a;b++){/*檢查是否重複*/
                if(lotto[a]==lotto[b]){
                    a--;
                    break;
                }
            }
        }
    }
    printf("Your chosen numbers: ");
    SortNum(yournum , 6);
    printf("\nLotto numbers are: ");
    SortNum(lotto , 6);
    int winning=0;
    int winnum[6];
    for(int j=0; j<6; j++){//key in and counting winning numbers
        for(int k=0; k<6; k++){
            if(lotto[j]==yournum[k]){
                winnum[winning]=lotto[j];
                winning++;
            }
        }
    }
    if(winning>0){//wins
        printf("\nCongrtulations! You won %d Numbers.",winning);
        printf("\nYour winning numbers: ");
        SortNum(winnum,winning);
    }
    else{//loses
        printf("\nIt is not your day for playing lotto :(");
    }
}//end main

void SortNum(int _arr[], int size){
    int temp=0;
    for(int j=size; j>0; j--){//how many times running
        for(int i=0; i+1<j; i++){//putting the bigger to the right
            if(_arr[i]>_arr[i+1]){
                temp=_arr[i];
                _arr[i]=_arr[i+1];
                _arr[i+1]=temp;
                temp=0;
            }  
        }
    }
    for (int i=0; i<size; i++){//print result
        printf("%d ", _arr[i]);
    }
}//end SortNum
