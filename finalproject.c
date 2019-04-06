#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void dictionary()
{
   char ch,string[100],sentence[100],password[100],file_name[25],altpass[100];
   int count=0,number=0,p,count1=0;
   FILE *fp;

    printf("enter password\n");
    scanf("%s",&password);
    strcpy(altpass,password);
    for(p=0;p<strlen(password);p++)
    {
        if(password[p]=='@')
            altpass[p]='a';
        if(password[p]=='3')
            altpass[p]='e';
        if(password[p]=='!')
            altpass[p]='1';
        if(password[p]=='$')
            altpass[p]='S';
    }
    printf("%s\n",altpass);
   fp = fopen("femalenames.txt", "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   fscanf(fp,"%[^\n]", string);

   while((ch = fgetc(fp)) != EOF){

        //printf("%c", ch);
        fscanf(fp,"%[^\n]", string);
        if(strcmp(password,string)==0)
        {
            count++;

        }
        if(strcmp(altpass,string)==0)
        {
            count1++;

        }

        if(ch=='\n')
            number++;

   }
   printf("%s found %d times and %s found %d times in females.txt\tnumber of inputs=%d\n",password,count,altpass,count1,number);

   //printf("\nstring is%s",string);



   fclose(fp);
   fp = fopen("test.txt", "a");
   if(fp == NULL)
   {
      printf("Error!");
      exit(1);
   }
    if(count==0)
    {
        fprintf(fp,"%s\n",password);
    }
    count=0;
    count1=0;
   fclose(fp);
//**************************************************************************************************************************
   fp = fopen("malenames.txt", "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }


   fscanf(fp,"%[^\n]", string);

   while((ch = fgetc(fp)) != EOF){

        fscanf(fp,"%[^\n]", string);
        if(strcmp(password,string)==0)
        {
            count++;
        }
        if(strcmp(altpass,string)==0)
        {
            count1++;

        }

        if(ch=='\n')
            number++;

   }
   printf("%s found %d times and %s found %d times in males.txt\tnumber of inputs=%d\n",password,count,altpass,count1,number);
    if(strstr(password,fp)!=NULL)
        printf("present");
   fclose(fp);
   fp = fopen("test.txt", "a");
   if(fp == NULL)
   {
      printf("Error!");
      exit(1);
   }
    if(count==0)
    {
        fprintf(fp,"%s\n",password);
    }
   fclose(fp);
   count=0;
    count1=0;
//**********************************************************************************************************************************************
fp = fopen("password10mil.txt", "r"); // read mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
   fscanf(fp,"%[^\n]", string);

   while((ch = fgetc(fp)) != EOF){

        //printf("%c", ch);
        fscanf(fp,"%[^\n]", string);
        if(strcmp(password,string)==0)
        {
            count++;

        }
        if(strcmp(altpass,string)==0)
        {
            count1++;

        }

        if(ch=='\n')
            number++;

   }
   printf("%s found %d times and %s found %d times in password10mil.txt\tnumber of inputs=%d\n",password,count,altpass,count1,number);
    if(strstr(password,fp)!=NULL)
        printf("present");
   //printf("\nstring is%s",string);



   fclose(fp);
   fp = fopen("test.txt", "a");
   if(fp == NULL)
   {
      printf("Error!");
      exit(1);
   }
    if(count==0)
    {
        fprintf(fp,"%s\n",password);
    }
   fclose(fp);
}
void bruteforce()
{

        char i='A',j='a',pass[100];
        int bv=0,len,c=8,d=1,k,m=0,n=0,t=0,maxchar;
        float bfstrength;
            printf("\nenter maximum no. of characters\n");
            scanf("%d",&maxchar);

        printf("enter string\n");
        scanf("%s",&pass);

        for(k=0;k<strlen(pass);k++)
        {


        if(pass[k]>='a'&&pass[k]<='z')
            m++;
        else if(pass[k]>='A'&&pass[k]<='Z')
            n++;
        else
            t++;
        }
        if(m>0)
        {
            if(n>0)
            {
                c=4;
                if(t>0){
                //printf("yes");
                c=1;
                }
            }
        }
        pass[0]=tolower(pass[0]);
        while(j<=pass[0])
        {
            bv++;
            i++;
            j++;
        }
        bv=(float)(bv);
        bv=10*bv/26;
        len=(float)(strlen(pass));
        bfstrength=(bv*len*len)*100;
        bfstrength/=10.0*maxchar*maxchar*c;

        printf("\n\nstrength of '%s' = %f out of 100\n",pass,bfstrength);
        if(bfstrength>60.0)
        {
            printf("good score!!");
        }

}
int main()
{
    int ch1;
    char p[100],choice='y';
    while(choice=='y')
    {
        printf("1.bruteforce\t\n");
        printf("2.dictionary\t\n");
        printf("Enter the choice\n");
        scanf("%d",&ch1);
        char p1[100];
        switch(ch1)
        {
            case 1:

                bruteforce();
                break;
            case 2:
                    dictionary();
                break;
            default: printf("wrong choice");
        }
        printf("\nDo you want to continue?(y/n)\n");
        scanf(" %c",&choice);
    }
    return(0);

}
