#include <stdio.h>
#include <stdlib.h>
#include <string.h>


  struct code
 {int n;
  char name[1000];
  char x;
  };

  int f=0;

 struct code infile()
 {
     struct code s;
     int i;
     i=0;
     printf("\n\t The file contains :\n ");
     FILE *fp;
     fp = fopen("jara_i.scb","r");
     if(fp==NULL)
     {
         puts("\n\t Invalid file! Try again!");
     }
     while(1)
     {
      s.name[i]=fgetc(fp);
      if(s.name[i]==EOF)
      {
          break;
      }
      i++;
     }
     fclose(fp);
     printf("\n\t %s",s.name);
     return s;
 }

 void outfile(struct code s1)
 {
     int i;
     FILE *fo;
     fo = fopen("jara_o.scb","w");
     for(i=0;s1.name[i]!='\0';i++)
      fputc(s1.name[i],fo);
     if(s1.x==1)
      {
          fputc('\0',fo);
          fputc('0',fo);
      }
     else
      {
          fputc('\0',fo);
      }
     fclose(fo);
 }

 struct code decode(struct code s)
{int i;
 int sh;
 sh=s.n;
 for(i=0;i<s.n;i++)
  {s.name[i]=s.name[i]-(sh++);}
 if(f<5)
 {
     f++;
     s=decode(s);
 }
 return s; }

 struct code encode(struct code s)
{int i;
 int sh;
 sh=s.n;
 for(i=0;i<s.n;i++)
  {s.name[i]=s.name[i]+(sh++);}
if(f<5)
 {
     f++;
     s=encode(s);
 }
 s.name[i]=s.n;
 f=0;
 return s ; }

struct code word()
{
    struct code s;
    int c3,i;

    s=infile();

    for(s.n=0;s.name[s.n]!='\0';s.n++);
    s.x=s.name[s.n+2];
    return s;
};

struct code cod(struct code s)
{
     f=0;
     int c;
     struct code s1;
 if(s.x=='0')
   {s1=decode(s);}
 else
    {s1=encode(s);}
 return s1;
}

int main()
{
 int c2,c;
 struct code s,s1;
 do{
  s=word();

f1:
 s1=cod(s);
 printf("\n\n\t Press y to save the decoded/encoded message or any other key to continue : ");
 c=getche();
 if(c=='y'||c=='Y')
 { outfile(s1); }
 printf("\n\n\t If you want to continue press 'y' : ");
 c=getche();
 if(c=='y'||c=='Y')
 {
   printf("\n\n\t  If you want to continue with same phase press 1 ");
   printf("\n\t  Make the encoded/decoded phase your main phase press 2 ");
   printf("\n\t  For a reset press 3\n\t  enter your choice : ");
   c2=getche();
   if(c2=='1')
   {
       goto f1;
   }
   if(c2=='2')
   {
     s=s1;
     goto f1;
   }
 }
 }while(c=='y'||c=='Y');
 return 28797;
}
