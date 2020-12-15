#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include <conio.h>
#include <string.h>
#define password 1234

//#define    NULL       ((void *)0)

struct paitent
{
	u8 name[80];
	u8 gander[10];
	u16 age,ID, date;
	struct paitent * nextptr;
};
//int n,i,j=0,a=0,sum=0,g,flag,num;//global val
struct paitent * head=NULL;
struct paitent * tail=NULL;
struct paitent * arr[5]={NULL};
struct paitent * IDsearch(u16 key);
void AddInfo();
void ViewInfo();
void EdDis (u16 key);
void EditInfo();
void CheckPrint ();
void CheckReserv (u16 key);
void Reservation (u16 key,u8 choice);
void CancelReserv (u16 key,u8 choice);
void UserDis (u16 key);


void main ()
{
	u8 x,i,a,choice,choice1;
	u16 kk,uv,aa,z,pass,key,key1;
	printf("To Enter Admin Mode Enter : 1\n");
	printf("To Enter User Mode Enter : 2\n");
	scanf(" %d", &x);
	fflush(stdin);
	switch (x)
	{
		case 1:
		system("cls");
		printf("Welcome Admin \n");
		printf("Please Enter Your Password :");
	    scanf(" %d", &pass);
		fflush(stdin);
		system("cls");
		if (pass == password)
		{
			while (1)
			{
				printf("To Add New Patient Enter 1 \n");
				printf("To Display Paitent File Enter 2 \n");
	            printf("To Edit Patient Enter 3 \n");
	            printf("To Reserve Date Enter 4 \n");
				printf("To Cancel Reservation Enter 5\n");
		        printf("To Exit Enter 6 \n");
			    scanf(" %d" ,&a);
				fflush(stdin);
				switch (a)
				{
					case 1 :
					system("cls");
					AddInfo();
					break;
					case 2:
					system("cls");
					ViewInfo();
					break;
					case 3:
					system("cls");
					printf("Please Enter The Paitent ID \n");
					EditInfo();
					break;
					case 4:
					system("cls");
					CheckPrint();
					printf("Please Enter The Paitent ID : ");				
					scanf(" %d" ,&key);
					fflush(stdin);
					if(IDsearch(key) != NULL)
					{
					    printf("Please Enter The Date : ");
					    scanf(" %d" ,&choice);
						fflush(stdin);
					    CheckReserv(key);
					    Reservation(key,choice);
					    
					}
					else if (IDsearch(key) == NULL)
					{
						printf("This ID Is Not Exist -_-\n");
					}
					break;
					case 5:
					system("cls");
					printf("Please Enter paitent ID : ");
					scanf(" %d" ,&key1);
					fflush(stdin);
					if (IDsearch(key1) != NULL)
					{
						printf("Please Enter The Date You Want To Cancel ");
						scanf(" %d" ,&choice1);
						fflush(stdin);
						CancelReserv(key1,choice1);
					}
					else if (IDsearch(key1) == NULL)
					{
						printf("This ID Is Not Exist -_-\n");
					}
					break;
				}
				if(a==6)
				{
					printf("Thank You :)");
					break;
				}
			}
		}
		else if (pass != password)//in case of wrong pass
		{
			for (i=0;i<3;i++)
			{
				printf("Please Enter Password Again : ");
				scanf(" %d", &pass);
				fflush(stdin);
				if (pass == password)// in case he enter correct passs in trial 
				{
			        while (1)
			        {
			            printf("To Add New Patient Enter 1 \n");
				        printf("To Display Paitent File Enter 2 \n");
	                    printf("To Edit Patient Enter 3 \n");
	                    printf("To Reserve Date Enter 4 \n");
						printf("To Cancel Reservation Enter 5 \n");
		                printf("To Exit Enter 6 \n");
			            scanf(" %d", &a);
						fflush(stdin);
				        switch (a)
				        {
					        case 1 :
							system("cls");
					        AddInfo();
					        break;
					        case 2:
							system("cls");
					        ViewInfo();
					        break;
					        case 3:
							system("cls");
					        printf("Please Enter The Paitent ID \n");
					        EditInfo();
					        break;
					        case 4:
							system("cls");
					        printf("Please Enter The Paitent ID : ");
					        scanf(" %d", &key);
							fflush(stdin);
							break;	
                            case 5:
							system("cls");
                    	    printf("Please Enter paitent ID : ");
					        scanf(" %d", &key1);
							fflush(stdin);
					        if (IDsearch(key1) != NULL)
					        {
						        printf("Please Enter The Date You Want To Cancel ");
						        scanf(" %d" ,&choice1);
								fflush(stdin);
						        CancelReserv(key1,choice1);
					        }
							//in case the id not registered
					        else if (IDsearch(key1) == NULL)
					        {
						        printf("This ID Is Not Exist -_-\n");
					        }
					        break;        							
				        }
                        //to Exit From Prog 						
						if (a==6)
						{
							printf("Thank You :) ");
							break;
						}
				
			        }
				}
			}
			//to test the condition after the for loop
			if (pass!=password)
			{
			    printf("Incorrect password for 3 times : No more tries :(");				
			}
		}
		break;
		//for User
		case 2:
		system("cls");
		printf("Welcome You Entered As A User :) \n");
		while (1)
		{
		    printf("To Display Paitent Enter : 1 \n");
		    printf("To View Today's Reservation Enter : 2\n");
			printf("To Exit Enter : 3\n");
		    scanf(" %d", &z);
			fflush(stdin);
		    switch (z)
			{
				case 1:
				system("cls");
                EdDis(z);
				break;
				case 2:
				system("cls");
				UserDis(z);
				break;
            }
            if (z==3)
			{
				printf("Thank You :)");
				break;
			}				
		}
	}
}

