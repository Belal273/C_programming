#include <stdio.h>
#include <stdlib.h>
#include "../STD_TYPES.h"
#include <string.h> 

u32 check_ID_exist(u32 temp_ID);

void getting(char * temp_name);
void add_at_first(char * temp_name,u32 temp_age,u8 temp_gender,u32 temp_ID);
void print_linked_list();
void main_mode();
void admin_mode();
void four_admin_states();
void continue_four_admin_states();
void admin_mode_one();
void edit_patient_m2();
void print_ID_Data(u32 temp_ID);
void add_tolinked_after_edit(char * edited_name,u32 edited_age,u8 edited_gender,u32 temp_ID);
void reserve_slot_m3();
void reserve_in_desiredslot(u32 desired_slot,u32 patients_ID);
void print_slots();
void cancel_slot_m4();
void user_mode();
void user_mode_one();
void user_mode_two();
void continue_four_admin_states_fromUser_mode();

typedef struct patient
{
u8 name[50];
u32 age;
u8 gender;
u32 ID;	
struct patient * next;
}patient;

typedef struct slots
{
u32 slot1;
u32 ID1;
u32 slot2;
u32 ID2;
u32 slot3;
u32 ID3;
u32 slot4;
u32 ID4;
//struct slots * next2;
}slots;
slots check_available_slots = {0,0,0,0,0,0,0,0};

patient * Head=NULL;
slots * Head2 = NULL;
u32 name_size=0;

void main()
{
	main_mode();
	
}

void main_mode()
{
	u16 mode;

printf("\nPlease Enter 0 to enter admin mode or 1 to enter user mode: ");
scanf("%d",&mode);  

if (mode == 0)
{
	admin_mode();
}
else if (mode == 1)
{
    user_mode();
}
else
{
	printf("\nError unidentified mode please restart");
}

}

void admin_mode()
{
	u16 def_pass = 1234;
	u16 user_pass;
	u16 count_pass=0;
	u16 adm_mode;
printf("\nYou are now in admin mode,please enter password: ");
scanf("%d",&user_pass);
while (user_pass != 1234)
{
	count_pass++;
	if (count_pass == 3)
		break;
	else
	{
		printf("\nWrong password please try again: ");
		scanf("%d",&user_pass);
	}
		
}
if (count_pass == 3)
	printf("\nYou entered the password wrong 3 times!");
else
{
	four_admin_states();
}
	
}

void four_admin_states()
{
	u16 adm_mode;
printf("\nWelcome!");
printf("\nPlease Enter 1 to add new patient record");
printf("\nEnter 2 to edit patient record");
printf("\nEnter 3 to reserve a slot with the doctor");
printf("\nEnter 4 to cancel the reservation\n");
scanf("%d",&adm_mode);
  if (adm_mode == 1)
  { 
	admin_mode_one();
  }
  else if (adm_mode == 2)
  {
	  edit_patient_m2();
  }
  else if (adm_mode == 3)
  {
	  reserve_slot_m3();
  }
  else if (adm_mode == 4)
  {
	  cancel_slot_m4();
  }
  else
  {
	  printf ("\nGood bye!");
  }

}

void continue_four_admin_states()
{
	u16 adm_mode;
	u8 want_continue;
	printf("\nTo go back and choose between states please enter 1: \n ");
	//printf("\nTo go back to user mode please enter 2: \n ");
	scanf("%d",&want_continue);
	if (want_continue == 1)
	{
printf("\nWelcome!");
printf("\nPlease Enter 1 to add new patient record");
printf("\nEnter 2 to edit patient record");
printf("\nEnter 3 to reserve a slot with the doctor");
printf("\nEnter 4 to cancel the reservation\n");
scanf("%d",&adm_mode);
  if (adm_mode == 1)
  { 
	admin_mode_one();
  }
  else if (adm_mode == 2)
  {
	  edit_patient_m2();
  }
  else if (adm_mode == 3)
  {
	  reserve_slot_m3();
  }
  else if (adm_mode == 4)
  {
	  cancel_slot_m4();
  }
  else
  {
	  printf ("\nGood bye!");
  }
  
  }
  
  else
	printf ("\nThanks and Good bye!");
	

}


void continue_four_admin_states_fromUser_mode()
{
	u16 adm_mode;
	u8 want_continue;
	printf("\nTo go back and choose between states please enter 1: \n ");
	printf("\nTo go back to user mode please enter 2: \n ");
	scanf("%d",&want_continue);
	if (want_continue == 1)
	{
	admin_mode();
	}
	 else if (want_continue == 2)
	user_mode();
else
	printf ("\nThanks and Good bye!");
}

