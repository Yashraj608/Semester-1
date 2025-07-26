#include<stdio.h>


struct employee
{
		int employee_code;
		char employee_name[50];
		int join_day,join_month,join_year;
		
};
void assign_values(struct employee employe[])
{
	 int currentDay, currentMonth,currentYear;
	int i,j;
	for(i=0;i<2;i++)
	{
	printf("Enter the code of employee %d\n",i+1);
	scanf("%d",& employe[i].employee_code);
	getchar();
	printf("Enter the name for emplyoee %d\n",i+1);
	fgets(employe[i].employee_name, sizeof(employe[i].employee_name), stdin);
	
	printf("Date of Joining (DD MM YYYY): for Employee %d ",i+1);
   	scanf("%d %d %d", &employe[i].join_day, &employe[i].join_month, &employe[i].join_year);
   	printf("Enter the current date (DD MM YYYY): ");
    scanf("%d %d %d",&currentDay,&currentMonth,&currentYear);
	}
}
void tenure_check(struct employee employe[])
{
	int currentDay, currentMonth,currentYear;
    int count=0,i;
     for ( i = 0; i < 4; i++) {
        int years=currentYear - employe[i].join_year;
        int months=currentMonth - employe[i].join_month;
        int days=currentDay - employe[i].join_day;
         if(months < 0 ||(months==0 && days<0))
		{
            years--;
        }
    if (years>3)
	{
            count++;
            printf("\nEmployee Code: %d\n", employe[i].employee_code);
            printf("Employee Name: %s\n", employe[i].employee_name);
            printf("Date of Joining: %02d/%02d/%04d\n", employe[i].join_day, employe[i].join_month, employe[i].join_year);
            printf("Tenure: %d years\n", years);
        }
        if(count==0)
        {
        	printf("No employees there whoes tensrue greater than 3 years");
		}
		else
		{
			printf("The number of employees have tenure gretaer 3 years are  %d",count);
		}
	}
}
int main()
{
	struct employee employe[4];
	int n=4;
	assign_values(employe);	
	tenure_check(employe);
}
