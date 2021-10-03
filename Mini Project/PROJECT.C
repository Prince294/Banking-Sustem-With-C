#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define BKSP 8
#define ENTER 13
#define TAB 9
#define SPACE 32

void Login();
void Home(int);
void Register();
void Pay();
void Wallet(int);
void Statement();
void Reset();
void Bank(int);
void delay(int);
void box(int,int);
void gotoxy(int,int,int,int);
void edit_detail();


FILE *info,*info1,*info2,*update;


struct Detail
{
	char Name[30],Pass[30];
	int ID;
}inf;


void gotoxy(int top,int bottom)
{
	printf("%c[%d;%df",0x1B,bottom,top);
}


void box(int row,int column,int X,int Y)
{
	for (int i = 1; i <= row; i++)
	{
		gotoxy(X,Y++);
		for (int j = 1; j <= column; j++)
		{
			if (i==1 || i==row)
			{
				printf("*");
			}
			else if (j==1 || j==column)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
			
			
		}
		printf("\n");
	}
	
}

void delay(int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			
		}
		
	}
	
}

int main()
{
	int opt;
	system("COLOR 1E");
	system("cls");
	box(25,120,9,4);
	gotoxy(34,8);
	printf("*************Welcome to The Online Bill Payment Service*************\n\n");
	delay(20000);
	box(4,13,27,13);
	gotoxy(30,14);
	printf("Press 1\n");
	gotoxy(31,15);
	printf("Login");
	box(4,22,93,13);
	gotoxy(101,14);
	printf("Press 2\n");
	gotoxy(96,15);	
	printf("New Registration\n\n");

	box(3,9,61,22);
	gotoxy(65,23);
	scanf("%d",&opt);

	switch(opt)
	{
		case 1 : Login();
					break;
		case 2 : Register();
					break;
		default: system("cls");
					printf("Sorry you choose wrong Option\n\n");
					delay(20000);
					printf("Press any key to continue...\n");
					getch();
					main();
	}
	return 0;
}

void Login()
{
	char name[30],pass[30],txt[5]=".txt",ID[20],path[50],day[5],month[5],time[10],email[50];
	int i=0,ch,Id,date,year;
	unsigned long long mobile;
	system("cls");
	box(25,120,9,4);
	gotoxy(34,8);
	printf("*************Welcome to The Online Bill Payment Login System*************\n\n");
	delay(18000);
	gotoxy(25,12);
	printf("ID Number of the User:");
	gotoxy(100,12);
	scanf("%d",&Id);
	sprintf(ID,"%d",Id);
	strcat(ID, txt);
	strcpy(path,"C:/Mini Project/Login/");

	gotoxy(55,22);
	printf("Please Wait Processing ");
	delay(10000);
	for (int p = 0; p < 3; p++)
	{
		for (int q = 0; q < 4; q++)
		{
			printf(".");
			delay(15000);
		}
		printf("\b\b\b\b    \b\b\b\b");	
	}

	if((info=fopen(strcat(path,ID),"r"))==NULL)
	{
		gotoxy(53,22);
		printf("                        ");
		gotoxy(57,22);
		printf("Sorry Username not Found");
		gotoxy(52,23);
		printf("Enter any key to ReEnter Username\n");
		gotoxy(68,24);
		getch();
		Login();
	}
	else
	{
		inf.ID=Id;
		while((fscanf(info,"\n%s %s %s %s %d %s %d %llu %s\n",inf.Pass,inf.Name,day,month,&date,time,&year,&mobile,email))!=EOF)
		{
			Pass:
			system("cls");
			box(25,120,9,4);
			gotoxy(34,8);
			printf("*************Welcome to The Online Bill Payment Login System*************\n\n");
			gotoxy(63,12);
			delay(18000);
			printf("Hello %s\n",inf.Name);
			delay(15000);
			gotoxy(25,15);
			printf("Please Enter the Password\n");
			gotoxy(100,15);
			i=0;
			while(1)
			{
				ch=getch();
				if(ch==ENTER)
				{
					pass[i]='\0';
					break;
				}
				else if(ch==BKSP)
				{	
					printf("\b \b");
					i--;
				}
				else if(ch==TAB || ch==SPACE)
				{
					continue;
				}	
				else
				{
					pass[i]=ch;
					printf("%c",ch);		delay(10500);			printf("\b*");
					i++;
				}
			}

			if(strcmp(pass,inf.Pass)==0)
			{
				Home(1);
			}
			else
			{
				gotoxy(57,22);
				delay(15000);
				printf("You Entered Wrong Password\n");
				delay(15000);
				gotoxy(56,23);
				printf("Press any key to continue...");
				gotoxy(68,24);
				getch();
				goto Pass;
			}
		}
	}
}

//***************************************RESET PASSWORD*********************************

void Reset()
{
	char ch,pass[30],upass[30],upass1[30],Pass[30],txt[6]=".txt",path[50],Id[20],name[20],day[5],month[5],time[10];
	int i=0,id=inf.ID,date,year;
	system("cls");
	sprintf(Id,"%d",id);
	strcpy(path,"C:/Mini Project/Login/");
	strcat(Id,txt);
	if((info=fopen(strcat(path,Id),"r"))!=NULL)
	{
		while((fscanf(info,"\n%s %s %s %s %d %s %d\n",Pass,name,day,month,&date,time,&year))!=EOF)
		{
			box(25,120,9,4);
			gotoxy(34,8);
			printf("*************Welcome to The Online Bill Payment Service*************\n\n");
			delay(18000);
			gotoxy(25,12);
			printf("Enter the Current Passowrd\n");
			gotoxy(100,12);
			while(1)
			{
				ch=getch();
				if(ch==ENTER)
				{
					pass[i]='\0';
					break;
				}
				else if(ch==BKSP)
				{
					printf("\b \b");
					i--;
				}
				else if(ch==TAB || ch==SPACE)
				{
					continue;
				}
				else
				{
					pass[i]=ch;
					printf("%c",ch);
					delay(10500);
					printf("\b*");
					i++;
				}
			}
			
			delay(15000);
			gotoxy(50,22);
			printf("Please Wait While We Processing ");
			delay(10000);
			for (int p = 0; p < 3; p++)
			{
				for (int q = 0; q < 4; q++)
				{
					printf(".");
					delay(15000);
				}
				printf("\b\b\b\b    \b\b\b\b");	
			}
			gotoxy(50,22);
			printf("                                ");
			if (strcmp(pass,Pass)==0)
			{
				new_pass:
				system("cls");
				box(25,120,9,4);
				gotoxy(34,8);
				printf("*************Welcome to The Online Bill Payment Service*************\n\n");
				delay(18000);
				gotoxy(25,12);
				printf("Enter the New Passowrd\n");
				gotoxy(100,12);
				i=0;
				while(1)
				{
					ch=getch();
					if(ch==ENTER)
					{
						upass[i]='\0';
						break;
					}
					else if(ch==BKSP)
					{
						printf("\b \b");
						i--;
					}
					else if(ch==TAB || ch==SPACE)
					{
						continue;
					}
					else
					{
						upass[i]=ch;
						printf("%c",ch);		delay(10500);			printf("\b*");
						i++;
					}
				}
				delay(15000);
				gotoxy(25,14);
				printf("Enter the New Passowrd Again\n");
				i=0;
				gotoxy(100,14);
				while(1)
				{
					ch=getch();
					if(ch==ENTER)
					{
						upass1[i]='\0';
						break;
					}
					else if(ch==BKSP)
					{
						printf("\b \b");
						i--;
					}
					else if(ch==TAB || ch==SPACE)
					{
						continue;
					}
					else
					{
						upass1[i]=ch;
						printf("%c",ch);		delay(10500);			printf("\b*");
						i++;
					}
				}

				if (strcmp(upass,upass1)==0)
				{
					delay(13000);
					gotoxy(58,22);
					printf("Please Wait ");
					delay(10000);
					for (int p = 0; p < 3; p++)
					{
						for (int q = 0; q < 4; q++)
						{
							printf(".");
							delay(15000);
						}
						printf("\b\b\b\b    \b\b\b\b");
					}
					gotoxy(56,22);
					printf("             ");
					gotoxy(50,22);
					printf("Your Password Changed Successfully\n\n");
					fclose(info);
					strcpy(path,"C:/Mini Project/Login/");
					info=fopen(strcat(path,Id),"w");
					fprintf(info,"\n%s %s %s %s %d %s %d\n",upass,name,day,month,date,time,year);
					fclose(info);
					gotoxy(51,23);
					printf("Press any Key to get Back to Home\n");
					gotoxy(68,24);
					getch();
					Home(1);
				}
				else
				{
					gotoxy(58,22);
					delay(18000);
					printf("Password MisMatched\n");
					delay(18000);
					gotoxy(48,23);
					printf("Press Any Key to ReEnter The New Password\n");
					gotoxy(68,24);
					getch();
					goto new_pass;
				}		

			}
			else
			{
				gotoxy(47,22);
				delay(18000);
				printf("Wrong Password! Please Enter The Password Agian\n");
				delay(18000);
				gotoxy(52,23);
				printf("Press any key to ReEnter the Password\n");
				gotoxy(68,24);
				getch();
				Reset();
			}
			
		}
		
	}
}


