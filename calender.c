#include <stdio.h>
int dayNumber(int day, int month, int year) {
static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
year -= month < 3;
return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}
int numberOfDays(int month, int year) {
if (month == 2) {
if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
return 29;
else
return 28;
}
if (month == 4 || month == 6 || month == 9 || month == 11)
return 30;
return 31;
}
void printCalendar(int month, int year) {
char *months[] = {"January", "February", "March", "April", "May", "June",
"July", "August", "September", "October", "November", "December"};
printf("\n ------------%s %d-------------\n", months[month-1], year);
printf(" Sun Mon Tue Wed Thu Fri Sat\n");
int days = numberOfDays(month, year);
int current = dayNumber(1, month, year);
for (int i = 0; i < current; i++)
printf(" ");
for (int day = 1; day <= days; day++) {
printf("%5d", day);
if (++current > 6) {
current = 0;
printf("\n");
}
}
printf("\n");
}
int main() {
int month, year;
printf("Enter month (1-12): ");
scanf("%d", &month);
printf("Enter year: ");
scanf("%d", &year);
printCalendar(month, year);
return 0;
}
