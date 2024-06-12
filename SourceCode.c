// the library needed to code this program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function prototype
void getUserInput(char *type);	 
void calculation(char *type);		
void receipt(char *type);			
void printreceipt(char *type);		

struct inventory		// initialization for structure inventory
{
	int quantity [3][4];
	float price [3][4];
	float totalitem [3][4];
	float total [3];
	float total_all;
	float tax;
	float total_rounding;
}member, notmember, *pmember = &member, *pnotmember = &notmember;

main()  // start main function
{  

	// declairing string inside the table
	char a, b, type[5];
	char* ary1[5][3] = {
	{"|  \t","\t\t\t   |  Non Member Price  |","Members Price (-20%)|"},
	{"|Clothing per kg Minimum\t   |\t\t\t|\t\t\t|\n   |order quantity of 4kg\t","|\tRM 6.00\t","\t|\tRM 4.80\t\t|"},
	{"|Bed Linen / Towels per kg\t   |\t\t\t|\t\t\t|\n   |Minimum order quantity of 2kg  |","   RM 9.00\t|","\tRM 7.20\t\t|"},
	{"|Blanket / Comforter /\t   |\t\t\t|\t\t\t|\n   |Duvet [ single ] per item\t","|\tRM 16.00\t|","\tRM 12.80\t|"},
	{"|Blanket /Comforter /\t   |\t\t\t|\t\t\t|\n   |Duvet [ queen ] per item\t","|\tRM 20.00\t|","\tRM 16.00\t|"}};

	char* ary2[5][3] = {
	{"| \t","\t\t\t   |  Non Member Price\t|","  Members Price (-20%)|"},
	{"|Shorts / Jeans / Pants /\t   |\t\t\t|\t\t\t  |\n   |Slack / Trousers\t","\t   |\tRM 11.00\t|","\t   RM 8.80\t  |"},
	{"|Blouse / Shirt [sequin ]\t","|\tRM 20.00\t|","\t   RM 16.00\t  |"},
	{"|Cardigan / Pullover / Sweater  | ","RM 15.00\t|","\t   RM 12.00\t  |"},
	{"|Jump Suit [women]\t","\t   |\tRM 30.00\t|","\t   RM 24.00\t  |"}};
	
	char* ary3[5][3] = {
	{"| \t","\t\t\t  |   Non Member Price\t|","Members Price (-20%)|"},
	{"|Curtain Per Kg\t","\t  |\tRM 24.00\t|","     RM 19.20\t|"},
	{"|Curtain + removing &\t  |\t\t\t|\t\t\t|\n   |hanging per kg\t","\t  |\tRM 34.00\t|","     RM 27.20\t|"},
	{"|Carpet / Prayer Mat per sqft  |","\tRM 5.00\t","\t|\t RM 4.00\t|"},
	{"|Cushion Cover per kg\t  |","\tRM 30.00\t|","\t RM 24.00\t|"}};
	
	// initializing the value for item's price
	member.price[0][0] = 4.8,  member.price[0][1] = 7.2, member.price[0][2] = 12.8, member.price[0][3] = 16;
	notmember.price[0][0] = 6, notmember.price[0][1] = 9, notmember.price[0][2] = 16, notmember.price[0][3] = 20;
	member.price[1][0] = 8.8, member.price[1][1] = 16, member.price[1][2] = 12, member.price[1][3] = 24;
	notmember.price[1][0] = 11, notmember.price[1][1] = 20, notmember.price[1][2] = 15, notmember.price[1][3] = 30;
	member.price[2][0] = 19.2, member.price[2][1] = 27.2, member.price[2][2] = 4, member.price[2][3] = 24;
	notmember.price[2][0] = 24, notmember.price[2][1] = 34, notmember.price[2][2] = 5, notmember.price[2][3] = 30;
	
	// start construct table for displaying price list
	printf("MyDobi Laundry Price\n\n");
	printf("1. Wash & Fold \n   Machine washed and machine dried. Returned crisply folded.\n\n");
	printf("\n   ______________________________________________________________________________\n");
	
	for(a=0;a<5;a++){
		for(b=0;b<3;b++){
			printf("   %s", ary1[a][b]);
		}
		printf("\n   |_______________________________|____________________|_______________________|\n");
	}
	
	printf("\n\n");
	printf("2. Garment Cleaning \n   Skillfully cleaned and pressed. Returned on a hanger. We follow the care label to ensure the best results.\n\n");
	printf("\n   ________________________________________________________________________________\n");
	
	for(a=0;a<5;a++){
		for(b=0;b<3;b++){
			
			printf("   %s", ary2[a][b]);
		}
		printf("\n   |_______________________________|____________________|_________________________|\n");
	}
	
	printf("\n\n");
	printf("3. Curtains & Household \n   Professional team to take down, clean & reinstall your curtain.\n\n");
	printf("\n   ______________________________________________________________________________\n");
	
	for(a=0;a<5;a++){
		for(b=0;b<3;b++){
			printf("   %s", ary3[a][b]);
		}
		printf("\n   |______________________________|_____________________|_______________________|\n");
	}
	
	// end of price list
	printf("\n\n");
	
	printf("Attention!!!\nTo all our beloved customers, please enter all your input with small capital letters to avoid error into the system.\n");
	printf("Please put a value of zero if you don't want to use any specific service.\nThank you -_^.\n\n\n");
	printf("Are you a member? Please type \"yes\" or \"no\"\nInput : ");
	scanf("%s", &type);
	
	// user must input the correct string or the statement below will be display again
	while(strcmp(type, "yes") != 0 && strcmp(type, "no") != 0)
	{
		printf("Please enter \"yes\" or \"no\"");
		printf("\n\nAre you a member? Please type \"yes\" or \"no\"\nInput : ");
		scanf("%s", &type); // getting the input for "type"
	}
	
	// calling the function
	getUserInput(type);
	calculation(type);
	receipt(type);
	printreceipt(type);
	
	return 0;		
} // exit main function

