#include<stdio.h>
typedef struct _fraction
{
int num,den;
}Fraction;
int size()
{
  int n;
  printf("Enter the number of fractions:\n");
  scanf("%d",&n);
  return n;
}
int find_gcd(int a, int b)
{
  int t;
  while(b!=0){
    t=b;
    b=a%b;
    a=t;
  }
  return a;
}
Fraction input_fraction()
{
  Fraction temp;
  printf("Enter the fraction:\n");
  scanf("%d%d",&temp.num,&temp.den);
  return temp;
}
void input_in_fractions(int n, Fraction f[n])
{
  for(int i=0;i<n;i++)
     f[i]=input_fraction();
}
Fraction add_fractions(Fraction f1, Fraction f2)
{
    Fraction t;
    t.den=f1.den*f2.den;
    t.num=(f1.num*f2.den)+(f2.num*f1.den);
    int temp=find_gcd(t.num,t.den);
    t.num=t.num/temp;
    t.den=t.den/temp;
    return t;
}
Fraction add_n_fractions(int n,Fraction f[n])
{
  Fraction sum;
  sum=f[0];
  for(int i=1;i<n;i++)
     sum=add_fractions(sum,f[i]);
  return sum;
}
void output(int n, Fraction f[n], Fraction sum)
{
  int i;
  printf("The sum of %d fractions:\n",n);
  for(i=0;i<n-1;i++)
    printf("%d/%d + ",f[i].num,f[i].den);
  printf("%d/%d is %d/%d\n",f[i].num,f[i].den,sum.num,sum.den);
}
int main()
{
  int n=size();
  Fraction f[n];
  input_in_fractions(n,f);
  Fraction sum=add_n_fractions(n,f);
  output(n,f,sum);
  return 0;
}