void admin_mode_one()
{
	printf("\nAddnig new patient:");
	
    char temp_name[50];
    u32 temp_age;
    u8 temp_gender;
    u32 temp_ID;
	u8 is_ID_exist =0 ;
    printf("\nPlease Enter the ID: ");
	scanf("%d",&temp_ID);
	is_ID_exist=check_ID_exist(temp_ID);
	  if (is_ID_exist == 1)
	  {
		printf("\nError ID already exists");
		continue_four_admin_states();
	  }
	  else
	  {
		  printf("\nOkay, This ID is unique!");
		  printf("\nPlease Enter the name: \n");
		  getting(temp_name);
		  printf("\nPlease Enter the age: ");
		  scanf("%d",&temp_age);
		  printf("\nPlease Enter m for male or f for female: \n"); 
		  
		 scanf(" %c", &temp_gender);
		 
		 add_at_first(temp_name,temp_age,temp_gender,temp_ID);
		 print_linked_list();
         continue_four_admin_states_fromUser_mode();
	  }
}

void edit_patient_m2()
{
	char edited_name[50];
    u32 edited_age;
    u8 edited_gender;
    u32 temp_ID;
	u8 is_ID_exist =0 ;
    printf("\nPlease Enter the ID: ");
	scanf("%d",&temp_ID);
	is_ID_exist=check_ID_exist(temp_ID);
	  if (is_ID_exist == 1)
	  {
		printf("\nOkay, The ID is in our Database");
		printf("\nThe data before Editing: ");
		print_ID_Data(temp_ID);
		printf("\nPlease Enter the name: \n");
		getting(edited_name);
		printf("\nPlease Enter the age: ");
		scanf("%d",&edited_age);
		printf("\nPlease Enter m for male or f for female: \n"); 
	    scanf(" %c", &edited_gender);
		add_tolinked_after_edit( edited_name,edited_age, edited_gender,temp_ID);
		printf("\nThe data after Editing: ");
		//print_ID_Data(temp_ID);
		print_linked_list();
		//continue_four_admin_states();
	  }
	  else
	  {
		 printf("\nIncorrect ID !");
		// continue_four_admin_states();
	  }
	  continue_four_admin_states_fromUser_mode();
}

void add_tolinked_after_edit(char * edited_name,u32 edited_age,u8 edited_gender,u32 temp_ID)
{
	patient * pn =(patient *)malloc(sizeof(patient));
	u32 i;
	u8 size;
	patient * tempsize = Head;
	while (tempsize != NULL)
	{
		//printf("\nin While1");
		if (temp_ID == tempsize->ID)
			  {
				  //printf("\nin if1");
				   for (i=0;i<name_size;i++)
	                {
		              tempsize->name[i]=edited_name[i];
		         
	                }
	                  tempsize->name[i]=0;
					  //printf("\nThe name is %s",tempsize->name);
	                  tempsize->age=edited_age;
					  //printf("\nTEST The age is %d",tempsize->age);
	                  tempsize->gender=edited_gender;
					  //printf("\nTEST The gender is %C",tempsize->gender);
					  break;
			   }
		tempsize=tempsize->next;
		size++ ;
	}
	//printf("\n The size is %d",size);
	
	//patient * temp = Head;
	/*
		while (temp_ID != pn->ID)
		{
			 printf("\nin While2");
			if (temp_ID == pn->ID)
			  {
				  printf("\nin if");
				   for (i=0;i<name_size;i++)
	                {
		              pn->name[i]=edited_name[i];
		         
	                }
	                  pn->name[i]=0;
					  printf("\nThe name is %s",pn->name);
	                  pn->age=edited_age;
					  printf("\nTEST The age is %d",pn->age);
	                  pn->gender=edited_gender;
					  printf("\nTEST The gender is %C",pn->gender);
					  break;
			   }
			   
			
			pn=pn->next;
		}
		 printf("\nafter While");
	*/
	/*
	    pn->next=NULL;
	if (Head == NULL)
		Head = pn;
	else 
	{
		patient * temp = Head;
		Head = pn;
		pn->next=temp;
	}
*/
	
}

void print_ID_Data(u32 temp_ID)
{
	patient * pn = Head;
	
	while (pn != NULL)
	{
		if (temp_ID == pn->ID)
		{
		printf("\nThe name is %s",pn->name);
		printf("\nThe age is %d",pn->age);
		printf("\nThe gender is %C",pn->gender);
		printf("\nThe ID is %d",pn->ID);
		}
		pn=pn->next;
		
	}
}