void getUserInput(char *type)		// getUserInput function's parameter
{
	int option; 					// declaire the variables
	char addcloth[5];				
	
	strcpy(addcloth, "yes");
	
	if(strcmp(type, "yes") == 0)		// member will given 20% discount
	{									// start if
		printf ("You are eligible for 20%% discount\n");
		
		while (strcmp(addcloth, "no") != 0)		
		{
			b1:
			printf ("\n\nWhat wash program do you want to use? Please choose one of the below.(Please enter the number as the input)\n");
			printf ("1. Wash & Fold\n");
			printf ("2. Garment Cleaning\n");
			printf ("3. Curtains & Household\nInput : ");
			scanf ("%d", &option);	
			
			// input by the user will select the option provided.
			
			if(option == 1)
			{
				b2:
				printf("\n\nHow many kg of clothing do you want? Min clothing weight is 4 kg.\nInput : ");
				scanf("%d", &member.quantity[0][0]);
				
				if (member.quantity[0][0] < 4)
				{
					if (member.quantity[0][0] == 0)
					{
						goto b3;
					}

					printf ("\nMinimum order for clothing is 4kg. You need to order 4kg or more.\n");
					goto b2;		
				}
				
				b3:
				printf("\nHow many kg of bed linen or towel do you want? Min is 2 kg.\nInput : ");
				scanf("%d", &member.quantity[0][1]);
					
				if (member.quantity[0][1] < 2)
				{
					if (member.quantity[0][1] == 0)
					{
						goto b4;
					}

					printf ("\n\nMinimum order for bed linen and towel is 2kg. You only can order 2kg and more.");
					goto b3;		
				}
				
				b4:
				printf("\nHow many blanket, comforter or duvet for single size do you want?\nInput : ");
				scanf("%d", &member.quantity[0][2]);
							
				printf("\nHow many blanket, comforter or duvet for queen size do you want?\nInput : ");
				scanf("%d", &member.quantity[0][3]);
			}
			
			else if(option == 2)
			{
				printf("\nHow many Shorts, Jeans, Pants, Slack, Trousers do you want to clean?\nInput : ");
				scanf("%d",&member.quantity[1][0]);
				
				printf("\nHow many Blouse, Shirt[sequin] do you want to clean?\nInput : ");
				scanf("%d",&member.quantity[1][1]);
				
				printf("\nHow many Cardigan, Pullover, Sweater do you want to clean?\nInput : ");
				scanf("%d",&member.quantity[1][2]);
				
				printf("\nHow many Jump Suit [women] do you want to clean?\nInput : ");
				scanf("%d",&member.quantity[1][3]);
			}
			
			else if(option ==3)
			{
				printf ("\nHow many kg of curtain do you want?\nInput : ");
				scanf ("%d", &member.quantity[2][0]);
				
				printf ("\nHow many kg of curtain + removing & hanging do you want?\nInput : ");
				scanf ("%d", &member.quantity[2][1]);
							
				printf ("\nHow many carpet or prayer mat per squarefeet do you want?\nInput : ");
				scanf ("%d", &member.quantity[2][2]);
						
				printf ("\nHow many kg of cushion cover do you want?\nInput : ");
				scanf ("%d", &member.quantity[2][3]);	
			}
			
			else		// if user enter the wrong number or using character. This will be the output.
			{
				printf ("\nYou have request the wrong option.\nPlease enter either option 1, 2 or 3.\n");
				goto b1;
			}
			
			printf("\nDo you want to add cloth for other wash program. Please type \"yes\" or \"no\"\nInput : ");
			scanf("%s", &addcloth);
			
			// if the user input the the wrong character or using number. 
			// the output will be given below.
			// the user must enter the correct string.
			
			while(strcmp(addcloth, "yes") != 0 && strcmp(addcloth, "no") != 0)
			{
				printf("Please enter either \"yes\" or \"no\"\n");
				printf("\nDo you want to add cloth for other wash program. Please type \"yes\" or \"no\"\nInput : ");
				scanf("%s", &addcloth);
			}
		}
	} // exit if
	else   // start else
	{		
		printf ("You are not eligible for 20%% discount\n");
		
		while(strcmp(addcloth, "no") != 0)		// if user input "no" for member 
		{
			c1:
			printf ("\n\nWhat wash program do you want to use? Please choose one of the below.(Please enter the number as the input)\n");
			printf ("1. Wash & Fold\n");
			printf ("2. Garment Cleaning\n");
			printf ("3. Curtains & Household\nInput : ");
			scanf ("%d", &option); 			
			
			// option will be selected from the user input
			
			if(option == 1)
			{
				c2:
				printf("\n\nHow many kg of clothing do you want? Min clothing weight is 4 kg.\nInput : ");
				scanf("%d", &notmember.quantity[0][0]);
				
				if (notmember.quantity[0][0] < 4)
				{
					if (notmember.quantity[0][0] == 0)
					{
						goto c3;
					}

					printf ("\nMinimum order for clothing is 4kg. You need to order 4kg or more.\n");
					goto c2;		
				}
				
				c3:
				printf("\nHow many kg of bed linen or towel do you want? Min is 2 kg.\nInput : ");
				scanf("%d", &notmember.quantity[0][1]);
					
				if (notmember.quantity[0][1] < 2)
				{
					if (notmember.quantity[0][1] == 0)
					{
						goto c4;
					}

					printf ("\n\nMinimum order for bed linen and towel is 2kg. You only can order 2kg and more.");
					goto c3;		
				}
				
				c4:
				printf("\nHow many blanket, comforter or duvet for single size do you want?\nInput : ");
				scanf("%d", &member.quantity[0][2]);
							
				printf("\nHow many blanket, comforter or duvet for queen size do you want?\nInput : ");
				scanf("%d", &notmember.quantity[0][3]);
			}
			
			else if(option == 2)
			{
				printf("\nHow many Shorts, Jeans, Pants, Slack, Trousers do you want to clean?\nInput : ");
				scanf("%d",&notmember.quantity[1][0]);
				
				printf("\nHow many Blouse, Shirt[sequin] do you want to clean?\nInput : ");
				scanf("%d",&notmember.quantity[1][1]);
				
				printf("\nHow many Cardigan, Pullover, Sweater do you want to clean?\nInput : ");
				scanf("%d",&notmember.quantity[1][2]);
				
				printf("\nHow many Jump Suit [women] do you want to clean?\nInput : ");
				scanf("%d",&notmember.quantity[1][3]);	
			}
			
			else if(option == 3)
			{
				printf ("\nHow many kg of curtain do you want?\nInput : ");
				scanf ("%d", &notmember.quantity[2][0]);
				
				printf ("\nHow many kg of curtain + removing & hanging do you want?\nInput : ");
				scanf ("%d", &notmember.quantity[2][1]);
						
				printf ("\nHow many carpet or prayer mat per squarefeet do you want?\nInput : ");
				scanf ("%d", &notmember.quantity[2][2]);
			
				printf ("\nHow many kg of cushion cover do you want?\nInput : ");
				scanf ("%d", &notmember.quantity[2][3]);
			}
			
			else 
			{
				printf ("\nYou have request the wrong option.\nPlease enter either option 1, 2 or 3.\n");
				goto c1;
			}
			
			printf("\nDo you want to add cloth for other wash program. Please type \"yes\" or \"no\"\nInput : ");
			scanf("%s", &addcloth);
			
			while(strcmp(addcloth, "yes") != 0 && strcmp(addcloth, "no") != 0) // comparing user input weither yes or no
			{
				printf("\nPlease enter either \"yes\" or \"no\"\n");
				printf("\nDo you want to add cloth for other wash program. Please type \"yes\" or \"no\"\nInput : ");
				scanf("%s", &addcloth);
			}
		}
	} // exit else
}  // exit getUserInput function