//*******************REGISTER*******************

void Register()
{
	char name[20],pass[30],pass1[30],ch,txt[10]=".txt",copy[20],path[50],email[50];
	int Id,i=0,day,month,year,bal=0,dig=0,a=0,email_len;
	unsigned long long mobile,mobile1;
	time_t now;
	system("cls");
	box(25,120,9,4);
	gotoxy(29,8);
	printf("*************Welcome to The Online Bill Payment Registration System*************\n\n");
	delay(18000);
	gotoxy(25,12);
	printf("Name of the User :");
	gotoxy(100,12);
	scanf("%s",name);
	delay(15000);
	mobile:
	dig=0;
	if (a==1)
	{
		box(25,120,9,4);
		gotoxy(29,8);
		printf("*************Welcome to The Online Bill Payment Registration System*************\n\n");
		gotoxy(25,12);
		printf("Enter The Name of the User\n");
		gotoxy(100,12);
		printf("%s\n",name);
	}
	gotoxy(25,14);
	printf("Mobile Number of the User:");
	gotoxy(100,14);
	scanf("%llu",&mobile);
	mobile1=mobile;
	while (mobile1>0)
	{
		mobile1/=10;
		dig++;
	}
	if (dig!=10)
	{
		delay(15000);
		gotoxy(50,22);
		printf("Please Enter the Valid Mobile Number\n");
		gotoxy(49,23);
		delay(15000);
		printf("Press any key to ReEnter Mobile Number\n");
		gotoxy(68,24);
		getch();
		a=1;
		goto mobile;
	}
	delay(15000);
	email:
	if (a==2)
	{
		box(25,120,9,4);
		gotoxy(29,8);
		printf("*************Welcome to The Online Bill Payment Registration System*************\n\n");
		gotoxy(25,12);
		printf("Enter The Name of the User\n");
		gotoxy(100,12);
		printf("%s\n",name);
		gotoxy(25,14);
		printf("Mobile Number of the User\n");
		gotoxy(100,14);
		printf("%llu\n",mobile);
	}
	gotoxy(25,16);
	printf("Email Address of the User\n");
	gotoxy(100,16);
	scanf("%s",email);
	email_len=strlen(email);
	if ((email[email_len-10]!='@' && email[email_len-9]!='g' && email[email_len-8]!='m' && 
	email[email_len-7]!='a' && email[email_len-6]!='i' && email[email_len-5]!='l' && email[email_len-4]!='.' && 
	email[email_len-3]!='c' && email[email_len-2]!='o' && email[email_len-1]!='m') || email_len<11)
	{
		delay(15000);
		gotoxy(50,22);
		printf("Enter The Valid Email Address Again\n");
		delay(15000);
		gotoxy(49,23);
		printf("Press any Key to ReEnter Email Address\n");
		gotoxy(68,24);
		getch();
		a=2;
		goto email;
	}
	delay(15000);
	gotoxy(25,18);
	printf("Enter The Login Password\n");
	gotoxy(100,18);
	while(1)
	{
		ch=getch();
		if(ch==ENTER)
		{
			pass[i]='\0';
			break;
		}
		else if(ch==BKSP)
		{
			printf("\b \b");
			i--;
		}
		else if(ch==TAB || ch==SPACE)
		{
			continue;
		}
		else
		{
			pass[i]=ch;
			printf("%c",ch);		delay(10500);			printf("\b*");
			i++;
		}
	}
	i=0;
	delay(15000);
	gotoxy(25,20);
	printf("Enter The Login Password Again\n");
	gotoxy(100,20);
	while(1)
	{
		ch=getch();
		if(ch==ENTER)
		{
			pass1[i]='\0';
			break;
		}
		else if(ch==BKSP)
		{
			printf("\b \b");
			i--;
		}
		else if(ch==TAB || ch==SPACE)
		{
			continue;
		}
		else
		{
			pass1[i]=ch;
			printf("%c",ch);		delay(10500);			printf("\b*");
			i++;
		}
	}

	if(strcmp(pass,pass1)==0)
	{
		system("cls");
		box(25,120,9,4);
		gotoxy(29,8);
		printf("*************Welcome to The Online Bill Payment Registration System*************\n\n");
		delay(15000);
		gotoxy(45,13);
		printf("Please Wait While we Processing Your Request ");
		delay(10000);
		for (int p = 0; p < 3; p++)
		{
			for (int q = 0; q < 4; q++)
			{
				printf(".");
				delay(15000);
			}
			printf("\b\b\b\b    \b\b\b\b");
		}
		gotoxy(45,13);
		printf("                                                ");
		gotoxy(58,14);
		delay(18000);
		printf("Thanks for Registring\n\n");
		delay(18000);
		gotoxy(48,15);
		printf("Press any key to get Your Login ID Number\n\n");
		gotoxy(68,16);
		getch();
		delay(20000);
		srand(time(0));
		I:
		Id=(rand() % 99999);
		if(Id<10000)
		{
			goto I;
		}

		sprintf(copy,"%d",Id);
		strcat(copy,txt);
		strcpy(path,"C:/Mini Project/Login/");

		if((info=(fopen(strcat(path,copy),"r")))!=NULL)
		{
			goto I;
		}
		gotoxy(58,14);
		printf("                          ");
		gotoxy(48,15);
		printf("                                             ");
		gotoxy(62,14);
		printf("Please Wait ");
		delay(10000);
		for (int p = 0; p < 3; p++)
		{
			for (int q = 0; q < 4; q++)
			{
				printf(".");
				delay(15000);
			}
			printf("\b\b\b\b    \b\b\b\b");
		}
		gotoxy(62,14);
		printf("             ");
		gotoxy(66,14);
		printf("%d\n",Id);
	}
	else
	{
		printf("Sorry, Password is Mismatched\n");
		printf("Press any key to Continue...\n");
		getch();
		Register();
	}

	strcpy(path,"C:/Mini Project/Login/");

	time(&now);

	info=(fopen(strcat(path,copy), "w"));//login
	fprintf(info,"\n%s %s %s %llu %s\n",pass,name,ctime(&now),mobile,email);
	fclose(info);

	strcpy(path,"C:/Mini Project/Home/");
	info1=(fopen(strcat(path,copy), "w"));//home
	fprintf(info1,"\n%s %d %s\n",name,bal,ctime(&now));
	fclose(info1);
	gotoxy(58,20);
	printf("Press any key to Login\n");
	gotoxy(69,21);
	getch();
	Login();
}


