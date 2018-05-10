
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  struct code
 {int n;
  char name[1000];
  char x;
  };


 void filewrite(struct code s1)
 {
     int i;
     FILE *fo;
     fo = fopen("aera_o.txt","w");
     for(i=0;s1.name[i]!='\0';i++)
      fputc(s1.name[i],fo);
    fputc('\0',fo);
    fclose(fo);
    printf("\n\t%s",s1.name);
 }

 struct code encode(struct code s)
 {
     int i,sh;
     sh=s.n;
     for(i=0;i<s.n;i++)
     {
         sh=4%s.n;
         if(sh<1)
         {
             sh=sh+2;
         }
         s.name[i]=(s.name[i]+((sh)*(-1)));
     }
     return s;
 }

  struct code decode(struct code s)
 {
     int i,sh;
     sh=s.n;
     sh=4%s.n;
         if(sh<1)
         {
             sh=sh+2;
         }
     for(i=0;i<s.n;i++)
     {
         s.name[i]=(s.name[i]-((sh)*(-1)));
     }
     return s;
 }

 struct code operate(struct code s)
 {
     if(s.x=='1')
     {
         s=encode(s);
         int i;
         for(i=0;i<s.n;i++)
        {
         if(s.name[i]==94)
         {
             s.name[i]=54;
         }
        }
     }
     else if(s.x=='2')
     {
         int i;
         for(i=0;i<s.n;i++)
        {
         if(s.name[i]==54)
         {
             s.name[i]=94;
         }
        }
         s=decode(s);
         for(s.n=0;s.name[s.n]!='\0';s.n++);
     }
     else
     {
         printf("\n\t error! %c is not an option!",s.x);
         strcpy(s.name,"waiting for input");
     }
     return s;

 }

  int main(int argc, char *argv[])
  {
      struct code s;
      int i;
      strcpy(s.name,argv[2]);
      for(i=3;i<argc;i++)
      {
          s.n=strlen(s.name);
           if(i!=argc)
          {
              s.name[s.n]='_';
              s.name[s.n+1]='\0';
          }
          s.name[s.n+1]='\0';
          s.n=strlen(s.name);
          strcat(s.name,argv[i]);
      }
      s.x=argv[1][0];
      for(s.n=0;s.name[s.n]!='\0';s.n++);
      s=operate(s);
      filewrite(s);
      return 28797;
  }