//ID SEARCH 
struct paitent * IDsearch(u16 key)
{
	struct paitent * ptr;
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr -> ID == key)
		{
			return ptr;
		}			
		ptr = ptr -> nextptr;
	}
	return NULL;
}

//ADD INFORMATION
void AddInfo()
{
	struct paitent * ptr;
	u16 key;
	u8 i;
	ptr=(struct paitent *)malloc(sizeof(struct paitent));
	system("cls");
	printf("Please Enter The ID Number To Add Paitent  : ");
	scanf(" %d", &key);
	fflush(stdin);
	system("cls");
	if (ptr != NULL)
	{
		if (IDsearch(key) == NULL)
		{
			ptr -> ID = key;
			printf("Please Enter Paitent Age : ");
			scanf(" %d" ,&(ptr -> age));
			fflush(stdin);
			printf("Please Enter Paitent Gander (Male) OR (Female) :");
			gets(&(ptr->gander[i]));
			fflush(stdin);
			printf("Please Enter Paitent Name :");
			gets(&(ptr->name[i]));
			fflush(stdin);
			//here i will think in reservation case 
			if (head == NULL)
			{
				head = ptr;
				tail = ptr;
				ptr -> nextptr = NULL;
			}
			else
			{
				tail -> nextptr = ptr;
				tail = ptr;
				tail -> nextptr =NULL;
			}
		}
		else if (IDsearch(key)!= NULL)
		{
			printf("This ID Is Already Exist -_- \n");
		}
	}
		
}

//View Information
void ViewInfo()
{
	struct paitent * ptr;
	u16 key;
	u8 i;
	system("cls");
	printf("Display paitent File please Enter the paitent ID : ");
	scanf(" %d" ,key);
	fflush(stdin);
	system("cls");
	if (IDsearch(key) != NULL)
	{
		ptr = IDsearch(key);
		printf("Paitent ID Is : %d\n " ,ptr -> ID);
		printf("Paitent Age Is : %d\n" ,ptr -> age);
		printf("Paitent Gender Is : %c\n" ,ptr -> gander);
		printf("Patient Name is : %c\n" ,ptr -> name);
		printf("\n\n");
		printf("Paitent Date Is : %d\n" ,ptr -> date);
	}
	else if (IDsearch(key) == NULL)
	{
		printf("Paitent Is Not Registered -_- \n");
		system("cls");
	}
}

// the paitent file
void EdDis (u16 key)
{
	struct paitent * ptr;
	u8 i;
	system("cls");
	printf("Paitent Old File ");
	if (IDsearch(key) != NULL)
	{
		ptr = IDsearch(key);
		printf("Paitent ID Is : %d\n " ,ptr -> ID);
		printf("Paitent Age Is : %d\n" ,ptr -> age);
		printf("Paitent Gender Is : %c\n" ,ptr -> gander);
		printf("Patient Name is : %c\n" ,ptr -> name);
		printf("\n\n");
		printf("Paitent Date Is : %d\n" ,ptr -> date);
	}
	else if (IDsearch(key) == NULL)
	{
		printf("Paitent Is Not Registered -_- \n");
		system("cls");
	}
}

//Edit Information

void EditInfo()
{
	struct paitent * ptr;
	u8 i, choice;
	u16 key;
	//system("cls");
	//printf("Paitent Old File ");
	scanf(" %d" ,&key);
	fflush(stdin);
	if (IDsearch(key) != NULL)
	{
		//to display the old data
		EdDis(key);
		//to make ptr hold the user pointer
		ptr = IDsearch(key);
		printf("Paitent New Age : ");
		scanf(" %d" ,&(ptr -> age));
		fflush(stdin);
		printf("Paitent New Gander : ");
		gets(&(ptr -> gander[i]));
		fflush(stdin);
		printf("Paitent New Name : ");
		gets(&(ptr -> name[i]));
		fflush(stdin);
		printf("\n");
		printf("Paitent New Date : ");
		CheckPrint();
		scanf(" %d" ,&choice);
		fflush(stdin);
		CheckReserv(key);
		Reservation(key,choice);
	}
	else if (IDsearch(key) == NULL)
	{
		printf("Paitent Is Not Registered -_- \n");
		system("cls");
	}
}