void calculation(char *type)		// parameter for calculation function
{
	int i,j;
	member.total_all = 0, notmember.total_all = 0;
	
	for(i = 0; i<3; i++){
		member.total[i] = 0;
		notmember.total[i] = 0;
	}
	
	if (strcmp(type, "yes") == 0)		// calcution for the member will be 20% less than non member
	{
		for (i = 0; i<3; i++){
			for (j = 0; j<4; j++){
				member.totalitem[i][j] = member.quantity[i][j] * member.price[i][j];
				member.total[i] = member.total[i] + member.totalitem[i][j];
			}
			member.total_all = member.total_all + member.total[i];
		}
		member.tax = member.total_all * 6/100;
		member.total_rounding = member.total_all + member.tax;
	}
	
	else			/* else for non member */
	{
		for (i = 0; i<3; i++){
			for (j = 0; j<4; j++){
				notmember.totalitem[i][j] = notmember.quantity[i][j] * notmember.price[i][j];
				notmember.total[i] = notmember.total[i] + notmember.totalitem[i][j];
			}
			notmember.total_all = notmember.total_all + notmember.total[i];
		}	
		notmember.tax = notmember.total_all * 6/100;
		notmember.total_rounding = notmember.total_all + notmember.tax;
	}
} // exit calculation function

