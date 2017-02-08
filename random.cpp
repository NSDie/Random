#include <iostream>
#include<stdlib.h>
using namespace std;
int flag =0 ;
class Question {
      public :
             int  randNum();
             int randSym();
             char symbol(int i);
   };
int  Question::randNum()
             {
                  return rand()%9+1;
              }
int Question::randSym()
             {
                  return rand()%4+1;
             }
char Question::symbol(int i){
                  switch(i)
                    {
                   case 1:  return '+';
                            break; 
                   case 2:  return '-';
                            break;         
                   case 3:  return '*';
                            break; 
                   case 4:  if(flag=0) 
                            {
                             return '/';
                             flag=1;
                             break; 
                             }
                             else return symbol(rand()%4+1);
                    }
                  }
int check(char str[])
{ 
   int sum,i,j,t,d,top=0;
   char exp[10];
   char stack[10];
   char ch;
   sum=7;
   t=1;i=1;
   ch=str[i];i++;
     while (ch!='#')
  {
	switch(ch)
	{
	  case '(':  /*�ж�Ϊ������*/
		   top++;stack[top]=ch;
		   break;
	  case ')':  /*�ж�Ϊ������*/
		   while (stack[top]!='(')
		   {
		     exp[t]=stack[top];top--;t++;
		   }
		   top--;
		   break;
	  case '+':   /*�ж�Ϊ�Ӽ���*/
	  case '-':
		    while (top!=0 && stack[top]!='(')
		    {
		      exp[t]=stack[top];top--;t++;
		    }
		    top++;stack[top]=ch;
		    break;
	   case '*':  /*�ж�Ϊ'*'��'/'��*/
	   case '/':
		    while (stack[top]=='*' || stack[top]=='/')
		    {
  	               exp[t]=stack[top];top--;t++;
		    }
		    top++;stack[top]=ch;
		    break;
	   case ' ':break;
	   default:
		    while (ch>='0' && ch<='9') /*�ж�Ϊ����*/
		    {
		       exp[t]=ch;t++;
		       ch=str[i];i++;
		    }
		    i--;
		    exp[t]='#';t++;
	 }
	 ch=str[i];i++;
  }
  while (top!=0)
  {
    exp[t]=stack[top];t++;top--;
  }
  exp[t]='#';
  t=1;top=0;
  ch=exp[t];t++;
  while (ch!='#')
  {
    switch (ch)
    {
	   case '+':stack[top-1]=stack[top-1]+stack[top];
		    top--;break;
	   case '-':stack[top-1]=stack[top-1]-stack[top];
		    top--;break;
	   case '*':stack[top-1]=stack[top-1]*stack[top];
		    top--;break;
	   case '/':if (stack[top]!=0)
		           stack[top-1]=stack[top-1]/stack[top];
		        else
		        {
		           printf("\n\t�������!\n");
                   exit(0);/*�쳣�˳�*/
		        }
	            top--;break;
	   default:d=0;
               while (ch>='0' && ch<='9')   /*�ж�Ϊ�����ַ�*/
                {
		          d=10*d+ch-'0';  /*�������ַ�ת���ɶ�Ӧ����ֵ*/
		          ch=exp[t];t++;
		        }
		        top++;
		        stack[top]=d;
    }
    ch=exp[t];t++;
  }
  return stack[top];
}

void Rand(){
int i;
int num[5];
int sign[5];
char sym[5];
char str[10];
char snum[5];
int s1,s;
srand(time(NULL));   
Question q;
for(i=1;i<=4;i++)
num[i]=q.randNum();
for(i=1;i<=3;i++)
sign[i]=q.randSym();
for(i=1;i<=3;i++)
sym[i]=q.symbol(sign[i]);
sprintf(snum,"%d",num);
for(i=1;i<=4;i++)
str[i*2-1]=snum[i];
for(i=1;i<=3;i++)
str[i*2]=sym[i];
for(i=1;i<=7;i++)
cout <<str[i];
cout <<"=";
cin>>s1;
str[8]='#';
s=check(str);
if(s1!=s) 
cout<<"����ˣ���ȷ����"<<s<<endl; 
else 
cout<<"�ش���ȷ��"<<endl;    
}
int main()
{
while(1)Rand();
 
return 0;
}
