//Ask sir how he wants to have the power to control slots/classes(also whether this control will be based on days or week
//Also ask about the number of rooms

//In case of 3 sections in 2 rooms(if 3 subs a day):
//Sec A: 0(r1) 1(r1) 7(r1)
//Sec B: 7(r2) 0(r2)       1(r2)
//Sec C:             0(r2) 7(r1)  1(r1)

//In case of 3 sections in 2 rooms(if 4 subs a day):
//Sec A: 0(r1) 1(r1) 7(r1)        10(r1)
//Sec B: 7(r2) 0(r2)        1(r1)         10(r1)
//Sec C:             10(r2) 7(r2)  1(r2)   0(r2)


#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int i,j,k,l,m,x;
    int teachernum=5;
    int dontpref[teachernum][2];
    int maxdontpref=2;
    int mk=0,tuk=0,wk=0,thk=0,fk=0;
    char section[2][25]= {"A","B"};
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

    int mon=0,tues=0,wed=0,thurs=0,fri=0;
    int itsmon=0,itstues=0,itswed=0,itsthurs=0,itsfri=0;
    int teacher=0;
    int totalclassesinweek;
    char subname[100][1000];

    char ch, file_name[25];
    FILE *fp;
    printf("In which file is the name of the subjects?\n");
    gets(file_name);
    fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    int z=0,zz=0;
    for ( ; ; )
    {
        i = fgetc(fp);

        if (i == EOF)   break;
        else
        {
            while (i != 10)
            {
                subname[z][zz] = i;
                zz++;
                i = fgetc(fp);
                if (i == EOF)   break;
            }
            subname[z][zz]=NULL;
            zz=0;
            z++;
        }
    }

    fclose(fp);   //file ends for input

    FILE *fpprint;
    char file_name2[25];
    printf("In which file will the routine be printed?\n");
    gets(file_name2);
    fpprint=fopen(file_name2, "w");                //file work ends(except the part to where to print and what to print after that is fclose)


    printf("How Many classes do you need in a week?\n");
    printf("Note that it cannot exceed 20\n");
    scanf("%d",&totalclassesinweek);
    int classesonfriday=2;
    int choiceof4classesor3classesonfri;
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

            if(choiceof4classesor3classesonfri==1) //since 2 classes on friday, preselected 3rd class on friday is being swapped by the day on which there'll be 4 classes
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

            if(choiceof4classes[0]==1)  ////since 2 classes on friday, preselected 3rd class on friday is being swapped by the day on which there'll be 4 classes
            {
                routine[0][0][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in monday for 16\n %d %d\n",routine[0][0][3],routine[0][4][2]);
            }
            else if(choiceof4classes[0]==2)
            {
                routine[0][1][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in tuesday for 16\n %d %d\n",routine[0][1][3],routine[0][4][2]);
            }
            else if(choiceof4classes[0]==3)
            {
                routine[0][2][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in wednesday for 16\n %d %d\n",routine[0][2][3],routine[0][4][2]);
            }
            else if(choiceof4classes[0]==4)
            {
                routine[0][3][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in thursday for 16\n %d %d\n",routine[0][3][3],routine[0][4][2]);
            }

            if(choiceof4classes[1]==1)  //choice for 2nd day with 4 classes
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

            if(choiceof4classes[0]==1)  //choice for 1st day with 4 classes
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


            if(choiceof4classes[1]==1)  //choice for 2nd day with 4 classes
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

            if(choiceof4classes[0]==1)  //since 2 classes on friday, preselected 3rd class on friday is being swapped by the day on which there'll be 4 classes
            {
                routine[0][0][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in monday\n %d %d for 17\n",routine[0][0][3],routine[0][4][2]);
            }
            else if(choiceof4classes[0]==2)
            {
                routine[0][1][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in tuesday\n %d %d for 17\n",routine[0][1][3],routine[0][4][2]);
            }
            else if(choiceof4classes[0]==3)
            {
                routine[0][2][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in wednesday\n %d %dfor 17\n",routine[0][2][3],routine[0][4][2]);
            }
            else if(choiceof4classes[0]==4)
            {
                routine[0][3][3]=9;
                routine[0][4][2]=110;
                printf("Swapped in thursday\n %d %dfor 17\n",routine[0][3][3],routine[0][4][2]);
            }


            if(choiceof4classes[1]==1)  //choice for 2nd day with 4 classes
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

            if(choiceof4classes[2]==1)  ////choice for 3rd day with 4 classes
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

            if(choiceof4classes[0]==1)  //choice for 1st day with 4 classes
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


            if(choiceof4classes[1]==1)  ////choice for 2nd day with 4 classes
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


            if(choiceof4classes[2]==1) //choice for 3rd day with 4 classes
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


    int techwith2classes=5;
    int currenttotalteacher=(totalclassesinweek-2*techwith2classes)+techwith2classes;
    int dontmon[currenttotalteacher],donttues[currenttotalteacher],dontwed[currenttotalteacher],dontthurs[currenttotalteacher],dontfri[currenttotalteacher];
    dontmon[0]=111,dontmon[1]=112,dontmon[2]=113;
    donttues[0]=111,donttues[1]=112,donttues[2]=113;
    dontwed[0]=111,dontwed[1]=112,dontwed[2]=113;
    dontthurs[0]=111,dontthurs[1]=112,dontthurs[2]=113;
    dontfri[0]=111,dontfri[1]=112,dontfri[2]=113;
    int techwithchoice[teachernum];
    char dayofweek[5][20]= {"Monday","Tuesday","Wednesday","Thursday","Friday"};
    int monswap02wed=0,monswap02thurs=0,monswap03wed=0,monswap03fri=0,monswap04thurs=0,monswap04fri=0;
    int monswap12wed=0,monswap12thurs=0,monswap13wed=0,monswap13fri=0,monswap14thurs=0,monswap14fri=0;
    int tuesswap02wed=0,tuesswap02thurs=0,tuesswap03wed=0,tuesswap03fri=0,tuesswap04thurs=0,tuesswap04fri=0;
    int tuesswap12wed=0,tuesswap12thurs=0,tuesswap13wed=0,tuesswap13fri=0,tuesswap14thurs=0,tuesswap14fri=0;


    for(i=0; i<currenttotalteacher; i++)
    {
        printf("Teacher with ID %d teaches %s\n",i,subname[i]);
    }



    for(i=0; i<teachernum; i++)
    {
        printf("Which 2 of these days do you not prefer?\n");
        printf("1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n5.Friday\n");

        for(j=0; j<2; j++)
        {
            scanf("%d",&dontpref[i][j]);
            if(dontpref[i][j]==1) mon++;
            else if(dontpref[i][j]==2) tues++;
            else if(dontpref[i][j]==3) wed++;
            else if(dontpref[i][j]==4) thurs++;
            else if(dontpref[i][j]==5) fri++;
        }
        printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
        teacher++;
        if(mon>maxdontpref && tues<=maxdontpref && wed<=maxdontpref && thurs<=maxdontpref && fri<=maxdontpref)
        {
            itsmon=1;
            break;
        }
        if(tues>maxdontpref && mon<=maxdontpref && wed<maxdontpref && thurs<=maxdontpref && fri<=maxdontpref)
        {
            itstues=1;
            break;
        }
        if(wed>maxdontpref && tues<=maxdontpref && mon<=maxdontpref && thurs<=maxdontpref && fri<=maxdontpref)
        {
            itswed=1;
            break;
        }
        if(thurs>maxdontpref && tues<=maxdontpref && wed<=maxdontpref && mon<=maxdontpref && fri<=maxdontpref)
        {
            itsthurs=1;
            break;
        }
        if(fri>maxdontpref-1 && tues<=maxdontpref && wed<=maxdontpref && thurs<=maxdontpref && mon<=maxdontpref)
        {
            itsfri=1;
            break;
        }
        if(mon>maxdontpref && tues>maxdontpref && wed<=maxdontpref && thurs<=maxdontpref && fri<=maxdontpref)
        {
            itsmon=1;
            itstues=1;
            break;
        }
        if(mon>maxdontpref && wed>maxdontpref && tues<=maxdontpref && thurs<=maxdontpref && fri<=maxdontpref)
        {
            itsmon=1;
            itswed=1;
            break;
        }
        if(mon>maxdontpref && thurs>maxdontpref && wed<=maxdontpref && tues<=maxdontpref && fri<=maxdontpref)
        {
            itsmon=1;
            itsthurs=1;
            break;
        }
        if(mon>maxdontpref && fri>maxdontpref-1 && wed<=maxdontpref && thurs<=maxdontpref && tues<=maxdontpref)
        {
            itsmon=1;
            itsfri=1;
            break;
        }
        if(tues>maxdontpref && wed>maxdontpref && mon<=maxdontpref && thurs<=maxdontpref && fri<=maxdontpref)
        {
            itstues=1;
            itswed=1;
            break;
        }
        if(tues>maxdontpref && thurs>maxdontpref && mon<=maxdontpref && wed<=maxdontpref && fri<=maxdontpref)
        {
            itstues=1;
            itsthurs=1;
            break;
        }
        if(tues>maxdontpref && fri>maxdontpref-1 && mon<=maxdontpref && wed<=maxdontpref && thurs<=maxdontpref)
        {
            itstues=1;
            itsfri=1;
            break;
        }
        if(wed>maxdontpref && thurs>maxdontpref && mon<=maxdontpref && tues<=maxdontpref && fri<=maxdontpref)
        {
            itswed=1;
            itsthurs=1;
            break;
        }
        if(wed>maxdontpref && fri>maxdontpref-1 && mon<=maxdontpref && tues<=maxdontpref && thurs<=maxdontpref)
        {
            itswed=1;
            itsfri=1;
            break;
        }
        if(thurs>maxdontpref && fri>maxdontpref-1 && mon<=maxdontpref && tues<=maxdontpref && wed<=maxdontpref)
        {
            itsthurs=1;
            itsfri=1;
            break;
        }
    }

    if(itsmon==1 && itstues==0 && itswed==0 && itsthurs==0 && itsfri==0)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Monday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("2.Tuesday\n3.Wednesday\n4.Thursday\n5.Friday\n");

            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==2) tues++;
                else if(dontpref[i][j]==3) wed++;
                else if(dontpref[i][j]==4) thurs++;
                else if(dontpref[i][j]==5) fri++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;
            if(tues>maxdontpref)
            {
                itstues=1;
                break;
            }
            if(wed>maxdontpref)
            {
                itswed=1;
                break;
            }
            if(thurs>maxdontpref)
            {
                itsthurs=1;
                break;
            }
            if(fri>maxdontpref-1)
            {
                itsfri=1;
                break;
            }
        }
    }

    if(itstues==1 && itsmon==0 && itswed==0 && itsthurs==0 && itsfri==0)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Tuesday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("1.Monday\n3.Wednesday\n4.Thursday\n5.Friday\n");
            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==1) mon++;
                else if(dontpref[i][j]==3) wed++;
                else if(dontpref[i][j]==4) thurs++;
                else if(dontpref[i][j]==5) fri++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;
            if(mon>maxdontpref)
            {
                itsmon=1;
                break;
            }
            if(wed>maxdontpref)
            {
                itswed=1;
                break;
            }
            if(thurs>maxdontpref)
            {
                itsthurs=1;
                break;
            }
            if(fri>maxdontpref-1)
            {
                itsfri=1;
                break;
            }
        }
    }

    if(itswed==1 && itsmon==0 && itstues==0 && itsthurs==0 && itsfri==0)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Wednesday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("1.Monday\n2.Tuesday\n4.Thursday\n5.Friday\n");

            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==1) mon++;
                else if(dontpref[i][j]==2) tues++;
                else if(dontpref[i][j]==4) thurs++;
                else if(dontpref[i][j]==5) fri++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;
            if(mon>maxdontpref)
            {
                itsmon=1;
                break;
            }
            if(tues>maxdontpref)
            {
                itstues=1;
                break;
            }
            if(thurs>maxdontpref)
            {
                itsthurs=1;
                break;
            }
            if(fri>maxdontpref-1)
            {
                itsfri=1;
                break;
            }
        }
    }

    if(itsthurs==1 && itsmon==0 && itstues==0 && itswed==0 && itsfri==0)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Thursday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("1.Monday\n2.Tuesday\n3.Wednesday\n5.Friday\n");

            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==1) mon++;
                else if(dontpref[i][j]==2) tues++;
                else if(dontpref[i][j]==3) wed++;
                else if(dontpref[i][j]==5) fri++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;
            if(mon>maxdontpref)
            {
                itsmon=1;
                break;
            }
            if(tues>maxdontpref)
            {
                itstues=1;
                break;
            }
            if(wed>maxdontpref)
            {
                itswed=1;
                break;
            }

            if(fri>maxdontpref-1)
            {
                itsfri=1;
                break;
            }
        }
    }

    if(itsfri==1 && itsmon==0 && itstues==0 && itswed==0 && itsthurs==0)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Friday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n");

            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==1) mon++;
                else if(dontpref[i][j]==2) tues++;
                else if(dontpref[i][j]==3) wed++;
                else if(dontpref[i][j]==4) thurs++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;
            if(mon>maxdontpref)
            {
                itsmon=1;
                break;
            }
            if(tues>maxdontpref)
            {
                itstues=1;
                break;
            }
            if(wed>maxdontpref)
            {
                itswed=1;
                break;
            }
            if(thurs>maxdontpref)
            {
                itsthurs=1;
                break;
            }
        }
    }

    if(itsmon==1 && itstues==1)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Monday or Tuesday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("3.Wednesday\n4.Thursday\n5.Friday\n");
            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==3) wed++;
                else if(dontpref[i][j]==4) thurs++;
                else if(dontpref[i][j]==5) fri++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;

            if(wed>maxdontpref)
            {
                itswed=1;
                break;
            }
            if(thurs>maxdontpref)
            {
                itsthurs=1;
                break;
            }
            if(fri>maxdontpref-1)
            {
                itsfri=1;
                break;
            }
        }
    }

    if(itsmon==1 && itswed==1)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Monday or Wednesday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("2.Tuesday\n4.Thursday\n5.Friday\n");
            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==2) tues++;
                else if(dontpref[i][j]==4) thurs++;
                else if(dontpref[i][j]==5) fri++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;

            if(tues>maxdontpref)
            {
                itstues=1;
                break;
            }

            if(thurs>maxdontpref)
            {
                itsthurs=1;
                break;
            }
            if(fri>maxdontpref-1)
            {
                itsfri=1;
                break;
            }
        }
    }

    if(itsmon==1 && itsthurs==1)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Monday or Thursday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("2.Tuesday\n3.Wednesday\n5.Friday\n");
            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==2) tues++;
                else if(dontpref[i][j]==3) wed++;
                else if(dontpref[i][j]==5) fri++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;

            if(tues>maxdontpref)
            {
                itstues=1;
                break;
            }
            if(wed>maxdontpref)
            {
                itswed=1;
                break;
            }

            if(fri>maxdontpref-1)
            {
                itsfri=1;
                break;
            }
        }
    }

    if(itsmon==1 && itsfri==1)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Monday or Friday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("2.Tuesday\n3.Wednesday\n4.Thursday\n");
            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==2) tues++;
                else if(dontpref[i][j]==3) wed++;
                else if(dontpref[i][j]==4) thurs++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;

            if(tues>maxdontpref)
            {
                itstues=1;
                break;
            }
            if(wed>maxdontpref)
            {
                itswed=1;
                break;
            }
            if(thurs>maxdontpref)
            {
                itsthurs=1;
                break;
            }
        }
    }

    if(itstues==1 && itswed==1)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Tuesday or Wednesday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("1.Monday\n4.Thursday\n5.Friday\n");

            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==1) mon++;
                else if(dontpref[i][j]==4) thurs++;
                else if(dontpref[i][j]==5) fri++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;
            if(mon>maxdontpref)
            {
                itsmon=1;
                break;
            }


            if(thurs>maxdontpref)
            {
                itsthurs=1;
                break;
            }
            if(fri>maxdontpref-1)
            {
                itsfri=1;
                break;
            }
        }
    }

    if(itstues==1 && itsthurs==1)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Tuesday or Thursday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("1.Monday3.Wednesday\n5.Friday\n");

            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==1) mon++;
                else if(dontpref[i][j]==3) wed++;
                else if(dontpref[i][j]==5) fri++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;
            if(mon>maxdontpref)
            {
                itsmon=1;
                break;
            }

            if(wed>maxdontpref)
            {
                itswed=1;
                break;
            }

            if(fri>maxdontpref-1)
            {
                itsfri=1;
                break;
            }
        }
    }

    if(itstues==1 && itsfri==1)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Tuesday or Friday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("1.Monday\n3.Wednesday\n4.Thursday\n");

            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==1) mon++;
                else if(dontpref[i][j]==3) wed++;
                else if(dontpref[i][j]==4) thurs++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;
            if(mon>maxdontpref)
            {
                itsmon=1;
                break;
            }

            if(wed>maxdontpref)
            {
                itswed=1;
                break;
            }
            if(thurs>maxdontpref)
            {
                itsthurs=1;
                break;
            }
        }
    }

    if(itswed==1 && itsthurs==1)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Wednesday or Thursday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("1.Monday\n2.Tuesday\n5.Friday\n");

            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==1) mon++;
                else if(dontpref[i][j]==2) tues++;
                else if(dontpref[i][j]==5) fri++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;
            if(mon>maxdontpref)
            {
                itsmon=1;
                break;
            }
            if(tues>maxdontpref)
            {
                itstues=1;
                break;
            }

            if(fri>maxdontpref-1)
            {
                itsfri=1;
                break;
            }
        }
    }

    if(itswed==1 && itsfri==1)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Wednesday or Friday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("1.Monday\n2.Tuesday\n4.Thursday\n");

            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==1) mon++;
                else if(dontpref[i][j]==2) tues++;
                else if(dontpref[i][j]==4) thurs++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;
            if(mon>maxdontpref)
            {
                itsmon=1;
                break;
            }
            if(tues>maxdontpref)
            {
                itstues=1;
                break;
            }

            if(thurs>maxdontpref)
            {
                itsthurs=1;
                break;
            }
        }
    }

    if(itsthurs==1 && itsfri==1)
    {
        for(i=teacher; i<teachernum; i++)
        {
            printf("Sorry, you cannot choose Tuesday or Wednesday\n");
            printf("Which 2 of these days do you not prefer?\n");
            printf("1.Monday\n2.Tuesday\n3.Wednesday\n");

            for(j=0; j<2; j++)
            {
                scanf("%d",&dontpref[i][j]);
                if(dontpref[i][j]==1) mon++;
                else if(dontpref[i][j]==2) tues++;
                else if(dontpref[i][j]==3) wed++;
            }
            printf("Teacher with ID %d chose %d & %d\n",i,dontpref[i][j-2],dontpref[i][j-1]);
            teacher++;
            if(mon>maxdontpref)
            {
                itsmon=1;
                break;
            }
            if(tues>maxdontpref)
            {
                itstues=1;
                break;
            }
            if(wed>maxdontpref)
            {
                itswed=1;
                break;
            }
        }
    }



    for(i=0; i<teachernum; i++)
    {
        printf("Teacher %d chose ",i);
        {
            for(j=0; j<2; j++)
                printf("%d ",dontpref[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<teachernum; i++)
    {
        for(j=0; j<2; j++)
        {
            if(dontpref[i][j]==1)
            {
                dontmon[mk]=i;
                mk++;
            }
            if(dontpref[i][j]==2)
            {
                donttues[tuk]=i;
                tuk++;
            }
            if(dontpref[i][j]==3)
            {
                dontwed[wk]=i;
                wk++;
            }
            if(dontpref[i][j]==4)
            {
                dontthurs[thk]=i;
                thk++;
            }
            if(dontpref[i][j]==5)
            {
                dontfri[fk]=i;
                fk++;
            }
        }
    }

    printf("Monday is not preferred by ");
    for(i=0; i<mk; i++)
    {
        printf("%d ",dontmon[i]);
    }
    printf("\n");

    printf("Tuesday is not preferred by ");
    for(i=0; i<tuk; i++)
    {
        printf("%d ",donttues[i]);
    }
    printf("\n");

    printf("Wednesday is not preferred by ");
    for(i=0; i<wk; i++)
    {
        printf("%d ",dontwed[i]);
    }
    printf("\n");

    printf("Thursday is not preferred by ");
    for(i=0; i<thk; i++)
    {
        printf("%d ",dontthurs[i]);
    }
    printf("\n");

    printf("Friday is not preferred by ");
    for(i=0; i<fk; i++)
    {
        printf("%d ",dontfri[i]);
    }
    printf("\n");

    for(i=0; i<mk; i++)
    {
        if(routine[0][0][0]==dontmon[i])
        {
            if(2!=dontmon[0] && 2!=dontmon[1] && 2!=dontmon[2])
            {
                if(routine[0][0][0]!=dontwed[0] && routine[0][0][0]!=dontwed[1] && routine[0][0][0]!=dontwed[2])
                {
                    //printf("monswap02wed=1\n");
                    monswap02wed=1;
                    int tempmonswap02wed=routine[0][0][0];
                    routine[0][0][0]=routine[0][2][0];
                    routine[0][2][0]=tempmonswap02wed;
                }
                else if(routine[0][0][0]!=dontthurs[0] && routine[0][0][0]!=dontthurs[1] && routine[0][0][0]!=dontthurs[2])
                {
                    //printf("monswap02thurs=1\n");
                    monswap02thurs=1;
                    int tempmonswap02thurs=routine[0][0][0];
                    routine[0][0][0]=routine[0][3][0];
                    routine[0][3][0]=tempmonswap02thurs;
                }
            }
            else if(routine[0][4][0]!=dontmon[0] && routine[0][4][0]!=dontmon[1] && routine[0][4][0]!=dontmon[2])
            {
                if(routine[0][0][0]!=dontwed[0] && routine[0][0][0]!=dontwed[1] && routine[0][0][0]!=dontwed[2])
                {
                    //printf("monswap03wed=1\n");
                    monswap03wed=1;
                    int tempmonswap03wed=routine[0][0][0];
                    routine[0][0][0]=routine[0][2][1];
                    routine[0][2][1]=tempmonswap03wed;
                }
                else if(routine[0][0][0]!=dontfri[0] && routine[0][0][0]!=dontfri[1] && routine[0][0][0]!=dontfri[2])
                {
                    //printf("monswap03fri=1\n");
                    monswap03fri=1;
                    int tempmonswap03fri=routine[0][0][0];
                    routine[0][0][0]=routine[0][4][0];
                    routine[0][4][0]=tempmonswap03fri;
                }
            }
            else
            {
                if(routine[0][0][0]!=dontthurs[0] && routine[0][0][0]!=dontthurs[1] && routine[0][0][0]!=dontthurs[2])
                {
                    //printf("monswap04thurs=1\n");
                    monswap04thurs=1;
                    int tempmonswap04thurs=routine[0][0][0];
                    routine[0][0][0]=routine[0][3][1];
                    routine[0][3][1]=tempmonswap04thurs;
                }
                else if(routine[0][0][0]!=dontfri[0] && routine[0][0][0]!=dontfri[1] && routine[0][0][0]!=dontfri[2])
                {
                    //printf("monswap04fri=1\n");
                    monswap04fri=1;
                    int tempmonswap04fri=routine[0][0][0];
                    routine[0][0][0]=routine[0][4][1];
                    routine[0][4][1]=tempmonswap04fri;
                }
            }
        }

        if(routine[0][0][1]==dontmon[i])
        {
            if(routine[0][2][0]!=dontmon[0] && routine[0][2][0]!=dontmon[1] && routine[0][2][0]!=dontmon[2])
            {
                if(routine[0][0][0]!=routine[0][2][0])
                {
                    if(routine[0][0][1]!=dontwed[0] && routine[0][0][1]!=dontwed[1] && routine[0][0][1]!=dontwed[2])
                    {
                        //printf("monswap12wed=1\n");
                        monswap12wed=1;
                        int tempmonswap12wed=routine[0][0][1];
                        routine[0][0][1]=routine[0][2][0];
                        routine[0][2][0]=tempmonswap12wed;
                    }
                    else if(routine[0][0][1]!=dontthurs[0] && routine[0][0][1]!=dontthurs[1] && routine[0][0][1]!=dontthurs[2])
                    {
                        //printf("monswap12thurs=1\n");
                        monswap12thurs=1;
                        int tempmonswap12thurs=routine[0][0][1];
                        routine[0][0][1]=routine[0][3][0];
                        routine[0][3][0]=tempmonswap12thurs;
                    }
                }
            }

            else if(routine[0][2][1]!=dontmon[0] && routine[0][2][1]!=dontmon[1] && routine[0][2][1]!=dontmon[2])
            {
                if(routine[0][0][0]!=routine[0][2][1])
                {
                    if(routine[0][0][1]!=dontwed[0] && routine[0][0][1]!=dontwed[1] && routine[0][0][1]!=dontwed[2])
                    {
                        //printf("monswap13wed=1\n");
                        monswap13wed=1;
                        int tempmonswap13wed=routine[0][0][1];
                        routine[0][0][1]=routine[0][2][1];
                        routine[0][2][1]=tempmonswap13wed;
                    }
                    else if(routine[0][0][1]!=dontfri[0] && routine[0][0][1]!=dontfri[1] && routine[0][0][1]!=dontfri[2])
                    {
                        //printf("monswap13fri=1\n");
                        monswap13fri=1;
                        int tempmonswap13fri=routine[0][0][1];
                        routine[0][0][1]=routine[0][4][0];
                        routine[0][4][0]=tempmonswap13fri;
                    }
                }
            }

            else
            {
                //printf("1 can be swapped by 4\n");
                //printf("%d %d %d\n",dontthurs[0],dontthurs[1],dontthurs[2]);
                //printf("%d %d %d\n",dontfri[0],dontfri[1],dontfri[2]);
                if(routine[0][0][1]!=dontthurs[0] && routine[0][0][1]!=dontthurs[1] && routine[0][0][1]!=dontthurs[2])
                {
                    //printf("monswap14thurs=1\n");
                    monswap14thurs=1;
                    int tempmonswap14thurs=routine[0][0][1];
                    routine[0][0][1]=routine[0][3][1];
                    routine[0][3][1]=tempmonswap14thurs;
                }
                else if(routine[0][0][1]!=dontfri[0] && routine[0][0][1]!=dontfri[1] && routine[0][0][1]!=dontfri[2])
                {
                    //printf("monswap14fri=1\n");
                    monswap14fri=1;
                    int tempmonswap14fri=routine[0][0][1];
                    routine[0][0][1]=routine[0][4][1];
                    routine[0][4][1]=tempmonswap14fri;
                }
            }
        }
    }


    for(i=0; i<tuk; i++)
    {
        if(routine[0][1][0]==donttues[i])
        {
            if(routine[0][2][0]!=donttues[0] && routine[0][2][0]!=donttues[1] && routine[0][2][0]!=donttues[2] && routine[0][1][0]!=dontwed[0] && routine[0][1][0]!=dontwed[1] && routine[0][1][0]!=dontwed[2] &&monswap02wed==0 && routine[0][2][0]!=routine[0][1][1] && routine[0][1][0]!=routine[0][2][0])
            {
                //printf("monswap02wed=0 & tuesswap02=1\n");
                tuesswap02wed=1;
                int temptuesswap02wed=routine[0][1][0];
                routine[0][1][0]=routine[0][2][0];
                routine[0][2][0]=temptuesswap02wed;
            }
            else if(routine[0][3][0]!=donttues[0] && routine[0][3][0]!=donttues[1] && routine[0][3][0]!=donttues[2] && routine[0][1][0]!=dontthurs[0] && routine[0][1][0]!=dontthurs[1] && routine[0][1][0]!=dontthurs[2] && monswap02thurs==0 && routine[0][3][0]!=routine[0][1][1] && routine[0][3][0]!=routine[0][1][0])
            {
                //printf("monswap02thurs=0 & tuesswap02thurs=1\n");
                tuesswap02thurs=1;
                int temptuesswap02thurs=routine[0][1][0];
                routine[0][1][0]=routine[0][3][0];
                routine[0][3][0]=temptuesswap02thurs;
            }
            else if(routine[0][2][1]!=donttues[0] && routine[0][2][1]!=donttues[1] && routine[0][2][1]!=donttues[2] && monswap03wed==0 && routine[0][1][0]!=dontwed[0] && routine[0][1][0]!=dontwed[1] && routine[0][1][0]!=dontwed[2] && routine[0][2][1]!=routine[0][1][1] && routine[0][2][1]!=routine[0][1][0])
            {
                //printf("monswap03wed=0 & tuesswap03wed=1\n");
                tuesswap03wed=1;
                int temptuesswap03wed=routine[0][1][0];
                routine[0][1][0]=routine[0][2][1];
                routine[0][2][1]=temptuesswap03wed;
            }
            else if(routine[0][4][0]!=donttues[0] && routine[0][4][0]!=donttues[1] && routine[0][4][0]!=donttues[2] && monswap03fri==0 && routine[0][1][0]!=dontfri[0] && routine[0][1][0]!=dontfri[1] && routine[0][1][0]!=dontfri[2] && routine[0][4][0]!=routine[0][1][1] && routine[0][4][0]!=routine[0][1][0])
            {

                //printf("monswap03fri=0 & tuesswap03fri=1\n");
                tuesswap03fri=1;
                int temptuesswap03fri=routine[0][1][0];
                routine[0][1][0]=routine[0][4][0];
                routine[0][4][0]=temptuesswap03fri;
            }
            else if(routine[0][3][1]!=donttues[0] && routine[0][3][1]!=donttues[1] && routine[0][3][1]!=donttues[2] && monswap04thurs==0 &&routine[0][1][0]!=dontthurs[0] && routine[0][1][0]!=dontthurs[1] && routine[0][1][0]!=dontthurs[2] && routine[0][3][1]!=routine[0][1][1] && routine[0][3][1]!=routine[0][1][0])
            {

                //printf("monswap04thurs=0 & tuesswap04thurs=1\n");
                tuesswap04thurs=1;
                int temptuesswap04thurs=routine[0][1][0];
                routine[0][1][0]=routine[0][3][1];
                routine[0][3][1]=temptuesswap04thurs;
            }
            else if(routine[0][4][1]!=donttues[0] && routine[0][4][1]!=donttues[1] && routine[0][4][1]!=donttues[2] && monswap04fri==0 && routine[0][1][0]!=dontfri[0] && routine[0][1][0]!=dontfri[1] && routine[0][1][0]!=dontfri[2] && routine[0][4][1]!=routine[0][1][1] && routine[0][4][1]!=routine[0][1][0])
            {
                //printf("monswap04fri=0 & tuesswap04fri=1\n");
                tuesswap04fri=1;
                int temptuesswap04fri=routine[0][1][0];
                routine[0][1][0]=routine[0][4][1];
                routine[0][4][1]=temptuesswap04fri;
            }
        }

        if(routine[0][1][1]==donttues[i])
        {
            if(monswap12wed==0 && routine[0][2][0]!=donttues[0] && routine[0][2][0]!=donttues[1] && routine[0][2][0]!=donttues[2] &&routine[0][1][0]!=routine[0][2][0] && routine[0][1][1]!=dontwed[0] && routine[0][1][1]!=dontwed[1] && routine[0][1][1]!=dontwed[2] && routine[0][2][0]!=routine[0][1][1] && routine[0][2][0]!=routine[0][1][0])
            {
                //printf("monswap12wed=0 tuesswap12wed=1\n");
                tuesswap12wed=1;
                int temptuesswap12wed=routine[0][1][1];
                routine[0][1][1]=routine[0][2][0];
                routine[0][2][0]=temptuesswap12wed;
            }
            else if(monswap12thurs==0 && routine[0][3][0]!=donttues[0] && routine[0][3][0]!=donttues[1] && routine[0][3][0]!=donttues[2] && routine[0][1][0]!=routine[0][2][0] && routine[0][1][1]!=dontthurs[0] && routine[0][1][1]!=dontthurs[1] && routine[0][1][1]!=dontthurs[2] && routine[0][3][0]!=routine[0][1][1] && routine[0][3][0]!=routine[0][1][0])
            {
                //printf("monswap12thurs=0 & tuesswap12thurs=1\n");
                tuesswap12thurs=1;
                int temptuesswap12thurs=routine[0][1][1];
                routine[0][1][1]=routine[0][3][0];
                routine[0][3][0]=temptuesswap12thurs;
            }
            else if(monswap13wed==0 && routine[0][2][1]!=donttues[0] && routine[0][2][1]!=donttues[1] && routine[0][2][1]!=donttues[2] && routine[0][1][0]!=routine[0][2][1] && routine[0][1][1]!=dontwed[0] && routine[0][1][1]!=dontwed[1] && routine[0][1][1]!=dontwed[2] && routine[0][2][1]!=routine[0][1][1] && routine[0][2][1]!=routine[0][1][0])
            {
                //printf("monswap13wed=0 tuesswap13wed=1\n");
                tuesswap13wed=1;
                int temptuesswap13wed=routine[0][1][1];
                routine[0][1][1]=routine[0][2][1];
                routine[0][2][1]=temptuesswap13wed;
            }
            else if(monswap13fri==0 && routine[0][4][0]!=donttues[0] && routine[0][4][0]!=donttues[1] && routine[0][4][0]!=donttues[2] && routine[0][1][0]!=routine[0][2][1] && routine[0][1][1]!=dontfri[0] && routine[0][1][1]!=dontfri[1] && routine[0][1][1]!=dontfri[2] && routine[0][4][0]!=routine[0][1][1] && routine[0][4][0]!=routine[0][1][0])
            {
                //printf("monswap13fri=0 & tuesswap13fri=1\n");
                tuesswap13fri=1;
                int temptuesswap13fri=routine[0][1][1];
                routine[0][1][1]=routine[0][4][0];
                routine[0][4][0]=temptuesswap13fri;
            }
            else if(monswap14thurs==0 && routine[0][3][1]!=donttues[0] && routine[0][3][1]!=donttues[1] && routine[0][3][1]!=donttues[2] && routine[0][1][0]!=routine[0][3][1] && routine[0][1][1]!=dontthurs[0] && routine[0][1][1]!=dontthurs[1] && routine[0][1][1]!=dontthurs[2] && routine[0][3][1]!=routine[0][1][1] && routine[0][3][1]!=routine[0][1][0])
            {
                //printf("monswap14thurs=0 & tuesswap14thurs=1\n");
                tuesswap14thurs=1;
                int temptuesswap14thurs=routine[0][1][1];
                routine[0][1][1]=routine[0][3][1];
                routine[0][3][1]=temptuesswap14thurs;
            }
            else if(monswap14fri==0 && routine[0][4][1]!=donttues[0] && routine[0][4][1]!=donttues[1] && routine[0][4][1]!=donttues[2] && routine[0][1][0]!=routine[0][4][1] && routine[0][1][1]!=dontfri[0] && routine[0][1][1]!=dontfri[1] && routine[0][1][1]!=dontfri[2] && routine[0][4][1]!=routine[0][1][1] && routine[0][4][1]!=routine[0][1][0])
            {
                //printf("monswap14fri=0 & tuesswap14fri=1\n");
                tuesswap14fri=1;
                int temptuesswap14fri=routine[0][1][1];
                routine[0][1][1]=routine[0][4][1];
                routine[0][4][1]=temptuesswap14fri;
            }
        }
    }

    int wedswap20mon=0,wedswap20tues=0,wedswap21mon=0,wedswap21tues=0,wedswap24thurs=0,wedswap24fri=0,wedswap23fri=0;
    int wedswap30mon=0,wedswap30tues=0,wedswap31mon=0,wedswap31tues=0,wedswap34thurs=0,wedswap34fri=0,wedswap32thurs=0;

    for(i=0; i<wk; i++)
    {
        if(monswap02wed==0 && tuesswap02wed==0 && monswap12wed==0 && tuesswap12wed==0)
        {
            if(routine[0][2][0]==dontwed[i])
            {
                if(routine[0][0][0]!=dontwed[0] && routine[0][0][0]!=dontwed[1] && routine[0][0][0]!=dontwed[2] &&routine[0][2][0]!=dontmon[0] && routine[0][2][0]!=dontmon[1] && routine[0][2][0]!=dontmon[2] && routine[0][0][0]!=routine[0][2][1] && routine[0][0][0]!=routine[0][2][0] && routine[0][2][0]!=routine[0][0][1])
                {
                    wedswap20mon=1;
                    int tempwedswap20mon=routine[0][2][0];
                    routine[0][2][0]=routine[0][0][0];
                    routine[0][0][0]=tempwedswap20mon;
                }
                else if(routine[0][1][0]!=dontwed[0] && routine[0][1][0]!=dontwed[1] && routine[0][1][0]!=dontwed[2] && routine[0][2][0]!=donttues[0] && routine[0][2][0]!=donttues[1] && routine[0][2][0]!=donttues[2] && routine[0][1][0]!=routine[0][2][1] && routine[0][1][0]!=routine[0][2][0] && routine[0][2][0]!=routine[0][1][1])
                {
                    wedswap20tues=1;
                    int tempwedswap20tues=routine[0][2][0];
                    routine[0][2][0]=routine[0][1][0];
                    routine[0][1][0]=tempwedswap20tues;
                }
                else if(routine[0][0][1]!=dontwed[0] && routine[0][0][1]!=dontwed[1] && routine[0][0][1]!=dontwed[2] && routine[0][2][0]!=dontmon[0] && routine[0][2][0]!=dontmon[1] && routine[0][2][0]!=dontmon[2] && routine[0][0][1]!=routine[0][2][1] && routine[0][0][1]!=routine[0][2][0] && routine[0][2][0]!=routine[0][0][0])
                {
                    wedswap21mon=1;
                    int tempwedswap21mon=routine[0][2][0];
                    routine[0][2][0]=routine[0][0][1];
                    routine[0][0][1]=tempwedswap21mon;
                }
                else if(routine[0][1][1]!=dontwed[0] && routine[0][1][1]!=dontwed[1] && routine[0][1][1]!=dontwed[2] && routine[0][2][0]!=donttues[0] && routine[0][2][0]!=donttues[1] && routine[0][2][0]!=donttues[2] && routine[0][1][1]!=routine[0][2][1] && routine[0][1][1]!=routine[0][2][0] && routine[0][2][0]!=routine[0][1][0])
                {
                    wedswap21tues=1;
                    int tempwedswap21tues=routine[0][2][0];
                    routine[0][2][0]=routine[0][1][1];
                    routine[0][1][1]=tempwedswap21tues;
                }
                else if(routine[0][3][1]!=dontwed[0] && routine[0][3][1]!=dontwed[1] && routine[0][3][1]!=dontwed[2] && routine[0][2][0]!=dontthurs[0] && routine[0][2][0]!=dontthurs[1] && routine[0][2][0]!=dontthurs[2] && routine[0][3][0]!=routine[0][2][0] && routine[0][3][1]!=routine[0][2][1] && routine[0][3][1]!=routine[0][2][0])
                {
                    wedswap24thurs=1;
                    int tempwedswap24thurs=routine[0][2][0];
                    routine[0][2][0]=routine[0][3][1];
                    routine[0][3][1]=tempwedswap24thurs;
                }
                else if(routine[0][4][1]!=dontwed[0] && routine[0][4][1]!=dontwed[1] && routine[0][4][1]!=dontwed[2] && routine[0][2][0]!=dontfri[0] && routine[0][2][0]!=dontfri[1] && routine[0][2][0]!=dontfri[2] && routine[0][4][0]!=routine[0][2][0] && routine[0][4][1]!=routine[0][2][0] && routine[0][2][1]!=routine[0][4][1])
                {
                    wedswap24fri=1;
                    int tempwedswap24fri=routine[0][2][0];
                    routine[0][2][0]=routine[0][4][1];
                    routine[0][4][1]=tempwedswap24fri;
                }
                else if(routine[0][2][1]!=routine[0][4][0] && routine[0][4][0]!=dontwed[0] && routine[0][4][0]!=dontwed[1] && routine[0][4][0]!=dontwed[2] && routine[0][2][0]!=dontfri[0] && routine[0][2][0]!=dontfri[1] && routine[0][2][0]!=dontfri[2] && routine[0][4][1]!=routine[0][2][0] && routine[0][4][0]!=routine[0][2][0])
                {
                    wedswap23fri=1;
                    int tempwedswap23fri=routine[0][2][0];
                    routine[0][2][0]=routine[0][4][0];
                    routine[0][4][0]=tempwedswap23fri;
                }
            }
        }

        if(monswap03wed==0 && tuesswap03wed==0 && monswap13wed==0 && tuesswap13wed==0)
        {
            if(routine[0][2][1]==dontwed[i])
            {
                if(routine[0][0][0]!=dontwed[0] && routine[0][0][0]!=dontwed[1] && routine[0][0][0]!=dontwed[2] && routine[0][2][0]!=routine[0][0][0] && routine[0][2][1]!=dontmon[0] && routine[0][2][1]!=dontmon[1] && routine[0][2][1]!=dontmon[2] && routine[0][0][0]!=routine[0][2][1] && routine[0][0][1]!=routine[0][2][1])
                {
                    wedswap30mon=1;
                    int tempwedswap30mon=routine[0][2][1];
                    routine[0][2][1]=routine[0][0][0];
                    routine[0][0][0]=tempwedswap30mon;
                }
                else if(routine[0][2][0]!=routine[0][1][0] && routine[0][1][0]!=dontwed[0] && routine[0][1][0]!=dontwed[1] && routine[0][1][0]!=dontwed[2] && routine[0][2][1]!=donttues[0] && routine[0][2][1]!=donttues[1] && routine[0][2][1]!=donttues[2] && routine[0][1][1]!=routine[0][2][1] && routine[0][1][0]!=routine[0][2][1])
                {
                    wedswap30tues=1;
                    int tempwedswap30tues=routine[0][2][1];
                    routine[0][2][1]=routine[0][1][0];
                    routine[0][1][0]=tempwedswap30tues;
                }
                else if(routine[0][2][0]!=routine[0][0][1] && routine[0][0][1]!=dontwed[0] && routine[0][0][1]!=dontwed[1] && routine[0][0][1]!=dontwed[2] && routine[0][2][1]!=dontmon[0] && routine[0][2][1]!=dontmon[1] && routine[0][2][1]!=dontmon[2] && routine[0][0][1]!=routine[0][2][1] && routine[0][0][0]!=routine[0][2][1])
                {
                    wedswap31mon=1;
                    int tempwedswap31mon=routine[0][2][1];
                    routine[0][2][1]=routine[0][0][1];
                    routine[0][0][1]=tempwedswap31mon;
                }
                else if(routine[0][2][0]!=routine[0][1][1] && routine[0][1][1]!=dontwed[0] && routine[0][1][1]!=dontwed[1] && routine[0][1][1]!=dontwed[2] && routine[0][2][1]!=donttues[0] && routine[0][2][1]!=donttues[1] && routine[0][2][1]!=donttues[2] && routine[0][1][0]!=routine[0][2][1] && routine[0][1][1]!=routine[0][2][1])
                {
                    wedswap31tues=1;
                    int tempwedswap31tues=routine[0][2][1];
                    routine[0][2][1]=routine[0][1][1];
                    routine[0][1][1]=tempwedswap31tues;
                }
                else if(routine[0][2][0]!=routine[0][3][1] && routine[0][3][1]!=dontwed[0] && routine[0][3][1]!=dontwed[1] && routine[0][3][1]!=dontwed[2] && routine[0][2][1]!=dontthurs[0] && routine[0][2][1]!=dontthurs[1] && routine[0][2][1]!=dontthurs[2] && routine[0][3][1]!=routine[0][2][1] && routine[0][3][0]!=routine[0][2][1])
                {
                    wedswap34thurs=1;
                    int tempwedswap34thurs=routine[0][2][1];
                    routine[0][2][1]=routine[0][3][1];
                    routine[0][3][1]=tempwedswap34thurs;
                }

                else if(routine[0][2][0]!=routine[0][4][1] && routine[0][4][1]!=dontwed[0] && routine[0][4][1]!=dontwed[1] && routine[0][4][1]!=dontwed[2] && routine[0][2][1]!=dontfri[0] && routine[0][2][1]!=dontfri[1] && routine[0][2][1]!=dontfri[2] && routine[0][4][0]!=routine[0][2][1] && routine[0][4][1]!=routine[0][2][1])
                {
                    wedswap34fri=1;
                    int tempwedswap34fri=routine[0][2][1];
                    routine[0][2][1]=routine[0][4][1];
                    routine[0][4][1]=tempwedswap34fri;
                }
                else if(routine[0][2][0]!=routine[0][3][0] && routine[0][3][0]!=dontwed[0] && routine[0][3][0]!=dontwed[1] && routine[0][3][0]!=dontwed[2] && routine[0][2][1]!=dontthurs[0] && routine[0][2][1]!=dontthurs[1] && routine[0][2][1]!=dontthurs[2] && routine[0][3][0]!=routine[0][2][1] && routine[0][3][1]!=routine[0][2][1])
                {
                    wedswap32thurs=1;
                    int tempwedswap32thurs=routine[0][2][1];
                    routine[0][2][1]=routine[0][3][0];
                    routine[0][3][0]=tempwedswap32thurs;
                }
            }
        }
    }

    int thursswap20mon=0,thursswap20tues=0,thursswap21mon=0,thursswap21tues=0,thursswap23fri=0,thursswap23tues=0,thursswap24fri=0;
    int thursswap40mon=0,thursswap40tues=0,thursswap41mon=0,thursswap41tues=0,thursswap43wed=0,thursswap43fri=0,thursswap42wed=0;
    int friswap30mon=0,friswap30tues=0,friswap31mon=0,friswap31tues=0,friswap32wed=0,friswap32thurs=0,friswap34thurs=0;
    int friswap40mon=0,friswap40tues=0,friswap41mon=0,friswap41tues=0,friswap42wed=0,friswap42thurs=0,friswap43wed=0;

    for(i=0; i<thk; i++)
    {
        if(monswap02thurs==0 && tuesswap02thurs==0 && monswap12thurs==0 && tuesswap12thurs==0)
        {
            if(routine[0][3][0]==dontthurs[i])
            {
                if(routine[0][0][0]!=dontthurs[0] && routine[0][0][0]!=dontthurs[1] && routine[0][0][0]!=dontthurs[2] && routine[0][3][0]!=dontmon[0] && routine[0][3][0]!=dontmon[1] && routine[0][3][0]!=dontmon[2] && wedswap20mon==0 && routine[0][0][1]!=routine[0][3][0] && routine[0][0][0]!=routine[0][3][0])
                {
                    thursswap20mon=1;
                    int tempthursswap20mon=routine[0][3][0];
                    routine[0][3][0]=routine[0][0][0];
                    routine[0][0][0]=tempthursswap20mon;

                }
                else if(routine[0][1][0]!=dontthurs[0] && routine[0][1][0]!=dontthurs[1] && routine[0][1][0]!=dontthurs[2] && routine[0][3][0]!=donttues[0] && routine[0][3][0]!=donttues[1] && routine[0][3][0]!=donttues[2] && wedswap20tues==0 && routine[0][1][1]!=routine[0][3][0] && routine[0][1][0]!=routine[0][3][0])
                {
                    thursswap20tues=1;
                    int tempthursswap20tues=routine[0][3][0];
                    routine[0][3][0]=routine[0][1][0];
                    routine[0][1][0]=tempthursswap20tues;
                }

                else if(routine[0][0][1]!=dontthurs[0] && routine[0][0][1]!=dontthurs[1] && routine[0][0][1]!=dontthurs[2] && routine[0][3][0]!=dontmon[0] && routine[0][3][0]!=dontmon[1] && routine[0][3][0]!=dontmon[2] && wedswap21mon==0 && routine[0][0][0]!=routine[0][3][0] && routine[0][0][1]!=routine[0][3][0])
                {
                    thursswap21mon=1;
                    int tempthursswap21mon=routine[0][3][0];
                    routine[0][3][0]=routine[0][0][1];
                    routine[0][0][1]=tempthursswap21mon;
                }

                else if(routine[0][1][1]!=dontthurs[0] && routine[0][1][1]!=dontthurs[1] && routine[0][1][1]!=dontthurs[2] && routine[0][3][0]!=donttues[0] && routine[0][3][0]!=donttues[1] && routine[0][3][0]!=donttues[2] && wedswap21tues==0 && routine[0][1][0]!=routine[0][3][0] && routine[0][1][1]!=routine[0][3][0] && routine[0][3][1]!=routine[0][1][1])
                {
                    thursswap21tues=1;
                    int tempthursswap21tues=routine[0][3][0];
                    routine[0][3][0]=routine[0][1][1];
                    routine[0][1][1]=tempthursswap21tues;
                }

                else if(routine[0][2][1]!=dontthurs[0] && routine[0][2][1]!=dontthurs[1] && routine[0][2][1]!=dontthurs[2] && routine[0][3][0]!=donttues[0] && routine[0][3][0]!=donttues[1] && routine[0][3][0]!=donttues[2] && routine[0][2][0]!=routine[0][3][0] && routine[0][2][1]!=routine[0][3][0] && routine[0][3][1]!=routine[0][2][1])
                {
                    thursswap23tues=1;
                    int tempthursswap23tues=routine[0][3][0];
                    routine[0][3][0]=routine[0][2][1];
                    routine[0][2][1]=tempthursswap23tues;
                }
                else if(routine[0][4][0]!=dontthurs[0] && routine[0][4][0]!=dontthurs[1] && routine[0][4][0]!=dontthurs[2] && routine[0][3][0]!=dontfri[0] && routine[0][3][0]!=dontfri[1] && routine[0][3][0]!=dontfri[2] && routine[0][4][1]!=routine[0][3][0] && routine[0][4][0]!=routine[0][3][0] && routine[0][4][0]!=routine[0][3][1])
                {
                    thursswap23fri=1;
                    int tempthursswap23fri=routine[0][3][0];
                    routine[0][3][0]=routine[0][4][0];
                    routine[0][4][0]=tempthursswap23fri;
                }
                else if(routine[0][3][1]!=routine[0][4][1] && routine[0][4][1]!=dontthurs[0] && routine[0][4][1]!=dontthurs[1] && routine[0][4][1]!=dontthurs[2] && routine[0][3][0]!=dontfri[0] && routine[0][3][0]!=dontfri[1] && routine[0][3][0]!=dontfri[2] && wedswap24fri==0 && routine[0][4][0]!=routine[0][3][0] && routine[0][4][1]!=routine[0][3][0])
                {
                    thursswap24fri=1;
                    int tempthursswap24fri=routine[0][3][0];
                    routine[0][3][0]=routine[0][4][1];
                    routine[0][4][1]=tempthursswap24fri;
                }
            }
        }

        if(monswap04thurs==0 && tuesswap04thurs==0 && monswap14thurs==0 && tuesswap14thurs==0)
        {
            if(routine[0][3][1]==dontthurs[i])
            {
                if(routine[0][0][0]!=dontthurs[0] && routine[0][0][0]!=dontthurs[1] && routine[0][0][0]!=dontthurs[2] && routine[0][3][0]!=routine[0][0][0] && routine[0][3][1]!=dontmon[0] && routine[0][3][1]!=dontmon[1] && routine[0][3][1]!=dontmon[2] && routine[0][0][0]!=routine[0][3][1] && routine[0][0][1]!=routine[0][3][1])
                {
                    thursswap40mon=1;
                    int tempthursswap40mon=routine[0][3][1];
                    routine[0][3][1]=routine[0][0][0];
                    routine[0][0][0]=tempthursswap40mon;
                }
                else if(routine[0][3][0]!=routine[0][1][0] && routine[0][1][0]!=dontthurs[0] && routine[0][1][0]!=dontthurs[1] && routine[0][1][0]!=dontthurs[2] && routine[0][3][1]!=donttues[0] && routine[0][3][1]!=donttues[1] && routine[0][3][1]!=donttues[2] && routine[0][1][1]!=routine[0][3][1] && routine[0][1][0]!=routine[0][3][1])
                {
                    thursswap40tues=1;
                    int tempthursswap40tues=routine[0][3][1];
                    routine[0][3][1]=routine[0][1][0];
                    routine[0][1][0]=tempthursswap40tues;
                }
                else if(routine[0][3][0]!=routine[0][0][1] && routine[0][0][1]!=dontthurs[0] && routine[0][0][1]!=dontthurs[1] && routine[0][0][1]!=dontthurs[2] && routine[0][3][1]!=dontmon[0] && routine[0][3][1]!=dontmon[1] && routine[0][3][1]!=dontmon[2] && routine[0][0][1]!=routine[0][3][1] && routine[0][0][0]!=routine[0][3][1])
                {
                    thursswap41mon=1;
                    int tempthursswap41mon=routine[0][3][1];
                    routine[0][3][1]=routine[0][0][1];
                    routine[0][0][1]=tempthursswap41mon;
                }
                else if(routine[0][3][0]!=routine[0][1][1] && routine[0][1][1]!=dontthurs[0] && routine[0][1][1]!=dontthurs[1] && routine[0][1][1]!=dontthurs[2] && routine[0][3][1]!=donttues[0] && routine[0][3][1]!=donttues[1] && routine[0][3][1]!=donttues[2] && routine[0][1][1]!=routine[0][3][1] && routine[0][1][0]!=routine[0][3][1])
                {
                    thursswap41tues=1;
                    int tempthursswap41tues=routine[0][3][1];
                    routine[0][3][1]=routine[0][1][1];
                    routine[0][1][1]=tempthursswap41tues;
                }
                else if(routine[0][3][0]!=routine[0][2][1] && routine[0][2][1]!=dontthurs[0] && routine[0][2][1]!=dontthurs[1] && routine[0][2][1]!=dontthurs[2] && routine[0][3][1]!=dontwed[0] && routine[0][3][1]!=dontwed[1] && routine[0][3][1]!=dontwed[2] && routine[0][2][1]!=routine[0][3][1] && routine[0][2][0]!=routine[0][3][1])
                {
                    thursswap43wed=1;
                    int tempthursswap43wed=routine[0][3][1];
                    routine[0][3][1]=routine[0][2][1];
                    routine[0][2][1]=tempthursswap43wed;
                }
                else if(routine[0][3][0]!=routine[0][4][0] && routine[0][4][0]!=dontthurs[0] && routine[0][4][0]!=dontthurs[1] && routine[0][4][0]!=dontthurs[2] && routine[0][3][1]!=dontfri[0] && routine[0][3][1]!=dontfri[1] && routine[0][3][1]!=dontfri[2] && routine[0][3][1]!=routine[0][4][1] && routine[0][4][0]!=routine[0][3][1])
                {
                    thursswap43fri=1;
                    int tempthursswap43fri=routine[0][3][1];
                    routine[0][3][1]=routine[0][4][0];
                    routine[0][4][0]=tempthursswap43fri;
                }
                else if(routine[0][3][0]!=routine[0][2][0] && routine[0][2][0]!=dontthurs[0] && routine[0][2][0]!=dontthurs[1] && routine[0][2][0]!=dontthurs[2] && routine[0][3][1]!=dontwed[0] && routine[0][3][1]!=dontwed[1] && routine[0][3][1]!=dontwed[2] && routine[0][2][0]!=routine[0][3][1] && routine[0][2][1]!=routine[0][3][1])
                {
                    thursswap42wed=1;
                    int tempthursswap42wed=routine[0][3][1];
                    routine[0][3][1]=routine[0][2][0];
                    routine[0][2][0]=tempthursswap42wed;
                }
            }
        }
    }

    for(i=0; i<fk; i++)
    {
        if(monswap03fri==0 && tuesswap03fri==0 && monswap13fri==0 && tuesswap13fri==0 && wedswap23fri==0 && thursswap23fri==0 && thursswap43fri==0)
        {
            if(routine[0][4][0]==dontfri[i])
            {
                if(routine[0][0][0]!=dontfri[0] && routine[0][0][0]!=dontfri[1] && routine[0][0][0]!=dontfri[2] && routine[0][4][0]!=dontmon[0] && routine[0][4][0]!=dontmon[1] && routine[0][4][0]!=dontmon[2] && wedswap30mon==0 && routine[0][4][0]!=routine[0][0][1] && routine[0][4][0]!=routine[0][0][0] && routine[0][4][1]!=routine[0][0][0])
                {
                    friswap30mon=1;
                    int tempfriswap30mon=routine[0][4][0];
                    routine[0][4][0]=routine[0][0][0];
                    routine[0][0][0]=tempfriswap30mon;
                }
                else if(routine[0][1][0]!=dontfri[0] && routine[0][1][0]!=dontfri[1] && routine[0][1][0]!=dontfri[2] && routine[0][4][0]!=donttues[0] && routine[0][4][0]!=donttues[1] && routine[0][4][0]!=donttues[2] && wedswap30tues==0 && routine[0][4][0]!=routine[0][1][1] && routine[0][4][0]!=routine[0][1][0] && routine[0][4][1]!=routine[0][1][0])
                {
                    friswap30tues=1;
                    int tempfriswap30tues=routine[0][4][0];
                    routine[0][4][0]=routine[0][1][0];
                    routine[0][1][0]=tempfriswap30tues;
                }
                else if(routine[0][0][1]!=dontfri[0] && routine[0][0][1]!=dontfri[1] && routine[0][0][1]!=dontfri[2] && routine[0][4][0]!=dontmon[0] && routine[0][4][0]!=dontmon[1] && routine[0][4][0]!=dontmon[2] && wedswap31mon==0 && routine[0][4][0]!=routine[0][0][1] && routine[0][4][0]!=routine[0][0][0] && routine[0][0][1]!=routine[0][4][1])
                {
                    friswap31mon=1;
                    int tempfriswap31mon=routine[0][4][0];
                    routine[0][4][0]=routine[0][0][1];
                    routine[0][0][1]=tempfriswap31mon;
                }
                else if(routine[0][1][1]!=dontfri[0] && routine[0][1][1]!=dontfri[1] && routine[0][1][1]!=dontfri[2] && routine[0][4][0]!=donttues[0] && routine[0][4][0]!=donttues[1] && routine[0][4][0]!=donttues[2] && wedswap31tues==0 && routine[0][4][0]!=routine[0][1][1] && routine[0][4][0]!=routine[0][1][0] && routine[0][4][1]!=routine[0][1][1])
{
                    friswap31tues=1;
                    int tempfriswap31tues=routine[0][4][0];
                    routine[0][4][0]=routine[0][1][1];
                    routine[0][1][1]=tempfriswap31tues;
                }
                else if(routine[0][2][0]!=dontfri[0] && routine[0][2][0]!=dontfri[1] && routine[0][2][0]!=dontfri[2] && routine[0][4][0]!=dontwed[0] && routine[0][4][0]!=dontwed[1] && routine[0][4][0]!=dontwed[2] && routine[0][4][0]!=routine[0][2][1] && routine[0][4][0]!=routine[0][2][0] && routine[0][2][0]!=routine[0][4][1])
{
                    friswap32wed=1;
                    int tempfriswap32wed=routine[0][4][0];
                    routine[0][4][0]=routine[0][2][0];
                    routine[0][2][0]=tempfriswap32wed;
                }

                else if(routine[0][3][0]!=dontfri[0] && routine[0][3][0]!=dontfri[1] && routine[0][3][0]!=dontfri[2] && routine[0][4][0]!=dontthurs[0] && routine[0][4][0]!=dontthurs[1] && routine[0][4][0]!=dontthurs[2] && wedswap32thurs==0 && routine[0][4][0]!=routine[0][3][1] && routine[0][4][0]!=routine[0][3][0] && routine[0][3][0]!=routine[0][4][1])
{
                    friswap32thurs=1;
                    int tempfriswap32thurs=routine[0][4][0];
                    routine[0][4][0]=routine[0][3][0];
                    routine[0][3][0]=tempfriswap32thurs;
                }
                else if(routine[0][3][1]!=routine[0][4][1] && routine[0][3][1]!=dontfri[0] && routine[0][3][1]!=dontfri[1] && routine[0][3][1]!=dontfri[2] && routine[0][4][0]!=dontthurs[0] && routine[0][4][0]!=dontthurs[1] && routine[0][4][0]!=dontthurs[2] && wedswap34thurs==0 && routine[0][4][0]!=routine[0][3][1] && routine[0][4][0]!=routine[0][3][0])
{
                    friswap34thurs=1;
                    int tempfriswap34thurs=routine[0][4][0];
                    routine[0][4][0]=routine[0][3][1];
                    routine[0][3][1]=tempfriswap34thurs;
                }
            }
        }

        if(monswap04fri==0 && tuesswap04fri==0 && monswap14fri==0 && tuesswap14fri==0 && wedswap24fri==0 && wedswap34fri==0 && thursswap24fri==0)
        {
            if(routine[0][4][1]==dontfri[i])
            {
                if(routine[0][0][0]!=dontfri[0] && routine[0][0][0]!=dontfri[1] && routine[0][0][0]!=dontfri[2] && routine[0][4][0]!=routine[0][0][0] && routine[0][4][1]!=dontmon[0] && routine[0][4][1]!=dontmon[1] && routine[0][4][1]!=dontmon[2] && thursswap40mon==0 && routine[0][4][1]!=routine[0][0][1] && routine[0][4][1]!=routine[0][0][0])
                {

                    friswap40mon=1;
                    int tempfriswap40mon=routine[0][4][1];
                    routine[0][4][1]=routine[0][0][0];
                    routine[0][0][0]=tempfriswap40mon;

                }
                else if(routine[0][4][0]!=routine[0][1][0] && routine[0][1][0]!=dontfri[0] && routine[0][1][0]!=dontfri[1] && routine[0][1][0]!=dontfri[2] && routine[0][4][1]!=donttues[0] && routine[0][4][1]!=donttues[1] && routine[0][4][1]!=donttues[2] && thursswap40tues==0 && routine[0][4][1]!=routine[0][1][1] && routine[0][4][1]!=routine[0][1][0])
                {

                    friswap40tues=1;
                    int tempfriswap40tues=routine[0][4][1];
                    routine[0][4][1]=routine[0][1][0];
                    routine[0][1][0]=tempfriswap40tues;

                }
                else if(routine[0][4][0]!=routine[0][0][1] && routine[0][0][1]!=dontfri[0] && routine[0][0][1]!=dontfri[1] && routine[0][0][1]!=dontfri[2] && routine[0][4][1]!=dontmon[0] && routine[0][4][1]!=dontmon[1] && routine[0][4][1]!=dontmon[2] && thursswap41mon==0 && routine[0][4][1]!=routine[0][0][1] && routine[0][4][1]!=routine[0][0][0])
                {
                    friswap41mon=1;
                    int tempfriswap41mon=routine[0][4][1];
                    routine[0][4][1]=routine[0][0][1];
                    routine[0][0][1]=tempfriswap41mon;
                }

                else if(routine[0][4][0]!=routine[0][1][1] && routine[0][1][1]!=dontfri[0] && routine[0][1][1]!=dontfri[1] && routine[0][1][1]!=dontfri[2] && routine[0][4][1]!=donttues[0] && routine[0][4][1]!=donttues[1] && routine[0][4][1]!=donttues[2] && thursswap41tues==0 && routine[0][4][1]!=routine[0][1][1] && routine[0][4][1]!=routine[0][1][0])
                {

                    friswap41tues=1;
                    int tempfriswap41tues=routine[0][4][1];
                    routine[0][4][1]=routine[0][1][1];
                    routine[0][1][1]=tempfriswap41tues;

                }

                else if(routine[0][4][0]!=routine[0][2][0] && routine[0][2][0]!=dontfri[0] && routine[0][2][0]!=dontfri[1] && routine[0][2][0]!=dontfri[2] && routine[0][4][1]!=dontwed[0] && routine[0][4][1]!=dontwed[1] && routine[0][4][1]!=dontwed[2] && thursswap42wed==0 && routine[0][4][1]!=routine[0][2][1] && routine[0][4][1]!=routine[0][2][0])
                {
                    friswap42wed=1;
                    int tempfriswap42wed=routine[0][4][1];
                    routine[0][4][1]=routine[0][2][0];
                    routine[0][2][0]=tempfriswap42wed;
                }

                else if(routine[0][4][0]!=routine[0][3][0] && routine[0][3][0]!=dontfri[0] && routine[0][3][0]!=dontfri[1] && routine[0][3][0]!=dontfri[2] && routine[0][4][1]!=dontthurs[0] && routine[0][4][1]!=dontthurs[1] && routine[0][4][1]!=dontthurs[2] && routine[0][4][1]!=routine[0][3][1] && routine[0][4][1]!=routine[0][3][0])
                {

                    friswap42thurs=1;
                    int tempfriswap42thurs=routine[0][4][1];
                    routine[0][4][1]=routine[0][3][0];
                    routine[0][3][0]=tempfriswap42thurs;

                }
                else if(routine[0][4][0]!=routine[0][2][1] && routine[0][2][1]!=dontfri[0] && routine[0][2][1]!=dontfri[1] && routine[0][2][1]!=dontfri[2] && routine[0][4][1]!=dontwed[0] && routine[0][4][1]!=dontwed[1] && routine[0][4][1]!=dontwed[2] && thursswap43wed==0 && routine[0][4][1]!=routine[0][2][1] && routine[0][4][1]!=routine[0][2][0])
                {

                    friswap43wed=1;
                    int tempfriswap43wed=routine[0][4][1];
                    routine[0][4][1]=routine[0][2][1];
                    routine[0][2][1]=tempfriswap43wed;

                }
            }
        }
    }



    for(i=0; i<5; i++)                       //if rooms are to be included this is where the code starts to change
    {
        for(j=0; j<4; j++)
        {
            if(j!=3)
            {
                if(i!=4)
                {
                    if(j==0)
                        routine[1][i][j]=routine[0][i][2];
                    else
                        routine[1][i][j]=routine[0][i][j-1];
                }
            }
            if(j==3)
            {
                if(routine[0][i][j]<=totalclassesinweek-6)
                {
                    printf("i=%d j=%d\n",i,j);
                    routine[1][i][1]=routine[0][i][0];
                    routine[1][i][2]=routine[0][i][1];
                    routine[1][i][3]=routine[0][i][2];
                    routine[1][i][0]=routine[0][i][3];
                }
            }
        }
        if(i==4)
        {
            if(classesonfriday==2)
            {
                routine[1][i][0]=routine[0][i][1];
                routine[1][i][1]=routine[0][i][0];
            }
            else if(classesonfriday==3)
            {
                routine[1][i][0]=routine[0][i][2];
                routine[1][i][1]=routine[0][i][0];
                routine[1][i][2]=routine[0][i][1];
                //printf("%d %d %d\n",routine[0][4][0],routine[0][4][1],routine[0][4][2]);
                //printf("%d %d %d\n",routine[1][4][0],routine[1][4][1],routine[1][4][2]);
            }
        }
    }



    for(k=0; k<2; k++)
    {
        fprintf(fpprint,"Section %s\n\n",section[k]);
        for(i=0; i<5; i++)
        {
            fprintf(fpprint,"\t%s:",dayofweek[i]);
            for(j=0; j<4; j++)
            {
                if(i!=4)
                {
                    if(i==0 && j==0) fprintf(fpprint,"\t");
                    for(m=0; m<totalclassesinweek-5; m++)
                    {
                        if(routine[k][i][j]==m && subname[m]!=NULL)
                        {
                            if(k==1 && j==3 && strcmp(subname[m],subname[0])==0) continue;
                            else fprintf(fpprint,"\t%s",subname[m]);
                        }
                    }
                }
            }
            if(i==4)
            {
                fprintf(fpprint,"\t");
                for(m=0; m<totalclassesinweek-5; m++)
                {
                    if(routine[k][i][0]==m && subname[m]!=NULL)
                    {
                        fprintf(fpprint,"\t%s",subname[m]);
                    }
                }
                for(m=0; m<totalclassesinweek-5; m++)
                {
                    if(routine[k][i][1]==m && subname[m]!=NULL)
                    {
                        fprintf(fpprint,"\t%s",subname[m]);
                    }
                }
                for(m=0; m<totalclassesinweek-5; m++)
                {
                    if(routine[k][i][2]==m && subname[m]!=NULL)
                    {
                        fprintf(fpprint,"\t%s",subname[m]);
                    }
                }
            }
            fprintf(fpprint,"\n");
        }
        fprintf(fpprint,"\n\n\n");
    }
    fclose (fpprint);                               //file work truly ends


    for(k=0; k<2; k++)
    {
        printf("Section %s\n\n",section[k]);
        for(i=0; i<5; i++)
        {
            printf("\t%s:",dayofweek[i]);
            for(j=0; j<4; j++)
            {
                if(i!=4)
                {
                    if(i==0 && j==0) printf("\t");
                    for(m=0; m<totalclassesinweek-5; m++)
                    {
                        if(routine[k][i][j]==m && subname[m]!=NULL)
                        {
                            //printf("\tk=%d i=%d j=%d plc=%d m=%d %s",k,i,j,routine[k][i][j],m,subname[m]);
                            if(k==1 && j==3 && strcmp(subname[m],subname[0])==0) continue;
                            else printf("\t%s",subname[m]);
                        }
                    }
                }
            }
            if(i==4)
            {
                printf("\t");
                for(m=0; m<totalclassesinweek-5; m++)
                {

                    if(routine[k][i][0]==m && subname[m]!=NULL)
                    {
                        printf("\t%s",subname[m]);
                    }
                }
                for(m=0; m<totalclassesinweek-5; m++)
                {
                    if(routine[k][i][1]==m && subname[m]!=NULL)
                    {
                        printf("\t%s",subname[m]);
                    }
                }
                for(m=0; m<totalclassesinweek-5; m++)
                {
                    if(classesonfriday>2)
                    {
                        if(routine[k][i][2]==m && subname[m]!=NULL)
                        {
                            printf("\t%s",subname[m]);
                        }
                    }
                }
            }
            printf("\n");
        }
        printf("\n\n\n");
    }
}


/*

CSE 4203
CSE 4205
Phy 4241
Math 4241
Chem 4241
Hum 4241
CSE 4202(B1)/CSE 4206(B2/2)
Phy 4242(B2/B1)
CSE 4202(B2/2)/CSE 4206(B1)
Hum 4242

*/