void reserve_slot_m3()
{
	//slots * tempslot = Head2;
		//while (tempslot != NULL)
		//{
			//slots check_available
			u32 patients_ID;
			u32 desired_slot;
			u8 is_ID_exist =0 ;
			u8 is_print_slots=0;
			if (check_available_slots.slot1 == 0)
				printf("\nFirst slot is Available");
			if (check_available_slots.slot2 == 0)
				printf("\nSecond slot is Available");
			if (check_available_slots.slot3 == 0)
				printf("\nThird slot is Available");
			if (check_available_slots.slot4 == 0)
				printf("\nFourth slot is Available");
			//tempslot=tempslot->next2;
            printf("\nPlease Enter the ID: ");
	        scanf("%d",&patients_ID);
	        is_ID_exist=check_ID_exist(patients_ID);
	        if (is_ID_exist == 1)
	        {
		      printf("\nOkay, The ID is in the Database");
		      printf("\n Please choose a slot from the available slots");
			  printf("\n Enter 1 to reserve the first slot , 2 for the second,etc: ");
			  scanf("%d",&desired_slot);
			  reserve_in_desiredslot(desired_slot,patients_ID);
			  //continue_four_admin_states();
			  //Reserve The Slot 
			  //Remove from available 
			  //Associate the ID with its slot , add slot in patient struct
	        }
	        else
	       {
			 printf("\nIncorrect ID !");
		     //continue_four_admin_states();   
		   }
		    printf("\nEnter 1 to Show The state of each slot");
	        scanf("%d",&is_print_slots);
	        if (is_print_slots == 1)
		    print_slots();
		
			//continue_four_admin_states();
			continue_four_admin_states_fromUser_mode();
		//}
}

void reserve_in_desiredslot(u32 desired_slot,u32 patients_ID)
{
	switch (desired_slot)
			  {
				case 1:
				if (check_available_slots.slot1 == 0)
				{
					check_available_slots.slot1 =1;
				    check_available_slots.ID1 =patients_ID;
					printf("\nYou reserved in the first slot successfully! ");
					break;
				}
				else if (check_available_slots.slot1 == 1)
				{
					printf("\nFirst Slot is Already reserved ");
					break;	
				}
				//if (check_available_slots.slot1 != 0)
					//printf("\nPosition 1 is not Available");
				    //break;
				case 2:
				 if (check_available_slots.slot2 == 0)
				 {
					check_available_slots.slot2 =1;
				    check_available_slots.ID2 =patients_ID;
					printf("\nYou reserved in the second slot successfully!  ");
					break;
				 }
				 else if (check_available_slots.slot2 == 1)
				{
					printf("\nSecond Slot is Already reserved ");
					break;	
				}
				//if (check_available_slots.slot2 != 0)
					//printf("\nPosition 2 is not Available");
				   // break;
				case 3:
                if (check_available_slots.slot3 == 0)
				{
					check_available_slots.slot3 =1;
				    check_available_slots.ID3 =patients_ID;
					printf("\nYou reserved in the third slot successfully!  ");
					break;
				}
				else if (check_available_slots.slot3 == 1)
				{
					printf("\nThird Slot is Already reserved ");
					break;	
				}
				//if (check_available_slots.slot3 != 0)
					//printf("\nPosition 3 is not Available");
				    //break;
				case 4:
				if (check_available_slots.slot4 == 0)
				{
					check_available_slots.slot4 =1;
				    check_available_slots.ID4 =patients_ID;
					printf("\nYou reserved in the fourth slot successfully!  ");
					break;
				}
				else if (check_available_slots.slot4 == 1)
				{
					printf("\nFourth Slot is Already reserved ");
					break;	
				}
				//if (check_available_slots.slot4 != 0)
					//printf("\nPosition 4 is not Available");
				  //  break;
				default:
				printf("\nError Please Enter from 1 to 4");
				reserve_in_desiredslot(desired_slot,patients_ID);
			  }
}
void print_slots()
{
	if (check_available_slots.slot1 == 1)
		printf("\nFirst Slot is reserved by the ID: %d",check_available_slots.ID1);
	else 
		printf("\nFirst slot is still available ");
	if (check_available_slots.slot2 == 1)
		printf("\nSecond Slot is reserved by the ID: %d",check_available_slots.ID2);
	else 
		printf("\nSecond slot is still available ");
	if (check_available_slots.slot3 == 1)
		printf("\nThird Slot is reserved by the ID: %d",check_available_slots.ID3);
	else 
		printf("\nThird slot is still available ");
	if (check_available_slots.slot4 == 1)
		printf("\nFourth Slot is reserved by the ID: %d",check_available_slots.ID4);
	else 
		printf("\nFourth slot is still available ");
}

