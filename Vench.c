#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

void menu();
void getMean();
void getMedian();
void hourlyWage();
void zodiacSign();
void polygonPerimeter();
void circumference();
void wordCounter();
double factorialCalc(int n);
void lcmCalc();
void nDenom();

int main()
{
	char username[] = "vench";
	char pass[] = "fuentes";
	char uname[100];
	char pw[100];
	int lctr = 0;
	bool auth = false;
	int r1, r2, mm;
	
mainmenu:
	system("cls");
	printf("MAIN MENU\n\n");
	printf("1. Login\n2. Change Username and Password\n3. Exit\n\n");
	scanf("%d", &mm);
	
	switch(mm)
	{
		case 1:
			do
			{
				system("cls");
				printf("LOGIN\n\n");
				printf("Enter username: ");
				scanf(" %[^\n]s", uname);
				printf("Enter password: ");
				scanf(" %[^\n]s", pw);
		
				r1 = strcmp(uname, username);
				r2 = strcmp(pw, pass);
				if(r1 == 0 && r2 == 0)
				{
					auth = true;
					lctr = 4;
				}
				else
				{
					lctr++;
				}
			}while(lctr < 3);
			break;
		case 2:
			system("cls");
			printf("CHANGE USERNAME AND PASSWORD\n\n");
			printf("Enter New Username: ");
			scanf(" %[^\n]s", username);
			printf("Enter New Password: ");
			scanf(" %[^\n]s", pass);
			printf("\nChange Complete! Press any key to continue");
			getch();
			goto mainmenu;
		default:
			return 0;
	}
	
	
	if(auth)
	{
		int choice, loop, n;
	
		do
		{
			system("cls");
			menu();
			scanf("%d", &choice);
	
			switch(choice)
			{
				case 1:
					getMean();
					break;
				case 2:
					getMedian();
					break;
				case 3:
					hourlyWage();
					break;
				case 4:
					zodiacSign();
					break;
				case 5:
					polygonPerimeter();
					break;
				case 6:
					circumference();
					break;
				case 7:
					wordCounter();
					break;
				case 8:
					system("cls");
					printf("Factorial Calculator\n\n");
					printf("Enter a positive integer: ");
					scanf("%d", &n);
				
					printf("The factorial of %d is %.2lf.", n , factorialCalc(n));
					break;
				case 9:
					lcmCalc();
					break;
				case 10:
					nDenom();
					break;
				default:
					printf("Unexisting Activity!");
					break;
			}
		
			printf("\n\nProcess Completed.\nEnter 1 to go back to menu. Enter any other number to exit program: ");
			scanf("%d", &loop);
			printf("\n");
		}while (loop == 1);
	}
	else
	{
		printf("\nEntered invalid credentials for 3 times. Program has exited.");
	}
	
	return 0;
}

void menu()
{	
	printf("List of Activities\n\n");
	printf("1. Mean Calculator\n");
	printf("2. Median Calculator\n");
	printf("3. Hourly Wage Calculator\n");
	printf("4. Zodiac Sign Identifier\n");
	printf("5. Polygon Perimeter Calculator\n");
	printf("6. Circumference of Circle Calculator\n");
	printf("7. Word Counter\n");
	printf("8. Factorial Calculator\n");
	printf("9. LCM of Two Numbers\n");
	printf("10. Number of Denominations (Money)\n");
	printf("-> ");
}

void getMean()
{
	int arrSize, i, j;
	float sum = 0, mean = 0;
	
	system("cls");
	printf("Mean Calculator\n\n");
	printf("Enter data size: ");
	
	scanf("%d", &arrSize);
	printf("\n");
	
	float arr[arrSize];
	
	for(i = 0; i < arrSize; i++)
	{
		printf("Enter Data #%d: ", i+1);
		scanf("%f", &arr[i]);
	}
	for(j = 0; j < arrSize; j++)
	{
		sum += arr[j]; // sum = sum + arr[j];
		mean = sum/arrSize;
	}
			
	printf("\nThe mean of your dataset is %.2f.", mean);
}

void getMedian()
{
	int arrSize, i, k, l;
	float temp = 0, median = 0;
	
	system("cls");
	printf("Median Calculator\n\n");
	printf("Enter data size: ");
	
	scanf("%d", &arrSize);
	printf("\n");
	
	float arr[arrSize];
	
	for(i = 0; i < arrSize; i++)
	{
		printf("Enter Data #%d: ", i+1);
		scanf("%f", &arr[i]);
	}
	
	for(k = 0 ; k < arrSize ; k++)
  	{
       	for(l = 0 ; l < arrSize-1 ; l++)
       	{
           	if(arr[l]>arr[l+1])
           	{
               	temp = arr[l];
               	arr[l] = arr[l+1];
               	arr[l+1] = temp;
           	}
       	}
   	}
   	if(arrSize%2 == 0)
       	median = (arr[(arrSize-1)/2] + arr[arrSize/2])/2.0;
    else
       	median = arr[arrSize/2];
        		
    printf("\nThe median of your dataset is %.2f", median);
}

void hourlyWage()
{
	char name[100];
	float salary = 0, hours = 0, days = 30, hourlyWage;
	
	system("cls");
	printf("Enter worker's name: ");
	scanf(" %[^\n]s", name);
	printf("Enter Monthly Salary: ");
	scanf("%f", &salary);
	printf("Enter hours worked per day: ");
	scanf("%f", &hours);
	
	hourlyWage = salary / (hours * 30);
	printf("%s's hourly wage is P %.2f", name, hourlyWage);
}