void Home(int opte)
{
	int Bal,opt,ID=inf.ID,i=1,date,year,wall_bal,amt;
	char ch,path[50],txt[10]=".txt",Id[30],name[30],pass[20],day[5],month[5],time[10];
	char wall_pass[20],wall_name[20];
	strcpy(path,"C:/Mini Project/Home/");
	sprintf(Id,"%d",ID);
	strcat(Id,txt);
	info=fopen(strcat(path,Id), "r");//Home
	strcpy(path,"C:/Mini Project/Wallet/");
	info1=fopen(strcat(path,Id), "r");
	
	if(info1==NULL)
	{
		system("cls");
		box(25,120,9,4);
		gotoxy(29,8);
		printf("*************Welcome to The Online Bill Payment Registration System*************\n\n");
		gotoxy(52,13);
		printf("You Have Successfully Loged In\n");
		delay(18000);
		gotoxy(49,15);
		printf("You Have to Update Your Wallet First\n");
		delay(16000);
		gotoxy(55,20);
		printf("Press any Key to Continue\n");
		gotoxy(66,21);
		getch();
		Wallet(1);
	}
	while(fscanf(info,"\n%s %d %s %s %d %s %d\n", name,&Bal,day,month,&date,time,&year)!=EOF)
	{
		if (opte==2)
		{
			opt=1;
			goto Pay;
		}
		system("cls");
		box(25,120,9,4);
		gotoxy(34,8);
		printf("*************Welcome to The Online Bill Payment Service*************\n\n");
		delay(20000);
		if (Bal==0)
		{
			gotoxy(52,11);
			printf("You Are All done! Nothing to Pay\n\n");

			delay(13000);
			box(4,13,27,15);
			gotoxy(30,16);
			printf("Press %d",i++);
			gotoxy(31,17);
			printf("Wallet");
		
			box(4,13,60,15);
			gotoxy(63,16);
			printf("Press %d",i++);
			gotoxy(63,17);
			printf("Details\n");

			box(4,22,88,15);
			gotoxy(96,16);
			printf("Press %d",i++);
			gotoxy(90,17);
			printf("Resetting Password");

		}
		else
		{
			gotoxy(65,11);
			printf("%d",Bal);
			gotoxy(59,12);
			printf("Bill Amount Left");

			box(4,13,27,15);
			gotoxy(30,16);
			printf("Press %d",i);
			gotoxy(32,17);
			printf("PAY");
			i++;
			box(4,13,48,15);
			gotoxy(51,16);
			printf("Press %d",i++);
			gotoxy(52,17);
			printf("Wallet");

			box(4,13,68,15);
			gotoxy(71,16);
			printf("Press %d",i++);
			gotoxy(71,17);
			printf("Details\n");

			box(4,22,88,15);
			gotoxy(96,16);
			printf("Press %d",i++);
			gotoxy(90,17);
			printf("Resetting Password");

		}
		box(3,7,63,23);
		gotoxy(66,24);
		scanf("%d",&opt);
		if(Bal!=0)
		{
			switch(opt)
			{
				case 1 : break;
				case 2 : Wallet(2);
							break;
				case 3 : free(info);
						 free(info1);
						 Statement();
							break;
				case 4 : Reset();
							break;
				default : 

						gotoxy(61,25);
						printf("           ");
						gotoxy(61,24);
						printf("           ");
						gotoxy(62,23);
						printf("Wrong Choice\n");
						delay(18000);
						gotoxy(55,24);
						printf("Press any Key to Continue\n");
						gotoxy(66,25);
						getch();
						Home(1);
						
			}
		}
		else
		{
			switch(opt)
			{
				case 1 : Wallet(2);
							break;
				case 2 : Statement();
							break;
				case 3 : Reset();
							break;
				default : 
					
						gotoxy(61,25);
						printf("           ");
						gotoxy(61,24);
						printf("           ");
						gotoxy(62,23);
						printf("Wrong Choice\n");
						delay(18000);
						gotoxy(55,24);
						printf("Press any Key to Continue\n");
						gotoxy(66,25);
						getch();
						Home(1);
			}
		}

//******************************************************PAY*************************************************************
		Pay:
		while(fscanf(info1,"\n%d %s %s\n",&wall_bal,wall_pass,wall_name)!=EOF)
		{
			if(opt==1 && Bal!=0)
			{
				system("cls");
				box(25,120,9,4);
				gotoxy(34,8);
				printf("*************Welcome to The Online Bill Payment Wallet System*************\n\n");
				delay(18000);
				box(4,20,30,13);
				gotoxy(33,14);
				printf("Wallet Balance");
				gotoxy(37,15);
				printf("%d\n",wall_bal);

				box(4,19,93,13);
				gotoxy(97,14);
				printf("Bill Amount");
				gotoxy(100,15);
				printf("%d\n",Bal);
				delay(15000);
				box(4,29,56,19);
				gotoxy(63,20);
				printf("Enter the Amount\n");
				gotoxy(68,21);
				scanf("%d",&amt);
				if(wall_bal<amt)
				{
					int opt;
					system("cls");
					A:
					box(25,120,9,4);
					gotoxy(34,8);
					printf("*************Welcome to The Online Bill Wallet System*************\n\n");

					gotoxy(58,12);
					printf("Low Wallet Balance!\n\n");
					delay(15000);
					gotoxy(51,14);
					printf("Firstly Add money to your wallet\n\n");
					delay(15000);

					box(4,23,30,17);
					gotoxy(38,18);
					printf("Press 1");
					gotoxy(32,19);
					printf("Redirecting to Bank\n");

					box(4,18,84,17);
					gotoxy(90,18);
					printf("Press 2");
					gotoxy(89,19);
					printf("Main Menu\n");

					box(3,7,63,23);
					gotoxy(66,24);
					scanf("%d",&opt);
					if(opt==2)
					{
						Home(1);
					}
					else if(opt==1)
					{
						Bank(2);
					}
					else
					{
						gotoxy(61,25);
						printf("           ");
						gotoxy(61,24);
						printf("           ");
						gotoxy(62,23);
						printf("Wrong Choice\n");
						delay(18000);
						gotoxy(55,24);
						printf("Press any Key to Continue\n");
						gotoxy(66,25);
						getch();
						goto A;
					}
				}//wall_bal<amt If ends
				else
				{
					B:
					i=0;
					system("cls");
					box(25,120,9,4);
					gotoxy(34,8);
					printf("*************Welcome to The Online Bill Payment Wallet System*************\n\n");
					delay(18000);
					gotoxy(25,12);
					printf("Enter Your Wallet Password\n");
					gotoxy(100,12);
					while(1)
					{
						ch=getch();
						if(ch==ENTER)
						{
							pass[i]='\0';
							break;
						}
						else if(ch==BKSP)
						{
							printf("\b \b");
							i--;
						}
						else if(ch==TAB || ch==SPACE)
						{
							continue;
						}
						else
						{
							pass[i]=ch;
							printf("%c",ch);		delay(10500);			printf("\b*");
							i++;
						}
					}
					gotoxy(47,20);
					printf("Please Wait While we Processing Your Request ");
					delay(10000);
					for (int p = 0; p < 3; p++)
					{
						for (int q = 0; q < 4; q++)
						{
							printf(".");
							delay(15000);
						}
						printf("\b\b\b\b    \b\b\b\b");
					}
					gotoxy(47,20);
					printf("                                             \n");
					if(strcmp(wall_pass,pass)==0)
					{
						gotoxy(50,20);
						delay(18000);
						printf("Your Transaction is successfully Processed\n\n");
					}
					else
					{
						gotoxy(56,20);
						delay(18000);
						printf("You Entered Wrong Password!\n");
						delay(18000);
						gotoxy(57,21);
						printf("Press any Key To Continue\n");
						gotoxy(68,22);
						getch();
						goto B;
					}

					strcpy(path,"C:/Mini Project/Wallet/update.txt");
					update=fopen(path,"w");//update.txt
					wall_bal-=amt;
					fprintf(update,"\n%d %s %s\n",wall_bal,wall_pass,wall_name); 
					

					fclose(info1);
					fclose(update);
					strcpy(path,"C:/Mini Project/Wallet/");
					info1=fopen(strcat(path,Id), "w");
					strcpy(path,"C:/Mini Project/Wallet/update.txt");
					update=fopen(path,"r");

					while(fscanf(update,"\n%d %s %s\n", &wall_bal,wall_pass,wall_name)!=EOF)
					{
						fprintf(info1,"\n%d %s %s\n",wall_bal,wall_pass,wall_name);
					}
					fclose(info1);
					fclose(update);


					strcpy(path,"C:/Mini Project/Home/update.txt");
					update=fopen(path,"w");
					Bal-=amt;
					fprintf(update,"\n%s %d %s %s %d %s %d\n", name,Bal,day,month,date,time,year);
					fclose(info);
					fclose(update);
					strcpy(path,"C:/Mini Project/Home/");
					info=fopen(strcat(path,Id),"w");

					strcpy(path,"C:/Mini Project/Home/update.txt");
					update=fopen(path,"r");
					while((fscanf(update,"\n%s %d %s %s %d %s %d\n", name,&Bal,day,month,&date,time,&year))!=EOF)
					{
						fprintf(info,"\n%s %d %s %s %d %s %d\n", name,Bal,day,month,date,time,year);
					}
					fclose(info);
					fclose(update);
					delay(20000);
					gotoxy(46,20);
					printf("                                                ");
					gotoxy(55,21);
					printf("Press any key to Get Back Home\n");
					gotoxy(69,22);
					getch();
					Home(1);
				}

			}//opt==1 if ends
		}//while Ends
	}//parent while ends
}


