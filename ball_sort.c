#include<stdio.h>
#include<conio.h>

char t1[4] = {'P','G','O','O'};
char t2[4] = {'P','G','O','P'};
char t3[4] = {'G','O','P','G'};
char t4[4] = {0};
char t5[4] = {0};

char *tubes[5] = {t1,t2,t3,t4,t5}; //<---storing starting address of each tube array in "tubes"
int top[5] = {3,3,3,-1,-1};
int moves = 0 ;

void pop(int tnum_pop)
{
    int tnum_push;
    char ball;

    if(top[tnum_pop] == -1)
    {
	printf("\nTube is Empty!!");
	return;
    }
    printf("In which tube to PUSH?");
    scanf("%d",&tnum_push);

    ball=tubes[tnum_pop][top[tnum_pop]];

    // checking if PUSH operation is possible

    if(top[tnum_push-1]==3)
    {
	printf("Tube is Full!\n");
	return;
    }
    if(top[tnum_push-1]==-1 || tubes[tnum_push-1][top[tnum_push-1]]==ball) //<---check empty or is of same color or not
    {
       top[tnum_push-1]++;
       tubes[tnum_push-1][top[tnum_push-1]]=ball;

       top[tnum_pop]--; // <---once PUSH successfull then only finally POP
       moves++;
    }
    else
    {
       printf("Can't PUSH Ball...since not of same type\n");
    }
}

void display()
{
   int i,j;
   for(i=3; i>=0; i--)
   {
       for(j=0; j<5; j++)
       {
	  if(i <= top[j])
		printf(" |%c| ",tubes[j][i]);
	  else
	  {
		printf(" | | ");
	  }
       }
       printf("\n");
   }
   printf("  1    2    3    4    5\n");
}

int check_win()
{
   int i,j;
   for(i=0; i<5; i++)
   {
       if(top[i]==-1) //<---empty tube skipped
	  continue;
       if(top[i]!=3)  //<---tube not full
	  return 0 ;
       for(j=0; j<3; j++)  //<---check all same balls within a full-filled-tube
       {
	   if( tubes[i][j] != tubes[i][j+1])
	      return 0;
	   else
	      continue;
       }
       if(i == 5)
	  return 1;    //<--all of same type-->WIN
   }
}

int main()
{
    int och, tnum_pop, tnum_push;
    

    while(1)
    {
	

	printf("\n-----Ball Sort Puzzle-----\n\n\n");
	display();
	printf("\n1.Play\n2.Exit\n");
	printf("Provide your choice: ");
	scanf("%d",&och);

	switch(och)
	{
	    case 1:
		printf("\nFrom which tube to POP? ");
		scanf("%d",&tnum_pop);
		pop(tnum_pop-1);

		if(check_win())
		{
		  
		  display();
		  printf("\nCongratulations! You Won the Game!! \n");
		  printf("Total Moves: %d",moves);
		  
		
		}
		break;

	    case 2:
	    	break;
		

	} //end of switch-case
    } //end of while-loop
} //end of main()