void receipt (char *type)  // parameter for receipt function
{
	//declairing the variables
	char fName [100] = {"|\t\t\t\t\t\tMyDobi Receipt.\t\t\t\t\t\t\t\t|"};
	char servh[3][50] = {"Wash & Fold\t", "Garment Cleaning", "Curtains & Household"};
	char servb[3][4][100] = {
	{"Clothing\t\t\t\t", "Bed Linen / Towels\t\t\t", "Blanket / Comforter / Duvet [ single ]", "Blanket / Comforter / Duvet [ queen ]\t"},
	{"Shorts / Jeans / Pants / Slack / Trousers", "Blouse / Shirt [ sequin ]\t\t", "Cardigan / Pullover / Sweater\t\t", "Jump Suit [ women ]\t\t\t"},
	{"Curtain\t\t\t\t", "Curtain + removing & hanging\t\t", "Carpet / Prayer Mat\t\t\t", "Cushion Cover\t\t\t\t"}};
	char quantsymb [3][4][10] = {{"kg", "kg", "\t", "\t"}, {"\t", "\t", "\t", "\t"}, {"kg", "kg", "sqft", "kg"}};
	int i = 1, j = 0, x, y, itm_nom[12], itm_nonm[12], quantm[12], quantnm[12];
	
	//start constructing the a table for receipt
	printf("\n_________________________________________________________________________________________________________________\n");
	printf ("%s",fName);
	printf("\n|_______________________________________________________________________________________________________________|\n");
	
	if (strcmp(type, "yes") == 0)
	{
		printf ("|\t\t\t\t\t\tType : Member\t\t\t\t\t\t\t\t|");
		printf("\n|_______________________________________________________________________________________________________________|\n");
		printf("|\tItem\t|\t\t\tService\t\t\t\t|\tQuantity\t|    Price\t|\n");
		printf("|_______________|_______________________________________________________|_______________________|_______________|\n");
		
		for (x = 0; x<3; x++){
			for(y = 0; y<4; y++){
				if(member.quantity[x][y] != 0){
					printf("|\t%.3d\t|%s\t\t\t\t\t|\t    %d %s\t|   RM %.2f\t|", i, servh[x], pmember->quantity[x][y], quantsymb[x][y], pmember->totalitem[x][y]);
					printf("\n|\t\t|-%s\t\t|\t\t\t|\t\t\t|\n", servb[x][y]);
					printf("|_______________|_______________________________________________________|_______________________|_______________|\n");
					i++;
				}
			}
		}
		printf("|\t\t\t\t\t\t\t\t\tSales & Service Tax (6%%)|   RM %.2f\t|", member.tax);
		printf("\n|_______________________________________________________________________________________________|_______________|\n");
		printf("|\t\t\t\t\t\t\t\t\t\tTotal (Rounding)|   RM %.2f\t|", member.total_rounding);
		printf("\n|_______________________________________________________________________________________________|_______________|\n");
	}
	
	else
	{
		printf("|\t\t\t\t\t\tType : Not Member\t\t\t\t\t\t\t|");
		printf("\n|_______________________________________________________________________________________________________________|\n");
		printf("|\tItem\t|\t\t\tService\t\t\t\t|\tQuantity\t|    Price\t|\n");
		printf("|_______________|_______________________________________________________|_______________________|_______________|\n");
		
		for (x = 0; x<3; x++){
			for(y = 0; y<4; y++){
				if(notmember.quantity[x][y] != 0){
					printf("|\t%2d\t|%s\t\t\t\t\t|\t    %d %s\t|   RM %.2f\t|", i, servh[x], pnotmember->quantity[x][y], quantsymb[x][y], pnotmember->totalitem[x][y]);
					printf("\n|\t\t|-%s\t\t|\t\t\t|\t\t\t|\n", servb[x][y]);
					printf("|_______________|_______________________________________________________|_______________________|_______________|\n");
					i++;
				}
			}
		}
		printf("|\t\t\t\t\t\t\t\t\tSales & Service Tax (6%%)|   RM %.2f\t|", notmember.tax);
		printf("\n|_______________________________________________________________________________________________|_______________|\n");
		printf("|\t\t\t\t\t\t\t\t\t\tTotal (Rounding)|   RM %.2f\t|", notmember.total_rounding);
		printf("\n|_______________________________________________________________________________________________|_______________|\n");
	}
	printreceipt(type);  // calling printreceipt function before exiting
}  // exit receipt function

