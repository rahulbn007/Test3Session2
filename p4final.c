#include<stdio.h>
int input_degree()
{
  int n;
  printf("Enter the degree of the polynomial\n");
  scanf("%d",&n);
  return n;
}
float input_x()
{
  float x;
  printf("Enter the value of x\n");
  scanf("%f",&x);
  return x;
}
void input_coefficients(int n, float a[n])
{
  printf("Enter the coefficients\n");
  for(int i=0;i<n;i++)
    scanf("%f",&a[i]);
}
float evaluate_polynomial(int n, float a[n], float x)
{
  if(n==1)
    return a[0];
  else
  {
    float b=a[n-1];
    int k=n-2;
    while(k>=0)
      {
        b=a[k]+x*b;
        k--;
      }
    return b;
  }
}
void out_put(int n, float a[n], float x, float result)
{
  if(n==1)
    printf("%0.2f = %0.2f",a[0],result);
  else{
  printf("%0.2f+",a[0]);
  int i;
  for(i=1;i<n-1;i++)
    printf("%0.2f*x^%d+",a[i],i);
  printf("%0.2f*x^%d is %f\n",a[i],i,result);
  }
}
int main()
{
  int n=input_degree();
  float a[n+1],result,x;
  input_coefficients(n+1,a);
  x=input_x();
  result=evaluate_polynomial(n+1,a,x);
  out_put(n+1,a,x,result);
  return 0;
}