void cancel_slot_m4()
{
	u32 patients_ID;
			u32 desired_slot;
			u8 is_ID_exist =0 ;
			u8 is_print_slots=0;
            printf("\nTo Cancel your reservation, Please Enter the ID: ");
	        scanf("%d",&patients_ID);
	        is_ID_exist=check_ID_exist(patients_ID);
	        if (is_ID_exist == 1)
	        {
		      if (patients_ID == check_available_slots.ID1)
			  {
				  check_available_slots.slot1=0;
				  check_available_slots.ID1=0;
				  printf("\nThe reservation in the first slot is cancelled");
			  }
			  else if (patients_ID == check_available_slots.ID2)
			  {
				  check_available_slots.slot2=0;
				  check_available_slots.ID2=0;
				  printf("\nThe reservation in the second slot is cancelled");
			  }
			  else if (patients_ID == check_available_slots.ID3)
			  {
				  check_available_slots.slot3=0;
				  check_available_slots.ID3=0;
				  printf("\nThe reservation in the third slot is cancelled");
			  }
			  else if (patients_ID == check_available_slots.ID4)
			  {
				  check_available_slots.slot4=0;
				  check_available_slots.ID4=0;
				  printf("\nThe reservation in the fourth slot is cancelled");
			  }
			  else
				  printf("\nYou did not reserve a slot !");
			}
	        else
	       {
			 printf("\nIncorrect ID !");
		     //continue_four_admin_states();   
		   }
		    printf("\nEnter 1 to Show The state of each slot");
	        scanf("%d",&is_print_slots);
	        if (is_print_slots == 1)
		    print_slots();
		
			//continue_four_admin_states();
			continue_four_admin_states_fromUser_mode();
}


void user_mode()
{
	u8 two_user_modes = 0;
	printf("\nWelcome, You are now in user mode");
    printf("\nPlease Enter 1 to View patient record");
    printf("\nEnter 2 to View the reservations: \n");
	
    scanf("%d",&two_user_modes);
     if (two_user_modes == 1)
	 {
	   user_mode_one();
	 }
      else if (two_user_modes == 2)
	  {
		  user_mode_two();
	  }
	  else
		  printf ("\nGood bye!");
	
}

void user_mode_one()
{
    u32 temp_ID;
	u8 is_ID_exist =0 ;
    printf("\nPlease Enter the ID: ");
	scanf("%d",&temp_ID);
	is_ID_exist=check_ID_exist(temp_ID);
	  if (is_ID_exist == 1)
	  {
		printf("\nOkay, The ID is in our Database");
		printf("\nThis is the patients' information: ");
		print_ID_Data(temp_ID);	
	  }
	  else
	  {
		 printf("\nIncorrect ID !");
	  }
	   continue_four_admin_states_fromUser_mode();
}

void user_mode_two()
{
	print_slots();
		
     continue_four_admin_states_fromUser_mode();
	
}

u32 check_ID_exist(u32 temp_ID)
{
	u8 status=0;
	patient * pn = Head;
	
	while (pn != NULL)
	{
		if (temp_ID == pn->ID)
		{
		status=1;
	    break;
		}
		pn=pn->next;
		
	}
	return status;
}

void getting(char * temp_name)
{
int character;
int i = 0;

getchar();
	while((character=getchar()) != '\n')
	{
		
		temp_name[i]=character;
		i++;
	}
	name_size=i;
	temp_name[i]=0;
	
	
}



void add_at_first(char * temp_name,u32 temp_age,u8 temp_gender,u32 temp_ID)
{
	patient * pn =(patient *)malloc(sizeof(patient));
	u32 i;
	for (i=0;i<name_size;i++)
	{
		pn->name[i]=temp_name[i];
		
	}
	pn->name[i]=0;
	pn->age=temp_age;
	pn->gender=temp_gender;
	pn->ID=temp_ID;
	pn->next=NULL;
	if (Head == NULL)
		Head = pn;
	else 
	{
		patient * temp = Head;
		Head = pn;
		pn->next=temp;
	}

	
}

void print_linked_list()
{
	if (Head == NULL)
		printf("\nThe List is empty");
	else
	{
		patient * temp = Head;
		while (temp != NULL)
		{
			printf("\nThe name is %s",temp->name);
			printf("\nThe age is %d",temp->age);
			printf("\nThe gender is %C",temp->gender);
			printf("\nThe ID is %d",temp->ID);
			temp=temp->next;
		}
		
	}
	
}
	