//******************WALLET*********************

void Wallet(int opt)
{
	char wall_name[30],wall_pass[30],wall_pass1[30],ch,ch1,path[20],txt[10]=".txt",ID[20],wall_pass3[30];
	int i=0,Id=inf.ID,wall_bal=0,opt1,a=0;
	system("cls");

	if(opt==1)
	{
		strcpy(path,"C:/Mini Project/Wallet/");
		sprintf(ID,"%d",Id);
		strcat(ID,txt);
		info=fopen(strcat(path,ID), "w");
		box(25,120,9,4);
		gotoxy(34,8);
		printf("*************Welcome to The Online Bill Payment Wallet System*************\n\n");
		gotoxy(28,12);
		delay(18000);
		printf("Name of your Wallet\n");
		gotoxy(98,12);
		scanf("%s",wall_name);

		delay(18000);
		pass:
		
		if (a==1)
		{
			system("cls");
			box(25,120,9,4);
			gotoxy(34,8);
			printf("*************Welcome to The Online Bill Payment Wallet System*************\n\n");
			gotoxy(28,12);
			printf("Name of your Wallet\n");
			gotoxy(98,12);
			printf("%s\n",wall_name);
		}
		gotoxy(28,14);
		printf("Password of your Wallet\n");
		gotoxy(98,14);
		while(1)
		{
			ch=getch();
			if(ch==ENTER)
			{
				wall_pass[i]='\0';
				break;
			}
			else if(ch==BKSP)
			{
				printf("\b \b");
				i--;
			}
			else if(ch==TAB || ch==SPACE)
			{
				continue;
			}
			else
			{
				wall_pass[i]=ch;
				printf("%c",ch);		delay(10500);			printf("\b*");
				i++;
			}
		}

		i=0;
		delay(16000);
		gotoxy(28,16);
		printf("Password of your Wallet Again\n");
		gotoxy(98,16);
		while(1)
		{
			ch=getch();
			if(ch==ENTER)
			{
				wall_pass1[i]='\0';
				break;
			}
			else if(ch==BKSP)
			{
				printf("\b \b");
				i--;
			}
			else if(ch==TAB || ch==SPACE)
			{
				continue;
			}
			else
			{
				wall_pass1[i]=ch;
				printf("%c",ch);		delay(10500);			printf("\b*");
				i++;
			}
		}

		if(strcmp(wall_pass,wall_pass1)==0)
		{
			fprintf(info,"\n%d %s %s\n",wall_bal,wall_pass,wall_name);
			gotoxy(47,22);
			delay(15000);
			printf("Please Wait While we Processing Your Request ");
			delay(10000);
			for (int p = 0; p < 3; p++)
			{
				for (int q = 0; q < 4; q++)
				{
					printf(".");
					delay(15000);
				}
				printf("\b\b\b\b    \b\b\b\b");
			}
			gotoxy(47,22);
			printf("                                             ");
			gotoxy(59,22);
			delay(16000);
			printf("Thanks for Registring\n");
			delay(18000);
			gotoxy(54,23);
			printf("Press any key to get back Home\n");
			fclose(info);
			gotoxy(69,24);
			getch();
			Home(1);
		}
		else
		{
			gotoxy(55,22);
			delay(16000);
			printf("Your Password is MisMatched\n");
			delay(18000);
			gotoxy(51,23);
			printf("Press Any Key to ReEnter the Password\n");
			gotoxy(69,24);
			getch();
			a=1;
			goto pass;
		}
		
	}
	else if(opt==2)
	{
		char wall_upass[30],wall_upass1[30];
		strcpy(path,"C:/Mini Project/Wallet/");
		sprintf(ID,"%d",Id);
		strcat(ID,txt);
		info=fopen(strcat(path,ID), "r");

		while(fscanf(info,"\n%d %s %s\n",&wall_bal,wall_pass,wall_name)!=EOF)
		{
			system("cls");
			box(25,120,9,4);
			gotoxy(33,8);
			printf("*************Welcome to The Online Bill Payment Wallet System*************\n\n");
			delay(18000);
			gotoxy(63,12);
			printf("Hello %s\n",wall_name);
			delay(16000);
			gotoxy(28,16);
			printf("Password Of your Wallet:\n");
			gotoxy(100,16);
			while(1)
			{
				ch=getch();
				if(ch==ENTER)
				{
					wall_upass[i]='\0';
					break;
				}
				else if(ch==BKSP)
				{
					printf("\b \b");
					i--;
				}
				else if(ch==TAB || ch==SPACE)
				{	
					continue;
				}
				else
				{
					wall_upass[i]=ch;
					printf("%c",ch);		delay(10500);			printf("\b*");
					i++;
				}
			}

			if(strcmp(wall_upass,wall_pass)!=0)
			{
				gotoxy(56,21);
				delay(16000);
				printf("You Entered Wrong Password!\n");
				delay(18000);
				gotoxy(51,22);
				printf("Press any Key to ReEnter The Password\n");
				gotoxy(68,23);
				getch();
				Wallet(2);
			}
			system:
			system("cls");
			box(25,120,9,4);
			gotoxy(33,8);
			printf("*************Welcome to The Online Bill Payment Wallet System*************\n\n");
			delay(18000);
			gotoxy(63,11);
			printf("Hello %s\n",wall_name);
			delay(18000);

			box(4,20,59,13);
			gotoxy(62,14);
			printf("Wallet Balance\n");
			gotoxy(67,15);
			printf("%d\n",wall_bal);
			delay(16000);

			box(4,13,29,18);
			gotoxy(32,19);
			printf("Press 1\n");
			gotoxy(31,20);
			printf("Add Money\n");

			box(4,18,60,18);
			gotoxy(66,19);
			printf("Press 2\n");
			gotoxy(62,20);
			printf("Reset Password\n");

			box(4,13,94,18);
			gotoxy(97,19);
			printf("Press 3\n");
			gotoxy(99,20);
			printf("Back\n");

			box(3,7,65,24);
			gotoxy(68,25);
			scanf("%d",&opt1);
			if(opt1==1)
			{
				Bank(1);
			}
			else if(opt1==2)
			{
				passw:
				box(25,120,9,4);
				gotoxy(33,8);
				printf("*************Welcome to The Online Bill Payment Wallet System*************\n\n");
				delay(18000);
				gotoxy(28,13);
				printf("Old Password of Your Wallet:\n");
				gotoxy(100,13);
				i=0;
				while(1)
				{
					ch=getch();
					if(ch==ENTER)
					{
						wall_pass3[i]='\0';
						break;
					}
					else if(ch==BKSP)
					{		
						printf("\b \b");
						i--;
					}
					else if(ch==TAB || ch==SPACE)
					{
						continue;
					}
					else
					{
						wall_pass3[i]=ch;
						printf("%c",ch);		delay(10500);			printf("\b*");
						i++;
					}
				}

				gotoxy(62,22);
				printf("Please Wait ");
				delay(10000);
				for (int p = 0; p < 3; p++)
				{
					for (int q = 0; q < 4; q++)
					{
						printf(".");
						delay(15000);
					}
					printf("\b\b\b\b    \b\b\b\b");
				}

				if(strcmp(wall_pass3,wall_pass)==0)
				{
					new_pass:
					system("cls");
					i=0;
					box(25,120,9,4);
					gotoxy(33,8);
					printf("*************Welcome to The Online Bill Payment Wallet System*************\n\n");
					delay(18000);
					gotoxy(28,13);
					printf("New Password of your Wallet\n");
					gotoxy(100,13);
					while(1)
					{
						ch=getch();
						if(ch==ENTER)
						{
							wall_upass[i]='\0';
							break;
						}
						else if(ch==BKSP)
						{		
							printf("\b \b");
							i--;
						}
						else if(ch==TAB || ch==SPACE)
						{
							continue;
						}
						else
						{
							wall_upass[i]=ch;
							printf("%c",ch);		delay(10500);			printf("\b*");
							i++;
						}
					}

					i=0;
					delay(15000);
					gotoxy(28,15);
					printf("New Password of your Wallet Again\n");
					gotoxy(100,15);
					while(1)
					{
						ch=getch();
						if(ch==ENTER)
						{
							wall_upass1[i]='\0';
							break;
							}
						else if(ch==BKSP)
						{
							printf("\b \b");
							i--;
						}
						else if(ch==TAB || ch==SPACE)
						{
							continue;
						}
						else
						{
							wall_upass1[i]=ch;
							printf("%c",ch);		delay(10500);			printf("\b*");
							i++;
						}
					}

					if(strcmp(wall_upass,wall_upass1)==0)
					{
						gotoxy(47,22);
						printf("Please Wait While we Processing Your Request ");
						delay(10000);
						for (int p = 0; p < 3; p++)
						{
							for (int q = 0; q < 4; q++)
							{
								printf(".");
								delay(15000);
							}
							printf("\b\b\b\b    \b\b\b\b");
						}

						strcpy(path,"C:/Mini Project/Wallet/update.txt");
						update=fopen(path,"w");

						fprintf(update,"\n%d %s %s\n",wall_bal,wall_upass,wall_name);

						fclose(update);
						fclose(info);

						strcpy(path,"C:/Mini Project/Wallet/");
						info=fopen(strcat(path,ID),"w");

						strcpy(path,"C:/Mini Project/Wallet/update.txt");
						update=fopen(path,"r");

						while(fscanf(update,"\n%d %s %s\n",&wall_bal,wall_pass,wall_name)!=EOF)
						{
							fprintf(info,"\n%d %s %s\n",wall_bal,wall_pass,wall_name);
						}
						fclose(info);
						fclose(update);

						gotoxy(47,22);
						printf("                                              ");
						gotoxy(50,22);
						printf("Your Password is Successfully Changed\n");
						delay(18000);
						gotoxy(52,23);
						printf("Press any key to Back to the Home\n");
						gotoxy(69,24);
						getch();
						Home(1);
					}
					else
					{
						gotoxy(55,22);
						printf("Your Password is MisMatched\n");
						delay(18000);
						gotoxy(50,23);
						printf("Press any Key to ReEnter the Password\n");
						gotoxy(69,24);
						getch();
						goto new_pass;
					}
				}
				else
				{
					gotoxy(61,22);
					printf("Wrong Passoword!\n");
					delay(18000);
					gotoxy(51,23);
					printf("Press any Key to ReEnter The Password\n");
					gotoxy(69,24);
					getch();
					goto passw;
				}
				
			}//opt1==2 else if ends
			else if(opt1==3)
			{
				Home(1);
			}
			else
			{
				gotoxy(65,26);
				printf("             ");
				gotoxy(65,25);
				printf("             ");
				gotoxy(63,24);
				printf("Wrong Choice\n");
				delay(18000);
				gotoxy(56,25);
				printf("Press any Key to Continue\n");
				gotoxy(66,26);
				getch();
			}
			
		}//while ends

	}//main else if opt==2 ends
	else if(opt==3)
	{
		goto system;
	}

}