void zodiacSign()
{
	char name[100];
	int month, day;
	
	system("cls");
	printf("Enter your name: ");
	scanf(" %[^\n]s", name);
	printf("Enter your birthmonth (1-12): ");
	scanf("%d", &month);
	printf("Enter your birthdate: ");
	scanf("%d", &day);
	printf("\n");
	
	if(month == 3)
	{
		if(day <= 21)
		printf("%s's zodiac sign is Aries.", name);
		else
		printf("%s's zodiac sign is Pisces", name);
	}
	else if(month == 4)
	{
		if(day <=19)
		printf("%s's zodiac sign is Aries.", name);
		else
		printf("%s's zodiac sign is Taurus.", name);
	}
	else if(month == 5)
	{
		if(day <=20)
		printf("%s's zodiac sign is Taurus.", name);
		else
		printf("%s's zodiac sign is Gemini.", name);
	}
	else if(month == 6)
	{
		if(day <= 21)
		printf("%s's zodiac sign is Gemini.", name);
		else
		printf("%s's zodiac sign is Cancer.", name);
	}
	else if(month == 7)
	{
		if(day <= 22)
		printf("%s's zodiac sign is Cancer.", name);
		else 
		printf("%s's zodiac sign is Leo.", name);
	}
	else if(month == 8)
	{
		if(day <= 22)
		printf("%s's zodiac sign is Leo.", name);
		else
		printf("%s's zodiac sign is Virgo.", name);
	}
	else if(month == 9)
	{
		if(day <= 22)
		printf("%s's zodiac sign is Virgo.", name);
		else
		printf("%s's zodiac sign is Libra.", name);
	}
	else if(month == 10)
	{
		if(day <= 23)
		printf("%s's zodiac sign is Libra.", name);
		else
		printf("%s's zodiac sign is Scorpius.", name);
	}
	else if(month == 11)
	{
		if(day <= 21)
		printf("%s's zodiac sign is Scorpius.", name);
		else
		printf("%s's zodiac sign is Sagittarius.", name);
	}
	else if(month == 12)
	{
		if(day <= 21)
		printf("%s's zodiac sign is Sagittarius.", name);
		else
		printf("%s's zodiac sign is Capricornus.", name);
	}
	else if(month == 1)
	{
		if(day <= 19)
		printf("%s's zodiac sign is Capricornus.", name);
		else
		printf("%s's zodiac sign is Aquarius.", name);
	}
	else if(month == 2)
	{
		if(day <= 18)
		printf("%s's zodiac sign is Aquarius.", name);
		else
		printf("%s's zodiac sign is Pisces.", name);
	}
	else if(month > 12)
	{
		printf("No month exists!");
	}
}

void polygonPerimeter()
{
	int sides;
	float length, perimeter;
	
	system("cls");
	printf("Polygon Perimeter\n\n");
	printf("Enter number of sides of polygon: ");
	scanf("%d", &sides);
	printf("Enter side length: ");
	scanf("%f", &length);
	
	perimeter = (float) (sides * length);
	
	printf("\nThe perimeter of the polygon is %.2f.", perimeter);
}

void circumference()
{
	float radius, diameter, circumference;
	int choice;

	system("cls");
	printf("Circumference of a Circle\n\n");
	printf("Given is (1) Diameter (2) Radius: ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1:
			printf("Enter diameter length: ");
			scanf("%f", &diameter);
			
			radius = diameter / 2;
			break;
		case 2:
			printf("Enter radius length: ");
			scanf("%f", &radius);
			break;
		default:
			printf("Invalid Input!");
			break;
	}
	
	circumference = M_PI * 2 * radius;
	printf("\nThe circumference of the circle is %.2f.", circumference);
}

void wordCounter()
{
	char string[1000];
	int ctr = 0, i;
	
	system("cls");
	printf("Word Counter\n\n");
	printf("Enter string to be counted:\n");
	scanf(" %[^\n]s", string);
	
	for(i = 0; i < 999; i++)
	{
		if(string[i] == ' ' && string[i+1] != ' ')
		ctr++;
	}
	
	printf("\nThe number of words in the string is %d", ctr);
}

double factorialCalc(int n)
{
	if(n>=1)
	return n * factorialCalc(n-1);
	else
	return 1;
}

void lcmCalc()
{
	int n1, n2, max;
	
	system("cls");
	printf("LCM of Two Numbers\n\n");
	printf("Enter first number: ");
	scanf("%d", &n1);
	printf("Enter second number: ");
	scanf("%d", &n2);
	
	max = (n1 > n2) ? n1 : n2;
	
	while (1) {
        if ((max % n1 == 0) && (max % n2 == 0)) {
            printf("\nThe LCM of %d and %d is %d.", n1, n2, max);
            break;
        }
        ++max;
    }
}

void nDenom()
{
	int amount, notes, i;
	int denom[8] = {1000, 500, 100, 50, 20, 10, 5, 1};
	
	system("cls");
	printf("Number of Denominations (Money)\n\n");
	printf("Enter amount (integer): ");
	scanf("%d", &amount);
	printf("\n");
	for (i = 0; i < 8; i++) 
    {
        notes = amount / denom[i];

        if (notes)
        {
            amount = amount % denom[i];

            printf("%d * %d = %d \n", notes, denom[i], 
                notes * denom[i]);
        }                
    }
}
