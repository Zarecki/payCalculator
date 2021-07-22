/*
Pay to be set at $12.00 per hour.
Overtime > 40 hours is time and a half.
tax:
    15% for the first $300
    20% for the next $150
    25% after.

Take in hours worked and return the gross pay, taxes, and net pay.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{

    double gross, totalTaxes, net, basicRate, overtimeRate, taxReducedTotal;
    int hoursWorked, overTimeHours;

    basicRate = 12.00;
    overtimeRate = 18.00;
    totalTaxes = 0.00;

    //Taking in the hours worked
    printf("Please input your total hours worked\n");
    scanf("%d", &hoursWorked);

    //Calculating the overtime worked
    if(hoursWorked > 40){
        overTimeHours = hoursWorked - 40;
    } else {
        overTimeHours = 0;
    };

    //Set gross pay
    gross = (basicRate * hoursWorked) + (overtimeRate * overTimeHours);
    


    if (hoursWorked > 37){
        //if hours worked are enough to require both tax rates, calculate each in turn.
        totalTaxes += (300*15)/100;
        totalTaxes += (150*20)/100;
        taxReducedTotal = (gross-450);
        totalTaxes += (taxReducedTotal*25)/100;
    } else if (hoursWorked > 25 && hoursWorked <= 37){
        //hours worked are only enough to pay one tax rate fully, with the remainder at the second rate.
        totalTaxes += (300*15)/100;
        taxReducedTotal = (gross-300);
        totalTaxes += (taxReducedTotal*25)/100;
    } else{
        //basic rate of tax.
        totalTaxes += (gross*15)/100;
    }

    //set net pay
    net = (gross-totalTaxes);

    printf("After working %d hours at $%.2lf per hour, with %d hours overtime:\n", hoursWorked, basicRate, overTimeHours);
    printf("Gross pay: %.2lf.\n", gross);
    printf("Total tax: %.2lf.\n", totalTaxes);
    printf("Net pay: %.2lf.\n", net);
    
    return 0;
}
