#include <stdio.h>
int input_size()
{
  int n;
  printf("Enter the array size:\n");
  scanf("%d",&n);
  return n;
}
void input_array(int n, int a[n])
{
  printf("Enter %d numbers:\n",n);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
}
int find_largest(int n, int a[n])
{
  int large=a[0],c=0;
  for(int i=1;i<n;i++)
  {
    if(a[i]>large)
    {
      large=a[i];
      c=i;
    }
  }
  return c;
}
void out_put(int n, int a[n], int largest)
{
  printf("The index of the largest element %d in array is %d\n",a[largest],largest);
}
int main()
{
  int x,y;
  x=input_size();
  int a[x];
  input_array(x,a);
  y=find_largest(x,a);
  out_put(x,a,y);
  return 0;
}