void printreceipt(char *type) //printreceipt parameter
{
	FILE *receipt;  //receipt pointer
	char fName [100] = {"|\t\t\t\t\t\tMyDobi Receipt.\t\t\t\t\t\t\t|"};
	char servh[3][50] = {"Wash & Fold\t", "Garment Cleaning", "Curtains & Household"};
	char servb[3][4][100] = {
	{"Clothing\t\t\t\t", "Bed Linen / Towels\t\t\t", "Blanket / Comforter / Duvet [ single ]", "Blanket / Comforter / Duvet [ queen ]\t"},
	{"Shorts / Jeans / Pants / Slack / Trousers", "Blouse / Shirt [ sequin ]\t\t", "Cardigan / Pullover / Sweater\t\t", "Jump Suit [ women ]\t\t\t"},
	{"Curtain\t\t\t\t", "Curtain + removing & hanging\t\t", "Carpet / Prayer Mat\t\t\t", "Cushion Cover\t\t\t\t"}};
	char quantsymb [3][4][10] = {{"kg", "kg", "\t", "\t"}, {"\t", "\t", "\t", "\t"}, {"kg", "kg", "sqft", "kg"}};
	int i = 1, j = 0, x, y;
	
	receipt = fopen ("MyDobi Receipt.txt", "w");			/* start the file operation & point it into the pointer declaired */
	
	fprintf (receipt,"\n_________________________________________________________________________________________________________________\n");
	fprintf (receipt,"%s",fName);
	fprintf (receipt,"\n|_______________________________________________________________________________________________________________|\n");
	
	if (strcmp(type, "yes") == 0)
	{
		fprintf (receipt,"|\t\t\t\t\t\tType : Member\t\t\t\t\t\t\t|");
		fprintf (receipt,"\n|_______________________________________________________________________________________________________________|\n");
		fprintf (receipt,"|\tItem\t|\t\t\tService\t\t\t\t|\tQuantity\t|    Price\t|\n");
		fprintf (receipt,"|_______________|_______________________________________________________|_______________________|_______________|\n");
		
		for (x = 0; x<3; x++){
			for(y = 0; y<4; y++){
				if(member.quantity[x][y] != 0){
					fprintf (receipt, "|\t%.3d\t|%s\t\t\t\t\t|\t    %d %s\t|   RM %.2f\t|", i, servh[x], pmember->quantity[x][y], quantsymb[x][y], pmember->totalitem[x][y]);
					fprintf (receipt, "\n|\t\t|-%s\t\t|\t\t\t|\t\t|\n", servb[x][y]);
					fprintf (receipt,"|_______________|_______________________________________________________|_______________________|_______________|\n");
					i++;
				}
			}
		}
		fprintf (receipt, "|\t\t\t\t\t\t\t\t\tSales & Service Tax (6%%)|   RM %.2f\t|\n", member.tax);
		fprintf (receipt, "|_______________________________________________________________________________________________|_______________|\n");
		fprintf (receipt, "|\t\t\t\t\t\t\t\t\t\tTotal (Rounding)|   RM %.2f\t|", member.total_rounding);
		fprintf (receipt, "\n|_______________________________________________________________________________________________|_______________|\n");
	}
	
	else
	{
		fprintf (receipt,"|\t\t\t\t\t\tType : Not Member\t\t\t\t\t\t|");
		fprintf (receipt,"\n|_______________________________________________________________________________________________________________|\n");
		fprintf (receipt,"|\tItem\t|\t\t\tService\t\t\t\t|\tQuantity\t|    Price\t|\n");
		fprintf (receipt,"|_______________|_______________________________________________________|_______________________|_______________|\n");
		
		for (x = 0; x<3; x++){
			for(y = 0; y<4; y++){
				if (notmember.quantity[x][y] != 0){
					fprintf (receipt, "|\t%2d\t|%s\t\t\t\t\t|\t    %d %s\t|   RM %.2f\t|", i, servh[x], pnotmember->quantity[x][y], quantsymb[x][y], pnotmember->totalitem[x][y]);
					fprintf (receipt, "\n|\t\t|-%s\t\t|\t\t\t|\t\t|\n", servb[x][y]);
					fprintf (receipt,"|_______________|_______________________________________________________|_______________________|_______________|\n");
					i++;
				}
			}
		}
		fprintf (receipt, "|\t\t\t\t\t\t\t\t\tSales & Service Tax (6%%)|   RM %.2f\t|", notmember.tax);
		fprintf (receipt, "\n|_______________________________________________________________________________________________|_______________|\n");
		fprintf (receipt, "|\t\t\t\t\t\t\t\t\t\tTotal (Rounding)|   RM %.2f\t|", notmember.total_rounding);
		fprintf (receipt, "\n|_______________________________________________________________________________________________|_______________|\n");
	}
	
	fclose (receipt); 				// close for receipt
} // exit printreceipt function
