#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

// Declaration of functions
void Stafflogin(); 
void Stdlogin();
void getinputs();
void login();
void timetable();
void tt();
void form();
void forms();
void hallticket();
void viewresult();
void flush();
int studentdetails();
int updateresult();
void Result();
int bubble(int*,int);
void leader();

int li=0;
FILE *fp;
char another;

//Creating a structure variable
struct stdmarks
{
	char name[50];
	char regno[11];
	char subname[10][10];
	float marks[10];
	float credits[10];
	float point[10];
	float gpa;
	float av[10];
};
struct student
{
	char name[50];
	char regno[9];
	char gender;
	int contact;
	char dob[10];
};

void printHead()
{
system("cls");
printf("\n\n\t");
printf("\t\tCONTROLLER OF EXAMINATION");
printf("\n\n\n");
}

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//function to display login page
void login()
{
	  void printHead();
	int n;
	printf("\t\t..........................\n\t     SRI KRISHNA COLLEGE OF TECHNOLOGY\n\t\t..........................\n\n\n");
	printf("\t\t..........................\n\t\tCONTROLLER OF EXAMINATION\n\t\t..........................\n\n\n");
	printf("\t\t..........................\n\t\t.......... LOGIN .........\n\t\t..........................\n\n");
	printf("\n1.Staff\n2.Student\n");
	printf("Choose any 1 from this......\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			Stafflogin();
			break;
		case 2:
			Stdlogin();
			break;
		default:
			printf("Choose any 1 from this......");
	}
}

//function for staff login
void Stafflogin(){
printHead();
int i;
char pass[20],name[20],ch;
char password[10];
printf("Enter Staff Id ");
scanf("%s",name);
printf("\nEnter Password:");
	   while (1) {
      if (i < 0) {
         i = 0;
      }
      ch = getch();
 
      if (ch == 13)
         break;
      if (ch == 8) /*ASCII value of BACKSPACE*/
      {
         putch('b');
         putch(NULL);
         putch('b');
         i--;
         continue;
      }
 
      pass[i++] = ch;
      ch = '*';
      putch(ch);
   }
 
   pass[i] = '\0';
if (strcmp(name, "Staff") == 0 && strcmp(pass, "pass") == 0)
{
	printHead();
	int v;
	printf("Access granted\n\n");
	printf("\n1.Student Details Management\n2.Result Management\n3.View Forms\n4.TimeTable\n5.GO BACK\nEnter Your choice");
	scanf("%d",&v);
	switch(v)
	{
		case 1:
			studentdetails();
			break;
		case 2:
			updateresult();
			break;
		case 3:
			forms();
			break;
		case 4:
			timetable();
			break;
		case 5:
			login();
	}
}
else printf("Access denied\n");
}

