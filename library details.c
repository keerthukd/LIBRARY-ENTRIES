#include<stdio.h>
void addbook();
void reportbook();
void view();
void lend();
void reeturn();
struct admin
{
   char bn[100],auna[100];
   int bid,v;
}s[100];
int n,x,y,t,a,b;
int main()
{
   char al[100],adid=111,adpass=000,st[100],ge[100];
   int f=1,age,stid=2000,stpass=77;
   printf("hello....what is your name?");
   printf("\nEnter your choice:");
   scanf("%d",&n);
   if(n==1)
   {
      do
      {
         printf("\nEnter admin id:");
         scanf("%d",&x);
         printf("\nEnter admin password:");
         scanf("%d",&y);
         if(x==adid&&y==adpass)
         {
            printf("\tWELCOME TO MY LIBRARY Mr.%s",al);
            while(1)
            {
               printf("\n1.Admin\n2.Student\n3.exit");
               printf("\nEnter your choice:");
               scanf("%d",&n);
               if(n==1)
               {
                  do{
                  printf("\nEnter admin id:");
                  scanf("%d",&x);
                  printf("Enter admin password:");
                  scanf("%d",&y);
                  if(x==adid&&y==adpass)
                  {
                     while(1)
                     {
                        printf("\n 1.Add book\n2.Report book\n3.exit");
                        printf("\nEnter your choice:");
                        scanf("%d",&x);
                        if(x==1)
                        addbook();
                        if(x==2)
                        reportbook();
                        if(x==3)
                        break;
                     }
                     
                  }
                  else
                  {
                     printf("\n Invalid admin registration");
                     f=0;
                  }
                  }while(f==0);
               }
               if(n==2)
               {
                  while(1)
                  {
                     printf("\n1.signup\n2.Login\n3.logout");
                     printf("\nEnter your choice:");
                     scanf("%d",&y);
                     if(y==1)
                     {
                        printf("\n enter student name:");
                        scanf("%s",st);
                        printf("\nenter student gender:");
                        scanf("%s",ge);
                        printf("\nenter student age:");
                        scanf("%d",&age);
                        printf("\nenter student ID:");
                        printf("%d",stid);
                        printf("\n The student password is:");
                        printf("%d",stpass);
                     }
                     f=1;
                     if(y==2)
                     {
                        do{
                           printf("\nEnter student ID:");
                           scanf("%d",&a);
                           printf("\nEnter student password:");
                           scanf("%d",&b);
                           if(a==stid&&b==stpass)
                           {
                              while(1)
                              {
                                 printf("\n1.view book\n2.lend book\n3.return book\n4.logout);");
                                 printf("\n Enter your choice:");
                                 scanf("%d",&x);
                                 if(x==1)
                                 view();
                                 if(x==2)
                                 lend();
                                 if(x==3)
                                 reeturn();
                                 if (x==4)
                                 break;
                              }
                           }
                           else
                           {
                              printf("\nInvalid student registration");
                              f=0;
                           }
                        }while(f==0);
                     }
                     if(y==3)
                     break;
                  }
               }
               if(n==3)
               {
                  printf("\n.......THANKS FOR COMMING......");
                  break;
               }
            }
            return 0;
         }
   }while(1);
}
}

         void addbook()
         {
            int i=1,x=1000;
            printf("\n How many book you are added?");
            scanf("%d",&n);
            t=n;
            while(n)
            {
               printf("\nEnter book name:");
               scanf("%s",s[i].bn);
               printf("\n Enter author name:");
               scanf("%s",s[i].auna);
               printf("\n book id is:%d",x);
               s[i].bid=x;
               s[i].v=1;
               i++;
               x++;
               n--;
            }
         }
         void reportbook()
         {
            FILE *rp;
            int i;
            rp=fopen("report.txt","w");
            for(i=1;i<=t;i++)
            {
               fprintf(rp,"%s......%s.....%d....%d\n",s[i].bn,s[i].auna,s[i].bid,s[i].v);
            }
            fclose(rp);
            printf("\nReport download");
         }
         void view()
         {
            int i;
            for(i=1;i<=t;i++)
            {
               if(s[i].v==1)
               printf("%s %s %d\n",s[i].bn,s[i].auna,s[i].bid);
            }
         }
         void lend()
         {
            int f=1,i;
            do{
               printf("\nEnter book id:");
               scanf("%d",&a);
               for(i=1;i<=t;i++)
               {
                  if(a==s[i].bid)
                  {
                     printf("%s %s %d\n",s[i].bn,s[i].auna,s[i].bid);
                     s[i].v=0;
                     f=0;
                  }
               }
               if(f==0)
               printf("\nlended successfully");
               else
               {
                  printf("\ninvalid lend register");
                  f=1;
               }
            }while(f);
         }
         void reeturn()
         {
            int i,k,f=1;
            alvin:
               printf("\nEnter your book id:");
               scanf("%d",&k);
               for(i=1;i<=t;i++)
               {
                  if(s[i].v==0&&k==s[i].bid)
                  {
                     printf("returned successfully");
                     s[i].v=1;
                     f=0;
                  }
               }
               if(f)
               {
                  printf("\nInvalid id");
                  goto alvin;
               }
         }
      
   


