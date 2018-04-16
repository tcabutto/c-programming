#include <stdio.h>


#include <stdio.h>


int main()
{
        int mo, day, year, mo2, day2, year2;
        mo2 = 0;
        day2 = 0;
        year2 = 0;

        printf("Enter a date: ");
        scanf("%d/%d/%d", &mo, &day, &year);

        while((mo != 0) && (day != 0) && (year != 0))
        {
                printf("Enter a date: ");
                scanf("%d/%d/%d", &mo2, &day2, &year2);

                if( (day2 == 0) && (mo2 == 0) && (year2 == 0)){break;}

                if(year2 < year)
                {
                        mo = mo2;
                        day = day2;
                        year = year2;
                }
                else if(year2 == year)
                {
                        if (mo2 < mo)
                        {
                                mo = mo2;
                                day = day2;
                                year = year2;
                        }
                        else if(mo2 == mo)
                        {
                                if(day2 < day)
                                {
                                        mo = mo2;
                                        day = day2;
                                        year = year2;
                                }
                        }
                }
                printf("Enter a date: ");
                scanf("%d/%d/%d", &mo2, &day2, &year2);


        }

        printf("%d/%d/%d is the earliest year.\n", mo, day, year);

        return 0;
}


int main()
{
	int mo, day, year, mo2, day2, year2;
	mo2 = 0;
	day2 = 0;
	year2 = 0;

	printf("Enter a date: ");
	scanf("%d/%d/%d", &mo, &day, &year);

	while((mo != 0) && (day != 0) && (year != 0))
	{
		printf("Enter a date: ");
		scanf("%d/%d/%d", &mo2, &day2, &year2);

		if( (day2 == 0) && (mo2 == 0) && (year2 == 0)){break;}

		if(year2 < year)
		{
			mo = mo2;
			day = day2;
			year = year2;
		}
		else if(year2 == year)
		{
			if (mo2 < mo)
			{
				mo = mo2;
				day = day2;
				year = year2;
			}
			else if(mo2 == mo)
			{
				if(day2 < day)
				{
					mo = mo2;
					day = day2;
					year = year2;
				}
			}
		}
		printf("Enter a date: ");
		scanf("%d/%d/%d", &mo2, &day2, &year2);


	}

	printf("%d/%d/%d is the earliest year.\n", mo, day, year);

	return 0;
}

