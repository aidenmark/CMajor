//
//  main.c
//  ESPP
//
//  Created by Aeriel Denmark on 10/13/19.
//  Copyright © 2019 Big Nerd Ranch. All rights reserved.
//

#include <stdio.h>
#include <math.h>

// Declare Global Variable for Cash Flow
float cashFlow;
float totalPurchasedShares;

float stockPrice(float start, float end) {
    float chosenPrice = (start > end) ? end : start;
    return chosenPrice;
}

void doWork(float start, float end) {
    printf("Starting Stock Price:  %.2f \n", start);
    printf("Ending Stock Price:  %.2f \n", end);

    cashFlow += 5000.0;
    printf("Cash Flow Amount:  %.2f \n", cashFlow);

    printf("Employee Stock Price: %.2f \n", stockPrice(start, end));

    int discount = 15;
    printf("Employee Discount:  %i%% per share \n", discount);

    float purchasedSharesPrice = stockPrice(start, end) * 0.85;
    printf("Price Per Share:  %.2f \n", purchasedSharesPrice);

    float numberOfShares = floor(cashFlow / purchasedSharesPrice);
    printf("Purchased Number of Shares:  %.2f \n", numberOfShares);

    float spentCashFlow = purchasedSharesPrice * numberOfShares;
    printf("Spent Cash Flow:  %.2f \n", spentCashFlow);

    float remainingCashFlow = cashFlow - spentCashFlow;
    printf("Remaining Cash Flow:  %.2f \n", remainingCashFlow);

    float instantaneous = end * numberOfShares;
    printf("Instantaneous Value of Purhcased Stocks:  %.2f \n", instantaneous);

    cashFlow = remainingCashFlow;

    totalPurchasedShares += numberOfShares;

    printf("\n");

}

int main(int argc, const char * argv[]) {
    // insert code here...

    cashFlow = 0.0;
    totalPurchasedShares = 0.0;

    doWork(100.0, 150.0);
    doWork(150.0, 200.0);
    doWork(200.0, 250.0);
    doWork(250.0, 300.0);

    printf("Over the course of 2 years, we bought a total of %.2f shares. \n", totalPurchasedShares);

    return 0;
}