//***********************************************************BANK**********************************************************************

void Bank(int opte)
{
	int i=0,balance=90000,amt,wall_ball,chk=0,IDD=inf.ID,acc_no_len;
	unsigned long long acc_no,ID;
	char Id[30],txt[6]=".txt",path[40],ch,ch1,pass[20],pass1[20],name[20],ifsc[20],npass[20],
	npass1[20],wall_pas[20],wall_nam[20],Ifsc[20],Name[20],Pass[20],Idd[30],bank_name[30];

	sprintf(Idd,"%d",IDD);

	strcat(Idd,txt);

	Detail:
	system("cls");
	box(25,120,9,4);
	gotoxy(40,8);
	printf("************Welcome to the Online Banking System************\n\n");
	delay(18000);
	gotoxy(28,12);
	printf("Enter The Account Number\n");
	gotoxy(100,12);
	scanf("%llu",&ID);
	sprintf(bank_name,"%llu",ID);
	acc_no_len=strlen(bank_name);
	if (acc_no_len<10 || acc_no_len>15)
	{
		gotoxy(56,23);
		delay(18000);
		printf("You Entered Wrong Bank Account Number\n\n");
		delay(18000);
		printf("Press Any Key to ReEnter Account Number\n");
		getch();
		goto Detail;
	}
	
	Regist:
	strcpy(path,"C:/Mini Project/Bank/");
	sprintf(Id,"%llu",ID);
	strcat(Id,txt);

	if((info=fopen(strcat(path,Id),"r"))!=NULL)
	{
		int opt,opt1;
		while((fscanf(info,"\n%s %s %s %d\n",ifsc,pass,name,&balance))!=EOF)
		{
			if(chk==0)
			{
				delay(15000);
				gotoxy(28,14);
				printf("Enter IFSC Code\n");
				gotoxy(100,14);
				scanf("%s",Ifsc);
				delay(15000);
				gotoxy(28,16);
				printf("Enter Bank Account Name\n");
				gotoxy(100,16);
				scanf("%s",Name);
				gotoxy(47,22);
				printf("Please Wait While we Processing Your Request ");
				delay(10000);
				for (int p = 0; p < 2; p++)
				{
					for (int q = 0; q < 4; q++)
					{
						printf(".");
						delay(14000);
					}
					printf("\b\b\b\b    \b\b\b\b");
				}
				gotoxy(47,22);
				printf("                                            ");
				Password:
				if((strcmp(Ifsc,ifsc))==0 && (strcmp(name,Name))==0)
				{
					system("cls");
					box(25,120,9,4);
					gotoxy(34,8);
					printf("************Welcome to the Online Banking System************\n\n");
					gotoxy(28,12);
					printf("Enter The Account Number\n");
					gotoxy(100,12);
					printf("%llu\n",ID);
					gotoxy(28,14);
					printf("Enter IFSC Code\n");
					gotoxy(100,14);
					printf("%s\n",Ifsc);
					gotoxy(28,16);
					printf("Enter Bank Account Name\n");
					gotoxy(100,16);
					printf("%s\n",Name);
					gotoxy(28,18);
					printf("Enter Password\n");
					gotoxy(100,18);
					i=0;
					while(1)
					{
						ch=getch();
						if(ch==ENTER)
						{
							Pass[i]='\0';
							break;
						}
						else if(ch==BKSP)
						{
							printf("\b \b");
							i--;
						}
						else if(ch==TAB || ch==SPACE)
						{
							continue;
						}
						else
						{
							Pass[i]=ch;
							printf("%c",ch);		delay(10500);			printf("\b*");
							i++;
						}
					}
					gotoxy(58,22);
					printf("Please Wait ");
					delay(10000);
					for (int p = 0; p < 3; p++)
					{
						for (int q = 0; q < 4; q++)
						{
							printf(".");
							delay(15000);
						}
						printf("\b\b\b\b    \b\b\b\b");
					}
					gotoxy(58,22);
					printf("            ");
					if((strcmp(pass,Pass))!=0)
					{
						gotoxy(55,23);
						delay(18000);
						printf("You Entered Wrong Password!\n");
						delay(16000);
						gotoxy(56,24);
						printf("Press any Key to Continue\n");
						gotoxy(68,25);
						getch();
						goto Password;
					}
				}
				else
				{
					gotoxy(56,23);
					delay(18000);
					printf("You Entered Wrong Detail\n");
					delay(16000);
					gotoxy(56,24);
					printf("Press any Key to Continue\n");
					gotoxy(68,25);
					getch();
					goto Detail;
				}
			}
			system:
			system("cls");
			box(25,120,9,4);
			if (acc_no_len==11)
			{
				gotoxy(36,8);
				printf("*************Welcome to ICICI Online Banking System*************\n\n\n");
			}
			else if (acc_no_len==12)
			{
				gotoxy(35,8);
				printf("*************Welcome to Bank of Baroda Online Banking System*************\n\n\n");
			}
			else if (acc_no_len==13)
			{
				gotoxy(37,8);
				printf("*************Welcome to SBI Online Banking System*************\n\n\n");
			}
			else if (acc_no_len==14)
			{
				gotoxy(37,8);
				printf("*************Welcome to HDFC Online Banking System*************\n\n\n");
			}
			else if (acc_no_len==15)
			{
				gotoxy(31,8);
				printf("*************Welcome to Punjab National Bank Online Banking System*************\n\n\n");
			}
			else if (acc_no_len==10)
			{
				gotoxy(37,8);
				printf("*************Welcome to Axis Bank Online Banking System*************\n\n\n");
			}
			
			delay(18000);
			box(4,13,27,15);
			gotoxy(30,16);
			printf("Press 1\n");
			gotoxy(32,17);
			printf("PAY\n");
			box(4,19,45,15);
			gotoxy(51,16);
			printf("Press 2\n");
			gotoxy(47,17);
			printf("Account Balance\n");
			box(4,22,69,15);
			gotoxy(76,16);
			printf("Press 3\n");
			gotoxy(71,17);
			printf("Resetting Password\n");
			box(4,13,96,15);
			gotoxy(99,16);
			printf("Press 4\n");
			gotoxy(100,17);
			printf("Back\n");
			box(3,7,63,23);
			gotoxy(66,24);
			scanf("%d",&opt);

			if(opt==1)
			{
				system("cls");
				box(25,120,9,4);
				if (acc_no_len==11)
				{
					gotoxy(36,8);
					printf("*************Welcome to ICICI Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==12)
				{
					gotoxy(35,8);
					printf("*************Welcome to Bank of Baroda Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==13)
				{
					gotoxy(37,8);
					printf("*************Welcome to SBI Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==14)
				{
					gotoxy(37,8);
					printf("*************Welcome to HDFC Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==15)
				{
					gotoxy(31,8);
					printf("*************Welcome to Punjab National Bank Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==10)
				{
					gotoxy(37,8);
					printf("*************Welcome to Axis Bank Online Banking System*************\n\n\n");
				}

				gotoxy(28,13);
				printf("Enter The Amount\n");
				gotoxy(100,13);
				scanf("%d",&amt);

				if(amt<=balance)
				{
					gotoxy(47,22);
					printf("Please Wait While we Processing Your Request ");
					delay(10000);
					for (int p = 0; p < 3; p++)
					{
						for (int q = 0; q < 4; q++)
						{
							printf(".");
							delay(15000);
						}
						printf("\b\b\b\b    \b\b\b\b");
					}

					gotoxy(47,22);
					printf("                                             ");
					gotoxy(50,22);
					printf("Your Transection Is Successfully Proceed\n");
					delay(18000);
					gotoxy(57,23);
					printf("Press any Key to Continue\n");
					gotoxy(68,24);
					getch();
					balance-=amt;

					strcpy(path,"C:/Mini Project/Bank/update.txt");
					update=fopen(path,"w");
					fprintf(update,"\n%s %s %s %d\n",ifsc,pass,name,balance);
					fclose(update);
					fclose(info);
					update=fopen(path,"r");
					strcpy(path,"C:/Mini Project/Bank/");
					info=fopen(strcat(path,Id),"w");
					while((fscanf(update,"\n%s %s %s %d\n",ifsc,pass,name,&balance))!=EOF)
					{
						fprintf(info,"\n%s %s %s %d\n",ifsc,pass,name,balance);
					}
					fclose(update);
					fclose(info);


					strcpy(path,"C:/Mini Project/Wallet/");
					info1=fopen(strcat(path,Idd),"r");


					strcpy(path,"C:/Mini Project/Wallet/update.txt");
					update=fopen(path,"w");

					while((fscanf(info1,"\n%d %s %s\n",&wall_ball,wall_pas,wall_nam))!=EOF)
					{
						fprintf(update,"\n%d %s %s\n",wall_ball+amt,wall_pas,wall_nam);

					}

					fclose(update);
					fclose(info1);

					strcpy(path,"C:/Mini Project/Wallet/");
					info1=fopen(strcat(path,Idd),"w");

					strcpy(path,"C:/Mini Project/Wallet/update.txt");
					update=fopen(path,"r");

					while((fscanf(update,"\n%d %s %s\n",&wall_ball,wall_pas,wall_nam))!=EOF)
					{
						fprintf(info1,"\n%d %s %s\n",wall_ball,wall_pas,wall_nam);
					}
					fclose(info1);
					fclose(update);

					goto system;

				}
				else
				{
					gotoxy(62,22);	
					printf("Low Balance!\n");
					delay(20000);
					gotoxy(58,23);
					printf("Press any Key to Back\n");
					gotoxy(68,24);
					getch();
					goto system;
				}
			}
			else if(opt==2)
			{
				system("cls");
				box(25,120,9,4);
				if (acc_no_len==11)
				{
					gotoxy(36,8);
					printf("*************Welcome to ICICI Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==12)
				{
					gotoxy(35,8);
					printf("*************Welcome to Bank of Baroda Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==13)
				{
					gotoxy(37,8);
					printf("*************Welcome to SBI Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==14)
				{
					gotoxy(37,8);
					printf("*************Welcome to HDFC Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==15)
				{
					gotoxy(31,8);
					printf("*************Welcome to Punjab National Bank Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==10)
				{
					gotoxy(37,8);
					printf("*************Welcome to Axis Bank Online Banking System*************\n\n\n");
				}

				gotoxy(61,11);
				printf("Hello %s ",name);
				delay(18000);
				box(4,21,57,13);
				gotoxy(60,14);
				printf("Account Balance\n");
				gotoxy(63,15);
				printf("Rs. %d",balance);
				delay(20000);	
				gotoxy(56,24);
				printf("Press any Key to Continue\n");
				gotoxy(68,25);
				getch();
				goto system;

			}
			else if(opt==3)
			{
				char ch,ch1;
				Passwo:
				system("cls");
				box(25,120,9,4);
				if (acc_no_len==11)
				{
					gotoxy(36,8);
					printf("*************Welcome to ICICI Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==12)
				{
					gotoxy(35,8);
					printf("*************Welcome to Bank of Baroda Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==13)
				{
					gotoxy(37,8);
					printf("*************Welcome to SBI Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==14)
				{
					gotoxy(37,8);
					printf("*************Welcome to HDFC Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==15)
				{
					gotoxy(31,8);
					printf("*************Welcome to Punjab National Bank Online Banking System*************\n\n\n");
				}
				else if (acc_no_len==10)
				{
					gotoxy(37,8);
					printf("*************Welcome to Axis Bank Online Banking System*************\n\n\n");
				}

				delay(20000);
				gotoxy(28,13);
				printf("Enter the Old Password\n");
				gotoxy(100,13);
				i=0;
				while(1)
				{
					ch=getch();
					if(ch==ENTER)
					{
					pass1[i]='\0';
					break;
					}
					else if(ch==BKSP)
					{
						printf("\b \b");
						i--;
					}
					else if(ch==TAB || ch==SPACE)
					{
						continue;
					}
					else
					{
						pass1[i]=ch;
						printf("%c",ch);		delay(10500);			printf("\b*");
						i++;
					}
				}
				i=0;
				gotoxy(62,22);
				printf("Please Wait ");
				delay(10000);
				for (int p = 0; p < 3; p++)
				{
					for (int q = 0; q < 4; q++)
					{
						printf(".");
						delay(15000);
					}
					printf("\b\b\b\b    \b\b\b\b");
				}
				gotoxy(62,22);
				printf("             ");
				if(strcmp(pass,pass1)==0)
				{
					new_pass:
					system("cls");
					box(25,120,9,4);
					if (acc_no_len==11)
					{
						gotoxy(36,8);
						printf("*************Welcome to ICICI Online Banking System*************\n\n\n");
					}
					else if (acc_no_len==12)
					{
						gotoxy(35,8);
						printf("*************Welcome to Bank of Baroda Online Banking System*************\n\n\n");
					}
					else if (acc_no_len==13)
					{
						gotoxy(37,8);
						printf("*************Welcome to SBI Online Banking System*************\n\n\n");
					}
					else if (acc_no_len==14)
					{
						gotoxy(37,8);
						printf("*************Welcome to HDFC Online Banking System*************\n\n\n");
					}
					else if (acc_no_len==15)
					{
						gotoxy(31,8);
						printf("*************Welcome to Punjab National Bank Online Banking System*************\n\n\n");
					}
					else if (acc_no_len==10)
					{
						gotoxy(37,8);
						printf("*************Welcome to Axis Bank Online Banking System*************\n\n\n");
					}

					delay(18000);
					gotoxy(28,13);
					printf("Enter The New Password\n");
					gotoxy(100,13);
					i=0;
					while(1)
					{
						ch=getch();
						if(ch==ENTER)
						{
							npass[i]='\0';
							break;
						}
						else if(ch==BKSP)
						{
							printf("\b \b");
							i--;
						}
						else if(ch==TAB || ch==SPACE)
						{
							continue;
						}
						else
						{
							npass[i]=ch;
							printf("%c",ch);		delay(10500);			printf("\b*");
							i++;
						}
					}
					i=0;
					delay(15000);
					gotoxy(28,15);
					printf("Enter The New Password Again\n");
					gotoxy(100,15);
					while(1)
					{
						ch=getch();
						if(ch==ENTER)
						{
							npass1[i]='\0';
							break;
						}
						else if(ch==BKSP)
						{
							printf("\b \b");
							i--;
						}	
						else if(ch==TAB || ch==SPACE)
						{
							continue;
						}
						else
						{				
							npass1[i]=ch;
							printf("%c",ch);		delay(10500);			printf("\b*");
							i++;
						}
					}
					if(strcmp(npass,npass1)==0)
					{
						gotoxy(47,22);
						printf("Please Wait While we Processing Your Request ");
						delay(10000);
						for (int p = 0; p < 3; p++)
						{
							for (int q = 0; q < 4; q++)
							{
								printf(".");
								delay(15000);
							}
							printf("\b\b\b\b    \b\b\b\b");
						}
						gotoxy(47,22);
						printf("                                             ");
						delay(16000);
						gotoxy(52,23);
						printf("Successfully Changed the Password\n");
						strcpy(path,"C:/Mini Project/Bank/update.txt");
						update=fopen(path,"w");
						fprintf(update,"\n%s %s %s %d\n",ifsc,npass,name,balance);
						fclose(update);
						fclose(info);
						update=fopen(path,"r");
						strcpy(path,"C:/Mini Project/Bank/");
						info=fopen(strcat(path,Id),"w");
						while((fscanf(update,"\n%s %s %s %d\n",ifsc,pass,name,&balance))!=EOF)
						{
							fprintf(info,"\n%s %s %s %d\n",ifsc,pass,name,balance);
						}
						fclose(update);
						fclose(info);
						delay(18000);
						gotoxy(56,24);
						printf("Press any Key to Continue\n");
						gotoxy(68,25);
						getch();
						goto system;
					}
					else
					{
						delay(18000);
						gotoxy(58,22);
						printf("Password MisMatched\n");
						delay(16000);
						gotoxy(56,23);
						printf("Press any Key to Continue\n");
						gotoxy(68,24);
						getch();
						goto new_pass;
					}
					
				}
				else
				{
					delay(18000);
					gotoxy(56,22);
					printf("You Entered Wrong Password\n");
					delay(16000);
					gotoxy(56,23);
					printf("Press any Key to Continue\n");
					gotoxy(68,24);
					getch();
					goto Passwo;
				}
			}
			else if(opt==4)
			{
				if (opte==1)
				{
					Wallet(2);
				}
				else if(opte==2)
				{
					Home(2);
				}
				
			}
			else
			{
				gotoxy(63,23);
				printf("                ");
				gotoxy(63,24);
				printf("                ");
				gotoxy(63,25);
				printf("                ");
				delay(18000);
				gotoxy(61,23);
				printf("Wrong Choice\n");
				delay(16000);
				gotoxy(56,24);
				printf("Press any Key to Continue\n");	
				gotoxy(68,25);
				getch();
				goto system;
								
			}
		}
	}
	else
	{
		delay(15000);
		gotoxy(28,14);
		printf("Enter IFSC Code\n");
		gotoxy(100,14);
		scanf("%s",Ifsc);
		delay(16000);
		gotoxy(28,16);
		printf("Enter Bank Account Name\n");
		gotoxy(100,16);
		scanf("%s",Name);
		delay(16000);
		gotoxy(28,18);
		printf("Enter Password\n");
		gotoxy(100,18);
		while(1)
		{
			ch=getch();
			if(ch==ENTER)
			{
				Pass[i]='\0';
				break;
			}
			else if(ch==BKSP)
			{	
				printf("\b \b");
				i--;
			}
			else if(ch==TAB || ch==SPACE)
			{
				continue;
			}
			else
			{
				Pass[i]=ch;
				printf("%c",ch);		delay(10500);			printf("\b*");
				i++;
			}
		}
		
		strcpy(path,"C:/Mini Project/Bank/");
		info1=fopen(strcat(path,Id),"w");
		strcpy(path,"C:/Mini Project/Bank/");
		info=fopen(strcat(path,Idd),"w");

		fprintf(info1,"\n%s %s %s %d\n",Ifsc,Pass,Name,balance);
		fprintf(info,"\n%s %s %s %d %llu\n",Ifsc,Pass,Name,balance,ID);

		fclose(info1);
		fclose(info);
		chk=2;
		goto Regist;

	}

}

//*****************************************************STATEMENT**********************************************************

void Statement()
{
	char path[100],Id[15],txt[10]=".txt",login_pass[20],login_name[20],time[10],month[5],day[5],email[50],ifsc[20],
	bank_pass[20],bank_name[20],acc_name[30];
	int id=inf.ID,year,Bal,date,opt,bank_bal,opt1,acc_no_len=0,acc_nu[20],acc_name_len,a=0;
	unsigned long long mobile,acc_no,acc_num;
	Bank:
	system("cls");
	box(35,120,9,2);
	gotoxy(24,4);
	printf("*********************Welcome to Online Bill Payment Statement System*********************\n\n");
	delay(20000);
	strcpy(path,"C:/Mini Project/Login/");
	sprintf(Id,"%d",id);
	strcat(Id,txt);
	info=fopen(strcat(path,Id),"r");
	while((fscanf(info,"\n%s %s %s %s %d %s %d %llu %s\n",login_pass,login_name,day,month,&date,time,&year,&mobile,email))!=EOF)
	{
		gotoxy(38,7);
		printf("Welcome %s\n",login_name);
		gotoxy(86,7);
		printf("Customer ID: %d",inf.ID);
		delay(15000);
		gotoxy(52,9);
		printf("Your Was Created Your Account On\n");
		gotoxy(57,10);
		delay(13000);
		printf("%s %s %d %s %d\n",time,day,date,month,year);
		delay(15000);
		gotoxy(57,12);
		printf("Registerd Mobile Number\n");
		gotoxy(63,13);
		delay(13000);
		printf("%llu\n",mobile);
		delay(15000);
		gotoxy(57,15);
		printf("Registerd Email Address\n");
		gotoxy(57,16);
		delay(13000);
		printf("%s\n",email);
	}
	fclose(info);
	strcpy(path,"C:/Mini Project/Bank/");
	if ((info1=fopen(strcat(path,Id),"r"))==NULL)
	{
		A:
		if (a==1)
		{
			system("cls");
			box(35,120,9,2);
			gotoxy(24,4);
			printf("*********************Welcome to Online Bill Payment Statement System*********************\n\n");
			gotoxy(61,7);
			printf("Welcome %s\n",login_name);
			gotoxy(52,9);
			printf("Your Was Created Your Account On\n");
			gotoxy(57,10);
			printf("%s %s %d %s %d\n",time,day,date,month,year);
			gotoxy(57,12);
			printf("Registerd Mobile Number\n");
			gotoxy(63,13);
			printf("%llu\n",mobile);
			gotoxy(57,15);
			printf("Registerd Email Address\n");
			gotoxy(57,16);
			printf("%s\n",email);
		}
		
		delay(15000);
		gotoxy(53,19);
		printf("Please Update Your Bank Details!\n");
		delay(22000);
		box(4,20,27,21);
		gotoxy(33,22);
		printf("Press 1\n");
		gotoxy(30,23);
		printf("Update Details\n");
		box(4,13,94,21);
		gotoxy(97,22);
		printf("Press 2\n");
		gotoxy(98,23);
		printf("Home\n");
		box(3,9,64,28);
		gotoxy(68,29);
		scanf("%d",&opt);
		if (opt==1)
		{
			Bank(2);
			goto Bank;
		}
		else if(opt==2)
		{
			Home(1);
		}
		else
		{
			gotoxy(63,28);
			printf("                ");
			gotoxy(63,29);
			printf("                ");
			gotoxy(63,30);
			printf("                ");
			delay(18000);
			gotoxy(63,28);
			printf("Wrong Choice\n");
			delay(16000);
			gotoxy(57,29);
			printf("Press any Key to Continue\n");	
			gotoxy(69,30);
			getch();
			a=1;
			goto A;
		}		
	}

	strcpy(path,"C:/Mini Project/Bank/");
	info1=fopen(strcat(path,Id),"r");

	while ((fscanf(info1,"\n%s %s %s %d %llu\n",ifsc,bank_pass,bank_name,&bank_bal,&acc_no))!=EOF)
	{
		delay(15000);
		acc_num=acc_no;
		while (acc_num!=0)
		{
			acc_num/=10;
			acc_no_len++;
		}
		
		int p=4;
		acc_num=acc_no;
		while(p!=0)
		{
			acc_nu[p]=acc_num%10;
			acc_num/=10;
			p--;
		}
		sprintf(acc_name,"%llu",acc_no);
		acc_name_len=strlen(acc_name);
		//box(1,2,9,30);
		box(1,120,9,18);
		if (acc_name_len==11)
		{
			gotoxy(59,19);
			printf("Bank Of Maharastra\n\n");
		}
		else if (acc_name_len==12)
		{
			gotoxy(61,19);
			printf("Bank of Baroda\n\n");
		}
		else if (acc_name_len==13)
		{
			gotoxy(64,19);
			printf("SBI Bank\n\n");
		}
		else if (acc_name_len==14)
		{
			gotoxy(64,19);
			printf("HDFC Bank\n\n");
		}
		else if (acc_name_len==15)
		{
			gotoxy(58,19);
			printf("Punjab National Bank\n\n");
		}
		else if (acc_name_len==10)
		{
			gotoxy(64,19);
			printf("Axis Bank\n\n");
		}
		else if (acc_name_len==9)
		{
			gotoxy(64,19);
			printf("ICICI Bank\n\n");
		}
		delay(16000);
		gotoxy(54,21);
		printf("Registerd Bank Account Number");
		gotoxy(63,22);
		delay(13000);
		for (int i = 0; i < (acc_no_len-4); i++)
		{
			printf("X");
		}
		for (int i = 1; i <= 4; i++)
		{
			printf("%d",acc_nu[i]);
		}
		gotoxy(64,24);
		delay(15000);
		printf("IFSC Code\n");
		gotoxy(63,25);
		delay(13000);
		printf("%s\n",ifsc);
		delay(15000);
		gotoxy(59,27);
		printf("Bank Account Balance\n");
		gotoxy(66,28);
		delay(13000);
		printf("%d\n",bank_bal);
	}
	delay(20000);
	gotoxy(57,31);
	printf("Press any key to get back\n");
	gotoxy(68,32);
	getch();
	Home(1);
}
/*
void edit_detail()
{
	int id=inf.ID;
	char Id[10],txt[5]=".txt",path[30];
	sprintf(Id,"%d",id);
	strcat(Id,txt);
	strcpy(path,"C:/Mini Project/Login/");
	info=fopen(strcat(path,Id),"r");
}
*/