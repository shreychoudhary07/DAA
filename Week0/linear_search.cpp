#include<iostream>
using namespace std;

void linearsearch(int a[],int x){
    int i,j,flag=0;
    for(i=0;i<=8;i++){
        flag++;
        if(a[i]==x){
            cout<<"key found at comparison number:  "<<flag<<endl;
        }
        else{
            cout<<"key not found at comparison: "<<flag<<endl;
        }
    }
}
int main(){
    int a[8]={2,6,8,3,9,4,7,1};
    int x;
    cout<<"enter the key you want to search"<<endl;
    cin>>x;
    linearsearch(a,x);
    return 0;
}