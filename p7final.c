#include<stdio.h>
typedef struct _fraction
{
int num,den;
}Fraction;
int find_gcd(int a,int b)
{
 int t;
    while (b != 0)
      {
        t = b;
        b = a%b;
        a = t;
      }
    return a;
}
Fraction input_fraction()
{
  Fraction f;
  printf("Enter the fraction:\n");
  scanf("%d%d",&f.num,&f.den);
  return f;
}
Fraction add_fractions(Fraction f1, Fraction f2)
{
    Fraction sum;
    sum.den=f1.den*f2.den;
    sum.num=(f1.num*f2.den)+(f2.num*f1.den);
    int n=find_gcd(sum.num,sum.den);
    sum.num=sum.num/n;
    sum.den=sum.den/n;
    return sum;
}
void output(Fraction f1, Fraction f2,Fraction sum)
{
  printf("The sum of two fractions:\n%d/%d\n%d/%d\nis %d/%d\n",f1.num,f1.den,f2.num,f2.den,sum.num,sum.den);
}
int main()
{
  Fraction f1= input_fraction();
  Fraction f2= input_fraction();
  Fraction sum=add_fractions(f1,f2);
  output(f1,f2,sum);
  return 0;
}

