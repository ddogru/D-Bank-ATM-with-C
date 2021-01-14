/*************************************************\
|* Code with <3                                   |
|* Created by Dilara Doðru & Buðra Bürüngüz       |
|* 2019-07-18                                     |
|* BugraBurunguz@gmail.com *dilosdogru35@gmail.com|
\************************************************/
//admin: kullanýcý adý 1453 password 1903
//user kullanýcý adý 3838 password 3438
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

struct userDTO{	
	char userID[5];
	char userName[15];
	int userPassword;
	float money;
	int IBANNo;
	float debt;
	int isUserActive;
	int fileSize;
	int fileSize2;
}userR;
struct adminDTO{
	
	char adminID[5];
	char adminName[15];
	int  adminPassword;
}adminR;
void adminAdd(struct adminDTO* adminR);
void userAdd(struct userDTO* userW);
void drawingCashScreen();
void drawingCash(struct userDTO* userR);
void otherAmountMoney(struct userDTO* userR);
void transferMoney(struct userDTO* userR);
void transferMoneyScreen();
void userDelete(struct userDTO *userR);
void userList(struct userDTO* userR);
void mainScreenMenu();
void mainMenuScreen();
void startApp(struct userDTO *userR, struct adminDTO *adminR);
void startAppScreen();
void login(struct userDTO* userR);
void adminLogin(struct adminDTO *adminR,struct userDTO *userR);
void adminScreen();
void adminScreenMenu(struct userDTO *userR);
void userDetail(struct userDTO *userR);
void loadMoney(struct userDTO *userR);
void lastScreen();

void adminAdd(struct adminDTO* adminR){
    int adminSize,i,choice;
	setlocale(LC_ALL,"Turkish");
	printf("How many admin you will add?: "); 	scanf("%d", &adminSize);
    FILE *fptr=fopen("adminDTO.txt","a+");
    	for(i=0; i<adminSize; i++){
	 		fflush(stdin);
        	printf("Enter ID: "); 			scanf("%d",&(adminR+i)->adminID);
        	printf("Enter Name: "); 		scanf("%s",(adminR+i)->adminName);
        	printf("Enter Password: "); 	scanf("%d",&(adminR+i)->adminPassword);
			fwrite((adminR+i),sizeof(struct adminDTO),1,fptr);
    	}
   	fclose(fptr);
   	printf("Enter 1 to complete or 9 to turn menu:"); scanf("%d",&choice);
   	switch(choice){
   		case 1:{
   			lastScreen();
			break;
		   }
		case 9:{
			adminScreen();
			break;
		}
	   }
}
void userAdd(struct userDTO *userR){
	int userSize,fileSize,i,choice;
    setlocale(LC_ALL,"Turkish");
	printf("How many user you will add?: "); scanf("%d", &userSize);
    FILE *cmp=fopen("userDTO.txt","a+");
	   for(i=0; i<=userSize; i++){
			printf("Enter ID: "); 					scanf("%s",(userR+i)->userID);
        	printf("Enter Name: "); 				scanf("%s",(userR+i)->userName);
        	printf("Enter IBAN: ");					scanf("%d",&(userR+i)->IBANNo);
        	printf("Enter Money: ");				scanf("%f",&(userR+i)->money);
        	printf("Enter Password(4 digit): ");	scanf("%d",&(userR+i)->userPassword);
        	printf("Enter Debt: "); 				scanf("%f",&(userR+i)->debt);
        	printf("Enter the activity statu:"); 	scanf("%d",&(userR+i)->isUserActive);
        	fwrite((userR+i),sizeof(struct userDTO),1,cmp);
    	}
    fclose(cmp);
		printf("Enter 1 to complete or 9 to turn menu:"); scanf("%d",&choice);
   	switch(choice){
   		case 1:{
   			lastScreen();
			break;
		   }
		case 9:{
			adminScreen();
			break;
		}
	   }
}
void drawingCashScreen(){
	printf(" __________             ___________________ \n");
	printf("|1) 10TL   |           |5)100TL            |\n");
	printf("|__________|           |___________________|\n");
	printf("|2) 20TL   |           |6)250TL            |\n");
	printf("|__________|           |___________________|\n");
	printf("|3) 30TL   |           |7)1000TL           |\n");
	printf("|__________|           |___________________|\n");
	printf("|4) 50TL   |           |8)OTHER AMOUNT TL: |\n");
	printf("|__________|           |___________________|\n");
	printf("|		   |           |9)RETURN		   |\n");
	printf("|__________|           |___________________|\n\n");
	}	