//checkprint 

void CheckPrint ()
{
	system("cls");
	if (arr[0]==NULL)
	{
		printf("The First Date from 2PM T0 2:30PM To Choice Enter  1 : \n");
	}
	if (arr[1]==NULL)
	{
		printf("The Second Date From 2:30PM To 3PM To Choice Enter 2 : \n");
	}
	if (arr[2]==NULL)
	{
		printf("The Third Date From 3PM To 3:30PM To Choice Enter  3 : \n");
	}
	if (arr[3]==NULL)
	{
		printf("The Fourth Date From 3:30PM To 4PM To Choice Enter 4 : \n");
	}
	if (arr[4]==NULL)
	{
		printf("The Last Date From 4PM To 4:30PM To Choice Enter  5 : \n");
	}
}

//check Reservation

void CheckReserv (u16 key)
{
	struct paitent * ptr ;
	system("cls");
    ptr=IDsearch(key);
	if(ptr != NULL)//to check if the id is exist or not 
	{
		if(arr[0] == ptr)//to check if the paitent reserve or not 
		{
			printf("This ID Is Already Reserved\n");
			EdDis(key);//to display the paitent file 
		}
		else if (arr[1] == ptr)
		{
			printf("This ID Is Already Reserved\n");
			EdDis(key);//to display the paitent file
		}
		else if (arr[2] == ptr)
		{
			printf("This ID Is Already Reserved\n");
			EdDis(key);//to display the paitent file
		}
		else if (arr[3] == ptr)
		{
			printf("This ID Is Already Reserved\n");
			EdDis(key);//to display the paitent file
		}
		else if (arr[4] == ptr)
		{
			printf("This ID Is Already Reserved\n");
			EdDis(key);//to display the paitent file
		}
	}
	else if (ptr == NULL)
	{
		printf("This ID Is Not Exist -_-\n");
	}
}

//Reservation
void Reservation (u16 key,u8 choice)
{
	struct paitent * ptr;
	system("cls");
	if(IDsearch(key)!= NULL)
	{  
		if (choice == 1)
		{
			ptr -> date = choice;
			arr[0] = ptr;	
		}
		else if (choice == 2)
		{
			ptr -> date = choice;
			arr[1] = ptr;
		}
		else if (choice == 3)
		{
			ptr -> date = choice;
			arr[2] = ptr;
		}
		else if (choice == 4)
		{
			ptr -> date = choice;
			arr[3] == ptr;
		}
		else if (choice == 5)
		{
			ptr -> date = choice;
			arr[4] == ptr;
		}
	}
	else if (IDsearch(key) == NULL)
	{
		printf("Paitent Is Not Registered -_-\n");
	}
}

//Canceling Reservation 

void CancelReserv (u16 key,u8 choice)
{
	struct paitent * ptr;
	ptr = IDsearch(key);
	ptr -> date = choice;
	if (ptr -> date == 1)
	{
		//it will empty the paitent fail
		arr[0] = NULL;
	}
	else if (ptr -> date == 2)
	{
		arr[1] = NULL;
	}
	else if (ptr -> date == 3)
	{
		arr[2] = NULL;
	}
	else if (ptr -> date == 4)
	{
		arr[3] = NULL;
	}
	else if (ptr -> date == 5)
	{
		arr[4] = NULL;
	}
	
}

//User  To Display 

void UserDis (u16 key)
{
	struct paitent * ptr;
	system("cls");
	if (IDsearch(key) != NULL)
	{
		ptr=IDsearch(key);
		CheckPrint();
		printf("Paitent Reserve Slot Number : %d" ,ptr -> date);
		if (arr[0] != NULL)
		{
			printf("Paitent Reserve Slot Number : %d" ,arr[0] -> date);
		}
		if (arr[1] != NULL)
		{
			printf("Paitent Reserve Slot Number : %d" ,arr[1] -> date);
		}
		if(arr[2] != NULL)
		{
			printf("Paitent Reserve Slot Number : %d" ,arr[2] -> date);
		}
		if(arr[3] != NULL)
		{
			printf("Paitent Reserve Slot Number : %d" ,arr[3] -> date);
		}
		if (arr[4]!=NULL)
		{
			printf("Paitent Reserve Slot Number : %d" ,arr[4] -> date);
		}
	}
	else if (IDsearch(key) == NULL)
	{
		printf("This ID Is Not Exist -_-\n");
	}
}

