#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int routine[2][5][4];
    routine[0][0][0]=0;
    routine[0][0][1]=1;
    routine[0][0][2]=7;
    routine[0][0][3]=10;
    routine[0][1][0]=0;
    routine[0][1][1]=1;
    routine[0][1][2]=6;
    routine[0][1][3]=11;
    routine[0][2][0]=2;
    routine[0][2][1]=3;
    routine[0][2][2]=5;
    routine[0][2][3]=12;
    routine[0][3][0]=2;
    routine[0][3][1]=4;
    routine[0][3][2]=8;
    routine[0][3][3]=13;
    routine[0][4][0]=3;
    routine[0][4][1]=4;
    routine[0][4][2]=9;
    routine[0][4][3]=14;

    int totalclassesinweek;
    printf("How Many classes do you need in a week?\n");
    printf("Note that it cannot exceed 20\n");
    scanf("%d",&totalclassesinweek);
    int choiceof4classesor3classesonfri;
    int techwith2classes=5;
    int currenttotalteacher=(totalclassesinweek-2*techwith2classes)+techwith2classes;
    int classesonfriday;
    int choiceof4classes[4];
    if(totalclassesinweek==15)
    {
        printf("How many classes you want on friday?\n");
        printf("If it's 2 then press 2 and if it's 3, press 3\n");
        scanf("%d",&classesonfriday);


        if(classesonfriday==2)
        {
            printf("Since you chose to have 2 classes on Friday, on which day would you have 4 classes?\n");
            printf("1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n5.I want 3 classes on Friday\n");
            scanf("%d",&choiceof4classesor3classesonfri);

        }
        if(choiceof4classesor3classesonfri==1)
        {
            int tempswap9thcls=routine[0][0][3];
            routine[0][0][3]=routine[0][4][2];
            routine[0][4][2]=tempswap9thcls;
            printf("Swapped in monday\n %d %d\n",routine[0][0][3],routine[0][4][2]);
        }
        else if(choiceof4classesor3classesonfri==2)
        {
            int tempswap9thcls=routine[0][1][3];
            routine[0][1][3]=routine[0][4][2];
            routine[0][4][2]=tempswap9thcls;
            printf("Swapped in tuesday\n %d %d\n",routine[0][1][3],routine[0][4][2]);
        }
        else if(choiceof4classesor3classesonfri==3)
        {
            int tempswap9thcls=routine[0][2][3];
            routine[0][2][3]=routine[0][4][2];
            routine[0][4][2]=tempswap9thcls;
            printf("Swapped in wednesday\n %d %d\n",routine[0][2][3],routine[0][4][2]);
        }
        else if(choiceof4classesor3classesonfri==4)
        {
            int tempswap9thcls=routine[0][3][3];
            routine[0][3][3]=routine[0][4][2];
            routine[0][4][2]=tempswap9thcls;
            printf("Swapped in thursday\n %d %d\n",routine[0][3][3],routine[0][4][2]);
        }
    }

    if(totalclassesinweek==16)
    {
        printf("Please choose how many classes you want to have on each day.\n");
        printf("How many classes you want on friday?\n");
        printf("If it's 2 then press 2 and if it's 3, press 3\n");
        scanf("%d",&classesonfriday);
        if(classesonfriday==3)
        {
            printf("Since you chose to have 3 classes on Friday, on which day would you have 4 classes?\n");
            printf("1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n");
            scanf("%d",&choiceof4classes[0]);
            if(choiceof4classes[0]==1)
            {
                routine[0][0][3]=10;
            }
            else if(choiceof4classes[0]==2)
            {
                routine[0][1][3]=10;
                routine[0][0][3]=110;
            }
            else if(choiceof4classes[0]==3)
            {
                routine[0][2][3]=10;
                routine[0][0][3]=110;
            }
            else if(choiceof4classes[0]==4)
            {
                routine[0][3][3]=10;
                routine[0][0][3]=110;
            }
        }
        else if(classesonfriday==2)
        {
            printf("Since you chose to have 2 classes on Friday, on which 2 days would you have 4 classes?\n");
            printf("1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n");
            scanf("%d %d",&choiceof4classes[0],&choiceof4classes[1]);

            if(choiceof4classes[0]==1)
            {
                routine[0][0][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in monday\n %d %d\n",routine[0][0][3],routine[0][4][2]);
            }
            else if(choiceof4classes[0]==2)
            {
                routine[0][1][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in tuesday\n %d %d\n",routine[0][1][3],routine[0][4][2]);
            }
            else if(choiceof4classes[0]==3)
            {
                routine[0][2][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in wednesday\n %d %d\n",routine[0][2][3],routine[0][4][2]);
            }
            else if(choiceof4classes[0]==4)
            {
                routine[0][3][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in thursday\n %d %d\n",routine[0][3][3],routine[0][4][2]);
            }

            if(choiceof4classes[1]==1)
            {
                routine[0][0][3]=10;
            }
            else if(choiceof4classes[1]==2)
            {
                routine[0][1][3]=10;
                routine[0][0][3]=110;
            }
            else if(choiceof4classes[1]==3)
            {
                routine[0][2][3]=10;
                routine[0][0][3]=110;
            }
            else if(choiceof4classes[1]==4)
            {
                routine[0][3][3]=10;
                routine[0][0][3]=110;
            }
        }
    }

    if(totalclassesinweek==17)
    {
        printf("Please choose how many classes you want to have on each day.\n");
        printf("How many classes you want on friday?\n");
        printf("If it's 2 then press 2 and if it's 3, press 3\n");
        scanf("%d",&classesonfriday);
        if(classesonfriday==3)
        {
            printf("Since you chose to have 3 classes on Friday, on which 2 days would you have 4 classes?\n");
            printf("1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n");
            scanf("%d %d",&choiceof4classes[0],&choiceof4classes[1]);

            if(choiceof4classes[0]==1)
            {
                routine[0][0][3]=10;
            }
            else if(choiceof4classes[0]==2)
            {
                routine[0][1][3]=10;
                routine[0][0][3]=110;
            }
            else if(choiceof4classes[0]==3)
            {
                routine[0][2][3]=10;
                routine[0][0][3]=110;
            }
            else if(choiceof4classes[0]==4)
            {
                routine[0][3][3]=10;
                routine[0][0][3]=110;
            }



            if(choiceof4classes[1]==1)
            {
                routine[0][0][3]=11;
                routine[0][1][3]=110;
            }
            else if(choiceof4classes[1]==2)
            {
                routine[0][1][3]=11;
            }
            else if(choiceof4classes[1]==3)
            {
                routine[0][2][3]=11;
                routine[0][1][3]=110;
            }
            else if(choiceof4classes[1]==4)
            {
                routine[0][3][3]=11;
                routine[0][1][3]=110;
            }
        }
        else if(classesonfriday==2)
        {
            printf("Since you chose to have 2 classes on Friday, on which 3 days would you have 4 classes?\n");
            printf("1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n");
            scanf("%d %d %d",&choiceof4classes[0],&choiceof4classes[1],&choiceof4classes[2]);

            if(choiceof4classes[0]==1)
            {
                routine[0][0][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in monday\n %d %d\n",routine[0][0][3],routine[0][4][2]);
            }
            else if(choiceof4classes[0]==2)
            {
                routine[0][1][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in tuesday\n %d %d\n",routine[0][1][3],routine[0][4][2]);
            }
            else if(choiceof4classes[0]==3)
            {
                routine[0][2][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in wednesday\n %d %d\n",routine[0][2][3],routine[0][4][2]);
            }
            else if(choiceof4classes[0]==4)
            {
                routine[0][3][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in thursday\n %d %d\n",routine[0][3][3],routine[0][4][2]);
            }



            if(choiceof4classes[1]==1)
            {
                routine[0][0][3]=10;
            }
            else if(choiceof4classes[1]==2)
            {
                routine[0][1][3]=10;
                routine[0][0][3]=110;
            }
            else if(choiceof4classes[1]==3)
            {
                routine[0][2][3]=10;
                routine[0][0][3]=110;
            }
            else if(choiceof4classes[1]==4)
            {
                routine[0][3][3]=10;
                routine[0][0][3]=110;
            }

            if(choiceof4classes[2]==1)
            {
                routine[0][0][3]=11;
                routine[0][1][3]=110;
            }
            else if(choiceof4classes[2]==2)
            {
                routine[0][1][3]=11;
            }
            else if(choiceof4classes[2]==3)
            {
                routine[0][2][3]=11;
                routine[0][1][3]=110;
            }
            else if(choiceof4classes[2]==4)
            {
                routine[0][3][3]=11;
                routine[0][1][3]=110;
            }
        }
    }

    if(totalclassesinweek==18)
    {
        printf("Please choose how many classes you want to have on each day.\n");
        printf("How many classes you want on friday?\n");
        printf("If it's 2 then press 2 and if it's 3, press 3\n");
        scanf("%d",&classesonfriday);
        if(classesonfriday==3)
        {
            printf("Since you chose to have 3 classes on Friday, on which 3 days would you have 4 classes?\n");
            printf("1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n");
            scanf("%d %d %d",&choiceof4classes[0],&choiceof4classes[1],&choiceof4classes[2]);

            if(choiceof4classes[0]==1)
            {
                routine[0][0][3]=10;
            }
            else if(choiceof4classes[0]==2)
            {
                routine[0][1][3]=10;
                routine[0][0][3]=110;
            }
            else if(choiceof4classes[0]==3)
            {
                routine[0][2][3]=10;
                routine[0][0][3]=110;
            }
            else if(choiceof4classes[0]==4)
            {
                routine[0][3][3]=10;
                routine[0][0][3]=110;
            }

            if(choiceof4classes[1]==1)
            {
                routine[0][0][3]=11;
                routine[0][1][3]=110;
            }
            else if(choiceof4classes[1]==2)
            {
                routine[0][1][3]=11;
            }
            else if(choiceof4classes[1]==3)
            {
                routine[0][2][3]=11;
                routine[0][1][3]=110;
            }
            else if(choiceof4classes[1]==4)
            {
                routine[0][3][3]=11;
                routine[0][1][3]=110;
            }




            if(choiceof4classes[2]==1)
            {
                routine[0][0][3]=12;
                routine[0][2][3]=110;
            }
            else if(choiceof4classes[2]==2)
            {
                routine[0][1][3]=12;
                routine[0][2][3]=110;
            }
            else if(choiceof4classes[2]==3)
            {
                routine[0][2][3]=12;
            }
            else if(choiceof4classes[2]==4)
            {
                routine[0][3][3]=12;
                routine[0][2][3]=110;
            }
        }
        else if(classesonfriday==2)
        {
            printf("Since you chose to have 2 classes on Friday, on the other 4 days there'll be 4 classes per day.\n");

            routine[0][4][2]=110;
            routine[0][0][3]=9;
            routine[0][1][3]=10;
            routine[0][2][3]=11;
            routine[0][3][3]=12;
        }
    }

}