void drawingCash(struct userDTO* userR){ 
	int moneyChoice,userID;
	drawingCashScreen();
	FILE *cmp=fopen("userDTO.txt","r+");
	printf("%.2f",userR->money);
	printf("Enter your choice:"); 	scanf("%d",&moneyChoice);
	switch(moneyChoice){
	case 1:{
		system("cls");
		userR->money-=10;
		printf("%.2f",userR->money);
		fseek (cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		printf("\nPlease enter a key to complete:");
		getch();
		system("cls");
		lastScreen();
		break;
		}
	case 2:{
		system("cls");
		userR->money-=20;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		printf("\nPlease enter a key to complete:");
		getch();
		system("cls");
		lastScreen();
		break;}
	case 3:{
		system("cls");
		userR->money-=30;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		printf("\nPlease enter a key to complete:");
		getch();
		system("cls");
		lastScreen();
		break;
		}
	case 4:{
		system("cls");
		userR->money-=50;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		printf("\nPlease enter a key to complete:");
		getch();
		system("cls");
		lastScreen();
		break;
		}
	case 5:{
		system("cls");
		userR->money-=100;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		printf("\nPlease enter a key to complete:");
		getch();
		system("cls");
		lastScreen();
		break;
		}
	case 6:{
		system("cls");
		userR->money-=250;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		printf("\nPlease enter a key to complete:");
		getch();
		system("cls");
		lastScreen();
		break;
		}
	case 7:{
		system("cls");
		userR->money-=100;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
		fclose(cmp);
		printf("\nPlease enter a key to complete:");
		getch();
		system("cls");
		lastScreen();
		}
	case 8:{
		system("cls");
		otherAmountMoney(userR);
		break;
		}
	case 9:{
		system("cls");
		mainScreenMenu(userR);
		break;
	}
	}
}
void otherAmountMoney(struct userDTO* userR){
	int amount;
	FILE *cmp=fopen("userDTO.txt","r+");
	printf("Please enter an amount: \n"); 	scanf("%d",&amount);
	if(amount>userR->money){
		system("cls");
		printf("You cannot withdraw this amount of money! Please try again...");
		drawingCash(userR);
	}
	else if(amount%10!=0){
		system("cls");
		printf("Please enter the multiples of 10!");
		drawingCash(userR);	
	}
	else{
		userR->money-=amount;
		printf("%.2f",(userR)->money);
		fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
		fwrite(userR,sizeof(struct userDTO),1,cmp);
	}
	fclose(cmp);
	printf("\nPlease enter a key to complete:");
	getch();
	system("cls");
	lastScreen();
}
void transferMoney(struct userDTO *userR){
	char account[4];
	int amount,i,transferType,otherCustomerIBAN,fileSize;
	transferMoneyScreen();
	printf("What is your choice?"); scanf("%d",&transferType);
	FILE *cmp=fopen("userDTO.txt","r+");
	switch(transferType){
		case 1:{
			system("cls");
			printf("Please enter other customer's IBAN: "); 	scanf("%d",&otherCustomerIBAN);
			printf("Please enter amount:"); 					scanf("%d",&amount);
			userR->money-=amount;
			fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
			fwrite(userR,sizeof(struct userDTO),1,cmp);
			printf("Remaining money:%.2f",userR->money);
				for(i=0;i<3;i++){
					fread(userR,sizeof(struct userDTO),1,cmp);
					if(userR->IBANNo==otherCustomerIBAN){
						userR->money+=amount;
						printf("Current money of %d:%.2f",otherCustomerIBAN,userR->money);
						fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
						fwrite(userR,sizeof(struct userDTO),1,cmp);
						printf("%d Money has been sent successfully!",amount);
					}
				}
				printf("\nPlease enter a key to complete:");
				getch();
				system("cls");
				lastScreen();		
		break;
		}
		case 2:{
			system("cls");
			printf("In this case 10 TL will be charged from your account!\n");
			printf("Please enter other customer's IBAN: "); 	scanf("%d",&otherCustomerIBAN);
			printf("Please enter amount:"); 					scanf("%d",&amount);
			userR->money-=10+amount;
			fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
			fwrite(userR,sizeof(struct userDTO),1,cmp);
			printf("Remaining money:%.2f",userR->money);	
			printf("\nPlease enter a key to complete:");
			getch();
			system("cls");
			lastScreen();
		break;
		}
		case 3:{
			system("cls");
			printf("In this case 50 TL will be charged from your account!");
			printf("Please enter other customer's IBAN: "); 	scanf("%d",&otherCustomerIBAN);
			printf("Please enter amount:"); 					scanf("%d",&amount);
			userR->money-=50+amount;
			fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
			fwrite(userR,sizeof(struct userDTO),1,cmp);
			printf("Remaining money:%.2f",userR->money);	
			printf("\nPlease enter a key to complete:");
			getch();
			system("cls");
			lastScreen();
		break;
		}
	}
	
	fclose(cmp);
}
void transferMoneyScreen(){
	printf(" ___________________________\n");
	printf("|1)	DBANK TO DBANK          |\n");
	printf("|___________________________|\n");
	printf("|2) DBANK TO OTHER BANK     |\n");
	printf("|___________________________|\n");
	printf("|3) DBANK TO FOREIGN BANK   |\n");
	printf("|___________________________|\n");
	printf("|4) CANCEL                  |\n");
	printf("|___________________________|\n");
}
void userDelete(struct userDTO *userR){
	int i,choice;
	char userID1[5];
    userList(userR);
	printf("The ID of user that will be deleted:"); 	scanf("%s",userID1);
	FILE *cmp=fopen("userDTO.txt","r+");
		while(!feof(cmp)){
			fread(userR,sizeof(struct userDTO),1,cmp);
			if(strcmp(userR->userID,userID1) == 0){
				userR->isUserActive=0;
				fseek(cmp,1*sizeof(struct userDTO), SEEK_CUR);
				fwrite(userR,sizeof(struct userDTO),1,cmp);
			}
		}
	fclose(cmp);
    fflush(stdin);
    printf("Enter 1 to complete or 9 to turn menu:"); scanf("%d",&choice);
   	switch(choice){
   		case 1:{
   			lastScreen();
			break;
		   }
		case 9:{
			adminScreenMenu(userR);
			break;
		}
	   }
}
void userList(struct userDTO *userR){
	int i,choice;
	FILE *cmp=fopen("userDTO.txt","r");
		while(!feof(cmp)){
    		fread(userR,sizeof(struct userDTO),1,cmp);
			printf("* ID: %s\nName: %s\nIBAN: %d\nStatu: %d*\n", userR->userID, userR->userName,userR->IBANNo,userR->isUserActive);
    	}
    fclose(cmp);
    printf("Enter 1 to complete or 9 to turn menu:"); scanf("%d",&choice);
   	switch(choice){
   		case 1:{
   			lastScreen();
			break;
		   }
		case 9:{
			adminScreenMenu(userR);
			break;
		}
	   }
}
void mainScreenMenu(struct userDTO *userR){
	int secim;
	mainMenuScreen();
	scanf("%d",&secim);
	switch(secim){
		case 1 :{
			drawingCash(userR);
			break;
		}
		case 2 :{
			transferMoney(userR);
			break;
		}
		case 3:{
			loadMoney(userR);
			break;
		}
		case 4:{
			userDetail(userR);
			break;
		}
		case 5:{
			main();
			break;
		}
		default :{
			printf("Please choose from the list!");
			mainScreenMenu(userR);
			break;
		}
	}
}
void loadMoney(struct userDTO *userR){
	int amount,choice;
	FILE *cmp=fopen("userDTO.txt","r+");
	printf("Enter 1 to continue or 9 to turn back:"); scanf("%d",&choice);
	switch(choice){
		case 1:{
			printf("Please enter an amount: \n"); scanf("%d",&amount);
			if(amount%10!=0){
				system("cls");
				printf("Please enter the multiples of 10!");
				loadMoney(userR);	
			}
			else{
				userR->money+=amount;
				printf("\nMoney has been loaded successfully.");
				printf("\n%.2f TL",userR->money);
				fseek(cmp,1*sizeof(struct userDTO),SEEK_CUR);
				fwrite(userR,sizeof(struct userDTO),1,cmp);
				printf("\nPlease enter a key to complete:");
				getch();
				system("cls");
				lastScreen();
			}
			fclose(cmp);
			break;
		}
		case 9:{
			mainScreenMenu(userR);
			break;
		}
		
	}
	
}
void mainMenuScreen(){
	system("cls");
	printf(" ____________________             __________________ \n");
	printf("|1)DRAWING CASH      |           |4)ACCOUNT DETAIL  |\n");         
	printf("|____________________|           |__________________|\n");
	printf("|2)TRANSFERING MONEY |           |5)CANCEL          |\n");
	printf("|____________________|           |__________________|\n");
	printf("|3)LOADING MONEY     |\n");
	printf("|____________________|\n\n");
	printf("Enter your choice");
}
void startAppScreen(){
	system("cls");
	printf(" __________________ \n");
	printf("|1) Customer Login |\n");         
	printf("|__________________|\n");
	printf("|2) Admin Login    |\n");
	printf("|__________________|\n");
}
void startApp(struct userDTO *userR, struct adminDTO *adminR){
	int choice,a;
	startAppScreen();
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			login(userR);
			break;
		}
		case 2:{
			adminLogin(adminR,userR);
			break;
		}
	}
}
void login(struct userDTO *userR){
	int password;
	char id[5];
	FILE *cmp=fopen("userDTO.txt","r");
	printf("Please enter your ID:\n"); 	scanf("%s",id);
	printf("Please enter your password:"); 				scanf("%d",&password);
	while(!feof(cmp)){
	    fread(userR,sizeof(struct userDTO),1,cmp);
		if((strcmp(id,userR->userID)==0)&&(password==userR->userPassword)){
			printf("Login is successful!");
			system("cls");
			mainScreenMenu(userR);
			break;
			}
		}
	fclose(cmp);
}
void adminLogin(struct adminDTO *adminR,struct userDTO *userR){
	int password;
	char id[5];
	FILE *cmp=fopen("adminDTO.txt","r");
	printf("Please enter your ID: "); 	scanf("%s",id);
	printf("Please enter your password: "); 		scanf("%d",&password);
	while(!feof(cmp)){
		fread(adminR,sizeof(struct adminDTO),1,cmp);
		if((strcmp(id,adminR->adminID)==0)&&(password==adminR->adminPassword)){
			printf("Login is succesful!");
			adminScreenMenu(userR);
			break;
			}
		}
	fclose(cmp);
}
void adminScreen(){
	system("cls");
	printf(" ___________________         _________________ \n");
	printf("|1)ADDING (USER) 	|       |4)ADDING (ADMIN) |\n");         
	printf("|___________________|       |_________________|\n");
	printf("|2)DELETING (USER)  |       |5)IPTAL          |\n");
	printf("|___________________|       |_________________|\n");
	printf("|3)USER DETAIL      |\n");
	printf("|___________________|\n\n");
	printf("Enter your choice:");
}
void adminScreenMenu(struct userDTO *userR){
	int secim;
	adminScreen();
	scanf("%d",&secim);
	switch(secim){
		case 1 :{
			system("cls");
			userAdd(userR);
			break;
		}
		case 2 :{
			system("cls");
			userDelete(userR);
			break;
		}
		case 3:{
			userList(userR);
			break;
		}
			case 5:{
			system("cls");
			main();
			break;
		}
		default :{
			printf("Please choose from the list.");
			adminScreenMenu(userR);
			break;
		}
	}
}
void userDetail(struct userDTO *userR){
	int choice;
	system("cls");
	printf("Name %s \n IBAN: TR %d \n Money: %2.f TL ",userR->userName,userR->IBANNo,userR->money);
	printf("\nEnter 1 to complete or 9 to turn Menu"); 	scanf("%d",&choice);
	switch(choice){
		case 1:{
			lastScreen();
			break;
		}
		case 9:{
			mainScreenMenu(userR);
			break;
		}
	}
}
void lastScreen(){
	printf(" _______________________________\n");
	printf("|   Thanks for choosing us...   |\n");
	printf("|                        D Bank |\n");
	printf("|_______________________________|\n");
}
int main() {
	setlocale(LC_ALL, "Turkish"); 
	struct userDTO *userR=(struct userDTO*)malloc(3*sizeof(struct userDTO));
	struct adminDTO *adminR=(struct adminDTO*)malloc(1*sizeof(struct adminDTO));
	startApp(userR,adminR);
	// kullanýcý kaydý
	/*int i;
	FILE *cmp=fopen("userDTO.txt","w");
	for(i=0;i<3;i++){
			printf("Enter ID: "); 					scanf("%s",(userR+i)->userID);
        	printf("Enter Name: "); 				scanf("%s",(userR+i)->userName);
        	printf("Enter IBAN: ");					scanf("%d",&(userR+i)->IBANNo);
        	printf("Enter Money: ");				scanf("%f",&(userR+i)->money);
        	printf("Enter Debt: "); 				scanf("%f",&(userR+i)->debt);
        	printf("Enter Password(4 digit): ");	scanf("%d",&(userR+i)->userPassword);
        	printf("Active"); scanf("%d",&(userR+i)->isUserActive);
        	fwrite((userR+i),sizeof(struct userDTO),1,cmp);
        	fread((userR+i),sizeof(struct userDTO),1,cmp);
        	printf("%s \n %s \n %d \n %f  \n %f  \n %d ",(userR+i)->userID,(userR+i)->userName,(userR+i)->IBANNo,(userR+i)->money,(userR+i)->debt,(userR+i)->isUserActive);
	}
	fclose(cmp);*/
	
	// admin kaydý
	/*FILE *fptr=fopen("adminDTO.txt","w");
			printf("Enter ID: "); 			scanf("%s",adminR->adminID);
        	printf("Enter Name: "); 		scanf("%s",adminR->adminName);
        	printf("Enter Password: "); 	scanf("%d",&adminR->adminPassword);
			fwrite(adminR,sizeof(struct adminDTO),1,fptr);
			fclose(fptr);
			fread(adminR,sizeof(struct adminDTO),1,fptr);
			printf("%s  %s  %d",adminR->adminID,adminR->adminName,adminR->adminPassword);*/
	
	//customers
	/* ID:a123 NAME:Dilara IBAN:111111 MONEY:10000 DEBT:300 PASSWORD:3535 STATU:1
	   ID:b123 NAME:Bugra IBAN:222222 MONEY:20000 DEBT:400 PASSWORD:3434 STATU:1
	   IDc123 NAME:Ahmet IBAN:333333 MONEY:30000 DEBT:500 PASSWORD:6161 STATU:1*/
	
	//admin
	/* ID:t123 NAME:Taner PASSWORD:7777*/
	

	return 0;
}