//function to display student details
int studentdetails()
{
    FILE *fp, *ft; 
    char another, choice;
 
    struct std{
	char name[50];
	char regno[11];
	char gender[8];
	char contact[12];
	int age;
	char dob[12];
	char dept[50];
	int yrjn;
	int gdyr;
    };
 
    struct std e;
    char stdname[40];
    long int recsize;
    fp = fopen("std.bin","ab+");
    if(fp == NULL){
        fp = fopen("std.bin","ab+");
        if(fp == NULL){
            printf("Connot open file");
            exit(1);
        }
    }

    recsize = sizeof(e);
 
    while(1){
    	void printHead();
        printf("\n1. Add Record\n"); 
        printf("2. List Records\n");
        printf("3. Modify Records\n");
        printf("4. Delete Records\n"); 
        printf("5. GO BACK\n"); 
        printf("Your Choice: "); 
        fflush(stdin); 
        scanf("\n%c", &choice); 
        switch(choice){
            case '1':  
            	void printHead();
                fseek(fp,0,SEEK_END); 
      			another = 'y';
                while(another == 'y'){
                    flush();
                    printf("\nEnter name: ");
                    fgets(e.name, 40, stdin);
                    printf("\nEnter register number: ");
                    gets(e.regno);
                    printf("\nEnter gender:  ");
                    gets(e.gender);
    				printf("\nEnter contact number: ");
    				gets(e.contact);
    				printf("\nEnter date of birth: ");
    				gets(e.dob);
    				printf("\nEnter Department: ");
    				gets(e.dept);
    				printf("\nEnter year of joining: ");
    				scanf("%d", &e.yrjn);
    				printf("\nEnter graduation year: ");
    				scanf("%d", &e.gdyr);
    				fwrite(&e,recsize,1,fp);
    				printf("\nAdd another record(y/n) ");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
                break;
                
                case '2':
                void printHead();
				rewind(fp);
                while(fread(&e,recsize,1,fp)==1){ 
                
                	printf("\nName: ");
                	printf("%s",e.name);
                    printf("Register number: ");
                    printf("%s", e.regno);
                    printf("\nEnter gender:  ");
                    printf("%s", e.gender);
    				printf("\nEnter contact number: ");
    				printf("%s", e.contact);
    				printf("\nEnter date of birth: ");
    				printf("%s", e.dob);
    				printf("\nEnter Department: ");
    				printf("%s", e.dept);
    				printf("\nEnter year of joining: ");
    				printf("%d", e.yrjn);
    				printf("\nEnter graduation year: ");
    				printf("%d", e.gdyr);
    				printf("\n");
                }
                break;
            
			case '3':
				void printHead();
                another = 'y';
                while(another == 'y'){
                    printf("\nEnter the student name to modify: ");
                    scanf("%s", stdname);
                    rewind(fp);
                    while(fread(&e,recsize,1,fp)==1){ 
                    if(strcmp(e.name,stdname) == 0){ 
						printf("\nEnter name: ");
                    	scanf("%s",&e.name);
                    	printf("\nEnter register number: ");
                    	scanf("%s", &e.regno);
                    	printf("\nEnter gender:  ");
                    	scanf("%c", &e.gender);
    					printf("\nEnter contact number: ");
    					scanf("%d", &e.contact);
    					printf("\nEnter date of birth: ");
    					scanf("%s", &e.dob);
    					printf("\nEnter Department: ");
    					scanf("%s", &e.dept);
    					printf("\nEnter year of joining: ");
    					scanf("%d", &e.yrjn);
    					printf("\nEnter graduation year: ");
    					scanf("%d", &e.gdyr);
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp); 
                        break;
                        }
                    }
                    printf("\nModify another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
                break;
            case '4':
            	void printHead();
                another = 'y';
                while(another == 'y'){
                    flush();
                    printf("\nEnter name of student detail to delete: ");
                    fgets(stdname,40, stdin);
                    ft = fopen("Tstd.dat","a");
                    rewind(fp);
                    while(fread(&e,recsize,1,fp)){ 
                        if(strcmp(e.name,stdname) != 0){ 
                            fwrite(&e,recsize,1,ft); 
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("std.DAT");
                    rename("Tstd.dat","std.DAT"); 
                    fp = fopen("std.DAT", "a+");
                    printf("Delete another record(y/n)");
                    fflush(stdin);
                    scanf("\n%c", &another);
                }
                break;
            case '5':
                fclose(fp);
                login(); 
        }
    }
    return 0;
}

//function to update result
int updateresult()
{
	printHead();
    FILE *fp, *ft; 
    char another, choice;
    struct stdmarks s;
    char stdname[40];
    long int recsize;
	if((fp=fopen("studentResult.txt","rb+"))==NULL)
	{
    if((fp=fopen("studentResult.txt","wb+"))==NULL)
    {
    printf("can't open file");
    exit(0);
    }
	}
    recsize = sizeof(s);
    while(1){
        printf("\n1. Add Student Result\n"); 
        printf("2. View Result\n");
        printf("5. Exit\n"); 
        printf("Your Choice: "); 
        fflush(stdin); 
        scanf("\n%c", &choice); 
        switch(choice){
        	case '1':
            	printHead();
				if((fp=fopen("studentResult.txt","rb+"))==NULL)
				{
    			if((fp=fopen("studentResult.txt","wb+"))==NULL)
       			{
           		printf("can't open file");
           		exit(0);
       			}
				}
                fseek(fp,0,SEEK_END); 
      			another = 'y';
                while(another == 'y'){
                flush();
                printf("\nEnter name: ");
                fgets(s.name, 40, stdin);
                printf("\nEnter register number: ");
                gets(s.regno);
                int n,i;
				float avg,credits;
				struct stdmarks e;
				printf("Enter the marks of 5 subjects : ");
				avg=0;
				credits=0; 
				for(i=0;i<5;i++)
				{
				printf("Enter the mark :");
				scanf("%f",&s.marks[i]);
				s.point[i]=s.marks[i]/10.00;
				printf("Enter the credits :");
				scanf("%f",&s.credits[i]);
				s.av[i]=s.credits[i]*s.point[i];
				avg=avg+s.av[i];
				credits=credits+s.credits[i];
				}
				s.gpa=avg/(credits);
				printf("GPA : %f",s.gpa);
				fwrite(&s,recsize,1,fp);
    			printf("\nAdd another record(y/n) ");
                fflush(stdin);
                scanf("\n%c", &another);
                }
                break;
        	case '2':
        		printHead();
                viewresult();
                break;
            case '5':
                fclose(fp);
                login(); 
        }
    }
    return 0;
}

//function for student login
void Stdlogin(){
printHead();
printHead();
int i;
char pass[20],name[20],ch;
char password[10];
printf("Enter Student Id ");
scanf("%s",name);
printf("\nEnter Password:");
	   while (1) {
      if (i < 0) {
         i = 0;
      }
      ch = getch();
 
      if (ch == 13)
         break;
      if (ch == 8) /*ASCII value of BACKSPACE*/
      {
         putch('b');
         putch(NULL);
         putch('b');
         i--;
         continue;
      }
 
      pass[i++] = ch;
      ch = '*';
      putch(ch);
   }
 
   pass[i] = '\0';
if (strcmp(name, "Student") == 0 && strcmp(pass, "pass") == 0)
{
	int v;
	printHead();
	printf("Access granted\n\n");
	printf("\n1.View Result\n2.View Forms\n3.TimeTable\n4.Send Queries\n5.Hall Ticket\n6.GO BACK\nEnter Your choice");
	scanf("%d",&v);
	char query[1000];
	switch(v)
	{
		case 1:
			Result();
			break;
		case 2:
			forms();
			break;
		case 3:
			timetable();
			break;
		case 4:
			printf("Send your Query : ");
			gets(query);
			printf("Query Sent");
		case 5:
			hallticket();
			break;
		case 6:
			login();
		}
}
else printf("Access denied\n");
}

//function to view result
void viewresult()
{
	printHead();
	struct stdmarks e;
    char stdname[40];
    long int recsize;
	if((fp=fopen("studentResult.txt","rb+"))==NULL)
	{
    if((fp=fopen("studentResult.txt","wb+"))==NULL)
    {
    printf("can't open file");
    exit(0);
    }
}
int flag,siz,i;
struct stdmarks s;
char tempRoll[12],another='y';
siz=sizeof(s);
while(another=='y'||another=='Y')
{
printf("\n\n\tEnter Register Number : ");
gets(tempRoll);
rewind(fp);
while((fread(&s,siz,1,fp))==1)
{
if(strcmp(s.regno,tempRoll) == 0)
        {flag=1;
        break;
        }
}
if(flag==1)
    {
    printf("\n\t\tNAME : %s",s.name);
        printf("\n\n\t\tREGISTER NUMBER : %s",s.regno);
        printf("\nMARKS :");
                    	for(i=0;i<5;i++)
					{
					printf("SUBJECT %d : %f / GRADE : %f / CREDITS : %f\n",i+1,s.marks[i],s.point[i],s.credits[i]);
                	}
                		printf("CGPA : %f",s.gpa);
}
else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");
printf("\n\n\t\tWant to enter another search (Y/N)");
fflush(stdin);
another=getchar();
}
}

//function to display forms
void forms()
{
	printHead();
	printf("\t\t\t\tFORMS");
	printf("\n\n");
	printf("1.HOSTEL FORM\n\n2.TRANSPORT FORM\n\n3.NO DUE FORM\n\n4.RE-EVALUATION FORM\n\n5.LEAVE / ON-DUTY FORM");
	int ch;
	void form();
	char answer='y';    
    while(answer=='y')
    {
    	form();
    	printf("\n\nDo you want to view another form? y/n:");
    	scanf("%s",&answer);
    	if(answer!='y')
    	break;
	}
}

//function to display main page of forms
void form()
	{
		printHead();
		printf("1.HOSTEL FORM\n\n2.TRANSPORT FORM\n\n3.NO DUE FORM\n\n4.RE-EVALUATION FORM\n\n5.LEAVE / ON-DUTY FORM");
		int ch;
	printf("\n\nEnter a choice: ");
	scanf("%d",&ch);
	switch(ch)
    {
        case 1:
        	printHead();
            printf("\t\t\tSRI KRISHNA COLLEGE OF TECHNOLOGY\n\n\t\t\tHOSTEL FORM\n\nName of the student: ______________________________\nRegister number: _______________\nFather's Name: ______________________________\nMother's Name: ______________________________\nAddress:______________________________\n\t______________________________\n\t______________________________\nContact number(student): _______________\nContact number(Father): _______________\nContact Number(Mother): _______________\n\n\nSignature of student\t\t\tSignature of Parent\n");
            break;
        case 2:
        	printHead();
            printf("\t\t\tSRI KRISHNA COLLEGE OF TECHNOLOGY\n\n\t\t\tTRANSPORT FORM\n\nName of the student: ______________________________\nRegister number: _______________\nFather's Name: ______________________________\nMother's Name: ______________________________\nAddress:______________________________\n\t______________________________\n\t______________________________\nBoarding Point:____________________\nContact number(student): _______________\nContact number(Father): _______________\nContact Number(Mother): _______________\n\n\nSignature of student\t\t\tSignature of Parent\n");
            break;
        case 3:
        	printHead();
        	printf("\t\t\tSRI KRISHNA COLLEGE OF TECHNOLOGY\n\n\t\t\tNO-DUE FORM\n\nName of the student: ______________________________\nRegister number: _______________\nSubject1:____________________\tFaculty sign:__________\n\nSubject2:____________________\tFaculty sign:__________\n\nSubject3:____________________\tFaculty sign:__________\n\nSubject4:____________________\tFaculty sign:__________\n\nSubject5:____________________\tFaculty sign:__________\n\nSubject6:____________________\tFaculty sign:__________\n\n\n\nSignature of student\t\t\tSignature of HoD\n");
			break;
        case 4:
        	printHead();
            printf("\t\t\tSRI KRISHNA COLLEGE OF TECHNOLOGY\n\n\t\t\tRE-EVALUATION FORM\n\nName of the student: ______________________________\nRegister number: _______________\n\nSubject1:____________________\tFaculty sign:__________\n\nSubject2:____________________\tFaculty sign:__________\n\nSubject3:____________________\tFaculty sign:__________\n\nSubject4:____________________\tFaculty sign:__________\n\nSubject5:____________________\tFaculty sign:__________\n\nSubject6:____________________\tFaculty sign:__________\n\nTotal amount paid:_______________\n\n\nSignature of student\t\t\tSignature of HoD\n");
            break;
        case 5:
        	printHead();
            printf("\t\t\tSRI KRISHNA COLLEGE OF TECHNOLOGY\n\n\t\t\tLEAVE / ON-DUTY FORM\n\nName of the student: ______________________________\nRegister number: _______________\nBranch/Year of study:____________________\nPeriod/Date for which leave applied: FROM__________TO__________/ON__________\nReason for leave:________________________________\nSignature of parent/guardian/\nwarden/faculty incharge:_________________\nSignature of student:_____________________\n\n\nSignature of faculty advisor\t\t\tSignature of HoD\n");
            break;
        default:
        	printf("INVALID CHOICE");
    }
}

//function to display timetable page
void timetable()
{
	printHead();
	printf("1.FIRST YEAR END SEMESTER TIME TABLE ->\n\n2.SECOND YEAR END SEMESTER TIME TABLE ->\n\n3.THIRD YEAR END SEMESTER TIME TABLE ->\n\n4.FOURTH YEAR END SEMESTER TIME TABLE ->\n\n5.ARREAR EXAMINATION TIME TABLE ->\n");
	int ch;
	char c;
	FILE *fa,*fb,*fc,*fd,*fe;
	fa = fopen("firstyr.doc","w");
	fprintf(fa,"\t\t\tSRI KRISHNA COLLEGE OF TECHNOLOGY\n\n\t\t\tFIRST YEAR TIME TABLE\n\nDATE      \tIT\tCSE\tECE\tEEE\n20.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n23.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n26.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n28.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n30.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n");
	fclose(fa);
	fb=fopen("secondyr.doc","w");
	fprintf(fb,"\t\t\tSRI KRISHNA COLLEGE OF TECHNOLOGY\n\n\t\t\tSECOND YEAR TIME TABLE\n\nDATE      \tIT\tCSE\tECE\tEEE\n20.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n23.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n26.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n28.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n30.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n");
	fclose(fb);
	fc=fopen("thirdyr.doc","w");
	fprintf(fa,"\t\t\tSRI KRISHNA COLLEGE OF TECHNOLOGY\n\n\t\t\tTHIRD YEAR TIME TABLE\n\nDATE      \tIT\tCSE\tECE\tEEE\n20.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n23.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n26.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n28.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n30.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n");
	fclose(fc);
	fd=fopen("fourthyr.doc","w");
	fprintf(fa,"\t\t\tSRI KRISHNA COLLEGE OF TECHNOLOGY\n\n\t\t\tFOURTH YEAR TIME TABLE\n\nDATE      \tIT\tCSE\tECE\tEEE\n20.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n23.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n26.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n28.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n30.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n");
	fclose(fd);
	fe=fopen("arrear.doc","w");
	fprintf(fa,"\t\t\tSRI KRISHNA COLLEGE OF TECHNOLOGY\n\n\t\t\tARREAR EXAMINATION TIME TABLE\n\nDATE      \tIT\tCSE\tECE\tEEE\n20.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n23.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n26.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n28.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n30.11.2018\tSUb 1\tSub 2\tSub 3\tSub 4\n");
	fclose(fe);
	void tt();
	char answer='y';    
    while(answer=='y')
    {
    	tt();
    	printf("\n\nDo you want to view another form? y/n:");
    	scanf("%s",&answer);
    	if(answer!='y')
    	break;
	}
}

//function to display timetable
void tt()
	{
		printHead();
		printf("1.FIRST YEAR END SEMESTER TIME TABLE ->\n\n2.SECOND YEAR END SEMESTER TIME TABLE ->\n\n3.THIRD YEAR END SEMESTER TIME TABLE ->\n\n4.FOURTH YEAR END SEMESTER TIME TABLE ->\n\n5.ARREAR EXAMINATION TIME TABLE ->\n");
		printf("\n6.GO BACK");
		char c;
		int ch;
		FILE *fa,*fb,*fc,*fd,*fe;
	printf("\nEnter a choice: ");
	scanf("%d",&ch);
	switch(ch)
    {
        case 1:
        	printHead();
        	fa=fopen("firstyr.doc","a+");
        	if (fa == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
    c = fgetc(fa); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fa); 
    } 
    fclose(fa); 
            break;
        case 2:
        	printHead();
            fb=fopen("secondyr.doc","a+");
        	if (fb == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
    c = fgetc(fb); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fb); 
    } 
    fclose(fb); 
	break;
        case 3:
        	printHead();
        	fc=fopen("thirdyr.doc","a+");
        	if (fc == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
    c = fgetc(fc); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fc); 
    } 
    fclose(fc); 
	break;
        case 4:
            printHead();
			fd=fopen("fourthyr.doc","a+");
        	if (fd == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
    c = fgetc(fd); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fd); 
    } 
    fclose(fd); 
	break;
        case 5:
        	printHead();
            fe=fopen("arrear.doc","a+");
        	if (fe == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
    c = fgetc(fe); 
    while (c != EOF) 
    { 
        printf ("%c", c); 
        c = fgetc(fe); 
    } 
    fclose(fe);  		
            break;      
            case 6:
            	printHead();
            	login();
            	break;
        default:
        	printf("INVALID CHOICE");
    }
}

//function to display the result login page
void Result()
{
	printHead();
	int n;
	printf("\n1.View Result\n2.View Leaderboard\n\n3.Go back");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			viewresult();
			break;
		case 2:
			leader();
			break;
		default:
			login();
	}
}

