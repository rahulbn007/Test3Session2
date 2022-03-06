#include<stdio.h>
void input_n_and_r(int *n, int *r)
{
  printf("Enter the value of n and r\n");
  scanf("%d%d",n,r);  
}
int ncr(int n, int r)
{
  if(r==0 || n==r)
    return 1;
  else
    return ncr(n-1,r-1)+ncr(n-1,r);
}
void output(int n, int r, int result)
{
  printf("%dC%d is %d\n",n,r,result);
}
int main()
{
  int n,r,result;
  input_n_and_r(&n,&r);
  result=ncr(n,r);
  output(n,r,result);
  return 0;
}