//function to show leaderboard
void leader()
  { 
  printHead();
  int marks[100],regno[100],x[100],n,i,j;
  char name[100][50];
  FILE *fp,*fm;
	if((fp=fopen("studentResult.txt","rb+"))==NULL)
	{
    if((fp=fopen("studentResult.txt","wb+"))==NULL)
    {
    printf("can't open file");
    exit(0);
    }
}
  fm = fopen("marks.txt","w");
  i=0;
  while(! feof(fp))
  {
  fscanf(fp,"%d %s %d\n",&regno[i],&name[i],&marks[i]);
  x[i]= marks[i];
  i=i+1;
  }
  n=i;
  bubble(x,n);
  for(i=0;i<n;i++)
  {
  printf(" %d\t",x[i]);
  }
  printf("TOP 5 RANK HOLDERS\n\nREG NO\tNAME\tCGPA");
  for(i=0;i<n;i++)
  {
  for (j=0;j<n;j++)
  {
  if(x[i]==marks[j])
  {
      fprintf(fm,"%d\t%s\t%d\n",regno[j],name[j],marks[j]);
     }
   }
 }
  fclose(fm);
  fclose(fp);
  printf("\n\n\nPRESS ANY KEY");
}

//sorting functions
int bubble(int x[],int n)
{
int hold,j,pass,i,switched = 1;
for(pass = 0; pass < n-1 && switched == 1;pass++)
{
switched=0;
for (j=0;j<n-pass-1;j++)
if (x[j]>x[j+1])
{
switched=1;
hold = x[j];
x[j] = x[j+1];
x[j+1]=hold;
}
}
return(0);
}

//function to display hallticket
void hallticket()
{
	printHead();
	printf("\n\n\t\t\tSRI KRISHNA COLLEGE OF TECHNOLOGY\n\n\t\t\tHALL TICKET\n\n");
	char name[50],reg[9];
	int yr,dep;
	printf("Enter your name: ");
	scanf("%s",name);
	printf("Enter your register number: ");
	scanf("%s",reg);
	printf("Enter your department number (1.IT/2.CSE/3.ECE/4.EEE): ");
	scanf("%d",&dep);
	printf("Enter year of study(1/2/3/4): ");
	scanf("%d",&yr);
	if(dep==1&&yr==1)
	{
		printHead();
		printf("\n\n\n\t\t\tFIRST YEAR B TECH INFORMATION TECHNOLOGY HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
	else if(dep==1&&yr==2)
	{
		printHead();
		printf("\n\n\n\t\t\tSECOND YEAR B TECH INFORMATION TECHNOLOGY HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
	else if(dep==1&&yr==3)
	{
		printHead();
		printf("\n\n\n\t\t\tTHIRD YEAR B TECH INFORMATION TECHNOLOGY HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
	else if(dep==1&&yr==4)
	{
		printHead();
		printf("\n\n\n\t\t\tFINAL YEAR B TECH INFORMATION TECHNOLOGY HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
	else if(dep==2&&yr==1)
	{
		printHead();
		printf("\n\n\n\t\t\tFIRST YEAR BE COMPUTER SCIENCE HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
	else if(dep==2&&yr==2)
	{
		printHead();
		printf("\n\n\n\t\t\tSECOND YEAR BE COMPUTER SCIENCE HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
	else if(dep==2&&yr==3)
	{
		printHead();
		printf("\n\n\n\t\t\tTHIRD YEAR BE COMPUTER SCIENCE HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
	else if(dep==2&&yr==4)
	{
		printHead();
		printf("\n\n\n\t\t\tFINAL YEAR BE COMPUTER SCIENCE HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
	else if(dep==3&&yr==1)
	{
		printHead();
		printf("\n\n\n\t\t\tFIRST YEAR BE ELECTRICAL AND ELECTRONIC ENGINEERING HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
		else if(dep==3&&yr==2)
	{
		printHead();
		printf("\n\n\n\t\t\tSECOND YEAR BE ELECTRICAL AND ELECTRONIC ENGINEERING HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
		else if(dep==3&&yr==3)
	{
		printHead();
		printf("\n\n\n\t\t\tTHIRD YEAR BE ELECTRICAL AND ELECTRONIC ENGINEERING HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
		else if(dep==3&&yr==4)
	{
		printHead();
		printf("\n\n\n\t\t\tFINAL YEAR BE ELECTRICAL AND ELECTRONIC ENGINEERING HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
		else if(dep==4&&yr==1)
	{
		printHead();
		printf("\n\n\n\t\t\tFIRST YEAR BE ELECTRICAL AND COMMUNICATION ENGINEERING HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
		else if(dep==4&&yr==2)
	{
		printHead();
		printf("\n\n\n\t\t\tSECOND YEAR BE ELECTRICAL AND COMMUNICATION ENGINEERING HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
		else if(dep==4&&yr==3)
	{
		printHead();
		printf("\n\n\n\t\t\tTHIRD YEAR BE ELECTRICAL AND COMMUNICATION ENGINEERING HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
		else if(dep==4&&yr==4)
	{
		printHead();
		printf("\n\n\n\t\t\tFINAL YEAR BE ELECTRICAL AND COMMUNICATION ENGINEERING HALL TICKET\n\n");
		printf("Student name: %s\n",name);
		printf("Register number: %s\n",reg);
		printf("\n\nDATE      \tSUBJECT\tFACULTY INCHARGE\n20.11.2018\tSUb 1\tSign:\n23.11.2018\tSUb 2\tSign:\n26.11.2018\tSub 3\tSign:\n28.11.2018\tSUb 4\tSign:\n30.11.2018\tSUb 5\tSign:\n");
		printf("\n\nSTUDENT'S SIGNATURE'");
	}
}

//main function
main()
{
int option;
char another;
if((fp=fopen("studentInfo.txt","rb+"))==NULL)  //file to store student details
{
if((fp=fopen("studentInfo.txt","wb+"))==NULL)
{
printf("can't open file");
return 0;
}
}
login(); //function call
}

